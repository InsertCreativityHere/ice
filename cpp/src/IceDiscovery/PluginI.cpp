//
// Copyright (c) ZeroC, Inc. All rights reserved.
//

#include "IceUtil/IceUtil.h"
#include "Ice/Ice.h"
#include "../Ice/Network.h" // For getInterfacesForMulticast

#include "PluginI.h"
#include "LocatorI.h"
#include "LookupI.h"

using namespace std;
using namespace IceDiscovery;

#ifndef ICE_DISCOVERY_API
#    ifdef ICE_DISCOVERY_API_EXPORTS
#        define ICE_DISCOVERY_API ICE_DECLSPEC_EXPORT
#    else
#        define ICE_DISCOVERY_API /**/
#    endif
#endif

//
// Plugin factory function.
//
extern "C" ICE_DISCOVERY_API Ice::Plugin*
createIceDiscovery(const Ice::CommunicatorPtr& communicator, const string&, const Ice::StringSeq&)
{
    return new PluginI(communicator);
}

namespace Ice
{
    ICE_DISCOVERY_API void registerIceDiscovery(bool loadOnInitialize)
    {
        Ice::registerPluginFactory("IceDiscovery", createIceDiscovery, loadOnInitialize);

#ifdef ICE_STATIC_LIBS
        //
        // Also register the UDP plugin with static builds to ensure the UDP transport is loaded.
        //
        registerIceUDP(true);
#endif
    }
}

PluginI::PluginI(const Ice::CommunicatorPtr& communicator) : _communicator(communicator) {}

void
PluginI::initialize()
{
    Ice::PropertiesPtr properties = _communicator->getProperties();

    bool ipv4 = properties->getPropertyAsIntWithDefault("Ice.IPv4", 1) > 0;
    bool preferIPv6 = properties->getPropertyAsInt("Ice.PreferIPv6Address") > 0;
    string address;
    if (ipv4 && !preferIPv6)
    {
        address = properties->getPropertyWithDefault("IceDiscovery.Address", "239.255.0.1");
    }
    else
    {
        address = properties->getPropertyWithDefault("IceDiscovery.Address", "ff15::1");
    }
    int port = properties->getPropertyAsIntWithDefault("IceDiscovery.Port", 4061);
    string intf = properties->getProperty("IceDiscovery.Interface");

    if (properties->getProperty("IceDiscovery.Multicast.Endpoints").empty())
    {
        ostringstream os;
        os << "udp -h \"" << address << "\" -p " << port;
        if (!intf.empty())
        {
            os << " --interface \"" << intf << "\"";
        }
        properties->setProperty("IceDiscovery.Multicast.Endpoints", os.str());
    }

    string lookupEndpoints = properties->getProperty("IceDiscovery.Lookup");
    if (lookupEndpoints.empty())
    {
        //
        // If no lookup endpoints are specified, we get all the network interfaces and create
        // an endpoint for each of them. We'll send UDP multicast packages on each interface.
        //
        IceInternal::ProtocolSupport protocol = ipv4 && !preferIPv6 ? IceInternal::EnableIPv4 : IceInternal::EnableIPv6;
        vector<string> interfaces = IceInternal::getInterfacesForMulticast(intf, protocol);
        ostringstream lookup;
        for (vector<string>::const_iterator p = interfaces.begin(); p != interfaces.end(); ++p)
        {
            if (p != interfaces.begin())
            {
                lookup << ":";
            }
            lookup << "udp -h \"" << address << "\" -p " << port << " --interface \"" << *p << "\"";
        }
        lookupEndpoints = lookup.str();
    }

    if (properties->getProperty("IceDiscovery.Reply.Endpoints").empty())
    {
        properties->setProperty("IceDiscovery.Reply.Endpoints", "udp -h " + (intf.empty() ? "*" : "\"" + intf + "\""));
    }

    if (properties->getProperty("IceDiscovery.Locator.Endpoints").empty())
    {
        properties->setProperty("IceDiscovery.Locator.AdapterId", Ice::generateUUID());
    }

    _multicastAdapter = _communicator->createObjectAdapter("IceDiscovery.Multicast");
    _replyAdapter = _communicator->createObjectAdapter("IceDiscovery.Reply");
    _locatorAdapter = _communicator->createObjectAdapter("IceDiscovery.Locator");

    //
    // Setup locatory registry.
    //
    auto locatorRegistry = make_shared<LocatorRegistryI>(_communicator);
    Ice::LocatorRegistryPrx locatorRegistryPrx(_locatorAdapter->addWithUUID(locatorRegistry));

    LookupPrx lookupPrx(_communicator, "IceDiscovery/Lookup -d:" + lookupEndpoints);
    // No collocation optimization for the multicast proxy!
    lookupPrx = lookupPrx->ice_collocationOptimized(false)->ice_router(nullopt);

    //
    // Add lookup and lookup reply Ice objects
    //
    _lookup = make_shared<LookupI>(locatorRegistry, lookupPrx, properties);
    _multicastAdapter->add(_lookup, Ice::stringToIdentity("IceDiscovery/Lookup"));

    _replyAdapter->addDefaultServant(make_shared<LookupReplyI>(_lookup), "");

    _lookup->setLookupReply(LookupReplyPrx(_replyAdapter->createProxy(Ice::Identity{"dummy", ""})->ice_datagram()));

    //
    // Setup locator on the communicator.
    //
    _locator = Ice::LocatorPrx(_locatorAdapter->addWithUUID(make_shared<LocatorI>(_lookup, locatorRegistryPrx)));
    _defaultLocator = _communicator->getDefaultLocator();
    _communicator->setDefaultLocator(_locator);

    _multicastAdapter->activate();
    _replyAdapter->activate();
    _locatorAdapter->activate();
}

void
PluginI::destroy()
{
    _multicastAdapter->destroy();
    _replyAdapter->destroy();
    _locatorAdapter->destroy();
    _lookup->destroy();
    // Restore original default locator proxy, if the user didn't change it in the meantime.
    if (_communicator->getDefaultLocator() == _locator)
    {
        _communicator->setDefaultLocator(_defaultLocator);
    }
}
