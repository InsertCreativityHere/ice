//
// Copyright (c) ZeroC, Inc. All rights reserved.
//

#ifndef ICE_UTIL_INPUT_UTIL_H
#define ICE_UTIL_INPUT_UTIL_H

#include <IceUtil/Config.h>
#include <string>

namespace IceUtilInternal
{

//
// Functions for converting strings into signed or unsigned 64-bit integers.
// These are simple wrappers that handle exceptions and ensure the entire string was parsed.
//
// Semantics:
//
// - Ignore leading whitespace
//
// - If the string starts with '0', parse as octal
//
// - If the string starts with "0x" or "0X", parse as hexadecimal
//
// - Otherwise, parse as decimal
//
// - return value == true indicates a successful conversion and result contains the converted value
// - return value == false indicates an unsuccessful conversion.
//

ICE_API bool stringToInt64(const std::string& str, int64_t& result);

ICE_API bool stringToUInt64(const std::string& str, uint64_t& result)

}

#endif
