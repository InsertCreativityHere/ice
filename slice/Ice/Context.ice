/// Copyright (c) ZeroC, Inc. All rights reserved.

#pragma once

[[cpp:dll-export(ICE_API)]]
[[cpp:header-ext(h)]]

[[suppress-warning(reserved-identifier)]]

[cs:namespace(ZeroC)]
module Ice
{
    /// A request context. Each operation has a <code>Context</code> as its implicit final parameter.
    [cs:generic:SortedDictionary] dictionary<string, string> Context;
}
