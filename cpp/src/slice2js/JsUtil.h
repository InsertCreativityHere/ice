// Copyright (c) ZeroC, Inc.

#ifndef JS_UTIL_H
#define JS_UTIL_H

#include "../Ice/OutputUtil.h"
#include "../Slice/Parser.h"

namespace Slice::Js
{
    std::string relativePath(const std::string&, const std::string&);
    std::string getJavaScriptModuleForType(const TypePtr& type);
    std::string getJavaScriptModule(const DefinitionContextPtr&);

    std::string typeToJsString(const TypePtr&, bool definition = false);

    std::string getHelper(const TypePtr&);

    //
    // Generate code to marshal or unmarshal a type
    //
    void writeMarshalUnmarshalCode(IceInternal::Output&, const TypePtr&, const std::string&, bool);
    void writeOptionalMarshalUnmarshalCode(IceInternal::Output&, const TypePtr&, const std::string&, int, bool);
}

#endif
