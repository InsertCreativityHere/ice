//
// Copyright (c) ZeroC, Inc. All rights reserved.
//

#ifndef __Ice_LocalException_h__
#define __Ice_LocalException_h__

#include <IceUtil/PushDisableWarnings.h>
#include <Ice/ProxyF.h>
#include <Ice/ObjectF.h>
#include <Ice/ValueF.h>
#include <Ice/Exception.h>
#include <Ice/LocalObject.h>
#include <Ice/StreamHelpers.h>
#include <Ice/Comparable.h>
#include <optional>
#include <Ice/ExceptionHelpers.h>
#include <Ice/Identity.h>
#include <Ice/Version.h>
#include <Ice/BuiltinSequences.h>
#include <IceUtil/UndefSysMacros.h>

#ifndef ICE_API
#   if defined(ICE_STATIC_LIBS)
#       define ICE_API /**/
#   elif defined(ICE_API_EXPORTS)
#       define ICE_API ICE_DECLSPEC_EXPORT
#   else
#       define ICE_API ICE_DECLSPEC_IMPORT
#   endif
#endif

namespace Ice
{

/**
 * This exception is raised when a failure occurs during initialization.
 * \headerfile Ice/Ice.h
 */
class ICE_CLASS(ICE_API) InitializationException : public LocalExceptionHelper<InitializationException, LocalException>
{
public:

    ICE_MEMBER(ICE_API) virtual ~InitializationException();

    InitializationException(const InitializationException&) = default;

    /**
     * The file and line number are required for all local exceptions.
     * @param file The file name in which the exception was raised, typically __FILE__.
     * @param line The line number at which the exception was raised, typically __LINE__.
     */
    InitializationException(const char* file, int line) : LocalExceptionHelper<InitializationException, LocalException>(file, line)
    {
    }

    /**
     * One-shot constructor to initialize all data members.
     * The file and line number are required for all local exceptions.
     * @param file The file name in which the exception was raised, typically __FILE__.
     * @param line The line number at which the exception was raised, typically __LINE__.
     * @param reason The reason for the failure.
     */
    InitializationException(const char* file, int line, const ::std::string& reason) : LocalExceptionHelper<InitializationException, LocalException>(file, line),
        reason(reason)
    {
    }

    /**
     * Obtains a tuple containing all of the exception's data members.
     * @return The data members in a tuple.
     */
    std::tuple<const ::std::string&> ice_tuple() const
    {
        return std::tie(reason);
    }

    /**
     * Obtains the Slice type ID of this exception.
     * @return The fully-scoped type ID.
     */
    ICE_MEMBER(ICE_API) static const ::std::string& ice_staticId();
    /**
     * Prints this exception to the given stream.
     * @param stream The target stream.
     */
    ICE_MEMBER(ICE_API) virtual void ice_print(::std::ostream& stream) const override;

    /**
     * The reason for the failure.
     */
    ::std::string reason;
};

/**
 * This exception indicates that a failure occurred while initializing a plug-in.
 * \headerfile Ice/Ice.h
 */
class ICE_CLASS(ICE_API) PluginInitializationException : public LocalExceptionHelper<PluginInitializationException, LocalException>
{
public:

    ICE_MEMBER(ICE_API) virtual ~PluginInitializationException();

    PluginInitializationException(const PluginInitializationException&) = default;

    /**
     * The file and line number are required for all local exceptions.
     * @param file The file name in which the exception was raised, typically __FILE__.
     * @param line The line number at which the exception was raised, typically __LINE__.
     */
    PluginInitializationException(const char* file, int line) : LocalExceptionHelper<PluginInitializationException, LocalException>(file, line)
    {
    }

    /**
     * One-shot constructor to initialize all data members.
     * The file and line number are required for all local exceptions.
     * @param file The file name in which the exception was raised, typically __FILE__.
     * @param line The line number at which the exception was raised, typically __LINE__.
     * @param reason The reason for the failure.
     */
    PluginInitializationException(const char* file, int line, const ::std::string& reason) : LocalExceptionHelper<PluginInitializationException, LocalException>(file, line),
        reason(reason)
    {
    }

    /**
     * Obtains a tuple containing all of the exception's data members.
     * @return The data members in a tuple.
     */
    std::tuple<const ::std::string&> ice_tuple() const
    {
        return std::tie(reason);
    }

    /**
     * Obtains the Slice type ID of this exception.
     * @return The fully-scoped type ID.
     */
    ICE_MEMBER(ICE_API) static const ::std::string& ice_staticId();
    /**
     * Prints this exception to the given stream.
     * @param stream The target stream.
     */
    ICE_MEMBER(ICE_API) virtual void ice_print(::std::ostream& stream) const override;

    /**
     * The reason for the failure.
     */
    ::std::string reason;
};

/**
 * This exception is raised if a feature is requested that is not supported with collocation optimization.
 *
 * @deprecated This exception is no longer used by the Ice run time
 * \headerfile Ice/Ice.h
 */
class ICE_CLASS(ICE_API) CollocationOptimizationException : public LocalExceptionHelper<CollocationOptimizationException, LocalException>
{
public:

    ICE_MEMBER(ICE_API) virtual ~CollocationOptimizationException();

    CollocationOptimizationException(const CollocationOptimizationException&) = default;

    /**
     * The file and line number are required for all local exceptions.
     * @param file The file name in which the exception was raised, typically __FILE__.
     * @param line The line number at which the exception was raised, typically __LINE__.
     */
    CollocationOptimizationException(const char* file, int line) : LocalExceptionHelper<CollocationOptimizationException, LocalException>(file, line)
    {
    }

    /**
     * Obtains a tuple containing all of the exception's data members.
     * @return The data members in a tuple.
     */
    std::tuple<> ice_tuple() const
    {
        return std::tie();
    }

    /**
     * Obtains the Slice type ID of this exception.
     * @return The fully-scoped type ID.
     */
    ICE_MEMBER(ICE_API) static const ::std::string& ice_staticId();
    /**
     * Prints this exception to the given stream.
     * @param stream The target stream.
     */
    ICE_MEMBER(ICE_API) virtual void ice_print(::std::ostream& stream) const override;
};

/**
 * An attempt was made to register something more than once with the Ice run time. This exception is raised if an
 * attempt is made to register a servant, servant locator, facet, value factory, plug-in, object adapter, object, or
 * user exception factory more than once for the same ID.
 * \headerfile Ice/Ice.h
 */
class ICE_CLASS(ICE_API) AlreadyRegisteredException : public LocalExceptionHelper<AlreadyRegisteredException, LocalException>
{
public:

    ICE_MEMBER(ICE_API) virtual ~AlreadyRegisteredException();

    AlreadyRegisteredException(const AlreadyRegisteredException&) = default;

    /**
     * The file and line number are required for all local exceptions.
     * @param file The file name in which the exception was raised, typically __FILE__.
     * @param line The line number at which the exception was raised, typically __LINE__.
     */
    AlreadyRegisteredException(const char* file, int line) : LocalExceptionHelper<AlreadyRegisteredException, LocalException>(file, line)
    {
    }

    /**
     * One-shot constructor to initialize all data members.
     * The file and line number are required for all local exceptions.
     * @param file The file name in which the exception was raised, typically __FILE__.
     * @param line The line number at which the exception was raised, typically __LINE__.
     * @param kindOfObject The kind of object that could not be removed: "servant", "facet", "object", "default servant", "servant locator", "value factory", "plugin", "object adapter", "object adapter with router", "replica group".
     * @param id The ID (or name) of the object that is registered already.
     */
    AlreadyRegisteredException(const char* file, int line, const ::std::string& kindOfObject, const ::std::string& id) : LocalExceptionHelper<AlreadyRegisteredException, LocalException>(file, line),
        kindOfObject(kindOfObject),
        id(id)
    {
    }

    /**
     * Obtains a tuple containing all of the exception's data members.
     * @return The data members in a tuple.
     */
    std::tuple<const ::std::string&, const ::std::string&> ice_tuple() const
    {
        return std::tie(kindOfObject, id);
    }

    /**
     * Obtains the Slice type ID of this exception.
     * @return The fully-scoped type ID.
     */
    ICE_MEMBER(ICE_API) static const ::std::string& ice_staticId();
    /**
     * Prints this exception to the given stream.
     * @param stream The target stream.
     */
    ICE_MEMBER(ICE_API) virtual void ice_print(::std::ostream& stream) const override;

    /**
     * The kind of object that could not be removed: "servant", "facet", "object", "default servant",
     * "servant locator", "value factory", "plugin", "object adapter", "object adapter with router", "replica group".
     */
    ::std::string kindOfObject;
    /**
     * The ID (or name) of the object that is registered already.
     */
    ::std::string id;
};

/**
 * An attempt was made to find or deregister something that is not registered with the Ice run time or Ice locator.
 * This exception is raised if an attempt is made to remove a servant, servant locator, facet, value factory, plug-in,
 * object adapter, object, or user exception factory that is not currently registered. It's also raised if the Ice
 * locator can't find an object or object adapter when resolving an indirect proxy or when an object adapter is
 * activated.
 * \headerfile Ice/Ice.h
 */
class ICE_CLASS(ICE_API) NotRegisteredException : public LocalExceptionHelper<NotRegisteredException, LocalException>
{
public:

    ICE_MEMBER(ICE_API) virtual ~NotRegisteredException();

    NotRegisteredException(const NotRegisteredException&) = default;

    /**
     * The file and line number are required for all local exceptions.
     * @param file The file name in which the exception was raised, typically __FILE__.
     * @param line The line number at which the exception was raised, typically __LINE__.
     */
    NotRegisteredException(const char* file, int line) : LocalExceptionHelper<NotRegisteredException, LocalException>(file, line)
    {
    }

    /**
     * One-shot constructor to initialize all data members.
     * The file and line number are required for all local exceptions.
     * @param file The file name in which the exception was raised, typically __FILE__.
     * @param line The line number at which the exception was raised, typically __LINE__.
     * @param kindOfObject The kind of object that could not be removed: "servant", "facet", "object", "default servant", "servant locator", "value factory", "plugin", "object adapter", "object adapter with router", "replica group".
     * @param id The ID (or name) of the object that could not be removed.
     */
    NotRegisteredException(const char* file, int line, const ::std::string& kindOfObject, const ::std::string& id) : LocalExceptionHelper<NotRegisteredException, LocalException>(file, line),
        kindOfObject(kindOfObject),
        id(id)
    {
    }

    /**
     * Obtains a tuple containing all of the exception's data members.
     * @return The data members in a tuple.
     */
    std::tuple<const ::std::string&, const ::std::string&> ice_tuple() const
    {
        return std::tie(kindOfObject, id);
    }

    /**
     * Obtains the Slice type ID of this exception.
     * @return The fully-scoped type ID.
     */
    ICE_MEMBER(ICE_API) static const ::std::string& ice_staticId();
    /**
     * Prints this exception to the given stream.
     * @param stream The target stream.
     */
    ICE_MEMBER(ICE_API) virtual void ice_print(::std::ostream& stream) const override;

    /**
     * The kind of object that could not be removed: "servant", "facet", "object", "default servant",
     * "servant locator", "value factory", "plugin", "object adapter", "object adapter with router", "replica group".
     */
    ::std::string kindOfObject;
    /**
     * The ID (or name) of the object that could not be removed.
     */
    ::std::string id;
};

/**
 * The operation can only be invoked with a twoway request. This exception is raised if an attempt is made to invoke
 * an operation with <code>ice_oneway</code>, <code>ice_batchOneway</code>, <code>ice_datagram</code>, or
 * <code>ice_batchDatagram</code> and the operation has a return value, out-parameters, or an exception specification.
 * \headerfile Ice/Ice.h
 */
class ICE_CLASS(ICE_API) TwowayOnlyException : public LocalExceptionHelper<TwowayOnlyException, LocalException>
{
public:

    ICE_MEMBER(ICE_API) virtual ~TwowayOnlyException();

    TwowayOnlyException(const TwowayOnlyException&) = default;

    /**
     * The file and line number are required for all local exceptions.
     * @param file The file name in which the exception was raised, typically __FILE__.
     * @param line The line number at which the exception was raised, typically __LINE__.
     */
    TwowayOnlyException(const char* file, int line) : LocalExceptionHelper<TwowayOnlyException, LocalException>(file, line)
    {
    }

    /**
     * One-shot constructor to initialize all data members.
     * The file and line number are required for all local exceptions.
     * @param file The file name in which the exception was raised, typically __FILE__.
     * @param line The line number at which the exception was raised, typically __LINE__.
     * @param operation The name of the operation that was invoked.
     */
    TwowayOnlyException(const char* file, int line, const ::std::string& operation) : LocalExceptionHelper<TwowayOnlyException, LocalException>(file, line),
        operation(operation)
    {
    }

    /**
     * Obtains a tuple containing all of the exception's data members.
     * @return The data members in a tuple.
     */
    std::tuple<const ::std::string&> ice_tuple() const
    {
        return std::tie(operation);
    }

    /**
     * Obtains the Slice type ID of this exception.
     * @return The fully-scoped type ID.
     */
    ICE_MEMBER(ICE_API) static const ::std::string& ice_staticId();
    /**
     * Prints this exception to the given stream.
     * @param stream The target stream.
     */
    ICE_MEMBER(ICE_API) virtual void ice_print(::std::ostream& stream) const override;

    /**
     * The name of the operation that was invoked.
     */
    ::std::string operation;
};

/**
 * An attempt was made to clone a class that does not support cloning. This exception is raised if
 * <code>ice_clone</code> is called on a class that is derived from an abstract Slice class (that is, a class
 * containing operations), and the derived class does not provide an implementation of the <code>ice_clone</code>
 * operation (C++ only).
 * \headerfile Ice/Ice.h
 */
class ICE_CLASS(ICE_API) CloneNotImplementedException : public LocalExceptionHelper<CloneNotImplementedException, LocalException>
{
public:

    ICE_MEMBER(ICE_API) virtual ~CloneNotImplementedException();

    CloneNotImplementedException(const CloneNotImplementedException&) = default;

    /**
     * The file and line number are required for all local exceptions.
     * @param file The file name in which the exception was raised, typically __FILE__.
     * @param line The line number at which the exception was raised, typically __LINE__.
     */
    CloneNotImplementedException(const char* file, int line) : LocalExceptionHelper<CloneNotImplementedException, LocalException>(file, line)
    {
    }

    /**
     * Obtains a tuple containing all of the exception's data members.
     * @return The data members in a tuple.
     */
    std::tuple<> ice_tuple() const
    {
        return std::tie();
    }

    /**
     * Obtains the Slice type ID of this exception.
     * @return The fully-scoped type ID.
     */
    ICE_MEMBER(ICE_API) static const ::std::string& ice_staticId();
    /**
     * Prints this exception to the given stream.
     * @param stream The target stream.
     */
    ICE_MEMBER(ICE_API) virtual void ice_print(::std::ostream& stream) const override;
};

/**
 * This exception is raised if an operation call on a server raises an unknown exception. For example, for C++, this
 * exception is raised if the server throws a C++ exception that is not directly or indirectly derived from
 * <code>Ice::LocalException</code> or <code>Ice::UserException</code>.
 * \headerfile Ice/Ice.h
 */
class ICE_CLASS(ICE_API) UnknownException : public LocalExceptionHelper<UnknownException, LocalException>
{
public:

