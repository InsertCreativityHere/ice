// Copyright (c) ZeroC, Inc.

package com.zeroc.IceBT;

import com.zeroc.Ice.Communicator;
import com.zeroc.Ice.Plugin;
import com.zeroc.Ice.PluginInitializationException;

/** Creates IceBT plug-ins. */
public class PluginFactory implements com.zeroc.Ice.PluginFactory {
    /**
     * Gets the plug-in name.
     *
     * @return The plug-in name.
     */
    @Override
    public String getPluginName() {
        return "IceBT";
    }

    /**
     * Creates a new IceBT plug-in.
     *
     * @param communicator The communicator for the plug-in.
     * @param name The name of the plug-in.
     * @param args The arguments for the plug-in.
     * @return A new IceBT plug-in instance.
     * @throws PluginInitializationException Thrown if the plug-in cannot be initialized.
     */
    @Override
    public Plugin create(
            Communicator communicator, String name, String[] args) {

        if (name == null || !name.equals(getPluginName())) {
            throw new PluginInitializationException(
                "The Bluetooth plug-in must be named '" + getPluginName() + "'.");
        }

        return new PluginI(communicator);
    }
}
