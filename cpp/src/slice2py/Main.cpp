// **********************************************************************
//
// Copyright (c) 2003-2004 ZeroC, Inc. All rights reserved.
//
// This copy of Ice is licensed to you under the terms described in the
// ICE_LICENSE file included in this distribution.
//
// **********************************************************************

#include <Slice/Preprocessor.h>
#include <Slice/PythonUtil.h>

#include <fstream>

#include <sys/types.h>
#include <sys/stat.h>

#ifdef _WIN32
#include <direct.h>
#endif

#ifndef _WIN32
#include <unistd.h>
#endif

using namespace std;
using namespace Slice;
using namespace Slice::Python;

//
// For each Slice file Foo.ice we generate Foo_ice.py containing the Python
// mappings. Furthermore, for each Slice module M in Foo.ice, we create a
// Python package of the same name. This package is simply a subdirectory
// containing the special file "__init__.py" that is executed when a Python
// script executes the statement "import M".
//
// Inside __init__.py we add an import statement for Foo_ice, causing
// Foo_ice to be imported implicitly when M is imported.
// 
// Of course, another Slice file Bar.ice may contain definitions for the
// same Slice module M, in which case the __init__.py file for M is modified
// to contain an additional import statement for Bar_ice. Therefore a
// Python script executing "import M" implicitly imports the definitions
// from both Foo_ice and Bar_ice.
//
// The __init__.py file also contains import statements for submodules,
// so that importing the top-level module automatically imports all of
// its submodules.
//
// The PackageVisitor class creates the directory hierarchy to mirror the
// Slice module hierarchy, and updates the __init__.py files as necessary.
//
class PackageVisitor : public ParserVisitor
{
public:

    PackageVisitor(const string&, const string&, const string&);

    virtual bool visitModuleStart(const ModulePtr&);
    virtual void visitModuleEnd(const ModulePtr&);

private:

    enum ReadState { PreModules, InModules, InSubmodules };

    static const char* _moduleTag;
    static const char* _submoduleTag;

    bool readInit(const string&, StringList&, StringList&);
    bool writeInit(const string&, const StringList&, const StringList&);

    string _name;
    string _module;
    StringList _pathStack;
};

const char* PackageVisitor::_moduleTag = "# Modules:";
const char* PackageVisitor::_submoduleTag = "# Submodules:";

PackageVisitor::PackageVisitor(const string& name, const string& module, const string& dir) :
    _name(name), _module(module)
{
    if(dir.empty())
    {
        _pathStack.push_front(".");
    }
    else
    {
        _pathStack.push_front(dir);
    }
}

bool
PackageVisitor::visitModuleStart(const ModulePtr& p)
{
    assert(!_pathStack.empty());
    string name = fixIdent(p->name());
    string path = _pathStack.front() + "/" + name;
    string parentPath = _pathStack.front();
    _pathStack.push_front(path);

    struct stat st;
    int result;
    result = stat(path.c_str(), &st);
    if(result != 0)
    {
#ifdef _WIN32
        result = _mkdir(path.c_str());
#else       
        result = mkdir(path.c_str(), S_IRWXU | S_IRWXG | S_IRWXO);
#endif

        if(result != 0)
        {
            cerr << _name << ": unable to create `" << path << "': " << strerror(errno) << endl;
            return false;
        }
    }

    //
    // If necessary, add this file to the set of imported modules in __init__.py.
    //
    StringList modules, submodules;
    if(readInit(path, modules, submodules))
    {
        StringList::iterator p;
        p = find(modules.begin(), modules.end(), _module);
        if(p == modules.end())
        {
            modules.push_back(_module);
            writeInit(path, modules, submodules);
        }
    }

    //
    // If this is a submodule, then modify the parent's __init__.py to import us.
    //
    ModulePtr mod = ModulePtr::dynamicCast(p->container());
    if(mod)
    {
        modules.clear();
        submodules.clear();
        if(readInit(parentPath, modules, submodules))
        {
            StringList::iterator p;
            p = find(submodules.begin(), submodules.end(), name);
            if(p == submodules.end())
            {
                submodules.push_back(name);
                writeInit(parentPath, modules, submodules);
            }
        }
    }

    return true;
}

void
PackageVisitor::visitModuleEnd(const ModulePtr& p)
{
    assert(!_pathStack.empty());
    _pathStack.pop_front();
}