    ICE_MEMBER(ICE_API) virtual ~UnknownException();

    UnknownException(const UnknownException&) = default;

    /**
     * The file and line number are required for all local exceptions.
     * @param file The file name in which the exception was raised, typically __FILE__.
     * @param line The line number at which the exception was raised, typically __LINE__.
     */
    UnknownException(const char* file, int line) : LocalExceptionHelper<UnknownException, LocalException>(file, line)
    {
    }

    /**
     * One-shot constructor to initialize all data members.
     * The file and line number are required for all local exceptions.
     * @param file The file name in which the exception was raised, typically __FILE__.
     * @param line The line number at which the exception was raised, typically __LINE__.
     * @param unknown This field is set to the textual representation of the unknown exception if available.
     */
    UnknownException(const char* file, int line, const ::std::string& unknown) : LocalExceptionHelper<UnknownException, LocalException>(file, line),
        unknown(unknown)
    {
    }

    /**
     * Obtains a tuple containing all of the exception's data members.
     * @return The data members in a tuple.
     */
    std::tuple<const ::std::string&> ice_tuple() const
    {
        return std::tie(unknown);
    }

    /**
     * Obtains the Slice type ID of this exception.
     * @return The fully-scoped type ID.
     */
    ICE_MEMBER(ICE_API) static const ::std::string& ice_staticId();
    /**
     * Prints this exception to the given stream.
     * @param stream The target stream.
     */
    ICE_MEMBER(ICE_API) virtual void ice_print(::std::ostream& stream) const override;

    /**
     * This field is set to the textual representation of the unknown exception if available.
     */
    ::std::string unknown;
};

/**
 * This exception is raised if an operation call on a server raises a  local exception. Because local exceptions are
 * not transmitted by the Ice protocol, the client receives all local exceptions raised by the server as
 * {@link UnknownLocalException}. The only exception to this rule are all exceptions derived from
 * {@link RequestFailedException}, which are transmitted by the Ice protocol even though they are declared
 * <code>local</code>.
 * \headerfile Ice/Ice.h
 */
class ICE_CLASS(ICE_API) UnknownLocalException : public LocalExceptionHelper<UnknownLocalException, UnknownException>
{
public:

    ICE_MEMBER(ICE_API) virtual ~UnknownLocalException();

    UnknownLocalException(const UnknownLocalException&) = default;

    /**
     * The file and line number are required for all local exceptions.
     * @param file The file name in which the exception was raised, typically __FILE__.
     * @param line The line number at which the exception was raised, typically __LINE__.
     */
    UnknownLocalException(const char* file, int line) : LocalExceptionHelper<UnknownLocalException, UnknownException>(file, line)
    {
    }

    /**
     * One-shot constructor to initialize all data members.
     * The file and line number are required for all local exceptions.
     * @param file The file name in which the exception was raised, typically __FILE__.
     * @param line The line number at which the exception was raised, typically __LINE__.
     * @param unknown This field is set to the textual representation of the unknown exception if available.
     */
    UnknownLocalException(const char* file, int line, const ::std::string& unknown) :
        LocalExceptionHelper<UnknownLocalException, UnknownException>(file, line, unknown)
    {
    }

    /**
     * Obtains a tuple containing all of the exception's data members.
     * @return The data members in a tuple.
     */
    std::tuple<const ::std::string&> ice_tuple() const
    {
        return std::tie(unknown);
    }

    /**
     * Obtains the Slice type ID of this exception.
     * @return The fully-scoped type ID.
     */
    ICE_MEMBER(ICE_API) static const ::std::string& ice_staticId();
    /**
     * Prints this exception to the given stream.
     * @param stream The target stream.
     */
    ICE_MEMBER(ICE_API) virtual void ice_print(::std::ostream& stream) const override;
};

/**
 * An operation raised an incorrect user exception. This exception is raised if an operation raises a user exception
 * that is not declared in the exception's <code>throws</code> clause. Such undeclared exceptions are not transmitted
 * from the server to the client by the Ice protocol, but instead the client just gets an {@link UnknownUserException}.
 * This is necessary in order to not violate the contract established by an operation's signature: Only local
 * exceptions and user exceptions declared in the <code>throws</code> clause can be raised.
 * \headerfile Ice/Ice.h
 */
class ICE_CLASS(ICE_API) UnknownUserException : public LocalExceptionHelper<UnknownUserException, UnknownException>
{
public:

    ICE_MEMBER(ICE_API) virtual ~UnknownUserException();

    UnknownUserException(const UnknownUserException&) = default;

    /**
     * The file and line number are required for all local exceptions.
     * @param file The file name in which the exception was raised, typically __FILE__.
     * @param line The line number at which the exception was raised, typically __LINE__.
     */
    UnknownUserException(const char* file, int line) : LocalExceptionHelper<UnknownUserException, UnknownException>(file, line)
    {
    }

    /**
     * One-shot constructor to initialize all data members.
     * The file and line number are required for all local exceptions.
     * @param file The file name in which the exception was raised, typically __FILE__.
     * @param line The line number at which the exception was raised, typically __LINE__.
     * @param unknown This field is set to the textual representation of the unknown exception if available.
     */
    UnknownUserException(const char* file, int line, const ::std::string& unknown) :
        LocalExceptionHelper<UnknownUserException, UnknownException>(file, line, unknown)
    {
    }

    /**
     * Obtains a tuple containing all of the exception's data members.
     * @return The data members in a tuple.
     */
    std::tuple<const ::std::string&> ice_tuple() const
    {
        return std::tie(unknown);
    }

    /**
     * Obtains the Slice type ID of this exception.
     * @return The fully-scoped type ID.
     */
    ICE_MEMBER(ICE_API) static const ::std::string& ice_staticId();
    /**
     * Prints this exception to the given stream.
     * @param stream The target stream.
     */
    ICE_MEMBER(ICE_API) virtual void ice_print(::std::ostream& stream) const override;
};

/**
 * This exception is raised if the Ice library version does not match the version in the Ice header files.
 * \headerfile Ice/Ice.h
 */
class ICE_CLASS(ICE_API) VersionMismatchException : public LocalExceptionHelper<VersionMismatchException, LocalException>
{
public:

    ICE_MEMBER(ICE_API) virtual ~VersionMismatchException();

    VersionMismatchException(const VersionMismatchException&) = default;

    /**
     * The file and line number are required for all local exceptions.
     * @param file The file name in which the exception was raised, typically __FILE__.
     * @param line The line number at which the exception was raised, typically __LINE__.
     */
    VersionMismatchException(const char* file, int line) : LocalExceptionHelper<VersionMismatchException, LocalException>(file, line)
    {
    }

    /**
     * Obtains a tuple containing all of the exception's data members.
     * @return The data members in a tuple.
     */
    std::tuple<> ice_tuple() const
    {
        return std::tie();
    }

    /**
     * Obtains the Slice type ID of this exception.
     * @return The fully-scoped type ID.
     */
    ICE_MEMBER(ICE_API) static const ::std::string& ice_staticId();
    /**
     * Prints this exception to the given stream.
     * @param stream The target stream.
     */
    ICE_MEMBER(ICE_API) virtual void ice_print(::std::ostream& stream) const override;
};

/**
 * This exception is raised if the {@link Communicator} has been destroyed.
 * @see Communicator#destroy
 * \headerfile Ice/Ice.h
 */
class ICE_CLASS(ICE_API) CommunicatorDestroyedException : public LocalExceptionHelper<CommunicatorDestroyedException, LocalException>
{
public:

    ICE_MEMBER(ICE_API) virtual ~CommunicatorDestroyedException();

    CommunicatorDestroyedException(const CommunicatorDestroyedException&) = default;

    /**
     * The file and line number are required for all local exceptions.
     * @param file The file name in which the exception was raised, typically __FILE__.
     * @param line The line number at which the exception was raised, typically __LINE__.
     */
    CommunicatorDestroyedException(const char* file, int line) : LocalExceptionHelper<CommunicatorDestroyedException, LocalException>(file, line)
    {
    }

    /**
     * Obtains a tuple containing all of the exception's data members.
     * @return The data members in a tuple.
     */
    std::tuple<> ice_tuple() const
    {
        return std::tie();
    }

    /**
     * Obtains the Slice type ID of this exception.
     * @return The fully-scoped type ID.
     */
    ICE_MEMBER(ICE_API) static const ::std::string& ice_staticId();
    /**
     * Prints this exception to the given stream.
     * @param stream The target stream.
     */
    ICE_MEMBER(ICE_API) virtual void ice_print(::std::ostream& stream) const override;
};

/**
 * This exception is raised if an attempt is made to use a deactivated {@link ObjectAdapter}.
 * @see ObjectAdapter#deactivate
 * @see Communicator#shutdown
 * \headerfile Ice/Ice.h
 */
class ICE_CLASS(ICE_API) ObjectAdapterDeactivatedException : public LocalExceptionHelper<ObjectAdapterDeactivatedException, LocalException>
{
public:

    ICE_MEMBER(ICE_API) virtual ~ObjectAdapterDeactivatedException();

    ObjectAdapterDeactivatedException(const ObjectAdapterDeactivatedException&) = default;

    /**
     * The file and line number are required for all local exceptions.
     * @param file The file name in which the exception was raised, typically __FILE__.
     * @param line The line number at which the exception was raised, typically __LINE__.
     */
    ObjectAdapterDeactivatedException(const char* file, int line) : LocalExceptionHelper<ObjectAdapterDeactivatedException, LocalException>(file, line)
    {
    }

    /**
     * One-shot constructor to initialize all data members.
     * The file and line number are required for all local exceptions.
     * @param file The file name in which the exception was raised, typically __FILE__.
     * @param line The line number at which the exception was raised, typically __LINE__.
     * @param name Name of the adapter.
     */
    ObjectAdapterDeactivatedException(const char* file, int line, const ::std::string& name) : LocalExceptionHelper<ObjectAdapterDeactivatedException, LocalException>(file, line),
        name(name)
    {
    }

    /**
     * Obtains a tuple containing all of the exception's data members.
     * @return The data members in a tuple.
     */
    std::tuple<const ::std::string&> ice_tuple() const
    {
        return std::tie(name);
    }

    /**
     * Obtains the Slice type ID of this exception.
     * @return The fully-scoped type ID.
     */
    ICE_MEMBER(ICE_API) static const ::std::string& ice_staticId();
    /**
     * Prints this exception to the given stream.
     * @param stream The target stream.
     */
    ICE_MEMBER(ICE_API) virtual void ice_print(::std::ostream& stream) const override;

    /**
     * Name of the adapter.
     */
    ::std::string name;
};

/**
 * This exception is raised if an {@link ObjectAdapter} cannot be activated. This happens if the {@link Locator}
 * detects another active {@link ObjectAdapter} with the same adapter id.
 * \headerfile Ice/Ice.h
 */
class ICE_CLASS(ICE_API) ObjectAdapterIdInUseException : public LocalExceptionHelper<ObjectAdapterIdInUseException, LocalException>
{
public:

    ICE_MEMBER(ICE_API) virtual ~ObjectAdapterIdInUseException();

    ObjectAdapterIdInUseException(const ObjectAdapterIdInUseException&) = default;

    /**
     * The file and line number are required for all local exceptions.
     * @param file The file name in which the exception was raised, typically __FILE__.
     * @param line The line number at which the exception was raised, typically __LINE__.
     */
    ObjectAdapterIdInUseException(const char* file, int line) : LocalExceptionHelper<ObjectAdapterIdInUseException, LocalException>(file, line)
    {
    }

    /**
     * One-shot constructor to initialize all data members.
     * The file and line number are required for all local exceptions.
     * @param file The file name in which the exception was raised, typically __FILE__.
     * @param line The line number at which the exception was raised, typically __LINE__.
     * @param id Adapter ID.
     */
    ObjectAdapterIdInUseException(const char* file, int line, const ::std::string& id) : LocalExceptionHelper<ObjectAdapterIdInUseException, LocalException>(file, line),
        id(id)
    {
    }

    /**
     * Obtains a tuple containing all of the exception's data members.
     * @return The data members in a tuple.
     */
    std::tuple<const ::std::string&> ice_tuple() const
    {
        return std::tie(id);
    }

    /**
     * Obtains the Slice type ID of this exception.
     * @return The fully-scoped type ID.
     */
    ICE_MEMBER(ICE_API) static const ::std::string& ice_staticId();
    /**
     * Prints this exception to the given stream.
     * @param stream The target stream.
     */
    ICE_MEMBER(ICE_API) virtual void ice_print(::std::ostream& stream) const override;

    /**
     * Adapter ID.
     */
    ::std::string id;
};

/**
 * This exception is raised if no suitable endpoint is available.
 * \headerfile Ice/Ice.h
 */
class ICE_CLASS(ICE_API) NoEndpointException : public LocalExceptionHelper<NoEndpointException, LocalException>
{
public:

    ICE_MEMBER(ICE_API) virtual ~NoEndpointException();

    NoEndpointException(const NoEndpointException&) = default;

    /**
     * The file and line number are required for all local exceptions.
     * @param file The file name in which the exception was raised, typically __FILE__.
     * @param line The line number at which the exception was raised, typically __LINE__.
     */
    NoEndpointException(const char* file, int line) : LocalExceptionHelper<NoEndpointException, LocalException>(file, line)
    {
    }

    /**
     * One-shot constructor to initialize all data members.
     * The file and line number are required for all local exceptions.
     * @param file The file name in which the exception was raised, typically __FILE__.
     * @param line The line number at which the exception was raised, typically __LINE__.
     * @param proxy The stringified proxy for which no suitable endpoint is available.
     */
    NoEndpointException(const char* file, int line, const ::std::string& proxy) : LocalExceptionHelper<NoEndpointException, LocalException>(file, line),
        proxy(proxy)
    {
    }

    /**
     * Obtains a tuple containing all of the exception's data members.
     * @return The data members in a tuple.
     */
    std::tuple<const ::std::string&> ice_tuple() const
    {
        return std::tie(proxy);
    }

    /**
     * Obtains the Slice type ID of this exception.
     * @return The fully-scoped type ID.
     */
    ICE_MEMBER(ICE_API) static const ::std::string& ice_staticId();
    /**
     * Prints this exception to the given stream.
     * @param stream The target stream.
     */
    ICE_MEMBER(ICE_API) virtual void ice_print(::std::ostream& stream) const override;

    /**
     * The stringified proxy for which no suitable endpoint is available.
     */
    ::std::string proxy;
};

/**
 * This exception is raised if there was an error while parsing an endpoint.
 * \headerfile Ice/Ice.h
 */
class ICE_CLASS(ICE_API) EndpointParseException : public LocalExceptionHelper<EndpointParseException, LocalException>
{
public:

    ICE_MEMBER(ICE_API) virtual ~EndpointParseException();

    EndpointParseException(const EndpointParseException&) = default;

    /**
     * The file and line number are required for all local exceptions.
     * @param file The file name in which the exception was raised, typically __FILE__.
     * @param line The line number at which the exception was raised, typically __LINE__.
     */
    EndpointParseException(const char* file, int line) : LocalExceptionHelper<EndpointParseException, LocalException>(file, line)
    {
    }

