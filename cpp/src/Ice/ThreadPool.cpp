//
// Copyright (c) ZeroC, Inc. All rights reserved.
//

#include <Ice/ThreadPool.h>
#include <Ice/EventHandler.h>
#include <Ice/Network.h>
#include <Ice/LocalException.h>
#include <Ice/Instance.h>
#include <Ice/LoggerUtil.h>
#include <Ice/Protocol.h>
#include <Ice/ObjectAdapterFactory.h>
#include <Ice/Properties.h>
#include <Ice/TraceLevels.h>

using namespace std;
using namespace Ice;
using namespace Ice::Instrumentation;
using namespace IceInternal;

ICE_API IceUtil::Shared* IceInternal::upCast(ThreadPool* p) { return p; }

namespace
{

class ShutdownWorkItem : public ThreadPoolWorkItem
{
public:

    ShutdownWorkItem(const InstancePtr& instance) : _instance(instance)
    {
    }

    virtual void
    execute(ThreadPoolCurrent& current)
    {
        current.ioCompleted();
        try
        {
            _instance->objectAdapterFactory()->shutdown();
        }
        catch(const CommunicatorDestroyedException&)
        {
        }
    }

private:

    const InstancePtr _instance;
};

class FinishedWorkItem : public ThreadPoolWorkItem
{
public:

    FinishedWorkItem(const EventHandlerPtr& handler, bool close) : _handler(handler), _close(close)
    {
    }

    virtual void
    execute(ThreadPoolCurrent& current)
    {
        _handler->finished(current, _close);

        //
        // Break cyclic reference count.
        //
        if(_handler->getNativeInfo())
        {
            _handler->getNativeInfo()->setReadyCallback(0);
        }
    }

private:

    const EventHandlerPtr _handler;
    const bool _close;
};

class JoinThreadWorkItem : public ThreadPoolWorkItem
{
public:

    JoinThreadWorkItem(const IceUtil::ThreadPtr& thread) : _thread(thread)
    {
    }

    virtual void
    execute(ThreadPoolCurrent&)
    {
        // No call to ioCompleted, this shouldn't block (and we don't want to cause
        // a new thread to be started).
        _thread->getThreadControl().join();
    }

private:

    IceUtil::ThreadPtr _thread;
};

//
// Exception raised by the thread pool work queue when the thread pool
// is destroyed.
//
class ThreadPoolDestroyedException
{
};

}

Ice::DispatcherCall::~DispatcherCall()
{
    // Out of line to avoid weak vtable
}

Ice::Dispatcher::~Dispatcher()
{
    // Out of line to avoid weak vtable
}

IceInternal::DispatchWorkItem::DispatchWorkItem()
{
}

IceInternal::DispatchWorkItem::DispatchWorkItem(const Ice::ConnectionPtr& connection) : _connection(connection)
{
}

void
IceInternal::DispatchWorkItem::execute(ThreadPoolCurrent& current)
{
    current.ioCompleted(); // Promote follower
    current.dispatchFromThisThread(this);
}

IceInternal::ThreadPoolWorkQueue::ThreadPoolWorkQueue(ThreadPool& threadPool) :
    _threadPool(threadPool),
    _destroyed(false)
{
    _registered = SocketOperationRead;
}

void
IceInternal::ThreadPoolWorkQueue::destroy()
{
    //Lock sync(*this); Called with the thread pool locked
    assert(!_destroyed);
    _destroyed = true;
#if defined(ICE_USE_IOCP)
    _threadPool._selector.completed(this, SocketOperationRead);
#else
    _threadPool._selector.ready(this, SocketOperationRead, true);
#endif
}

void
IceInternal::ThreadPoolWorkQueue::queue(const ThreadPoolWorkItemPtr& item)
{
    //Lock sync(*this); Called with the thread pool locked
    _workItems.push_back(item);
#if defined(ICE_USE_IOCP)
    _threadPool._selector.completed(this, SocketOperationRead);
#else
    if(_workItems.size() == 1)
    {
        _threadPool._selector.ready(this, SocketOperationRead, true);
    }
#endif
}

#if defined(ICE_USE_IOCP)
bool
IceInternal::ThreadPoolWorkQueue::startAsync(SocketOperation)
{
    assert(false);
    return false;
}

