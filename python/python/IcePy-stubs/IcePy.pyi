import Ice
from _typeshed import Incomplete
from typing import Any, Callable

class AsyncInvocationContext:
    """IcePy.AsyncInvocationContext"""
    @classmethod
    def __init__(cls, *args, **kwargs) -> None:
        """Create and return a new object.  See help(type) for accurate signature."""
    def cancel(self) -> None:
        """cancel() -> None"""

class BatchRequest:
    """Represents a batch request. A batch request is created by invoking an operation on a batch-oneway or
    batch-datagram proxy."""
    @classmethod
    def __init__(cls, *args, **kwargs) -> None:
        """Create and return a new object.  See help(type) for accurate signature."""
    def enqueue(self) -> None:
        """enqueue() -> None

        Queues this request."""
    def getOperation(self) -> str:
        """getOperation() -> str

        Gets the name of the operation.

        Returns
        -------
        str
            The operation name."""
    def getProxy(self) -> Ice.ObjectPrx:
        """getProxy() -> Ice.ObjectPrx

        Gets the proxy used to create this batch request.

        Returns
        -------
        Ice.ObjectPrx
            The proxy."""
    def getSize(self) -> int:
        """getSize() -> int

        Gets the size of the request.

        Returns
        -------
        int
            The number of bytes consumed by the request."""

class Communicator:
    """IcePy.Communicator"""
    def __init__(self, *args, **kwargs) -> None:
        """Initialize self.  See help(type(self)) for accurate signature."""
    def addAdminFacet(self, servant: Ice.Object | None, facet: str) -> None:
        """addAdminFacet(servant: Ice.Object | None, facet: str) -> None"""
    def createAdmin(self, adminAdapter: Ice.ObjectAdapter | None, adminIdentity: Ice.Identity) -> Ice.ObjectPrx:
        """createAdmin(adminAdapter: Ice.ObjectAdapter | None, adminIdentity: Ice.Identity) -> Ice.ObjectPrx"""
    def createObjectAdapter(self, name: str) -> ObjectAdapter:
        """createObjectAdapter(name: str) -> ObjectAdapter"""
    def createObjectAdapterWithEndpoints(self, name: str, endpoints: str) -> ObjectAdapter:
        """createObjectAdapterWithEndpoints(name: str, endpoints: str) -> ObjectAdapter"""
    def createObjectAdapterWithRouter(self, name: str, router: Ice.RouterPrx) -> ObjectAdapter:
        """createObjectAdapterWithRouter(name: str, router: Ice.RouterPrx) -> ObjectAdapter"""
    def destroy(self) -> None:
        """destroy() -> None"""
    def destroyAsync(self, callable: Callable) -> None:
        """destroyAsync(callable: Callable) -> None"""
    def findAdminFacet(self, facet: str) -> Ice.Object:
        """findAdminFacet(facet: str) -> Ice.Object"""
    def findAllAdminFacets(self) -> dict:
        """findAllAdminFacets() -> dict"""
    def flushBatchRequests(self, compress: Ice.CompressBatch) -> None:
        """flushBatchRequests(compress: Ice.CompressBatch) -> None"""
    def flushBatchRequestsAsync(self, compress: Ice.CompressBatch) -> Awaitable[None]:
        """flushBatchRequestsAsync(compress: Ice.CompressBatch) -> Awaitable[None]"""
    def getAdmin(self) -> Ice.ObjectPrx | None:
        """getAdmin() -> Ice.ObjectPrx | None"""
    def getDefaultLocator(self) -> Ice.LocatorPrx | None:
        """getDefaultLocator() -> Ice.LocatorPrx | None"""
    def getDefaultObjectAdapter(self) -> Ice.ObjectAdapter | None:
        """getDefaultObjectAdapter() -> Ice.ObjectAdapter | None"""
    def getDefaultRouter(self) -> Ice.RouterPrx | None:
        """getDefaultRouter() -> Ice.RouterPrx | None"""
    def getImplicitContext(self) -> ImplicitContext | None:
        """getImplicitContext() -> ImplicitContext | None"""
    def getLogger(self) -> Ice.Logger | Logger:
        """getLogger() -> Ice.Logger | Logger"""
    def getProperties(self) -> Properties:
        """getProperties() -> Properties"""
    def identityToString(self, identity: Ice.Identity) -> str:
        """identityToString(identity: Ice.Identity) -> str"""
    def isShutdown(self) -> bool:
        """isShutdown() -> bool"""
    def propertyToProxy(self, property: str) -> Ice.ObjectPrx:
        """propertyToProxy(property: str) -> Ice.ObjectPrx"""
    def proxyToProperty(self, proxy: Ice.ObjectPrx, property: str) -> dict[str, str]:
        """proxyToProperty(proxy: Ice.ObjectPrx, property: str) -> dict[str, str]"""
    def proxyToString(self, proxy: Ice.ObjectPrx | None) -> str:
        """proxyToString(proxy: Ice.ObjectPrx | None) -> str"""
    def removeAdminFacet(self, facet: str) -> Ice.Object:
        """removeAdminFacet(facet: str) -> Ice.Object"""
    def setDefaultLocator(self, locator: Ice.LocatorPrx | None) -> None:
        """setDefaultLocator(locator: Ice.LocatorPrx | None) -> None"""
    def setDefaultObjectAdapter(self, adapter: Ice.ObjectAdapter | None) -> None:
        """setDefaultObjectAdapter(adapter: Ice.ObjectAdapter | None) -> None"""
    def setDefaultRouter(self, router: Ice.RouterPrx | None) -> None:
        """setDefaultRouter(router: Ice.RouterPrx | None) -> None"""
    def shutdown(self) -> None:
        """shutdown() -> None"""
    def shutdownCompleted(self) -> Ice.Future:
        """shutdownCompleted() -> Ice.Future"""
    def stringToProxy(self, str: str) -> Ice.ObjectPrx:
        """stringToProxy(str: str) -> Ice.ObjectPrx"""
    def waitForShutdown(self, timeout: int) -> bool:
        """waitForShutdown(timeout: int) -> bool"""