    /**
     * One-shot constructor to initialize all data members.
     * The file and line number are required for all local exceptions.
     * @param file The file name in which the exception was raised, typically __FILE__.
     * @param line The line number at which the exception was raised, typically __LINE__.
     * @param str Describes the failure and includes the string that could not be parsed.
     */
    EndpointParseException(const char* file, int line, const ::std::string& str) : LocalExceptionHelper<EndpointParseException, LocalException>(file, line),
        str(str)
    {
    }

    /**
     * Obtains a tuple containing all of the exception's data members.
     * @return The data members in a tuple.
     */
    std::tuple<const ::std::string&> ice_tuple() const
    {
        return std::tie(str);
    }

    /**
     * Obtains the Slice type ID of this exception.
     * @return The fully-scoped type ID.
     */
    ICE_MEMBER(ICE_API) static const ::std::string& ice_staticId();
    /**
     * Prints this exception to the given stream.
     * @param stream The target stream.
     */
    ICE_MEMBER(ICE_API) virtual void ice_print(::std::ostream& stream) const override;

    /**
     * Describes the failure and includes the string that could not be parsed.
     */
    ::std::string str;
};

/**
 * This exception is raised if there was an error while parsing an endpoint selection type.
 * \headerfile Ice/Ice.h
 */
class ICE_CLASS(ICE_API) EndpointSelectionTypeParseException : public LocalExceptionHelper<EndpointSelectionTypeParseException, LocalException>
{
public:

    ICE_MEMBER(ICE_API) virtual ~EndpointSelectionTypeParseException();

    EndpointSelectionTypeParseException(const EndpointSelectionTypeParseException&) = default;

    /**
     * The file and line number are required for all local exceptions.
     * @param file The file name in which the exception was raised, typically __FILE__.
     * @param line The line number at which the exception was raised, typically __LINE__.
     */
    EndpointSelectionTypeParseException(const char* file, int line) : LocalExceptionHelper<EndpointSelectionTypeParseException, LocalException>(file, line)
    {
    }

    /**
     * One-shot constructor to initialize all data members.
     * The file and line number are required for all local exceptions.
     * @param file The file name in which the exception was raised, typically __FILE__.
     * @param line The line number at which the exception was raised, typically __LINE__.
     * @param str Describes the failure and includes the string that could not be parsed.
     */
    EndpointSelectionTypeParseException(const char* file, int line, const ::std::string& str) : LocalExceptionHelper<EndpointSelectionTypeParseException, LocalException>(file, line),
        str(str)
    {
    }

    /**
     * Obtains a tuple containing all of the exception's data members.
     * @return The data members in a tuple.
     */
    std::tuple<const ::std::string&> ice_tuple() const
    {
        return std::tie(str);
    }

    /**
     * Obtains the Slice type ID of this exception.
     * @return The fully-scoped type ID.
     */
    ICE_MEMBER(ICE_API) static const ::std::string& ice_staticId();
    /**
     * Prints this exception to the given stream.
     * @param stream The target stream.
     */
    ICE_MEMBER(ICE_API) virtual void ice_print(::std::ostream& stream) const override;

    /**
     * Describes the failure and includes the string that could not be parsed.
     */
    ::std::string str;
};

/**
 * This exception is raised if there was an error while parsing a version.
 * \headerfile Ice/Ice.h
 */
class ICE_CLASS(ICE_API) VersionParseException : public LocalExceptionHelper<VersionParseException, LocalException>
{
public:

    ICE_MEMBER(ICE_API) virtual ~VersionParseException();

    VersionParseException(const VersionParseException&) = default;

    /**
     * The file and line number are required for all local exceptions.
     * @param file The file name in which the exception was raised, typically __FILE__.
     * @param line The line number at which the exception was raised, typically __LINE__.
     */
    VersionParseException(const char* file, int line) : LocalExceptionHelper<VersionParseException, LocalException>(file, line)
    {
    }

    /**
     * One-shot constructor to initialize all data members.
     * The file and line number are required for all local exceptions.
     * @param file The file name in which the exception was raised, typically __FILE__.
     * @param line The line number at which the exception was raised, typically __LINE__.
     * @param str Describes the failure and includes the string that could not be parsed.
     */
    VersionParseException(const char* file, int line, const ::std::string& str) : LocalExceptionHelper<VersionParseException, LocalException>(file, line),
        str(str)
    {
    }

    /**
     * Obtains a tuple containing all of the exception's data members.
     * @return The data members in a tuple.
     */
    std::tuple<const ::std::string&> ice_tuple() const
    {
        return std::tie(str);
    }

    /**
     * Obtains the Slice type ID of this exception.
     * @return The fully-scoped type ID.
     */
    ICE_MEMBER(ICE_API) static const ::std::string& ice_staticId();
    /**
     * Prints this exception to the given stream.
     * @param stream The target stream.
     */
    ICE_MEMBER(ICE_API) virtual void ice_print(::std::ostream& stream) const override;

    /**
     * Describes the failure and includes the string that could not be parsed.
     */
    ::std::string str;
};

/**
 * This exception is raised if there was an error while parsing a stringified identity.
 * \headerfile Ice/Ice.h
 */
class ICE_CLASS(ICE_API) IdentityParseException : public LocalExceptionHelper<IdentityParseException, LocalException>
{
public:

    ICE_MEMBER(ICE_API) virtual ~IdentityParseException();

    IdentityParseException(const IdentityParseException&) = default;

    /**
     * The file and line number are required for all local exceptions.
     * @param file The file name in which the exception was raised, typically __FILE__.
     * @param line The line number at which the exception was raised, typically __LINE__.
     */
    IdentityParseException(const char* file, int line) : LocalExceptionHelper<IdentityParseException, LocalException>(file, line)
    {
    }

    /**
     * One-shot constructor to initialize all data members.
     * The file and line number are required for all local exceptions.
     * @param file The file name in which the exception was raised, typically __FILE__.
     * @param line The line number at which the exception was raised, typically __LINE__.
     * @param str Describes the failure and includes the string that could not be parsed.
     */
    IdentityParseException(const char* file, int line, const ::std::string& str) : LocalExceptionHelper<IdentityParseException, LocalException>(file, line),
        str(str)
    {
    }

    /**
     * Obtains a tuple containing all of the exception's data members.
     * @return The data members in a tuple.
     */
    std::tuple<const ::std::string&> ice_tuple() const
    {
        return std::tie(str);
    }

    /**
     * Obtains the Slice type ID of this exception.
     * @return The fully-scoped type ID.
     */
    ICE_MEMBER(ICE_API) static const ::std::string& ice_staticId();
    /**
     * Prints this exception to the given stream.
     * @param stream The target stream.
     */
    ICE_MEMBER(ICE_API) virtual void ice_print(::std::ostream& stream) const override;

    /**
     * Describes the failure and includes the string that could not be parsed.
     */
    ::std::string str;
};

/**
 * This exception is raised if there was an error while parsing a stringified proxy.
 * \headerfile Ice/Ice.h
 */
class ICE_CLASS(ICE_API) ProxyParseException : public LocalExceptionHelper<ProxyParseException, LocalException>
{
public:

    ICE_MEMBER(ICE_API) virtual ~ProxyParseException();

    ProxyParseException(const ProxyParseException&) = default;

    /**
     * The file and line number are required for all local exceptions.
     * @param file The file name in which the exception was raised, typically __FILE__.
     * @param line The line number at which the exception was raised, typically __LINE__.
     */
    ProxyParseException(const char* file, int line) : LocalExceptionHelper<ProxyParseException, LocalException>(file, line)
    {
    }

    /**
     * One-shot constructor to initialize all data members.
     * The file and line number are required for all local exceptions.
     * @param file The file name in which the exception was raised, typically __FILE__.
     * @param line The line number at which the exception was raised, typically __LINE__.
     * @param str Describes the failure and includes the string that could not be parsed.
     */
    ProxyParseException(const char* file, int line, const ::std::string& str) : LocalExceptionHelper<ProxyParseException, LocalException>(file, line),
        str(str)
    {
    }

    /**
     * Obtains a tuple containing all of the exception's data members.
     * @return The data members in a tuple.
     */
    std::tuple<const ::std::string&> ice_tuple() const
    {
        return std::tie(str);
    }

    /**
     * Obtains the Slice type ID of this exception.
     * @return The fully-scoped type ID.
     */
    ICE_MEMBER(ICE_API) static const ::std::string& ice_staticId();
    /**
     * Prints this exception to the given stream.
     * @param stream The target stream.
     */
    ICE_MEMBER(ICE_API) virtual void ice_print(::std::ostream& stream) const override;

    /**
     * Describes the failure and includes the string that could not be parsed.
     */
    ::std::string str;
};

/**
 * This exception is raised if an illegal identity is encountered.
 * \headerfile Ice/Ice.h
 */
class ICE_CLASS(ICE_API) IllegalIdentityException : public LocalExceptionHelper<IllegalIdentityException, LocalException>
{
public:

    ICE_MEMBER(ICE_API) virtual ~IllegalIdentityException();

    IllegalIdentityException(const IllegalIdentityException&) = default;

    /**
     * The file and line number are required for all local exceptions.
     * @param file The file name in which the exception was raised, typically __FILE__.
     * @param line The line number at which the exception was raised, typically __LINE__.
     */
    IllegalIdentityException(const char* file, int line) : LocalExceptionHelper<IllegalIdentityException, LocalException>(file, line)
    {
    }

    /**
     * One-shot constructor to initialize all data members.
     * The file and line number are required for all local exceptions.
     * @param file The file name in which the exception was raised, typically __FILE__.
     * @param line The line number at which the exception was raised, typically __LINE__.
     * @param id The illegal identity.
     */
    IllegalIdentityException(const char* file, int line, const Identity& id) : LocalExceptionHelper<IllegalIdentityException, LocalException>(file, line),
        id(id)
    {
    }

    /**
     * Obtains a tuple containing all of the exception's data members.
     * @return The data members in a tuple.
     */
    std::tuple<const ::Ice::Identity&> ice_tuple() const
    {
        return std::tie(id);
    }

    /**
     * Obtains the Slice type ID of this exception.
     * @return The fully-scoped type ID.
     */
    ICE_MEMBER(ICE_API) static const ::std::string& ice_staticId();
    /**
     * Prints this exception to the given stream.
     * @param stream The target stream.
     */
    ICE_MEMBER(ICE_API) virtual void ice_print(::std::ostream& stream) const override;

    /**
     * The illegal identity.
     */
    ::Ice::Identity id;
};

/**
 * This exception is raised to reject an illegal servant (typically a null servant).
 * \headerfile Ice/Ice.h
 */
class ICE_CLASS(ICE_API) IllegalServantException : public LocalExceptionHelper<IllegalServantException, LocalException>
{
public:

    ICE_MEMBER(ICE_API) virtual ~IllegalServantException();

    IllegalServantException(const IllegalServantException&) = default;

    /**
     * The file and line number are required for all local exceptions.
     * @param file The file name in which the exception was raised, typically __FILE__.
     * @param line The line number at which the exception was raised, typically __LINE__.
     */
    IllegalServantException(const char* file, int line) : LocalExceptionHelper<IllegalServantException, LocalException>(file, line)
    {
    }

    /**
     * One-shot constructor to initialize all data members.
     * The file and line number are required for all local exceptions.
     * @param file The file name in which the exception was raised, typically __FILE__.
     * @param line The line number at which the exception was raised, typically __LINE__.
     * @param reason Describes why this servant is illegal.
     */
    IllegalServantException(const char* file, int line, const ::std::string& reason) : LocalExceptionHelper<IllegalServantException, LocalException>(file, line),
        reason(reason)
    {
    }

    /**
     * Obtains a tuple containing all of the exception's data members.
     * @return The data members in a tuple.
     */
    std::tuple<const ::std::string&> ice_tuple() const
    {
        return std::tie(reason);
    }

    /**
     * Obtains the Slice type ID of this exception.
     * @return The fully-scoped type ID.
     */
    ICE_MEMBER(ICE_API) static const ::std::string& ice_staticId();
    /**
     * Prints this exception to the given stream.
     * @param stream The target stream.
     */
    ICE_MEMBER(ICE_API) virtual void ice_print(::std::ostream& stream) const override;

    /**
     * Describes why this servant is illegal.
     */
    ::std::string reason;
};

/**
 * This exception is raised if a request failed. This exception, and all exceptions derived from
 * {@link RequestFailedException}, are transmitted by the Ice protocol, even though they are declared
 * <code>local</code>.
 * \headerfile Ice/Ice.h
 */
class ICE_CLASS(ICE_API) RequestFailedException : public LocalExceptionHelper<RequestFailedException, LocalException>
{
public:

    ICE_MEMBER(ICE_API) virtual ~RequestFailedException();

    RequestFailedException(const RequestFailedException&) = default;

    /**
     * The file and line number are required for all local exceptions.
     * @param file The file name in which the exception was raised, typically __FILE__.
     * @param line The line number at which the exception was raised, typically __LINE__.
     */
    RequestFailedException(const char* file, int line) : LocalExceptionHelper<RequestFailedException, LocalException>(file, line)
    {
    }

    /**
     * One-shot constructor to initialize all data members.
     * The file and line number are required for all local exceptions.
     * @param file The file name in which the exception was raised, typically __FILE__.
     * @param line The line number at which the exception was raised, typically __LINE__.
     * @param id The identity of the Ice Object to which the request was sent.
     * @param facet The facet to which the request was sent.
     * @param operation The operation name of the request.
     */
    RequestFailedException(const char* file, int line, const Identity& id, const ::std::string& facet, const ::std::string& operation) : LocalExceptionHelper<RequestFailedException, LocalException>(file, line),
        id(id),
        facet(facet),
        operation(operation)
    {
    }

    /**
     * Obtains a tuple containing all of the exception's data members.
     * @return The data members in a tuple.
     */
    std::tuple<const ::Ice::Identity&, const ::std::string&, const ::std::string&> ice_tuple() const
    {
        return std::tie(id, facet, operation);
    }

    /**
     * Obtains the Slice type ID of this exception.
     * @return The fully-scoped type ID.
     */
    ICE_MEMBER(ICE_API) static const ::std::string& ice_staticId();
    /**
     * Prints this exception to the given stream.
     * @param stream The target stream.
     */
    ICE_MEMBER(ICE_API) virtual void ice_print(::std::ostream& stream) const override;

    /**
     * The identity of the Ice Object to which the request was sent.
     */
    ::Ice::Identity id;
    /**
     * The facet to which the request was sent.
     */
    ::std::string facet;
    /**
     * The operation name of the request.
     */
    ::std::string operation;
};

/**
 * This exception is raised if an object does not exist on the server, that is, if no facets with the given identity
 * exist.
 * \headerfile Ice/Ice.h
 */
class ICE_CLASS(ICE_API) ObjectNotExistException : public LocalExceptionHelper<ObjectNotExistException, RequestFailedException>
{
public:

    ICE_MEMBER(ICE_API) virtual ~ObjectNotExistException();

    ObjectNotExistException(const ObjectNotExistException&) = default;

