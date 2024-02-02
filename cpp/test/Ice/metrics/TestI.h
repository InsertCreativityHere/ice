//
// Copyright (c) ZeroC, Inc. All rights reserved.
//

#ifndef TEST_I_H
#define TEST_I_H

#include <Test.h>

class MetricsI : public Test::Metrics
{
    virtual void op(const Ice::Current&);

    virtual void fail(const Ice::Current&);

    virtual void opWithUserException(const Ice::Current&);

    virtual void opWithRequestFailedException(const Ice::Current&);

    virtual void opWithLocalException(const Ice::Current&);

    virtual void opWithUnknownException(const Ice::Current&);

    virtual void opByteS(Test::ByteSeq, const Ice::Current&);

    virtual Ice::ObjectPrxPtr getAdmin(const Ice::Current&);

    virtual void shutdown(const Ice::Current&);
};

class ControllerI : public Test::Controller
{
public:

    ControllerI(const Ice::ObjectAdapterPtr&);

    virtual void hold(const Ice::Current&);

    virtual void resume(const Ice::Current&);

private:

    const Ice::ObjectAdapterPtr _adapter;
};

#endif
