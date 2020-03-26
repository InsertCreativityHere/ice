//
// Copyright (c) ZeroC, Inc. All rights reserved.
//

#include <Ice/Ice.h>
#include <TestAMDI.h>
#include <TestHelper.h>

using namespace Test;
using namespace std;

bool
endsWith(const string& s, const string& findme)
{
    if(s.length() > findme.length())
    {
        return 0 == s.compare(s.length() - findme.length(), findme.length(), findme);
    }
    return false;
}

ThrowerI::ThrowerI()
{
}

void
ThrowerI::shutdownAsync(function<void()> response,
                        function<void(exception_ptr)>,
                        const Ice::Current& current)
{
    current.adapter->getCommunicator()->shutdown();
    response();
}

void
ThrowerI::supportsUndeclaredExceptionsAsync(function<void(bool)> response,
                                            function<void(exception_ptr)>,
                                            const Ice::Current&)
{
    response(true);
}

void
ThrowerI::supportsAssertExceptionAsync(function<void(bool)> response,
                                       function<void(exception_ptr)>,
                                       const Ice::Current&)
{
    response(false);
}

void
ThrowerI::throwAasAAsync(int a,
                         function<void()>,
                         function<void(exception_ptr)> exception,
                         const Ice::Current&)
{
    try
    {
        A ex;
        ex.aMem = a;
        throw ex;
    }
    catch(...)
    {
        exception(current_exception());
    }
}

void
ThrowerI::throwAorDasAorDAsync(int a,
                               function<void()>,
                               function<void(exception_ptr)> exception,
                               const Ice::Current&)
{
    try
    {
        if(a > 0)
        {
            A ex;
            ex.aMem = a;
            throw ex;
        }
        else
        {
            D ex;
            ex.dMem = a;
            throw ex;
        }
    }
    catch(...)
    {
        exception(current_exception());
    }
}

void
ThrowerI::throwBasAAsync(int a, int b,
                         function<void()>,
                         function<void(exception_ptr)> exception,
                         const Ice::Current&)
{
    try
    {
        B ex;
        ex.aMem = a;
        ex.bMem = b;
        throw ex;
    }
    catch(...)
    {
        exception(current_exception());
    }
}

void
ThrowerI::throwCasAAsync(int a, int b, int c,
                         function<void()>,
                         function<void(exception_ptr)> exception,
                         const Ice::Current&)
{
    try
    {
        C ex;
        ex.aMem = a;
        ex.bMem = b;
        ex.cMem = c;
        throw ex;
    }
    catch(...)
    {
        exception(current_exception());
    }
}

void
ThrowerI::throwBasBAsync(int a, int b,
                         function<void()>,
                         function<void(exception_ptr)> exception,
                         const Ice::Current&)
{
    try
    {
        B ex;
        ex.aMem = a;
        ex.bMem = b;
        throw ex;
    }
    catch(...)
    {
        exception(current_exception());
    }
}

void
ThrowerI::throwCasBAsync(int a, int b, int c,
                         function<void()>,
                         function<void(exception_ptr)> exception,
                         const Ice::Current&)
{
    try
    {
        C ex;
        ex.aMem = a;
        ex.bMem = b;
        ex.cMem = c;
        throw ex;
    }
    catch(...)
    {
        exception(current_exception());
    }
}

void
ThrowerI::throwCasCAsync(int a, int b, int c,
                         function<void()>,
                         function<void(exception_ptr)> exception,
                         const Ice::Current&)
{
    try
    {
        C ex;
        ex.aMem = a;
        ex.bMem = b;
        ex.cMem = c;
        throw ex;
    }
    catch(...)
    {
        exception(current_exception());
    }
}

void
ThrowerI::throwModAAsync(int a, int a2,
                         function<void()>,
                         function<void(exception_ptr)>,
                         const Ice::Current&)
{
    Mod::A ex;
    ex.aMem = a;
    ex.a2Mem = a2;
    throw ex;
}

