// Copyright (c) ZeroC, Inc.

#include "DocCommentParser.h"
#include "Ice/StringUtil.h"

#include <algorithm>

using namespace std;
using namespace Slice;

namespace Slice
{
    class DocCommentParser final : public ParserVisitor
    {
    public:
        DocCommentParser(DocCommentFormatter& formatter) : _formatter(formatter) {}

        bool visitModuleStart(const ModulePtr&) final;
        void visitClassDecl(const ClassDeclPtr&) final;
        bool visitClassDefStart(const ClassDefPtr&) final;
        void visitInterfaceDecl(const InterfaceDeclPtr&) final;
        bool visitInterfaceDefStart(const InterfaceDefPtr&) final;
        bool visitExceptionStart(const ExceptionPtr&) final;
        bool visitStructStart(const StructPtr&) final;
        void visitOperation(const OperationPtr&) final;
        void visitParameter(const ParameterPtr&) final;
        void visitDataMember(const DataMemberPtr&) final;
        void visitSequence(const SequencePtr&) final;
        void visitDictionary(const DictionaryPtr&) final;
        void visitEnum(const EnumPtr&) final;
        void visitConst(const ConstPtr&) final;

    private:
        optional<DocComment> parseDocCommentFor(const ContainedPtr& p);

        DocCommentFormatter& _formatter;
    };
}

void
Slice::parseAllDocCommentsWithin(const UnitPtr& unit, DocCommentFormatter& formatter)
{
    DocCommentParser docCommentParser{formatter};
    unit->visit(&docCommentParser);
}

bool
DocCommentParser::visitModuleStart(const ModulePtr& module)
{
    module->_docComment = parseDocCommentFor(module);
    return true;
}

void
DocCommentParser::visitClassDecl(const ClassDeclPtr& classDecl)
{
    classDecl->_docComment = parseDocCommentFor(classDecl);
}

bool
DocCommentParser::visitClassDefStart(const ClassDefPtr& classDef)
{
    classDef->_docComment = parseDocCommentFor(classDef);
    return true;
}

void
DocCommentParser::visitInterfaceDecl(const InterfaceDeclPtr& interfaceDecl)
{
    interfaceDecl->_docComment = parseDocCommentFor(interfaceDecl);
}

bool
DocCommentParser::visitInterfaceDefStart(const InterfaceDefPtr& interfaceDef)
{
    interfaceDef->_docComment = parseDocCommentFor(interfaceDef);
    return true;
}

bool
DocCommentParser::visitExceptionStart(const ExceptionPtr& exceptionDef)
{
    exceptionDef->_docComment = parseDocCommentFor(exceptionDef);
    return true;
}

bool
DocCommentParser::visitStructStart(const StructPtr& structDef)
{
    structDef->_docComment = parseDocCommentFor(structDef);
    return true;
}

void
DocCommentParser::visitOperation(const OperationPtr& operation)
{
    operation->_docComment = parseDocCommentFor(operation);
}

void
DocCommentParser::visitParameter(const ParameterPtr& parameter)
{
    parameter->_docComment = parseDocCommentFor(parameter);
}

void
DocCommentParser::visitDataMember(const DataMemberPtr& member)
{
    member->_docComment = parseDocCommentFor(member);
}

void
DocCommentParser::visitSequence(const SequencePtr& sequence)
{
    sequence->_docComment = parseDocCommentFor(sequence);
}

void
DocCommentParser::visitDictionary(const DictionaryPtr& dictionary)
{
    dictionary->_docComment = parseDocCommentFor(dictionary);
}

void
DocCommentParser::visitEnum(const EnumPtr& enumDef)
{
    enumDef->_docComment = parseDocCommentFor(enumDef);
}

void
DocCommentParser::visitConst(const ConstPtr& constDef)
{
    constDef->_docComment = parseDocCommentFor(constDef);
}

namespace
{
    void trimLines(StringList& lines)
    {
        // Remove empty trailing lines.
        while (!lines.empty() && lines.back().empty())
        {
            lines.pop_back();
        }
    }

    StringList splitComment(string comment)
    {
        string::size_type pos = 0;

        // Split the comment into separate lines, and removing any trailing whitespace and lines from it.
        StringList result;
        pos = 0;
        string::size_type nextPos;
        while ((nextPos = comment.find_first_of('\n', pos)) != string::npos)
        {
            result.push_back(IceInternal::trim(comment.substr(pos, nextPos - pos)));
            pos = nextPos + 1;
        }
        result.push_back(IceInternal::trim(comment.substr(pos)));

        trimLines(result);
        return result;
    }