class Connection:
    """Represents a connection that uses the Ice protocol."""
    @classmethod
    def __init__(cls, *args, **kwargs) -> None:
        """Create and return a new object.  See help(type) for accurate signature."""
    def abort(self) -> None:
        """abort() -> None

        Aborts this connection."""
    def close(self) -> Awaitable[None]:
        """close() -> Awaitable[None]

        Starts a graceful closure of this connection once all outstanding invocations have completed.

        Returns
        -------
        Awaitable[None]
            A future that becomes available when the connection is closed."""
    def createProxy(self, identity: Ice.Identity) -> Ice.ObjectPrx:
        """createProxy(identity: Ice.Identity) -> Ice.ObjectPrx

        Creates a special proxy (a 'fixed proxy') that always uses this connection.

        Parameters
        ----------
        identity : Ice.Identity
            The identity of the target object.

        Returns
        -------
        Ice.ObjectPrx
            A fixed proxy with the provided identity."""
    def disableInactivityCheck(self) -> None:
        """disableInactivityCheck() -> None

        Disables the inactivity check on this connection.

        By default, Ice will close connections that remain inactive for a certain period.
        This function disables that behavior for this connection."""
    def flushBatchRequests(self, compress: Ice.CompressBatch) -> None:
        """flushBatchRequests(compress: Ice.CompressBatch) -> None

        Flushes any pending batch requests for this connection.

        This corresponds to all batch requests invoked on fixed proxies associated with the connection.

        Parameters
        ----------
        compress : Ice.CompressBatch
            Specifies whether or not the queued batch requests should be compressed before being sent over the wire."""
    def flushBatchRequestsAsync(self, compress: Ice.CompressBatch) -> Awaitable[None]:
        """flushBatchRequestsAsync(compress: Ice.CompressBatch) -> Awaitable[None]

        Flushes any pending batch requests for this connection asynchronously.

        This corresponds to all batch requests invoked on fixed proxies associated with the connection.

        Parameters
        ----------
        compress : Ice.CompressBatch
            Specifies whether or not the queued batch requests should be compressed before being sent over the wire.

        Returns
        -------
        Awaitable[None]
            A future that becomes available when the flush completes."""
    def getAdapter(self) -> Ice.ObjectAdapter | None:
        """getAdapter() -> Ice.ObjectAdapter | None

        Gets the object adapter associated with this connection.

        Returns
        -------
        Ice.ObjectAdapter | None
            The object adapter associated with this connection."""
    def getEndpoint(self) -> Endpoint:
        """getEndpoint() -> Endpoint

        Gets the endpoint from which the connection was created.

        Returns
        -------
        Ice.Endpoint
            The endpoint from which the connection was created."""
    def getInfo(self) -> Ice.ConnectionInfo:
        """getInfo() -> Ice.ConnectionInfo

        Returns the connection information.

        Returns
        -------
        Ice.ConnectionInfo
            The connection information."""
    def setAdapter(self, adapter: Ice.ObjectAdapter | None) -> None:
        """setAdapter(adapter: Ice.ObjectAdapter | None) -> None

        Associates an object adapter with this connection.

        When a connection receives a request, it dispatches this request using its associated object adapter.
        If the associated object adapter is ``None``, the connection rejects any incoming request with an
        :class:`ObjectNotExistException`.

        The default object adapter of an incoming connection is the object adapter that created this connection;
        the default object adapter of an outgoing connection is the communicator's default object adapter.

        Parameters
        ----------
        adapter : Ice.ObjectAdapter | None
            The object adapter to associate with this connection."""
    def setBufferSize(self, rcvSize: int, sndSize: int) -> None:
        """setBufferSize(rcvSize: int, sndSize: int) -> None

        Sets the size of the receive and send buffers.

        Parameters
        ----------
        rcvSize : int
            The size of the receive buffer.
        sndSize : int
            The size of the send buffer."""
    def setCloseCallback(self, callback: Callable[[Connection], None]) -> None:
        """setCloseCallback(callback: Callable[[Connection], None]) -> None

        Sets a close callback on the connection. The callback is called by the connection when it's closed.
        The callback is called from the Ice thread pool associated with the connection.

        Parameters
        ----------
        callback : Callable[[Connection], None]
            The close callback callable."""
    def throwException(self) -> None:
        """throwException() -> None

        Raises an exception that provides the reason for the closure of this connection. For example,
        this function raises :class:`CloseConnectionException` when the connection was closed gracefully by the peer;
        it raises :class:`ConnectionAbortedException` when the connection is aborted with :func:`abort`.
        This function does nothing if the connection is not yet closed."""
    def toString(self) -> str:
        """toString() -> str

        Returns a description of the connection as human readable text, suitable for logging or error messages.

        Notes
        -----
        This function remains usable after the connection is closed or aborted.

        Returns
        -------
        str
            The description of the connection as human readable text."""
    def type(self) -> str:
        """type() -> str

        Returns the connection type. This corresponds to the endpoint type, such as 'tcp', 'udp', etc.

        Returns
        -------
        str
            The type of the connection."""
    def __eq__(self, other: object) -> bool:
        """Return self==value."""
    def __ge__(self, other: object) -> bool:
        """Return self>=value."""
    def __gt__(self, other: object) -> bool:
        """Return self>value."""
    def __hash__(self) -> int:
        """Return hash(self)."""
    def __le__(self, other: object) -> bool:
        """Return self<=value."""
    def __lt__(self, other: object) -> bool:
        """Return self<value."""
    def __ne__(self, other: object) -> bool:
        """Return self!=value."""