bool
IceInternal::ThreadPoolWorkQueue::finishAsync(SocketOperation)
{
    assert(false);
    return false;
}
#endif

void
IceInternal::ThreadPoolWorkQueue::message(ThreadPoolCurrent& current)
{
    ThreadPoolWorkItemPtr workItem;
    {
        IceUtil::Monitor<IceUtil::Mutex>::Lock sync(_threadPool);
        if(!_workItems.empty())
        {
            workItem = _workItems.front();
            _workItems.pop_front();
        }
#if defined(ICE_USE_IOCP)
        else
        {
            assert(_destroyed);
            _threadPool._selector.completed(this, SocketOperationRead);
        }
#else
        if(_workItems.empty() && !_destroyed)
        {
            _threadPool._selector.ready(this, SocketOperationRead, false);
        }
#endif
    }

    if(workItem)
    {
        workItem->execute(current);
    }
    else
    {
        assert(_destroyed);
        current.ioCompleted();
        throw ThreadPoolDestroyedException();
    }
}

void
IceInternal::ThreadPoolWorkQueue::finished(ThreadPoolCurrent&, bool)
{
    assert(false);
}

string
IceInternal::ThreadPoolWorkQueue::toString() const
{
    return "work queue";
}

NativeInfoPtr
IceInternal::ThreadPoolWorkQueue::getNativeInfo()
{
    return 0;
}

IceInternal::ThreadPool::ThreadPool(const InstancePtr& instance, const string& prefix, int timeout) :
    _instance(instance),
    _dispatcher(_instance->initializationData().dispatcher),
    _destroyed(false),
    _prefix(prefix),
    _selector(instance),
    _nextThreadId(0),
    _size(0),
    _sizeIO(0),
    _maxSize(0),
    _warnSize(0),
    _serialize(_instance->initializationData().properties->getPropertyAsInt(_prefix + ".Serialize") > 0),
    _hasPriority(false),
    _priority(0),
    _serverIdleTime(timeout),
    _threadIdleTime(0),
    _stackSize(0),
    _inUse(0),
#if !defined(ICE_USE_IOCP)
    _inUseIO(0),
    _nextHandler(_handlers.end()),
