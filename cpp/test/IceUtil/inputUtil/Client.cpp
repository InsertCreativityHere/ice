//
// Copyright (c) ZeroC, Inc. All rights reserved.
//

#include <IceUtil/InputUtil.h>
#include <IceUtil/StringUtil.h>
#include <IceUtil/Options.h>
#include <TestHelper.h>

#include <vector>

using namespace IceUtil;
using namespace IceUtilInternal;
using namespace std;

#define WS " \f\n\r\t\v"

class Client : public Test::TestHelper
{
public:

    virtual void run(int argc, char* argv[]);
};

void
Client::run(int, char**)
{
    cout << "testing string to command line arguments... " << flush;
    vector<string> args;

    test(IceUtilInternal::Options::split("").empty());

    args = IceUtilInternal::Options::split("\"\"");
    test(args.size() == 1 && args[0] == "");
    args = IceUtilInternal::Options::split("''");
    test(args.size() == 1 && args[0] == "");
    args = IceUtilInternal::Options::split("$''");
    test(args.size() == 1 && args[0] == "");

    args = IceUtilInternal::Options::split("-a -b -c");
    test(args.size() == 3 && args[0] == "-a" && args[1] == "-b" && args[2] == "-c");
    args = IceUtilInternal::Options::split("\"-a\" '-b' $'-c'");
    test(args.size() == 3 && args[0] == "-a" && args[1] == "-b" && args[2] == "-c");
    args = IceUtilInternal::Options::split("  '-b' \"-a\" $'-c' ");
    test(args.size() == 3 && args[0] == "-b" && args[1] == "-a" && args[2] == "-c");
    args = IceUtilInternal::Options::split(" $'-c' '-b' \"-a\"  ");
    test(args.size() == 3 && args[0] == "-c" && args[1] == "-b" && args[2] == "-a");

    // Testing single quote
    args = IceUtilInternal::Options::split("-Dir='C:\\\\test\\\\file'"); // -Dir='C:\\test\\file'
    test(args.size() == 1 && args[0] == "-Dir=C:\\\\test\\\\file"); // -Dir=C:\\test\\file
    args = IceUtilInternal::Options::split("-Dir='C:\\test\\file'"); // -Dir='C:\test\file'
    test(args.size() == 1 && args[0] == "-Dir=C:\\test\\file"); // -Dir=C:\test\file
    args = IceUtilInternal::Options::split("-Dir='C:\\test\\filewith\"quote'"); // -Dir='C:\test\filewith"quote'
    test(args.size() == 1 && args[0] == "-Dir=C:\\test\\filewith\"quote"); // -Dir=C:\test\filewith"quote

    // Testing double quote
    args = IceUtilInternal::Options::split("-Dir=\"C:\\\\test\\\\file\""); // -Dir="C:\\test\\file"
    test(args.size() == 1 && args[0] == "-Dir=C:\\test\\file"); // -Dir=C:\test\file
    args = IceUtilInternal::Options::split("-Dir=\"C:\\test\\file\""); // -Dir="C:\test\file"
    test(args.size() == 1 && args[0] == "-Dir=C:\\test\\file"); // -Dir=C:\test\file
    args = IceUtilInternal::Options::split("-Dir=\"C:\\test\\filewith\\\"quote\""); // -Dir="C:\test\filewith\"quote"
    test(args.size() == 1 && args[0] == "-Dir=C:\\test\\filewith\"quote"); // -Dir=C:\test\filewith"quote

    // Testing ANSI quote
    args = IceUtilInternal::Options::split("-Dir=$'C:\\\\test\\\\file'"); // -Dir=$'C:\\test\\file'
    test(args.size() == 1 && args[0] == "-Dir=C:\\test\\file"); // -Dir=C:\test\file
    args = IceUtilInternal::Options::split("-Dir=$'C:\\oest\\oile'"); // -Dir='C:\oest\oile'
    test(args.size() == 1 && args[0] == "-Dir=C:\\oest\\oile"); // -Dir=C:\oest\oile
    args = IceUtilInternal::Options::split("-Dir=$'C:\\oest\\oilewith\"quote'"); // -Dir=$'C:\oest\oilewith"quote'
    test(args.size() == 1 && args[0] == "-Dir=C:\\oest\\oilewith\"quote"); // -Dir=C:\oest\oilewith"quote
    args = IceUtilInternal::Options::split("-Dir=$'\\103\\072\\134\\164\\145\\163\\164\\134\\146\\151\\154\\145'");
    test(args.size() == 1 && args[0] == "-Dir=C:\\test\\file"); // -Dir=C:\test\file
    args = IceUtilInternal::Options::split("-Dir=$'\\x43\\x3A\\x5C\\x74\\x65\\x73\\x74\\x5C\\x66\\x69\\x6C\\x65'");
    test(args.size() == 1 && args[0] == "-Dir=C:\\test\\file"); // -Dir=C:\test\file
    args = IceUtilInternal::Options::split("-Dir=$'\\cM\\c_'"); // Control characters
    test(args.size() == 1 && args[0] == "-Dir=\015\037");
    args = IceUtilInternal::Options::split("-Dir=$'C:\\\\\\146\\x66\\cMi'"); // -Dir=$'C:\\\146\x66i\cMi'
    test(args.size() == 1 && args[0] == "-Dir=C:\\ff\015i");
    args = IceUtilInternal::Options::split("-Dir=$'C:\\\\\\cM\\x66\\146i'"); // -Dir=$'C:\\\cM\x66\146i'
    test(args.size() == 1 && args[0] == "-Dir=C:\\\015ffi");

    vector<string> badQuoteCommands;
    badQuoteCommands.push_back("\"");
    badQuoteCommands.push_back("'");
    badQuoteCommands.push_back("\\$'");
    badQuoteCommands.push_back("-Dir=\"test");
    badQuoteCommands.push_back("-Dir='test");
    badQuoteCommands.push_back("-Dir=$'test");
    for(vector<string>::const_iterator p = badQuoteCommands.begin(); p != badQuoteCommands.end(); ++p)
    {
        try
        {
            IceUtilInternal::Options::split(*p);
            test(false);
        }
        catch(const IceUtilInternal::BadOptException&)
        {
        }
    }
    cout << "ok" << endl;

    cout << "checking string splitting... " << flush;
    {
        vector<string> ss;
        test(IceUtilInternal::splitString("", "", ss) && ss.empty());
        ss.clear();
        test(IceUtilInternal::splitString("", ":", ss) && ss.empty());
        ss.clear();
        test(IceUtilInternal::splitString("a", "", ss) && ss.size() == 1 && ss[0] == "a");
        ss.clear();
        test(IceUtilInternal::splitString("a", ":", ss) && ss.size() == 1 && ss[0] == "a");
        ss.clear();
        test(IceUtilInternal::splitString("ab", "", ss) && ss.size() == 1 && ss[0] == "ab");
        ss.clear();
        test(IceUtilInternal::splitString("ab:", ":", ss) && ss.size() == 1 && ss[0] == "ab");
        ss.clear();
        test(IceUtilInternal::splitString(":ab", ":", ss) && ss.size() == 1 && ss[0] == "ab");
        ss.clear();
        test(IceUtilInternal::splitString("a:b", ":", ss) && ss.size() == 2 && ss[0] == "a" && ss[1] == "b");
        ss.clear();
        test(IceUtilInternal::splitString(":a:b:", ":", ss) && ss.size() == 2 && ss[0] == "a" && ss[1] == "b");
        ss.clear();

        test(IceUtilInternal::splitString("\"a\"", ":", ss) && ss.size() == 1 && ss[0] == "a");
        ss.clear();
        test(IceUtilInternal::splitString("\"a\":b", ":", ss) && ss.size() == 2 && ss[0] == "a" && ss[1] == "b");
        ss.clear();
        test(IceUtilInternal::splitString("\"a\":\"b\"", ":", ss) && ss.size() == 2 && ss[0] == "a" && ss[1] == "b");
        ss.clear();
        test(IceUtilInternal::splitString("\"a:b\"", ":", ss) && ss.size() == 1 && ss[0] == "a:b");
        ss.clear();
        test(IceUtilInternal::splitString("a=\"a:b\"", ":", ss) && ss.size() == 1 && ss[0] == "a=a:b");
        ss.clear();

        test(IceUtilInternal::splitString("'a'", ":", ss) && ss.size() == 1 && ss[0] == "a");
        ss.clear();
        test(IceUtilInternal::splitString("'\"a'", ":", ss) && ss.size() == 1 && ss[0] == "\"a");
        ss.clear();
        test(IceUtilInternal::splitString("\"'a\"", ":", ss) && ss.size() == 1 && ss[0] == "'a");
        ss.clear();

        test(IceUtilInternal::splitString("a\\'b", ":", ss) && ss.size() == 1 && ss[0] == "a'b");
        ss.clear();
        test(IceUtilInternal::splitString("'a:b\\'c'", ":", ss) && ss.size() == 1 && ss[0] == "a:b'c");
        ss.clear();
        test(IceUtilInternal::splitString("a\\\"b", ":", ss) && ss.size() == 1 && ss[0] == "a\"b");
        ss.clear();
        test(IceUtilInternal::splitString("\"a:b\\\"c\"", ":", ss) && ss.size() == 1 && ss[0] == "a:b\"c");
        ss.clear();
        test(IceUtilInternal::splitString("'a:b\"c'", ":", ss) && ss.size() == 1 && ss[0] == "a:b\"c");
        ss.clear();
        test(IceUtilInternal::splitString("\"a:b'c\"", ":", ss) && ss.size() == 1 && ss[0] == "a:b'c");
        ss.clear();
        test(!IceUtilInternal::splitString("a\"b", ":", ss));
    }
    cout << "ok" << endl;
}

DEFINE_TEST(Client)