class ConnectionInfo:
    """Base class for all connection info classes."""
    adapterName: str
    incoming: bool
    underlying: Incomplete
    @classmethod
    def __init__(cls, *args, **kwargs) -> None:
        """Create and return a new object.  See help(type) for accurate signature."""

class DispatchCallback:
    """IcePy.DispatchCallback"""
    @classmethod
    def __init__(cls, *args, **kwargs) -> None:
        """Create and return a new object.  See help(type) for accurate signature."""
    def exception(self, exception: BaseException) -> None:
        """exception(exception: BaseException) -> None"""
    def response(self, *args: tuple) -> None:
        """response(*args: tuple) -> None"""

class Endpoint:
    """An endpoint specifies the address of the server-end of an Ice connection.
    An object adapter listens on one or more endpoints and a client establishes a connection to an endpoint."""
    @classmethod
    def __init__(cls, *args, **kwargs) -> None:
        """Create and return a new object.  See help(type) for accurate signature."""
    def getInfo(self) -> Ice.EndpointInfo:
        """getInfo() -> Ice.EndpointInfo

        Returns this endpoint's information.

        Returns
        -------
        Ice.EndpointInfo
            This endpoint's information class."""
    def toString(self) -> str:
        """toString() -> str

        Returns a string representation of this endpoint.

        Returns
        -------
        str
            The string representation of this endpoint."""
    def __eq__(self, other: object) -> bool:
        """Return self==value."""
    def __ge__(self, other: object) -> bool:
        """Return self>=value."""
    def __gt__(self, other: object) -> bool:
        """Return self>value."""
    def __le__(self, other: object) -> bool:
        """Return self<=value."""
    def __lt__(self, other: object) -> bool:
        """Return self<value."""
    def __ne__(self, other: object) -> bool:
        """Return self!=value."""

class EndpointInfo:
    """Base class for the endpoint info classes."""
    compress: bool
    underlying: Incomplete
    @classmethod
    def __init__(cls, *args, **kwargs) -> None:
        """Create and return a new object.  See help(type) for accurate signature."""
    def datagram(self) -> bool:
        """datagram() -> bool

        Returns whether this endpoint is a datagram endpoint (namely, UDP).

        Returns
        -------
        bool
            ``True`` for a UDP endpoint, ``False`` otherwise."""
    def secure(self) -> bool:
        """secure() -> bool

        Returns whether this endpoint uses SSL.

        Returns
        -------
        bool
            ``True`` for SSL and SSL-based transports, ``False`` otherwise."""
    def type(self) -> int:
        """type() -> int

        Returns the type of the endpoint.

        Returns
        -------
        int
            The endpoint type."""

class ExceptionInfo:
    """IcePy.ExceptionInfo"""
    @classmethod
    def __init__(cls, *args, **kwargs) -> None:
        """Create and return a new object.  See help(type) for accurate signature."""

class ExecutorCall:
    def __call__(self, *args, **kwargs):
        """Call self as a function."""

class IPConnectionInfo(ConnectionInfo):
    """Provides access to the connection details of an IP connection."""
    localAddress: str
    localPort: int
    remoteAddress: str
    remotePort: int
    @classmethod
    def __init__(cls, *args, **kwargs) -> None:
        """Create and return a new object.  See help(type) for accurate signature."""

class IPEndpointInfo(EndpointInfo):
    """Provides access to the address details of an IP endpoint."""
    host: str
    port: int
    sourceAddress: str
    @classmethod
    def __init__(cls, *args, **kwargs) -> None:
        """Create and return a new object.  See help(type) for accurate signature."""

class ImplicitContext:
    """IcePy.ImplicitContext"""
    @classmethod
    def __init__(cls, *args, **kwargs) -> None:
        """Create and return a new object.  See help(type) for accurate signature."""
    def containsKey(self, key: str) -> bool:
        """containsKey(key: str) -> bool"""
    def get(self, key: str) -> str:
        """get(key: str) -> str"""
    def getContext(self) -> dict[str, str]:
        """getContext() -> dict[str, str]"""
    def put(self, key: str, value: str) -> str | None:
        """put(key: str, value: str) -> str | None"""
    def remove(self, key: str) -> str | None:
        """remove(key: str) -> str | None"""
    def setContext(self, newContext: dict[str, str]) -> None:
        """setContext(newContext: dict[str, str]) -> None"""
    def __eq__(self, other: object) -> bool:
        """Return self==value."""
    def __ge__(self, other: object) -> bool:
        """Return self>=value."""
    def __gt__(self, other: object) -> bool:
        """Return self>value."""
    def __le__(self, other: object) -> bool:
        """Return self<=value."""
    def __lt__(self, other: object) -> bool:
        """Return self<value."""
    def __ne__(self, other: object) -> bool:
        """Return self!=value."""