void
ThrowerI::throwUndeclaredAAsync(int a,
                                function<void()>,
                                function<void(exception_ptr)> exception,
                                const Ice::Current&)
{
    try
    {
        A ex;
        ex.aMem = a;
        throw ex;
    }
    catch(...)
    {
        exception(current_exception());
    }
}

void
ThrowerI::throwUndeclaredBAsync(int a, int b,
                                function<void()>,
                                function<void(exception_ptr)>,
                                const Ice::Current&)
{
    B ex;
    ex.aMem = a;
    ex.bMem = b;
    throw ex;
}

void
ThrowerI::throwUndeclaredCAsync(int a, int b, int c,
                                function<void()>,
                                function<void(exception_ptr)> exception,
                                const Ice::Current&)
{
    try
    {
        C ex;
        ex.aMem = a;
        ex.bMem = b;
        ex.cMem = c;
        throw ex;
    }
    catch(...)
    {
        exception(current_exception());
    }
}

void
ThrowerI::throwLocalExceptionAsync(function<void()>,
                                   function<void(exception_ptr)> exception,
                                   const Ice::Current&)
{
    try
    {
        throw Ice::TimeoutException(__FILE__, __LINE__);
    }
    catch(...)
    {
        exception(current_exception());
    }
}

void
ThrowerI::throwNonIceExceptionAsync(function<void()>,
                                    function<void(exception_ptr)> exception,
                                    const Ice::Current&)
{
    try
    {
        throw int(12345);
    }
    catch(...)
    {
        exception(current_exception());
    }
}

void
ThrowerI::throwAssertExceptionAsync(function<void()>,
                                    function<void(exception_ptr)>,
                                    const Ice::Current&)
{
    assert(false); // No supported in C++
}

void
ThrowerI::throwMemoryLimitExceptionAsync(ICE_IN(Ice::ByteSeq),
                                         function<void(const Ice::ByteSeq&)> response,
                                         function<void(exception_ptr)>,
                                         const Ice::Current&)
{
    response(Ice::ByteSeq(1024 * 20)); // 20 KB.
}

void
ThrowerI::throwLocalExceptionIdempotentAsync(function<void()>,
                                             function<void(exception_ptr)> exception,
                                             const Ice::Current&)
{
    try
    {
        throw Ice::TimeoutException(__FILE__, __LINE__);
    }
    catch(...)
    {
        exception(current_exception());
    }

}

void
ThrowerI::throwAfterResponseAsync(function<void()> response,
                                  function<void(exception_ptr)>,
                                  const Ice::Current&)
{
    response();

    throw std::string();
}

void
ThrowerI::throwAfterExceptionAsync(function<void()>,
                                   function<void(exception_ptr)> exception,
                                   const Ice::Current&)
{
    try
    {
        throw A(12345);
    }
    catch(...)
    {
        exception(current_exception());
    }
    throw std::string();
}

void
ThrowerI::throwEAsync(function<void()>,
                      function<void(exception_ptr)> exception,
                      const Ice::Current&)
{
    try
    {
        throw E("E");
    }
    catch(...)
    {
        exception(current_exception());
    }
}

void
ThrowerI::throwFAsync(function<void()>,
                      function<void(exception_ptr)> exception,
                      const Ice::Current&)
{
    try
    {
        throw F("F");
    }
    catch(...)
    {
        exception(current_exception());
    }
}

void
ThrowerI::throwGAsync(function<void()>,
                      function<void(exception_ptr)> exception,
                      const Ice::Current&)
{
    try
    {
        throw runtime_error("G async");
    }
    catch(const std::exception&)
    {
        exception(current_exception());
    }
}

void
ThrowerI::throwHAsync(function<void()>,
                      function<void(exception_ptr)> exception,
                      const Ice::Current&)
{
    try
    {
        throw runtime_error("H async");
    }
    catch(const std::exception&)
    {
        exception(current_exception());
    }
}
