//
// Copyright (c) ZeroC, Inc. All rights reserved.
//

#ifndef SWIFT_UTIL_H
#define SWIFT_UTIL_H

#include <Slice/Parser.h>
#include <IceUtil/OutputUtil.h>

typedef std::list<std::pair<std:: string, std::string> > StringPairList;

namespace Slice
{

std::string getSwiftModule(const ModulePtr&, std::string&);
std::string getSwiftModule(const ModulePtr&);
ModulePtr getTopLevelModule(const ContainedPtr&);
ModulePtr getTopLevelModule(const TypePtr&);

std::string fixIdent(const std::string&);

struct ParamInfo
{
    std::string name;
    TypePtr type;
    std::string typeStr;
    bool isTagged;
    int tag;
    DataMemberPtr param; // 0 == return value
};

typedef std::list<ParamInfo> ParamInfoList;

struct DocElements
{
    StringList overview;
    bool deprecated;
    StringList deprecateReason;
    StringList misc;
    StringList seeAlso;
    StringList returns;
    std::map<std::string, StringList> params;
    std::map<std::string, StringList> exceptions;
};

class SwiftGenerator : private IceUtil::noncopyable
{
public:

    virtual ~SwiftGenerator() {};

    static void validateMetaData(const UnitPtr&);

protected:

    void trimLines(StringList&);
    StringList splitComment(const std::string&);
    bool parseCommentLine(const std::string&, const std::string&, bool, std::string&, std::string&);
    DocElements parseComment(const ContainedPtr&);
    void writeDocLines(IceUtilInternal::Output&, const StringList&, bool commentFirst = true,
                       const std::string& space = " ");
    void writeDocSentence(IceUtilInternal::Output&, const StringList&);
    void writeSeeAlso(IceUtilInternal::Output&, const StringList&, const ContainerPtr&);
    void writeDocSummary(IceUtilInternal::Output&, const ContainedPtr&);
    void writeOpDocSummary(IceUtilInternal::Output&, const OperationPtr&, bool, bool = false);

    void writeProxyDocSummary(IceUtilInternal::Output&, const InterfaceDefPtr&, const std::string&);
    void writeServantDocSummary(IceUtilInternal::Output&, const InterfaceDefPtr&, const std::string&);
    void writeMemberDoc(IceUtilInternal::Output&, const DataMemberPtr&);

    std::string paramLabel(const std::string&, const DataMemberList&);
    std::string operationReturnType(const OperationPtr&);
    bool operationReturnIsTuple(const OperationPtr&);
    std::string operationReturnDeclaration(const OperationPtr&);
    std::string operationInParamsDeclaration(const OperationPtr&);

    bool operationIsAmd(const OperationPtr&);

    ParamInfoList getAllInParams(const OperationPtr&);
    void getInParams(const OperationPtr&, ParamInfoList&, ParamInfoList&);

    ParamInfoList getAllOutParams(const OperationPtr&);
    void getOutParams(const OperationPtr&, ParamInfoList&, ParamInfoList&);

    std::string typeToString(const TypePtr&, const ContainedPtr&, const StringList& = StringList());

    std::string getAbsolute(const TypePtr&);
    std::string getAbsolute(const InterfaceDeclPtr&);
    std::string getAbsolute(const InterfaceDefPtr&);
    std::string getAbsolute(const ClassDeclPtr&);
    std::string getAbsolute(const ClassDefPtr&);
    std::string getAbsolute(const StructPtr&);
    std::string getAbsolute(const ExceptionPtr&);
    std::string getAbsolute(const EnumPtr&);
    std::string getAbsolute(const ConstPtr&);
    std::string getAbsolute(const SequencePtr&);
    std::string getAbsolute(const DictionaryPtr&);

    std::string getUnqualified(const std::string&, const std::string&);
    std::string modeToString(Operation::Mode);
    std::string getTagFormat(const TypePtr&);
    bool isClassType(const TypePtr&);

    bool containsClassMembers(const StructPtr&);

    std::string getValue(const std::string&, const TypePtr&);
    void writeConstantValue(IceUtilInternal::Output& out, const TypePtr&, const SyntaxTreeBasePtr&,
                            const std::string&, const StringList&, const std::string&, bool optional = false);
    void writeDefaultInitializer(IceUtilInternal::Output&,  bool, bool);
    void writeMemberwiseInitializer(IceUtilInternal::Output&, const DataMemberList&, const ContainedPtr&);
    void writeMemberwiseInitializer(IceUtilInternal::Output&, const DataMemberList&, const DataMemberList&,
                                    const DataMemberList&, const ContainedPtr&,
                                    bool rootClass = false);
    void writeMembers(IceUtilInternal::Output&, const DataMemberList&, const ContainedPtr&);

    void writeMarshalUnmarshalCode(::IceUtilInternal::Output&,
                                   const TypePtr&,
                                   const ContainedPtr&,
                                   const std::string&,
                                   bool,
                                   int = -1);

    bool usesMarshalHelper(const TypePtr&);
    void writeMarshalInParams(::IceUtilInternal::Output&, const OperationPtr&);
    void writeMarshalOutParams(::IceUtilInternal::Output&, const OperationPtr&);
    void writeMarshalAsyncOutParams(::IceUtilInternal::Output&, const OperationPtr&);
    void writeUnmarshalInParams(::IceUtilInternal::Output&, const OperationPtr&);
    void writeUnmarshalOutParams(::IceUtilInternal::Output&, const OperationPtr&);
    void writeUnmarshalUserException(::IceUtilInternal::Output& out, const OperationPtr&);
    void writeSwiftAttributes(::IceUtilInternal::Output&, const StringList&);
    void writeProxyOperation(::IceUtilInternal::Output&, const OperationPtr&);
    void writeProxyAsyncOperation(::IceUtilInternal::Output&, const OperationPtr&);
    void writeDispatchOperation(::IceUtilInternal::Output&, const OperationPtr&);
    void writeDispatchAsyncOperation(::IceUtilInternal::Output&, const OperationPtr&);

private:

    class MetaDataVisitor : public ParserVisitor
    {
    public:

        bool visitModuleStart(const ModulePtr&) override;
        bool visitClassDefStart(const ClassDefPtr&) override;
        bool visitInterfaceDefStart(const InterfaceDefPtr&) override;
        void visitOperation(const OperationPtr&) override;
        bool visitExceptionStart(const ExceptionPtr&) override;
        bool visitStructStart(const StructPtr&) override;
        void visitSequence(const SequencePtr&) override;
        void visitDictionary(const DictionaryPtr&) override;
        void visitEnum(const EnumPtr&) override;
        void visitConst(const ConstPtr&) override;

    private:

        StringList validate(const SyntaxTreeBasePtr&, const StringList&, const std::string&, int);

        typedef std::map<std::string, std::string> ModuleMap;
        typedef std::map<std::string, ModuleMap> ModulePrefix;

        //
        // Each Slice unit has to map all top-level modules to a single Swift module
        //
        ModuleMap _modules;

        //
        // With a given Swift module a Slice module has to map to a single prefix
        //
        ModulePrefix _prefixes;

        static const std::string _msg;
    };
};

}

#endif