    /**
     * The file and line number are required for all local exceptions.
     * @param file The file name in which the exception was raised, typically __FILE__.
     * @param line The line number at which the exception was raised, typically __LINE__.
     */
    ObjectNotExistException(const char* file, int line) : LocalExceptionHelper<ObjectNotExistException, RequestFailedException>(file, line)
    {
    }

    /**
     * One-shot constructor to initialize all data members.
     * The file and line number are required for all local exceptions.
     * @param file The file name in which the exception was raised, typically __FILE__.
     * @param line The line number at which the exception was raised, typically __LINE__.
     * @param id The identity of the Ice Object to which the request was sent.
     * @param facet The facet to which the request was sent.
     * @param operation The operation name of the request.
     */
    ObjectNotExistException(const char* file, int line, const Identity& id, const ::std::string& facet, const ::std::string& operation) :
        LocalExceptionHelper<ObjectNotExistException, RequestFailedException>(file, line, id, facet, operation)
    {
    }

    /**
     * Obtains a tuple containing all of the exception's data members.
     * @return The data members in a tuple.
     */
    std::tuple<const ::Ice::Identity&, const ::std::string&, const ::std::string&> ice_tuple() const
    {
        return std::tie(id, facet, operation);
    }

    /**
     * Obtains the Slice type ID of this exception.
     * @return The fully-scoped type ID.
     */
    ICE_MEMBER(ICE_API) static const ::std::string& ice_staticId();
    /**
     * Prints this exception to the given stream.
     * @param stream The target stream.
     */
    ICE_MEMBER(ICE_API) virtual void ice_print(::std::ostream& stream) const override;
};

/**
 * This exception is raised if no facet with the given name exists, but at least one facet with the given identity
 * exists.
 * \headerfile Ice/Ice.h
 */
class ICE_CLASS(ICE_API) FacetNotExistException : public LocalExceptionHelper<FacetNotExistException, RequestFailedException>
{
public:

    ICE_MEMBER(ICE_API) virtual ~FacetNotExistException();

    FacetNotExistException(const FacetNotExistException&) = default;

    /**
     * The file and line number are required for all local exceptions.
     * @param file The file name in which the exception was raised, typically __FILE__.
     * @param line The line number at which the exception was raised, typically __LINE__.
     */
    FacetNotExistException(const char* file, int line) : LocalExceptionHelper<FacetNotExistException, RequestFailedException>(file, line)
    {
    }

    /**
     * One-shot constructor to initialize all data members.
     * The file and line number are required for all local exceptions.
     * @param file The file name in which the exception was raised, typically __FILE__.
     * @param line The line number at which the exception was raised, typically __LINE__.
     * @param id The identity of the Ice Object to which the request was sent.
     * @param facet The facet to which the request was sent.
     * @param operation The operation name of the request.
     */
    FacetNotExistException(const char* file, int line, const Identity& id, const ::std::string& facet, const ::std::string& operation) :
        LocalExceptionHelper<FacetNotExistException, RequestFailedException>(file, line, id, facet, operation)
    {
    }

    /**
     * Obtains a tuple containing all of the exception's data members.
     * @return The data members in a tuple.
     */
    std::tuple<const ::Ice::Identity&, const ::std::string&, const ::std::string&> ice_tuple() const
    {
        return std::tie(id, facet, operation);
    }

    /**
     * Obtains the Slice type ID of this exception.
     * @return The fully-scoped type ID.
     */
    ICE_MEMBER(ICE_API) static const ::std::string& ice_staticId();
    /**
     * Prints this exception to the given stream.
     * @param stream The target stream.
     */
    ICE_MEMBER(ICE_API) virtual void ice_print(::std::ostream& stream) const override;
};

/**
 * This exception is raised if an operation for a given object does not exist on the server. Typically this is caused
 * by either the client or the server using an outdated Slice specification.
 * \headerfile Ice/Ice.h
 */
class ICE_CLASS(ICE_API) OperationNotExistException : public LocalExceptionHelper<OperationNotExistException, RequestFailedException>
{
public:

    ICE_MEMBER(ICE_API) virtual ~OperationNotExistException();

    OperationNotExistException(const OperationNotExistException&) = default;

    /**
     * The file and line number are required for all local exceptions.
     * @param file The file name in which the exception was raised, typically __FILE__.
     * @param line The line number at which the exception was raised, typically __LINE__.
     */
    OperationNotExistException(const char* file, int line) : LocalExceptionHelper<OperationNotExistException, RequestFailedException>(file, line)
    {
    }

    /**
     * One-shot constructor to initialize all data members.
     * The file and line number are required for all local exceptions.
     * @param file The file name in which the exception was raised, typically __FILE__.
     * @param line The line number at which the exception was raised, typically __LINE__.
     * @param id The identity of the Ice Object to which the request was sent.
     * @param facet The facet to which the request was sent.
     * @param operation The operation name of the request.
     */
    OperationNotExistException(const char* file, int line, const Identity& id, const ::std::string& facet, const ::std::string& operation) :
        LocalExceptionHelper<OperationNotExistException, RequestFailedException>(file, line, id, facet, operation)
    {
    }

    /**
     * Obtains a tuple containing all of the exception's data members.
     * @return The data members in a tuple.
     */
    std::tuple<const ::Ice::Identity&, const ::std::string&, const ::std::string&> ice_tuple() const
    {
        return std::tie(id, facet, operation);
    }

    /**
     * Obtains the Slice type ID of this exception.
     * @return The fully-scoped type ID.
     */
    ICE_MEMBER(ICE_API) static const ::std::string& ice_staticId();
    /**
     * Prints this exception to the given stream.
     * @param stream The target stream.
     */
    ICE_MEMBER(ICE_API) virtual void ice_print(::std::ostream& stream) const override;
};

/**
 * This exception is raised if a system error occurred in the server or client process. There are many possible causes
 * for such a system exception. For details on the cause, {@link SyscallException#error} should be inspected.
 * \headerfile Ice/Ice.h
 */
class ICE_CLASS(ICE_API) SyscallException : public LocalExceptionHelper<SyscallException, LocalException>
{
public:

    ICE_MEMBER(ICE_API) virtual ~SyscallException();

    SyscallException(const SyscallException&) = default;

    /**
     * The file and line number are required for all local exceptions.
     * @param file The file name in which the exception was raised, typically __FILE__.
     * @param line The line number at which the exception was raised, typically __LINE__.
     */
    SyscallException(const char* file, int line) : LocalExceptionHelper<SyscallException, LocalException>(file, line)
    {
    }

    /**
     * One-shot constructor to initialize all data members.
     * The file and line number are required for all local exceptions.
     * @param file The file name in which the exception was raised, typically __FILE__.
     * @param line The line number at which the exception was raised, typically __LINE__.
     * @param error The error number describing the system exception.
     */
    SyscallException(const char* file, int line, int error) : LocalExceptionHelper<SyscallException, LocalException>(file, line),
        error(error)
    {
    }

    /**
     * Obtains a tuple containing all of the exception's data members.
     * @return The data members in a tuple.
     */
    std::tuple<const int&> ice_tuple() const
    {
        return std::tie(error);
    }

    /**
     * Obtains the Slice type ID of this exception.
     * @return The fully-scoped type ID.
     */
    ICE_MEMBER(ICE_API) static const ::std::string& ice_staticId();
    /**
     * Prints this exception to the given stream.
     * @param stream The target stream.
     */
    ICE_MEMBER(ICE_API) virtual void ice_print(::std::ostream& stream) const override;

    /**
     * The error number describing the system exception. For C++ and Unix, this is equivalent to <code>errno</code>.
     * For C++ and Windows, this is the value returned by <code>GetLastError()</code> or
     * <code>WSAGetLastError()</code>.
     */
    int error = 0;
};

/**
 * This exception indicates socket errors.
 * \headerfile Ice/Ice.h
 */
class ICE_CLASS(ICE_API) SocketException : public LocalExceptionHelper<SocketException, SyscallException>
{
public:

    ICE_MEMBER(ICE_API) virtual ~SocketException();

    SocketException(const SocketException&) = default;

    /**
     * The file and line number are required for all local exceptions.
     * @param file The file name in which the exception was raised, typically __FILE__.
     * @param line The line number at which the exception was raised, typically __LINE__.
     */
    SocketException(const char* file, int line) : LocalExceptionHelper<SocketException, SyscallException>(file, line)
    {
    }

    /**
     * One-shot constructor to initialize all data members.
     * The file and line number are required for all local exceptions.
     * @param file The file name in which the exception was raised, typically __FILE__.
     * @param line The line number at which the exception was raised, typically __LINE__.
     * @param error The error number describing the system exception.
     */
    SocketException(const char* file, int line, int error) :
        LocalExceptionHelper<SocketException, SyscallException>(file, line, error)
    {
    }

    /**
     * Obtains a tuple containing all of the exception's data members.
     * @return The data members in a tuple.
     */
    std::tuple<const int&> ice_tuple() const
    {
        return std::tie(error);
    }

    /**
     * Obtains the Slice type ID of this exception.
     * @return The fully-scoped type ID.
     */
    ICE_MEMBER(ICE_API) static const ::std::string& ice_staticId();
    /**
     * Prints this exception to the given stream.
     * @param stream The target stream.
     */
    ICE_MEMBER(ICE_API) virtual void ice_print(::std::ostream& stream) const override;
};

/**
 * This exception indicates CFNetwork errors.
 * \headerfile Ice/Ice.h
 */
class ICE_CLASS(ICE_API) CFNetworkException : public LocalExceptionHelper<CFNetworkException, SocketException>
{
public:

    ICE_MEMBER(ICE_API) virtual ~CFNetworkException();

    CFNetworkException(const CFNetworkException&) = default;

    /**
     * The file and line number are required for all local exceptions.
     * @param file The file name in which the exception was raised, typically __FILE__.
     * @param line The line number at which the exception was raised, typically __LINE__.
     */
    CFNetworkException(const char* file, int line) : LocalExceptionHelper<CFNetworkException, SocketException>(file, line)
    {
    }

    /**
     * One-shot constructor to initialize all data members.
     * The file and line number are required for all local exceptions.
     * @param file The file name in which the exception was raised, typically __FILE__.
     * @param line The line number at which the exception was raised, typically __LINE__.
     * @param error The error number describing the system exception.
     * @param domain The domain of the error.
     */
    CFNetworkException(const char* file, int line, int error, const ::std::string& domain) :
        LocalExceptionHelper<CFNetworkException, SocketException>(file, line, error),
        domain(domain)
    {
    }

    /**
     * Obtains a tuple containing all of the exception's data members.
     * @return The data members in a tuple.
     */
    std::tuple<const int&, const ::std::string&> ice_tuple() const
    {
        return std::tie(error, domain);
    }

    /**
     * Obtains the Slice type ID of this exception.
     * @return The fully-scoped type ID.
     */
    ICE_MEMBER(ICE_API) static const ::std::string& ice_staticId();
    /**
     * Prints this exception to the given stream.
     * @param stream The target stream.
     */
    ICE_MEMBER(ICE_API) virtual void ice_print(::std::ostream& stream) const override;

    /**
     * The domain of the error.
     */
    ::std::string domain;
};

/**
 * This exception indicates file errors.
 * \headerfile Ice/Ice.h
 */
class ICE_CLASS(ICE_API) FileException : public LocalExceptionHelper<FileException, SyscallException>
{
public:

    ICE_MEMBER(ICE_API) virtual ~FileException();

    FileException(const FileException&) = default;

    /**
     * The file and line number are required for all local exceptions.
     * @param file The file name in which the exception was raised, typically __FILE__.
     * @param line The line number at which the exception was raised, typically __LINE__.
     */
    FileException(const char* file, int line) : LocalExceptionHelper<FileException, SyscallException>(file, line)
    {
    }

    /**
     * One-shot constructor to initialize all data members.
     * The file and line number are required for all local exceptions.
     * @param file The file name in which the exception was raised, typically __FILE__.
     * @param line The line number at which the exception was raised, typically __LINE__.
     * @param error The error number describing the system exception.
     * @param path The path of the file responsible for the error.
     */
    FileException(const char* file, int line, int error, const ::std::string& path) :
        LocalExceptionHelper<FileException, SyscallException>(file, line, error),
        path(path)
    {
    }

    /**
     * Obtains a tuple containing all of the exception's data members.
     * @return The data members in a tuple.
     */
    std::tuple<const int&, const ::std::string&> ice_tuple() const
    {
        return std::tie(error, path);
    }

    /**
     * Obtains the Slice type ID of this exception.
     * @return The fully-scoped type ID.
     */
    ICE_MEMBER(ICE_API) static const ::std::string& ice_staticId();
    /**
     * Prints this exception to the given stream.
     * @param stream The target stream.
     */
    ICE_MEMBER(ICE_API) virtual void ice_print(::std::ostream& stream) const override;

    /**
     * The path of the file responsible for the error.
     */
    ::std::string path;
};

/**
 * This exception indicates connection failures.
 * \headerfile Ice/Ice.h
 */
class ICE_CLASS(ICE_API) ConnectFailedException : public LocalExceptionHelper<ConnectFailedException, SocketException>
{
public:

    ICE_MEMBER(ICE_API) virtual ~ConnectFailedException();

    ConnectFailedException(const ConnectFailedException&) = default;

    /**
     * The file and line number are required for all local exceptions.
     * @param file The file name in which the exception was raised, typically __FILE__.
     * @param line The line number at which the exception was raised, typically __LINE__.
     */
    ConnectFailedException(const char* file, int line) : LocalExceptionHelper<ConnectFailedException, SocketException>(file, line)
    {
    }

    /**
     * One-shot constructor to initialize all data members.
     * The file and line number are required for all local exceptions.
     * @param file The file name in which the exception was raised, typically __FILE__.
     * @param line The line number at which the exception was raised, typically __LINE__.
     * @param error The error number describing the system exception.
     */
    ConnectFailedException(const char* file, int line, int error) :
        LocalExceptionHelper<ConnectFailedException, SocketException>(file, line, error)
    {
    }

    /**
     * Obtains a tuple containing all of the exception's data members.
     * @return The data members in a tuple.
     */
    std::tuple<const int&> ice_tuple() const
    {
        return std::tie(error);
    }

    /**
     * Obtains the Slice type ID of this exception.
     * @return The fully-scoped type ID.
     */
    ICE_MEMBER(ICE_API) static const ::std::string& ice_staticId();
    /**
     * Prints this exception to the given stream.
     * @param stream The target stream.
     */
    ICE_MEMBER(ICE_API) virtual void ice_print(::std::ostream& stream) const override;
};

/**
 * This exception indicates a connection failure for which the server host actively refuses a connection.
 * \headerfile Ice/Ice.h
 */
class ICE_CLASS(ICE_API) ConnectionRefusedException : public LocalExceptionHelper<ConnectionRefusedException, ConnectFailedException>
{
public:

    ICE_MEMBER(ICE_API) virtual ~ConnectionRefusedException();

    ConnectionRefusedException(const ConnectionRefusedException&) = default;

    /**
     * The file and line number are required for all local exceptions.
     * @param file The file name in which the exception was raised, typically __FILE__.
     * @param line The line number at which the exception was raised, typically __LINE__.
     */
    ConnectionRefusedException(const char* file, int line) : LocalExceptionHelper<ConnectionRefusedException, ConnectFailedException>(file, line)
    {
    }