    bool parseNamedCommentLine(string_view l, string_view tag, string& name, string& doc)
    {
        if (l.find(tag) == 0)
        {
            const string ws = " \t";

            auto nameStart = l.find_first_not_of(ws, tag.size());
            if (nameStart == string::npos)
            {
                return false; // Malformed line, ignore it.
            }

            auto nameEnd = l.find_first_of(ws, nameStart);
            if (nameEnd == string::npos)
            {
                return false; // Malformed line, ignore it.
            }
            name = l.substr(nameStart, nameEnd - nameStart);

            // Store whatever remains of the doc comment in the `doc` string.
            auto docSplitPos = l.find_first_not_of(ws, nameEnd);
            if (docSplitPos != string::npos)
            {
                doc = l.substr(docSplitPos);
            }

            return true;
        }
        return false;
    }

    bool parseCommentLine(string_view l, string_view tag, string& doc)
    {
        if (l.find(tag) == 0)
        {
            // Find the first whitespace that appears after the tag. Everything after it is part of the `doc` string.
            auto docSplitPos = l.find_first_not_of(" \t", tag.size());
            if (docSplitPos != string::npos)
            {
                doc = l.substr(docSplitPos);
            }
            return true;
        }
        return false;
    }

    /// Returns a pointer to the Slice element referenced by `linkText`, relative to the scope of `source`.
    /// If the link cannot be resolved, `nullptr` is returned instead.
    SyntaxTreeBasePtr resolveDocLink(string linkText, const ContainedPtr& source)
    {
        // First we check if the link is to a builtin type.
        if (auto kind = Builtin::kindFromString(linkText))
        {
            return source->unit()->createBuiltin(kind.value());
        }

        // Then, before checking for user-defined types, we determine which scope we'll be searching relative to.
        ContainerPtr linkSourceScope = dynamic_pointer_cast<Container>(source);
        if (!linkSourceScope || dynamic_pointer_cast<Operation>(source))
        {
            linkSourceScope = source->container();
        }

        // Perform the actual lookup.
        auto separatorPos = linkText.find('#');
        if (separatorPos == 0)
        {
            // If the link starts with '#', it is explicitly relative to the `linkSourceScope` container.
            ContainedList results = source->unit()->findContents(linkSourceScope->thisScope() + linkText.substr(1));
            return (results.empty() ? nullptr : results.front());
        }
        else if (separatorPos != string::npos)
        {
            // If the link has a '#' anywhere else, convert it to '::' so we can look it up.
            linkText.replace(separatorPos, 1, "::");
        }
        ContainedList results = linkSourceScope->lookupContained(linkText, false);
        return (results.empty() ? nullptr : results.front());
    }
}

