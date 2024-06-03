//
// Copyright (c) ZeroC, Inc. All rights reserved.
//
//
// Ice version 3.7.10
//
// <auto-generated>
//
// Generated from file `Communicator.ice'
//
// Warning: do not edit this file.
//
// </auto-generated>
//

import Foundation
import PromiseKit

/// The output mode for xxxToString method such as identityToString and proxyToString. The actual encoding format for
/// the string is the same for all modes: you don't need to specify an encoding format or mode when reading such a
/// string.
public enum ToStringMode: Swift.UInt8 {
    /// Unicode Characters with ordinal values greater than 127 are kept as-is in the resulting string. Non-printable
    /// ASCII characters with ordinal values 127 and below are encoded as \\t, \\n (etc.) or \\unnnn.
    case Unicode = 0
    /// ASCII Characters with ordinal values greater than 127 are encoded as universal character names in the resulting
    /// string: \\unnnn for BMP characters and \\Unnnnnnnn for non-BMP characters. Non-printable ASCII characters
    /// with ordinal values 127 and below are encoded as \\t, \\n (etc.) or \\unnnn.
    case ASCII = 1
    /// Compat Characters with ordinal values greater than 127 are encoded as a sequence of UTF-8 bytes using octal
    /// escapes.
    /// Characters with ordinal values 127 and below are encoded as \\t, \\n (etc.) or an octal escape. Use this mode
    /// to generate strings compatible with Ice 3.6 and earlier.
    case Compat = 2
    public init() {
        self = .Unicode
    }
}

/// An `Ice.InputStream` extension to read `ToStringMode` enumerated values from the stream.
extension InputStream {
    /// Read an enumerated value.
    ///
    /// - returns: `ToStringMode` - The enumarated value.
    public func read() throws -> ToStringMode {
        let rawValue: Swift.UInt8 = try read(enumMaxValue: 2)
        guard let val = ToStringMode(rawValue: rawValue) else {
            throw MarshalException(reason: "invalid enum value")
        }
        return val
    }

    /// Read an optional enumerated value from the stream.
    ///
    /// - parameter tag: `Int32` - The numeric tag associated with the value.
    ///
    /// - returns: `ToStringMode` - The enumerated value.
    public func read(tag: Swift.Int32) throws -> ToStringMode? {
        guard try readOptional(tag: tag, expectedFormat: .Size) else {
            return nil
        }
        return try read() as ToStringMode
    }
}

/// An `Ice.OutputStream` extension to write `ToStringMode` enumerated values to the stream.
extension OutputStream {
    /// Writes an enumerated value to the stream.
    ///
    /// parameter _: `ToStringMode` - The enumerator to write.
    public func write(_ v: ToStringMode) {
        write(enum: v.rawValue, maxValue: 2)
    }

    /// Writes an optional enumerated value to the stream.
    ///
    /// parameter tag: `Int32` - The numeric tag associated with the value.
    ///
    /// parameter _: `ToStringMode` - The enumerator to write.
    public func write(tag: Swift.Int32, value: ToStringMode?) {
        guard let v = value else {
            return
        }
        write(tag: tag, val: v.rawValue, maxValue: 2)
    }
}

/// The central object in Ice. One or more communicators can be instantiated for an Ice application. Communicator
/// instantiation is language-specific, and not specified in Slice code.
public protocol Communicator: Swift.AnyObject {
    /// Destroy the communicator. This operation calls shutdown implicitly. Calling destroy cleans up
    /// memory, and shuts down this communicator's client functionality and destroys all object adapters. Subsequent
    /// calls to destroy are ignored.
    func destroy()

    /// Shuts down this communicator's server functionality, which includes the deactivation of all object adapters.
    /// Attempts to use a deactivated object adapter raise ObjectAdapterDeactivatedException. Subsequent calls to
    /// shutdown are ignored.
    /// After shutdown returns, no new requests are processed. However, requests that have been started before shutdown
    /// was called might still be active. You can use waitForShutdown to wait for the completion of all
    /// requests.
    func shutdown()