    /**
     * One-shot constructor to initialize all data members.
     * The file and line number are required for all local exceptions.
     * @param file The file name in which the exception was raised, typically __FILE__.
     * @param line The line number at which the exception was raised, typically __LINE__.
     * @param error The error number describing the system exception.
     */
    ConnectionRefusedException(const char* file, int line, int error) :
        LocalExceptionHelper<ConnectionRefusedException, ConnectFailedException>(file, line, error)
    {
    }

    /**
     * Obtains a tuple containing all of the exception's data members.
     * @return The data members in a tuple.
     */
    std::tuple<const int&> ice_tuple() const
    {
        return std::tie(error);
    }

    /**
     * Obtains the Slice type ID of this exception.
     * @return The fully-scoped type ID.
     */
    ICE_MEMBER(ICE_API) static const ::std::string& ice_staticId();
    /**
     * Prints this exception to the given stream.
     * @param stream The target stream.
     */
    ICE_MEMBER(ICE_API) virtual void ice_print(::std::ostream& stream) const override;
};

/**
 * This exception indicates a lost connection.
 * \headerfile Ice/Ice.h
 */
class ICE_CLASS(ICE_API) ConnectionLostException : public LocalExceptionHelper<ConnectionLostException, SocketException>
{
public:

    ICE_MEMBER(ICE_API) virtual ~ConnectionLostException();

    ConnectionLostException(const ConnectionLostException&) = default;

    /**
     * The file and line number are required for all local exceptions.
     * @param file The file name in which the exception was raised, typically __FILE__.
     * @param line The line number at which the exception was raised, typically __LINE__.
     */
    ConnectionLostException(const char* file, int line) : LocalExceptionHelper<ConnectionLostException, SocketException>(file, line)
    {
    }

    /**
     * One-shot constructor to initialize all data members.
     * The file and line number are required for all local exceptions.
     * @param file The file name in which the exception was raised, typically __FILE__.
     * @param line The line number at which the exception was raised, typically __LINE__.
     * @param error The error number describing the system exception.
     */
    ConnectionLostException(const char* file, int line, int error) :
        LocalExceptionHelper<ConnectionLostException, SocketException>(file, line, error)
    {
    }

    /**
     * Obtains a tuple containing all of the exception's data members.
     * @return The data members in a tuple.
     */
    std::tuple<const int&> ice_tuple() const
    {
        return std::tie(error);
    }

    /**
     * Obtains the Slice type ID of this exception.
     * @return The fully-scoped type ID.
     */
    ICE_MEMBER(ICE_API) static const ::std::string& ice_staticId();
    /**
     * Prints this exception to the given stream.
     * @param stream The target stream.
     */
    ICE_MEMBER(ICE_API) virtual void ice_print(::std::ostream& stream) const override;
};

/**
 * This exception indicates a DNS problem. For details on the cause, {@link DNSException#error} should be inspected.
 * \headerfile Ice/Ice.h
 */
class ICE_CLASS(ICE_API) DNSException : public LocalExceptionHelper<DNSException, LocalException>
{
public:

    ICE_MEMBER(ICE_API) virtual ~DNSException();

    DNSException(const DNSException&) = default;

    /**
     * The file and line number are required for all local exceptions.
     * @param file The file name in which the exception was raised, typically __FILE__.
     * @param line The line number at which the exception was raised, typically __LINE__.
     */
    DNSException(const char* file, int line) : LocalExceptionHelper<DNSException, LocalException>(file, line)
    {
    }

    /**
     * One-shot constructor to initialize all data members.
     * The file and line number are required for all local exceptions.
     * @param file The file name in which the exception was raised, typically __FILE__.
     * @param line The line number at which the exception was raised, typically __LINE__.
     * @param error The error number describing the DNS problem.
     * @param host The host name that could not be resolved.
     */
    DNSException(const char* file, int line, int error, const ::std::string& host) : LocalExceptionHelper<DNSException, LocalException>(file, line),
        error(error),
        host(host)
    {
    }

    /**
     * Obtains a tuple containing all of the exception's data members.
     * @return The data members in a tuple.
     */
    std::tuple<const int&, const ::std::string&> ice_tuple() const
    {
        return std::tie(error, host);
    }

    /**
     * Obtains the Slice type ID of this exception.
     * @return The fully-scoped type ID.
     */
    ICE_MEMBER(ICE_API) static const ::std::string& ice_staticId();
    /**
     * Prints this exception to the given stream.
     * @param stream The target stream.
     */
    ICE_MEMBER(ICE_API) virtual void ice_print(::std::ostream& stream) const override;

    /**
     * The error number describing the DNS problem. For C++ and Unix, this is equivalent to <code>h_errno</code>. For
     * C++ and Windows, this is the value returned by <code>WSAGetLastError()</code>.
     */
    int error = 0;
    /**
     * The host name that could not be resolved.
     */
    ::std::string host;
};

/**
 * This exception indicates a request was interrupted.
 * \headerfile Ice/Ice.h
 */
class ICE_CLASS(ICE_API) OperationInterruptedException : public LocalExceptionHelper<OperationInterruptedException, LocalException>
{
public:

    ICE_MEMBER(ICE_API) virtual ~OperationInterruptedException();

    OperationInterruptedException(const OperationInterruptedException&) = default;

    /**
     * The file and line number are required for all local exceptions.
     * @param file The file name in which the exception was raised, typically __FILE__.
     * @param line The line number at which the exception was raised, typically __LINE__.
     */
    OperationInterruptedException(const char* file, int line) : LocalExceptionHelper<OperationInterruptedException, LocalException>(file, line)
    {
    }

    /**
     * Obtains a tuple containing all of the exception's data members.
     * @return The data members in a tuple.
     */
    std::tuple<> ice_tuple() const
    {
        return std::tie();
    }

    /**
     * Obtains the Slice type ID of this exception.
     * @return The fully-scoped type ID.
     */
    ICE_MEMBER(ICE_API) static const ::std::string& ice_staticId();
    /**
     * Prints this exception to the given stream.
     * @param stream The target stream.
     */
    ICE_MEMBER(ICE_API) virtual void ice_print(::std::ostream& stream) const override;
};

/**
 * This exception indicates a timeout condition.
 * \headerfile Ice/Ice.h
 */
class ICE_CLASS(ICE_API) TimeoutException : public LocalExceptionHelper<TimeoutException, LocalException>
{
public:

    ICE_MEMBER(ICE_API) virtual ~TimeoutException();

    TimeoutException(const TimeoutException&) = default;

    /**
     * The file and line number are required for all local exceptions.
     * @param file The file name in which the exception was raised, typically __FILE__.
     * @param line The line number at which the exception was raised, typically __LINE__.
     */
    TimeoutException(const char* file, int line) : LocalExceptionHelper<TimeoutException, LocalException>(file, line)
    {
    }

    /**
     * Obtains a tuple containing all of the exception's data members.
     * @return The data members in a tuple.
     */
    std::tuple<> ice_tuple() const
    {
        return std::tie();
    }

    /**
     * Obtains the Slice type ID of this exception.
     * @return The fully-scoped type ID.
     */
    ICE_MEMBER(ICE_API) static const ::std::string& ice_staticId();
    /**
     * Prints this exception to the given stream.
     * @param stream The target stream.
     */
    ICE_MEMBER(ICE_API) virtual void ice_print(::std::ostream& stream) const override;
};

/**
 * This exception indicates a connection establishment timeout condition.
 * \headerfile Ice/Ice.h
 */
class ICE_CLASS(ICE_API) ConnectTimeoutException : public LocalExceptionHelper<ConnectTimeoutException, TimeoutException>
{
public:

    ICE_MEMBER(ICE_API) virtual ~ConnectTimeoutException();

    ConnectTimeoutException(const ConnectTimeoutException&) = default;

    /**
     * The file and line number are required for all local exceptions.
     * @param file The file name in which the exception was raised, typically __FILE__.
     * @param line The line number at which the exception was raised, typically __LINE__.
     */
    ConnectTimeoutException(const char* file, int line) : LocalExceptionHelper<ConnectTimeoutException, TimeoutException>(file, line)
    {
    }

    /**
     * Obtains a tuple containing all of the exception's data members.
     * @return The data members in a tuple.
     */
    std::tuple<> ice_tuple() const
    {
        return std::tie();
    }

    /**
     * Obtains the Slice type ID of this exception.
     * @return The fully-scoped type ID.
     */
    ICE_MEMBER(ICE_API) static const ::std::string& ice_staticId();
    /**
     * Prints this exception to the given stream.
     * @param stream The target stream.
     */
    ICE_MEMBER(ICE_API) virtual void ice_print(::std::ostream& stream) const override;
};

/**
 * This exception indicates a connection closure timeout condition.
 * \headerfile Ice/Ice.h
 */
class ICE_CLASS(ICE_API) CloseTimeoutException : public LocalExceptionHelper<CloseTimeoutException, TimeoutException>
{
public:

    ICE_MEMBER(ICE_API) virtual ~CloseTimeoutException();

    CloseTimeoutException(const CloseTimeoutException&) = default;

    /**
     * The file and line number are required for all local exceptions.
     * @param file The file name in which the exception was raised, typically __FILE__.
     * @param line The line number at which the exception was raised, typically __LINE__.
     */
    CloseTimeoutException(const char* file, int line) : LocalExceptionHelper<CloseTimeoutException, TimeoutException>(file, line)
    {
    }

    /**
     * Obtains a tuple containing all of the exception's data members.
     * @return The data members in a tuple.
     */
    std::tuple<> ice_tuple() const
    {
        return std::tie();
    }

    /**
     * Obtains the Slice type ID of this exception.
     * @return The fully-scoped type ID.
     */
    ICE_MEMBER(ICE_API) static const ::std::string& ice_staticId();
    /**
     * Prints this exception to the given stream.
     * @param stream The target stream.
     */
    ICE_MEMBER(ICE_API) virtual void ice_print(::std::ostream& stream) const override;
};

/**
 * This exception indicates that a connection has been shut down because it has been idle for some time.
 * \headerfile Ice/Ice.h
 */
class ICE_CLASS(ICE_API) ConnectionTimeoutException : public LocalExceptionHelper<ConnectionTimeoutException, TimeoutException>
{
public:

    ICE_MEMBER(ICE_API) virtual ~ConnectionTimeoutException();

    ConnectionTimeoutException(const ConnectionTimeoutException&) = default;

    /**
     * The file and line number are required for all local exceptions.
     * @param file The file name in which the exception was raised, typically __FILE__.
     * @param line The line number at which the exception was raised, typically __LINE__.
     */
    ConnectionTimeoutException(const char* file, int line) : LocalExceptionHelper<ConnectionTimeoutException, TimeoutException>(file, line)
    {
    }

    /**
     * Obtains a tuple containing all of the exception's data members.
     * @return The data members in a tuple.
     */
    std::tuple<> ice_tuple() const
    {
        return std::tie();
    }

    /**
     * Obtains the Slice type ID of this exception.
     * @return The fully-scoped type ID.
     */
    ICE_MEMBER(ICE_API) static const ::std::string& ice_staticId();
    /**
     * Prints this exception to the given stream.
     * @param stream The target stream.
     */
    ICE_MEMBER(ICE_API) virtual void ice_print(::std::ostream& stream) const override;
};

/**
 * This exception indicates that an invocation failed because it timed out.
 * \headerfile Ice/Ice.h
 */
class ICE_CLASS(ICE_API) InvocationTimeoutException : public LocalExceptionHelper<InvocationTimeoutException, TimeoutException>
{
public:

    ICE_MEMBER(ICE_API) virtual ~InvocationTimeoutException();

    InvocationTimeoutException(const InvocationTimeoutException&) = default;

    /**
     * The file and line number are required for all local exceptions.
     * @param file The file name in which the exception was raised, typically __FILE__.
     * @param line The line number at which the exception was raised, typically __LINE__.
     */
    InvocationTimeoutException(const char* file, int line) : LocalExceptionHelper<InvocationTimeoutException, TimeoutException>(file, line)
    {
    }

    /**
     * Obtains a tuple containing all of the exception's data members.
     * @return The data members in a tuple.
     */
    std::tuple<> ice_tuple() const
    {
        return std::tie();
    }

    /**
     * Obtains the Slice type ID of this exception.
     * @return The fully-scoped type ID.
     */
    ICE_MEMBER(ICE_API) static const ::std::string& ice_staticId();
    /**
     * Prints this exception to the given stream.
     * @param stream The target stream.
     */
    ICE_MEMBER(ICE_API) virtual void ice_print(::std::ostream& stream) const override;
};

/**
 * This exception indicates that an asynchronous invocation failed because it was canceled explicitly by the user.
 * \headerfile Ice/Ice.h
 */
class ICE_CLASS(ICE_API) InvocationCanceledException : public LocalExceptionHelper<InvocationCanceledException, LocalException>
{
public:

    ICE_MEMBER(ICE_API) virtual ~InvocationCanceledException();

    InvocationCanceledException(const InvocationCanceledException&) = default;

    /**
     * The file and line number are required for all local exceptions.
     * @param file The file name in which the exception was raised, typically __FILE__.
     * @param line The line number at which the exception was raised, typically __LINE__.
     */
    InvocationCanceledException(const char* file, int line) : LocalExceptionHelper<InvocationCanceledException, LocalException>(file, line)
    {
    }

    /**
     * Obtains a tuple containing all of the exception's data members.
     * @return The data members in a tuple.
     */
    std::tuple<> ice_tuple() const
    {
        return std::tie();
    }

    /**
     * Obtains the Slice type ID of this exception.
     * @return The fully-scoped type ID.
     */
    ICE_MEMBER(ICE_API) static const ::std::string& ice_staticId();
    /**
     * Prints this exception to the given stream.
     * @param stream The target stream.
     */
    ICE_MEMBER(ICE_API) virtual void ice_print(::std::ostream& stream) const override;
};

/**
 * A generic exception base for all kinds of protocol error conditions.
 * \headerfile Ice/Ice.h
 */
class ICE_CLASS(ICE_API) ProtocolException : public LocalExceptionHelper<ProtocolException, LocalException>
{
public:

    ICE_MEMBER(ICE_API) virtual ~ProtocolException();

    ProtocolException(const ProtocolException&) = default;

    /**
     * The file and line number are required for all local exceptions.
     * @param file The file name in which the exception was raised, typically __FILE__.
     * @param line The line number at which the exception was raised, typically __LINE__.
     */
    ProtocolException(const char* file, int line) : LocalExceptionHelper<ProtocolException, LocalException>(file, line)
    {
    }

    /**
     * One-shot constructor to initialize all data members.
     * The file and line number are required for all local exceptions.
     * @param file The file name in which the exception was raised, typically __FILE__.
     * @param line The line number at which the exception was raised, typically __LINE__.
     * @param reason The reason for the failure.
     */
    ProtocolException(const char* file, int line, const ::std::string& reason) : LocalExceptionHelper<ProtocolException, LocalException>(file, line),
        reason(reason)
    {
    }

    /**
     * Obtains a tuple containing all of the exception's data members.
     * @return The data members in a tuple.
     */
    std::tuple<const ::std::string&> ice_tuple() const
    {
        return std::tie(reason);
    }