#endif
    _promote(true)
{
    PropertiesPtr properties = _instance->initializationData().properties;
#ifdef _WIN32
    SYSTEM_INFO sysInfo;
    GetSystemInfo(&sysInfo);
    int nProcessors = sysInfo.dwNumberOfProcessors;
#elif defined(__FreeBSD__) || defined(__FreeBSD_kernel__)
    static int ncpu[2] = { CTL_HW, HW_NCPU };
    size_t sz = sizeof(nProcessors);
    int nProcessors;
    if(sysctl(ncpu, 2, &nProcessors, &sz, 0, 0) == -1)
    {
        nProcessors = 1;
    }
#else
    int nProcessors = static_cast<int>(sysconf(_SC_NPROCESSORS_ONLN));
    if(nProcessors == -1)
    {
        nProcessors = 1;
    }
#endif

    //
    // We use just one thread as the default. This is the fastest
    // possible setting, still allows one level of nesting, and
    // doesn't require to make the servants thread safe.
    //
    int size = properties->getPropertyAsIntWithDefault(_prefix + ".Size", 1);
    if(size < 1)
    {
        Warning out(_instance->initializationData().logger);
        out << _prefix << ".Size < 1; Size adjusted to 1";
        size = 1;
    }

    int maxSize = properties->getPropertyAsIntWithDefault(_prefix + ".MaxSize", size);
    if(maxSize == -1)
    {
        maxSize = nProcessors;
    }

    if(maxSize < size)
    {
        Warning out(_instance->initializationData().logger);
        out << _prefix << ".MaxSize < " << _prefix << ".Size; MaxSize adjusted to Size (" << size << ")";
        maxSize = size;
    }

    int warnSize = properties->getPropertyAsInt(_prefix + ".WarnSize");
    if(warnSize != 0 && warnSize < size)
    {
        Warning out(_instance->initializationData().logger);
        out << _prefix << ".WarnSize < " << _prefix << ".Size; adjusted WarnSize to Size (" << size << ")";
        warnSize = size;
    }
    else if(warnSize > maxSize)
    {
        Warning out(_instance->initializationData().logger);
        out << _prefix << ".WarnSize > " << _prefix << ".MaxSize; adjusted WarnSize to MaxSize (" << maxSize << ")";
        warnSize = maxSize;
    }

    int threadIdleTime = properties->getPropertyAsIntWithDefault(_prefix + ".ThreadIdleTime", 60);
    if(threadIdleTime < 0)
    {
        Warning out(_instance->initializationData().logger);
        out << _prefix << ".ThreadIdleTime < 0; ThreadIdleTime adjusted to 0";
        threadIdleTime = 0;
    }

    const_cast<int&>(_size) = size;
    const_cast<int&>(_maxSize) = maxSize;
    const_cast<int&>(_warnSize) = warnSize;
    const_cast<int&>(_sizeIO) = min(maxSize, nProcessors);
    const_cast<int&>(_threadIdleTime) = threadIdleTime;

#ifdef ICE_USE_IOCP
    _selector.setup(_sizeIO);
#endif

#if defined(__APPLE__)
    //
    // We use a default stack size of 1MB on macOS to allow transmitting
    // class graphs with a depth of 100 (maximum default), 512KB is not enough otherwise.
    //
    int defaultStackSize = 1024 * 1024; // 1MB
#else
    int defaultStackSize = 0;
#endif
    int stackSize = properties->getPropertyAsIntWithDefault(_prefix + ".StackSize", defaultStackSize);
    if(stackSize < 0)
    {
        Warning out(_instance->initializationData().logger);
        out << _prefix << ".StackSize < 0; Size adjusted to OS default";
        stackSize = 0;
    }
    const_cast<size_t&>(_stackSize) = static_cast<size_t>(stackSize);

    const_cast<bool&>(_hasPriority) = properties->getProperty(_prefix + ".ThreadPriority") != "";
    const_cast<int&>(_priority) = properties->getPropertyAsInt(_prefix + ".ThreadPriority");
    if(!_hasPriority)
    {
        const_cast<bool&>(_hasPriority) = properties->getProperty("Ice.ThreadPriority") != "";
        const_cast<int&>(_priority) = properties->getPropertyAsInt("Ice.ThreadPriority");
    }

    _workQueue = std::make_shared<ThreadPoolWorkQueue>(*this);
    _selector.initialize(_workQueue.get());

    if(_instance->traceLevels()->threadPool >= 1)
    {
        Trace out(_instance->initializationData().logger, _instance->traceLevels()->threadPoolCat);
        out << "creating " << _prefix << ": Size = " << _size << ", MaxSize = " << _maxSize << ", WarnSize = "
            << _warnSize;
    }

    __setNoDelete(true);
    try
    {
        for(int i = 0 ; i < _size ; ++i)
        {
            EventHandlerThreadPtr thread = new EventHandlerThread(this, nextThreadId());
            if(_hasPriority)
            {
                thread->start(_stackSize, _priority);
            }
            else
            {
                thread->start(_stackSize);
            }
            _threads.insert(thread);
        }
    }
    catch(const IceUtil::Exception& ex)
    {
        {
            Error out(_instance->initializationData().logger);
            out << "cannot create thread for `" << _prefix << "':\n" << ex;
        }

        destroy();
        joinWithAllThreads();
        __setNoDelete(false);
        throw;
    }
    catch(...)
    {
        __setNoDelete(false);
        throw;
    }
    __setNoDelete(false);
}

IceInternal::ThreadPool::~ThreadPool()
{
    assert(_destroyed);
}

void
IceInternal::ThreadPool::destroy()
{
    Lock sync(*this);
    if(_destroyed)
    {
        return;
    }
    _destroyed = true;
    _workQueue->destroy();
}

void
IceInternal::ThreadPool::updateObservers()
{
    Lock sync(*this);
    for(set<EventHandlerThreadPtr>::iterator p = _threads.begin(); p != _threads.end(); ++p)
    {
        (*p)->updateObserver();
    }
}