    /// Wait until the application has called shutdown (or destroy). On the server side, this
    /// operation blocks the calling thread until all currently-executing operations have completed. On the client
    /// side, the operation simply blocks until another thread has called shutdown or destroy.
    /// A typical use of this operation is to call it from the main thread, which then waits until some other thread
    /// calls shutdown. After shut-down is complete, the main thread returns and can do some cleanup work
    /// before it finally calls destroy to shut down the client functionality, and then exits the application.
    func waitForShutdown()

    /// Check whether communicator has been shut down.
    ///
    /// - returns: `Swift.Bool` - True if the communicator has been shut down; false otherwise.
    func isShutdown() -> Swift.Bool

    /// Convert a stringified proxy into a proxy.
    /// For example, MyCategory/MyObject:tcp -h some_host -p 10000 creates a proxy that refers to the Ice
    /// object having an identity with a name "MyObject" and a category "MyCategory", with the server running on host
    /// "some_host", port 10000. If the stringified proxy does not parse correctly, the operation throws one of
    /// ProxyParseException, EndpointParseException, or IdentityParseException. Refer to the Ice manual for a detailed
    /// description of the syntax supported by stringified proxies.
    ///
    /// - parameter _: `Swift.String` The stringified proxy to convert into a proxy.
    ///
    /// - returns: `ObjectPrx?` - The proxy, or nil if str is an empty string.
    func stringToProxy(_ str: Swift.String) throws -> ObjectPrx?

    /// Convert a proxy into a string.
    ///
    /// - parameter _: `ObjectPrx?` The proxy to convert into a stringified proxy.
    ///
    /// - returns: `Swift.String` - The stringified proxy, or an empty string if
    /// obj is nil.
    func proxyToString(_ obj: ObjectPrx?) -> Swift.String

    /// Convert a set of proxy properties into a proxy. The "base" name supplied in the property argument
    /// refers to a property containing a stringified proxy, such as MyProxy=id:tcp -h localhost -p 10000.
    /// Additional properties configure local settings for the proxy, such as MyProxy.PreferSecure=1. The
    /// "Properties" appendix in the Ice manual describes each of the supported proxy properties.
    ///
    /// - parameter _: `Swift.String` The base property name.
    ///
    /// - returns: `ObjectPrx?` - The proxy.
    func propertyToProxy(_ property: Swift.String) throws -> ObjectPrx?

    /// Convert a proxy to a set of proxy properties.
    ///
    /// - parameter proxy: `ObjectPrx` The proxy.
    ///
    /// - parameter property: `Swift.String` The base property name.
    ///
    /// - returns: `PropertyDict` - The property set.
    func proxyToProperty(proxy: ObjectPrx, property: Swift.String) -> PropertyDict

    /// Convert an identity into a string.
    ///
    /// - parameter _: `Identity` The identity to convert into a string.
    ///
    /// - returns: `Swift.String` - The "stringified" identity.
    func identityToString(_ ident: Identity) -> Swift.String

    /// Create a new object adapter. The endpoints for the object adapter are taken from the property
    /// name.Endpoints.
    /// It is legal to create an object adapter with the empty string as its name. Such an object adapter is accessible
    /// via bidirectional connections or by collocated invocations that originate from the same communicator as is used
    /// by the adapter. Attempts to create a named object adapter for which no configuration can be found raise
    /// InitializationException.
    ///
    /// - parameter _: `Swift.String` The object adapter name.
    ///
    /// - returns: `ObjectAdapter` - The new object adapter.
    func createObjectAdapter(_ name: Swift.String) throws -> ObjectAdapter