bool
PackageVisitor::readInit(const string& dir, StringList& modules, StringList& submodules)
{
    string initPath = dir + "/__init__.py";

    struct stat st;
    if(stat(initPath.c_str(), &st) == 0)
    {
        ifstream in(initPath.c_str());
        if(!in)
        {
            cerr << _name << ": unable to open `" << initPath << "': " << strerror(errno) << endl;
            return false;
        }

        ReadState state = PreModules;
        char line[1024];
        while(in.getline(line, 1024))
        {
            string s = line;
            if(s.find(_moduleTag) == 0)
            {
                if(state != PreModules)
                {
                    break;
                }
                state = InModules;
            }
            else if(s.find(_submoduleTag) == 0)
            {
                if(state != InModules)
                {
                    break;
                }
                state = InSubmodules;
            }
            else if(s.find("import") == 0)
            {
                if(state == PreModules)
                {
                    break;
                }

                if(s.size() < 8)
                {
                    cerr << _name << ": invalid line `" << s << "' in `" << initPath << "'" << endl;
                    return false;
                }

                string name = s.substr(7);
                if(state == InModules)
                {
                    modules.push_back(name);
                }
                else
                {
                    submodules.push_back(name);
                }
            }
        }

        if(state != InSubmodules)
        {
            cerr << _name << ": invalid format in `" << initPath << "'" << endl;
            return false;
        }
    }

    return true;
}

bool
PackageVisitor::writeInit(const string& dir, const StringList& modules, const StringList& submodules)
{
    string initPath = dir + "/__init__.py";

    ofstream os(initPath.c_str());
    if(!os)
    {
        return false;
    }

    StringList::const_iterator p;

    os << "# Generated by slice2py - DO NOT EDIT!" << endl
       << "#" << endl
       << _moduleTag << endl;
    for(p = modules.begin(); p != modules.end(); ++p)
    {
        os << "import " << *p << endl;
    }

    os << endl;
    os << _submoduleTag << endl;
    for(p = submodules.begin(); p != submodules.end(); ++p)
    {
        os << "import " << *p << endl;
    }

    return true;
}

void
usage(const char* n)
{
    cerr << "Usage: " << n << " [options] slice-files...\n";
    cerr <<        
        "Options:\n"
        "-h, --help           Show this message.\n"
        "-v, --version        Display the Ice version.\n"
        "-DNAME               Define NAME as 1.\n"
        "-DNAME=DEF           Define NAME as DEF.\n"
        "-UNAME               Remove any definition for NAME.\n"
        "-IDIR                Put DIR in the include file search path.\n"
        "--output-dir DIR     Create files in the directory DIR.\n"
        "-d, --debug          Print debug messages.\n"
        "--ice                Permit `Ice' prefix (for building Ice source code only)\n"
        "--all                Generate code for Slice definitions in included files.\n"
        "--no-package         Do not create Python packages.\n"
        "--checksum           Generate checksums for Slice definitions.\n"
        "--prefix PREFIX      Prepend filenames of Python modules with PREFIX.\n"
        ;
    // Note: --case-sensitive is intentionally not shown here!
}

