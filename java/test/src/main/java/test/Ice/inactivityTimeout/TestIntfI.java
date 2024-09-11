// Copyright (c) ZeroC, Inc.

package test.Ice.inactivityTimeout;

import com.zeroc.Ice.Current;
import test.Ice.inactivityTimeout.Test.TestIntf;

class TestIntfI implements TestIntf {
    @Override
    public void sleep(int ms, Current current) {
        try {
            Thread.sleep(ms);
        } catch (InterruptedException ex) {
            // ignored
        }
    }

    @Override
    public void shutdown(Current current) {
        current.adapter.getCommunicator().shutdown();
    }
}