    /// Create a new object adapter with endpoints. This operation sets the property
    /// name.Endpoints, and then calls createObjectAdapter. It is provided as a
    /// convenience function. Calling this operation with an empty name will result in a UUID being generated for the
    /// name.
    ///
    /// - parameter name: `Swift.String` The object adapter name.
    ///
    /// - parameter endpoints: `Swift.String` The endpoints for the object adapter.
    ///
    /// - returns: `ObjectAdapter` - The new object adapter.
    func createObjectAdapterWithEndpoints(name: Swift.String, endpoints: Swift.String) throws
        -> ObjectAdapter

    /// Create a new object adapter with a router. This operation creates a routed object adapter.
    /// Calling this operation with an empty name will result in a UUID being generated for the name.
    ///
    /// - parameter name: `Swift.String` The object adapter name.
    ///
    /// - parameter rtr: `RouterPrx` The router.
    ///
    /// - returns: `ObjectAdapter` - The new object adapter.
    func createObjectAdapterWithRouter(name: Swift.String, rtr: RouterPrx) throws -> ObjectAdapter

    /// Get the implicit context associated with this communicator.
    ///
    /// - returns: `ImplicitContext` - The implicit context associated with this communicator; returns null when the
    ///                                 property Ice.ImplicitContext
    /// is not set or is set to None.
    func getImplicitContext() -> ImplicitContext

    /// Get the properties for this communicator.
    ///
    /// - returns: `Properties` - This communicator's properties.
    func getProperties() -> Properties

    /// Get the logger for this communicator.
    ///
    /// - returns: `Logger` - This communicator's logger.
    func getLogger() -> Logger

    /// Get the default router for this communicator.
    ///
    /// - returns: `RouterPrx?` - The default router for this communicator.
    func getDefaultRouter() -> RouterPrx?

    /// Set a default router for this communicator. All newly created proxies will use this default router. To disable
    /// the default router, null can be used. Note that this operation has no effect on existing proxies.
    /// You can also set a router for an individual proxy by calling the operation ice_router on the
    /// proxy.
    ///
    /// - parameter _: `RouterPrx?` The default router to use for this communicator.
    func setDefaultRouter(_ rtr: RouterPrx?)

    /// Get the default locator for this communicator.
    ///
    /// - returns: `LocatorPrx?` - The default locator for this communicator.
    func getDefaultLocator() -> LocatorPrx?

    /// Set a default Ice locator for this communicator. All newly created proxy and object adapters will use this
    /// default locator. To disable the default locator, null can be used. Note that this operation has no effect on
    /// existing proxies or object adapters.
    /// You can also set a locator for an individual proxy by calling the operation ice_locator on the
    /// proxy, or for an object adapter by calling ObjectAdapter.setLocator on the object adapter.
    ///
    /// - parameter _: `LocatorPrx?` The default locator to use for this communicator.
    func setDefaultLocator(_ loc: LocatorPrx?)

    /// Get the value factory manager for this communicator.
    ///
    /// - returns: `ValueFactoryManager` - This communicator's value factory manager.
    func getValueFactoryManager() -> ValueFactoryManager

    /// Flush any pending batch requests for this communicator. This means all batch requests invoked on fixed proxies
    /// for all connections associated with the communicator. Any errors that occur while flushing a connection are
    /// ignored.
    ///
    /// - parameter _: `CompressBatch` Specifies whether or not the queued batch requests should be compressed before
    /// being sent over the wire.
    func flushBatchRequests(_ compress: CompressBatch) throws

    /// Flush any pending batch requests for this communicator. This means all batch requests invoked on fixed proxies
    /// for all connections associated with the communicator. Any errors that occur while flushing a connection are
    /// ignored.
    ///
    /// - parameter _: `CompressBatch` Specifies whether or not the queued batch requests should be compressed before
    /// being sent over the wire.
    ///
    /// - parameter sentOn: `Dispatch.DispatchQueue?` - Optional dispatch queue used to
    ///   dispatch the sent callback.
    ///
    /// - parameter sentFlags: `Dispatch.DispatchWorkItemFlags?` - Optional dispatch flags used
    ///   to dispatch the sent callback
    ///
    /// - parameter sent: `((Swift.Bool) -> Swift.Void)` - Optional sent callback.
    ///
    /// - returns: `PromiseKit.Promise<>` - The result of the operation
    func flushBatchRequestsAsync(
        _ compress: CompressBatch,
        sentOn: Dispatch.DispatchQueue?,
        sentFlags: Dispatch.DispatchWorkItemFlags?,
        sent: ((Swift.Bool) -> Swift.Void)?
    ) -> PromiseKit.Promise<Swift.Void>