void
IceInternal::ThreadPool::initialize(const EventHandlerPtr& handler)
{
    Lock sync(*this);
    assert(!_destroyed);
    _selector.initialize(handler.get());

    class ReadyCallbackI : public ReadyCallback
    {
    public:

        ReadyCallbackI(const ThreadPoolPtr& threadPool, const EventHandlerPtr& handler) :
            _threadPool(threadPool), _handler(handler)
        {
        }

        virtual void
        ready(SocketOperation op, bool value)
        {
            _threadPool->ready(_handler, op, value);
        }

    private:

        const ThreadPoolPtr _threadPool;
        const EventHandlerPtr _handler;
    };
    handler->getNativeInfo()->setReadyCallback(new ReadyCallbackI(this, handler));
}

void
IceInternal::ThreadPool::update(const EventHandlerPtr& handler, SocketOperation remove, SocketOperation add)
{
    Lock sync(*this);
    assert(!_destroyed);

    // Don't remove what needs to be added
    remove = static_cast<SocketOperation>(remove & ~add);

    // Don't remove/add if already un-registered or registered
    remove  = static_cast<SocketOperation>(handler->_registered & remove);
    add  = static_cast<SocketOperation>(~handler->_registered & add);
    if(remove == add)
    {
        return;
    }

    _selector.update(handler.get(), remove, add);
}

bool
IceInternal::ThreadPool::finish(const EventHandlerPtr& handler, bool closeNow)
{
    Lock sync(*this);
    assert(!_destroyed);
#if !defined(ICE_USE_IOCP)
    closeNow = _selector.finish(handler.get(), closeNow); // This must be called before!
    _workQueue->queue(new FinishedWorkItem(handler, !closeNow));
    return closeNow;
#else
    UNREFERENCED_PARAMETER(closeNow);

    // If there are no pending asynchronous operations, we can call finish on the handler now.
    if(!handler->_pending)
    {
        _workQueue->queue(new FinishedWorkItem(handler, false));
        _selector.finish(handler.get());
    }
    else
    {
        handler->_finish = true;
    }
    return true; // Always close now to interrupt the pending call.
#endif
}

void
IceInternal::ThreadPool::ready(const EventHandlerPtr& handler, SocketOperation op, bool value)
{
    Lock sync(*this);
    if(_destroyed)
    {
        return;
    }
    _selector.ready(handler.get(), op, value);
}

void
IceInternal::ThreadPool::dispatchFromThisThread(const DispatchWorkItemPtr& workItem)
{
    if(_dispatcher)
    {
        try
        {
            _dispatcher([workItem]()
            {
                workItem->run();
            },
            workItem->getConnection());
        }
        catch(const std::exception& ex)
        {
            if(_instance->initializationData().properties->getPropertyAsIntWithDefault("Ice.Warn.Dispatch", 1) > 1)
            {
                Warning out(_instance->initializationData().logger);
                out << "dispatch exception:\n" << ex;
            }
        }
        catch(...)
        {
            if(_instance->initializationData().properties->getPropertyAsIntWithDefault("Ice.Warn.Dispatch", 1) > 1)
            {
                Warning out(_instance->initializationData().logger);
                out << "dispatch exception:\nunknown c++ exception";
            }
        }
    }
    else
    {
        workItem->run();
    }
}

void
IceInternal::ThreadPool::dispatch(const DispatchWorkItemPtr& workItem)
{
    Lock sync(*this);
    if(_destroyed)
    {
        throw CommunicatorDestroyedException(__FILE__, __LINE__);
    }
    _workQueue->queue(workItem);
}

void
IceInternal::ThreadPool::joinWithAllThreads()
{
    assert(_destroyed);

    //
    // _threads is immutable after destroy() has been called,
    // therefore no synchronization is needed. (Synchronization
    // wouldn't be possible here anyway, because otherwise the other
    // threads would never terminate.)
    //
    for(set<EventHandlerThreadPtr>::iterator p = _threads.begin(); p != _threads.end(); ++p)
    {
        (*p)->getThreadControl().join();
    }
    _selector.destroy();
}

string
IceInternal::ThreadPool::prefix() const
{
    return _prefix;
}

