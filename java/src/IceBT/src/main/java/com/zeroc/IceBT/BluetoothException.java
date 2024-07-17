// Copyright (c) ZeroC, Inc.

package com.zeroc.IceBT;

/** Indicates a failure in the Bluetooth plug-in. */
public class BluetoothException extends com.zeroc.Ice.LocalException
{
    public BluetoothException()
    {
        this.reason = "";
    }

    public BluetoothException(Throwable cause)
    {
        super(cause);
        this.reason = "";
    }

    public BluetoothException(String reason)
    {
        this.reason = reason;
    }

    public BluetoothException(String reason, Throwable cause)
    {
        super(cause);
        this.reason = reason;
    }

    public String ice_id()
    {
        return "::IceBT::BluetoothException";
    }

    /** Provides more information about the failure. */
    public String reason;

    private static final long serialVersionUID = -2714934297616925968L;
}
