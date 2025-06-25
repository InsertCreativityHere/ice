// Copyright (c) ZeroC, Inc.

#ifndef DOC_COMMENT_PARSER_H
#define DOC_COMMENT_PARSER_H

#include "Parser.h"

namespace Slice
{
    /// Visits all Slice definitions in the provided unit, and parses any doc comments that have been applied to them.
    void parseAllDocCommentsWithin(const UnitPtr& unit);
}

#endif