void
IceInternal::ThreadPool::run(const EventHandlerThreadPtr& thread)
{
#if !defined(ICE_USE_IOCP)
    ThreadPoolCurrent current(_instance, this, thread);
    bool select = false;
    while(true)
    {
        if(current._handler)
        {
            try
            {
                current._handler->message(current);
            }
            catch(const ThreadPoolDestroyedException&)
            {
                Lock sync(*this);
                --_inUse;
                thread->setState(ThreadState::ThreadStateIdle);
                return;
            }
            catch(const exception& ex)
            {
                Error out(_instance->initializationData().logger);
                out << "exception in `" << _prefix << "':\n" << ex << "\nevent handler: "
                    << current._handler->toString();
            }
            catch(...)
            {
                Error out(_instance->initializationData().logger);
                out << "exception in `" << _prefix << "':\nevent handler: " << current._handler->toString();
            }
        }
        else if(select)
        {
            try
            {
                _selector.select(_serverIdleTime);
            }
            catch(const SelectorTimeoutException&)
            {
                Lock sync(*this);
                if(!_destroyed && _inUse == 0)
                {
                    _workQueue->queue(new ShutdownWorkItem(_instance)); // Select timed-out.
                }
                continue;
            }
        }

        {
            Lock sync(*this);
            if(!current._handler)
            {
                if(select)
                {
                    _selector.finishSelect(_handlers);
                    _nextHandler = _handlers.begin();
                    select = false;
                }
                else if(!current._leader && followerWait(current))
                {
                    return; // Wait timed-out.
                }
            }
            else if(_maxSize > 1)
            {
                if(!current._ioCompleted)
                {
                    //
                    // The handler didn't call ioCompleted() so we take care of decreasing
                    // the IO thread count now.
                    //
                    --_inUseIO;
                }
                else
                {
                    //
                    // If the handler called ioCompleted(), we re-enable the handler in
                    // case it was disabled and we decrease the number of thread in use.
                    //
                    if(_serialize && current._handler.get() != _workQueue.get())
                    {
                        _selector.enable(current._handler.get(), current.operation);
                    }
                    assert(_inUse > 0);
                    --_inUse;
                }

                if(!current._leader && followerWait(current))
                {
                    return; // Wait timed-out.
                }
            }

            //
            // Get the next ready handler.
            //
            while(_nextHandler != _handlers.end() &&
                    !(_nextHandler->second & ~_nextHandler->first->_disabled & _nextHandler->first->_registered))
            {
                ++_nextHandler;
            }
            if(_nextHandler != _handlers.end())
            {
                current._ioCompleted = false;
                current._handler = _nextHandler->first->shared_from_this();
                current.operation = _nextHandler->second;
                ++_nextHandler;
                thread->setState(ThreadState::ThreadStateInUseForIO);
            }
            else
            {
                current._handler = 0;
            }

            if(!current._handler)
            {
                //
                // If there are no more ready handlers and there are still threads busy performing
                // IO, we give up leadership and promote another follower (which will perform the
                // select() only once all the IOs are completed). Otherwise, if there are no more
                // threads peforming IOs, it's time to do another select().
                //
                if(_inUseIO > 0)
                {
                    promoteFollower(current);
                }
                else
                {
                    _handlers.clear();
                    _selector.startSelect();
                    select = true;
                    thread->setState(ThreadState::ThreadStateIdle);
                }
            }
            else if(_maxSize > 1)
            {
                //
                // Increment the IO thread count and if there are still threads available
                // to perform IO and more handlers ready, we promote a follower.
                //
                ++_inUseIO;
                if(_nextHandler != _handlers.end() && _inUseIO < _sizeIO)
                {
                    promoteFollower(current);
                }
            }
        }
    }
#else
    ThreadPoolCurrent current(_instance, this, thread);
    while(true)
    {
        try
        {
            current._ioCompleted = false;
            current._handler = _selector.getNextHandler(current.operation, current._count, current._error,
                                                        _threadIdleTime)->shared_from_this();
        }
        catch(const SelectorTimeoutException&)
        {
            if(_maxSize > 1)
            {
                Lock sync(*this);

                if(_destroyed)
                {
                    continue;
                }
                else if(_inUse < static_cast<int>(_threads.size() - 1)) // If not the last idle thread, we can exit.
                {
                    if(_instance->traceLevels()->threadPool >= 1)
                    {
                        Trace out(_instance->initializationData().logger, _instance->traceLevels()->threadPoolCat);
                        out << "shrinking " << _prefix << ": Size = " << (_threads.size() - 1);
                    }
                    _threads.erase(thread);
                    _workQueue->queue(new JoinThreadWorkItem(thread));
                    return;
                }
                else if(_inUse > 0)
                {
                    //
                    // If this is the last idle thread but there are still other threads
                    // busy dispatching, we go back waiting with _threadIdleTime. We only
                    // wait with _serverIdleTime when there's only one thread left.
                    //
                    continue;
                }
                assert(_threads.size() == 1);
            }

            try
            {

                current._handler = _selector.getNextHandler(current.operation, current._count,
                                   current._error, _serverIdleTime)->shared_from_this();
            }
            catch(const SelectorTimeoutException&)
            {
                Lock sync(*this);
                if(!_destroyed)
                {
                    _workQueue->queue(new ShutdownWorkItem(_instance));
                }
                continue;
            }
        }

        {
            IceUtil::Monitor<IceUtil::Mutex>::Lock sync(*this);
            thread->setState(ThreadState::ThreadStateInUseForIO);
        }

        try
        {
            assert(current._handler);
            current._handler->message(current);
        }
        catch(const ThreadPoolDestroyedException&)
        {
            return;
        }
        catch(const exception& ex)
        {
            Error out(_instance->initializationData().logger);
            out << "exception in `" << _prefix << "':\n" << ex << "\nevent handler: " << current._handler->toString();
        }
        catch(...)
        {
            Error out(_instance->initializationData().logger);
            out << "exception in `" << _prefix << "':\nevent handler: " << current._handler->toString();
        }

        {
            Lock sync(*this);
            if(_maxSize > 1 && current._ioCompleted)
            {
                assert(_inUse > 0);
                --_inUse;
            }
            thread->setState(ThreadState::ThreadStateIdle);
        }
    }
#endif
}