int
main(int argc, char* argv[])
{
    string cppArgs;
    vector<string> includePaths;
    string output;
    bool debug = false;
    bool ice = false;
    bool caseSensitive = false;
    bool all = false;
    bool noPackage = false;
    bool checksum = false;
    string prefix;

    int idx = 1;
    while(idx < argc)
    {
        if(strncmp(argv[idx], "-I", 2) == 0)
        {
            cppArgs += ' ';
            cppArgs += argv[idx];

            string path = argv[idx] + 2;
            if(path.length())
            {
                includePaths.push_back(path);
            }

            for(int i = idx ; i + 1 < argc ; ++i)
            {
                argv[i] = argv[i + 1];
            }
            --argc;
        }
        else if(strncmp(argv[idx], "-D", 2) == 0 || strncmp(argv[idx], "-U", 2) == 0)
        {
            cppArgs += ' ';
            cppArgs += argv[idx];

            for(int i = idx ; i + 1 < argc ; ++i)
            {
                argv[i] = argv[i + 1];
            }
            --argc;
        }
        else if(strcmp(argv[idx], "-h") == 0 || strcmp(argv[idx], "--help") == 0)
        {
            usage(argv[0]);
            return EXIT_SUCCESS;
        }
        else if(strcmp(argv[idx], "-v") == 0 || strcmp(argv[idx], "--version") == 0)
        {
            cout << ICE_STRING_VERSION << endl;
            return EXIT_SUCCESS;
        }
        else if(strcmp(argv[idx], "--output-dir") == 0)
        {
            if(idx + 1 >= argc)
            {
                cerr << argv[0] << ": argument expected for`" << argv[idx] << "'" << endl;
                usage(argv[0]);
                return EXIT_FAILURE;
            }

            output = argv[idx + 1];
            for(int i = idx ; i + 2 < argc ; ++i)
            {
                argv[i] = argv[i + 2];
            }
            argc -= 2;
        }
        else if(strcmp(argv[idx], "-d") == 0 || strcmp(argv[idx], "--debug") == 0)
        {
            debug = true;
            for(int i = idx ; i + 1 < argc ; ++i)
            {
                argv[i] = argv[i + 1];
            }
            --argc;
        }
        else if(strcmp(argv[idx], "--ice") == 0)
        {
            ice = true;
            for(int i = idx ; i + 1 < argc ; ++i)
            {
                argv[i] = argv[i + 1];
            }
            --argc;
        }
        else if(strcmp(argv[idx], "--case-sensitive") == 0)
        {
            caseSensitive = true;
            for(int i = idx ; i + 1 < argc ; ++i)
            {
                argv[i] = argv[i + 1];
            }
            --argc;
        }
        else if(strcmp(argv[idx], "--all") == 0)
        {
            all = true;
            for(int i = idx ; i + 1 < argc ; ++i)
            {
                argv[i] = argv[i + 1];
            }
            --argc;
        }
        else if(strcmp(argv[idx], "--no-package") == 0)
        {
            noPackage = true;
            for(int i = idx ; i + 1 < argc ; ++i)
            {
                argv[i] = argv[i + 1];
            }
            --argc;
        }
        else if(strcmp(argv[idx], "--checksum") == 0)
        {
            checksum = true;
            for(int i = idx ; i + 1 < argc ; ++i)
            {
                argv[i] = argv[i + 1];
            }
            --argc;
        }
        else if(strcmp(argv[idx], "--prefix") == 0)
        {
            if(idx + 1 >= argc)
            {
                cerr << argv[0] << ": argument expected for`" << argv[idx] << "'" << endl;
                usage(argv[0]);
                return EXIT_FAILURE;
            }

            prefix = argv[idx + 1];
            for(int i = idx ; i + 2 < argc ; ++i)
            {
                argv[i] = argv[i + 2];
            }
            argc -= 2;
        }
        else if(argv[idx][0] == '-')
        {
            cerr << argv[0] << ": unknown option `" << argv[idx] << "'" << endl;
            usage(argv[0]);
            return EXIT_FAILURE;
        }
        else
        {
            ++idx;
        }
    }

    if(argc < 2)
    {
        cerr << argv[0] << ": no input file" << endl;
        usage(argv[0]);
        return EXIT_FAILURE;
    }

    int status = EXIT_SUCCESS;

    for(idx = 1 ; idx < argc ; ++idx)
    {
        Preprocessor icecpp(argv[0], argv[idx], cppArgs);
        FILE* cppHandle = icecpp.preprocess(false);

        if(cppHandle == 0)
        {
            return EXIT_FAILURE;
        }

        UnitPtr u = Unit::createUnit(false, all, ice, caseSensitive);
        int parseStatus = u->parse(cppHandle, debug);

        if(!icecpp.close())
        {
            u->destroy();
            return EXIT_FAILURE;
        }

        if(parseStatus == EXIT_FAILURE)
        {
            status = EXIT_FAILURE;
        }
        else
        {
            string base = icecpp.getBaseName();
            string::size_type pos = base.rfind('/');
            if(pos != string::npos)
            {
                base.erase(0, pos + 1);
            }

            //
            // Append the suffix "_ice" to the filename in order to avoid any conflicts
            // with Slice module names. For example, if the file Test.ice defines a
            // Slice module named "Test", then we couldn't create a Python package named
            // "Test" and also call the generated file "Test.py".
            //
            string file = prefix + base + "_ice.py";
            if(!output.empty())
            {
                file = output + '/' + file;
            }

            IceUtil::Output out;
            out.setUseTab(false);
            out.open(file.c_str());
            if(!out)
            {
                cerr << argv[0] << ": can't open `" << file << "' for writing" << endl;
                u->destroy();
                return EXIT_FAILURE;
            }

            printHeader(out);
            out << "\n# Generated from file `" << base << ".ice'\n";

            //
            // Generate the Python mapping.
            //
            generate(u, all, checksum, includePaths, out);

            //
            // Create or update the Python package hierarchy.
            //
            if(!noPackage)
            {
                PackageVisitor visitor(argv[0], prefix + base + "_ice", output);
                u->visit(&visitor, false);
            }
        }

        u->destroy();
    }

    return status;
}
