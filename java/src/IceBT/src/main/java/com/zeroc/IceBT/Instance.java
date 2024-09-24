// Copyright (c) ZeroC, Inc.

package com.zeroc.IceBT;

import android.bluetooth.BluetoothAdapter;
import com.zeroc.Ice.Communicator;
import com.zeroc.Ice.PluginInitializationException;

class Instance extends com.zeroc.Ice.ProtocolInstance {
    Instance(Communicator communicator, short type, String protocol) {
        super(communicator, type, protocol, type == com.zeroc.Ice.BTSEndpointType.value);

        _communicator = communicator;

        _bluetoothAdapter = BluetoothAdapter.getDefaultAdapter();
        if (_bluetoothAdapter == null) {
            throw new PluginInitializationException("bluetooth adapter not available");
        } else if (!_bluetoothAdapter.isEnabled()) {
            throw new PluginInitializationException("bluetooth is not enabled");
        }
    }

    void destroy() {
        _communicator = null;
    }

    Communicator communicator() {
        return _communicator;
    }

    BluetoothAdapter bluetoothAdapter() {
        return _bluetoothAdapter;
    }

    private Communicator _communicator;
    private BluetoothAdapter _bluetoothAdapter;
}
