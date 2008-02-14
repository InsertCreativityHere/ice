#!/usr/bin/env python
# **********************************************************************
#
# Copyright (c) 2003-2008 ZeroC, Inc. All rights reserved.
#
# This copy of Ice is licensed to you under the terms described in the
# ICE_LICENSE file included in this distribution.
#
# **********************************************************************

import os, sys
import time

for toplevel in [".", "..", "../..", "../../..", "../../../.."]:
    toplevel = os.path.normpath(toplevel)
    if os.path.exists(os.path.join(toplevel, "config", "TestUtil.py")):
        break
else:
    raise "can't find toplevel directory!"

sys.path.append(os.path.join(toplevel, "config"))
import TestUtil
TestUtil.processCmdLine()

name = os.path.join("IceStorm", "federation")
testdir = os.path.dirname(os.path.abspath(__file__))

iceBox = TestUtil.getIceBox(testdir)
iceBoxAdmin = os.path.join(TestUtil.getBinDir(__file__), "iceboxadmin")
iceStormAdmin = os.path.join(TestUtil.getBinDir(__file__), "icestormadmin")

iceStormService = " --IceBox.Service.IceStorm=IceStormService," + TestUtil.getIceSoVersion() + ":createIceStorm" + \
                  ' --IceStorm.TopicManager.Endpoints="default -p 12011"' + \
                  ' --IceStorm.Publish.Endpoints="default"' + \
                  " --IceBox.PrintServicesReady=IceStorm" + \
                  " --IceBox.InheritProperties=1" + \
                  ' --Ice.Admin.Endpoints="default -p 12010"' + \
                  " --Ice.Admin.InstanceName=IceBox"

serviceManagerProxy = ' --IceBoxAdmin.ServiceManager.Proxy="IceBox/admin -f IceBox.ServiceManager:default -p 12010"'

iceStormReference = ' --IceStorm.TopicManager.Proxy="IceStorm/TopicManager:default -p 12011"'

def doTest(batch):
    global testdir
    global iceStormReference

    publisher = os.path.join(testdir, "publisher")
    subscriber = os.path.join(testdir, "subscriber")

    if batch:
        name = "batch subscriber"
        batchOptions = " -b"
    else:
        name = "subscriber"
        batchOptions = ""

    subscriberPipe = TestUtil.startServer(subscriber, batchOptions + iceStormReference + " 2>&1")
    TestUtil.getServerPid(subscriberPipe)
    TestUtil.getAdapterReady(subscriberPipe)

    #
    # Start the publisher. This should publish events which eventually
    # causes subscriber to terminate.
    #
    publisherPipe = TestUtil.startClient(publisher, iceStormReference + " 2>&1")

    TestUtil.printOutputFromPipe(publisherPipe)

    subscriberStatus = TestUtil.specificServerStatus(subscriberPipe, 30)
    publisherStatus = TestUtil.closePipe(publisherPipe)

    return subscriberStatus or publisherStatus

dbHome = os.path.join(testdir, "db")
TestUtil.cleanDbDir(dbHome)
iceStormDBEnv=" --Freeze.DbEnv.IceStorm.DbHome=" + dbHome

print "starting icestorm service...",
iceBoxPipe = TestUtil.startServer(iceBox, iceStormService + iceStormDBEnv + " 2>&1")
TestUtil.getServerPid(iceBoxPipe)
TestUtil.waitServiceReady(iceBoxPipe, "IceStorm")
print "ok"

print "setting up topics...",
iceStormAdminPipe = TestUtil.startClient(iceStormAdmin, iceStormReference + \
        r' -e "create fed1 fed2 fed3; link fed1 fed2 10; link fed2 fed3 5" 2>&1')
iceStormAdminStatus = TestUtil.closePipe(iceStormAdminPipe)
if iceStormAdminStatus:
    TestUtil.killServers()
    sys.exit(1)
print "ok"

#
# Test oneway subscribers.
#
print "testing oneway subscribers...",
sys.stdout.flush()
onewayStatus = doTest(0)
print "ok"

#
# Test batch oneway subscribers.
#
print "testing batch subscribers...",
sys.stdout.flush()
batchStatus = doTest(1)
print "ok"

#
# Destroy the topics.
#
print "destroying topics...",
iceStormAdminPipe = TestUtil.startClient(iceStormAdmin, iceStormReference + r' -e "destroy fed1 fed2 fed3" 2>&1')
iceStormAdminStatus = TestUtil.closePipe(iceStormAdminPipe)
if iceStormAdminStatus:
    TestUtil.killServers()
    sys.exit(1)
print "ok"

#
# Shutdown icestorm.
#
print "shutting down icestorm service...",
iceBoxAdminPipe = TestUtil.startClient(iceBoxAdmin,  serviceManagerProxy + r' shutdown 2>&1')
iceBoxAdminStatus = TestUtil.closePipe(iceBoxAdminPipe)
if iceBoxAdminStatus:
    TestUtil.killServers()
    sys.exit(1)
print "ok"

if TestUtil.serverStatus() or onewayStatus or batchStatus:
    TestUtil.killServers()
    sys.exit(1)

sys.exit(0)
