//
// Copyright (c) ZeroC, Inc. All rights reserved.
//
//
// <auto-generated>
//
// Generated from file `PropertiesF.ice'
//
// Warning: do not edit this file.
//
// </auto-generated>
//

#ifndef __Ice_PropertiesF_h__
#define __Ice_PropertiesF_h__

#include <IceUtil/PushDisableWarnings.h>
#include <Ice/ProxyF.h>
#include <Ice/ObjectF.h>
#include <Ice/ValueF.h>
#include <Ice/Exception.h>
#include <Ice/LocalObject.h>
#include <Ice/StreamHelpers.h>
#include <Ice/Comparable.h>
#include <Ice/Proxy.h>
#include <IceUtil/ScopedArray.h>
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

#ifdef ICE_CPP11_MAPPING // C++11 mapping

namespace Ice
{

class Properties;
class PropertiesAdmin;
class PropertiesAdminPrx;

}

/// \cond STREAM
namespace Ice
{

}
/// \endcond

/// \cond INTERNAL
namespace Ice
{

using PropertiesPtr = ::std::shared_ptr<Properties>;

using PropertiesAdminPtr = ::std::shared_ptr<PropertiesAdmin>;
using PropertiesAdminPrxPtr = ::std::shared_ptr<PropertiesAdminPrx>;

}
/// \endcond

#else // C++98 mapping

namespace IceProxy
{

namespace Ice
{

class PropertiesAdmin;
/// \cond INTERNAL
ICE_API void _readProxy(::Ice::InputStream*, ::IceInternal::ProxyHandle< PropertiesAdmin>&);
ICE_API ::IceProxy::Ice::Object* upCast(PropertiesAdmin*);
/// \endcond

}

}

namespace Ice
{

class Properties;
/// \cond INTERNAL
ICE_API LocalObject* upCast(Properties*);
/// \endcond
typedef ::IceInternal::Handle< Properties> PropertiesPtr;

class PropertiesAdmin;
/// \cond INTERNAL
ICE_API Object* upCast(PropertiesAdmin*);
/// \endcond
typedef ::IceInternal::Handle< PropertiesAdmin> PropertiesAdminPtr;
typedef ::IceInternal::ProxyHandle< ::IceProxy::Ice::PropertiesAdmin> PropertiesAdminPrx;
typedef PropertiesAdminPrx PropertiesAdminPrxPtr;
/// \cond INTERNAL
ICE_API void _icePatchObjectPtr(PropertiesAdminPtr&, const ObjectPtr&);
/// \endcond

}

/// \cond STREAM
namespace Ice
{

}
/// \endcond

#endif

#include <IceUtil/PopDisableWarnings.h>
#endif
