//
// Copyright (c) ZeroC, Inc. All rights reserved.
//

#include <IceUtil/InputUtil.h>
#include <stdlib.h>

using namespace std;
using namespace IceUtil;

namespace IceUtilInternal
{

bool
stringToInt64(const string& str, int64_t& result)
{
    size_t count = 0;
    try
    {
        result = stoll(str, &count);
        return count == str.length();
    }
    catch(const std::invalid_argument& e)
    {
        return false;
    }
    catch(const std::out_of_range& e)
    {
        return false;
    }
}

bool
stringToUInt64(const string& str, uint64_t result)
{
    size_t count = 0;
    try
    {
        result = stoull(str, &count);
        return count == str.length();
    }
    catch(const std::invalid_argument& e)
    {
        return false;
    }
    catch(const std::out_of_range& e)
    {
        return false;
    }
}

}
