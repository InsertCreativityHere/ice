// Copyright (c) ZeroC, Inc.

#ifndef METADATA_VISITOR_H
#define METADATA_VISITOR_H

#include "Parser.h"

#include <functional>
#include <typeinfo>

namespace Slice
{
    enum class MetadataArgumentKind
    {
        /// The metadata takes no arguments.
        NoArguments,
        /// The metadata must have exactly 1 argument.
        SingleArgument,
        /// This metadata can have any number of arguments [0, ∞).
        AnyNumberOfArguments,

        /// This metadata must have an argument, but that argument is raw text and not validated further.
        RequiredTextArgument,
        /// This metadata can optionally have an argument, but that argument is raw text and not validated further.
        OptionalTextArgument,
    };

    /// Typedef for functions which can provide additional validation to certain metadata directives.
    ///
    /// They take a reference to the instance of metadata we're validation, and a reference to what it was applied on,
    /// and should return `nullopt` to signal that the metadata was valid. If the metadata is invalid however, it
    /// should return a string describing the error. This string will be supplied to the user in a diagnostic.
    using ValidationFunc = std::function<std::optional<std::string>(const MetadataPtr&, const SyntaxTreeBasePtr&)>;

    struct MetadataInfo
    {
        /// A list of types that this metadata can validly be applied to.
        std::list<const std::type_info*> validOn;

        /// Specifies how many and what kinds of arguments this metadata accepts.
        MetadataArgumentKind acceptedArguments;

        /// This field stores the specific values that can be provided as arguments to this metadata.
        /// If this field is unset, then we perform no validation of the arguments (ie. arguments can have any value).
        std::optional<StringList> validArgumentValues = nullopt;

        /// Indicates wether this metadata can be applied to types (ex: on return types, inner sequence types, etc.).
        bool isTypeMetadata = false;

        /// A function used to run additional validation for this metadata.
        /// If this field is set, it will always be run.
        /// @see ValidationFunc
        std::optional<ValidationFunc> extraValidation = std::nullopt;
    };

    class MetadataValidator final : public ParserVisitor
    {
    public:
        MetadataValidator(std::string language, std::map<std::string, MetadataInfo> metadataInfo);

        bool visitUnitStart(const UnitPtr&) final;
        bool visitModuleStart(const ModulePtr&) final;
        void visitClassDecl(const ClassDeclPtr&) final;
        bool visitClassDefStart(const ClassDefPtr&) final;
        void visitInterfaceDecl(const InterfaceDeclPtr&) final;
        bool visitInterfaceDefStart(const InterfaceDefPtr&) final;
        bool visitExceptionStart(const ExceptionPtr&) final;
        bool visitStructStart(const StructPtr&) final;
        void visitOperation(const OperationPtr&) final;
        void visitParamDecl(const ParamDeclPtr&) final;
        void visitDataMember(const DataMemberPtr&) final;
        void visitSequence(const SequencePtr&) final;
        void visitDictionary(const DictionaryPtr&) final;
        void visitEnum(const EnumPtr&) final;
        void visitConst(const ConstPtr&) final;

    private:
        MetadataList validate(MetadataList metadata, const SyntaxTreeBasePtr& p, bool isTypeContext = false);
        bool isMetadataValid(const MetadataPtr& metadata, const SyntaxTreeBasePtr& p, bool isTypeContext);

        std::string _language;
        std::map<std::string, MetadataInfo> _metadataInfo;
    };
}
#endif