bool
IceInternal::ThreadPool::ioCompleted(ThreadPoolCurrent& current)
{
    IceUtil::Monitor<IceUtil::Mutex>::Lock sync(*this);

    current._ioCompleted = true; // Set the IO completed flag to specifiy that ioCompleted() has been called.

    current._thread->setState(ThreadState::ThreadStateInUseForUser);

    if(_maxSize > 1)
    {

#if !defined(ICE_USE_IOCP)
        --_inUseIO;

        if(!_destroyed)
        {
            if(_serialize && current._handler.get() != _workQueue.get())
            {
                _selector.disable(current._handler.get(), current.operation);
            }
        }

        if(current._leader)
        {
            //
            // If this thread is still the leader, it's time to promote a new leader.
            //
            promoteFollower(current);
        }
        else if(_promote && (_nextHandler != _handlers.end() || _inUseIO == 0))
        {
            notify();
        }
#endif

        assert(_inUse >= 0);
        ++_inUse;

        if(_inUse == _warnSize)
        {
            Warning out(_instance->initializationData().logger);
            out << "thread pool `" << _prefix << "' is running low on threads\n"
                << "Size=" << _size << ", " << "MaxSize=" << _maxSize << ", " << "WarnSize=" << _warnSize;
        }

        if(!_destroyed)
        {
            assert(_inUse <= static_cast<int>(_threads.size()));
            if(_inUse < _maxSize && _inUse == static_cast<int>(_threads.size()))
            {
                if(_instance->traceLevels()->threadPool >= 1)
                {
                    Trace out(_instance->initializationData().logger, _instance->traceLevels()->threadPoolCat);
                    out << "growing " << _prefix << ": Size=" << _threads.size() + 1;
                }

                try
                {
                    EventHandlerThreadPtr thread = new EventHandlerThread(this, nextThreadId());
                    if(_hasPriority)
                    {
                        thread->start(_stackSize, _priority);
                    }
                    else
                    {
                        thread->start(_stackSize);
                    }
                    _threads.insert(thread);
                }
                catch(const IceUtil::Exception& ex)
                {
                    Error out(_instance->initializationData().logger);
                    out << "cannot create thread for `" << _prefix << "':\n" << ex;
                }
            }
        }
    }

    return _serialize && current._handler.get() != _workQueue.get();
}

