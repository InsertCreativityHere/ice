// Copyright (c) ZeroC, Inc.

package test.Slice.deprecated;

import com.zeroc.Ice.Current;

import test.Slice.deprecated.Test.MyInterface;

// Make sure we can implement a deprecated interface without warning.
class MyInterfaceI implements MyInterface {
    @Override
    public void opInt(int i, Current current) {}
}