class Logger:
    """IcePy.Logger"""
    @classmethod
    def __init__(cls, *args, **kwargs) -> None:
        """Create and return a new object.  See help(type) for accurate signature."""
    def cloneWithPrefix(self, prefix: str) -> Logger:
        """cloneWithPrefix(prefix: str) -> Logger"""
    def error(self, message: str) -> None:
        """error(message: str) -> None"""
    def getPrefix(self) -> str:
        """getPrefix() -> str"""
    def print(self, message: str) -> None:
        """print(message: str) -> None"""
    def trace(self, category: str, message: str) -> None:
        """trace(category: str, message: str) -> None"""
    def warning(self, message: str) -> None:
        """warning(message: str) -> None"""

class NativePropertiesAdmin:
    """The default implementation of the 'Properties' admin facet."""
    @classmethod
    def __init__(cls, *args, **kwargs) -> None:
        """Create and return a new object.  See help(type) for accurate signature."""
    def addUpdateCallback(self, callback: Callable[[dict[str, str]], None]) -> None:
        """addUpdateCallback(callback: Callable[[dict[str, str]], None]) -> None

        Registers an update callback that will be invoked when a property update occurs.

        Parameters
        ----------
        callback : Callable[[dict[str, str]], None]
            The callback."""
    def removeUpdateCallback(self, callback: Callable[[dict[str, str]], None]) -> None:
        """removeUpdateCallback(callback: Callable[[dict[str, str]], None]) -> None

        Removes a previously registered update callback.

        Parameters
        ----------
        callback : Callable[[dict[str, str]], None]
            The callback to remove."""

class ObjectAdapter:
    """IcePy.ObjectAdapter"""
    @classmethod
    def __init__(cls, *args, **kwargs) -> None:
        """Create and return a new object.  See help(type) for accurate signature."""
    def activate(self) -> None:
        """activate() -> None"""
    def add(self, servant: Ice.Object, id: Ice.Identity) -> Ice.ObjectPrx:
        """add(servant: Ice.Object, id: Ice.Identity) -> Ice.ObjectPrx"""
    def addDefaultServant(self, servant: Ice.Object, category: str) -> None:
        """addDefaultServant(servant: Ice.Object, category: str) -> None"""
    def addFacet(self, servant: Ice.Object, id: Ice.Identity, facet: str) -> Ice.ObjectPrx:
        """addFacet(servant: Ice.Object, id: Ice.Identity, facet: str) -> Ice.ObjectPrx"""
    def addFacetWithUUID(self, servant: Ice.Object, facet: str) -> Ice.ObjectPrx:
        """addFacetWithUUID(servant: Ice.Object, facet: str) -> Ice.ObjectPrx"""
    def addServantLocator(self, locator: Ice.ServantLocator, category: str) -> None:
        """addServantLocator(locator: Ice.ServantLocator, category: str) -> None"""
    def addWithUUID(self, servant: Ice.Object) -> Ice.ObjectPrx:
        """addWithUUID(servant: Ice.Object) -> Ice.ObjectPrx"""
    def createDirectProxy(self, identity: Ice.Identity) -> Ice.ObjectPrx:
        """createDirectProxy(identity: Ice.Identity) -> Ice.ObjectPrx"""
    def createIndirectProxy(self, identity: Ice.Identity) -> Ice.ObjectPrx:
        """createIndirectProxy(identity: Ice.Identity) -> Ice.ObjectPrx"""
    def createProxy(self, identity: Ice.Identity) -> Ice.ObjectPrx:
        """createProxy(identity: Ice.Identity) -> Ice.ObjectPrx"""
    def deactivate(self) -> None:
        """deactivate() -> None"""
    def destroy(self) -> None:
        """destroy() -> None"""
    def find(self, identity: Ice.Identity) -> Ice.Object | None:
        """find(identity: Ice.Identity) -> Ice.Object | None"""
    def findAllFacets(self, id: Ice.Identity) -> dict[str, Ice.Object]:
        """findAllFacets(id: Ice.Identity) -> dict[str, Ice.Object]"""
    def findByProxy(self, proxy: Ice.ObjectPrx) -> Ice.Object | None:
        """findByProxy(proxy: Ice.ObjectPrx) -> Ice.Object | None"""
    def findDefaultServant(self, category: str) -> Ice.Object:
        """findDefaultServant(category: str) -> Ice.Object"""
    def findFacet(self, id: Ice.Identity, facet: str) -> Ice.Object | None:
        """findFacet(id: Ice.Identity, facet: str) -> Ice.Object | None"""
    def findServantLocator(self, category: str) -> Ice.ServantLocator:
        """findServantLocator(category: str) -> Ice.ServantLocator"""
    def getCommunicator(self) -> Communicator:
        """getCommunicator() -> Communicator"""
    def getEndpoints(self) -> None:
        """getEndpoints() -> None"""
    def getLocator(self) -> Ice.LocatorPrx:
        """getLocator() -> Ice.LocatorPrx"""
    def getName(self) -> str:
        """getName() -> str"""
    def getPublishedEndpoints(self) -> None:
        """getPublishedEndpoints() -> None"""
    def hold(self) -> None:
        """hold() -> None"""
    def isDeactivated(self) -> bool:
        """isDeactivated() -> bool"""
    def remove(self, id: Ice.Identity) -> Ice.Object:
        """remove(id: Ice.Identity) -> Ice.Object"""
    def removeAllFacets(self, id: Ice.Identity) -> dict[str, Ice.Object]:
        """removeAllFacets(id: Ice.Identity) -> dict[str, Ice.Object]"""
    def removeDefaultServant(self, category: str) -> Ice.Object:
        """removeDefaultServant(category: str) -> Ice.Object"""
    def removeFacet(self, id: Ice.Identity, facet: str) -> Ice.Object:
        """removeFacet(id: Ice.Identity, facet: str) -> Ice.Object"""
    def removeServantLocator(self, category: str) -> Ice.ServantLocator:
        """removeServantLocator(category: str) -> Ice.ServantLocator"""
    def setLocator(self, locator: Ice.LocatorPrx) -> None:
        """setLocator(locator: Ice.LocatorPrx) -> None"""
    def setPublishedEndpoints(self, newEndpoints: tuple[Endpoint, ...] | list[Endpoint]) -> None:
        """setPublishedEndpoints(newEndpoints: tuple[Endpoint, ...] | list[Endpoint]) -> None"""
    def waitForDeactivate(self, timeout: int) -> bool:
        """waitForDeactivate(timeout: int) -> bool"""
    def waitForHold(self, timeout: int) -> None:
        """waitForHold(timeout: int) -> None"""