    /// Add the Admin object with all its facets to the provided object adapter. If Ice.Admin.ServerId is
    /// set and the provided object adapter has a Locator, createAdmin registers the Admin's Process facet with
    /// the Locator's LocatorRegistry. createAdmin must only be called once; subsequent calls raise
    /// InitializationException.
    ///
    /// - parameter adminAdapter: `ObjectAdapter?` The object adapter used to host the Admin object; if null and
    /// Ice.Admin.Endpoints is set, create, activate and use the Ice.Admin object adapter.
    ///
    /// - parameter adminId: `Identity` The identity of the Admin object.
    ///
    /// - returns: `ObjectPrx` - A proxy to the main ("") facet of the Admin object. Never returns a null proxy.
    func createAdmin(adminAdapter: ObjectAdapter?, adminId: Identity) throws -> ObjectPrx

    /// Get a proxy to the main facet of the Admin object. getAdmin also creates the Admin object and creates and
    /// activates the Ice.Admin object adapter to host this Admin object if Ice.Admin.Enpoints is set. The identity of
    /// the Admin object created by getAdmin is {value of Ice.Admin.InstanceName}/admin, or {UUID}/admin when
    /// Ice.Admin.InstanceName is not set. If Ice.Admin.DelayCreation is 0 or not set, getAdmin is called
    /// by the communicator initialization, after initialization of all plugins.
    ///
    /// - returns: `ObjectPrx?` - A proxy to the main ("") facet of the Admin object, or a null proxy if no Admin
    /// object is configured.
    func getAdmin() throws -> ObjectPrx?

    /// Add a new facet to the Admin object. Adding a servant with a facet that is already registered throws
    /// AlreadyRegisteredException.
    ///
    /// - parameter servant: `Disp` The servant that implements the new Admin facet.
    ///
    /// - parameter facet: `Swift.String` The name of the new Admin facet.
    func addAdminFacet(servant: Disp, facet: Swift.String) throws

    /// Remove the following facet to the Admin object. Removing a facet that was not previously registered throws
    /// NotRegisteredException.
    ///
    /// - parameter _: `Swift.String` The name of the Admin facet.
    ///
    /// - returns: `Disp` - The servant associated with this Admin facet.
    @discardableResult
    func removeAdminFacet(_ facet: Swift.String) throws -> Disp

    /// Returns a facet of the Admin object.
    ///
    /// - parameter _: `Swift.String` The name of the Admin facet.
    ///
    /// - returns: `Disp?` - The servant associated with this Admin facet, or null if no facet is registered with the
    /// given name.
    func findAdminFacet(_ facet: Swift.String) -> Disp?

    /// Returns a map of all facets of the Admin object.
    ///
    /// - returns: `FacetMap` - A collection containing all the facet names and servants of the Admin object.
    func findAllAdminFacets() -> FacetMap

    /// Returns the client dispatch queue.
    ///
    /// - returns: `Dispatch.DispatchQueue` - The dispatch queue associated wih this Communicator's client thread pool.
    func getClientDispatchQueue() throws -> Dispatch.DispatchQueue

    /// Returns the server dispatch queue.
    ///
    /// - returns: `Dispatch.DispatchQueue` - The dispatch queue associated wih the Communicator's server thread pool.
    func getServerDispatchQueue() throws -> Dispatch.DispatchQueue
}