    /**
     * Obtains the Slice type ID of this exception.
     * @return The fully-scoped type ID.
     */
    ICE_MEMBER(ICE_API) static const ::std::string& ice_staticId();
    /**
     * Prints this exception to the given stream.
     * @param stream The target stream.
     */
    ICE_MEMBER(ICE_API) virtual void ice_print(::std::ostream& stream) const override;

    /**
     * The reason for the failure.
     */
    ::std::string reason;
};

/**
 * This exception indicates that a message did not start with the expected magic number ('I', 'c', 'e', 'P').
 * \headerfile Ice/Ice.h
 */
class ICE_CLASS(ICE_API) BadMagicException : public LocalExceptionHelper<BadMagicException, ProtocolException>
{
public:

    ICE_MEMBER(ICE_API) virtual ~BadMagicException();

    BadMagicException(const BadMagicException&) = default;

    /**
     * The file and line number are required for all local exceptions.
     * @param file The file name in which the exception was raised, typically __FILE__.
     * @param line The line number at which the exception was raised, typically __LINE__.
     */
    BadMagicException(const char* file, int line) : LocalExceptionHelper<BadMagicException, ProtocolException>(file, line)
    {
    }

    /**
     * One-shot constructor to initialize all data members.
     * The file and line number are required for all local exceptions.
     * @param file The file name in which the exception was raised, typically __FILE__.
     * @param line The line number at which the exception was raised, typically __LINE__.
     * @param reason The reason for the failure.
     * @param badMagic A sequence containing the first four bytes of the incorrect message.
     */
    BadMagicException(const char* file, int line, const ::std::string& reason, const ByteSeq& badMagic) :
        LocalExceptionHelper<BadMagicException, ProtocolException>(file, line, reason),
        badMagic(badMagic)
    {
    }

    /**
     * Obtains a tuple containing all of the exception's data members.
     * @return The data members in a tuple.
     */
    std::tuple<const ::std::string&, const ::Ice::ByteSeq&> ice_tuple() const
    {
        return std::tie(reason, badMagic);
    }

    /**
     * Obtains the Slice type ID of this exception.
     * @return The fully-scoped type ID.
     */
    ICE_MEMBER(ICE_API) static const ::std::string& ice_staticId();
    /**
     * Prints this exception to the given stream.
     * @param stream The target stream.
     */
    ICE_MEMBER(ICE_API) virtual void ice_print(::std::ostream& stream) const override;

    /**
     * A sequence containing the first four bytes of the incorrect message.
     */
    ::Ice::ByteSeq badMagic;
};

/**
 * This exception indicates an unsupported protocol version.
 * \headerfile Ice/Ice.h
 */
class ICE_CLASS(ICE_API) UnsupportedProtocolException : public LocalExceptionHelper<UnsupportedProtocolException, ProtocolException>
{
public:

    ICE_MEMBER(ICE_API) virtual ~UnsupportedProtocolException();

    UnsupportedProtocolException(const UnsupportedProtocolException&) = default;

    /**
     * The file and line number are required for all local exceptions.
     * @param file The file name in which the exception was raised, typically __FILE__.
     * @param line The line number at which the exception was raised, typically __LINE__.
     */
    UnsupportedProtocolException(const char* file, int line) : LocalExceptionHelper<UnsupportedProtocolException, ProtocolException>(file, line)
    {
    }

    /**
     * One-shot constructor to initialize all data members.
     * The file and line number are required for all local exceptions.
     * @param file The file name in which the exception was raised, typically __FILE__.
     * @param line The line number at which the exception was raised, typically __LINE__.
     * @param reason The reason for the failure.
     * @param bad The version of the unsupported protocol.
     * @param supported The version of the protocol that is supported.
     */
    UnsupportedProtocolException(const char* file, int line, const ::std::string& reason, const ProtocolVersion& bad, const ProtocolVersion& supported) :
        LocalExceptionHelper<UnsupportedProtocolException, ProtocolException>(file, line, reason),
        bad(bad),
        supported(supported)
    {
    }

    /**
     * Obtains a tuple containing all of the exception's data members.
     * @return The data members in a tuple.
     */
    std::tuple<const ::std::string&, const ::Ice::ProtocolVersion&, const ::Ice::ProtocolVersion&> ice_tuple() const
    {
        return std::tie(reason, bad, supported);
    }

    /**
     * Obtains the Slice type ID of this exception.
     * @return The fully-scoped type ID.
     */
    ICE_MEMBER(ICE_API) static const ::std::string& ice_staticId();
    /**
     * Prints this exception to the given stream.
     * @param stream The target stream.
     */
    ICE_MEMBER(ICE_API) virtual void ice_print(::std::ostream& stream) const override;

    /**
     * The version of the unsupported protocol.
     */
    ::Ice::ProtocolVersion bad;
    /**
     * The version of the protocol that is supported.
     */
    ::Ice::ProtocolVersion supported;
};

/**
 * This exception indicates an unsupported data encoding version.
 * \headerfile Ice/Ice.h
 */
class ICE_CLASS(ICE_API) UnsupportedEncodingException : public LocalExceptionHelper<UnsupportedEncodingException, ProtocolException>
{
public:

    ICE_MEMBER(ICE_API) virtual ~UnsupportedEncodingException();

    UnsupportedEncodingException(const UnsupportedEncodingException&) = default;

    /**
     * The file and line number are required for all local exceptions.
     * @param file The file name in which the exception was raised, typically __FILE__.
     * @param line The line number at which the exception was raised, typically __LINE__.
     */
    UnsupportedEncodingException(const char* file, int line) : LocalExceptionHelper<UnsupportedEncodingException, ProtocolException>(file, line)
    {
    }

    /**
     * One-shot constructor to initialize all data members.
     * The file and line number are required for all local exceptions.
     * @param file The file name in which the exception was raised, typically __FILE__.
     * @param line The line number at which the exception was raised, typically __LINE__.
     * @param reason The reason for the failure.
     * @param bad The version of the unsupported encoding.
     * @param supported The version of the encoding that is supported.
     */
    UnsupportedEncodingException(const char* file, int line, const ::std::string& reason, const EncodingVersion& bad, const EncodingVersion& supported) :
        LocalExceptionHelper<UnsupportedEncodingException, ProtocolException>(file, line, reason),
        bad(bad),
        supported(supported)
    {
    }

    /**
     * Obtains a tuple containing all of the exception's data members.
     * @return The data members in a tuple.
     */
    std::tuple<const ::std::string&, const ::Ice::EncodingVersion&, const ::Ice::EncodingVersion&> ice_tuple() const
    {
        return std::tie(reason, bad, supported);
    }

    /**
     * Obtains the Slice type ID of this exception.
     * @return The fully-scoped type ID.
     */
    ICE_MEMBER(ICE_API) static const ::std::string& ice_staticId();
    /**
     * Prints this exception to the given stream.
     * @param stream The target stream.
     */
    ICE_MEMBER(ICE_API) virtual void ice_print(::std::ostream& stream) const override;

    /**
     * The version of the unsupported encoding.
     */
    ::Ice::EncodingVersion bad;
    /**
     * The version of the encoding that is supported.
     */
    ::Ice::EncodingVersion supported;
};

/**
 * This exception indicates that an unknown protocol message has been received.
 * \headerfile Ice/Ice.h
 */
class ICE_CLASS(ICE_API) UnknownMessageException : public LocalExceptionHelper<UnknownMessageException, ProtocolException>
{
public:

    ICE_MEMBER(ICE_API) virtual ~UnknownMessageException();

    UnknownMessageException(const UnknownMessageException&) = default;

    /**
     * The file and line number are required for all local exceptions.
     * @param file The file name in which the exception was raised, typically __FILE__.
     * @param line The line number at which the exception was raised, typically __LINE__.
     */
    UnknownMessageException(const char* file, int line) : LocalExceptionHelper<UnknownMessageException, ProtocolException>(file, line)
    {
    }

    /**
     * One-shot constructor to initialize all data members.
     * The file and line number are required for all local exceptions.
     * @param file The file name in which the exception was raised, typically __FILE__.
     * @param line The line number at which the exception was raised, typically __LINE__.
     * @param reason The reason for the failure.
     */
    UnknownMessageException(const char* file, int line, const ::std::string& reason) :
        LocalExceptionHelper<UnknownMessageException, ProtocolException>(file, line, reason)
    {
    }

    /**
     * Obtains a tuple containing all of the exception's data members.
     * @return The data members in a tuple.
     */
    std::tuple<const ::std::string&> ice_tuple() const
    {
        return std::tie(reason);
    }

    /**
     * Obtains the Slice type ID of this exception.
     * @return The fully-scoped type ID.
     */
    ICE_MEMBER(ICE_API) static const ::std::string& ice_staticId();
    /**
     * Prints this exception to the given stream.
     * @param stream The target stream.
     */
    ICE_MEMBER(ICE_API) virtual void ice_print(::std::ostream& stream) const override;
};

/**
 * This exception is raised if a message is received over a connection that is not yet validated.
 * \headerfile Ice/Ice.h
 */
class ICE_CLASS(ICE_API) ConnectionNotValidatedException : public LocalExceptionHelper<ConnectionNotValidatedException, ProtocolException>
{
public:

    ICE_MEMBER(ICE_API) virtual ~ConnectionNotValidatedException();

    ConnectionNotValidatedException(const ConnectionNotValidatedException&) = default;

    /**
     * The file and line number are required for all local exceptions.
     * @param file The file name in which the exception was raised, typically __FILE__.
     * @param line The line number at which the exception was raised, typically __LINE__.
     */
    ConnectionNotValidatedException(const char* file, int line) : LocalExceptionHelper<ConnectionNotValidatedException, ProtocolException>(file, line)
    {
    }

    /**
     * One-shot constructor to initialize all data members.
     * The file and line number are required for all local exceptions.
     * @param file The file name in which the exception was raised, typically __FILE__.
     * @param line The line number at which the exception was raised, typically __LINE__.
     * @param reason The reason for the failure.
     */
    ConnectionNotValidatedException(const char* file, int line, const ::std::string& reason) :
        LocalExceptionHelper<ConnectionNotValidatedException, ProtocolException>(file, line, reason)
    {
    }

    /**
     * Obtains a tuple containing all of the exception's data members.
     * @return The data members in a tuple.
     */
    std::tuple<const ::std::string&> ice_tuple() const
    {
        return std::tie(reason);
    }

    /**
     * Obtains the Slice type ID of this exception.
     * @return The fully-scoped type ID.
     */
    ICE_MEMBER(ICE_API) static const ::std::string& ice_staticId();
    /**
     * Prints this exception to the given stream.
     * @param stream The target stream.
     */
    ICE_MEMBER(ICE_API) virtual void ice_print(::std::ostream& stream) const override;
};

/**
 * This exception indicates that a response for an unknown request ID has been received.
 * \headerfile Ice/Ice.h
 */
class ICE_CLASS(ICE_API) UnknownRequestIdException : public LocalExceptionHelper<UnknownRequestIdException, ProtocolException>
{
public:

    ICE_MEMBER(ICE_API) virtual ~UnknownRequestIdException();

    UnknownRequestIdException(const UnknownRequestIdException&) = default;

    /**
     * The file and line number are required for all local exceptions.
     * @param file The file name in which the exception was raised, typically __FILE__.
     * @param line The line number at which the exception was raised, typically __LINE__.
     */
    UnknownRequestIdException(const char* file, int line) : LocalExceptionHelper<UnknownRequestIdException, ProtocolException>(file, line)
    {
    }

    /**
     * One-shot constructor to initialize all data members.
     * The file and line number are required for all local exceptions.
     * @param file The file name in which the exception was raised, typically __FILE__.
     * @param line The line number at which the exception was raised, typically __LINE__.
     * @param reason The reason for the failure.
     */
    UnknownRequestIdException(const char* file, int line, const ::std::string& reason) :
        LocalExceptionHelper<UnknownRequestIdException, ProtocolException>(file, line, reason)
    {
    }

    /**
     * Obtains a tuple containing all of the exception's data members.
     * @return The data members in a tuple.
     */
    std::tuple<const ::std::string&> ice_tuple() const
    {
        return std::tie(reason);
    }

    /**
     * Obtains the Slice type ID of this exception.
     * @return The fully-scoped type ID.
     */
    ICE_MEMBER(ICE_API) static const ::std::string& ice_staticId();
    /**
     * Prints this exception to the given stream.
     * @param stream The target stream.
     */
    ICE_MEMBER(ICE_API) virtual void ice_print(::std::ostream& stream) const override;
};

/**
 * This exception indicates that an unknown reply status has been received.
 * \headerfile Ice/Ice.h
 */
class ICE_CLASS(ICE_API) UnknownReplyStatusException : public LocalExceptionHelper<UnknownReplyStatusException, ProtocolException>
{
public:

    ICE_MEMBER(ICE_API) virtual ~UnknownReplyStatusException();

    UnknownReplyStatusException(const UnknownReplyStatusException&) = default;

    /**
     * The file and line number are required for all local exceptions.
     * @param file The file name in which the exception was raised, typically __FILE__.
     * @param line The line number at which the exception was raised, typically __LINE__.
     */
    UnknownReplyStatusException(const char* file, int line) : LocalExceptionHelper<UnknownReplyStatusException, ProtocolException>(file, line)
    {
    }

    /**
     * One-shot constructor to initialize all data members.
     * The file and line number are required for all local exceptions.
     * @param file The file name in which the exception was raised, typically __FILE__.
     * @param line The line number at which the exception was raised, typically __LINE__.
     * @param reason The reason for the failure.
     */
    UnknownReplyStatusException(const char* file, int line, const ::std::string& reason) :
        LocalExceptionHelper<UnknownReplyStatusException, ProtocolException>(file, line, reason)
    {
    }

    /**
     * Obtains a tuple containing all of the exception's data members.
     * @return The data members in a tuple.
     */
    std::tuple<const ::std::string&> ice_tuple() const
    {
        return std::tie(reason);
    }

    /**
     * Obtains the Slice type ID of this exception.
     * @return The fully-scoped type ID.
     */
    ICE_MEMBER(ICE_API) static const ::std::string& ice_staticId();
    /**
     * Prints this exception to the given stream.
     * @param stream The target stream.
     */
    ICE_MEMBER(ICE_API) virtual void ice_print(::std::ostream& stream) const override;
};

/**
 * This exception indicates that the connection has been gracefully shut down by the server. The operation call that
 * caused this exception has not been executed by the server. In most cases you will not get this exception, because
 * the client will automatically retry the operation call in case the server shut down the connection. However, if
 * upon retry the server shuts down the connection again, and the retry limit has been reached, then this exception is
 * propagated to the application code.
 * \headerfile Ice/Ice.h
 */
class ICE_CLASS(ICE_API) CloseConnectionException : public LocalExceptionHelper<CloseConnectionException, ProtocolException>
{
public:

    ICE_MEMBER(ICE_API) virtual ~CloseConnectionException();

    CloseConnectionException(const CloseConnectionException&) = default;

    /**
     * The file and line number are required for all local exceptions.
     * @param file The file name in which the exception was raised, typically __FILE__.
     * @param line The line number at which the exception was raised, typically __LINE__.
     */
    CloseConnectionException(const char* file, int line) : LocalExceptionHelper<CloseConnectionException, ProtocolException>(file, line)
    {
    }