class ObjectPrx:
    """IcePy.ObjectPrx"""
    def __init__(self, *args, **kwargs) -> None:
        """Initialize self.  See help(type(self)) for accurate signature."""
    def ice_adapterId(self, id: str) -> Ice.ObjectPrx:
        """ice_adapterId(id: str) -> Ice.ObjectPrx"""
    def ice_batchDatagram(self) -> Ice.ObjectPrx:
        """ice_batchDatagram() -> Ice.ObjectPrx"""
    def ice_batchOneway(self) -> Ice.ObjectPrx:
        """ice_batchOneway() -> Ice.ObjectPrx"""
    def ice_collocationOptimized(self, collocated: bool) -> Ice.ObjectPrx:
        """ice_collocationOptimized(collocated: bool) -> Ice.ObjectPrx"""
    def ice_compress(self, compress: bool) -> Ice.ObjectPrx:
        """ice_compress(compress: bool) -> Ice.ObjectPrx"""
    def ice_connectionCached(self, newCache: bool) -> Ice.ObjectPrx:
        """ice_connectionCached(newCache: bool) -> Ice.ObjectPrx"""
    def ice_connectionId(self, connectionId: str) -> Ice.ObjectPrx:
        """ice_connectionId(connectionId: str) -> Ice.ObjectPrx"""
    def ice_context(self, new_context: dict[str, str]) -> Ice.ObjectPrx:
        """ice_context(new_context: dict[str, str]) -> Ice.ObjectPrx"""
    def ice_datagram(self) -> Ice.ObjectPrx:
        """ice_datagram() -> Ice.ObjectPrx"""
    def ice_encodingVersion(self, version: Ice.EncodingVersion) -> Ice.ObjectPrx:
        """ice_encodingVersion(version: Ice.EncodingVersion) -> Ice.ObjectPrx"""
    def ice_endpointSelection(self, type: Ice.EndpointSelectionType) -> Ice.ObjectPrx:
        """ice_endpointSelection(type: Ice.EndpointSelectionType) -> Ice.ObjectPrx"""
    def ice_endpoints(self, newEndpoints: tuple[Endpoint, ...] | list[Endpoint]) -> Ice.ObjectPrx:
        """ice_endpoints(newEndpoints: tuple[Endpoint, ...] | list[Endpoint]) -> Ice.ObjectPrx"""
    def ice_facet(self, facet: str) -> Ice.ObjectPrx:
        """ice_facet(facet: str) -> Ice.ObjectPrx"""
    def ice_fixed(self, connection: Ice.Connection) -> Ice.ObjectPrx:
        """ice_fixed(connection: Ice.Connection) -> Ice.ObjectPrx"""
    def ice_flushBatchRequests(self) -> None:
        """ice_flushBatchRequests() -> None"""
    def ice_flushBatchRequestsAsync(self) -> Ice.Future:
        """ice_flushBatchRequestsAsync() -> Ice.Future"""
    def ice_getAdapterId(self) -> str:
        """ice_getAdapterId() -> str"""
    def ice_getCachedConnection(self) -> Ice.Connection:
        """ice_getCachedConnection() -> Ice.Connection"""
    def ice_getCommunicator(self) -> Ice.Communicator:
        """ice_getCommunicator() -> Ice.Communicator"""
    def ice_getCompress(self) -> bool:
        """ice_getCompress() -> bool"""
    def ice_getConnection(self) -> Ice.Connection:
        """ice_getConnection() -> Ice.Connection"""
    def ice_getConnectionAsync(self) -> Ice.Future:
        """ice_getConnectionAsync() -> Ice.Future"""
    def ice_getConnectionId(self) -> str:
        """ice_getConnectionId() -> str"""
    def ice_getContext(self) -> dict[str, str]:
        """ice_getContext() -> dict[str, str]"""
    def ice_getEncodingVersion(self) -> Ice.EncodingVersion:
        """ice_getEncodingVersion() -> Ice.EncodingVersion"""
    def ice_getEndpointSelection(self) -> bool:
        """ice_getEndpointSelection() -> bool"""
    def ice_getEndpoints(self) -> tuple[Endpoint, ...]:
        """ice_getEndpoints() -> tuple[Endpoint, ...]"""
    def ice_getFacet(self) -> str:
        """ice_getFacet() -> str"""
    def ice_getIdentity(self) -> Ice.Identity:
        """ice_getIdentity() -> Ice.Identity"""
    def ice_getInvocationTimeout(self) -> int:
        """ice_getInvocationTimeout() -> int"""
    def ice_getLocator(self) -> Ice.LocatorPrx:
        """ice_getLocator() -> Ice.LocatorPrx"""
    def ice_getLocatorCacheTimeout(self) -> int:
        """ice_getLocatorCacheTimeout() -> int"""
    def ice_getRouter(self) -> Ice.RouterPrx:
        """ice_getRouter() -> Ice.RouterPrx"""
    def ice_identity(self, id: str) -> Ice.ObjectPrx:
        """ice_identity(id: str) -> Ice.ObjectPrx"""
    def ice_invocationTimeout(self, timeout: int) -> Ice.ObjectPrx:
        """ice_invocationTimeout(timeout: int) -> Ice.ObjectPrx"""
    def ice_invoke(self, operation: str, mode: Ice.OperationMode, inParams: bytes, ctx: dict[str, str] | None) -> tuple[bool, bytes]:
        """ice_invoke(operation: str, mode: Ice.OperationMode, inParams: bytes, ctx: dict[str, str] | None) -> tuple[bool, bytes]"""
    def ice_invokeAsync(self, operation: str, mode: Ice.OperationMode, inParams: bytes, ctx: dict[str, str] | None) -> Awaitable[tuple[bool, bytes]]:
        """ice_invokeAsync(operation: str, mode: Ice.OperationMode, inParams: bytes, ctx: dict[str, str] | None) -> Awaitable[tuple[bool, bytes]]"""
    def ice_isBatchDatagram(self) -> bool:
        """ice_isBatchDatagram() -> bool"""
    def ice_isBatchOneway(self) -> bool:
        """ice_isBatchOneway() -> bool"""
    def ice_isCollocationOptimized(self) -> bool:
        """ice_isCollocationOptimized() -> bool"""
    def ice_isConnectionCached(self) -> bool:
        """ice_isConnectionCached() -> bool"""
    def ice_isDatagram(self) -> bool:
        """ice_isDatagram() -> bool"""
    def ice_isFixed(self) -> bool:
        """ice_isFixed() -> bool"""
    def ice_isOneway(self) -> bool:
        """ice_isOneway() -> bool"""
    def ice_isTwoway(self) -> bool:
        """ice_isTwoway() -> bool"""
    def ice_locator(self, locator: Ice.LocatorPrx | None) -> Ice.ObjectPrx:
        """ice_locator(locator: Ice.LocatorPrx | None) -> Ice.ObjectPrx"""
    def ice_locatorCacheTimeout(self, timeout: int) -> Ice.ObjectPrx:
        """ice_locatorCacheTimeout(timeout: int) -> Ice.ObjectPrx"""
    def ice_oneway(self) -> Ice.ObjectPrx:
        """ice_oneway() -> Ice.ObjectPrx"""
    def ice_router(self, router: Ice.RouterPrx | None) -> Ice.ObjectPrx:
        """ice_router(router: Ice.RouterPrx | None) -> Ice.ObjectPrx"""
    def ice_toString(self) -> str:
        """ice_toString() -> str"""
    def ice_twoway(self) -> Ice.ObjectPrx:
        """ice_twoway() -> Ice.ObjectPrx"""
    @staticmethod
    def newProxy(type: Type[T], proxy: Ice.ObjectPrx) -> proxy:
        """newProxy(type: Type[T], proxy: Ice.ObjectPrx) -> proxy"""
    def __eq__(self, other: object) -> bool:
        """Return self==value."""
    def __ge__(self, other: object) -> bool:
        """Return self>=value."""
    def __gt__(self, other: object) -> bool:
        """Return self>value."""
    def __hash__(self) -> int:
        """Return hash(self)."""
    def __le__(self, other: object) -> bool:
        """Return self<=value."""
    def __lt__(self, other: object) -> bool:
        """Return self<value."""
    def __ne__(self, other: object) -> bool:
        """Return self!=value."""

