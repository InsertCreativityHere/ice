# -*- coding: utf-8 -*-
#
# Copyright (c) ZeroC, Inc. All rights reserved.
#

import uuid

domainId = uuid.uuid4() # Ensures each test uses a unique domain ID

def props(process, current):
    port = current.driver.getTestPort(10)
    discoveryProps = {
        "Ice.ProgramName": "server{}".format(process.args[0]) if isinstance(process, Server) else "client", # This is used for the trace file
        "Ice.Plugin.IceDiscovery": current.getPluginEntryPoint("IceDiscovery", process),
        "IceDiscovery.RetryCount": 20,
        "IceDiscovery.DomainId": domainId,
        "IceDiscovery.Timeout": "50",
        "IceDiscovery.Interface": "" if isinstance(platform, Linux) else "::1" if current.config.ipv6 else "127.0.0.1",
        "IceDiscovery.Port": port,
    }
    return discoveryProps


traceProps = {
    "Ice.Trace.Locator" : 2,
    "Ice.Trace.Protocol" : 1
}

#
# Suppress the warning lines
#
suppressDiscoveryWarning=False
def suppressWarning(x):
    global suppressDiscoveryWarning
    if re.search("-! .* warning: .*failed to lookup adapter.*\n", x):
        suppressDiscoveryWarning = True
        return re.sub("-! .* warning: .*failed to lookup adapter.*\n", "", x)
    elif suppressDiscoveryWarning and re.search("^   .*\n", x):
        return ""
    else:
        suppressDiscoveryWarning = False
        return x

# Filter-out the warning about invalid lookup proxy
outfilters = [ lambda x: suppressWarning(x) ]

options = None
if isinstance(platform,AIX):
    # AIX test VMs only have IPv6 enabled on the loopback interface
    # where multicast doesn't work
    options = { "ipv6" : [False] }

TestSuite(__name__, [
   ClientServerTestCase(client=Client(args=[3], props=props, outfilters=outfilters),
                        servers=[Server(args=[i], readyCount=4, props=props) for i in range(0, 3)],
                        traceProps=traceProps)
], multihost=False, options=options)
