// Copyright (c) ZeroC, Inc.

package com.zeroc.Ice;

/** Provides access to WebSocket endpoint information. */
public final class WSEndpointInfo extends EndpointInfo {
    /** The URI configured for this endpoint. */
    public final String resource;

    // internal constructor
    WSEndpointInfo(EndpointInfo underlying, String resource) {
        super(underlying);
        this.resource = resource;
    }
}
