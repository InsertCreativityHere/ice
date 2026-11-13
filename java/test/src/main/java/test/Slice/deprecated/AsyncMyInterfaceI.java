// Copyright (c) ZeroC, Inc.

package test.Slice.deprecated;

import com.zeroc.Ice.Current;

import test.Slice.deprecated.Test.AsyncMyInterface;

import java.util.concurrent.CompletableFuture;
import java.util.concurrent.CompletionStage;

// Make sure we can implement a deprecated interface without warning.
class AsyncMyInterfaceI implements AsyncMyInterface {
    @Override
    public CompletionStage<Void> opIntAsync(int i, Current current) {
        return CompletableFuture.completedFuture(null);
    }
}
