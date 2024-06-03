//
// Copyright (c) ZeroC, Inc. All rights reserved.
//
//
// Ice version 3.7.10
//
// <auto-generated>
//
// Generated from file `ImplicitContext.ice'
//
// Warning: do not edit this file.
//
// </auto-generated>
//

import Foundation

/// An interface to associate implict contexts with communicators. When you make a remote invocation without an
/// explicit context parameter, Ice uses the per-proxy context (if any) combined with the ImplicitContext
/// associated with the communicator.
/// Ice provides several implementations of ImplicitContext. The implementation used depends on the value
/// of the Ice.ImplicitContext property.
///
/// None (default)
/// No implicit context at all.
/// PerThread
/// The implementation maintains a context per thread.
/// Shared
/// The implementation maintains a single context shared by all threads.
///
/// ImplicitContext also provides a number of operations to create, update or retrieve an entry in the
/// underlying context without first retrieving a copy of the entire context. These operations correspond to a subset
/// of the java.util.Map methods, with java.lang.Object replaced by string and
/// null replaced by the empty-string.
public protocol ImplicitContext: Swift.AnyObject {
    /// Get a copy of the underlying context.
    ///
    /// - returns: `Context` - A copy of the underlying context.
    func getContext() -> Context

    /// Set the underlying context.
    ///
    /// - parameter _: `Context` The new context.
    func setContext(_ newContext: Context)

    /// Check if this key has an associated value in the underlying context.
    ///
    /// - parameter _: `Swift.String` The key.
    ///
    /// - returns: `Swift.Bool` - True if the key has an associated value, False otherwise.
    func containsKey(_ key: Swift.String) -> Swift.Bool

    /// Get the value associated with the given key in the underlying context. Returns an empty string if no value is
    /// associated with the key. containsKey allows you to distinguish between an empty-string value and no
    /// value at all.
    ///
    /// - parameter _: `Swift.String` The key.
    ///
    /// - returns: `Swift.String` - The value associated with the key.
    func get(_ key: Swift.String) -> Swift.String

    /// Create or update a key/value entry in the underlying context.
    ///
    /// - parameter key: `Swift.String` The key.
    ///
    /// - parameter value: `Swift.String` The value.
    ///
    /// - returns: `Swift.String` - The previous value associated with the key, if any.
    func put(key: Swift.String, value: Swift.String) -> Swift.String

    /// Remove the entry for the given key in the underlying context.
    ///
    /// - parameter _: `Swift.String` The key.
    ///
    /// - returns: `Swift.String` - The value associated with the key, if any.
    func remove(_ key: Swift.String) -> Swift.String
}