#if defined(ICE_USE_IOCP)
bool
IceInternal::ThreadPool::startMessage(ThreadPoolCurrent& current)
{
    assert(current._handler->_pending & current.operation);

    if(current._handler->_started & current.operation)
    {
        assert(!(current._handler->_completed & current.operation));
        current._handler->_completed = static_cast<SocketOperation>(current._handler->_completed | current.operation);
        current._handler->_started = static_cast<SocketOperation>(current._handler->_started & ~current.operation);

        AsyncInfo* info = current._handler->getNativeInfo()->getAsyncInfo(current.operation);
        info->count = current._count;
        info->error = current._error;

        if(!current._handler->finishAsync(current.operation)) // Returns false if the handler is finished.
        {
            current._handler->_pending = static_cast<SocketOperation>(current._handler->_pending & ~current.operation);
            if(!current._handler->_pending && current._handler->_finish)
            {
                Lock sync(*this);
                _workQueue->queue(new FinishedWorkItem(current._handler, false));
                _selector.finish(current._handler.get());
            }
            return false;
        }
    }
    else if(!(current._handler->_completed & current.operation) && (current._handler->_registered & current.operation))
    {
        assert(!(current._handler->_started & current.operation));
        if(current._handler->_ready & current.operation)
        {
            return true;
        }
        else if(!current._handler->startAsync(current.operation))
        {
            current._handler->_pending = static_cast<SocketOperation>(current._handler->_pending & ~current.operation);
            if(!current._handler->_pending && current._handler->_finish)
            {
                Lock sync(*this);
                _workQueue->queue(new FinishedWorkItem(current._handler, false));
                _selector.finish(current._handler.get());
            }
            return false;
        }
        else
        {
            current._handler->_started = static_cast<SocketOperation>(current._handler->_started | current.operation);
            return false;
        }
    }

    if(current._handler->_registered & current.operation)
    {
        assert(current._handler->_completed & current.operation);
        current._handler->_completed = static_cast<SocketOperation>(current._handler->_completed & ~current.operation);
        return true;
    }
    else
    {
        current._handler->_pending = static_cast<SocketOperation>(current._handler->_pending & ~current.operation);
        if(!current._handler->_pending && current._handler->_finish)
        {
            Lock sync(*this);
            _workQueue->queue(new FinishedWorkItem(current._handler, false));
            _selector.finish(current._handler.get());
        }
        return false;
    }
}

void
IceInternal::ThreadPool::finishMessage(ThreadPoolCurrent& current)
{
    if(current._handler->_registered & current.operation && !current._handler->_finish)
    {
        assert(!(current._handler->_completed & current.operation));
        if(current._handler->_ready & current.operation)
        {
            _selector.completed(current._handler.get(), current.operation);
        }
        else if(!current._handler->startAsync(current.operation))
        {
            current._handler->_pending = static_cast<SocketOperation>(current._handler->_pending & ~current.operation);
        }
        else
        {
            assert(current._handler->_pending & current.operation);
            current._handler->_started = static_cast<SocketOperation>(current._handler->_started | current.operation);
        }
    }
    else
    {
        current._handler->_pending = static_cast<SocketOperation>(current._handler->_pending & ~current.operation);
    }

    if(!current._handler->_pending && current._handler->_finish)
    {
        // There are no more pending async operations, it's time to call finish.
        Lock sync(*this);
        _workQueue->queue(new FinishedWorkItem(current._handler, false));
        _selector.finish(current._handler.get());
    }
}
#else
void
IceInternal::ThreadPool::promoteFollower(ThreadPoolCurrent& current)
{
    assert(!_promote && current._leader);
    _promote = true;
    if(_inUseIO < _sizeIO && (_nextHandler != _handlers.end() || _inUseIO == 0))
    {
        notify();
    }
    current._leader = false;
}