class OpaqueEndpointInfo(EndpointInfo):
    """Provides access to the details of an opaque endpoint."""
    rawBytes: bytes
    rawEncoding: Ice.EncodingVersion
    @classmethod
    def __init__(cls, *args, **kwargs) -> None:
        """Create and return a new object.  See help(type) for accurate signature."""

class Operation:
    """IcePy.Operation"""
    def __init__(self, *args, **kwargs) -> None:
        """Initialize self.  See help(type(self)) for accurate signature."""
    def deprecate(self, reason: str) -> Any:
        """deprecate(reason: str)"""
    def invoke(self, proxy: ObjectPrx, args: tuple) -> Any:
        """invoke(proxy: ObjectPrx, args: tuple) -> Any"""
    def invokeAsync(self, proxy: ObjectPrx, args: tuple) -> Awaitable[Any]:
        """invokeAsync(proxy: ObjectPrx, args: tuple) -> Awaitable[Any]"""

class Properties:
    """IcePy.Properties"""
    def __init__(self, *args, **kwargs) -> None:
        """Initialize self.  See help(type(self)) for accurate signature."""
    def clone(self) -> Properties:
        """clone() -> Properties"""
    def getCommandLineOptions(self) -> list[str]:
        """getCommandLineOptions() -> list[str]"""
    def getIceProperty(self, key: str) -> str:
        """getIceProperty(key: str) -> str"""
    def getIcePropertyAsInt(self, key: str) -> int:
        """getIcePropertyAsInt(key: str) -> int"""
    def getIcePropertyAsList(self, key: str) -> list[str]:
        """getIcePropertyAsList(key: str) -> list[str]"""
    def getPropertiesForPrefix(self, prefix: str) -> dict[str, str]:
        """getPropertiesForPrefix(prefix: str) -> dict[str, str]"""
    def getProperty(self, key: str) -> str:
        """getProperty(key: str) -> str"""
    def getPropertyAsInt(self, key: str) -> int:
        """getPropertyAsInt(key: str) -> int"""
    def getPropertyAsIntWithDefault(self, key: str, value: int) -> int:
        """getPropertyAsIntWithDefault(key: str, value: int) -> int"""
    def getPropertyAsList(self, key: str) -> list[str]:
        """getPropertyAsList(key: str) -> list[str]"""
    def getPropertyAsListWithDefault(self, key: str, value: list[str]) -> list[str]:
        """getPropertyAsListWithDefault(key: str, value: list[str]) -> list[str]"""
    def getPropertyWithDefault(self, key: str, value: str) -> str:
        """getPropertyWithDefault(key: str, value: str) -> str"""
    def load(self, file: str) -> None:
        """load(file: str) -> None"""
    def parseCommandLineOptions(self, prefix: str, options: list[str]) -> list[str]:
        """parseCommandLineOptions(prefix: str, options: list[str]) -> list[str]"""
    def parseIceCommandLineOptions(self, options: list[str]) -> list[str]:
        """parseIceCommandLineOptions(options: list[str]) -> list[str]"""
    def setProperty(self, key: str, value: str) -> None:
        """setProperty(key: str, value: str) -> None"""

