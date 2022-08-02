//
// Copyright (c) ZeroC, Inc. All rights reserved.
//
//
// <auto-generated>
//
// Generated from file `Version.ice'
//
// Warning: do not edit this file.
//
// </auto-generated>
//

#ifndef __Ice_Version_h__
#define __Ice_Version_h__

#include <IceUtil/PushDisableWarnings.h>
#include <Ice/ProxyF.h>
#include <Ice/ObjectF.h>
#include <Ice/ValueF.h>
#include <Ice/Exception.h>
#include <Ice/LocalObject.h>
#include <Ice/StreamHelpers.h>
#include <Ice/Comparable.h>
#include <Ice/Optional.h>
#include <IceUtil/UndefSysMacros.h>

#ifndef ICE_API
#   if defined(ICE_STATIC_LIBS)
#       define ICE_API /**/
#   elif defined(ICE_API_EXPORTS)
#       define ICE_API ICE_DECLSPEC_EXPORT
#   else
#       define ICE_API ICE_DECLSPEC_IMPORT
#   endif
#endif

namespace Ice
{

/**
 * A version structure for the protocol version.
 * \headerfile Ice/Ice.h
 */
struct ProtocolVersion
{
    ::Ice::Byte major;
    ::Ice::Byte minor;

    /**
     * Obtains a tuple containing all of the struct's data members.
     * @return The data members in a tuple.
     */
    std::tuple<const ::Ice::Byte&, const ::Ice::Byte&> ice_tuple() const
    {
        return std::tie(major, minor);
    }
};

/**
 * A version structure for the encoding version.
 * \headerfile Ice/Ice.h
 */
struct EncodingVersion
{
    ::Ice::Byte major;
    ::Ice::Byte minor;

    /**
     * Obtains a tuple containing all of the struct's data members.
     * @return The data members in a tuple.
     */
    std::tuple<const ::Ice::Byte&, const ::Ice::Byte&> ice_tuple() const
    {
        return std::tie(major, minor);
    }
};

using Ice::operator<;
using Ice::operator<=;
using Ice::operator>;
using Ice::operator>=;
using Ice::operator==;
using Ice::operator!=;

}

/// \cond STREAM
namespace Ice
{

template<>
struct StreamableTraits<::Ice::ProtocolVersion>
{
    static const StreamHelperCategory helper = StreamHelperCategoryStruct;
    static const int minWireSize = 2;
    static const bool fixedLength = true;
};

template<typename S>
struct StreamReader<::Ice::ProtocolVersion, S>
{
    static void read(S* istr, ::Ice::ProtocolVersion& v)
    {
        istr->readAll(v.major, v.minor);
    }
};

template<>
struct StreamableTraits<::Ice::EncodingVersion>
{
    static const StreamHelperCategory helper = StreamHelperCategoryStruct;
    static const int minWireSize = 2;
    static const bool fixedLength = true;
};

template<typename S>
struct StreamReader<::Ice::EncodingVersion, S>
{
    static void read(S* istr, ::Ice::EncodingVersion& v)
    {
        istr->readAll(v.major, v.minor);
    }
};

}
/// \endcond

#include <IceUtil/PopDisableWarnings.h>
#endif