    /**
     * One-shot constructor to initialize all data members.
     * The file and line number are required for all local exceptions.
     * @param file The file name in which the exception was raised, typically __FILE__.
     * @param line The line number at which the exception was raised, typically __LINE__.
     * @param reason The reason for the failure.
     */
    CloseConnectionException(const char* file, int line, const ::std::string& reason) :
        LocalExceptionHelper<CloseConnectionException, ProtocolException>(file, line, reason)
    {
    }

    /**
     * Obtains a tuple containing all of the exception's data members.
     * @return The data members in a tuple.
     */
    std::tuple<const ::std::string&> ice_tuple() const
    {
        return std::tie(reason);
    }

    /**
     * Obtains the Slice type ID of this exception.
     * @return The fully-scoped type ID.
     */
    ICE_MEMBER(ICE_API) static const ::std::string& ice_staticId();
    /**
     * Prints this exception to the given stream.
     * @param stream The target stream.
     */
    ICE_MEMBER(ICE_API) virtual void ice_print(::std::ostream& stream) const override;
};

/**
 * This exception is raised by an operation call if the application closes the connection locally using
 * {@link Connection#close}.
 * @see Connection#close
 * \headerfile Ice/Ice.h
 */
class ICE_CLASS(ICE_API) ConnectionManuallyClosedException : public LocalExceptionHelper<ConnectionManuallyClosedException, LocalException>
{
public:

    ICE_MEMBER(ICE_API) virtual ~ConnectionManuallyClosedException();

    ConnectionManuallyClosedException(const ConnectionManuallyClosedException&) = default;

    /**
     * The file and line number are required for all local exceptions.
     * @param file The file name in which the exception was raised, typically __FILE__.
     * @param line The line number at which the exception was raised, typically __LINE__.
     */
    ConnectionManuallyClosedException(const char* file, int line) : LocalExceptionHelper<ConnectionManuallyClosedException, LocalException>(file, line)
    {
    }

    /**
     * One-shot constructor to initialize all data members.
     * The file and line number are required for all local exceptions.
     * @param file The file name in which the exception was raised, typically __FILE__.
     * @param line The line number at which the exception was raised, typically __LINE__.
     * @param graceful True if the connection was closed gracefully, false otherwise.
     */
    ConnectionManuallyClosedException(const char* file, int line, bool graceful) : LocalExceptionHelper<ConnectionManuallyClosedException, LocalException>(file, line),
        graceful(graceful)
    {
    }

    /**
     * Obtains a tuple containing all of the exception's data members.
     * @return The data members in a tuple.
     */
    std::tuple<const bool&> ice_tuple() const
    {
        return std::tie(graceful);
    }

    /**
     * Obtains the Slice type ID of this exception.
     * @return The fully-scoped type ID.
     */
    ICE_MEMBER(ICE_API) static const ::std::string& ice_staticId();
    /**
     * Prints this exception to the given stream.
     * @param stream The target stream.
     */
    ICE_MEMBER(ICE_API) virtual void ice_print(::std::ostream& stream) const override;

    /**
     * True if the connection was closed gracefully, false otherwise.
     */
    bool graceful;
};

/**
 * This exception indicates that a message size is less than the minimum required size.
 * \headerfile Ice/Ice.h
 */
class ICE_CLASS(ICE_API) IllegalMessageSizeException : public LocalExceptionHelper<IllegalMessageSizeException, ProtocolException>
{
public:

    ICE_MEMBER(ICE_API) virtual ~IllegalMessageSizeException();

    IllegalMessageSizeException(const IllegalMessageSizeException&) = default;

    /**
     * The file and line number are required for all local exceptions.
     * @param file The file name in which the exception was raised, typically __FILE__.
     * @param line The line number at which the exception was raised, typically __LINE__.
     */
    IllegalMessageSizeException(const char* file, int line) : LocalExceptionHelper<IllegalMessageSizeException, ProtocolException>(file, line)
    {
    }

    /**
     * One-shot constructor to initialize all data members.
     * The file and line number are required for all local exceptions.
     * @param file The file name in which the exception was raised, typically __FILE__.
     * @param line The line number at which the exception was raised, typically __LINE__.
     * @param reason The reason for the failure.
     */
    IllegalMessageSizeException(const char* file, int line, const ::std::string& reason) :
        LocalExceptionHelper<IllegalMessageSizeException, ProtocolException>(file, line, reason)
    {
    }

    /**
     * Obtains a tuple containing all of the exception's data members.
     * @return The data members in a tuple.
     */
    std::tuple<const ::std::string&> ice_tuple() const
    {
        return std::tie(reason);
    }

    /**
     * Obtains the Slice type ID of this exception.
     * @return The fully-scoped type ID.
     */
    ICE_MEMBER(ICE_API) static const ::std::string& ice_staticId();
    /**
     * Prints this exception to the given stream.
     * @param stream The target stream.
     */
    ICE_MEMBER(ICE_API) virtual void ice_print(::std::ostream& stream) const override;
};

/**
 * This exception indicates a problem with compressing or uncompressing data.
 * \headerfile Ice/Ice.h
 */
class ICE_CLASS(ICE_API) CompressionException : public LocalExceptionHelper<CompressionException, ProtocolException>
{
public:

    ICE_MEMBER(ICE_API) virtual ~CompressionException();

    CompressionException(const CompressionException&) = default;

    /**
     * The file and line number are required for all local exceptions.
     * @param file The file name in which the exception was raised, typically __FILE__.
     * @param line The line number at which the exception was raised, typically __LINE__.
     */
    CompressionException(const char* file, int line) : LocalExceptionHelper<CompressionException, ProtocolException>(file, line)
    {
    }

    /**
     * One-shot constructor to initialize all data members.
     * The file and line number are required for all local exceptions.
     * @param file The file name in which the exception was raised, typically __FILE__.
     * @param line The line number at which the exception was raised, typically __LINE__.
     * @param reason The reason for the failure.
     */
    CompressionException(const char* file, int line, const ::std::string& reason) :
        LocalExceptionHelper<CompressionException, ProtocolException>(file, line, reason)
    {
    }

    /**
     * Obtains a tuple containing all of the exception's data members.
     * @return The data members in a tuple.
     */
    std::tuple<const ::std::string&> ice_tuple() const
    {
        return std::tie(reason);
    }

    /**
     * Obtains the Slice type ID of this exception.
     * @return The fully-scoped type ID.
     */
    ICE_MEMBER(ICE_API) static const ::std::string& ice_staticId();
    /**
     * Prints this exception to the given stream.
     * @param stream The target stream.
     */
    ICE_MEMBER(ICE_API) virtual void ice_print(::std::ostream& stream) const override;
};

/**
 * A datagram exceeds the configured size. This exception is raised if a datagram exceeds the configured send or
 * receive buffer size, or exceeds the maximum payload size of a UDP packet (65507 bytes).
 * \headerfile Ice/Ice.h
 */
class ICE_CLASS(ICE_API) DatagramLimitException : public LocalExceptionHelper<DatagramLimitException, ProtocolException>
{
public:

    ICE_MEMBER(ICE_API) virtual ~DatagramLimitException();

    DatagramLimitException(const DatagramLimitException&) = default;

    /**
     * The file and line number are required for all local exceptions.
     * @param file The file name in which the exception was raised, typically __FILE__.
     * @param line The line number at which the exception was raised, typically __LINE__.
     */
    DatagramLimitException(const char* file, int line) : LocalExceptionHelper<DatagramLimitException, ProtocolException>(file, line)
    {
    }

    /**
     * One-shot constructor to initialize all data members.
     * The file and line number are required for all local exceptions.
     * @param file The file name in which the exception was raised, typically __FILE__.
     * @param line The line number at which the exception was raised, typically __LINE__.
     * @param reason The reason for the failure.
     */
    DatagramLimitException(const char* file, int line, const ::std::string& reason) :
        LocalExceptionHelper<DatagramLimitException, ProtocolException>(file, line, reason)
    {
    }

    /**
     * Obtains a tuple containing all of the exception's data members.
     * @return The data members in a tuple.
     */
    std::tuple<const ::std::string&> ice_tuple() const
    {
        return std::tie(reason);
    }

    /**
     * Obtains the Slice type ID of this exception.
     * @return The fully-scoped type ID.
     */
    ICE_MEMBER(ICE_API) static const ::std::string& ice_staticId();
    /**
     * Prints this exception to the given stream.
     * @param stream The target stream.
     */
    ICE_MEMBER(ICE_API) virtual void ice_print(::std::ostream& stream) const override;
};

/**
 * This exception is raised for errors during marshaling or unmarshaling data.
 * \headerfile Ice/Ice.h
 */
class ICE_CLASS(ICE_API) MarshalException : public LocalExceptionHelper<MarshalException, ProtocolException>
{
public:

    ICE_MEMBER(ICE_API) virtual ~MarshalException();

    MarshalException(const MarshalException&) = default;

    /**
     * The file and line number are required for all local exceptions.
     * @param file The file name in which the exception was raised, typically __FILE__.
     * @param line The line number at which the exception was raised, typically __LINE__.
     */
    MarshalException(const char* file, int line) : LocalExceptionHelper<MarshalException, ProtocolException>(file, line)
    {
    }

    /**
     * One-shot constructor to initialize all data members.
     * The file and line number are required for all local exceptions.
     * @param file The file name in which the exception was raised, typically __FILE__.
     * @param line The line number at which the exception was raised, typically __LINE__.
     * @param reason The reason for the failure.
     */
    MarshalException(const char* file, int line, const ::std::string& reason) :
        LocalExceptionHelper<MarshalException, ProtocolException>(file, line, reason)
    {
    }

    /**
     * Obtains a tuple containing all of the exception's data members.
     * @return The data members in a tuple.
     */
    std::tuple<const ::std::string&> ice_tuple() const
    {
        return std::tie(reason);
    }

    /**
     * Obtains the Slice type ID of this exception.
     * @return The fully-scoped type ID.
     */
    ICE_MEMBER(ICE_API) static const ::std::string& ice_staticId();
    /**
     * Prints this exception to the given stream.
     * @param stream The target stream.
     */
    ICE_MEMBER(ICE_API) virtual void ice_print(::std::ostream& stream) const override;
};

/**
 * This exception is raised if inconsistent data is received while unmarshaling a proxy.
 * \headerfile Ice/Ice.h
 */
class ICE_CLASS(ICE_API) ProxyUnmarshalException : public LocalExceptionHelper<ProxyUnmarshalException, MarshalException>
{
public:

    ICE_MEMBER(ICE_API) virtual ~ProxyUnmarshalException();

    ProxyUnmarshalException(const ProxyUnmarshalException&) = default;

    /**
     * The file and line number are required for all local exceptions.
     * @param file The file name in which the exception was raised, typically __FILE__.
     * @param line The line number at which the exception was raised, typically __LINE__.
     */
    ProxyUnmarshalException(const char* file, int line) : LocalExceptionHelper<ProxyUnmarshalException, MarshalException>(file, line)
    {
    }

    /**
     * One-shot constructor to initialize all data members.
     * The file and line number are required for all local exceptions.
     * @param file The file name in which the exception was raised, typically __FILE__.
     * @param line The line number at which the exception was raised, typically __LINE__.
     * @param reason The reason for the failure.
     */
    ProxyUnmarshalException(const char* file, int line, const ::std::string& reason) :
        LocalExceptionHelper<ProxyUnmarshalException, MarshalException>(file, line, reason)
    {
    }

    /**
     * Obtains a tuple containing all of the exception's data members.
     * @return The data members in a tuple.
     */
    std::tuple<const ::std::string&> ice_tuple() const
    {
        return std::tie(reason);
    }

    /**
     * Obtains the Slice type ID of this exception.
     * @return The fully-scoped type ID.
     */
    ICE_MEMBER(ICE_API) static const ::std::string& ice_staticId();
    /**
     * Prints this exception to the given stream.
     * @param stream The target stream.
     */
    ICE_MEMBER(ICE_API) virtual void ice_print(::std::ostream& stream) const override;
};

/**
 * This exception is raised if an out-of-bounds condition occurs during unmarshaling.
 * \headerfile Ice/Ice.h
 */
class ICE_CLASS(ICE_API) UnmarshalOutOfBoundsException : public LocalExceptionHelper<UnmarshalOutOfBoundsException, MarshalException>
{
public:

    ICE_MEMBER(ICE_API) virtual ~UnmarshalOutOfBoundsException();

    UnmarshalOutOfBoundsException(const UnmarshalOutOfBoundsException&) = default;

    /**
     * The file and line number are required for all local exceptions.
     * @param file The file name in which the exception was raised, typically __FILE__.
     * @param line The line number at which the exception was raised, typically __LINE__.
     */
    UnmarshalOutOfBoundsException(const char* file, int line) : LocalExceptionHelper<UnmarshalOutOfBoundsException, MarshalException>(file, line)
    {
    }

    /**
     * One-shot constructor to initialize all data members.
     * The file and line number are required for all local exceptions.
     * @param file The file name in which the exception was raised, typically __FILE__.
     * @param line The line number at which the exception was raised, typically __LINE__.
     * @param reason The reason for the failure.
     */
    UnmarshalOutOfBoundsException(const char* file, int line, const ::std::string& reason) :
        LocalExceptionHelper<UnmarshalOutOfBoundsException, MarshalException>(file, line, reason)
    {
    }

    /**
     * Obtains a tuple containing all of the exception's data members.
     * @return The data members in a tuple.
     */
    std::tuple<const ::std::string&> ice_tuple() const
    {
        return std::tie(reason);
    }

    /**
     * Obtains the Slice type ID of this exception.
     * @return The fully-scoped type ID.
     */
    ICE_MEMBER(ICE_API) static const ::std::string& ice_staticId();
    /**
     * Prints this exception to the given stream.
     * @param stream The target stream.
     */
    ICE_MEMBER(ICE_API) virtual void ice_print(::std::ostream& stream) const override;
};

/**
 * This exception is raised if no suitable value factory was found during unmarshaling of a Slice class instance.
 * @see ValueFactory
 * @see Communicator#getValueFactoryManager
 * @see ValueFactoryManager#add
 * @see ValueFactoryManager#find
 * \headerfile Ice/Ice.h
 */
class ICE_CLASS(ICE_API) NoValueFactoryException : public LocalExceptionHelper<NoValueFactoryException, MarshalException>
{
public:

    ICE_MEMBER(ICE_API) virtual ~NoValueFactoryException();

    NoValueFactoryException(const NoValueFactoryException&) = default;

    /**
     * The file and line number are required for all local exceptions.
     * @param file The file name in which the exception was raised, typically __FILE__.
     * @param line The line number at which the exception was raised, typically __LINE__.
     */
    NoValueFactoryException(const char* file, int line) : LocalExceptionHelper<NoValueFactoryException, MarshalException>(file, line)
    {
    }

    /**
     * One-shot constructor to initialize all data members.
     * The file and line number are required for all local exceptions.
     * @param file The file name in which the exception was raised, typically __FILE__.
     * @param line The line number at which the exception was raised, typically __LINE__.
     * @param reason The reason for the failure.
     * @param type The Slice type ID of the class instance for which no factory could be found.
     */
    NoValueFactoryException(const char* file, int line, const ::std::string& reason, const ::std::string& type) :
        LocalExceptionHelper<NoValueFactoryException, MarshalException>(file, line, reason),
        type(type)
    {
    }