class SSLConnectionInfo(ConnectionInfo):
    """Provides access to the connection details of an SSL connection."""
    peerCertificate: str
    @classmethod
    def __init__(cls, *args, **kwargs) -> None:
        """Create and return a new object.  See help(type) for accurate signature."""

class SSLEndpointInfo(EndpointInfo):
    """Provides access to an SSL endpoint information."""
    @classmethod
    def __init__(cls, *args, **kwargs) -> None:
        """Create and return a new object.  See help(type) for accurate signature."""

class TCPConnectionInfo(IPConnectionInfo):
    """Provides access to the connection details of a TCP connection."""
    rcvSize: int
    sndSize: int
    @classmethod
    def __init__(cls, *args, **kwargs) -> None:
        """Create and return a new object.  See help(type) for accurate signature."""

class TCPEndpointInfo(IPEndpointInfo):
    """Provides access to a TCP endpoint information."""
    @classmethod
    def __init__(cls, *args, **kwargs) -> None:
        """Create and return a new object.  See help(type) for accurate signature."""

class TypeInfo:
    """IcePy.TypeInfo"""
    @classmethod
    def __init__(cls, *args, **kwargs) -> None:
        """Create and return a new object.  See help(type) for accurate signature."""

class UDPConnectionInfo(IPConnectionInfo):
    """Provides access to the connection details of a UDP connection."""
    mcastAddress: str
    mcastPort: int
    rcvSize: int
    sndSize: int
    @classmethod
    def __init__(cls, *args, **kwargs) -> None:
        """Create and return a new object.  See help(type) for accurate signature."""

class UDPEndpointInfo(IPEndpointInfo):
    """Provides access to a UDP endpoint information."""
    mcastInterface: str
    mcastTtl: int
    @classmethod
    def __init__(cls, *args, **kwargs) -> None:
        """Create and return a new object.  See help(type) for accurate signature."""

class WSConnectionInfo(ConnectionInfo):
    """Provides access to the connection details of a WebSocket connection."""
    headers: dict[str, str]
    @classmethod
    def __init__(cls, *args, **kwargs) -> None:
        """Create and return a new object.  See help(type) for accurate signature."""

class WSEndpointInfo(EndpointInfo):
    """Provides access to a WebSocket endpoint information."""
    resource: str
    @classmethod
    def __init__(cls, *args, **kwargs) -> None:
        """Create and return a new object.  See help(type) for accurate signature."""

def compileSlice(args: list[str]) -> int:
    """compileSlice(args: list[str]) -> int

    Compiles Slice definitions. The behavior is identical to that of the `slice2py` compiler.

    Any errors or warnings emitted during compilation are printed to 'stderr'.

    This is an internal function used in the implementation of the `slice2py` Python script included in the Ice Python package.

    Parameters
    ----------
    args : list[str]
        The list of command-line arguments for Slice compilation, following the same syntax as the `slice2py` compiler.

    Returns
    -------
    int
        The exit code: 0 indicates success, and a non-zero value indicates failure."""
def createProperties(args: list[str] | None = ..., defaults: Ice.Properties | None = ...) -> Ice.Properties:
    """createProperties(args: list[str] | None = None, defaults: Ice.Properties | None = None) -> Ice.Properties

    Creates a property set initialized from command-line arguments and a default property set.

    Parameters
    ----------
    args : list[str] | None, optional
        The command-line arguments.
    defaults : Properties | None, optional
        Default values for the new property set.

    Returns
    -------
    Ice.Properties
        A new property set."""