optional<DocComment>
DocCommentParser::parseDocCommentFor(const ContainedPtr& p)
{
    // Split the comment's raw text up into lines.
    StringList lines = splitComment(_formatter.preprocess(p->_rawDocComment));
    if (lines.empty())
    {
        return nullopt;
    }

    // Fix any link tags using the provided link formatter.
    const string link = "{@link ";
    for (auto& line : lines)
    {
        auto pos = line.find(link);
        while (pos != string::npos)
        {
            auto endpos = line.find('}', pos);
            if (endpos != string::npos)
            {
                // Extract the linked-to identifier.
                auto identStart = line.find_first_not_of(" \t", pos + link.size());
                auto identEnd = line.find_last_not_of(" \t", endpos);
                string linkText = line.substr(identStart, identEnd - identStart);

                // Then erase the entire '{@link foo}' tag from the comment.
                line.erase(pos, endpos - pos + 1);

                // Attempt to resolve the link, and issue a warning if the link is invalid.
                SyntaxTreeBasePtr linkTarget = resolveDocLink(linkText, p);
                if (!linkTarget)
                {
                    string msg = "no Slice element with identifier '" + linkText + "' could be found in this context";
                    p->unit()->warning(p->file(), p->line(), InvalidComment, msg);
                }
                if (dynamic_pointer_cast<Parameter>(linkTarget))
                {
                    // We don't support linking to parameters with '@link' tags.
                    // Parameter links must be done with '@p' tags, and can only appear on the enclosing operation.
                    string msg = "cannot link parameter '" + linkText + "'; parameters can only be referenced with @p";
                    p->unit()->warning(p->file(), p->line(), InvalidComment, msg);
                    linkTarget = nullptr;
                }

                // Finally, insert a correctly formatted link where the '{@link foo}' used to be.
                string formattedLink = _formatter.formatLink(linkText, p, linkTarget);
                line.insert(pos, formattedLink);
                pos += formattedLink.length();
            }
            pos = line.find(link, pos);
        }
    }

    // Some tags are only valid if they're applied to an operation.
    // And we need a reference to the operation to make sure any names used in the tag match the names in the operation.
    OperationPtr operationTarget = dynamic_pointer_cast<Operation>(p);

    const string ws = " \t";
    const string paramTag = "@param";
    const string throwsTag = "@throws";
    const string exceptionTag = "@exception";
    const string remarkTag = "@remark";
    const string remarksTag = "@remarks";
    const string seeTag = "@see";
    const string returnTag = "@return";
    const string deprecatedTag = "@deprecated";

    DocComment comment;
    StringList* currentSection = &comment._overview;
    string lineText;
    string name;

    // Parse the comment's text.
    for (const auto& line : lines)
    {
        lineText.clear();

        if (parseNamedCommentLine(line, paramTag, name, lineText))
        {
            if (!operationTarget)
            {
                // If '@param' was put on anything other than an operation, ignore it and issue a warning.
                const string msg = "the '" + paramTag + "' tag is only valid on operations";
                p->unit()->warning(p->file(), p->line(), InvalidComment, msg);
                currentSection = nullptr;
            }
            else
            {
                // Check that the '@param <name>' corresponds to an actual parameter in the operation.
                const ParameterList params = operationTarget->parameters();
                const auto paramNameCheck = [&name](const ParameterPtr& param) { return param->name() == name; };
                if (std::none_of(params.begin(), params.end(), paramNameCheck))
                {
                    const string msg = "'" + paramTag + " " + name +
                                       "' does not correspond to any parameter in operation '" + p->name() + "'";
                    p->unit()->warning(p->file(), p->line(), InvalidComment, msg);
                }

                // Check if this is a duplicate tag. If it is, ignore it and issue a warning.
                if (comment._parameters.count(name) != 0)
                {
                    const string msg = "ignoring duplicate doc-comment tag: '" + paramTag + " " + name + "'";
                    p->unit()->warning(p->file(), p->line(), InvalidComment, msg);
                    currentSection = nullptr;
                }
                else
                {
                    comment._parameters[name] = {};
                    currentSection = &comment._parameters[name];
                }
            }
        }
        else if (
            parseNamedCommentLine(line, throwsTag, name, lineText) ||
            parseNamedCommentLine(line, exceptionTag, name, lineText))
        {
            // '@throws' and '@exception' are equivalent. But we want to use the correct one in our warning messages.
            const string actualTag = (line.find(throwsTag) == 0) ? throwsTag : exceptionTag;
            if (!operationTarget)
            {
                // If '@throws'/'@exception' was put on anything other than an operation, ignore it and issue a warning.
                const string msg = "the '" + actualTag + "' tag is only valid on operations";
                p->unit()->warning(p->file(), p->line(), InvalidComment, msg);
                currentSection = nullptr;
            }
            else
            {
                // Check if the exception exists...
                const ExceptionPtr exceptionTarget = operationTarget->lookupException(name, false);
                if (!exceptionTarget)
                {
                    const string msg = "'" + actualTag + " " + name +
                                       "': no exception with this name could be found from the current scope";
                    p->unit()->warning(p->file(), p->line(), InvalidComment, msg);
                }
                else
                {
                    // ... and matches one of the exceptions in the operation's specification.
                    const ExceptionList exceptionSpec = operationTarget->throws();
                    const auto exceptionCheck = [&exceptionTarget](const ExceptionPtr& ex)
                    { return ex->isBaseOf(exceptionTarget) || ex->scoped() == exceptionTarget->scoped(); };
                    if (std::none_of(exceptionSpec.begin(), exceptionSpec.end(), exceptionCheck))
                    {
                        const string msg = "'" + actualTag + " " + name + "': this exception is not listed in nor " +
                                           "derived from any exception in this operation's specification";
                        p->unit()->warning(p->file(), p->line(), InvalidComment, msg);
                    }

                    // Check if this is a duplicate tag. If it is, ignore it and issue a warning.
                    if (comment._exceptions.count(name) != 0)
                    {
                        const string msg = "ignoring duplicate doc-comment tag: '" + actualTag + " " + name + "'";
                        p->unit()->warning(p->file(), p->line(), InvalidComment, msg);
                        currentSection = nullptr;
                    }
                    else
                    {
                        comment._exceptions[name] = {};
                        currentSection = &comment._exceptions[name];
                    }
                }
            }
        }
        else if (parseCommentLine(line, remarkTag, lineText) || parseCommentLine(line, remarksTag, lineText))
        {
            currentSection = &comment._remarks;
        }
        else if (parseCommentLine(line, seeTag, lineText))
        {
            currentSection = &comment._seeAlso;

            // Remove any leading and trailing whitespace from the line.
            // There's no concern of losing formatting for `@see` due to its simplicity.
            lineText = IceInternal::trim(lineText);
            if (lineText.empty())
            {
                const string msg = "missing link target after '" + seeTag + "' tag";
                p->unit()->warning(p->file(), p->line(), InvalidComment, msg);
            }
            else if (lineText.back() == '.')
            {
                // '@see' tags aren't allowed to end with periods.
                // They do not take sentences, and the trailing period will trip up some language's doc-comments.
                const string msg = "ignoring trailing '.' character in '" + seeTag + "' tag";
                p->unit()->warning(p->file(), p->line(), InvalidComment, msg);
                lineText.pop_back();
            }
        }
        else if (parseCommentLine(line, returnTag, lineText))
        {
            if (!operationTarget)
            {
                // If '@return' was put on anything other than an operation, ignore it and issue a warning.
                const string msg = "the '" + returnTag + "' tag is only valid on operations";
                p->unit()->warning(p->file(), p->line(), InvalidComment, msg);
                currentSection = nullptr;
            }
            else
            {
                if (!operationTarget->returnType())
                {
                    // If '@return' was applied to a void operation (one without a return-type), issue a warning.
                    const string msg = "'" + returnTag + "' is only valid on operations with non-void return types";
                    p->unit()->warning(p->file(), p->line(), InvalidComment, msg);
                }

                // Check if this is a duplicate tag. If it is, ignore it and issue a warning.
                if (!comment._returns.empty())
                {
                    const string msg = "ignoring duplicate doc-comment tag: '" + returnTag + "'";
                    p->unit()->warning(p->file(), p->line(), InvalidComment, msg);
                    currentSection = nullptr;
                }
                else
                {
                    currentSection = &comment._returns;
                }
            }
        }
        else if (parseCommentLine(line, deprecatedTag, lineText))
        {
            // Check if this is a duplicate tag (ie. multiple '@deprecated'). If it is, ignore it and issue a warning.
            if (comment._isDeprecated)
            {
                const string msg = "ignoring duplicate doc-comment tag: '" + deprecatedTag + "'";
                p->unit()->warning(p->file(), p->line(), InvalidComment, msg);
                currentSection = nullptr;
            }
            else
            {
                comment._isDeprecated = true;
                currentSection = &comment._deprecated;
            }
        }
        else // This line didn't introduce a new tag. Either we're in the overview or a tag whose content is multi-line.
        {
            if (!line.empty())
            {
                // We've encountered an unknown doc tag.
                if (line[0] == '@')
                {
                    auto unknownTag = line.substr(0, line.find_first_of(" \t:"));
                    const string msg = "ignoring unknown doc tag '" + unknownTag + "' in comment";
                    p->unit()->warning(p->file(), p->line(), InvalidComment, msg);
                    currentSection = nullptr;
                }

                // '@see' tags are not allowed to span multiple lines.
                if (currentSection == &comment._seeAlso)
                {
                    string msg = "'@see' tags cannot span multiple lines and must be of the form: '@see identifier'";
                    p->unit()->warning(p->file(), p->line(), InvalidComment, msg);
                    currentSection = nullptr;
                }
            }

            // Here we allow empty lines, since they could be used for formatting to separate lines.
            if (currentSection)
            {
                currentSection->push_back(line);
            }
            continue;
        }

        // Reaching here means that this line introduced a new tag. We reject empty lines to handle comments which
        // are formatted like: `@param myVeryCoolParam\nvery long explanation that\nspans multiple lines`.
        // We don't want an empty line at the top just because the user's content didn't start until the next line.
        if (currentSection && !lineText.empty())
        {
            currentSection->push_back(lineText);
        }
    }

    trimLines(comment._overview);
    trimLines(comment._remarks);
    trimLines(comment._deprecated);
    trimLines(comment._returns);

    return comment;
}
