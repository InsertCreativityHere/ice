// Copyright (c) ZeroC, Inc. All rights reserved.

using System;
using System.Collections.Generic;
using System.IO;
using System.Reflection;
using System.Threading;
using System.Threading.Tasks;
using Test;

namespace ZeroC.Ice.Test.Plugin
{
    public class Client : TestHelper
    {
        public static Task<int> Main(string[] args) => TestDriver.RunTestAsync<Client>(args);

        public override async Task RunAsync(string[] args)
        {
            string pluginPath =
                string.Format("msbuild/plugin/{0}/Plugin.dll",
                              Path.GetFileName(Path.GetDirectoryName(Assembly.GetExecutingAssembly().Location)));
            {
                Console.Write("testing a simple plug-in... ");
                Console.Out.Flush();
                await using Communicator communicator = Initialize(
                    new Dictionary<string, string>
                    {
                        {
                            "Ice.Plugin.Test",
                            $"{pluginPath}:ZeroC.Ice.Test.Plugin.PluginFactory 'C:\\Program Files\\' --DatabasePath 'C:\\Program Files\\Application\\db'"
                        }
                    });
                await communicator.ActivateAsync();
                Console.WriteLine("ok");
            }

            {
                Console.Write("testing a simple plug-in that fails to initialize... ");
                Console.Out.Flush();
                try
                {
                    await using Communicator communicator = Initialize(
                        new Dictionary<string, string>()
                        {
                            {
                                "Ice.Plugin.Test", $"{pluginPath}:ZeroC.Ice.Test.Plugin.PluginInitializeFailFactory"
                            }
                        });
                    await communicator.ActivateAsync();
                    Assert(false);
                }
                catch
                {
                    // Expected
                }
                Console.WriteLine("ok");
            }

            {
                Console.Write("testing plug-in load order... ");
                Console.Out.Flush();

                await using Communicator communicator = Initialize(
                    new Dictionary<string, string>()
                    {
                        { "Ice.Plugin.PluginOne", $"{pluginPath}:ZeroC.Ice.Test.Plugin.PluginOneFactory" },
                        { "Ice.Plugin.PluginTwo", $"{pluginPath}:ZeroC.Ice.Test.Plugin.PluginTwoFactory" },
                        { "Ice.Plugin.PluginThree", $"{pluginPath}:ZeroC.Ice.Test.Plugin.PluginThreeFactory" },
                        { "Ice.PluginLoadOrder", "PluginOne, PluginTwo" } // Exclude PluginThree
                    });
                await communicator.ActivateAsync();
                Console.WriteLine("ok");
            }

            {
                Console.Write("testing plug-in manager... ");
                Console.Out.Flush();

                await using Communicator communicator = Initialize(
                    new Dictionary<string, string>()
                    {
                        { "Ice.Plugin.PluginOne", $"{pluginPath}:ZeroC.Ice.Test.Plugin.PluginOneFactory" },
                        { "Ice.Plugin.PluginTwo", $"{pluginPath}:ZeroC.Ice.Test.Plugin.PluginTwoFactory" },
                        { "Ice.Plugin.PluginThree", $"{pluginPath}:ZeroC.Ice.Test.Plugin.PluginThreeFactory" },
                    });

                Assert(communicator.Plugins.Count == 3);
                Assert(communicator.Plugins[0].Name == "PluginOne");
                Assert(communicator.Plugins[1].Name == "PluginTwo");
                Assert(communicator.Plugins[2].Name == "PluginThree");
                await communicator.ActivateAsync();
                Console.WriteLine("ok");
            }

            {
                Console.Write("testing destroy when a plug-in fails to initialize... ");
                Console.Out.Flush();
                try
                {
                    await using Communicator communicator = Initialize(
                        new Dictionary<string, string>()
                        {
                            { "Ice.Plugin.PluginOneFail", $"{pluginPath}:ZeroC.Ice.Test.Plugin.PluginOneFailFactory" },
                            { "Ice.Plugin.PluginTwoFail", $"{pluginPath}:ZeroC.Ice.Test.Plugin.PluginTwoFailFactory" },
                            { "Ice.Plugin.PluginThreeFail", $"{pluginPath}:ZeroC.Ice.Test.Plugin.PluginThreeFailFactory" },
                            { "Ice.PluginLoadOrder", "PluginOneFail, PluginTwoFail, PluginThreeFail"}
                        });
                    await communicator.ActivateAsync();
                }
                catch
                {
                    // Expected
                }
                Console.WriteLine("ok");
            }
        }
    }
}