def declareProxy(sliceId: str) -> Any:
    """declareProxy(sliceId: str)"""
def declareValue(sliceId: str) -> Any:
    """declareValue(sliceId: str)"""
def defineDictionary(sliceId: str, meta: tuple, keyType: TypeInfo, valueType: TypeInfo) -> Any:
    """defineDictionary(sliceId: str, meta: tuple, keyType: TypeInfo, valueType: TypeInfo)"""
def defineEnum(sliceId: str, type: Type, meta: tuple, enumerators: dict) -> Any:
    """defineEnum(sliceId: str, type: Type, meta: tuple, enumerators: dict)"""
def defineException(sliceId: str, type: Type[BaseException], meta: tuple, base: Type[BaseException] | None, members: tuple) -> Any:
    """defineException(sliceId: str, type: Type[BaseException], meta: tuple, base: Type[BaseException] | None, members: tuple)"""
def defineProxy(sliceId: str, proxyType: Type[ObjectPrx]) -> Any:
    """defineProxy(sliceId: str, proxyType: Type[ObjectPrx])"""
def defineSequence(sliceId: str, meta: tuple, elementType: TypeInfo) -> Any:
    """defineSequence(sliceId: str, meta: tuple, elementType: TypeInfo)"""
def defineStruct(sliceId: str, type: Type, meta: tuple, members: tuple) -> Any:
    """defineStruct(sliceId: str, type: Type, meta: tuple, members: tuple)"""
def defineValue(sliceId: str, valueType: Type[Ice.Value], compactId: int, meta: tuple, isInterface: bool, baseType: Type[Ice.Value] | None, members: tuple) -> Any:
    """defineValue(sliceId: str, valueType: Type[Ice.Value], compactId: int, meta: tuple, isInterface: bool, baseType: Type[Ice.Value] | None, members: tuple)"""
def getProcessLogger() -> Ice.Logger:
    """getProcessLogger() -> Ice.Logger

    Gets the per-process logger. This logger is used by all communicators that do not have their own specific logger
    configured at the time the communicator is created.

    Returns
    -------
    Ice.Logger
        The current per-process logger instance."""
def identityToString(identity: Ice.Identity, toStringMode: Ice.ToStringMode | None = ...) -> str:
    """identityToString(identity: Ice.Identity, toStringMode: Ice.ToStringMode | None = None) -> str

    Converts an Identity into a string using the specified mode.

    Parameters
    ----------
    identity : Ice.Identity
        The identity.
    toStringMode : Ice.ToStringMode | None, optional
        Specifies how to handle non-ASCII characters and non-printable ASCII characters.
        The default is :const:`Ice.ToStringMode.Unicode`.

    Returns
    -------
    str
        The stringified identity."""
def intVersion() -> int:
    """intVersion() -> int

    Returns the Ice version as an integer in the form ``AABBCC``, where ``AA`` indicates the major version,
    ``BB`` indicates the minor version, and ``CC`` indicates the patch level.
    For example, for Ice 3.9.1, the returned value is 30901.

    Returns
    -------
    int
        The Ice version."""
def loadSlice(args: list[str]) -> None:
    """loadSlice(args: list[str]) -> None

    Compiles Slice definitions and loads the generated code directly into the current Python environment.

    This function does not generate any Python source files. Instead, the generated Python code is loaded directly into the
    running interpreter.

    This function does not generate any code for Slice files included by the Slice files being loaded. It is the caller's
    responsibility to load all necessary Slice definitions. This can be done in a single call to :func:`loadSlice` by
    providing all Slice files (including included files) in the `args` parameter, or by making multiple calls to
    :func:`loadSlice`.

    When :func:`loadSlice` is called multiple times with the same Slice file, the corresponding Python code is not reloaded.

    Parameters
    ----------
    args : list[str]
        The list of command-line arguments for the Slice loader. These arguments may include both compiler options and
        the Slice files to compile.

        Supported compiler options:

            - ``-DNAME``:  Define NAME as 1.
            - ``-DNAME=DEF``:  Define NAME as DEF.
            - ``-UNAME``:  Remove any definition for NAME.
            - ``-IDIR``:  Put DIR in the include file search path.
            - ``-d``, ``--debug``:  Print debug messages.

    Raises
    ------
    RuntimeError
        If an error occurs during Slice parsing or compilation."""
def setProcessLogger(logger: Ice.Logger) -> None:
    """setProcessLogger(logger: Ice.Logger) -> None

    Sets the per-process logger. This logger is used by all communicators that do not have their own specific logger
    configured at the time the communicator is created.

    Parameters
    ----------
    logger : Ice.Logger
        The new per-process logger instance."""
def stringToIdentity(str: str) -> Ice.Identity:
    """stringToIdentity(str: str) -> Ice.Identity

    Converts a stringified identity into an Identity.

    Parameters
    ----------
    str : str
        The stringified identity.

    Returns
    -------
    Ice.Identity
        An Identity created from the provided string.

    Raises
    ------
    ParseException
        If the string cannot be converted to an object identity."""
def stringVersion() -> str:
    """stringVersion() -> str

    Returns the Ice version in the form ``A.B.C``, where ``A`` indicates the major version,
    ``B`` indicates the minor version, and ``C`` indicates the patch level.

    Returns
    -------
    str
        The Ice version."""
