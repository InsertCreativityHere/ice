// Copyright (c) ZeroC, Inc. All rights reserved.

#pragma once

[[cpp:dll-export(ICE_API)]]
[[cpp:header-ext(h)]]

[[suppress-warning(reserved-identifier)]]

[cs:namespace(ZeroC)]
module Ice
{
    /// Represents a version of the Ice protocol.
    unchecked enum Protocol : byte
    {
        /// The ice1 protocol supported by all Ice versions since Ice 1.0.
        Ice1 = 1,
        /// The ice2 protocol introduced in Ice 4.0.
        Ice2 = 2
    }
}
