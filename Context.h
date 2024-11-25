//
// Copyright (c) ZeroC, Inc. All rights reserved.
//
//
// Ice version 3.8.0-alpha.0
//
// <auto-generated>
//
// Generated from file `Context.ice'
//
// Warning: do not edit this file.
//
// </auto-generated>
//

#ifndef __Context_h__
#define __Context_h__

#include <Ice/PushDisableWarnings.h>
#include <Ice/Config.h>
#include <map>
#include <string>

#ifndef ICE_IGNORE_VERSION
#   if ICE_INT_VERSION  != 30850
#       error Ice version mismatch: an exact match is required for beta generated code
#   endif
#endif

namespace Ice
{
    /// A string-string dictionary, used to transmit additional information with an Ice request. This context is only
    /// transmitted with requests, from clients to servers; the Ice protocol does not provide response contexts.
    using Context = std::map<std::string, std::string, std::less<>>;

}

#include <Ice/PopDisableWarnings.h>
#endif