bool
IceInternal::ThreadPool::followerWait(ThreadPoolCurrent& current)
{
    assert(!current._leader);

    current._thread->setState(ThreadState::ThreadStateIdle);

    //
    // It's important to clear the handler before waiting to make sure that
    // resources for the handler are released now if it's finished. We also
    // clear the per-thread stream.
    //
    current._handler = 0;
    current.stream.clear();
    current.stream.b.clear();

    //
    // Wait to be promoted and for all the IO threads to be done.
    //
    while(!_promote || _inUseIO == _sizeIO || (_nextHandler == _handlers.end() && _inUseIO > 0))
    {
        if(_threadIdleTime)
        {
            if(!timedWait(IceUtil::Time::seconds(_threadIdleTime)))
            {
                if(!_destroyed && (!_promote || _inUseIO == _sizeIO ||
                                   (_nextHandler == _handlers.end() && _inUseIO > 0)))
                {
                    if(_instance->traceLevels()->threadPool >= 1)
                    {
                        Trace out(_instance->initializationData().logger, _instance->traceLevels()->threadPoolCat);
                        out << "shrinking " << _prefix << ": Size=" << (_threads.size() - 1);
                    }
                    assert(_threads.size() > 1); // Can only be called by a waiting follower thread.
                    _threads.erase(current._thread);
                    _workQueue->queue(new JoinThreadWorkItem(current._thread));
                    return true;
                }
            }
        }
        else
        {
            wait();
        }
    }
    current._leader = true; // The current thread has become the leader.
    _promote = false;
    return false;
}
#endif

string
IceInternal::ThreadPool::nextThreadId()
{
    ostringstream os;
    os << _prefix << "-" << _nextThreadId++;
    return os.str();
}

IceInternal::ThreadPool::EventHandlerThread::EventHandlerThread(const ThreadPoolPtr& pool, const string& name) :
    IceUtil::Thread(name),
    _pool(pool),
    _state(ThreadState::ThreadStateIdle)
{
    updateObserver();
}

void
IceInternal::ThreadPool::EventHandlerThread::updateObserver()
{
    // Must be called with the thread pool mutex locked
    const CommunicatorObserverPtr& obsv = _pool->_instance->initializationData().observer;
    if(obsv)
    {
        _observer.attach(obsv->getThreadObserver(_pool->_prefix, name(), _state, _observer.get()));
    }
}

void
IceInternal::ThreadPool::EventHandlerThread::setState(Ice::Instrumentation::ThreadState s)
{
    // Must be called with the thread pool mutex locked
    if(_observer)
    {
        if(_state != s)
        {
            _observer->stateChanged(_state, s);
        }
    }
    _state = s;
}

void
IceInternal::ThreadPool::EventHandlerThread::run()
{
    if(_pool->_instance->initializationData().threadStart)
    {
        try
        {
            _pool->_instance->initializationData().threadStart();
        }
        catch(const exception& ex)
        {
            Error out(_pool->_instance->initializationData().logger);
            out << "thread hook start() method raised an unexpected exception in `" << _pool->_prefix << "':\n" << ex;
        }
        catch(...)
        {
            Error out(_pool->_instance->initializationData().logger);
            out << "thread hook start() method raised an unexpected exception in `" << _pool->_prefix << "'";
        }
    }

    try
    {
        _pool->run(this);
    }
    catch(const exception& ex)
    {
        Error out(_pool->_instance->initializationData().logger);
        out << "exception in `" << _pool->_prefix << "':\n" << ex;
    }
    catch(...)
    {
        Error out(_pool->_instance->initializationData().logger);
        out << "unknown exception in `" << _pool->_prefix << "'";
    }

    _observer.detach();

    if(_pool->_instance->initializationData().threadStop)
    {
        try
        {
            _pool->_instance->initializationData().threadStop();
        }
        catch(const exception& ex)
        {
            Error out(_pool->_instance->initializationData().logger);
            out << "thread hook stop() method raised an unexpected exception in `" << _pool->_prefix << "':\n" << ex;
        }
        catch(...)
        {
            Error out(_pool->_instance->initializationData().logger);
            out << "thread hook stop() method raised an unexpected exception in `" << _pool->_prefix << "'";
        }
    }

    _pool = 0; // Break cyclic dependency.
}

ThreadPoolCurrent::ThreadPoolCurrent(const InstancePtr& instance,
                                     const ThreadPoolPtr& threadPool,
                                     const ThreadPool::EventHandlerThreadPtr& thread) :
    operation(SocketOperationNone),
    stream(instance.get(), Ice::currentProtocolEncoding),
    _threadPool(threadPool.get()),
    _thread(thread),
    _ioCompleted(false)
#if !defined(ICE_USE_IOCP)
    , _leader(false)
#endif
{
}
