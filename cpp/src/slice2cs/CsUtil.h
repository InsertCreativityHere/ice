// Copyright (c) ZeroC, Inc.

#ifndef CS_UTIL_H
#define CS_UTIL_H

#include "../Ice/OutputUtil.h"
#include "../Slice/Parser.h"

namespace Slice::Cs
{
    /// Convert a dimension-less array declaration to one with a dimension.
    [[nodiscard]] std::string toArrayAlloc(const std::string& decl, const std::string& sz);

    void validateMetadata(const UnitPtr&);

    /// Returns the namespace of a Contained entity.
    [[nodiscard]] std::string getNamespace(const ContainedPtr&);

    [[nodiscard]] std::string getUnqualified(const ContainedPtr&, const std::string& package);

    /// Removes a leading '@' character from the provided identifier (if one is present).
    [[nodiscard]] std::string removeEscapePrefix(const std::string& identifier);

    std::string typeToString(const TypePtr&, const std::string&, bool = false);

    /// Returns the namespace prefix of a Contained entity.
    std::string getNamespacePrefix(const ContainedPtr&);

    std::string resultStructName(const std::string&, const std::string&, bool = false);
    std::string resultType(const OperationPtr&, const std::string&, bool = false);
    std::string taskResultType(const OperationPtr&, const std::string&, bool = false);
    std::string getOptionalFormat(const TypePtr&);
    std::string getStaticId(const TypePtr&);

    // Is this Slice type mapped to a C# value type?
    bool isValueType(const TypePtr&);

    // Is this Slice struct mapped to a C# class?
    bool isMappedToClass(const StructPtr& p) { return !isValueType(p); }

    // Is the mapped C# type for this field a non-nullable C# reference type?
    bool isMappedToNonNullableReference(const DataMemberPtr& p);

    // Is the mapped C# type for this field a non-nullable reference type?
    // string fields are not included since they have a "" default.
    bool isMappedToRequiredField(const DataMemberPtr&);

    //
    // Generate code to marshal or unmarshal a type
    //
    void writeMarshalUnmarshalCode(
        ::IceInternal::Output&,
        const TypePtr&,
        const std::string&,
        const std::string&,
        bool,
        const std::string& = "");
    void writeOptionalMarshalUnmarshalCode(
        ::IceInternal::Output&,
        const TypePtr&,
        const std::string&,
        const std::string&,
        int,
        bool,
        const std::string& = "");
    void writeSequenceMarshalUnmarshalCode(
        ::IceInternal::Output&,
        const SequencePtr&,
        const std::string&,
        const std::string&,
        bool,
        bool,
        const std::string& = "");
    void writeOptionalSequenceMarshalUnmarshalCode(
        ::IceInternal::Output&,
        const SequencePtr&,
        const std::string&,
        const std::string&,
        int,
        bool,
        const std::string& = "");
}

#endif
