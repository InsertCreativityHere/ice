// Copyright (c) ZeroC, Inc. All rights reserved.

using System.Collections.Generic;
using System.Threading.Tasks;
using ZeroC.Test;

namespace ZeroC.Ice.Test.AMI
{
    public class Collocated : TestHelper
    {
        public override async Task RunAsync(string[] args)
        {
            await Communicator.ActivateAsync();

            Communicator.SetProperty("TestAdapter.Endpoints", GetTestEndpoint(0));
            Communicator.SetProperty("TestAdapter2.Endpoints", GetTestEndpoint(1));

            ObjectAdapter adapter = Communicator.CreateObjectAdapter("TestAdapter");
            adapter.Add("test", new TestIntf());
            adapter.Add("test2", new TestIntf2());
            // Don't activate OA to ensure collocation is used.

            ObjectAdapter adapter2 = Communicator.CreateObjectAdapter("TestAdapter2", serializeDispatch: true);
            adapter2.Add("serialized", new TestIntf());
            // Don't activate OA to ensure collocation is used.

            await AllTests.RunAsync(this);
        }

        public static async Task<int> Main(string[] args)
        {
            Dictionary<string, string> properties = CreateTestProperties(ref args);
            properties["Ice.Warn.AMICallback"] = "0";
            // Limit the send buffer size, this test relies on the socket send() blocking after sending a given amount
            // of data.
            properties["Ice.TCP.SndSize"] = "50K";
            // This test kills connections, so we don't want warnings.
            properties["Ice.Warn.Connections"] = "0";

            await using var communicator = CreateCommunicator(properties);
            return await RunTestAsync<Collocated>(communicator, args);
        }
    }
}
