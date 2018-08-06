#!/usr/bin/env python
# **********************************************************************
#
# Copyright (c) 2003-2018 ZeroC, Inc. All rights reserved.
#
# This copy of Ice is licensed to you under the terms described in the
# ICE_LICENSE file included in this distribution.
#
# **********************************************************************

from TestHelper import TestHelper
TestHelper.loadSlice("Test.ice")
import sys
import Test
import Ice


def test(b):
    if not b:
        raise RuntimeError('test assertion failed')


class CustomI(Test.Custom):
    def opByteString1(self, b1, current=None):
        if sys.version_info[0] == 2:
            test(isinstance(b1, str))
        else:
            test(isinstance(b1, bytes))
        return (b1, b1)

    def opByteString2(self, b1, current=None):
        test(isinstance(b1, list))
        return (b1, b1)

    def opByteList1(self, b1, current=None):
        test(isinstance(b1, list))
        return (b1, b1)

    def opByteList2(self, b1, current=None):
        test(isinstance(b1, tuple))
        return (b1, b1)

    def opStringList1(self, s1, current=None):
        test(isinstance(s1, list))
        return (s1, s1)

    def opStringList2(self, s1, current=None):
        test(isinstance(s1, tuple))
        return (s1, s1)

    def opStringTuple1(self, s1, current=None):
        test(isinstance(s1, tuple))
        return (s1, s1)

    def opStringTuple2(self, s1, current=None):
        test(isinstance(s1, list))
        return (s1, s1)

    def sendS(self, val, current=None):
        if sys.version_info[0] == 2:
            test(isinstance(val.b1, str))
        else:
            test(isinstance(val.b1, bytes))
        test(isinstance(val.b2, list))
        if sys.version_info[0] == 2:
            test(isinstance(val.b3, str))
        else:
            test(isinstance(val.b3, bytes))
        test(isinstance(val.b4, list))
        test(isinstance(val.s1, list))
        test(isinstance(val.s2, tuple))
        test(isinstance(val.s3, tuple))
        test(isinstance(val.s4, list))

    def sendC(self, val, current=None):
        if sys.version_info[0] == 2:
            test(isinstance(val.b1, str))
        else:
            test(isinstance(val.b1, bytes))
        test(isinstance(val.b2, list))
        if sys.version_info[0] == 2:
            test(isinstance(val.b3, str))
        else:
            test(isinstance(val.b3, bytes))
        test(isinstance(val.b4, list))
        test(isinstance(val.s1, list))
        test(isinstance(val.s2, tuple))
        test(isinstance(val.s3, tuple))
        test(isinstance(val.s4, list))

    def shutdown(self, current=None):
        current.adapter.getCommunicator().shutdown()


class Server(TestHelper):

    def run(self, args):
        with self.initialize(args=args) as communicator:
            communicator.getProperties().setProperty("TestAdapter.Endpoints", self.getTestEndpoint())
            adapter = communicator.createObjectAdapter("TestAdapter")
            adapter.add(CustomI(), Ice.stringToIdentity("test"))
            adapter.activate()
            communicator.waitForShutdown()
