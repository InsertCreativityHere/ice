//
// Copyright (c) ZeroC, Inc. All rights reserved.
//

using System;
using System.Collections.Generic;
using Test;

public sealed class ControllerI : Controller
{
    public ControllerI(Ice.ObjectAdapter adapter)
    {
        _adapter = adapter;
    }

    public void hold(Ice.Current current)
    {
        _adapter.Hold();
        _adapter.WaitForHold();
    }

    public void resume(Ice.Current current)
    {
        _adapter.Activate();
    }

    readonly private Ice.ObjectAdapter _adapter;
};

public sealed class MetricsI : Metrics
{
    public void op(Ice.Current current)
    {
    }

    public void fail(Ice.Current current)
    {
        current.con.close(Ice.ConnectionClose.Forcefully);
    }

    public void opWithUserException(Ice.Current current)
    {
        throw new UserEx();
    }

    public void opWithRequestFailedException(Ice.Current current)
    {
        throw new Ice.ObjectNotExistException();
    }

    public void opWithLocalException(Ice.Current current)
    {
        throw new Ice.SyscallException();
    }

    public void opWithUnknownException(Ice.Current current)
    {
        throw new ArgumentOutOfRangeException();
    }

    public void opByteS(byte[] bs, Ice.Current current)
    {
    }

    public Ice.IObjectPrx getAdmin(Ice.Current current)
    {
        return current.adapter.GetCommunicator().getAdmin();
    }

    public void shutdown(Ice.Current current)
    {
        current.adapter.GetCommunicator().shutdown();
    }
}