    /**
     * Obtains a tuple containing all of the exception's data members.
     * @return The data members in a tuple.
     */
    std::tuple<const ::std::string&, const ::std::string&> ice_tuple() const
    {
        return std::tie(reason, type);
    }

    /**
     * Obtains the Slice type ID of this exception.
     * @return The fully-scoped type ID.
     */
    ICE_MEMBER(ICE_API) static const ::std::string& ice_staticId();
    /**
     * Prints this exception to the given stream.
     * @param stream The target stream.
     */
    ICE_MEMBER(ICE_API) virtual void ice_print(::std::ostream& stream) const override;

    /**
     * The Slice type ID of the class instance for which no factory could be found.
     */
    ::std::string type;
};

/**
 * This exception is raised if the type of an unmarshaled Slice class instance does not match its expected type. This
 * can happen if client and server are compiled with mismatched Slice definitions or if a class of the wrong type is
 * passed as a parameter or return value using dynamic invocation. This exception can also be raised if IceStorm is
 * used to send Slice class instances and an operation is subscribed to the wrong topic.
 * \headerfile Ice/Ice.h
 */
class ICE_CLASS(ICE_API) UnexpectedObjectException : public LocalExceptionHelper<UnexpectedObjectException, MarshalException>
{
public:

    ICE_MEMBER(ICE_API) virtual ~UnexpectedObjectException();

    UnexpectedObjectException(const UnexpectedObjectException&) = default;

    /**
     * The file and line number are required for all local exceptions.
     * @param file The file name in which the exception was raised, typically __FILE__.
     * @param line The line number at which the exception was raised, typically __LINE__.
     */
    UnexpectedObjectException(const char* file, int line) : LocalExceptionHelper<UnexpectedObjectException, MarshalException>(file, line)
    {
    }

    /**
     * One-shot constructor to initialize all data members.
     * The file and line number are required for all local exceptions.
     * @param file The file name in which the exception was raised, typically __FILE__.
     * @param line The line number at which the exception was raised, typically __LINE__.
     * @param reason The reason for the failure.
     * @param type The Slice type ID of the class instance that was unmarshaled.
     * @param expectedType The Slice type ID that was expected by the receiving operation.
     */
    UnexpectedObjectException(const char* file, int line, const ::std::string& reason, const ::std::string& type, const ::std::string& expectedType) :
        LocalExceptionHelper<UnexpectedObjectException, MarshalException>(file, line, reason),
        type(type),
        expectedType(expectedType)
    {
    }

    /**
     * Obtains a tuple containing all of the exception's data members.
     * @return The data members in a tuple.
     */
    std::tuple<const ::std::string&, const ::std::string&, const ::std::string&> ice_tuple() const
    {
        return std::tie(reason, type, expectedType);
    }

    /**
     * Obtains the Slice type ID of this exception.
     * @return The fully-scoped type ID.
     */
    ICE_MEMBER(ICE_API) static const ::std::string& ice_staticId();
    /**
     * Prints this exception to the given stream.
     * @param stream The target stream.
     */
    ICE_MEMBER(ICE_API) virtual void ice_print(::std::ostream& stream) const override;

    /**
     * The Slice type ID of the class instance that was unmarshaled.
     */
    ::std::string type;
    /**
     * The Slice type ID that was expected by the receiving operation.
     */
    ::std::string expectedType;
};

/**
 * This exception is raised when Ice receives a request or reply message whose size exceeds the limit specified by the
 * <code>Ice.MessageSizeMax</code> property.
 * \headerfile Ice/Ice.h
 */
class ICE_CLASS(ICE_API) MemoryLimitException : public LocalExceptionHelper<MemoryLimitException, MarshalException>
{
public:

    ICE_MEMBER(ICE_API) virtual ~MemoryLimitException();

    MemoryLimitException(const MemoryLimitException&) = default;

    /**
     * The file and line number are required for all local exceptions.
     * @param file The file name in which the exception was raised, typically __FILE__.
     * @param line The line number at which the exception was raised, typically __LINE__.
     */
    MemoryLimitException(const char* file, int line) : LocalExceptionHelper<MemoryLimitException, MarshalException>(file, line)
    {
    }

    /**
     * One-shot constructor to initialize all data members.
     * The file and line number are required for all local exceptions.
     * @param file The file name in which the exception was raised, typically __FILE__.
     * @param line The line number at which the exception was raised, typically __LINE__.
     * @param reason The reason for the failure.
     */
    MemoryLimitException(const char* file, int line, const ::std::string& reason) :
        LocalExceptionHelper<MemoryLimitException, MarshalException>(file, line, reason)
    {
    }

    /**
     * Obtains a tuple containing all of the exception's data members.
     * @return The data members in a tuple.
     */
    std::tuple<const ::std::string&> ice_tuple() const
    {
        return std::tie(reason);
    }

    /**
     * Obtains the Slice type ID of this exception.
     * @return The fully-scoped type ID.
     */
    ICE_MEMBER(ICE_API) static const ::std::string& ice_staticId();
    /**
     * Prints this exception to the given stream.
     * @param stream The target stream.
     */
    ICE_MEMBER(ICE_API) virtual void ice_print(::std::ostream& stream) const override;
};

/**
 * This exception is raised when a string conversion to or from UTF-8 fails during marshaling or unmarshaling.
 * \headerfile Ice/Ice.h
 */
class ICE_CLASS(ICE_API) StringConversionException : public LocalExceptionHelper<StringConversionException, MarshalException>
{
public:

    ICE_MEMBER(ICE_API) virtual ~StringConversionException();

    StringConversionException(const StringConversionException&) = default;

    /**
     * The file and line number are required for all local exceptions.
     * @param file The file name in which the exception was raised, typically __FILE__.
     * @param line The line number at which the exception was raised, typically __LINE__.
     */
    StringConversionException(const char* file, int line) : LocalExceptionHelper<StringConversionException, MarshalException>(file, line)
    {
    }

    /**
     * One-shot constructor to initialize all data members.
     * The file and line number are required for all local exceptions.
     * @param file The file name in which the exception was raised, typically __FILE__.
     * @param line The line number at which the exception was raised, typically __LINE__.
     * @param reason The reason for the failure.
     */
    StringConversionException(const char* file, int line, const ::std::string& reason) :
        LocalExceptionHelper<StringConversionException, MarshalException>(file, line, reason)
    {
    }

    /**
     * Obtains a tuple containing all of the exception's data members.
     * @return The data members in a tuple.
     */
    std::tuple<const ::std::string&> ice_tuple() const
    {
        return std::tie(reason);
    }

    /**
     * Obtains the Slice type ID of this exception.
     * @return The fully-scoped type ID.
     */
    ICE_MEMBER(ICE_API) static const ::std::string& ice_staticId();
    /**
     * Prints this exception to the given stream.
     * @param stream The target stream.
     */
    ICE_MEMBER(ICE_API) virtual void ice_print(::std::ostream& stream) const override;
};

/**
 * This exception indicates a malformed data encapsulation.
 * \headerfile Ice/Ice.h
 */
class ICE_CLASS(ICE_API) EncapsulationException : public LocalExceptionHelper<EncapsulationException, MarshalException>
{
public:

    ICE_MEMBER(ICE_API) virtual ~EncapsulationException();

    EncapsulationException(const EncapsulationException&) = default;

    /**
     * The file and line number are required for all local exceptions.
     * @param file The file name in which the exception was raised, typically __FILE__.
     * @param line The line number at which the exception was raised, typically __LINE__.
     */
    EncapsulationException(const char* file, int line) : LocalExceptionHelper<EncapsulationException, MarshalException>(file, line)
    {
    }

    /**
     * One-shot constructor to initialize all data members.
     * The file and line number are required for all local exceptions.
     * @param file The file name in which the exception was raised, typically __FILE__.
     * @param line The line number at which the exception was raised, typically __LINE__.
     * @param reason The reason for the failure.
     */
    EncapsulationException(const char* file, int line, const ::std::string& reason) :
        LocalExceptionHelper<EncapsulationException, MarshalException>(file, line, reason)
    {
    }

    /**
     * Obtains a tuple containing all of the exception's data members.
     * @return The data members in a tuple.
     */
    std::tuple<const ::std::string&> ice_tuple() const
    {
        return std::tie(reason);
    }

    /**
     * Obtains the Slice type ID of this exception.
     * @return The fully-scoped type ID.
     */
    ICE_MEMBER(ICE_API) static const ::std::string& ice_staticId();
    /**
     * Prints this exception to the given stream.
     * @param stream The target stream.
     */
    ICE_MEMBER(ICE_API) virtual void ice_print(::std::ostream& stream) const override;
};

/**
 * This exception is raised if an unsupported feature is used. The unsupported feature string contains the name of the
 * unsupported feature.
 * \headerfile Ice/Ice.h
 */
class ICE_CLASS(ICE_API) FeatureNotSupportedException : public LocalExceptionHelper<FeatureNotSupportedException, LocalException>
{
public:

    ICE_MEMBER(ICE_API) virtual ~FeatureNotSupportedException();

    FeatureNotSupportedException(const FeatureNotSupportedException&) = default;

    /**
     * The file and line number are required for all local exceptions.
     * @param file The file name in which the exception was raised, typically __FILE__.
     * @param line The line number at which the exception was raised, typically __LINE__.
     */
    FeatureNotSupportedException(const char* file, int line) : LocalExceptionHelper<FeatureNotSupportedException, LocalException>(file, line)
    {
    }

    /**
     * One-shot constructor to initialize all data members.
     * The file and line number are required for all local exceptions.
     * @param file The file name in which the exception was raised, typically __FILE__.
     * @param line The line number at which the exception was raised, typically __LINE__.
     * @param unsupportedFeature The name of the unsupported feature.
     */
    FeatureNotSupportedException(const char* file, int line, const ::std::string& unsupportedFeature) : LocalExceptionHelper<FeatureNotSupportedException, LocalException>(file, line),
        unsupportedFeature(unsupportedFeature)
    {
    }

    /**
     * Obtains a tuple containing all of the exception's data members.
     * @return The data members in a tuple.
     */
    std::tuple<const ::std::string&> ice_tuple() const
    {
        return std::tie(unsupportedFeature);
    }

    /**
     * Obtains the Slice type ID of this exception.
     * @return The fully-scoped type ID.
     */
    ICE_MEMBER(ICE_API) static const ::std::string& ice_staticId();
    /**
     * Prints this exception to the given stream.
     * @param stream The target stream.
     */
    ICE_MEMBER(ICE_API) virtual void ice_print(::std::ostream& stream) const override;

    /**
     * The name of the unsupported feature.
     */
    ::std::string unsupportedFeature;
};

/**
 * This exception indicates a failure in a security subsystem, such as the IceSSL plug-in.
 * \headerfile Ice/Ice.h
 */
class ICE_CLASS(ICE_API) SecurityException : public LocalExceptionHelper<SecurityException, LocalException>
{
public:

    ICE_MEMBER(ICE_API) virtual ~SecurityException();

    SecurityException(const SecurityException&) = default;

    /**
     * The file and line number are required for all local exceptions.
     * @param file The file name in which the exception was raised, typically __FILE__.
     * @param line The line number at which the exception was raised, typically __LINE__.
     */
    SecurityException(const char* file, int line) : LocalExceptionHelper<SecurityException, LocalException>(file, line)
    {
    }

    /**
     * One-shot constructor to initialize all data members.
     * The file and line number are required for all local exceptions.
     * @param file The file name in which the exception was raised, typically __FILE__.
     * @param line The line number at which the exception was raised, typically __LINE__.
     * @param reason The reason for the failure.
     */
    SecurityException(const char* file, int line, const ::std::string& reason) : LocalExceptionHelper<SecurityException, LocalException>(file, line),
        reason(reason)
    {
    }

    /**
     * Obtains a tuple containing all of the exception's data members.
     * @return The data members in a tuple.
     */
    std::tuple<const ::std::string&> ice_tuple() const
    {
        return std::tie(reason);
    }

    /**
     * Obtains the Slice type ID of this exception.
     * @return The fully-scoped type ID.
     */
    ICE_MEMBER(ICE_API) static const ::std::string& ice_staticId();
    /**
     * Prints this exception to the given stream.
     * @param stream The target stream.
     */
    ICE_MEMBER(ICE_API) virtual void ice_print(::std::ostream& stream) const override;

    /**
     * The reason for the failure.
     */
    ::std::string reason;
};

/**
 * This exception indicates that an attempt has been made to change the connection properties of a fixed proxy.
 * \headerfile Ice/Ice.h
 */
class ICE_CLASS(ICE_API) FixedProxyException : public LocalExceptionHelper<FixedProxyException, LocalException>
{
public:

    ICE_MEMBER(ICE_API) virtual ~FixedProxyException();

    FixedProxyException(const FixedProxyException&) = default;

    /**
     * The file and line number are required for all local exceptions.
     * @param file The file name in which the exception was raised, typically __FILE__.
     * @param line The line number at which the exception was raised, typically __LINE__.
     */
    FixedProxyException(const char* file, int line) : LocalExceptionHelper<FixedProxyException, LocalException>(file, line)
    {
    }

    /**
     * Obtains a tuple containing all of the exception's data members.
     * @return The data members in a tuple.
     */
    std::tuple<> ice_tuple() const
    {
        return std::tie();
    }

    /**
     * Obtains the Slice type ID of this exception.
     * @return The fully-scoped type ID.
     */
    ICE_MEMBER(ICE_API) static const ::std::string& ice_staticId();
    /**
     * Prints this exception to the given stream.
     * @param stream The target stream.
     */
    ICE_MEMBER(ICE_API) virtual void ice_print(::std::ostream& stream) const override;
};

/**
 * Indicates that the response to a request has already been sent; re-dispatching such a request is not possible.
 * \headerfile Ice/Ice.h
 */
class ICE_CLASS(ICE_API) ResponseSentException : public LocalExceptionHelper<ResponseSentException, LocalException>
{
public:

    ICE_MEMBER(ICE_API) virtual ~ResponseSentException();

    ResponseSentException(const ResponseSentException&) = default;

    /**
     * The file and line number are required for all local exceptions.
     * @param file The file name in which the exception was raised, typically __FILE__.
     * @param line The line number at which the exception was raised, typically __LINE__.
     */
    ResponseSentException(const char* file, int line) : LocalExceptionHelper<ResponseSentException, LocalException>(file, line)
    {
    }

    /**
     * Obtains a tuple containing all of the exception's data members.
     * @return The data members in a tuple.
     */
    std::tuple<> ice_tuple() const
    {
        return std::tie();
    }

    /**
     * Obtains the Slice type ID of this exception.
     * @return The fully-scoped type ID.
     */
    ICE_MEMBER(ICE_API) static const ::std::string& ice_staticId();
    /**
     * Prints this exception to the given stream.
     * @param stream The target stream.
     */
    ICE_MEMBER(ICE_API) virtual void ice_print(::std::ostream& stream) const override;
};

}

/// \cond STREAM
namespace Ice
{

}
/// \endcond

#include <IceUtil/PopDisableWarnings.h>
#endif
