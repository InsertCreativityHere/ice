/* A Bison parser, made by GNU Bison 3.7.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30704

/* Bison version string.  */
#define YYBISON_VERSION "3.7.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 1

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* "%code top" blocks.  */
#line 1 "src/Slice/Grammar.y"


//
// Copyright (c) ZeroC, Inc. All rights reserved.
//

// Included first to get 'TokenContext' which we need to define YYLTYPE before flex does.
#include <Slice/GrammarUtil.h>

#line 30 "src/Slice/Grammar.y"


// Defines the rule bison uses to reduce token locations. Bison asks that the macro should
// be one-line, and treatable as a single statement when followed by a semi-colon.
// `N` is the number of tokens that are being combined, and (Cur) is their combined location.
#define YYLLOC_DEFAULT(Cur, Rhs, N)                               \
do                                                                \
    if(N == 1)                                                    \
    {                                                             \
        (Cur) = (YYRHSLOC((Rhs), 1));                             \
    }                                                             \
    else                                                          \
    {                                                             \
        if(N)                                                     \
        {                                                         \
            (Cur).firstLine = (YYRHSLOC((Rhs), 1)).firstLine;     \
            (Cur).firstColumn = (YYRHSLOC((Rhs), 1)).firstColumn; \
        }                                                         \
        else                                                      \
        {                                                         \
            (Cur).firstLine = (YYRHSLOC((Rhs), 0)).lastLine;      \
            (Cur).firstColumn = (YYRHSLOC((Rhs), 0)).lastColumn;  \
        }                                                         \
        (Cur).filename = (YYRHSLOC((Rhs), N)).filename;           \
        (Cur).lastLine = (YYRHSLOC((Rhs), N)).lastLine;           \
        (Cur).lastColumn = (YYRHSLOC((Rhs), N)).lastColumn;       \
    }                                                             \
while(0)


#line 109 "src/Slice/Grammar.cpp"

/* Substitute the variable and function names.  */
#define yyparse         slice_parse
#define yylex           slice_lex
#define yyerror         slice_error
#define yydebug         slice_debug
#define yynerrs         slice_nerrs

/* First part of user prologue.  */
#line 69 "src/Slice/Grammar.y"


#include <IceUtil/InputUtil.h>
#include <IceUtil/UUID.h>
#include <cstring>

#ifdef _MSC_VER
// warning C4102: 'yyoverflowlab' : unreferenced label
#   pragma warning(disable:4102)
// warning C4065: switch statement contains 'default' but no 'case' labels
#   pragma warning(disable:4065)
// warning C4244: '=': conversion from 'int' to 'yytype_int16', possible loss of data
#   pragma warning(disable:4244)
// warning C4127: conditional expression is constant
#   pragma warning(disable:4127)
#endif

// Avoid old style cast warnings in generated grammar
#ifdef __GNUC__
#  pragma GCC diagnostic ignored "-Wold-style-cast"
#endif

// Avoid clang conversion warnings
#if defined(__clang__)
#   pragma clang diagnostic ignored "-Wconversion"
#   pragma clang diagnostic ignored "-Wsign-conversion"
#endif

using namespace std;
using namespace Slice;

void
slice_error(const char* s)
{
    // yacc and recent versions of Bison use "syntax error" instead
    // of "parse error".

    if (strcmp(s, "parse error") == 0)
    {
        unit->error("syntax error");
    }
    else
    {
        unit->error(s);
    }
}

// TODO this function is only temporarily necessary to convert between the old and new syntax styles.
void convertMetadata(StringListTokPtr& metadata)
{
    for (auto& m : metadata->v)
    {
        auto pos = m.find('(');
        if (pos != string::npos)
        {
            m[pos] = ':';
            assert(m.back() == ')');
            m.pop_back();
        }
    }
}

const int QUALIFIER_NONE = 0;
const int QUALIFIER_OUT = 1;
const int QUALIFIER_STREAM = 2;


#line 187 "src/Slice/Grammar.cpp"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "Grammar.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_ICE_MODULE = 3,                 /* ICE_MODULE  */
  YYSYMBOL_ICE_CLASS = 4,                  /* ICE_CLASS  */
  YYSYMBOL_ICE_INTERFACE = 5,              /* ICE_INTERFACE  */
  YYSYMBOL_ICE_EXCEPTION = 6,              /* ICE_EXCEPTION  */
  YYSYMBOL_ICE_STRUCT = 7,                 /* ICE_STRUCT  */
<<<<<<< HEAD
  YYSYMBOL_ICE_SEQUENCE = 8,               /* ICE_SEQUENCE  */
  YYSYMBOL_ICE_DICTIONARY = 9,             /* ICE_DICTIONARY  */
  YYSYMBOL_ICE_ENUM = 10,                  /* ICE_ENUM  */
  YYSYMBOL_ICE_OUT = 11,                   /* ICE_OUT  */
  YYSYMBOL_ICE_STREAM = 12,                /* ICE_STREAM  */
=======
  YYSYMBOL_ICE_USING = 8,                  /* ICE_USING  */
  YYSYMBOL_ICE_SEQUENCE = 9,               /* ICE_SEQUENCE  */
  YYSYMBOL_ICE_DICTIONARY = 10,            /* ICE_DICTIONARY  */
  YYSYMBOL_ICE_ENUM = 11,                  /* ICE_ENUM  */
  YYSYMBOL_ICE_OUT = 12,                   /* ICE_OUT  */
>>>>>>> Regenerated compilers, and fixed build errors.
  YYSYMBOL_ICE_EXTENDS = 13,               /* ICE_EXTENDS  */
  YYSYMBOL_ICE_IMPLEMENTS = 14,            /* ICE_IMPLEMENTS  */
  YYSYMBOL_ICE_THROWS = 15,                /* ICE_THROWS  */
  YYSYMBOL_ICE_VOID = 16,                  /* ICE_VOID  */
  YYSYMBOL_ICE_BOOL = 17,                  /* ICE_BOOL  */
  YYSYMBOL_ICE_BYTE = 18,                  /* ICE_BYTE  */
  YYSYMBOL_ICE_SHORT = 19,                 /* ICE_SHORT  */
  YYSYMBOL_ICE_USHORT = 20,                /* ICE_USHORT  */
  YYSYMBOL_ICE_INT = 21,                   /* ICE_INT  */
  YYSYMBOL_ICE_UINT = 22,                  /* ICE_UINT  */
  YYSYMBOL_ICE_VARINT = 23,                /* ICE_VARINT  */
  YYSYMBOL_ICE_VARUINT = 24,               /* ICE_VARUINT  */
  YYSYMBOL_ICE_LONG = 25,                  /* ICE_LONG  */
  YYSYMBOL_ICE_ULONG = 26,                 /* ICE_ULONG  */
  YYSYMBOL_ICE_VARLONG = 27,               /* ICE_VARLONG  */
  YYSYMBOL_ICE_VARULONG = 28,              /* ICE_VARULONG  */
  YYSYMBOL_ICE_FLOAT = 29,                 /* ICE_FLOAT  */
  YYSYMBOL_ICE_DOUBLE = 30,                /* ICE_DOUBLE  */
  YYSYMBOL_ICE_STRING = 31,                /* ICE_STRING  */
  YYSYMBOL_ICE_OBJECT = 32,                /* ICE_OBJECT  */
  YYSYMBOL_ICE_CONST = 33,                 /* ICE_CONST  */
  YYSYMBOL_ICE_FALSE = 34,                 /* ICE_FALSE  */
  YYSYMBOL_ICE_TRUE = 35,                  /* ICE_TRUE  */
  YYSYMBOL_ICE_IDEMPOTENT = 36,            /* ICE_IDEMPOTENT  */
  YYSYMBOL_ICE_TAG = 37,                   /* ICE_TAG  */
  YYSYMBOL_ICE_OPTIONAL = 38,              /* ICE_OPTIONAL  */
  YYSYMBOL_ICE_ANYCLASS = 39,              /* ICE_ANYCLASS  */
  YYSYMBOL_ICE_VALUE = 40,                 /* ICE_VALUE  */
  YYSYMBOL_ICE_UNCHECKED = 41,             /* ICE_UNCHECKED  */
  YYSYMBOL_ICE_STRING_LITERAL = 42,        /* ICE_STRING_LITERAL  */
  YYSYMBOL_ICE_INTEGER_LITERAL = 43,       /* ICE_INTEGER_LITERAL  */
  YYSYMBOL_ICE_FLOATING_POINT_LITERAL = 44, /* ICE_FLOATING_POINT_LITERAL  */
  YYSYMBOL_ICE_IDENTIFIER = 45,            /* ICE_IDENTIFIER  */
  YYSYMBOL_ICE_SCOPED_IDENTIFIER = 46,     /* ICE_SCOPED_IDENTIFIER  */
  YYSYMBOL_ICE_LOCAL_METADATA_OPEN = 47,   /* ICE_LOCAL_METADATA_OPEN  */
  YYSYMBOL_ICE_LOCAL_METADATA_CLOSE = 48,  /* ICE_LOCAL_METADATA_CLOSE  */
  YYSYMBOL_ICE_FILE_METADATA_OPEN = 49,    /* ICE_FILE_METADATA_OPEN  */
  YYSYMBOL_ICE_FILE_METADATA_CLOSE = 50,   /* ICE_FILE_METADATA_CLOSE  */
  YYSYMBOL_BAD_CHAR = 51,                  /* BAD_CHAR  */
  YYSYMBOL_52_ = 52,                       /* ';'  */
  YYSYMBOL_53_ = 53,                       /* '{'  */
  YYSYMBOL_54_ = 54,                       /* '}'  */
  YYSYMBOL_55_ = 55,                       /* '('  */
  YYSYMBOL_56_ = 56,                       /* ')'  */
  YYSYMBOL_57_ = 57,                       /* ':'  */
  YYSYMBOL_58_ = 58,                       /* '='  */
  YYSYMBOL_59_ = 59,                       /* ','  */
  YYSYMBOL_60_ = 60,                       /* '<'  */
  YYSYMBOL_61_ = 61,                       /* '>'  */
  YYSYMBOL_62_ = 62,                       /* '*'  */
  YYSYMBOL_63_ = 63,                       /* '?'  */
  YYSYMBOL_YYACCEPT = 64,                  /* $accept  */
  YYSYMBOL_start = 65,                     /* start  */
  YYSYMBOL_opt_semicolon = 66,             /* opt_semicolon  */
  YYSYMBOL_file_metadata = 67,             /* file_metadata  */
  YYSYMBOL_local_metadata = 68,            /* local_metadata  */
  YYSYMBOL_definitions = 69,               /* definitions  */
  YYSYMBOL_definition = 70,                /* definition  */
  YYSYMBOL_71_1 = 71,                      /* $@1  */
  YYSYMBOL_72_2 = 72,                      /* $@2  */
  YYSYMBOL_73_3 = 73,                      /* $@3  */
  YYSYMBOL_74_4 = 74,                      /* $@4  */
  YYSYMBOL_75_5 = 75,                      /* $@5  */
  YYSYMBOL_76_6 = 76,                      /* $@6  */
  YYSYMBOL_77_7 = 77,                      /* $@7  */
  YYSYMBOL_78_8 = 78,                      /* $@8  */
  YYSYMBOL_79_9 = 79,                      /* $@9  */
  YYSYMBOL_80_10 = 80,                     /* $@10  */
  YYSYMBOL_81_11 = 81,                     /* $@11  */
  YYSYMBOL_82_12 = 82,                     /* $@12  */
  YYSYMBOL_83_13 = 83,                     /* $@13  */
<<<<<<< HEAD
  YYSYMBOL_module_def = 84,                /* module_def  */
  YYSYMBOL_85_14 = 85,                     /* @14  */
  YYSYMBOL_86_15 = 86,                     /* @15  */
  YYSYMBOL_exception_id = 87,              /* exception_id  */
  YYSYMBOL_exception_decl = 88,            /* exception_decl  */
  YYSYMBOL_exception_def = 89,             /* exception_def  */
  YYSYMBOL_90_16 = 90,                     /* @16  */
  YYSYMBOL_exception_extends = 91,         /* exception_extends  */
  YYSYMBOL_tag = 92,                       /* tag  */
  YYSYMBOL_optional = 93,                  /* optional  */
  YYSYMBOL_struct_id = 94,                 /* struct_id  */
  YYSYMBOL_struct_decl = 95,               /* struct_decl  */
  YYSYMBOL_struct_def = 96,                /* struct_def  */
  YYSYMBOL_97_17 = 97,                     /* @17  */
  YYSYMBOL_class_name = 98,                /* class_name  */
  YYSYMBOL_class_id = 99,                  /* class_id  */
  YYSYMBOL_class_decl = 100,               /* class_decl  */
  YYSYMBOL_class_def = 101,                /* class_def  */
  YYSYMBOL_102_18 = 102,                   /* @18  */
  YYSYMBOL_class_extends = 103,            /* class_extends  */
  YYSYMBOL_extends = 104,                  /* extends  */
  YYSYMBOL_data_member = 105,              /* data_member  */
  YYSYMBOL_data_member_list = 106,         /* data_member_list  */
  YYSYMBOL_data_members = 107,             /* data_members  */
  YYSYMBOL_return_tuple = 108,             /* return_tuple  */
  YYSYMBOL_return_type = 109,              /* return_type  */
  YYSYMBOL_operation_preamble = 110,       /* operation_preamble  */
  YYSYMBOL_operation = 111,                /* operation  */
  YYSYMBOL_112_19 = 112,                   /* @19  */
  YYSYMBOL_113_20 = 113,                   /* @20  */
  YYSYMBOL_operation_list = 114,           /* operation_list  */
  YYSYMBOL_interface_id = 115,             /* interface_id  */
  YYSYMBOL_interface_decl = 116,           /* interface_decl  */
  YYSYMBOL_interface_def = 117,            /* interface_def  */
  YYSYMBOL_118_21 = 118,                   /* @21  */
  YYSYMBOL_interface_list = 119,           /* interface_list  */
  YYSYMBOL_interface_extends = 120,        /* interface_extends  */
  YYSYMBOL_exception_list = 121,           /* exception_list  */
  YYSYMBOL_exception = 122,                /* exception  */
  YYSYMBOL_sequence_def = 123,             /* sequence_def  */
  YYSYMBOL_dictionary_def = 124,           /* dictionary_def  */
  YYSYMBOL_enum_start = 125,               /* enum_start  */
  YYSYMBOL_enum_id = 126,                  /* enum_id  */
  YYSYMBOL_enum_def = 127,                 /* enum_def  */
  YYSYMBOL_128_22 = 128,                   /* @22  */
  YYSYMBOL_129_23 = 129,                   /* @23  */
  YYSYMBOL_enum_underlying = 130,          /* enum_underlying  */
  YYSYMBOL_enumerator_list_or_empty = 131, /* enumerator_list_or_empty  */
  YYSYMBOL_enumerator_list = 132,          /* enumerator_list  */
  YYSYMBOL_enumerator = 133,               /* enumerator  */
  YYSYMBOL_enumerator_initializer = 134,   /* enumerator_initializer  */
  YYSYMBOL_qualifier = 135,                /* qualifier  */
  YYSYMBOL_parameter = 136,                /* parameter  */
  YYSYMBOL_parameter_list = 137,           /* parameter_list  */
  YYSYMBOL_parameters = 138,               /* parameters  */
  YYSYMBOL_throws = 139,                   /* throws  */
  YYSYMBOL_scoped_name = 140,              /* scoped_name  */
  YYSYMBOL_unscoped_name = 141,            /* unscoped_name  */
  YYSYMBOL_builtin = 142,                  /* builtin  */
  YYSYMBOL_type = 143,                     /* type  */
  YYSYMBOL_tagged_type = 144,              /* tagged_type  */
  YYSYMBOL_member = 145,                   /* member  */
  YYSYMBOL_string_literal = 146,           /* string_literal  */
  YYSYMBOL_string_list = 147,              /* string_list  */
  YYSYMBOL_const_initializer = 148,        /* const_initializer  */
  YYSYMBOL_const_def = 149,                /* const_def  */
  YYSYMBOL_keyword = 150                   /* keyword  */
=======
  YYSYMBOL_84_14 = 84,                     /* $@14  */
  YYSYMBOL_module_def = 85,                /* module_def  */
  YYSYMBOL_86_15 = 86,                     /* @15  */
  YYSYMBOL_87_16 = 87,                     /* @16  */
  YYSYMBOL_exception_id = 88,              /* exception_id  */
  YYSYMBOL_exception_decl = 89,            /* exception_decl  */
  YYSYMBOL_exception_def = 90,             /* exception_def  */
  YYSYMBOL_91_17 = 91,                     /* @17  */
  YYSYMBOL_exception_extends = 92,         /* exception_extends  */
  YYSYMBOL_tag = 93,                       /* tag  */
  YYSYMBOL_optional = 94,                  /* optional  */
  YYSYMBOL_struct_id = 95,                 /* struct_id  */
  YYSYMBOL_struct_decl = 96,               /* struct_decl  */
  YYSYMBOL_struct_def = 97,                /* struct_def  */
  YYSYMBOL_98_18 = 98,                     /* @18  */
  YYSYMBOL_class_name = 99,                /* class_name  */
  YYSYMBOL_class_id = 100,                 /* class_id  */
  YYSYMBOL_class_decl = 101,               /* class_decl  */
  YYSYMBOL_class_def = 102,                /* class_def  */
  YYSYMBOL_103_19 = 103,                   /* @19  */
  YYSYMBOL_class_extends = 104,            /* class_extends  */
  YYSYMBOL_extends = 105,                  /* extends  */
  YYSYMBOL_data_member = 106,              /* data_member  */
  YYSYMBOL_data_member_list = 107,         /* data_member_list  */
  YYSYMBOL_data_members = 108,             /* data_members  */
  YYSYMBOL_return_tuple = 109,             /* return_tuple  */
  YYSYMBOL_return_type = 110,              /* return_type  */
  YYSYMBOL_operation_preamble = 111,       /* operation_preamble  */
  YYSYMBOL_operation = 112,                /* operation  */
  YYSYMBOL_113_20 = 113,                   /* @20  */
  YYSYMBOL_114_21 = 114,                   /* @21  */
  YYSYMBOL_operation_list = 115,           /* operation_list  */
  YYSYMBOL_interface_id = 116,             /* interface_id  */
  YYSYMBOL_interface_decl = 117,           /* interface_decl  */
  YYSYMBOL_interface_def = 118,            /* interface_def  */
  YYSYMBOL_119_22 = 119,                   /* @22  */
  YYSYMBOL_interface_list = 120,           /* interface_list  */
  YYSYMBOL_interface_extends = 121,        /* interface_extends  */
  YYSYMBOL_exception_list = 122,           /* exception_list  */
  YYSYMBOL_exception = 123,                /* exception  */
  YYSYMBOL_type_alias_def = 124,           /* type_alias_def  */
  YYSYMBOL_sequence_def = 125,             /* sequence_def  */
  YYSYMBOL_dictionary_def = 126,           /* dictionary_def  */
  YYSYMBOL_enum_start = 127,               /* enum_start  */
  YYSYMBOL_enum_id = 128,                  /* enum_id  */
  YYSYMBOL_enum_def = 129,                 /* enum_def  */
  YYSYMBOL_130_23 = 130,                   /* @23  */
  YYSYMBOL_131_24 = 131,                   /* @24  */
  YYSYMBOL_enum_underlying = 132,          /* enum_underlying  */
  YYSYMBOL_enumerator_list_or_empty = 133, /* enumerator_list_or_empty  */
  YYSYMBOL_enumerator_list = 134,          /* enumerator_list  */
  YYSYMBOL_enumerator = 135,               /* enumerator  */
  YYSYMBOL_enumerator_initializer = 136,   /* enumerator_initializer  */
  YYSYMBOL_out_qualifier = 137,            /* out_qualifier  */
  YYSYMBOL_parameter = 138,                /* parameter  */
  YYSYMBOL_parameter_list = 139,           /* parameter_list  */
  YYSYMBOL_parameters = 140,               /* parameters  */
  YYSYMBOL_throws = 141,                   /* throws  */
  YYSYMBOL_scoped_name = 142,              /* scoped_name  */
  YYSYMBOL_unscoped_name = 143,            /* unscoped_name  */
  YYSYMBOL_builtin = 144,                  /* builtin  */
  YYSYMBOL_type = 145,                     /* type  */
  YYSYMBOL_tagged_type = 146,              /* tagged_type  */
  YYSYMBOL_member = 147,                   /* member  */
  YYSYMBOL_string_literal = 148,           /* string_literal  */
  YYSYMBOL_string_list = 149,              /* string_list  */
  YYSYMBOL_const_initializer = 150,        /* const_initializer  */
  YYSYMBOL_const_def = 151,                /* const_def  */
  YYSYMBOL_keyword = 152                   /* keyword  */
>>>>>>> Regenerated compilers, and fixed build errors.
};
typedef enum yysymbol_kind_t yysymbol_kind_t;



/* Unqualified %code blocks.  */
#line 61 "src/Slice/Grammar.y"


// Forward declaration of the lexing function generated by flex, so bison knows about it.
// This must match the definition of 'yylex' (or 'slice_lex') in the generated scanner.
int slice_lex(YYSTYPE* lvalp, YYLTYPE* llocp);


<<<<<<< HEAD
#line 380 "src/Slice/Grammar.cpp"
=======
#line 378 "src/Slice/Grammar.cpp"
>>>>>>> Regenerated compilers, and fixed build errors.

#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int16 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if !defined yyoverflow

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* !defined yyoverflow */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
             && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE) \
             + YYSIZEOF (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
#define YYLAST   1062
=======
#define YYLAST   1109
>>>>>>> Regenerated compilers, and fixed build errors.
=======
#define YYLAST   1121
>>>>>>> Added support for type-alias metadata.
=======
#define YYLAST   1151
>>>>>>> Added better error handling logic to the parser.
=======
#define YYLAST   1080
>>>>>>> More cosmetic changes.

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  64
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  89
/* YYNRULES -- Number of rules.  */
<<<<<<< HEAD
<<<<<<< HEAD
#define YYNRULES  247
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  351
=======
#define YYNRULES  248
/* YYNSTATES -- Number of states.  */
<<<<<<< HEAD
#define YYNSTATES  353
>>>>>>> Regenerated compilers, and fixed build errors.
=======
#define YYNSTATES  354
>>>>>>> Added support for type-alias metadata.
=======
#define YYNRULES  249
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  355
>>>>>>> Added better error handling logic to the parser.

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   306


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      55,    56,    62,     2,    59,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    57,    52,
      60,    58,    61,    63,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    53,     2,    54,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
<<<<<<< HEAD
       0,   208,   208,   214,   215,   221,   232,   238,   247,   256,
     264,   273,   280,   279,   285,   284,   289,   294,   293,   299,
     298,   303,   308,   307,   313,   312,   317,   322,   321,   327,
     326,   331,   336,   335,   341,   340,   345,   350,   349,   354,
     359,   358,   364,   363,   368,   372,   382,   381,   420,   419,
     497,   501,   512,   523,   522,   548,   556,   565,   583,   657,
     663,   674,   696,   774,   784,   799,   803,   814,   825,   824,
     865,   869,   880,   905,   995,  1007,  1020,  1019,  1053,  1087,
    1096,  1097,  1103,  1118,  1140,  1141,  1142,  1146,  1152,  1153,
    1159,  1176,  1197,  1222,  1231,  1236,  1245,  1280,  1315,  1349,
    1389,  1388,  1411,  1410,  1433,  1451,  1455,  1456,  1462,  1466,
    1477,  1491,  1490,  1524,  1559,  1594,  1599,  1604,  1618,  1622,
    1631,  1638,  1650,  1662,  1673,  1681,  1695,  1705,  1721,  1725,
    1734,  1750,  1764,  1763,  1784,  1783,  1802,  1806,  1815,  1816,
    1817,  1826,  1835,  1849,  1863,  1878,  1898,  1902,  1940,  1944,
    1948,  1953,  1958,  1967,  1993,  1994,  2000,  2001,  2007,  2011,
    2020,  2021,  2027,  2028,  2039,  2040,  2041,  2042,  2043,  2044,
    2045,  2046,  2047,  2048,  2049,  2050,  2051,  2052,  2053,  2058,
    2062,  2066,  2070,  2078,  2083,  2094,  2098,  2110,  2115,  2141,
    2173,  2201,  2216,  2230,  2241,  2253,  2264,  2275,  2286,  2292,
    2298,  2305,  2317,  2326,  2335,  2375,  2382,  2389,  2401,  2410,
    2424,  2425,  2426,  2427,  2428,  2429,  2430,  2431,  2432,  2433,
    2434,  2435,  2436,  2437,  2438,  2439,  2440,  2441,  2442,  2443,
    2444,  2445,  2446,  2447,  2448,  2449,  2450,  2451,  2452,  2453,
    2454,  2455,  2456,  2457,  2458,  2459,  2460,  2461
=======
       0,   204,   204,   210,   211,   217,   228,   234,   243,   252,
     260,   269,   276,   275,   281,   280,   285,   290,   289,   295,
     294,   299,   304,   303,   309,   308,   313,   318,   317,   323,
     322,   327,   332,   331,   337,   336,   341,   346,   345,   350,
     355,   354,   359,   364,   363,   369,   368,   373,   377,   387,
     386,   425,   424,   502,   506,   517,   528,   527,   553,   561,
     570,   588,   662,   668,   679,   701,   779,   789,   804,   808,
     819,   830,   829,   870,   874,   885,   910,  1000,  1012,  1025,
<<<<<<< HEAD
<<<<<<< HEAD
    1024,  1058,  1092,  1101,  1102,  1108,  1123,  1145,  1146,  1147,
    1151,  1157,  1158,  1164,  1176,  1192,  1207,  1216,  1221,  1230,
    1265,  1300,  1334,  1374,  1373,  1396,  1395,  1418,  1436,  1440,
    1441,  1447,  1451,  1462,  1476,  1475,  1509,  1544,  1579,  1584,
<<<<<<< HEAD
    1589,  1603,  1607,  1616,  1623,  1635,  1647,  1658,  1666,  1676,
    1684,  1698,  1708,  1724,  1728,  1737,  1753,  1767,  1766,  1787,
    1786,  1805,  1809,  1818,  1819,  1820,  1829,  1838,  1852,  1866,
    1881,  1901,  1905,  1943,  1947,  1956,  1975,  1976,  1982,  1983,
    1989,  1993,  2002,  2003,  2009,  2010,  2021,  2022,  2023,  2024,
    2025,  2026,  2027,  2028,  2029,  2030,  2031,  2032,  2033,  2034,
    2035,  2040,  2044,  2048,  2052,  2060,  2065,  2076,  2080,  2092,
    2097,  2123,  2155,  2183,  2198,  2212,  2223,  2235,  2246,  2257,
    2268,  2274,  2280,  2287,  2299,  2308,  2317,  2357,  2364,  2371,
    2383,  2392,  2406,  2407,  2408,  2409,  2410,  2411,  2412,  2413,
    2414,  2415,  2416,  2417,  2418,  2419,  2420,  2421,  2422,  2423,
    2424,  2425,  2426,  2427,  2428,  2429,  2430,  2431,  2432,  2433,
    2434,  2435,  2436,  2437,  2438,  2439,  2440,  2441,  2442
>>>>>>> Regenerated compilers, and fixed build errors.
=======
    1589,  1603,  1607,  1616,  1623,  1635,  1647,  1658,  1667,  1677,
    1685,  1699,  1709,  1725,  1729,  1738,  1754,  1768,  1767,  1788,
    1787,  1806,  1810,  1819,  1820,  1821,  1830,  1839,  1853,  1867,
    1882,  1902,  1906,  1944,  1948,  1957,  1976,  1977,  1983,  1984,
    1990,  1994,  2003,  2004,  2010,  2011,  2022,  2023,  2024,  2025,
    2026,  2027,  2028,  2029,  2030,  2031,  2032,  2033,  2034,  2035,
    2036,  2041,  2045,  2049,  2053,  2061,  2066,  2077,  2081,  2093,
    2098,  2124,  2156,  2184,  2199,  2213,  2224,  2236,  2247,  2258,
    2269,  2275,  2281,  2288,  2300,  2309,  2318,  2358,  2365,  2372,
    2384,  2393,  2407,  2408,  2409,  2410,  2411,  2412,  2413,  2414,
    2415,  2416,  2417,  2418,  2419,  2420,  2421,  2422,  2423,  2424,
    2425,  2426,  2427,  2428,  2429,  2430,  2431,  2432,  2433,  2434,
    2435,  2436,  2437,  2438,  2439,  2440,  2441,  2442,  2443
>>>>>>> Added support for type-alias metadata.
=======
    1024,  1058,  1099,  1108,  1109,  1115,  1130,  1152,  1153,  1154,
    1158,  1164,  1165,  1171,  1183,  1199,  1214,  1223,  1228,  1237,
    1272,  1307,  1341,  1381,  1380,  1403,  1402,  1425,  1446,  1450,
    1451,  1457,  1461,  1472,  1486,  1485,  1519,  1561,  1603,  1608,
<<<<<<< HEAD
<<<<<<< HEAD
    1613,  1627,  1631,  1640,  1647,  1659,  1671,  1682,  1697,  1707,
    1722,  1743,  1765,  1793,  1797,  1806,  1822,  1836,  1835,  1868,
    1867,  1886,  1890,  1899,  1900,  1901,  1910,  1919,  1933,  1947,
    1962,  1982,  1986,  2024,  2028,  2037,  2056,  2057,  2063,  2064,
    2070,  2074,  2083,  2084,  2090,  2091,  2102,  2103,  2104,  2105,
    2106,  2107,  2108,  2109,  2110,  2111,  2112,  2113,  2114,  2115,
    2116,  2121,  2125,  2129,  2133,  2141,  2146,  2157,  2161,  2173,
    2178,  2204,  2236,  2260,  2281,  2301,  2320,  2332,  2343,  2354,
    2366,  2372,  2378,  2385,  2397,  2406,  2415,  2455,  2462,  2469,
    2481,  2497,  2518,  2519,  2520,  2521,  2522,  2523,  2524,  2525,
    2526,  2527,  2528,  2529,  2530,  2531,  2532,  2533,  2534,  2535,
    2536,  2537,  2538,  2539,  2540,  2541,  2542,  2543,  2544,  2545,
    2546,  2547,  2548,  2549,  2550,  2551,  2552,  2553,  2554
>>>>>>> Added aliasing support into the parser.
=======
    1613,  1627,  1631,  1640,  1647,  1659,  1671,  1682,  1704,  1709,
    1719,  1734,  1755,  1777,  1805,  1809,  1818,  1834,  1848,  1847,
    1880,  1879,  1898,  1902,  1911,  1912,  1913,  1922,  1931,  1945,
    1959,  1974,  1994,  1998,  2036,  2040,  2049,  2068,  2069,  2075,
    2076,  2082,  2086,  2095,  2096,  2102,  2103,  2114,  2115,  2116,
    2117,  2118,  2119,  2120,  2121,  2122,  2123,  2124,  2125,  2126,
    2127,  2128,  2133,  2137,  2141,  2145,  2153,  2158,  2169,  2173,
<<<<<<< HEAD
    2185,  2190,  2216,  2248,  2272,  2293,  2313,  2332,  2344,  2355,
    2366,  2378,  2384,  2390,  2397,  2409,  2418,  2427,  2467,  2474,
    2481,  2493,  2509,  2530,  2531,  2532,  2533,  2534,  2535,  2536,
    2537,  2538,  2539,  2540,  2541,  2542,  2543,  2544,  2545,  2546,
    2547,  2548,  2549,  2550,  2551,  2552,  2553,  2554,  2555,  2556,
    2557,  2558,  2559,  2560,  2561,  2562,  2563,  2564,  2565,  2566
>>>>>>> Added better error handling logic to the parser.
=======
    2185,  2190,  2216,  2248,  2272,  2293,  2313,  2334,  2346,  2357,
    2368,  2380,  2386,  2392,  2399,  2411,  2420,  2429,  2469,  2476,
    2483,  2495,  2511,  2532,  2533,  2534,  2535,  2536,  2537,  2538,
    2539,  2540,  2541,  2542,  2543,  2544,  2545,  2546,  2547,  2548,
    2549,  2550,  2551,  2552,  2553,  2554,  2555,  2556,  2557,  2558,
    2559,  2560,  2561,  2562,  2563,  2564,  2565,  2566,  2567,  2568
>>>>>>> Cosmetic changes.
=======
    1613,  1627,  1631,  1640,  1647,  1659,  1671,  1682,  1703,  1709,
    1718,  1733,  1754,  1776,  1804,  1808,  1817,  1833,  1847,  1846,
    1879,  1878,  1897,  1901,  1910,  1911,  1912,  1921,  1930,  1944,
    1958,  1973,  1993,  1997,  2035,  2039,  2048,  2067,  2068,  2074,
    2075,  2081,  2085,  2094,  2095,  2101,  2102,  2113,  2114,  2115,
    2116,  2117,  2118,  2119,  2120,  2121,  2122,  2123,  2124,  2125,
    2126,  2127,  2132,  2136,  2140,  2144,  2152,  2157,  2168,  2172,
    2184,  2189,  2215,  2247,  2271,  2292,  2312,  2333,  2345,  2356,
    2367,  2379,  2385,  2391,  2398,  2410,  2419,  2428,  2468,  2475,
    2482,  2494,  2510,  2531,  2532,  2533,  2534,  2535,  2536,  2537,
    2538,  2539,  2540,  2541,  2542,  2543,  2544,  2545,  2546,  2547,
    2548,  2549,  2550,  2551,  2552,  2553,  2554,  2555,  2556,  2557,
    2558,  2559,  2560,  2561,  2562,  2563,  2564,  2565,  2566,  2567
>>>>>>> More cosmetic changes.
=======
    1024,  1058,  1094,  1103,  1104,  1110,  1125,  1147,  1148,  1149,
    1153,  1159,  1160,  1166,  1178,  1194,  1209,  1218,  1223,  1232,
<<<<<<< HEAD
    1267,  1302,  1336,  1376,  1375,  1398,  1397,  1420,  1441,  1445,
<<<<<<< HEAD
    1446,  1452,  1456,  1467,  1481,  1480,  1514,  1551,  1593,  1598,
    1603,  1617,  1621,  1630,  1637,  1649,  1661,  1672,  1708,  1714,
    1723,  1734,  1751,  1765,  1785,  1789,  1798,  1814,  1828,  1827,
    1860,  1859,  1878,  1882,  1891,  1892,  1893,  1902,  1911,  1925,
    1939,  1954,  1974,  1978,  2016,  2020,  2029,  2048,  2049,  2055,
    2056,  2062,  2066,  2075,  2076,  2082,  2083,  2094,  2095,  2096,
    2097,  2098,  2099,  2100,  2101,  2102,  2103,  2104,  2105,  2106,
    2107,  2108,  2113,  2117,  2121,  2125,  2133,  2138,  2149,  2153,
    2165,  2170,  2196,  2228,  2252,  2273,  2293,  2307,  2319,  2330,
    2341,  2353,  2359,  2365,  2372,  2384,  2393,  2402,  2442,  2449,
    2456,  2468,  2480,  2497,  2498,  2499,  2500,  2501,  2502,  2503,
    2504,  2505,  2506,  2507,  2508,  2509,  2510,  2511,  2512,  2513,
    2514,  2515,  2516,  2517,  2518,  2519,  2520,  2521,  2522,  2523,
    2524,  2525,  2526,  2527,  2528,  2529,  2530,  2531,  2532,  2533
>>>>>>> Fixed review comments.
=======
    1446,  1452,  1456,  1467,  1481,  1480,  1514,  1551,  1588,  1593,
    1598,  1612,  1616,  1625,  1632,  1644,  1656,  1667,  1703,  1709,
    1718,  1729,  1746,  1760,  1780,  1784,  1793,  1809,  1823,  1822,
    1855,  1854,  1873,  1877,  1886,  1887,  1888,  1897,  1906,  1920,
    1934,  1949,  1969,  1973,  2011,  2015,  2024,  2043,  2044,  2050,
    2051,  2057,  2061,  2070,  2071,  2077,  2078,  2089,  2090,  2091,
    2092,  2093,  2094,  2095,  2096,  2097,  2098,  2099,  2100,  2101,
    2102,  2103,  2108,  2112,  2116,  2120,  2128,  2133,  2144,  2148,
    2160,  2165,  2191,  2223,  2247,  2268,  2288,  2302,  2314,  2325,
    2336,  2348,  2354,  2360,  2367,  2379,  2388,  2397,  2437,  2444,
    2451,  2463,  2475,  2492,  2493,  2494,  2495,  2496,  2497,  2498,
    2499,  2500,  2501,  2502,  2503,  2504,  2505,  2506,  2507,  2508,
    2509,  2510,  2511,  2512,  2513,  2514,  2515,  2516,  2517,  2518,
    2519,  2520,  2521,  2522,  2523,  2524,  2525,  2526,  2527,  2528
>>>>>>> Fixed the tests.
=======
    1267,  1302,  1336,  1376,  1375,  1398,  1397,  1420,  1442,  1446,
    1447,  1453,  1457,  1468,  1482,  1481,  1515,  1552,  1589,  1594,
    1599,  1613,  1617,  1626,  1633,  1645,  1657,  1668,  1689,  1695,
    1704,  1715,  1732,  1746,  1766,  1770,  1779,  1795,  1809,  1808,
    1841,  1840,  1859,  1863,  1872,  1873,  1874,  1883,  1892,  1906,
    1920,  1935,  1955,  1959,  1997,  2001,  2010,  2029,  2030,  2036,
    2037,  2043,  2047,  2056,  2057,  2063,  2064,  2075,  2076,  2077,
    2078,  2079,  2080,  2081,  2082,  2083,  2084,  2085,  2086,  2087,
    2088,  2089,  2094,  2098,  2102,  2106,  2114,  2119,  2130,  2134,
<<<<<<< HEAD
    2146,  2151,  2177,  2209,  2233,  2254,  2274,  2289,  2301,  2312,
    2323,  2335,  2341,  2347,  2354,  2366,  2375,  2384,  2424,  2431,
    2438,  2450,  2462,  2479,  2480,  2481,  2482,  2483,  2484,  2485,
    2486,  2487,  2488,  2489,  2490,  2491,  2492,  2493,  2494,  2495,
    2496,  2497,  2498,  2499,  2500,  2501,  2502,  2503,  2504,  2505,
    2506,  2507,  2508,  2509,  2510,  2511,  2512,  2513,  2514,  2515
>>>>>>> Next batch of review fixes.
=======
    2146,  2151,  2177,  2209,  2233,  2254,  2274,  2288,  2300,  2311,
    2322,  2334,  2340,  2346,  2353,  2365,  2374,  2383,  2423,  2430,
    2437,  2449,  2461,  2478,  2479,  2480,  2481,  2482,  2483,  2484,
    2485,  2486,  2487,  2488,  2489,  2490,  2491,  2492,  2493,  2494,
    2495,  2496,  2497,  2498,  2499,  2500,  2501,  2502,  2503,  2504,
    2505,  2506,  2507,  2508,  2509,  2510,  2511,  2512,  2513,  2514
>>>>>>> Missed some stuff I meant to git add.
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "ICE_MODULE",
<<<<<<< HEAD
  "ICE_CLASS", "ICE_INTERFACE", "ICE_EXCEPTION", "ICE_STRUCT",
  "ICE_SEQUENCE", "ICE_DICTIONARY", "ICE_ENUM", "ICE_OUT", "ICE_STREAM",
  "ICE_EXTENDS", "ICE_IMPLEMENTS", "ICE_THROWS", "ICE_VOID", "ICE_BOOL",
  "ICE_BYTE", "ICE_SHORT", "ICE_USHORT", "ICE_INT", "ICE_UINT",
  "ICE_VARINT", "ICE_VARUINT", "ICE_LONG", "ICE_ULONG", "ICE_VARLONG",
  "ICE_VARULONG", "ICE_FLOAT", "ICE_DOUBLE", "ICE_STRING", "ICE_OBJECT",
  "ICE_CONST", "ICE_FALSE", "ICE_TRUE", "ICE_IDEMPOTENT", "ICE_TAG",
  "ICE_OPTIONAL", "ICE_ANYCLASS", "ICE_VALUE", "ICE_UNCHECKED",
  "ICE_STRING_LITERAL", "ICE_INTEGER_LITERAL",
  "ICE_FLOATING_POINT_LITERAL", "ICE_IDENTIFIER", "ICE_SCOPED_IDENTIFIER",
  "ICE_LOCAL_METADATA_OPEN", "ICE_LOCAL_METADATA_CLOSE",
  "ICE_FILE_METADATA_OPEN", "ICE_FILE_METADATA_CLOSE", "BAD_CHAR", "';'",
  "'{'", "'}'", "'('", "')'", "':'", "'='", "','", "'<'", "'>'", "'*'",
  "'?'", "$accept", "start", "opt_semicolon", "file_metadata",
  "local_metadata", "definitions", "definition", "$@1", "$@2", "$@3",
  "$@4", "$@5", "$@6", "$@7", "$@8", "$@9", "$@10", "$@11", "$@12", "$@13",
  "module_def", "@14", "@15", "exception_id", "exception_decl",
  "exception_def", "@16", "exception_extends", "tag", "optional",
  "struct_id", "struct_decl", "struct_def", "@17", "class_name",
  "class_id", "class_decl", "class_def", "@18", "class_extends", "extends",
  "data_member", "data_member_list", "data_members", "return_tuple",
  "return_type", "operation_preamble", "operation", "@19", "@20",
  "operation_list", "interface_id", "interface_decl", "interface_def",
  "@21", "interface_list", "interface_extends", "exception_list",
  "exception", "sequence_def", "dictionary_def", "enum_start", "enum_id",
  "enum_def", "@22", "@23", "enum_underlying", "enumerator_list_or_empty",
  "enumerator_list", "enumerator", "enumerator_initializer", "qualifier",
  "parameter", "parameter_list", "parameters", "throws", "scoped_name",
  "unscoped_name", "builtin", "type", "tagged_type", "member",
  "string_literal", "string_list", "const_initializer", "const_def",
  "keyword", YY_NULLPTR
=======
  "ICE_CLASS", "ICE_INTERFACE", "ICE_EXCEPTION", "ICE_STRUCT", "ICE_USING",
  "ICE_SEQUENCE", "ICE_DICTIONARY", "ICE_ENUM", "ICE_OUT", "ICE_EXTENDS",
  "ICE_IMPLEMENTS", "ICE_THROWS", "ICE_VOID", "ICE_BOOL", "ICE_BYTE",
  "ICE_SHORT", "ICE_USHORT", "ICE_INT", "ICE_UINT", "ICE_VARINT",
  "ICE_VARUINT", "ICE_LONG", "ICE_ULONG", "ICE_VARLONG", "ICE_VARULONG",
  "ICE_FLOAT", "ICE_DOUBLE", "ICE_STRING", "ICE_OBJECT", "ICE_CONST",
  "ICE_FALSE", "ICE_TRUE", "ICE_IDEMPOTENT", "ICE_TAG", "ICE_OPTIONAL",
  "ICE_ANYCLASS", "ICE_VALUE", "ICE_UNCHECKED", "ICE_STRING_LITERAL",
  "ICE_INTEGER_LITERAL", "ICE_FLOATING_POINT_LITERAL", "ICE_IDENTIFIER",
  "ICE_SCOPED_IDENTIFIER", "ICE_LOCAL_METADATA_OPEN",
  "ICE_LOCAL_METADATA_CLOSE", "ICE_FILE_METADATA_OPEN",
  "ICE_FILE_METADATA_CLOSE", "BAD_CHAR", "';'", "'{'", "'}'", "'('", "')'",
  "':'", "'='", "','", "'<'", "'>'", "'*'", "'?'", "$accept", "start",
  "opt_semicolon", "file_metadata", "local_metadata", "definitions",
  "definition", "$@1", "$@2", "$@3", "$@4", "$@5", "$@6", "$@7", "$@8",
  "$@9", "$@10", "$@11", "$@12", "$@13", "$@14", "module_def", "@15",
  "@16", "exception_id", "exception_decl", "exception_def", "@17",
  "exception_extends", "tag", "optional", "struct_id", "struct_decl",
  "struct_def", "@18", "class_name", "class_id", "class_decl", "class_def",
  "@19", "class_extends", "extends", "data_member", "data_member_list",
  "data_members", "return_tuple", "return_type", "operation_preamble",
  "operation", "@20", "@21", "operation_list", "interface_id",
  "interface_decl", "interface_def", "@22", "interface_list",
  "interface_extends", "exception_list", "exception", "type_alias_def",
  "sequence_def", "dictionary_def", "enum_start", "enum_id", "enum_def",
  "@23", "@24", "enum_underlying", "enumerator_list_or_empty",
  "enumerator_list", "enumerator", "enumerator_initializer",
  "out_qualifier", "parameter", "parameter_list", "parameters", "throws",
  "scoped_name", "unscoped_name", "builtin", "type", "tagged_type",
  "member", "string_literal", "string_list", "const_initializer",
  "const_def", "keyword", YY_NULLPTR
>>>>>>> Regenerated compilers, and fixed build errors.
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,    59,   123,   125,    40,    41,    58,    61,    44,
      60,    62,    42,    63
};
#endif

<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
#define YYPACT_NINF (-277)
=======
#define YYPACT_NINF (-281)
>>>>>>> Regenerated compilers, and fixed build errors.
=======
#define YYPACT_NINF (-254)
>>>>>>> Added support for type-alias metadata.
=======
#define YYPACT_NINF (-283)
>>>>>>> Added better error handling logic to the parser.
=======
#define YYPACT_NINF (-279)
>>>>>>> More cosmetic changes.

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

<<<<<<< HEAD
<<<<<<< HEAD
#define YYTABLE_NINF (-163)
=======
#define YYTABLE_NINF (-165)
>>>>>>> Regenerated compilers, and fixed build errors.
=======
#define YYTABLE_NINF (-166)
>>>>>>> Added better error handling logic to the parser.

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
    -277,    22,    14,  -277,    -4,    -4,  -277,    85,    -4,  -277,
      48,   -29,    30,   107,   474,   606,   649,   692,    27,    37,
    -277,    59,   120,    -4,  -277,  -277,    56,   102,  -277,    58,
     129,  -277,    57,     7,   136,  -277,    66,   161,  -277,   164,
     168,   735,   115,  -277,   170,  -277,  -277,    -4,  -277,  -277,
    -277,  -277,  -277,  -277,  -277,  -277,  -277,  -277,  -277,  -277,
    -277,  -277,  -277,  -277,  -277,  -277,  -277,  -277,  -277,  -277,
    -277,  -277,  -277,  -277,  -277,  -277,  -277,  -277,  -277,  -277,
    -277,  -277,  -277,  -277,  -277,  -277,  -277,  -277,  -277,  -277,
     143,  -277,   151,  -277,  -277,  -277,  -277,  -277,  -277,  -277,
      59,    59,   955,  -277,    83,   175,  -277,  -277,  -277,   146,
     181,   175,   148,   191,   175,  -277,   146,   192,   175,   150,
    -277,   195,   175,   196,   197,  -277,   198,  -277,  1016,  -277,
     175,   200,  -277,   201,   202,   185,   955,   955,  -277,  -277,
    -277,  -277,  -277,  -277,  -277,  -277,  -277,  -277,  -277,  -277,
    -277,  -277,  -277,   149,   187,   190,  -277,  -277,   174,   193,
     -34,  -277,  -277,  -277,   204,  -277,  -277,  -277,   297,  -277,
    -277,   205,  -277,  -277,  -277,  -277,  -277,  -277,  -277,   203,
     206,  -277,  -277,  -277,  -277,   -31,  -277,   208,  -277,  -277,
    -277,  -277,   207,   209,   210,   211,  -277,  -277,  -277,  -277,
    -277,  -277,  -277,   214,   101,   297,   212,   213,   219,   893,
    1016,  1016,   215,   337,   221,  -277,   778,   218,   297,   150,
     139,   429,   223,   220,  -277,   -31,   160,   172,  -277,  -277,
     821,    59,   101,  -277,  -277,  -277,  -277,  -277,  -277,  -277,
     226,  -277,   154,   159,    -4,  -277,  -277,  -277,  -277,   377,
    -277,  -277,  -277,   101,   227,  -277,   217,    65,   229,   224,
    -277,  -277,   126,   230,  -277,  -277,  -277,  -277,   955,  -277,
    -277,   231,  -277,   232,   233,  -277,   235,    89,  -277,  -277,
     139,   254,   274,  -277,    25,     6,   518,    28,   234,   986,
    -277,   189,  -277,  -277,   236,  -277,  -277,  -277,  -277,  -277,
    -277,  -277,  -277,   518,  -277,    46,   924,  -277,   237,   238,
     239,   924,  -277,   240,   244,   139,  -277,  -277,  -277,  -277,
     864,   241,   246,  -277,   228,  -277,  -277,  -277,  -277,  -277,
     228,  -277,  -277,  -277,  -277,  -277,  -277,   924,   279,  -277,
     279,  -277,   562,  -277,  -277,  -277,   243,  -277,  -277,   562,
    -277
=======
    -281,   104,    17,  -281,   -16,   -16,  -281,    84,   -16,  -281,
      76,    96,    54,    36,   471,   603,   646,   689,    71,    66,
      88,  -281,    89,   148,   -16,  -281,  -281,    21,   129,  -281,
     136,   147,  -281,    26,     6,   156,  -281,    27,   160,  -281,
     163,   164,   165,   732,   162,  -281,   166,  -281,  -281,   -16,
    -281,  -281,  -281,  -281,  -281,  -281,  -281,  -281,  -281,  -281,
    -281,  -281,  -281,  -281,  -281,  -281,  -281,  -281,  -281,  -281,
    -281,  -281,  -281,  -281,  -281,  -281,  -281,  -281,  -281,  -281,
    -281,  -281,  -281,  -281,  -281,  -281,  -281,  -281,  -281,  -281,
    -281,   158,  -281,   167,  -281,  -281,  -281,  -281,  -281,  -281,
    -281,   168,    89,    89,  1032,  -281,    86,   169,  -281,  -281,
    -281,   157,   173,   169,   174,   176,   169,  -281,   157,   180,
     169,   -17,  -281,   181,   169,   182,   184,   185,  -281,   187,
    -281,  1063,  -281,   169,   186,  -281,   188,   189,   115,  1063,
    1032,  1032,  -281,  -281,  -281,  -281,  -281,  -281,  -281,  -281,
    -281,  -281,  -281,  -281,  -281,  -281,  -281,   142,   190,   191,
    -281,  -281,   144,   192,   -31,  -281,  -281,  -281,   194,  -281,
    -281,  -281,   300,  -281,  -281,   195,  -281,  -281,  -281,  -281,
    -281,  -281,  -281,   193,   196,  -281,  -281,  -281,  -281,  -281,
     -36,  -281,   198,  -281,  -281,  -281,  -281,   200,   201,  -281,
     159,   199,  -281,  -281,  -281,  -281,  -281,  -281,  -281,   202,
      95,   300,   207,   206,   208,   970,  1063,  1063,   210,   340,
     211,  -281,   775,   209,   300,   -17,   146,   426,   214,   205,
    -281,   -36,   102,   103,  -281,  -281,   818,    89,    95,  -281,
    -281,  -281,  -281,  -281,  -281,  -281,   215,  -281,    53,    67,
     -16,  -281,  -281,  -281,  -281,   380,  -281,  -281,  -281,    95,
     216,  -281,   219,   891,   218,   217,  -281,  -281,   133,   220,
    -281,  -281,  -281,  -281,  1032,  -281,  -281,   222,  -281,   223,
     224,  -281,   225,    94,  -281,  -281,   146,  -281,   931,     9,
     515,    30,   221,  -281,  -281,   151,  -281,  -281,   183,  -281,
    -281,  -281,  -281,  -281,  -281,   515,  -281,  -281,   -18,  1001,
    -281,   227,   228,   229,  1001,  -281,   230,   231,   146,  -281,
    -281,  -281,   861,   233,   235,  -281,   264,  -281,  -281,  -281,
    -281,  -281,   264,  -281,  -281,  -281,  -281,  -281,  -281,  1001,
     271,  -281,   271,  -281,   559,  -281,  -281,  -281,   232,  -281,
    -281,   559,  -281
>>>>>>> Regenerated compilers, and fixed build errors.
=======
    -254,    12,     9,  -254,   -26,   -26,  -254,    77,   -26,  -254,
     -38,    88,   -30,    48,   513,   645,   688,   731,   -19,    35,
      55,  -254,    70,   128,   -26,  -254,  -254,    14,    82,  -254,
      91,    97,  -254,    19,     0,   109,  -254,    20,   127,  -254,
     132,   133,   134,   774,   136,  -254,   135,  -254,  -254,   -26,
    -254,  -254,  -254,  -254,  -254,  -254,  -254,  -254,  -254,  -254,
    -254,  -254,  -254,  -254,  -254,  -254,  -254,  -254,  -254,  -254,
    -254,  -254,  -254,  -254,  -254,  -254,  -254,  -254,  -254,  -254,
    -254,  -254,  -254,  -254,  -254,  -254,  -254,  -254,  -254,  -254,
    -254,   112,  -254,   156,  -254,  -254,  -254,  -254,  -254,  -254,
    -254,   131,    70,    70,  1074,  -254,   -29,   138,  -254,  -254,
    -254,   130,   139,   138,   159,   161,   138,  -254,   130,   162,
     138,    59,  -254,   166,   138,   167,   168,   169,  -254,   173,
    -254,   177,  -254,   138,   175,  -254,   179,   180,   117,    70,
    1074,  1074,  -254,  -254,  -254,  -254,  -254,  -254,  -254,  -254,
    -254,  -254,  -254,  -254,  -254,  -254,  -254,   115,   165,   171,
    -254,  -254,   118,   172,    74,  -254,  -254,  -254,   184,  -254,
    -254,  -254,   342,  -254,  -254,   185,  -254,  -254,  -254,  -254,
    -254,  -254,  -254,   181,   186,  -254,  -254,  -254,  -254,  -254,
     101,  -254,   189,  -254,  -254,  -254,  -254,   187,   188,  1074,
     190,   191,  -254,  -254,  -254,  -254,  -254,  -254,  -254,   195,
     108,   342,   193,   192,   194,  1012,   177,   177,   202,   382,
     201,  -254,   817,   198,   342,    59,   302,   468,   203,   199,
    -254,   101,    43,   110,  -254,  -254,  -254,   860,    70,   108,
    -254,  -254,  -254,  -254,  -254,  -254,  -254,   205,  -254,    80,
      85,   -26,  -254,  -254,  -254,  -254,   422,  -254,  -254,  -254,
     108,   206,  -254,   209,   933,   208,   207,  -254,  -254,   111,
     210,  -254,  -254,  -254,  -254,  1074,  -254,  -254,   212,  -254,
     213,   214,  -254,   215,    63,  -254,  -254,   302,  -254,   973,
       3,   557,    23,   211,  -254,  -254,   123,  -254,  -254,   216,
    -254,  -254,  -254,  -254,  -254,  -254,   557,  -254,  -254,   114,
    1043,  -254,   217,   218,   219,  1043,  -254,   221,   220,   302,
    -254,  -254,  -254,   903,   223,   226,  -254,   234,  -254,  -254,
    -254,  -254,  -254,   234,  -254,  -254,  -254,  -254,  -254,  -254,
    1043,   251,  -254,   251,  -254,   601,  -254,  -254,  -254,   224,
    -254,  -254,   601,  -254
>>>>>>> Added support for type-alias metadata.
=======
    -283,    18,    17,  -283,   -19,   -19,  -283,    84,   -19,  -283,
     -37,    57,    45,   137,   513,   645,   688,   731,    37,    58,
      72,  -283,    91,   141,   -19,  -283,  -283,    21,    96,  -283,
     102,   122,  -283,    26,     6,   132,  -283,    27,   139,  -283,
     152,   161,   165,   774,   136,  -283,   166,  -283,  -283,   -19,
    -283,  -283,  -283,  -283,  -283,  -283,  -283,  -283,  -283,  -283,
    -283,  -283,  -283,  -283,  -283,  -283,  -283,  -283,  -283,  -283,
    -283,  -283,  -283,  -283,  -283,  -283,  -283,  -283,  -283,  -283,
    -283,  -283,  -283,  -283,  -283,  -283,  -283,  -283,  -283,  -283,
    -283,   147,  -283,   153,  -283,  -283,  -283,  -283,  -283,  -283,
    -283,   162,    91,    91,  1074,  -283,   -22,   167,  -283,  -283,
    -283,   150,   169,   167,   170,   174,   167,  -283,   150,   175,
     167,   104,  -283,   176,   167,   180,   181,   182,  -283,   183,
    -283,  1105,  -283,   167,   186,  -283,   187,   189,   108,    91,
    1074,  1074,  -283,  -283,  -283,  -283,  -283,  -283,  -283,  -283,
    -283,  -283,  -283,  -283,  -283,  -283,  -283,   144,   159,   172,
    -283,  -283,   149,   184,   -31,  -283,  -283,  -283,   190,  -283,
    -283,  -283,   140,  -283,  -283,   191,  -283,  -283,  -283,  -283,
    -283,  -283,  -283,   192,   193,  -283,  -283,  -283,  -283,  -283,
      76,  -283,   196,  -283,  -283,  -283,  -283,   194,   197,   423,
     178,   195,  -283,  -283,  -283,  -283,  -283,  -283,  -283,   198,
     155,   140,   203,   202,   204,  1012,  1105,  1105,   206,   343,
     207,  -283,   817,   205,   140,   104,   303,   468,   208,   201,
    -283,    76,    93,   156,  -283,  -283,  -283,  -283,   860,    91,
     155,  -283,  -283,  -283,  -283,  -283,  -283,  -283,   210,  -283,
      68,    83,   -19,  -283,  -283,  -283,  -283,   383,  -283,  -283,
    -283,   155,   211,  -283,   214,   933,   213,   212,  -283,  -283,
      80,   215,  -283,  -283,  -283,  -283,  1074,  -283,  -283,   216,
    -283,   217,   218,  -283,   219,    50,  -283,  -283,   303,  -283,
     973,     9,   557,    30,   224,  -283,  -283,   130,  -283,  -283,
     220,  -283,  -283,  -283,  -283,  -283,  -283,   557,  -283,  -283,
     -18,  1043,  -283,   222,   223,   226,  1043,  -283,   221,   227,
     303,  -283,  -283,  -283,   903,   229,   230,  -283,   233,  -283,
    -283,  -283,  -283,  -283,   233,  -283,  -283,  -283,  -283,  -283,
    -283,  1043,   256,  -283,   256,  -283,   601,  -283,  -283,  -283,
     228,  -283,  -283,   601,  -283
>>>>>>> Added better error handling logic to the parser.
=======
    -279,    24,    17,  -279,    -4,    -4,  -279,    85,    -4,  -279,
     -32,    23,    51,   -27,   473,   605,   648,   691,    20,    47,
      57,  -279,    80,   140,    -4,  -279,  -279,    22,   119,  -279,
     126,   132,  -279,    27,    10,   158,  -279,    28,   165,  -279,
     166,   167,   171,   734,   170,  -279,   172,  -279,  -279,    -4,
    -279,  -279,  -279,  -279,  -279,  -279,  -279,  -279,  -279,  -279,
    -279,  -279,  -279,  -279,  -279,  -279,  -279,  -279,  -279,  -279,
    -279,  -279,  -279,  -279,  -279,  -279,  -279,  -279,  -279,  -279,
    -279,  -279,  -279,  -279,  -279,  -279,  -279,  -279,  -279,  -279,
    -279,   173,  -279,   174,  -279,  -279,  -279,  -279,  -279,  -279,
    -279,  -279,   176,    80,    80,  1003,  -279,   -26,   181,  -279,
    -279,  -279,    99,   188,   181,   192,   194,   181,  -279,    99,
     199,   181,   102,  -279,   200,   181,   209,   212,   214,  -279,
     197,  -279,  1034,  -279,   181,   215,  -279,   216,   218,   142,
      80,  1003,  1003,  -279,  -279,  -279,  -279,  -279,  -279,  -279,
    -279,  -279,  -279,  -279,  -279,  -279,  -279,  -279,   107,   202,
     207,  -279,  -279,   115,   210,   -19,  -279,  -279,  -279,   219,
    -279,  -279,  -279,   302,  -279,  -279,   221,  -279,  -279,  -279,
    -279,  -279,  -279,  -279,   220,   222,  -279,  -279,  -279,  -279,
    -279,    52,  -279,   223,  -279,  -279,  -279,  -279,   225,   226,
    1003,   224,   228,  -279,  -279,  -279,  -279,  -279,  -279,  -279,
     230,   213,   302,   231,   229,   234,   175,  1034,  1034,   238,
     342,   237,  -279,   777,   235,   302,   102,   136,   428,   240,
     233,  -279,    52,    65,    76,  -279,  -279,  -279,   820,    80,
     213,  -279,  -279,  -279,  -279,  -279,  -279,  -279,   242,  -279,
     193,   198,    -4,  -279,  -279,  -279,  -279,   382,  -279,  -279,
    -279,   213,   243,  -279,   246,   893,   245,   244,  -279,  -279,
      89,   247,  -279,  -279,  -279,  -279,  1003,  -279,  -279,   248,
    -279,   249,   250,  -279,   251,    49,  -279,  -279,   136,  -279,
     933,    18,   517,    31,   256,  -279,  -279,   217,  -279,  -279,
     239,  -279,  -279,  -279,  -279,  -279,  -279,   517,  -279,  -279,
      72,   972,  -279,   254,   255,   257,   972,  -279,   252,   258,
     136,  -279,  -279,  -279,   863,   260,   261,  -279,   265,  -279,
    -279,  -279,  -279,  -279,   265,  -279,  -279,  -279,  -279,  -279,
    -279,   972,   263,  -279,   263,  -279,   561,  -279,  -279,  -279,
     276,  -279,  -279,   561,  -279
>>>>>>> More cosmetic changes.
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
<<<<<<< HEAD
<<<<<<< HEAD
      11,     0,     8,     1,     0,     0,     9,     0,   199,   201,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     129,     8,     0,     0,    10,    12,    52,    26,    27,    67,
      31,    32,    75,    79,    16,    17,   110,    21,    22,    36,
      39,   134,   137,    40,    44,   198,     6,     0,     5,    45,
      46,    48,   210,   211,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
      70,   163,     0,    71,   108,   109,    50,    51,    65,    66,
       8,     8,     0,   128,     0,     4,    80,    81,    53,     0,
       0,     4,     0,     0,     4,    76,     0,     0,     4,     0,
     111,     0,     4,     0,     0,   130,     0,   131,     0,   132,
       4,     0,   200,     0,     0,     0,     0,     0,   164,   165,
     166,   167,   168,   169,   170,   171,   172,   173,   174,   175,
     176,   177,   178,   184,   185,   186,   160,   161,   188,   187,
       0,     7,     3,    13,     0,    55,    25,    28,     0,    30,
      33,     0,    78,    15,    18,   115,   116,   117,   118,   114,
       0,    20,    23,    35,    38,     8,   136,     0,    41,    43,
      11,    11,     0,     0,     0,     0,   179,   180,   181,   182,
     189,   190,   183,     0,     0,     0,     0,    60,    64,     0,
       0,     0,    86,     0,     0,   193,   196,    82,     0,     0,
       0,     0,     0,   138,   142,     8,     8,     8,    72,    73,
       0,     8,     0,   206,   207,   205,   202,   203,   204,   209,
       0,    85,     0,     0,     0,   197,   191,   192,    84,     0,
      69,   194,   195,     0,     0,   113,     0,   152,     0,   143,
     145,   135,     8,     0,    47,    49,   124,   125,     0,   208,
      54,     0,    59,     0,     0,    63,     0,     0,    83,    77,
       0,   148,   149,    95,   152,   152,     0,     0,   105,     0,
     112,     0,   141,   133,     0,    57,    58,    61,    62,     6,
     106,   151,   150,     0,    94,     0,     0,   162,     0,     0,
       0,     0,   154,   156,     0,     0,    92,   146,   144,   147,
       0,     0,     0,    93,   152,    90,    96,    98,   102,   153,
     152,   100,   104,   126,   127,    97,    99,     0,   159,   155,
     159,    91,     0,   103,   101,   158,   121,   122,   123,     0,
     120
=======
      11,     0,     8,     1,     0,     0,     9,     0,   201,   203,
=======
      11,     0,     8,     1,     0,     0,     9,     0,   202,   204,
>>>>>>> Added better error handling logic to the parser.
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   135,     8,     0,     0,    10,    12,    55,    26,    27,
      70,    31,    32,    78,    82,    16,    17,   113,    21,    22,
      39,    36,    42,   140,   143,    43,    47,   201,     6,     0,
       5,    48,    49,    51,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,    73,   166,     0,    74,   111,   112,    53,    54,    68,
<<<<<<< HEAD
      69,   129,     8,     8,     0,   134,     0,     4,    83,    84,
      56,     0,     0,     4,     0,     0,     4,    79,     0,     0,
       4,     0,   114,     0,     4,     0,     0,     0,   136,     0,
     137,     0,   138,     4,     0,   203,     0,     0,     0,     8,
       0,     0,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   187,   188,   189,
     163,   164,   191,   190,     0,     7,     3,    13,     0,    58,
      25,    28,     0,    30,    33,     0,    81,    15,    18,   118,
     119,   120,   121,   117,     0,    20,    23,    38,    35,    41,
       8,   142,     0,    44,    46,    11,    11,     0,     0,     0,
       0,     0,   182,   183,   184,   185,   192,   193,   186,     0,
       0,     0,     0,    63,    67,     0,     0,     0,    89,     0,
<<<<<<< HEAD
       0,   195,   198,    85,     0,     0,     0,     0,     0,   143,
<<<<<<< HEAD
     147,     8,     8,     8,    75,    76,     0,     8,     0,   208,
     209,   207,   204,   205,   206,   211,     0,    88,     0,     0,
       0,   199,   193,   194,    87,     0,    72,   196,   197,     0,
       0,   116,     0,     0,     0,   148,   150,   140,     8,     0,
      50,    52,   129,   130,     0,   210,    57,     0,    62,     0,
       0,    66,     0,     0,    86,    80,     0,    98,     0,   154,
       0,     0,   108,    95,   115,     0,   146,   138,     0,    60,
      61,    64,    65,     6,   109,     0,   153,    97,     0,     0,
     164,     0,     0,     0,     0,   156,   158,     0,     0,   151,
     149,   152,     0,     0,     0,    96,   154,    93,    99,   101,
     105,   155,   154,   103,   107,   131,   132,   100,   102,     0,
     161,   157,   161,    94,     0,   106,   104,   160,   124,   125,
     126,     0,   123
>>>>>>> Regenerated compilers, and fixed build errors.
=======
     147,     8,     8,     8,    75,    76,   127,     0,     8,     0,
     208,   209,   207,   204,   205,   206,   211,     0,    88,     0,
       0,     0,   199,   193,   194,    87,     0,    72,   196,   197,
       0,     0,   116,     0,     0,     0,   148,   150,   140,     8,
       0,    50,    52,   129,   130,     0,   210,    57,     0,    62,
       0,     0,    66,     0,     0,    86,    80,     0,    98,     0,
     154,     0,     0,   108,    95,   115,     0,   146,   138,     0,
      60,    61,    64,    65,     6,   109,     0,   153,    97,     0,
       0,   164,     0,     0,     0,     0,   156,   158,     0,     0,
     151,   149,   152,     0,     0,     0,    96,   154,    93,    99,
     101,   105,   155,   154,   103,   107,   131,   132,   100,   102,
       0,   161,   157,   161,    94,     0,   106,   104,   160,   124,
     125,   126,     0,   123
>>>>>>> Added support for type-alias metadata.
=======
       0,   196,   199,    85,     0,     0,     0,     0,     0,   144,
     148,     8,     8,     8,    75,    76,   128,   127,     0,     8,
=======
      69,   129,   128,     8,     8,     0,   134,     0,     4,    83,
      84,    56,     0,     0,     4,     0,     0,     4,    79,     0,
       0,     4,     0,   114,     0,     4,     0,     0,     0,   136,
       0,   137,     0,   138,     4,     0,   203,     0,     0,     0,
       8,     0,     0,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   181,   187,   188,
     189,   163,   164,   191,   190,     0,     7,     3,    13,     0,
      58,    25,    28,     0,    30,    33,     0,    81,    15,    18,
     118,   119,   120,   121,   117,     0,    20,    23,    38,    35,
      41,     8,   142,     0,    44,    46,    11,    11,     0,     0,
       0,     0,     0,   182,   183,   184,   185,   192,   193,   186,
       0,     0,     0,     0,    63,    67,     0,     0,     0,    89,
       0,     0,   196,   199,    85,     0,     0,     0,     0,     0,
     144,   148,     8,     8,     8,    75,    76,   127,     0,     8,
>>>>>>> More cosmetic changes.
       0,   209,   210,   208,   205,   206,   207,   212,     0,    88,
       0,     0,     0,   200,   194,   195,    87,     0,    72,   197,
     198,     0,     0,   116,     0,     0,     0,   149,   151,   141,
       8,     0,    50,    52,   130,   131,     0,   211,    57,     0,
      62,     0,     0,    66,     0,     0,    86,    80,     0,    98,
       0,   155,     0,     0,   108,    95,   115,     0,   147,   139,
       0,    60,    61,    64,    65,     6,   109,     0,   154,    97,
       0,     0,   165,     0,     0,     0,     0,   157,   159,     0,
       0,   152,   150,   153,     0,     0,     0,    96,   155,    93,
      99,   101,   105,   156,   155,   103,   107,   132,   133,   100,
     102,     0,   162,   158,   162,    94,     0,   106,   104,   161,
     124,   125,   126,     0,   123
>>>>>>> Added better error handling logic to the parser.
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
    -277,  -277,    11,  -277,    -2,    51,  -277,  -277,  -277,  -277,
    -277,  -277,  -277,  -277,  -277,  -277,  -277,  -277,  -277,  -277,
    -277,  -277,  -277,  -277,  -277,  -277,  -277,  -277,  -277,  -277,
    -277,  -277,  -277,  -277,  -277,  -277,  -277,  -277,  -277,  -277,
      91,  -277,  -128,  -192,  -277,    19,  -277,  -277,  -277,  -277,
    -271,  -277,  -277,  -277,  -277,    86,  -277,   -45,  -277,  -277,
    -277,  -277,  -277,  -277,  -277,  -277,  -277,    81,  -277,    47,
    -277,  -252,   -22,  -277,  -277,   -30,  -104,  -276,  -277,   -94,
      23,  -203,    24,     2,  -149,  -277,   -13
=======
    -281,  -281,    -5,  -281,    -2,    15,  -281,  -281,  -281,  -281,
    -281,  -281,  -281,  -281,  -281,  -281,  -281,  -281,  -281,  -281,
    -281,  -281,  -281,  -281,  -281,  -281,  -281,  -281,  -281,  -281,
    -281,  -281,  -281,  -281,  -281,  -281,  -281,  -281,  -281,  -281,
    -281,   161,  -281,  -212,   -97,  -281,   -45,  -281,  -281,  -281,
    -281,  -215,  -281,  -281,  -281,  -281,    20,  -281,   -58,  -281,
    -281,  -281,  -281,  -281,  -281,  -281,  -281,  -281,  -281,    63,
    -281,    28,  -281,  -254,   -37,  -281,  -281,   -44,  -105,  -280,
    -281,   -95,  -251,  -207,    24,     0,  -141,  -281,   -13
>>>>>>> Regenerated compilers, and fixed build errors.
=======
    -254,  -254,    -4,  -254,    -2,   -13,  -254,  -254,  -254,  -254,
    -254,  -254,  -254,  -254,  -254,  -254,  -254,  -254,  -254,  -254,
    -254,  -254,  -254,  -254,  -254,  -254,  -254,  -254,  -254,  -254,
    -254,  -254,  -254,  -254,  -254,  -254,  -254,  -254,  -254,  -254,
    -254,   137,  -254,  -190,   -84,  -254,   -15,  -254,  -254,  -254,
    -254,  -212,  -254,  -254,  -254,  -254,    57,  -254,   -68,  -254,
    -254,  -254,  -254,  -254,  -254,  -254,  -254,  -254,  -254,    56,
    -254,    17,  -254,  -225,   -45,  -254,  -254,   -54,  -104,  -217,
    -254,  -103,  -253,  -207,    15,     1,  -221,  -254,   -12
>>>>>>> Added support for type-alias metadata.
=======
    -283,  -283,   -14,  -283,    -2,    20,  -283,  -283,  -283,  -283,
    -283,  -283,  -283,  -283,  -283,  -283,  -283,  -283,  -283,  -283,
    -283,  -283,  -283,  -283,  -283,  -283,  -283,  -283,  -283,  -283,
    -283,  -283,  -283,  -283,  -283,  -283,  -283,  -283,  -283,  -283,
    -283,    78,  -283,  -176,  -196,  -283,    -1,  -283,  -283,  -283,
    -283,  -276,  -283,  -283,  -283,  -283,    63,  -283,   -63,  -283,
    -283,  -283,  -283,  -283,  -283,  -283,  -283,  -283,  -283,    60,
    -283,    22,  -283,  -256,   -41,  -283,  -283,   -49,  -105,  -282,
    -283,   -95,  -194,  -208,    24,     0,  -232,  -283,   -13
>>>>>>> Added better error handling logic to the parser.
=======
    -279,  -279,    -1,  -279,    -2,    12,  -279,  -279,  -279,  -279,
    -279,  -279,  -279,  -279,  -279,  -279,  -279,  -279,  -279,  -279,
    -279,  -279,  -279,  -279,  -279,  -279,  -279,  -279,  -279,  -279,
    -279,  -279,  -279,  -279,  -279,  -279,  -279,  -279,  -279,  -279,
    -279,   112,  -279,  -213,  -114,  -279,    46,  -279,  -279,  -279,
    -279,  -273,  -279,  -279,  -279,  -279,    91,  -279,   -16,  -279,
    -279,  -279,  -279,  -279,  -279,  -279,  -279,  -279,  -279,   106,
    -279,    74,  -279,  -219,    11,  -279,  -279,     2,  -111,  -278,
    -279,   -96,  -253,  -206,    34,     1,  -227,  -279,   -12
>>>>>>> More cosmetic changes.
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
<<<<<<< HEAD
<<<<<<< HEAD
      -1,     1,   163,     6,   209,     2,    24,   105,   117,   118,
     121,   122,   110,   111,   113,   114,   123,   124,   130,   131,
      25,   133,   134,    26,    27,    28,   164,   108,   210,   211,
      29,    30,    31,   112,    32,    33,    34,    35,   171,   115,
     109,   212,   213,   214,   305,   286,   287,   288,   340,   338,
     258,    36,    37,    38,   180,   178,   120,   345,   346,    39,
      40,    41,    42,    43,   187,   126,   129,   222,   223,   224,
     318,   289,   312,   313,   314,   343,   158,    92,   159,   215,
     216,   217,     9,    10,   239,    44,   348
=======
      -1,     1,   167,     6,   215,     2,    25,   107,   119,   120,
     123,   124,   112,   113,   115,   116,   126,   125,   127,   133,
     134,    26,   136,   137,    27,    28,    29,   168,   110,   216,
     217,    30,    31,    32,   114,    33,    34,    35,    36,   175,
     117,   111,   218,   219,   220,   310,   292,   293,   294,   344,
     342,   266,    37,    38,    39,   184,   182,   122,   349,   350,
      40,    41,    42,    43,    44,    45,   192,   129,   132,   228,
<<<<<<< HEAD
<<<<<<< HEAD
     229,   230,   320,   314,   315,   316,   317,   345,   162,    93,
     163,   221,   222,   223,     9,    10,   245,    46,   350
>>>>>>> Regenerated compilers, and fixed build errors.
=======
     229,   230,   321,   315,   316,   317,   318,   346,   162,    93,
     163,   221,   222,   223,     9,    10,   246,    46,   351
>>>>>>> Added support for type-alias metadata.
=======
     229,   230,   322,   316,   317,   318,   319,   347,   162,    93,
     163,   221,   222,   223,     9,    10,   247,    46,   352
>>>>>>> Added better error handling logic to the parser.
=======
      -1,     1,   168,     6,   216,     2,    25,   108,   120,   121,
     124,   125,   113,   114,   116,   117,   127,   126,   128,   134,
     135,    26,   137,   138,    27,    28,    29,   169,   111,   217,
     218,    30,    31,    32,   115,    33,    34,    35,    36,   176,
     118,   112,   219,   220,   221,   310,   292,   293,   294,   344,
     342,   266,    37,    38,    39,   185,   183,   123,   349,   350,
      40,    41,    42,    43,    44,    45,   193,   130,   133,   229,
     230,   231,   322,   316,   317,   318,   319,   347,   163,    93,
     164,   222,   223,   224,     9,    10,   247,    46,   352
>>>>>>> More cosmetic changes.
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
       7,    93,    95,    97,    99,   165,   245,    11,   160,   300,
     308,   203,   172,   240,    -2,   179,     4,   281,   282,   102,
     106,    48,     3,  -140,   204,   104,   254,   321,   127,   310,
      47,   193,    45,   306,   186,   311,   281,   282,     8,   281,
     282,   283,   194,   195,   332,  -152,  -152,  -152,  -152,  -152,
    -152,  -152,  -152,  -152,  -152,  -152,  -152,  -152,  -152,  -152,
    -152,     4,   304,     5,   107,  -152,  -152,  -152,  -152,   106,
     -74,   132,   337,  -152,  -152,  -152,   281,   282,   311,   106,
     285,   283,    49,   269,  -157,   249,    12,   100,    13,    14,
      15,    16,    17,    18,    19,    20,    46,   101,   136,   137,
     238,   284,   323,   325,   278,   324,     4,    47,   329,   -56,
     -74,   -68,    23,   107,   -74,   179,   246,   247,    21,  -119,
     285,   249,   167,   107,   116,   170,    22,   119,   238,   174,
     103,   161,    23,   182,   341,   233,   234,   299,   273,   276,
     256,   188,    47,   235,   236,   237,   156,   157,    47,   238,
      -8,    -8,    50,    51,   -24,    -8,    -8,    -8,    -8,    -8,
      -8,    -8,    -8,    -8,    -8,    -8,    -8,    -8,    -8,    -8,
      -8,    -8,   128,     4,   294,    -8,    -8,    -8,    -8,    -8,
    -139,   -29,   175,   221,    -8,    -8,     4,   319,   -14,   176,
     177,   156,   157,  -107,    -8,   156,   157,   271,  -162,   156,
     157,   168,   274,   252,   156,   157,   135,     4,   260,     5,
     272,   196,   197,   -19,   264,   275,   -34,   267,   257,     4,
     -37,     5,   -42,   221,     7,     7,   265,   162,   192,   268,
     156,   157,   317,   166,   156,   157,   200,   201,   347,   281,
     282,   226,   227,   169,   173,   347,   277,   181,   183,   184,
     198,   185,   189,   199,   190,   191,   202,   205,   218,   220,
     221,   225,   219,   228,   241,   229,   301,   248,   242,   280,
     231,   230,   232,   309,   243,   250,   253,   261,   257,   262,
     270,   279,   291,   290,   293,   302,   315,   295,   296,   297,
     322,   298,   326,   327,   342,   328,   335,   320,   206,   330,
     331,   336,   349,   303,   350,   255,   263,   334,   339,   292,
     344,     0,   316,   257,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
       0,     0,     0,     0,   207,   208,   154,   155,   206,     0,
       0,     0,   156,   157,     4,     0,     0,     0,     0,     0,
       0,   -89,     0,     0,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
       0,     0,     0,     0,   207,   208,   154,   155,   206,     0,
       0,     0,   156,   157,     4,     0,     0,     0,     0,     0,
       0,   -88,     0,     0,   138,   139,   140,   141,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
       0,     0,     0,     0,   207,   208,   154,   155,     0,     0,
       0,     0,   156,   157,     4,     0,     0,     0,     0,     0,
       0,   -87,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
       0,     0,     0,     0,   259,     0,    23,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,     0,     0,     0,     0,    90,
      91,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,     0,
       0,     0,     0,   307,    91,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,     0,     0,     0,     0,   156,   157,    52,
      53,    54,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,     0,     0,     0,
       0,    94,    52,    53,    54,    55,    56,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
       0,     0,     0,     0,    96,    52,    53,    54,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,     0,     0,     0,     0,    98,    52,    53,
      54,    55,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,     0,     0,     0,     0,
     125,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,     0,
       0,     0,     0,   251,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,     0,     0,     0,     0,   266,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,     0,     0,     0,     0,   333,
     138,   139,   140,   141,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,     0,     0,     0,     0,
     207,   208,   154,   155,     0,     0,     0,     0,   156,   157,
     244,   138,   139,   140,   141,   142,   143,   144,   145,   146,
     147,   148,   149,   150,   151,   152,   153,     0,     0,     0,
       0,   207,   208,   154,   155,     0,     0,     0,     0,   156,
     157,     4,   138,   139,   140,   141,   142,   143,   144,   145,
     146,   147,   148,   149,   150,   151,   152,   153,     0,     0,
       0,     0,     0,     0,   154,   155,     0,     0,     0,     0,
     156,   157,    23,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,     0,
       0,     0,     0,   207,   208,   154,   155,     0,     0,     0,
       0,   156,   157,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,     0,
       0,     0,     0,     0,     0,   154,   155,     0,     0,     0,
       0,   156,   157
=======
       7,    94,    96,    98,   100,    11,   169,   255,   251,   164,
     311,     4,   293,   176,   209,   179,   183,    -2,  -145,   108,
     104,   306,   180,   181,   106,   323,     8,   210,   160,   161,
     130,   313,    47,   198,   108,   309,   191,   293,   325,   -77,
     108,   326,   306,   255,   199,   200,   201,  -154,  -154,  -154,
=======
       7,   164,    94,    96,    98,   100,    11,   169,   252,    -2,
      48,   294,     3,   108,   176,   307,     8,   183,   276,   165,
     104,    49,    51,    47,   314,   106,   101,   108,   191,   256,
      49,   130,   -77,   108,   198,   307,   294,   200,   201,   285,
>>>>>>> Added support for type-alias metadata.
    -154,  -154,  -154,  -154,  -154,  -154,  -154,  -154,  -154,  -154,
    -154,  -154,  -154,  -154,  -154,  -154,     4,   109,     5,   308,
    -154,  -154,  -154,  -154,   135,   310,   256,   -59,  -154,  -154,
    -154,   109,   -77,  -122,   312,   305,   -77,   109,    12,  -159,
      13,    14,    15,    16,    17,    18,    19,    20,    21,   324,
       4,   179,     5,    52,    53,   102,   236,   271,   180,   181,
     140,   141,   340,   328,   160,   161,   245,   335,   332,   171,
      22,   304,   174,   253,   254,   103,   178,     4,    23,   209,
     186,   183,    49,   278,    24,   160,   161,   247,   281,   193,
     160,   161,   210,   344,   -24,   245,   279,   199,    50,   105,
     261,   282,   240,   241,   -71,   280,   283,    49,     4,   -29,
     242,   243,   244,   160,   161,  -145,   245,     4,     4,     5,
     197,   -14,   160,   161,   272,  -144,   320,  -164,   160,   161,
     326,   118,   299,   327,   121,   160,   161,   202,   203,   -19,
     206,   207,   232,   233,   -36,   -34,   -40,   -45,   227,   139,
     166,   170,   322,   131,   142,   143,   144,   145,   146,   147,
     148,   149,   150,   151,   152,   153,   154,   155,   156,   157,
     259,   138,   172,   173,   177,   267,   158,   159,   185,   187,
     188,   189,   160,   161,   264,   274,   190,   194,   204,   227,
       7,     7,   195,   196,   205,   208,   275,   211,   224,   226,
     225,   350,   231,   234,   235,   248,   307,   249,   350,   250,
     238,   237,   284,   239,   255,   257,   260,   268,   269,   277,
     286,   287,   295,   319,   298,   296,   345,   227,   300,   301,
     302,   303,   329,   330,   306,   331,   334,   323,   338,   313,
     333,   339,   262,   352,   353,   264,   297,   270,   342,   347,
       0,     0,     0,     0,   325,     0,     0,     0,     0,     0,
       0,     0,     0,   263,     0,     0,     0,     0,     0,     0,
       0,   337,     0,     0,     0,     0,     0,   264,    -8,    -8,
=======
       7,    94,    96,    98,   100,    11,   169,   253,   277,   164,
     313,    48,   306,   176,   209,   248,   183,    -2,     3,   108,
     104,   308,    49,     8,   106,   325,   165,   210,   262,   286,
     130,   315,    47,   198,   108,   311,   191,    49,   327,   -77,
     108,   328,   308,   257,   336,   200,   201,  -155,  -155,  -155,
    -155,  -155,  -155,  -155,  -155,  -155,  -155,  -155,  -155,  -155,
    -155,  -155,  -155,   109,     4,   309,     5,  -155,  -155,  -155,
    -155,   295,   341,   135,   -59,  -155,  -155,  -155,   109,   -77,
    -122,   257,   101,   -77,   109,    12,  -160,    13,    14,    15,
      16,    17,    18,    19,    20,    21,   295,    51,   305,   171,
     140,   141,   174,   329,   237,   246,   178,    50,   333,    49,
     186,   279,   118,   160,   161,   121,    49,    22,   102,   193,
     183,   254,   255,     4,   280,    23,   282,     4,   160,   161,
    -146,    24,   103,   345,  -145,   246,   179,   199,     4,   283,
       4,   212,     5,   180,   181,   281,   284,   272,   -24,   160,
     161,   197,   105,   160,   161,   -71,   246,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   321,   -29,   160,   161,   213,   214,   158,
     159,   300,    52,    53,   -14,   160,   161,     4,   227,   241,
     242,   -19,   323,   131,   -92,   160,   161,   243,   244,   245,
     160,   161,  -165,     4,   -37,     5,   202,   203,   138,   260,
     273,   206,   207,   -34,   268,   232,   233,   -40,   -45,   166,
     139,   170,   204,   172,   265,   275,   173,   177,   185,   227,
       7,     7,   187,   188,   189,   205,   190,   276,   194,   238,
     195,   351,   196,   211,   224,   308,   226,   208,   351,   231,
     234,   225,   285,   235,   239,   249,   240,   250,   256,   251,
     270,   258,   269,   261,   278,   287,   288,   296,   227,   299,
     297,   346,   301,   302,   303,   304,   320,   330,   331,   314,
     334,   324,   332,   335,   339,   340,   265,   353,   263,   307,
     354,   271,   298,   343,   326,   348,     0,     0,     0,     0,
       0,     0,     0,     0,   264,     0,     0,     0,     0,     0,
       0,   338,     0,     0,     0,     0,     0,     0,   265,    -8,
>>>>>>> Added better error handling logic to the parser.
      -8,    -8,    -8,    -8,    -8,    -8,    -8,    -8,    -8,    -8,
      -8,    -8,    -8,    -8,    -8,    -8,     0,     0,     0,    -8,
      -8,    -8,    -8,    -8,   212,     0,     0,     0,    -8,    -8,
       4,     0,     0,     0,     0,     0,     0,  -110,    -8,     0,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,     0,     0,     0,     0,
     213,   214,   158,   159,   212,     0,     0,     0,   160,   161,
       4,     0,     0,     0,     0,     0,     0,   -91,     0,     0,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,     0,     0,     0,     0,
     213,   214,   158,   159,   236,     0,     0,     0,   160,   161,
       4,     0,     0,     0,     0,     0,     0,   -90,     0,     0,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,     0,     0,     0,     0,
       0,     0,   158,   159,     0,     0,     0,     0,   160,   161,
      24,    54,    55,    56,    57,    58,     0,    59,    60,    61,
=======
       7,   170,    94,    96,    98,   100,    11,   257,   177,   165,
     253,   184,   295,   277,   313,   306,    48,    -2,    52,    53,
     105,   101,   166,   109,     3,   107,   210,    49,   199,   325,
     308,   131,   315,    49,   286,   109,   192,   295,     8,   211,
     -77,   109,    47,   308,   257,   201,   202,   336,  -155,  -155,
    -155,  -155,  -155,  -155,  -155,  -155,  -155,  -155,  -155,  -155,
    -155,  -155,  -155,  -155,     4,   102,     5,   110,  -155,  -155,
    -155,  -155,   311,    50,   309,   -59,  -155,  -155,  -155,   110,
     -77,  -122,    49,   136,   -77,   110,    12,  -160,    13,    14,
      15,    16,    17,    18,    19,    20,    21,   305,   248,     4,
     246,   141,   142,    51,   237,   329,  -146,   103,    49,   341,
     333,   262,     4,   172,     5,   184,   175,   104,    22,   272,
     179,   254,   255,     4,   187,     5,    23,     4,   327,   246,
     273,   328,    24,   194,   180,   345,     4,   264,   200,   281,
     284,   181,   182,  -145,   161,   162,   119,   161,   162,   122,
     246,   106,    -8,    -8,    -8,    -8,    -8,    -8,    -8,    -8,
      -8,    -8,    -8,    -8,    -8,    -8,    -8,    -8,    -8,   203,
     204,   -24,    -8,    -8,    -8,    -8,    -8,   207,   208,   -71,
     300,    -8,    -8,     4,   -29,   198,   323,   161,   162,   228,
    -110,    -8,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,   158,   233,   234,
     -14,   260,   214,   215,   159,   160,   268,   -19,   -37,   -34,
     161,   162,   252,   -40,   -45,   265,   275,   132,  -165,   139,
     228,     7,     7,   167,   140,   351,   279,   276,   161,   162,
     171,   282,   351,   161,   162,   173,   174,   241,   242,   280,
     191,   178,   186,   285,   283,   243,   244,   245,   161,   162,
     321,   188,   161,   162,   189,   205,   190,   195,   228,   196,
     206,   197,   212,   209,   225,   227,   232,   308,   346,   226,
     314,   235,   236,   249,   250,   238,   265,   239,   240,   251,
     256,   258,   270,   261,   269,   326,   278,   287,   288,   296,
     324,   299,   297,   213,   301,   302,   303,   304,   320,   330,
     331,   334,   338,   332,   335,   339,   340,   263,   265,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,   353,   307,   354,   271,   214,
     215,   159,   160,   213,   298,   343,   348,   161,   162,     4,
       0,     0,     0,     0,     0,     0,   -92,     0,     0,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,     0,     0,     0,     0,   214,
     215,   159,   160,   213,     0,     0,     0,   161,   162,     4,
       0,     0,     0,     0,     0,     0,   -91,     0,     0,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,     0,     0,     0,     0,   214,
     215,   159,   160,     0,     0,     0,     0,   161,   162,     4,
       0,    54,    55,    56,    57,    58,   -90,    59,    60,    61,
>>>>>>> More cosmetic changes.
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,     0,
       0,     0,     0,   267,     0,    24,    54,    55,    56,    57,
      58,     0,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,     0,     0,     0,     0,    91,    92,
      54,    55,    56,    57,    58,     0,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,     0,     0,
       0,     0,   312,    92,    54,    55,    56,    57,    58,     0,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,     0,     0,     0,     0,   161,   162,    54,    55,
      56,    57,    58,     0,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,     0,     0,     0,     0,
      95,    54,    55,    56,    57,    58,     0,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,     0,
       0,     0,     0,    97,    54,    55,    56,    57,    58,     0,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,     0,     0,     0,     0,    99,    54,    55,    56,
      57,    58,     0,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
      86,    87,    88,    89,    90,     0,     0,     0,     0,   129,
      54,    55,    56,    57,    58,     0,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,    86,    87,    88,    89,    90,     0,     0,
       0,     0,   259,    54,    55,    56,    57,    58,     0,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    86,    87,    88,    89,
      90,     0,     0,     0,     0,   274,    54,    55,    56,    57,
      58,     0,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,     0,     0,     0,     0,   337,   289,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,     0,     0,     0,   290,
     214,   215,   159,   160,     0,     0,     0,     0,   161,   162,
      24,     0,     0,     0,     0,     0,     0,     0,   291,   289,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
<<<<<<< HEAD
     153,   154,   155,   156,   157,     0,     0,     0,     0,   213,
     214,   158,   159,     0,     0,     0,     0,   160,   161,   252,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,     0,     0,     0,     0,
<<<<<<< HEAD
       0,     0,   158,   159,     0,     0,     0,     0,   160,   161
>>>>>>> Regenerated compilers, and fixed build errors.
=======
     213,   214,   158,   159,     0,     0,     0,     0,   160,   161,
       4,   142,   143,   144,   145,   146,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   156,   157,     0,     0,     0,
       0,     0,     0,   158,   159,     0,     0,     0,     0,   160,
<<<<<<< HEAD
     161,    24
>>>>>>> Added support for type-alias metadata.
=======
     161,    24,   142,   143,   144,   145,   146,   147,   148,   149,
     150,   151,   152,   153,   154,   155,   156,   157,     0,     0,
       0,     0,     0,     0,   158,   159,     0,     0,     0,     0,
     160,   161
>>>>>>> Added better error handling logic to the parser.
=======
     153,   154,   155,   156,   157,   158,     0,     0,     0,     0,
     214,   215,   159,   160,     0,     0,     0,     0,   161,   162,
       0,     0,     0,     0,     0,     0,     0,     0,   291,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   158,     0,     0,     0,     0,   214,
     215,   159,   160,     0,     0,     0,     0,   161,   162,     4,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,   158,     0,     0,     0,     0,
       0,     0,   159,   160,     0,     0,     0,     0,   161,   162,
      24,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,   158,     0,     0,     0,
       0,     0,     0,   159,   160,     0,     0,     0,     0,   161,
     162
>>>>>>> More cosmetic changes.
};

static const yytype_int16 yycheck[] =
{
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
       2,    14,    15,    16,    17,   109,   209,     5,   102,   280,
     286,    45,   116,   205,     0,   119,    47,    11,    12,    21,
      13,    50,     0,    54,    58,    23,   218,   303,    41,     1,
      59,   135,     8,   285,   128,   287,    11,    12,    42,    11,
      12,    16,   136,   137,   315,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    47,    56,    49,    57,    37,    38,    39,    40,    13,
      13,    47,   324,    45,    46,    47,    11,    12,   330,    13,
      55,    16,    52,   232,    56,   213,     1,    60,     3,     4,
       5,     6,     7,     8,     9,    10,    48,    60,   100,   101,
     204,    36,    56,   306,   253,    59,    47,    59,   311,    53,
      53,    53,    47,    57,    57,   219,   210,   211,    33,    53,
      55,   249,   111,    57,    33,   114,    41,    36,   232,   118,
      10,    48,    47,   122,   337,    34,    35,    48,   242,   243,
       1,   130,    59,    42,    43,    44,    45,    46,    59,   253,
      11,    12,    45,    46,    52,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    57,    47,   268,    36,    37,    38,    39,    40,
      54,    52,    32,   185,    45,    46,    47,   291,    52,    39,
      40,    45,    46,    54,    55,    45,    46,    43,    55,    45,
      46,    53,    43,   216,    45,    46,    55,    47,   221,    49,
      56,    62,    63,    52,    54,    56,    52,   230,   220,    47,
      52,    49,    52,   225,   226,   227,    54,    52,    43,   231,
      45,    46,    43,    52,    45,    46,    62,    63,   342,    11,
      12,   190,   191,    52,    52,   349,   244,    52,    52,    52,
      63,    53,    52,    63,    53,    53,    63,    53,    53,    53,
     262,    53,    59,    56,    52,    56,    12,    52,    55,    52,
      59,    61,    58,   286,    55,    54,    58,    54,   280,    59,
      54,    54,    58,    54,    54,    11,    52,    56,    56,    56,
     303,    56,    55,    55,    15,    56,    55,    61,     1,    59,
      56,    55,    59,   284,   349,   219,   225,   320,   330,   262,
     340,    -1,   289,   315,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      -1,    -1,    -1,    -1,    37,    38,    39,    40,     1,    -1,
      -1,    -1,    45,    46,    47,    -1,    -1,    -1,    -1,    -1,
      -1,    54,    -1,    -1,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      -1,    -1,    -1,    -1,    37,    38,    39,    40,     1,    -1,
      -1,    -1,    45,    46,    47,    -1,    -1,    -1,    -1,    -1,
      -1,    54,    -1,    -1,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      -1,    -1,    -1,    -1,    37,    38,    39,    40,    -1,    -1,
      -1,    -1,    45,    46,    47,    -1,    -1,    -1,    -1,    -1,
      -1,    54,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      -1,    -1,    -1,    -1,    45,    -1,    47,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    -1,    -1,    -1,    -1,    45,
      46,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    -1,
      -1,    -1,    -1,    45,    46,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    -1,    -1,    -1,    -1,    45,    46,     3,
       4,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    -1,    -1,    -1,
      -1,    45,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      -1,    -1,    -1,    -1,    45,     3,     4,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    -1,    -1,    -1,    -1,    45,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    -1,    -1,    -1,    -1,
      45,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    -1,
      -1,    -1,    -1,    45,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    -1,    -1,    -1,    -1,    45,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    -1,    -1,    -1,    -1,    45,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    -1,    -1,    -1,    -1,
      37,    38,    39,    40,    -1,    -1,    -1,    -1,    45,    46,
      47,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    -1,    -1,    -1,
      -1,    37,    38,    39,    40,    -1,    -1,    -1,    -1,    45,
      46,    47,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    -1,    -1,
      -1,    -1,    -1,    -1,    39,    40,    -1,    -1,    -1,    -1,
      45,    46,    47,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    -1,
      -1,    -1,    -1,    37,    38,    39,    40,    -1,    -1,    -1,
      -1,    45,    46,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    -1,
      -1,    -1,    -1,    -1,    -1,    39,    40,    -1,    -1,    -1,
      -1,    45,    46
=======
       2,    14,    15,    16,    17,     5,   111,   219,   215,   104,
     290,    47,   263,   118,    45,    32,   121,     0,    54,    13,
      22,    12,    39,    40,    24,   305,    42,    58,    45,    46,
      43,     1,     8,   138,    13,   289,   131,   288,    56,    13,
      13,    59,    12,   255,   139,   140,   141,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    57,    47,    56,    49,    37,    38,    39,
      40,   286,   326,    49,    53,    45,    46,    47,    57,    53,
      53,    45,    46,    57,    57,     1,    56,     3,     4,     5,
       6,     7,     8,     9,    10,    11,    43,   238,    45,    46,
     102,   103,   309,   318,     0,   210,    52,   314,   113,    56,
      43,   116,    45,    46,   211,   120,    45,    33,   259,   124,
     225,   216,   217,    56,    48,    41,    60,   224,   133,    34,
      35,    47,   339,   238,    48,    59,    47,    42,    43,    44,
      45,    46,    48,   248,   249,    59,    50,     1,    60,    47,
      47,    49,    49,    59,   259,    59,    54,    54,    43,    11,
      45,    46,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,   274,
      47,    52,    36,    37,    38,    39,    40,    54,   190,    53,
     295,    45,    46,    47,    43,    34,    45,    46,    37,    52,
      54,    55,    45,    46,    62,    63,    62,    63,    52,   222,
     195,   196,    52,    55,   227,    52,    52,    52,    52,    57,
      61,    52,    55,   236,   226,    52,    58,    53,    52,   231,
     232,   233,    52,    52,    52,   237,    52,    52,    52,   344,
      53,    53,    53,   288,    61,   225,   351,    53,    53,    53,
     250,    53,    59,    63,    63,    63,    56,    56,    59,    52,
      58,    55,    52,    55,    59,    54,   268,    58,    54,    54,
      54,    52,    54,    52,    54,    58,    12,   290,    56,    56,
      56,    56,    55,    55,   286,    56,    15,    56,    55,    59,
      55,    59,   305,   351,   231,   332,   268,    -1,   342,    -1,
      -1,     1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   322,
      -1,    -1,    -1,    -1,    -1,    -1,   318,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    -1,    -1,    -1,    -1,    37,    38,    39,
      40,     1,    -1,    -1,    -1,    45,    46,    47,    -1,    -1,
      -1,    -1,    -1,    -1,    54,    -1,    -1,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    -1,    -1,    -1,    -1,    37,    38,    39,
      40,     1,    -1,    -1,    -1,    45,    46,    47,    -1,    -1,
      -1,    -1,    -1,    -1,    54,    -1,    -1,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    -1,    -1,    -1,    -1,    37,    38,    39,
      40,    -1,    -1,    -1,    -1,    45,    46,    47,    -1,     3,
       4,     5,     6,     7,    54,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    -1,    -1,    -1,
      -1,    45,    -1,    47,     3,     4,     5,     6,     7,    -1,
=======
       2,   104,    14,    15,    16,    17,     5,   111,   215,     0,
      48,   264,     0,    13,   118,    12,    42,   121,   239,    48,
      22,    59,    52,     8,     1,    24,    45,    13,   131,   219,
      59,    43,    13,    13,   138,    12,   289,   140,   141,   260,
=======
       2,    14,    15,    16,    17,     5,   111,   215,   240,   104,
     292,    48,   288,   118,    45,   211,   121,     0,     0,    13,
      22,    12,    59,    42,    24,   307,    48,    58,   224,   261,
      43,     1,     8,   138,    13,   291,   131,    59,    56,    13,
      13,    59,    12,   219,   320,   140,   141,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    57,    47,    56,    49,    37,    38,    39,
      40,   265,   328,    49,    53,    45,    46,    47,    57,    53,
      53,   257,    45,    57,    57,     1,    56,     3,     4,     5,
       6,     7,     8,     9,    10,    11,   290,    52,    48,   113,
     102,   103,   116,   311,   199,   210,   120,    50,   316,    59,
     124,    43,    34,    45,    46,    37,    59,    33,    60,   133,
     225,   216,   217,    47,    56,    41,    43,    47,    45,    46,
      54,    47,    60,   341,    54,   240,    32,   139,    47,    56,
      47,     1,    49,    39,    40,   250,   251,    54,    52,    45,
      46,    43,    11,    45,    46,    53,   261,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    43,    52,    45,    46,    37,    38,    39,
      40,   276,    45,    46,    52,    45,    46,    47,   190,    34,
      35,    52,   297,    57,    54,    45,    46,    42,    43,    44,
      45,    46,    55,    47,    52,    49,    62,    63,    55,   222,
      54,    62,    63,    52,   227,   195,   196,    52,    52,    52,
      58,    52,    63,    53,   226,   238,    52,    52,    52,   231,
     232,   233,    52,    52,    52,    63,    53,   239,    52,    61,
      53,   346,    53,    53,    53,    12,    53,    63,   353,    53,
      56,    59,   252,    56,    59,    52,    58,    55,    52,    55,
      59,    54,    54,    58,    54,    54,    52,    54,   270,    54,
      58,    15,    56,    56,    56,    56,    52,    55,    55,   292,
      59,    61,    56,    56,    55,    55,   288,    59,   225,   290,
     353,   231,   270,   334,   307,   344,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     1,    -1,    -1,    -1,    -1,    -1,
      -1,   324,    -1,    -1,    -1,    -1,    -1,    -1,   320,    16,
>>>>>>> Added better error handling logic to the parser.
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    -1,    -1,    -1,    36,
      37,    38,    39,    40,     1,    -1,    -1,    -1,    45,    46,
      47,    -1,    -1,    -1,    -1,    -1,    -1,    54,    55,    -1,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    -1,    -1,    -1,    -1,
      37,    38,    39,    40,     1,    -1,    -1,    -1,    45,    46,
      47,    -1,    -1,    -1,    -1,    -1,    -1,    54,    -1,    -1,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    -1,    -1,    -1,    -1,
      37,    38,    39,    40,     1,    -1,    -1,    -1,    45,    46,
      47,    -1,    -1,    -1,    -1,    -1,    -1,    54,    -1,    -1,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    -1,    -1,    -1,    -1,
      -1,    -1,    39,    40,    -1,    -1,    -1,    -1,    45,    46,
      47,     3,     4,     5,     6,     7,    -1,     9,    10,    11,
=======
       2,   112,    14,    15,    16,    17,     5,   220,   119,   105,
     216,   122,   265,   240,   292,   288,    48,     0,    45,    46,
      22,     1,    48,    13,     0,    24,    45,    59,   139,   307,
      12,    43,     1,    59,   261,    13,   132,   290,    42,    58,
      13,    13,     8,    12,   257,   141,   142,   320,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    47,    45,    49,    57,    37,    38,
      39,    40,   291,    50,    56,    53,    45,    46,    47,    57,
      53,    53,    59,    49,    57,    57,     1,    56,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    48,   212,    47,
     211,   103,   104,    52,   200,   311,    54,    60,    59,   328,
     316,   225,    47,   114,    49,   226,   117,    60,    33,    54,
     121,   217,   218,    47,   125,    49,    41,    47,    56,   240,
      54,    59,    47,   134,    32,   341,    47,     1,   140,   250,
     251,    39,    40,    54,    45,    46,    34,    45,    46,    37,
     261,    11,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    62,
      63,    52,    36,    37,    38,    39,    40,    62,    63,    53,
     276,    45,    46,    47,    52,    43,   297,    45,    46,   191,
      54,    55,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,   196,   197,
      52,   223,    37,    38,    39,    40,   228,    52,    52,    52,
      45,    46,    47,    52,    52,   227,   238,    57,    55,    55,
     232,   233,   234,    52,    58,   346,    43,   239,    45,    46,
      52,    43,   353,    45,    46,    53,    52,    34,    35,    56,
      53,    52,    52,   252,    56,    42,    43,    44,    45,    46,
      43,    52,    45,    46,    52,    63,    52,    52,   270,    53,
      63,    53,    53,    63,    53,    53,    53,    12,    15,    59,
     292,    56,    56,    52,    55,    61,   288,    59,    58,    55,
      52,    54,    59,    58,    54,   307,    54,    54,    52,    54,
      61,    54,    58,     1,    56,    56,    56,    56,    52,    55,
      55,    59,   324,    56,    56,    55,    55,   226,   320,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    59,   290,   353,   232,    37,
      38,    39,    40,     1,   270,   334,   344,    45,    46,    47,
      -1,    -1,    -1,    -1,    -1,    -1,    54,    -1,    -1,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    -1,    -1,    -1,    -1,    37,
      38,    39,    40,     1,    -1,    -1,    -1,    45,    46,    47,
      -1,    -1,    -1,    -1,    -1,    -1,    54,    -1,    -1,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    -1,    -1,    -1,    -1,    37,
      38,    39,    40,    -1,    -1,    -1,    -1,    45,    46,    47,
      -1,     3,     4,     5,     6,     7,    54,     9,    10,    11,
>>>>>>> More cosmetic changes.
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    -1,
      -1,    -1,    -1,    45,    -1,    47,     3,     4,     5,     6,
       7,    -1,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    -1,    -1,    -1,    -1,    45,    46,
       3,     4,     5,     6,     7,    -1,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    -1,    -1,
      -1,    -1,    45,    46,     3,     4,     5,     6,     7,    -1,
>>>>>>> Added support for type-alias metadata.
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    -1,    -1,    -1,    -1,    45,    46,     3,     4,
       5,     6,     7,    -1,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    -1,    -1,    -1,    -1,
      45,     3,     4,     5,     6,     7,    -1,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,    -1,
      -1,    -1,    -1,    45,     3,     4,     5,     6,     7,    -1,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    -1,    -1,    -1,    -1,    45,     3,     4,     5,
       6,     7,    -1,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    -1,    -1,    -1,    -1,    45,
       3,     4,     5,     6,     7,    -1,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    -1,    -1,
      -1,    -1,    45,     3,     4,     5,     6,     7,    -1,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    -1,    -1,    -1,    -1,    45,     3,     4,     5,     6,
       7,    -1,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    -1,    -1,    -1,    -1,    45,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    -1,    -1,    -1,    36,
      37,    38,    39,    40,    -1,    -1,    -1,    -1,    45,    46,
      47,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    55,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    -1,    -1,    -1,    -1,
      37,    38,    39,    40,    -1,    -1,    -1,    -1,    45,    46,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    55,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    -1,    -1,    -1,    -1,    37,
      38,    39,    40,    -1,    -1,    -1,    -1,    45,    46,    47,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    -1,    -1,    -1,    -1,
<<<<<<< HEAD
<<<<<<< HEAD
      -1,    -1,    39,    40,    -1,    -1,    -1,    -1,    45,    46
>>>>>>> Regenerated compilers, and fixed build errors.
=======
      37,    38,    39,    40,    -1,    -1,    -1,    -1,    45,    46,
      47,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    -1,    -1,    -1,
      -1,    -1,    -1,    39,    40,    -1,    -1,    -1,    -1,    45,
<<<<<<< HEAD
      46,    47
>>>>>>> Added support for type-alias metadata.
=======
      46,    47,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    -1,    -1,
      -1,    -1,    -1,    -1,    39,    40,    -1,    -1,    -1,    -1,
      45,    46
>>>>>>> Added better error handling logic to the parser.
=======
      -1,    -1,    39,    40,    -1,    -1,    -1,    -1,    45,    46,
      47,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    -1,    -1,    -1,
      -1,    -1,    -1,    39,    40,    -1,    -1,    -1,    -1,    45,
      46
>>>>>>> More cosmetic changes.
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
<<<<<<< HEAD
       0,    65,    69,     0,    47,    49,    67,    68,    42,   146,
     147,   147,     1,     3,     4,     5,     6,     7,     8,     9,
      10,    33,    41,    47,    70,    84,    87,    88,    89,    94,
      95,    96,    98,    99,   100,   101,   115,   116,   117,   123,
     124,   125,   126,   127,   149,   146,    48,    59,    50,    52,
      45,    46,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      45,    46,   141,   150,    45,   150,    45,   150,    45,   150,
      60,    60,    68,    10,   147,    71,    13,    57,    91,   104,
      76,    77,    97,    78,    79,   103,   104,    72,    73,   104,
     120,    74,    75,    80,    81,    45,   129,   150,    57,   130,
      82,    83,   146,    85,    86,    55,    68,    68,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    39,    40,    45,    46,   140,   142,
     143,    48,    52,    66,    90,   140,    52,    66,    53,    52,
      66,   102,   140,    52,    66,    32,    39,    40,   119,   140,
     118,    52,    66,    52,    52,    53,   143,   128,    66,    52,
      53,    53,    43,   140,   143,   143,    62,    63,    63,    63,
      62,    63,    63,    45,    58,    53,     1,    37,    38,    68,
      92,    93,   105,   106,   107,   143,   144,   145,    53,    59,
      53,    68,   131,   132,   133,    53,    69,    69,    56,    56,
      61,    59,    58,    34,    35,    42,    43,    44,   140,   148,
     107,    52,    55,    55,    47,   145,   143,   143,    52,   106,
      54,    45,   150,    58,   107,   119,     1,    68,   114,    45,
     150,    54,    59,   131,    54,    54,    45,   150,    68,   148,
      54,    43,    56,   140,    43,    56,   140,   147,   148,    54,
      52,    11,    12,    16,    36,    55,   109,   110,   111,   135,
      54,    58,   133,    54,   143,    56,    56,    56,    56,    48,
     114,    12,    11,   109,    56,   108,   135,    45,   141,   150,
       1,   135,   136,   137,   138,    52,   144,    43,   134,   140,
      61,   141,   150,    56,    59,   145,    55,    55,    56,   145,
      59,    56,   114,    45,   150,    55,    55,   135,   113,   136,
     112,   145,    15,   139,   139,   121,   122,   140,   150,    59,
     121
=======
       0,    65,    69,     0,    47,    49,    67,    68,    42,   148,
     149,   149,     1,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    33,    41,    47,    70,    85,    88,    89,    90,
      95,    96,    97,    99,   100,   101,   102,   116,   117,   118,
     124,   125,   126,   127,   128,   129,   151,   148,    48,    59,
      50,    52,    45,    46,     3,     4,     5,     6,     7,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    45,    46,   143,   152,    45,   152,    45,   152,    45,
<<<<<<< HEAD
     152,    45,    60,    60,    68,    11,   149,    71,    13,    57,
      92,   105,    76,    77,    98,    78,    79,   104,   105,    72,
      73,   105,   121,    74,    75,    81,    80,    82,    45,   131,
     152,    57,   132,    83,    84,   148,    86,    87,    55,    58,
      68,    68,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    39,    40,
      45,    46,   142,   144,   145,    48,    52,    66,    91,   142,
      52,    66,    53,    52,    66,   103,   142,    52,    66,    32,
      39,    40,   120,   142,   119,    52,    66,    52,    52,    52,
      53,   145,   130,    66,    52,    53,    53,    43,   142,    68,
     145,   145,    62,    63,    63,    63,    62,    63,    63,    45,
      58,    53,     1,    37,    38,    68,    93,    94,   106,   107,
     108,   145,   146,   147,    53,    59,    53,    68,   133,   134,
<<<<<<< HEAD
<<<<<<< HEAD
     135,    53,    69,    69,    56,    56,    61,    59,    58,    34,
      35,    42,    43,    44,   142,   150,   108,    52,    55,    55,
      47,   147,   145,   145,    52,   107,    54,    45,   152,    58,
     108,   120,     1,    68,   115,    45,   152,    54,    59,   133,
      54,    54,    45,   152,    68,   150,    54,    43,    56,   142,
      43,    56,   142,   149,   150,    54,    52,    16,    36,    55,
     110,   111,   112,   146,    54,    58,   135,    54,   145,    56,
      56,    56,    56,    48,   115,   110,    12,    56,   109,   137,
      45,   143,   152,     1,   137,   138,   139,   140,    52,    43,
     136,   142,    61,   143,   152,    56,    59,   147,    55,    55,
      56,   147,    59,    56,   115,    45,   152,    55,    55,   137,
     114,   138,   113,   147,    15,   141,   141,   122,   123,   142,
     152,    59,   122
>>>>>>> Regenerated compilers, and fixed build errors.
=======
     135,    53,    69,    69,    56,    56,   145,    61,    59,    58,
      34,    35,    42,    43,    44,   142,   150,   108,    52,    55,
      55,    47,   147,   145,   145,    52,   107,    54,    45,   152,
      58,   108,   120,     1,    68,   115,    45,   152,    54,    59,
     133,    54,    54,    45,   152,    68,   150,    54,    43,    56,
     142,    43,    56,   142,   149,   150,    54,    52,    16,    36,
      55,   110,   111,   112,   146,    54,    58,   135,    54,   145,
      56,    56,    56,    56,    48,   115,   110,    12,    56,   109,
     137,    45,   143,   152,     1,   137,   138,   139,   140,    52,
      43,   136,   142,    61,   143,   152,    56,    59,   147,    55,
      55,    56,   147,    59,    56,   115,    45,   152,    55,    55,
     137,   114,   138,   113,   147,    15,   141,   141,   122,   123,
     142,   152,    59,   122
>>>>>>> Added support for type-alias metadata.
=======
     135,    53,    69,    69,    56,    56,     1,   145,    61,    59,
=======
     152,     1,    45,    60,    60,    68,    11,   149,    71,    13,
      57,    92,   105,    76,    77,    98,    78,    79,   104,   105,
      72,    73,   105,   121,    74,    75,    81,    80,    82,    45,
     131,   152,    57,   132,    83,    84,   148,    86,    87,    55,
      58,    68,    68,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    39,
      40,    45,    46,   142,   144,   145,    48,    52,    66,    91,
     142,    52,    66,    53,    52,    66,   103,   142,    52,    66,
      32,    39,    40,   120,   142,   119,    52,    66,    52,    52,
      52,    53,   145,   130,    66,    52,    53,    53,    43,   142,
      68,   145,   145,    62,    63,    63,    63,    62,    63,    63,
      45,    58,    53,     1,    37,    38,    68,    93,    94,   106,
     107,   108,   145,   146,   147,    53,    59,    53,    68,   133,
     134,   135,    53,    69,    69,    56,    56,   145,    61,    59,
>>>>>>> More cosmetic changes.
      58,    34,    35,    42,    43,    44,   142,   150,   108,    52,
      55,    55,    47,   147,   145,   145,    52,   107,    54,    45,
     152,    58,   108,   120,     1,    68,   115,    45,   152,    54,
      59,   133,    54,    54,    45,   152,    68,   150,    54,    43,
      56,   142,    43,    56,   142,   149,   150,    54,    52,    16,
      36,    55,   110,   111,   112,   146,    54,    58,   135,    54,
     145,    56,    56,    56,    56,    48,   115,   110,    12,    56,
     109,   137,    45,   143,   152,     1,   137,   138,   139,   140,
      52,    43,   136,   142,    61,   143,   152,    56,    59,   147,
      55,    55,    56,   147,    59,    56,   115,    45,   152,    55,
      55,   137,   114,   138,   113,   147,    15,   141,   141,   122,
     123,   142,   152,    59,   122
>>>>>>> Added better error handling logic to the parser.
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    64,    65,    66,    66,    67,    68,    68,    68,    69,
      69,    69,    71,    70,    72,    70,    70,    73,    70,    74,
      70,    70,    75,    70,    76,    70,    70,    77,    70,    78,
<<<<<<< HEAD
<<<<<<< HEAD
      70,    70,    79,    70,    80,    70,    70,    81,    70,    70,
      82,    70,    83,    70,    70,    70,    85,    84,    86,    84,
      87,    87,    88,    90,    89,    91,    91,    92,    92,    92,
      92,    93,    93,    93,    93,    94,    94,    95,    97,    96,
      98,    98,    99,    99,    99,   100,   102,   101,   103,   103,
     104,   104,   105,   105,   106,   106,   106,   106,   107,   107,
     108,   108,   109,   109,   109,   109,   110,   110,   110,   110,
     112,   111,   113,   111,   114,   114,   114,   114,   115,   115,
     116,   118,   117,   119,   119,   119,   119,   119,   120,   120,
     121,   121,   122,   122,   123,   123,   124,   124,   125,   125,
     126,   126,   128,   127,   129,   127,   130,   130,   131,   131,
     131,   132,   132,   133,   133,   133,   134,   134,   135,   135,
     135,   135,   135,   136,   137,   137,   138,   138,   139,   139,
     140,   140,   141,   141,   142,   142,   142,   142,   142,   142,
     142,   142,   142,   142,   142,   142,   142,   142,   142,   143,
     143,   143,   143,   143,   143,   143,   143,   143,   143,   143,
     143,   144,   144,   144,   145,   145,   145,   145,   146,   146,
     147,   147,   148,   148,   148,   148,   148,   148,   149,   149,
     150,   150,   150,   150,   150,   150,   150,   150,   150,   150,
     150,   150,   150,   150,   150,   150,   150,   150,   150,   150,
     150,   150,   150,   150,   150,   150,   150,   150,   150,   150,
     150,   150,   150,   150,   150,   150,   150,   150
=======
      70,    70,    79,    70,    80,    70,    81,    70,    70,    70,
=======
      70,    70,    79,    70,    80,    70,    70,    81,    70,    70,
>>>>>>> Added alias test to C#.
      82,    70,    70,    83,    70,    84,    70,    70,    70,    86,
      85,    87,    85,    88,    88,    89,    91,    90,    92,    92,
      93,    93,    93,    93,    94,    94,    94,    94,    95,    95,
      96,    98,    97,    99,    99,   100,   100,   100,   101,   103,
     102,   104,   104,   105,   105,   106,   106,   107,   107,   107,
     107,   108,   108,   109,   109,   110,   110,   110,   110,   111,
     111,   111,   111,   113,   112,   114,   112,   115,   115,   115,
     115,   116,   116,   117,   119,   118,   120,   120,   120,   120,
     120,   121,   121,   122,   122,   123,   123,   124,   124,   124,
     125,   125,   126,   126,   127,   127,   128,   128,   130,   129,
     131,   129,   132,   132,   133,   133,   133,   134,   134,   135,
     135,   135,   136,   136,   137,   137,   138,   139,   139,   140,
     140,   141,   141,   142,   142,   143,   143,   144,   144,   144,
     144,   144,   144,   144,   144,   144,   144,   144,   144,   144,
     144,   144,   145,   145,   145,   145,   145,   145,   145,   145,
     145,   145,   145,   145,   146,   146,   146,   147,   147,   147,
     147,   148,   148,   149,   149,   150,   150,   150,   150,   150,
     150,   151,   151,   152,   152,   152,   152,   152,   152,   152,
     152,   152,   152,   152,   152,   152,   152,   152,   152,   152,
     152,   152,   152,   152,   152,   152,   152,   152,   152,   152,
<<<<<<< HEAD
     152,   152,   152,   152,   152,   152,   152,   152,   152
>>>>>>> Regenerated compilers, and fixed build errors.
=======
     152,   152,   152,   152,   152,   152,   152,   152,   152,   152
>>>>>>> Added better error handling logic to the parser.
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     0,     3,     3,     4,     0,     2,
       3,     0,     0,     3,     0,     3,     1,     0,     3,     0,
       3,     1,     0,     3,     0,     3,     1,     0,     3,     0,
<<<<<<< HEAD
<<<<<<< HEAD
       3,     1,     0,     3,     0,     3,     1,     0,     3,     1,
       0,     3,     0,     3,     1,     2,     0,     6,     0,     6,
       2,     2,     1,     0,     6,     2,     0,     4,     4,     3,
       1,     4,     4,     3,     1,     2,     2,     1,     0,     5,
       2,     2,     5,     5,     1,     1,     0,     6,     2,     0,
       1,     1,     1,     3,     2,     2,     1,     2,     1,     0,
       2,     4,     2,     3,     2,     1,     3,     4,     3,     4,
       0,     5,     0,     5,     4,     2,     3,     0,     2,     2,
       1,     0,     6,     3,     1,     1,     1,     1,     2,     0,
       3,     1,     1,     1,     6,     6,     9,     9,     2,     1,
       2,     2,     0,     6,     0,     5,     2,     0,     1,     2,
       0,     3,     1,     2,     4,     2,     1,     1,     1,     1,
       2,     2,     0,     2,     1,     3,     1,     0,     2,     0,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     2,
       2,     2,     2,     2,     1,     1,     1,     1,     1,     2,
       2,     2,     2,     1,     2,     2,     1,     2,     2,     1,
       3,     1,     1,     1,     1,     1,     1,     1,     6,     5,
=======
       3,     1,     0,     3,     0,     3,     0,     3,     1,     1,
=======
       3,     1,     0,     3,     0,     3,     1,     0,     3,     1,
>>>>>>> Added alias test to C#.
       0,     3,     1,     0,     3,     0,     3,     1,     2,     0,
       6,     0,     6,     2,     2,     1,     0,     6,     2,     0,
       4,     4,     3,     1,     4,     4,     3,     1,     2,     2,
       1,     0,     5,     2,     2,     5,     5,     1,     1,     0,
       6,     2,     0,     1,     1,     1,     3,     2,     2,     1,
       2,     1,     0,     2,     4,     1,     3,     2,     1,     3,
       4,     3,     4,     0,     5,     0,     5,     4,     2,     3,
       0,     2,     2,     1,     0,     6,     3,     1,     1,     1,
<<<<<<< HEAD
<<<<<<< HEAD
       1,     2,     0,     3,     1,     1,     1,     5,     2,     6,
       6,     9,     9,     2,     1,     2,     2,     0,     6,     0,
       5,     2,     0,     1,     2,     0,     3,     1,     2,     4,
       2,     1,     1,     1,     0,     2,     1,     3,     1,     0,
       2,     0,     1,     1,     1,     1,     1,     1,     1,     1,
>>>>>>> Regenerated compilers, and fixed build errors.
=======
       1,     2,     0,     3,     1,     1,     1,     5,     5,     2,
=======
       1,     2,     0,     3,     1,     1,     1,     5,     2,     2,
>>>>>>> More cosmetic changes.
       6,     6,     9,     9,     2,     1,     2,     2,     0,     6,
       0,     5,     2,     0,     1,     2,     0,     3,     1,     2,
       4,     2,     1,     1,     1,     0,     2,     1,     3,     1,
       0,     2,     0,     1,     1,     1,     1,     1,     1,     1,
>>>>>>> Added better error handling logic to the parser.
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     2,     2,     2,     2,     2,     1,     1,     1,
       1,     1,     2,     2,     2,     2,     1,     2,     2,     1,
       2,     2,     1,     3,     1,     1,     1,     1,     1,     1,
       1,     6,     5,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
<<<<<<< HEAD
<<<<<<< HEAD
       1,     1,     1,     1,     1,     1,     1,     1
=======
       1,     1,     1,     1,     1,     1,     1,     1,     1
>>>>>>> Regenerated compilers, and fixed build errors.
=======
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1
>>>>>>> Added better error handling logic to the parser.
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF

/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (0)
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

# ifndef YY_LOCATION_PRINT
#  if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

YY_ATTRIBUTE_UNUSED
static int
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  int res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += YYFPRINTF (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += YYFPRINTF (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += YYFPRINTF (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += YYFPRINTF (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += YYFPRINTF (yyo, "-%d", end_col);
    }
  return res;
 }

#   define YY_LOCATION_PRINT(File, Loc)          \
  yy_location_print_ (File, &(Loc))

#  else
#   define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#  endif
# endif /* !defined YY_LOCATION_PRINT */


# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value, Location); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  YYUSE (yylocationp);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yykind < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yykind], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  YY_LOCATION_PRINT (yyo, *yylocationp);
  YYFPRINTF (yyo, ": ");
  yy_symbol_value_print (yyo, yykind, yyvaluep, yylocationp);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)],
                       &(yylsp[(yyi + 1) - (yynrhs)]));
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, yylsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}






/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
/* Lookahead token kind.  */
int yychar;


/* The semantic value of the lookahead symbol.  */
/* Default value used for initialization, for pacifying older GCCs
   or non-GCC compilers.  */
YY_INITIAL_VALUE (static YYSTYPE yyval_default;)
YYSTYPE yylval YY_INITIAL_VALUE (= yyval_default);

/* Location data for the lookahead symbol.  */
static YYLTYPE yyloc_default
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;
YYLTYPE yylloc = yyloc_default;

    /* Number of syntax errors so far.  */
    int yynerrs = 0;

    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

    /* The location stack: array, bottom, top.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls = yylsa;
    YYLTYPE *yylsp = yyls;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

  /* The locations where the error started and ended.  */
  YYLTYPE yyerror_range[3];



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */
  yylsp[0] = yylloc;
  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;
        YYLTYPE *yyls1 = yyls;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yyls1, yysize * YYSIZEOF (*yylsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
        yyls = yyls1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
        YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex (&yylval, &yylloc);
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      yyerror_range[1] = yylloc;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END
  *++yylsp = yylloc;

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];

  /* Default location. */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  yyerror_range[1] = yyloc;
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 5: /* file_metadata: ICE_FILE_METADATA_OPEN string_list ICE_FILE_METADATA_CLOSE  */
<<<<<<< HEAD
#line 222 "src/Slice/Grammar.y"
=======
#line 218 "src/Slice/Grammar.y"
>>>>>>> Regenerated compilers, and fixed build errors.
{
    StringListTokPtr metadata = StringListTokPtr::dynamicCast(yyvsp[-1]);
    convertMetadata(metadata);
    yyval = metadata;
}
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
#line 1871 "src/Slice/Grammar.cpp"
    break;

  case 6: /* local_metadata: ICE_LOCAL_METADATA_OPEN string_list ICE_LOCAL_METADATA_CLOSE  */
#line 233 "src/Slice/Grammar.y"
=======
#line 1877 "src/Slice/Grammar.cpp"
=======
#line 1881 "src/Slice/Grammar.cpp"
>>>>>>> Added support for type-alias metadata.
=======
#line 1887 "src/Slice/Grammar.cpp"
>>>>>>> Added better error handling logic to the parser.
=======
#line 1873 "src/Slice/Grammar.cpp"
>>>>>>> More cosmetic changes.
    break;

  case 6: /* local_metadata: ICE_LOCAL_METADATA_OPEN string_list ICE_LOCAL_METADATA_CLOSE  */
#line 229 "src/Slice/Grammar.y"
>>>>>>> Regenerated compilers, and fixed build errors.
{
    StringListTokPtr metadata = StringListTokPtr::dynamicCast(yyvsp[-1]);
    convertMetadata(metadata);
    yyval = metadata;
}
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
#line 1881 "src/Slice/Grammar.cpp"
    break;

  case 7: /* local_metadata: local_metadata ICE_LOCAL_METADATA_OPEN string_list ICE_LOCAL_METADATA_CLOSE  */
#line 239 "src/Slice/Grammar.y"
=======
#line 1887 "src/Slice/Grammar.cpp"
=======
#line 1891 "src/Slice/Grammar.cpp"
>>>>>>> Added support for type-alias metadata.
=======
#line 1897 "src/Slice/Grammar.cpp"
>>>>>>> Added better error handling logic to the parser.
=======
#line 1883 "src/Slice/Grammar.cpp"
>>>>>>> More cosmetic changes.
    break;

  case 7: /* local_metadata: local_metadata ICE_LOCAL_METADATA_OPEN string_list ICE_LOCAL_METADATA_CLOSE  */
#line 235 "src/Slice/Grammar.y"
>>>>>>> Regenerated compilers, and fixed build errors.
{
    StringListTokPtr metadata1 = StringListTokPtr::dynamicCast(yyvsp[-3]);
    StringListTokPtr metadata2 = StringListTokPtr::dynamicCast(yyvsp[-1]);
    metadata1->v.splice(metadata1->v.end(), metadata2->v);

    convertMetadata(metadata1);
    yyval = metadata1;
}
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
#line 1894 "src/Slice/Grammar.cpp"
    break;

  case 8: /* local_metadata: %empty  */
#line 248 "src/Slice/Grammar.y"
{
    yyval = new StringListTok;
}
#line 1902 "src/Slice/Grammar.cpp"
    break;

  case 9: /* definitions: definitions file_metadata  */
#line 257 "src/Slice/Grammar.y"
=======
#line 1900 "src/Slice/Grammar.cpp"
=======
#line 1904 "src/Slice/Grammar.cpp"
>>>>>>> Added support for type-alias metadata.
=======
#line 1910 "src/Slice/Grammar.cpp"
>>>>>>> Added better error handling logic to the parser.
=======
#line 1896 "src/Slice/Grammar.cpp"
>>>>>>> More cosmetic changes.
    break;

  case 8: /* local_metadata: %empty  */
#line 244 "src/Slice/Grammar.y"
{
    yyval = new StringListTok;
}
#line 1904 "src/Slice/Grammar.cpp"
    break;

  case 9: /* definitions: definitions file_metadata  */
#line 253 "src/Slice/Grammar.y"
>>>>>>> Regenerated compilers, and fixed build errors.
{
    StringListTokPtr metadata = StringListTokPtr::dynamicCast(yyvsp[0]);
    if(!metadata->v.empty())
    {
        unit->addFileMetadata(metadata->v);
    }
}
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
#line 1914 "src/Slice/Grammar.cpp"
    break;

  case 10: /* definitions: definitions local_metadata definition  */
#line 265 "src/Slice/Grammar.y"
=======
#line 1920 "src/Slice/Grammar.cpp"
=======
#line 1924 "src/Slice/Grammar.cpp"
>>>>>>> Added support for type-alias metadata.
=======
#line 1930 "src/Slice/Grammar.cpp"
>>>>>>> Added better error handling logic to the parser.
=======
#line 1916 "src/Slice/Grammar.cpp"
>>>>>>> More cosmetic changes.
    break;

  case 10: /* definitions: definitions local_metadata definition  */
#line 261 "src/Slice/Grammar.y"
>>>>>>> Regenerated compilers, and fixed build errors.
{
    StringListTokPtr metadata = StringListTokPtr::dynamicCast(yyvsp[-1]);
    ContainedPtr contained = ContainedPtr::dynamicCast(yyvsp[0]);
    if(contained && !metadata->v.empty())
    {
        contained->setMetadata(metadata->v);
    }
}
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
#line 1927 "src/Slice/Grammar.cpp"
    break;

  case 12: /* $@1: %empty  */
#line 280 "src/Slice/Grammar.y"
{
    assert(yyvsp[0] == 0 || ModulePtr::dynamicCast(yyvsp[0]));
}
#line 1935 "src/Slice/Grammar.cpp"
    break;

  case 14: /* $@2: %empty  */
#line 285 "src/Slice/Grammar.y"
{
    assert(yyvsp[0] == 0 || ClassDeclPtr::dynamicCast(yyvsp[0]));
}
#line 1943 "src/Slice/Grammar.cpp"
    break;

  case 16: /* definition: class_decl  */
#line 290 "src/Slice/Grammar.y"
{
    unit->error("`;' missing after class forward declaration");
}
#line 1951 "src/Slice/Grammar.cpp"
    break;

  case 17: /* $@3: %empty  */
#line 294 "src/Slice/Grammar.y"
{
    assert(yyvsp[0] == 0 || ClassDefPtr::dynamicCast(yyvsp[0]));
}
#line 1959 "src/Slice/Grammar.cpp"
    break;

  case 19: /* $@4: %empty  */
#line 299 "src/Slice/Grammar.y"
{
    assert(yyvsp[0] == 0 || InterfaceDeclPtr::dynamicCast(yyvsp[0]));
}
#line 1967 "src/Slice/Grammar.cpp"
    break;

  case 21: /* definition: interface_decl  */
#line 304 "src/Slice/Grammar.y"
{
    unit->error("`;' missing after interface forward declaration");
}
#line 1975 "src/Slice/Grammar.cpp"
    break;

  case 22: /* $@5: %empty  */
#line 308 "src/Slice/Grammar.y"
{
    assert(yyvsp[0] == 0 || InterfaceDefPtr::dynamicCast(yyvsp[0]));
}
#line 1983 "src/Slice/Grammar.cpp"
    break;

  case 24: /* $@6: %empty  */
#line 313 "src/Slice/Grammar.y"
{
    assert(yyvsp[0] == 0);
}
#line 1991 "src/Slice/Grammar.cpp"
    break;

  case 26: /* definition: exception_decl  */
#line 318 "src/Slice/Grammar.y"
{
    unit->error("`;' missing after exception forward declaration");
}
#line 1999 "src/Slice/Grammar.cpp"
    break;

  case 27: /* $@7: %empty  */
#line 322 "src/Slice/Grammar.y"
{
    assert(yyvsp[0] == 0 || ExceptionPtr::dynamicCast(yyvsp[0]));
}
#line 2007 "src/Slice/Grammar.cpp"
    break;

  case 29: /* $@8: %empty  */
#line 327 "src/Slice/Grammar.y"
{
    assert(yyvsp[0] == 0);
}
#line 2015 "src/Slice/Grammar.cpp"
    break;

  case 31: /* definition: struct_decl  */
#line 332 "src/Slice/Grammar.y"
{
    unit->error("`;' missing after struct forward declaration");
}
#line 2023 "src/Slice/Grammar.cpp"
    break;

  case 32: /* $@9: %empty  */
#line 336 "src/Slice/Grammar.y"
{
    assert(yyvsp[0] == 0 || StructPtr::dynamicCast(yyvsp[0]));
}
#line 2031 "src/Slice/Grammar.cpp"
    break;

  case 34: /* $@10: %empty  */
#line 341 "src/Slice/Grammar.y"
{
    assert(yyvsp[0] == 0 || SequencePtr::dynamicCast(yyvsp[0]));
}
#line 2039 "src/Slice/Grammar.cpp"
    break;

  case 36: /* definition: sequence_def  */
#line 346 "src/Slice/Grammar.y"
{
    unit->error("`;' missing after sequence definition");
}
#line 2047 "src/Slice/Grammar.cpp"
    break;

  case 37: /* $@11: %empty  */
#line 350 "src/Slice/Grammar.y"
{
    assert(yyvsp[0] == 0 || DictionaryPtr::dynamicCast(yyvsp[0]));
}
#line 2055 "src/Slice/Grammar.cpp"
    break;

  case 39: /* definition: dictionary_def  */
#line 355 "src/Slice/Grammar.y"
{
    unit->error("`;' missing after dictionary definition");
}
#line 2063 "src/Slice/Grammar.cpp"
    break;

  case 40: /* $@12: %empty  */
#line 359 "src/Slice/Grammar.y"
{
    assert(yyvsp[0] == 0 || EnumPtr::dynamicCast(yyvsp[0]));
}
#line 2071 "src/Slice/Grammar.cpp"
    break;

  case 42: /* $@13: %empty  */
#line 364 "src/Slice/Grammar.y"
{
    assert(yyvsp[0] == 0 || ConstPtr::dynamicCast(yyvsp[0]));
}
#line 2079 "src/Slice/Grammar.cpp"
    break;

  case 44: /* definition: const_def  */
#line 369 "src/Slice/Grammar.y"
{
    unit->error("`;' missing after const definition");
}
#line 2087 "src/Slice/Grammar.cpp"
    break;

  case 45: /* definition: error ';'  */
#line 373 "src/Slice/Grammar.y"
{
    yyerrok;
}
#line 2095 "src/Slice/Grammar.cpp"
    break;

  case 46: /* @14: %empty  */
#line 382 "src/Slice/Grammar.y"
=======
#line 1933 "src/Slice/Grammar.cpp"
=======
#line 1937 "src/Slice/Grammar.cpp"
>>>>>>> Added support for type-alias metadata.
=======
#line 1943 "src/Slice/Grammar.cpp"
>>>>>>> Added better error handling logic to the parser.
=======
#line 1929 "src/Slice/Grammar.cpp"
>>>>>>> More cosmetic changes.
    break;

  case 12: /* $@1: %empty  */
#line 276 "src/Slice/Grammar.y"
{
    assert(yyvsp[0] == 0 || ModulePtr::dynamicCast(yyvsp[0]));
}
#line 1937 "src/Slice/Grammar.cpp"
    break;

  case 14: /* $@2: %empty  */
#line 281 "src/Slice/Grammar.y"
{
    assert(yyvsp[0] == 0 || ClassDeclPtr::dynamicCast(yyvsp[0]));
}
#line 1945 "src/Slice/Grammar.cpp"
    break;

  case 16: /* definition: class_decl  */
#line 286 "src/Slice/Grammar.y"
{
    unit->error("`;' missing after class forward declaration");
}
#line 1953 "src/Slice/Grammar.cpp"
    break;

  case 17: /* $@3: %empty  */
#line 290 "src/Slice/Grammar.y"
{
    assert(yyvsp[0] == 0 || ClassDefPtr::dynamicCast(yyvsp[0]));
}
#line 1961 "src/Slice/Grammar.cpp"
    break;

  case 19: /* $@4: %empty  */
#line 295 "src/Slice/Grammar.y"
{
    assert(yyvsp[0] == 0 || InterfaceDeclPtr::dynamicCast(yyvsp[0]));
}
#line 1969 "src/Slice/Grammar.cpp"
    break;

  case 21: /* definition: interface_decl  */
#line 300 "src/Slice/Grammar.y"
{
    unit->error("`;' missing after interface forward declaration");
}
#line 1977 "src/Slice/Grammar.cpp"
    break;

  case 22: /* $@5: %empty  */
#line 304 "src/Slice/Grammar.y"
{
    assert(yyvsp[0] == 0 || InterfaceDefPtr::dynamicCast(yyvsp[0]));
}
#line 1985 "src/Slice/Grammar.cpp"
    break;

  case 24: /* $@6: %empty  */
#line 309 "src/Slice/Grammar.y"
{
    assert(yyvsp[0] == 0);
}
#line 1993 "src/Slice/Grammar.cpp"
    break;

  case 26: /* definition: exception_decl  */
#line 314 "src/Slice/Grammar.y"
{
    unit->error("`;' missing after exception forward declaration");
}
#line 2001 "src/Slice/Grammar.cpp"
    break;

  case 27: /* $@7: %empty  */
#line 318 "src/Slice/Grammar.y"
{
    assert(yyvsp[0] == 0 || ExceptionPtr::dynamicCast(yyvsp[0]));
}
#line 2009 "src/Slice/Grammar.cpp"
    break;

  case 29: /* $@8: %empty  */
#line 323 "src/Slice/Grammar.y"
{
    assert(yyvsp[0] == 0);
}
#line 2017 "src/Slice/Grammar.cpp"
    break;

  case 31: /* definition: struct_decl  */
#line 328 "src/Slice/Grammar.y"
{
    unit->error("`;' missing after struct forward declaration");
}
#line 2025 "src/Slice/Grammar.cpp"
    break;

  case 32: /* $@9: %empty  */
#line 332 "src/Slice/Grammar.y"
{
    assert(yyvsp[0] == 0 || StructPtr::dynamicCast(yyvsp[0]));
}
#line 2033 "src/Slice/Grammar.cpp"
    break;

  case 34: /* $@10: %empty  */
#line 337 "src/Slice/Grammar.y"
{
    assert(yyvsp[0] == 0 || SequencePtr::dynamicCast(yyvsp[0]));
}
#line 2041 "src/Slice/Grammar.cpp"
    break;

  case 36: /* definition: sequence_def  */
#line 342 "src/Slice/Grammar.y"
{
    unit->error("`;' missing after sequence definition");
}
#line 2049 "src/Slice/Grammar.cpp"
    break;

  case 37: /* $@11: %empty  */
#line 346 "src/Slice/Grammar.y"
{
    assert(yyvsp[0] == 0 || TypeAliasPtr::dynamicCast(yyvsp[0]));
}
#line 2057 "src/Slice/Grammar.cpp"
    break;

  case 39: /* definition: type_alias_def  */
#line 351 "src/Slice/Grammar.y"
{
    unit->error("`;' missing after type-alias");
}
#line 2065 "src/Slice/Grammar.cpp"
    break;

  case 40: /* $@12: %empty  */
#line 355 "src/Slice/Grammar.y"
{
    assert(yyvsp[0] == 0 || DictionaryPtr::dynamicCast(yyvsp[0]));
}
#line 2073 "src/Slice/Grammar.cpp"
    break;

  case 42: /* definition: dictionary_def  */
#line 360 "src/Slice/Grammar.y"
{
    unit->error("`;' missing after dictionary definition");
}
#line 2081 "src/Slice/Grammar.cpp"
    break;

  case 43: /* $@13: %empty  */
#line 364 "src/Slice/Grammar.y"
{
    assert(yyvsp[0] == 0 || EnumPtr::dynamicCast(yyvsp[0]));
}
#line 2089 "src/Slice/Grammar.cpp"
    break;

  case 45: /* $@14: %empty  */
#line 369 "src/Slice/Grammar.y"
{
    assert(yyvsp[0] == 0 || ConstPtr::dynamicCast(yyvsp[0]));
}
#line 2097 "src/Slice/Grammar.cpp"
    break;

  case 47: /* definition: const_def  */
#line 374 "src/Slice/Grammar.y"
{
    unit->error("`;' missing after const definition");
}
#line 2105 "src/Slice/Grammar.cpp"
    break;

  case 48: /* definition: error ';'  */
#line 378 "src/Slice/Grammar.y"
{
    yyerrok;
}
#line 2113 "src/Slice/Grammar.cpp"
    break;

  case 49: /* @15: %empty  */
#line 387 "src/Slice/Grammar.y"
>>>>>>> Regenerated compilers, and fixed build errors.
{
    StringTokPtr ident = StringTokPtr::dynamicCast(yyvsp[0]);
    ContainerPtr cont = unit->currentContainer();

    ModulePtr module;
    if (UnitPtr ut = UnitPtr::dynamicCast(cont))
    {
        module = ut->createModule(ident->v);
    }
    else if (ModulePtr mod = ModulePtr::dynamicCast(cont))
    {
        module = mod->createModule(ident->v);
    }

    if(module)
    {
        cont->checkIntroduced(ident->v, module);
        unit->pushContainer(module);
        yyval = module;
    }
    else
    {
        yyval = 0;
    }
}
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
#line 2125 "src/Slice/Grammar.cpp"
    break;

  case 47: /* module_def: ICE_MODULE ICE_IDENTIFIER @14 '{' definitions '}'  */
#line 408 "src/Slice/Grammar.y"
=======
#line 2147 "src/Slice/Grammar.cpp"
=======
#line 2151 "src/Slice/Grammar.cpp"
>>>>>>> Added support for type-alias metadata.
=======
#line 2157 "src/Slice/Grammar.cpp"
>>>>>>> Added better error handling logic to the parser.
=======
#line 2143 "src/Slice/Grammar.cpp"
>>>>>>> More cosmetic changes.
    break;

  case 50: /* module_def: ICE_MODULE ICE_IDENTIFIER @15 '{' definitions '}'  */
#line 413 "src/Slice/Grammar.y"
>>>>>>> Regenerated compilers, and fixed build errors.
{
    if(yyvsp[-3])
    {
        unit->popContainer();
        yyval = yyvsp[-3];
    }
    else
    {
        yyval = 0;
    }
}
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
#line 2141 "src/Slice/Grammar.cpp"
    break;

  case 48: /* @15: %empty  */
#line 420 "src/Slice/Grammar.y"
=======
#line 2163 "src/Slice/Grammar.cpp"
=======
#line 2167 "src/Slice/Grammar.cpp"
>>>>>>> Added support for type-alias metadata.
=======
#line 2173 "src/Slice/Grammar.cpp"
>>>>>>> Added better error handling logic to the parser.
=======
#line 2159 "src/Slice/Grammar.cpp"
>>>>>>> More cosmetic changes.
    break;

  case 51: /* @16: %empty  */
#line 425 "src/Slice/Grammar.y"
>>>>>>> Regenerated compilers, and fixed build errors.
{
    StringTokPtr ident = StringTokPtr::dynamicCast(yyvsp[0]);

    // Split the 'scoped identifier' into separate module names.
    vector<string> modules;
    size_t startPos = 0;
    size_t endPos;
    while((endPos = ident->v.find("::", startPos)) != string::npos)
    {
        modules.push_back(ident->v.substr(startPos, (endPos - startPos)));
        startPos = endPos + 2;
    }
    modules.push_back(ident->v.substr(startPos));

    // Create the nested modules.
    ContainerPtr cont = unit->currentContainer();
    ModulePtr parent;
    size_t i = 0;
    if (UnitPtr ut = UnitPtr::dynamicCast(cont))
    {
        parent = ut->createModule(modules[i++]);
        if (parent)
        {
            ut->checkIntroduced(ident->v, parent);
            unit->pushContainer(parent);
        }
    }

    if (i == 0 || parent)
    {
        parent = unit->currentModule();
        for (; i < modules.size(); i++)
        {
            if (ModulePtr module = parent->createModule(modules[i]))
            {
                parent->checkIntroduced(ident->v, module);
                unit->pushContainer(module);
                parent = module;
            }
            else
            {
                // If an error occurs creating one of the modules, back up the entire chain.
                for(; i > 0; i--)
                {
                    unit->popContainer();
                }
                parent = nullptr;
                break;
            }
        }
    }

    yyval = parent;
}
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
#line 2200 "src/Slice/Grammar.cpp"
    break;

  case 49: /* module_def: ICE_MODULE ICE_SCOPED_IDENTIFIER @15 '{' definitions '}'  */
#line 475 "src/Slice/Grammar.y"
=======
#line 2222 "src/Slice/Grammar.cpp"
=======
#line 2226 "src/Slice/Grammar.cpp"
>>>>>>> Added support for type-alias metadata.
=======
#line 2232 "src/Slice/Grammar.cpp"
>>>>>>> Added better error handling logic to the parser.
=======
#line 2218 "src/Slice/Grammar.cpp"
>>>>>>> More cosmetic changes.
    break;

  case 52: /* module_def: ICE_MODULE ICE_SCOPED_IDENTIFIER @16 '{' definitions '}'  */
#line 480 "src/Slice/Grammar.y"
>>>>>>> Regenerated compilers, and fixed build errors.
{
    if(yyvsp[-3])
    {
        StringTokPtr ident = StringTokPtr::dynamicCast(yyvsp[-4]);
        size_t startPos = 0;
        while((startPos = ident->v.find("::", startPos + 2)) != string::npos)
        {
            unit->popContainer();
        }
        yyval = unit->currentContainer();
        unit->popContainer();
    }
    else
    {
        yyval = 0;
    }
}
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
#line 2222 "src/Slice/Grammar.cpp"
    break;

  case 50: /* exception_id: ICE_EXCEPTION ICE_IDENTIFIER  */
#line 498 "src/Slice/Grammar.y"
{
    yyval = yyvsp[0];
}
#line 2230 "src/Slice/Grammar.cpp"
    break;

  case 51: /* exception_id: ICE_EXCEPTION keyword  */
#line 502 "src/Slice/Grammar.y"
=======
#line 2244 "src/Slice/Grammar.cpp"
=======
#line 2248 "src/Slice/Grammar.cpp"
>>>>>>> Added support for type-alias metadata.
=======
#line 2254 "src/Slice/Grammar.cpp"
>>>>>>> Added better error handling logic to the parser.
=======
#line 2240 "src/Slice/Grammar.cpp"
>>>>>>> More cosmetic changes.
    break;

  case 53: /* exception_id: ICE_EXCEPTION ICE_IDENTIFIER  */
#line 503 "src/Slice/Grammar.y"
{
    yyval = yyvsp[0];
}
#line 2248 "src/Slice/Grammar.cpp"
    break;

  case 54: /* exception_id: ICE_EXCEPTION keyword  */
#line 507 "src/Slice/Grammar.y"
>>>>>>> Regenerated compilers, and fixed build errors.
{
    StringTokPtr ident = StringTokPtr::dynamicCast(yyvsp[0]);
    unit->error("keyword `" + ident->v + "' cannot be used as exception name");
    yyval = yyvsp[0]; // Dummy
}
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
#line 2240 "src/Slice/Grammar.cpp"
    break;

  case 52: /* exception_decl: exception_id  */
#line 513 "src/Slice/Grammar.y"
=======
#line 2262 "src/Slice/Grammar.cpp"
=======
#line 2266 "src/Slice/Grammar.cpp"
>>>>>>> Added support for type-alias metadata.
=======
#line 2272 "src/Slice/Grammar.cpp"
>>>>>>> Added better error handling logic to the parser.
=======
#line 2258 "src/Slice/Grammar.cpp"
>>>>>>> More cosmetic changes.
    break;

  case 55: /* exception_decl: exception_id  */
#line 518 "src/Slice/Grammar.y"
>>>>>>> Regenerated compilers, and fixed build errors.
{
    unit->error("exceptions cannot be forward declared");
    yyval = 0;
}
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
#line 2249 "src/Slice/Grammar.cpp"
    break;

  case 53: /* @16: %empty  */
#line 523 "src/Slice/Grammar.y"
=======
#line 2271 "src/Slice/Grammar.cpp"
=======
#line 2275 "src/Slice/Grammar.cpp"
>>>>>>> Added support for type-alias metadata.
=======
#line 2281 "src/Slice/Grammar.cpp"
>>>>>>> Added better error handling logic to the parser.
=======
#line 2267 "src/Slice/Grammar.cpp"
>>>>>>> More cosmetic changes.
    break;

  case 56: /* @17: %empty  */
#line 528 "src/Slice/Grammar.y"
>>>>>>> Regenerated compilers, and fixed build errors.
{
    StringTokPtr ident = StringTokPtr::dynamicCast(yyvsp[-1]);
    ExceptionPtr base = ExceptionPtr::dynamicCast(yyvsp[0]);
    ModulePtr cont = unit->currentModule();
    ExceptionPtr ex = cont->createException(ident->v, base);
    if(ex)
    {
        cont->checkIntroduced(ident->v, ex);
        unit->pushContainer(ex);
    }
    yyval = ex;
}
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
#line 2266 "src/Slice/Grammar.cpp"
    break;

  case 54: /* exception_def: exception_id exception_extends @16 '{' data_members '}'  */
#line 536 "src/Slice/Grammar.y"
=======
#line 2288 "src/Slice/Grammar.cpp"
=======
#line 2292 "src/Slice/Grammar.cpp"
>>>>>>> Added support for type-alias metadata.
=======
#line 2298 "src/Slice/Grammar.cpp"
>>>>>>> Added better error handling logic to the parser.
=======
#line 2284 "src/Slice/Grammar.cpp"
>>>>>>> More cosmetic changes.
    break;

  case 57: /* exception_def: exception_id exception_extends @17 '{' data_members '}'  */
#line 541 "src/Slice/Grammar.y"
>>>>>>> Regenerated compilers, and fixed build errors.
{
    if(yyvsp[-3])
    {
        unit->popContainer();
    }
    yyval = yyvsp[-3];
}
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
#line 2278 "src/Slice/Grammar.cpp"
    break;

  case 55: /* exception_extends: extends scoped_name  */
#line 549 "src/Slice/Grammar.y"
=======
#line 2300 "src/Slice/Grammar.cpp"
=======
#line 2304 "src/Slice/Grammar.cpp"
>>>>>>> Added support for type-alias metadata.
=======
#line 2310 "src/Slice/Grammar.cpp"
>>>>>>> Added better error handling logic to the parser.
=======
#line 2296 "src/Slice/Grammar.cpp"
>>>>>>> More cosmetic changes.
    break;

  case 58: /* exception_extends: extends scoped_name  */
#line 554 "src/Slice/Grammar.y"
>>>>>>> Regenerated compilers, and fixed build errors.
{
    StringTokPtr scoped = StringTokPtr::dynamicCast(yyvsp[0]);
    ContainerPtr cont = unit->currentContainer();
    ContainedPtr contained = cont->lookupException(scoped->v);
    cont->checkIntroduced(scoped->v);
    yyval = contained;
}
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
#line 2290 "src/Slice/Grammar.cpp"
    break;

  case 56: /* exception_extends: %empty  */
#line 557 "src/Slice/Grammar.y"
{
    yyval = 0;
}
#line 2298 "src/Slice/Grammar.cpp"
    break;

  case 57: /* tag: ICE_TAG '(' ICE_INTEGER_LITERAL ')'  */
#line 566 "src/Slice/Grammar.y"
=======
#line 2312 "src/Slice/Grammar.cpp"
=======
#line 2316 "src/Slice/Grammar.cpp"
>>>>>>> Added support for type-alias metadata.
=======
#line 2322 "src/Slice/Grammar.cpp"
>>>>>>> Added better error handling logic to the parser.
=======
#line 2308 "src/Slice/Grammar.cpp"
>>>>>>> More cosmetic changes.
    break;

  case 59: /* exception_extends: %empty  */
#line 562 "src/Slice/Grammar.y"
{
    yyval = 0;
}
#line 2316 "src/Slice/Grammar.cpp"
    break;

  case 60: /* tag: ICE_TAG '(' ICE_INTEGER_LITERAL ')'  */
#line 571 "src/Slice/Grammar.y"
>>>>>>> Regenerated compilers, and fixed build errors.
{
    IntegerTokPtr i = IntegerTokPtr::dynamicCast(yyvsp[-1]);

    int tag;
    if(i->v < 0 || i->v > INT32_MAX)
    {
        unit->error("tag is out of range");
        tag = -1;
    }
    else
    {
        tag = static_cast<int>(i->v);
    }

    TaggedDefTokPtr m = new TaggedDefTok(tag);
    yyval = m;
}
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
#line 2320 "src/Slice/Grammar.cpp"
    break;

  case 58: /* tag: ICE_TAG '(' scoped_name ')'  */
#line 584 "src/Slice/Grammar.y"
=======
#line 2342 "src/Slice/Grammar.cpp"
=======
#line 2346 "src/Slice/Grammar.cpp"
>>>>>>> Added support for type-alias metadata.
=======
#line 2352 "src/Slice/Grammar.cpp"
>>>>>>> Added better error handling logic to the parser.
=======
#line 2338 "src/Slice/Grammar.cpp"
>>>>>>> More cosmetic changes.
    break;

  case 61: /* tag: ICE_TAG '(' scoped_name ')'  */
#line 589 "src/Slice/Grammar.y"
>>>>>>> Regenerated compilers, and fixed build errors.
{
    StringTokPtr scoped = StringTokPtr::dynamicCast(yyvsp[-1]);

    ContainerPtr cont = unit->currentContainer();
    assert(cont);
    ContainedList cl = cont->lookupContained(scoped->v, false);
    if(cl.empty())
    {
        EnumeratorList enumerators = cont->enumerators(scoped->v);
        if(enumerators.size() == 1)
        {
            // Found
            cl.push_back(enumerators.front());
            scoped->v = enumerators.front()->scoped();
            unit->warning(Deprecated, string("referencing enumerator `") + scoped->v
                          + "' without its enumeration's scope is deprecated");
        }
        else if(enumerators.size() > 1)
        {
            ostringstream os;
            os << "enumerator `" << scoped->v << "' could designate";
            bool first = true;
            for(const auto& p : enumerators)
            {
                if(first)
                {
                    first = false;
                }
                else
                {
                    os << " or";
                }

                os << " `" << p->scoped() << "'";
            }
            unit->error(os.str());
        }
        else
        {
            unit->error(string("`") + scoped->v + "' is not defined");
        }
    }

    if(cl.empty())
    {
        YYERROR; // Can't continue, jump to next yyerrok
    }
    cont->checkIntroduced(scoped->v);

    std::int64_t tag = -1;
    EnumeratorPtr enumerator = EnumeratorPtr::dynamicCast(cl.front());
    ConstPtr constant = ConstPtr::dynamicCast(cl.front());
    if (constant)
    {
        BuiltinPtr b = BuiltinPtr::dynamicCast(constant->type());
        if (b && b->isIntegralType())
        {
            tag = IceUtilInternal::strToInt64(constant->value().c_str(), 0, 0);
        }
    }
    else if(enumerator)
    {
        tag = enumerator->value();
    }

    if (tag < 0 || tag > INT32_MAX)
    {
        unit->error("cannot use value of `" + scoped->v + "' as a tag");
    }

    TaggedDefTokPtr m = new TaggedDefTok(static_cast<int>(tag));
    yyval = m;
}
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
#line 2398 "src/Slice/Grammar.cpp"
    break;

  case 59: /* tag: ICE_TAG '(' ')'  */
#line 658 "src/Slice/Grammar.y"
=======
#line 2420 "src/Slice/Grammar.cpp"
=======
#line 2424 "src/Slice/Grammar.cpp"
>>>>>>> Added support for type-alias metadata.
=======
#line 2430 "src/Slice/Grammar.cpp"
>>>>>>> Added better error handling logic to the parser.
=======
#line 2416 "src/Slice/Grammar.cpp"
>>>>>>> More cosmetic changes.
    break;

  case 62: /* tag: ICE_TAG '(' ')'  */
#line 663 "src/Slice/Grammar.y"
>>>>>>> Regenerated compilers, and fixed build errors.
{
    unit->error("missing tag");
    TaggedDefTokPtr m = new TaggedDefTok; // Dummy
    yyval = m;
}
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
#line 2408 "src/Slice/Grammar.cpp"
    break;

  case 60: /* tag: ICE_TAG  */
#line 664 "src/Slice/Grammar.y"
=======
#line 2430 "src/Slice/Grammar.cpp"
=======
#line 2434 "src/Slice/Grammar.cpp"
>>>>>>> Added support for type-alias metadata.
=======
#line 2440 "src/Slice/Grammar.cpp"
>>>>>>> Added better error handling logic to the parser.
=======
#line 2426 "src/Slice/Grammar.cpp"
>>>>>>> More cosmetic changes.
    break;

  case 63: /* tag: ICE_TAG  */
#line 669 "src/Slice/Grammar.y"
>>>>>>> Regenerated compilers, and fixed build errors.
{
    unit->error("missing tag");
    TaggedDefTokPtr m = new TaggedDefTok; // Dummy
    yyval = m;
}
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
#line 2418 "src/Slice/Grammar.cpp"
    break;

  case 61: /* optional: ICE_OPTIONAL '(' ICE_INTEGER_LITERAL ')'  */
#line 675 "src/Slice/Grammar.y"
=======
#line 2440 "src/Slice/Grammar.cpp"
=======
#line 2444 "src/Slice/Grammar.cpp"
>>>>>>> Added support for type-alias metadata.
=======
#line 2450 "src/Slice/Grammar.cpp"
>>>>>>> Added better error handling logic to the parser.
=======
#line 2436 "src/Slice/Grammar.cpp"
>>>>>>> More cosmetic changes.
    break;

  case 64: /* optional: ICE_OPTIONAL '(' ICE_INTEGER_LITERAL ')'  */
#line 680 "src/Slice/Grammar.y"
>>>>>>> Regenerated compilers, and fixed build errors.
{
    IntegerTokPtr i = IntegerTokPtr::dynamicCast(yyvsp[-1]);
    if (!unit->compatMode())
    {
        unit->warning(Deprecated, string("The `optional' keyword is deprecated, use `tag' instead"));
    }

    int tag;
    if(i->v < 0 || i->v > INT32_MAX)
    {
        unit->error("tag is out of range");
        tag = -1;
    }
    else
    {
        tag = static_cast<int>(i->v);
    }

    TaggedDefTokPtr m = new TaggedDefTok(tag);
    yyval = m;
}
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
#line 2444 "src/Slice/Grammar.cpp"
    break;

  case 62: /* optional: ICE_OPTIONAL '(' scoped_name ')'  */
#line 697 "src/Slice/Grammar.y"
=======
#line 2466 "src/Slice/Grammar.cpp"
=======
#line 2470 "src/Slice/Grammar.cpp"
>>>>>>> Added support for type-alias metadata.
=======
#line 2476 "src/Slice/Grammar.cpp"
>>>>>>> Added better error handling logic to the parser.
=======
#line 2462 "src/Slice/Grammar.cpp"
>>>>>>> More cosmetic changes.
    break;

  case 65: /* optional: ICE_OPTIONAL '(' scoped_name ')'  */
#line 702 "src/Slice/Grammar.y"
>>>>>>> Regenerated compilers, and fixed build errors.
{
    StringTokPtr scoped = StringTokPtr::dynamicCast(yyvsp[-1]);
    if (!unit->compatMode())
    {
        unit->warning(Deprecated, string("The `optional' keyword is deprecated, use `tag' instead"));
    }

    ContainerPtr cont = unit->currentContainer();
    assert(cont);
    ContainedList cl = cont->lookupContained(scoped->v, false);
    if(cl.empty())
    {
        EnumeratorList enumerators = cont->enumerators(scoped->v);
        if(enumerators.size() == 1)
        {
            // Found
            cl.push_back(enumerators.front());
            scoped->v = enumerators.front()->scoped();
            unit->warning(Deprecated, string("referencing enumerator `") + scoped->v
                          + "' without its enumeration's scope is deprecated");
        }
        else if(enumerators.size() > 1)
        {
            ostringstream os;
            os << "enumerator `" << scoped->v << "' could designate";
            bool first = true;
            for(const auto& p : enumerators)
            {
                if(first)
                {
                    first = false;
                }
                else
                {
                    os << " or";
                }

                os << " `" << p->scoped() << "'";
            }
            unit->error(os.str());
        }
        else
        {
            unit->error(string("`") + scoped->v + "' is not defined");
        }
    }

    if(cl.empty())
    {
        YYERROR; // Can't continue, jump to next yyerrok
    }
    cont->checkIntroduced(scoped->v);

    std::int64_t tag = -1;
    EnumeratorPtr enumerator = EnumeratorPtr::dynamicCast(cl.front());
    ConstPtr constant = ConstPtr::dynamicCast(cl.front());
    if (constant)
    {
        BuiltinPtr b = BuiltinPtr::dynamicCast(constant->type());
        if(b && b->isIntegralType())
        {
            tag = IceUtilInternal::strToInt64(constant->value().c_str(), 0, 0);
        }
    }
    else if(enumerator)
    {
        tag = enumerator->value();
    }

    if (tag < 0 || tag > INT32_MAX)
    {
        unit->error("cannot use value of `" + scoped->v + "' as a tag");
    }

    TaggedDefTokPtr m = new TaggedDefTok(static_cast<int>(tag));
    yyval = m;
}
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
#line 2526 "src/Slice/Grammar.cpp"
    break;

  case 63: /* optional: ICE_OPTIONAL '(' ')'  */
#line 775 "src/Slice/Grammar.y"
=======
#line 2548 "src/Slice/Grammar.cpp"
=======
#line 2552 "src/Slice/Grammar.cpp"
>>>>>>> Added support for type-alias metadata.
=======
#line 2558 "src/Slice/Grammar.cpp"
>>>>>>> Added better error handling logic to the parser.
=======
#line 2544 "src/Slice/Grammar.cpp"
>>>>>>> More cosmetic changes.
    break;

  case 66: /* optional: ICE_OPTIONAL '(' ')'  */
#line 780 "src/Slice/Grammar.y"
>>>>>>> Regenerated compilers, and fixed build errors.
{
    if (!unit->compatMode())
    {
        unit->warning(Deprecated, string("The `optional' keyword is deprecated, use `tag' instead"));
    }
    unit->error("missing tag");
    TaggedDefTokPtr m = new TaggedDefTok; // Dummy
    yyval = m;
}
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
#line 2540 "src/Slice/Grammar.cpp"
    break;

  case 64: /* optional: ICE_OPTIONAL  */
#line 785 "src/Slice/Grammar.y"
=======
#line 2562 "src/Slice/Grammar.cpp"
=======
#line 2566 "src/Slice/Grammar.cpp"
>>>>>>> Added support for type-alias metadata.
=======
#line 2572 "src/Slice/Grammar.cpp"
>>>>>>> Added better error handling logic to the parser.
=======
#line 2558 "src/Slice/Grammar.cpp"
>>>>>>> More cosmetic changes.
    break;

  case 67: /* optional: ICE_OPTIONAL  */
#line 790 "src/Slice/Grammar.y"
>>>>>>> Regenerated compilers, and fixed build errors.
{
    if (!unit->compatMode())
    {
        unit->warning(Deprecated, string("The `optional' keyword is deprecated, use `tag' instead"));
    }
    unit->error("missing tag");
    TaggedDefTokPtr m = new TaggedDefTok; // Dummy
    yyval = m;
}
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
#line 2554 "src/Slice/Grammar.cpp"
=======
#line 2586 "src/Slice/Grammar.cpp"
>>>>>>> Added better error handling logic to the parser.
    break;

  case 65: /* struct_id: ICE_STRUCT ICE_IDENTIFIER  */
#line 800 "src/Slice/Grammar.y"
{
    yyval = yyvsp[0];
}
#line 2562 "src/Slice/Grammar.cpp"
    break;

  case 66: /* struct_id: ICE_STRUCT keyword  */
#line 804 "src/Slice/Grammar.y"
=======
#line 2576 "src/Slice/Grammar.cpp"
=======
#line 2580 "src/Slice/Grammar.cpp"
>>>>>>> Added support for type-alias metadata.
=======
#line 2572 "src/Slice/Grammar.cpp"
>>>>>>> More cosmetic changes.
    break;

  case 68: /* struct_id: ICE_STRUCT ICE_IDENTIFIER  */
#line 805 "src/Slice/Grammar.y"
{
    yyval = yyvsp[0];
}
#line 2580 "src/Slice/Grammar.cpp"
    break;

  case 69: /* struct_id: ICE_STRUCT keyword  */
#line 809 "src/Slice/Grammar.y"
>>>>>>> Regenerated compilers, and fixed build errors.
{
    StringTokPtr ident = StringTokPtr::dynamicCast(yyvsp[0]);
    unit->error("keyword `" + ident->v + "' cannot be used as struct name");
    yyval = yyvsp[0]; // Dummy
}
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
#line 2572 "src/Slice/Grammar.cpp"
    break;

  case 67: /* struct_decl: struct_id  */
#line 815 "src/Slice/Grammar.y"
=======
#line 2594 "src/Slice/Grammar.cpp"
=======
#line 2598 "src/Slice/Grammar.cpp"
>>>>>>> Added support for type-alias metadata.
=======
#line 2604 "src/Slice/Grammar.cpp"
>>>>>>> Added better error handling logic to the parser.
=======
#line 2590 "src/Slice/Grammar.cpp"
>>>>>>> More cosmetic changes.
    break;

  case 70: /* struct_decl: struct_id  */
#line 820 "src/Slice/Grammar.y"
>>>>>>> Regenerated compilers, and fixed build errors.
{
    unit->error("structs cannot be forward declared");
    yyval = 0; // Dummy
}
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
#line 2581 "src/Slice/Grammar.cpp"
    break;

  case 68: /* @17: %empty  */
#line 825 "src/Slice/Grammar.y"
=======
#line 2603 "src/Slice/Grammar.cpp"
=======
#line 2607 "src/Slice/Grammar.cpp"
>>>>>>> Added support for type-alias metadata.
=======
#line 2613 "src/Slice/Grammar.cpp"
>>>>>>> Added better error handling logic to the parser.
=======
#line 2599 "src/Slice/Grammar.cpp"
>>>>>>> More cosmetic changes.
    break;

  case 71: /* @18: %empty  */
#line 830 "src/Slice/Grammar.y"
>>>>>>> Regenerated compilers, and fixed build errors.
{
    StringTokPtr ident = StringTokPtr::dynamicCast(yyvsp[0]);
    ModulePtr cont = unit->currentModule();
    StructPtr st = cont->createStruct(ident->v);
    if(st)
    {
        cont->checkIntroduced(ident->v, st);
        unit->pushContainer(st);
    }
    else
    {
        st = cont->createStruct(IceUtil::generateUUID(), Dummy);
        assert(st);
        unit->pushContainer(st);
    }
    yyval = st;
}
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
#line 2603 "src/Slice/Grammar.cpp"
    break;

  case 69: /* struct_def: struct_id @17 '{' data_members '}'  */
#line 843 "src/Slice/Grammar.y"
=======
#line 2625 "src/Slice/Grammar.cpp"
=======
#line 2629 "src/Slice/Grammar.cpp"
>>>>>>> Added support for type-alias metadata.
=======
#line 2635 "src/Slice/Grammar.cpp"
>>>>>>> Added better error handling logic to the parser.
=======
#line 2621 "src/Slice/Grammar.cpp"
>>>>>>> More cosmetic changes.
    break;

  case 72: /* struct_def: struct_id @18 '{' data_members '}'  */
#line 848 "src/Slice/Grammar.y"
>>>>>>> Regenerated compilers, and fixed build errors.
{
    if(yyvsp[-3])
    {
        unit->popContainer();
    }
    yyval = yyvsp[-3];

    //
    // Empty structures are not allowed
    //
    StructPtr st = StructPtr::dynamicCast(yyval);
    assert(st);
    if (!st->hasDataMembers())
    {
        unit->error("struct `" + st->name() + "' must have at least one member"); // $$ is a dummy
    }
}
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
#line 2625 "src/Slice/Grammar.cpp"
    break;

  case 70: /* class_name: ICE_CLASS ICE_IDENTIFIER  */
#line 866 "src/Slice/Grammar.y"
{
    yyval = yyvsp[0];
}
#line 2633 "src/Slice/Grammar.cpp"
    break;

  case 71: /* class_name: ICE_CLASS keyword  */
#line 870 "src/Slice/Grammar.y"
=======
#line 2647 "src/Slice/Grammar.cpp"
=======
#line 2651 "src/Slice/Grammar.cpp"
>>>>>>> Added support for type-alias metadata.
=======
#line 2657 "src/Slice/Grammar.cpp"
>>>>>>> Added better error handling logic to the parser.
=======
#line 2643 "src/Slice/Grammar.cpp"
>>>>>>> More cosmetic changes.
    break;

  case 73: /* class_name: ICE_CLASS ICE_IDENTIFIER  */
#line 871 "src/Slice/Grammar.y"
{
    yyval = yyvsp[0];
}
#line 2651 "src/Slice/Grammar.cpp"
    break;

  case 74: /* class_name: ICE_CLASS keyword  */
#line 875 "src/Slice/Grammar.y"
>>>>>>> Regenerated compilers, and fixed build errors.
{
    StringTokPtr ident = StringTokPtr::dynamicCast(yyvsp[0]);
    unit->error("keyword `" + ident->v + "' cannot be used as class name");
    yyval = yyvsp[0]; // Dummy
}
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
#line 2643 "src/Slice/Grammar.cpp"
    break;

  case 72: /* class_id: ICE_CLASS unscoped_name '(' ICE_INTEGER_LITERAL ')'  */
#line 881 "src/Slice/Grammar.y"
=======
#line 2665 "src/Slice/Grammar.cpp"
=======
#line 2669 "src/Slice/Grammar.cpp"
>>>>>>> Added support for type-alias metadata.
=======
#line 2675 "src/Slice/Grammar.cpp"
>>>>>>> Added better error handling logic to the parser.
=======
#line 2661 "src/Slice/Grammar.cpp"
>>>>>>> More cosmetic changes.
    break;

  case 75: /* class_id: ICE_CLASS unscoped_name '(' ICE_INTEGER_LITERAL ')'  */
#line 886 "src/Slice/Grammar.y"
>>>>>>> Regenerated compilers, and fixed build errors.
{
    IceUtil::Int64 id = IntegerTokPtr::dynamicCast(yyvsp[-1])->v;
    if(id < 0)
    {
        unit->error("invalid compact id for class: id must be a positive integer");
    }
    else if(id > INT32_MAX)
    {
        unit->error("invalid compact id for class: value is out of range");
    }
    else
    {
        string typeId = unit->getTypeId(static_cast<int>(id));
        if(!typeId.empty())
        {
            unit->error("invalid compact id for class: already assigned to class `" + typeId + "'");
        }
    }

    ClassIdTokPtr classId = new ClassIdTok();
    classId->v = StringTokPtr::dynamicCast(yyvsp[-3])->v;
    classId->t = static_cast<int>(id);
    yyval = classId;
}
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
#line 2672 "src/Slice/Grammar.cpp"
    break;

  case 73: /* class_id: ICE_CLASS unscoped_name '(' scoped_name ')'  */
#line 906 "src/Slice/Grammar.y"
=======
#line 2694 "src/Slice/Grammar.cpp"
=======
#line 2698 "src/Slice/Grammar.cpp"
>>>>>>> Added support for type-alias metadata.
=======
#line 2704 "src/Slice/Grammar.cpp"
>>>>>>> Added better error handling logic to the parser.
=======
#line 2690 "src/Slice/Grammar.cpp"
>>>>>>> More cosmetic changes.
    break;

  case 76: /* class_id: ICE_CLASS unscoped_name '(' scoped_name ')'  */
#line 911 "src/Slice/Grammar.y"
>>>>>>> Regenerated compilers, and fixed build errors.
{
    StringTokPtr scoped = StringTokPtr::dynamicCast(yyvsp[-1]);

    ContainerPtr cont = unit->currentContainer();
    assert(cont);
    ContainedList cl = cont->lookupContained(scoped->v, false);
    if(cl.empty())
    {
        EnumeratorList enumerators = cont->enumerators(scoped->v);
        if(enumerators.size() == 1)
        {
            // Found
            cl.push_back(enumerators.front());
            scoped->v = enumerators.front()->scoped();
            unit->warning(Deprecated, string("referencing enumerator `") + scoped->v
                          + "' without its enumeration's scope is deprecated");
        }
        else if(enumerators.size() > 1)
        {
            ostringstream os;
            os << "enumerator `" << scoped->v << "' could designate";
            bool first = true;
            for(EnumeratorList::iterator p = enumerators.begin(); p != enumerators.end(); ++p)
            {
                if(first)
                {
                    first = false;
                }
                else
                {
                    os << " or";
                }

                os << " `" << (*p)->scoped() << "'";
            }
            unit->error(os.str());
        }
        else
        {
            unit->error(string("`") + scoped->v + "' is not defined");
        }
    }

    if(cl.empty())
    {
        YYERROR; // Can't continue, jump to next yyerrok
    }
    cont->checkIntroduced(scoped->v);

    int id = -1;
    EnumeratorPtr enumerator = EnumeratorPtr::dynamicCast(cl.front());
    ConstPtr constant = ConstPtr::dynamicCast(cl.front());
    if(constant)
    {
        BuiltinPtr b = BuiltinPtr::dynamicCast(constant->type());
        if(b && b->isIntegralType())
        {
            IceUtil::Int64 l = IceUtilInternal::strToInt64(constant->value().c_str(), 0, 0);
            if(l < 0 || l > INT32_MAX)
            {
                unit->error("compact id for class is out of range");
            }
            id = static_cast<int>(l);
        }
    }
    else if(enumerator)
    {
        id = enumerator->value();
    }

    if(id < 0)
    {
        unit->error("invalid compact id for class: id must be a positive integer");
    }
    else
    {
        string typeId = unit->getTypeId(id);
        if(!typeId.empty())
        {
            unit->error("invalid compact id for class: already assigned to class `" + typeId + "'");
        }
    }

    ClassIdTokPtr classId = new ClassIdTok();
    classId->v = StringTokPtr::dynamicCast(yyvsp[-3])->v;
    classId->t = id;
    yyval = classId;

}
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
#line 2766 "src/Slice/Grammar.cpp"
    break;

  case 74: /* class_id: class_name  */
#line 996 "src/Slice/Grammar.y"
=======
#line 2788 "src/Slice/Grammar.cpp"
=======
#line 2792 "src/Slice/Grammar.cpp"
>>>>>>> Added support for type-alias metadata.
=======
#line 2798 "src/Slice/Grammar.cpp"
>>>>>>> Added better error handling logic to the parser.
=======
#line 2784 "src/Slice/Grammar.cpp"
>>>>>>> More cosmetic changes.
    break;

  case 77: /* class_id: class_name  */
#line 1001 "src/Slice/Grammar.y"
>>>>>>> Regenerated compilers, and fixed build errors.
{
    ClassIdTokPtr classId = new ClassIdTok();
    classId->v = StringTokPtr::dynamicCast(yyvsp[0])->v;
    classId->t = -1;
    yyval = classId;
}
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
#line 2777 "src/Slice/Grammar.cpp"
    break;

  case 75: /* class_decl: class_name  */
#line 1008 "src/Slice/Grammar.y"
=======
#line 2799 "src/Slice/Grammar.cpp"
=======
#line 2803 "src/Slice/Grammar.cpp"
>>>>>>> Added support for type-alias metadata.
=======
#line 2809 "src/Slice/Grammar.cpp"
>>>>>>> Added better error handling logic to the parser.
=======
#line 2795 "src/Slice/Grammar.cpp"
>>>>>>> More cosmetic changes.
    break;

  case 78: /* class_decl: class_name  */
#line 1013 "src/Slice/Grammar.y"
>>>>>>> Regenerated compilers, and fixed build errors.
{
    StringTokPtr ident = StringTokPtr::dynamicCast(yyvsp[0]);
    ModulePtr cont = unit->currentModule();
    ClassDeclPtr cl = cont->createClassDecl(ident->v);
    yyval = cl;
}
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
#line 2788 "src/Slice/Grammar.cpp"
    break;

  case 76: /* @18: %empty  */
#line 1020 "src/Slice/Grammar.y"
=======
#line 2810 "src/Slice/Grammar.cpp"
=======
#line 2814 "src/Slice/Grammar.cpp"
>>>>>>> Added support for type-alias metadata.
=======
#line 2820 "src/Slice/Grammar.cpp"
>>>>>>> Added better error handling logic to the parser.
=======
#line 2806 "src/Slice/Grammar.cpp"
>>>>>>> More cosmetic changes.
    break;

  case 79: /* @19: %empty  */
#line 1025 "src/Slice/Grammar.y"
>>>>>>> Regenerated compilers, and fixed build errors.
{
    ClassIdTokPtr ident = ClassIdTokPtr::dynamicCast(yyvsp[-1]);
    ModulePtr cont = unit->currentModule();
    ClassDefPtr base = ClassDefPtr::dynamicCast(yyvsp[0]);
    ClassDefPtr cl = cont->createClassDef(ident->v, ident->t, base);
    if(cl)
    {
        cont->checkIntroduced(ident->v, cl);
        unit->pushContainer(cl);
        yyval = cl;
    }
    else
    {
        yyval = 0;
    }
}
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
#line 2809 "src/Slice/Grammar.cpp"
    break;

  case 77: /* class_def: class_id class_extends @18 '{' data_members '}'  */
#line 1037 "src/Slice/Grammar.y"
=======
#line 2831 "src/Slice/Grammar.cpp"
=======
#line 2835 "src/Slice/Grammar.cpp"
>>>>>>> Added support for type-alias metadata.
=======
#line 2841 "src/Slice/Grammar.cpp"
>>>>>>> Added better error handling logic to the parser.
=======
#line 2827 "src/Slice/Grammar.cpp"
>>>>>>> More cosmetic changes.
    break;

  case 80: /* class_def: class_id class_extends @19 '{' data_members '}'  */
#line 1042 "src/Slice/Grammar.y"
>>>>>>> Regenerated compilers, and fixed build errors.
{
    if(yyvsp[-3])
    {
        unit->popContainer();
        yyval = yyvsp[-3];
    }
    else
    {
        yyval = 0;
    }
}
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
#line 2825 "src/Slice/Grammar.cpp"
    break;

  case 78: /* class_extends: extends scoped_name  */
#line 1054 "src/Slice/Grammar.y"
=======
#line 2847 "src/Slice/Grammar.cpp"
=======
#line 2851 "src/Slice/Grammar.cpp"
>>>>>>> Added support for type-alias metadata.
=======
#line 2857 "src/Slice/Grammar.cpp"
>>>>>>> Added better error handling logic to the parser.
=======
#line 2843 "src/Slice/Grammar.cpp"
>>>>>>> More cosmetic changes.
    break;

  case 81: /* class_extends: extends scoped_name  */
#line 1059 "src/Slice/Grammar.y"
>>>>>>> Regenerated compilers, and fixed build errors.
{
    StringTokPtr scoped = StringTokPtr::dynamicCast(yyvsp[0]);
    ContainerPtr cont = unit->currentContainer();
    TypeList types = cont->lookupType(scoped->v);
    yyval = 0;
    if (!types.empty())
    {
        ClassDeclPtr cl = ClassDeclPtr::dynamicCast(types.front());
        if (!cl)
        {
            if (auto alias = TypeAliasPtr::dynamicCast(types.front()))
            {
                cl = ClassDeclPtr::dynamicCast(alias->underlying());
            }
        }

        if (cl)
        {
            ClassDefPtr def = cl->definition();
            if (!def)
            {
                unit->error("`" + scoped->v + "' has been declared but not defined");
            }
            else
            {
                cont->checkIntroduced(scoped->v);
                yyval = def;
            }
        }
        else
        {
            unit->error("`" + scoped->v + "' is not a class");
        }
    }
}
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
#line 2863 "src/Slice/Grammar.cpp"
    break;

  case 79: /* class_extends: %empty  */
#line 1088 "src/Slice/Grammar.y"
{
    yyval = 0;
}
#line 2871 "src/Slice/Grammar.cpp"
    break;

  case 82: /* data_member: member  */
#line 1104 "src/Slice/Grammar.y"
=======
#line 2885 "src/Slice/Grammar.cpp"
=======
#line 2889 "src/Slice/Grammar.cpp"
>>>>>>> Added support for type-alias metadata.
=======
#line 2896 "src/Slice/Grammar.cpp"
>>>>>>> Added aliasing support into the parser.
=======
#line 2902 "src/Slice/Grammar.cpp"
>>>>>>> Added better error handling logic to the parser.
=======
#line 2888 "src/Slice/Grammar.cpp"
>>>>>>> More cosmetic changes.
=======
#line 2883 "src/Slice/Grammar.cpp"
>>>>>>> Fixed review comments.
    break;

  case 82: /* class_extends: %empty  */
#line 1095 "src/Slice/Grammar.y"
{
    yyval = 0;
}
#line 2891 "src/Slice/Grammar.cpp"
    break;

  case 85: /* data_member: member  */
<<<<<<< HEAD
<<<<<<< HEAD
#line 1109 "src/Slice/Grammar.y"
>>>>>>> Regenerated compilers, and fixed build errors.
=======
#line 1116 "src/Slice/Grammar.y"
>>>>>>> Added aliasing support into the parser.
=======
#line 1111 "src/Slice/Grammar.y"
>>>>>>> Fixed review comments.
{
    TaggedDefTokPtr def = TaggedDefTokPtr::dynamicCast(yyvsp[0]);

    // Check if the container was created successfully. If it wasn't skip creating the data member and continue parsing.
    if (DataMemberContainerPtr cont = DataMemberContainerPtr::dynamicCast(unit->currentContainer()))
    {
        MemberPtr dm = cont->createDataMember(def->name, def->type, def->isTagged, def->tag);
        unit->currentContainer()->checkIntroduced(def->name, dm);
        if (dm && !def->metadata.empty())
        {
            dm->setMetadata(def->metadata);
        }
    }
}
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
#line 2890 "src/Slice/Grammar.cpp"
    break;

  case 83: /* data_member: member '=' const_initializer  */
#line 1119 "src/Slice/Grammar.y"
=======
#line 2912 "src/Slice/Grammar.cpp"
=======
#line 2916 "src/Slice/Grammar.cpp"
>>>>>>> Added support for type-alias metadata.
    break;

  case 86: /* data_member: member '=' const_initializer  */
#line 1124 "src/Slice/Grammar.y"
>>>>>>> Regenerated compilers, and fixed build errors.
=======
#line 2923 "src/Slice/Grammar.cpp"
=======
#line 2929 "src/Slice/Grammar.cpp"
>>>>>>> Added better error handling logic to the parser.
=======
#line 2915 "src/Slice/Grammar.cpp"
>>>>>>> More cosmetic changes.
    break;

  case 86: /* data_member: member '=' const_initializer  */
#line 1131 "src/Slice/Grammar.y"
>>>>>>> Added aliasing support into the parser.
=======
#line 2910 "src/Slice/Grammar.cpp"
    break;

  case 86: /* data_member: member '=' const_initializer  */
#line 1126 "src/Slice/Grammar.y"
>>>>>>> Fixed review comments.
{
    TaggedDefTokPtr def = TaggedDefTokPtr::dynamicCast(yyvsp[-2]);
    ConstDefTokPtr value = ConstDefTokPtr::dynamicCast(yyvsp[0]);

    // Check if the container was created successfully. If it wasn't skip creating the data member and continue parsing.
    if (DataMemberContainerPtr cont = DataMemberContainerPtr::dynamicCast(unit->currentContainer()))
    {
        MemberPtr dm = cont->createDataMember(def->name, def->type, def->isTagged, def->tag, value->v,
                                              value->valueAsString, value->valueAsLiteral);
        unit->currentContainer()->checkIntroduced(def->name, dm);
        if (dm && !def->metadata.empty())
        {
            dm->setMetadata(def->metadata);
        }
    }
}
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
#line 2911 "src/Slice/Grammar.cpp"
    break;

  case 86: /* data_member_list: data_member  */
#line 1143 "src/Slice/Grammar.y"
{
    unit->error("`;' missing after definition");
}
#line 2919 "src/Slice/Grammar.cpp"
    break;

  case 90: /* return_tuple: qualifier member  */
#line 1160 "src/Slice/Grammar.y"
=======
#line 2933 "src/Slice/Grammar.cpp"
=======
#line 2937 "src/Slice/Grammar.cpp"
>>>>>>> Added support for type-alias metadata.
=======
#line 2944 "src/Slice/Grammar.cpp"
>>>>>>> Added aliasing support into the parser.
=======
#line 2950 "src/Slice/Grammar.cpp"
>>>>>>> Added better error handling logic to the parser.
=======
#line 2936 "src/Slice/Grammar.cpp"
>>>>>>> More cosmetic changes.
=======
#line 2931 "src/Slice/Grammar.cpp"
>>>>>>> Fixed review comments.
    break;

  case 89: /* data_member_list: data_member  */
#line 1150 "src/Slice/Grammar.y"
{
    unit->error("`;' missing after definition");
}
#line 2939 "src/Slice/Grammar.cpp"
    break;

  case 93: /* return_tuple: out_qualifier member  */
<<<<<<< HEAD
<<<<<<< HEAD
#line 1165 "src/Slice/Grammar.y"
>>>>>>> Regenerated compilers, and fixed build errors.
=======
#line 1172 "src/Slice/Grammar.y"
>>>>>>> Added aliasing support into the parser.
=======
#line 1167 "src/Slice/Grammar.y"
>>>>>>> Fixed review comments.
{
    IntegerTokPtr qualifier = IntegerTokPtr::dynamicCast(yyvsp[-1]);
    TaggedDefTokPtr returnMember = TaggedDefTokPtr::dynamicCast(yyvsp[0]);

    returnMember->isStream = qualifier->v & QUALIFIER_STREAM;

    bool isOutParam = qualifier->v & QUALIFIER_OUT;
    if (isOutParam)
    {
        unit->error("`" + returnMember->name + "': return members cannot be marked as out");
    }

    TaggedDefListTokPtr returnMembers = new TaggedDefListTok();
    returnMembers->v.push_back(returnMember);
    yyval = returnMembers;
}
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
#line 2940 "src/Slice/Grammar.cpp"
    break;

  case 91: /* return_tuple: return_tuple ',' qualifier member  */
=======
#line 2957 "src/Slice/Grammar.cpp"
=======
#line 2961 "src/Slice/Grammar.cpp"
>>>>>>> Added support for type-alias metadata.
    break;

  case 94: /* return_tuple: return_tuple ',' out_qualifier member  */
>>>>>>> Regenerated compilers, and fixed build errors.
#line 1177 "src/Slice/Grammar.y"
=======
#line 2968 "src/Slice/Grammar.cpp"
=======
#line 2974 "src/Slice/Grammar.cpp"
>>>>>>> Added better error handling logic to the parser.
=======
#line 2960 "src/Slice/Grammar.cpp"
>>>>>>> More cosmetic changes.
    break;

  case 94: /* return_tuple: return_tuple ',' out_qualifier member  */
#line 1184 "src/Slice/Grammar.y"
>>>>>>> Added aliasing support into the parser.
=======
#line 2955 "src/Slice/Grammar.cpp"
    break;

  case 94: /* return_tuple: return_tuple ',' out_qualifier member  */
#line 1179 "src/Slice/Grammar.y"
>>>>>>> Fixed review comments.
{
    IntegerTokPtr qualifier = IntegerTokPtr::dynamicCast(yyvsp[-1]);
    TaggedDefTokPtr returnMember = TaggedDefTokPtr::dynamicCast(yyvsp[0]);

    returnMember->isStream = qualifier->v & QUALIFIER_STREAM;

    bool isOutParam = qualifier->v & QUALIFIER_OUT;
    if (isOutParam)
    {
        unit->error("`" + returnMember->name + "': return members cannot be marked as out");
    }

    TaggedDefListTokPtr returnMembers = TaggedDefListTokPtr::dynamicCast(yyvsp[-3]);
    returnMembers->v.push_back(returnMember);
    yyval = returnMembers;
}
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
#line 2961 "src/Slice/Grammar.cpp"
    break;

  case 92: /* return_type: qualifier tagged_type  */
#line 1198 "src/Slice/Grammar.y"
=======
#line 2973 "src/Slice/Grammar.cpp"
=======
#line 2977 "src/Slice/Grammar.cpp"
>>>>>>> Added support for type-alias metadata.
    break;

  case 95: /* return_type: tagged_type  */
#line 1193 "src/Slice/Grammar.y"
>>>>>>> Regenerated compilers, and fixed build errors.
=======
#line 2984 "src/Slice/Grammar.cpp"
=======
#line 2990 "src/Slice/Grammar.cpp"
>>>>>>> Added better error handling logic to the parser.
=======
#line 2976 "src/Slice/Grammar.cpp"
>>>>>>> More cosmetic changes.
    break;

  case 95: /* return_type: tagged_type  */
#line 1200 "src/Slice/Grammar.y"
>>>>>>> Added aliasing support into the parser.
=======
#line 2971 "src/Slice/Grammar.cpp"
    break;

  case 95: /* return_type: tagged_type  */
#line 1195 "src/Slice/Grammar.y"
>>>>>>> Fixed review comments.
{
    IntegerTokPtr qualifier = IntegerTokPtr::dynamicCast(yyvsp[-1]);
    TaggedDefTokPtr returnMember = TaggedDefTokPtr::dynamicCast(yyvsp[0]);

    // For unnamed return types we infer their name to be 'returnValue'.
    returnMember->name = "returnValue";

    returnMember->isStream = qualifier->v & QUALIFIER_STREAM;

    bool isOutParam = qualifier->v & QUALIFIER_OUT;
    if (isOutParam)
    {
        unit->error("return value cannot be marked as out");
    }

    if (returnMember->isTagged)
    {
        checkForTaggableType(returnMember->type);
    }

    TaggedDefListTokPtr returnMembers = new TaggedDefListTok();
    returnMembers->v.push_back(returnMember);
    yyval = returnMembers;
}
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
#line 2990 "src/Slice/Grammar.cpp"
    break;

  case 93: /* return_type: '(' return_tuple ')'  */
#line 1223 "src/Slice/Grammar.y"
=======
#line 2992 "src/Slice/Grammar.cpp"
=======
#line 2996 "src/Slice/Grammar.cpp"
>>>>>>> Added support for type-alias metadata.
    break;

  case 96: /* return_type: '(' return_tuple ')'  */
#line 1208 "src/Slice/Grammar.y"
>>>>>>> Regenerated compilers, and fixed build errors.
=======
#line 3003 "src/Slice/Grammar.cpp"
=======
#line 3009 "src/Slice/Grammar.cpp"
>>>>>>> Added better error handling logic to the parser.
=======
#line 2995 "src/Slice/Grammar.cpp"
>>>>>>> More cosmetic changes.
    break;

  case 96: /* return_type: '(' return_tuple ')'  */
#line 1215 "src/Slice/Grammar.y"
>>>>>>> Added aliasing support into the parser.
=======
#line 2990 "src/Slice/Grammar.cpp"
    break;

  case 96: /* return_type: '(' return_tuple ')'  */
#line 1210 "src/Slice/Grammar.y"
>>>>>>> Fixed review comments.
{
    TaggedDefListTokPtr returnMembers = TaggedDefListTokPtr::dynamicCast(yyvsp[-1]);
    if (returnMembers->v.size() == 1)
    {
        unit->error("return tuples must contain at least 2 elements");
    }
    yyval = yyvsp[-1];
}
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
#line 3003 "src/Slice/Grammar.cpp"
    break;

  case 94: /* return_type: '(' ')'  */
#line 1232 "src/Slice/Grammar.y"
=======
#line 3005 "src/Slice/Grammar.cpp"
=======
#line 3009 "src/Slice/Grammar.cpp"
>>>>>>> Added support for type-alias metadata.
    break;

  case 97: /* return_type: '(' ')'  */
#line 1217 "src/Slice/Grammar.y"
>>>>>>> Regenerated compilers, and fixed build errors.
=======
#line 3016 "src/Slice/Grammar.cpp"
=======
#line 3022 "src/Slice/Grammar.cpp"
>>>>>>> Added better error handling logic to the parser.
=======
#line 3008 "src/Slice/Grammar.cpp"
>>>>>>> More cosmetic changes.
    break;

  case 97: /* return_type: '(' ')'  */
#line 1224 "src/Slice/Grammar.y"
>>>>>>> Added aliasing support into the parser.
=======
#line 3003 "src/Slice/Grammar.cpp"
    break;

  case 97: /* return_type: '(' ')'  */
#line 1219 "src/Slice/Grammar.y"
>>>>>>> Fixed review comments.
{
    unit->error("return tuples must contain at least 2 elements");
    yyval = new TaggedDefListTok();
}
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
#line 3012 "src/Slice/Grammar.cpp"
    break;

  case 95: /* return_type: ICE_VOID  */
#line 1237 "src/Slice/Grammar.y"
{
    yyval = new TaggedDefListTok();
}
#line 3020 "src/Slice/Grammar.cpp"
    break;

  case 96: /* operation_preamble: return_type unscoped_name '('  */
#line 1246 "src/Slice/Grammar.y"
=======
#line 3014 "src/Slice/Grammar.cpp"
=======
#line 3018 "src/Slice/Grammar.cpp"
>>>>>>> Added support for type-alias metadata.
=======
#line 3025 "src/Slice/Grammar.cpp"
>>>>>>> Added aliasing support into the parser.
=======
#line 3031 "src/Slice/Grammar.cpp"
>>>>>>> Added better error handling logic to the parser.
=======
#line 3017 "src/Slice/Grammar.cpp"
>>>>>>> More cosmetic changes.
=======
#line 3012 "src/Slice/Grammar.cpp"
>>>>>>> Fixed review comments.
    break;

  case 98: /* return_type: ICE_VOID  */
#line 1224 "src/Slice/Grammar.y"
{
    yyval = new TaggedDefListTok();
}
#line 3020 "src/Slice/Grammar.cpp"
    break;

  case 99: /* operation_preamble: return_type unscoped_name '('  */
<<<<<<< HEAD
<<<<<<< HEAD
#line 1231 "src/Slice/Grammar.y"
>>>>>>> Regenerated compilers, and fixed build errors.
=======
#line 1238 "src/Slice/Grammar.y"
>>>>>>> Added aliasing support into the parser.
=======
#line 1233 "src/Slice/Grammar.y"
>>>>>>> Fixed review comments.
{
    TaggedDefListTokPtr returnMembers = TaggedDefListTokPtr::dynamicCast(yyvsp[-2]);
    string name = StringTokPtr::dynamicCast(yyvsp[-1])->v;

    if (InterfaceDefPtr interface = InterfaceDefPtr::dynamicCast(unit->currentContainer()))
    {
        if (OperationPtr op = interface->createOperation(name))
        {
            interface->checkIntroduced(name, op);
            unit->pushContainer(op);

            // Set the return members for the operation.
            for (const auto& returnMember : returnMembers->v)
            {
                MemberPtr p = op->createReturnMember(returnMember->name, returnMember->type, returnMember->isTagged,
                                                     returnMember->tag, returnMember->isStream);
                if (p && !returnMember->metadata.empty())
                {
                    p->setMetadata(returnMember->metadata);
                }
            }

            yyval = op;
        }
        else
        {
            yyval = 0;
        }
    }
    else
    {
        yyval = 0;
    }
}
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
#line 3059 "src/Slice/Grammar.cpp"
    break;

  case 97: /* operation_preamble: ICE_IDEMPOTENT return_type unscoped_name '('  */
#line 1281 "src/Slice/Grammar.y"
=======
#line 3061 "src/Slice/Grammar.cpp"
=======
#line 3065 "src/Slice/Grammar.cpp"
>>>>>>> Added support for type-alias metadata.
    break;

  case 100: /* operation_preamble: ICE_IDEMPOTENT return_type unscoped_name '('  */
#line 1266 "src/Slice/Grammar.y"
>>>>>>> Regenerated compilers, and fixed build errors.
=======
#line 3072 "src/Slice/Grammar.cpp"
=======
#line 3078 "src/Slice/Grammar.cpp"
>>>>>>> Added better error handling logic to the parser.
=======
#line 3064 "src/Slice/Grammar.cpp"
>>>>>>> More cosmetic changes.
    break;

  case 100: /* operation_preamble: ICE_IDEMPOTENT return_type unscoped_name '('  */
#line 1273 "src/Slice/Grammar.y"
>>>>>>> Added aliasing support into the parser.
=======
#line 3059 "src/Slice/Grammar.cpp"
    break;

  case 100: /* operation_preamble: ICE_IDEMPOTENT return_type unscoped_name '('  */
#line 1268 "src/Slice/Grammar.y"
>>>>>>> Fixed review comments.
{
    TaggedDefListTokPtr returnMembers = TaggedDefListTokPtr::dynamicCast(yyvsp[-2]);
    string name = StringTokPtr::dynamicCast(yyvsp[-1])->v;

    if (InterfaceDefPtr interface = InterfaceDefPtr::dynamicCast(unit->currentContainer()))
    {
        if (OperationPtr op = interface->createOperation(name, Operation::Idempotent))
        {
            interface->checkIntroduced(name, op);
            unit->pushContainer(op);

            // Set the return members for the operation.
            for (const auto& returnMember : returnMembers->v)
            {
                MemberPtr p = op->createReturnMember(returnMember->name, returnMember->type, returnMember->isTagged,
                                                     returnMember->tag, returnMember->isStream);
                if (p && !returnMember->metadata.empty())
                {
                    p->setMetadata(returnMember->metadata);
                }
            }

            yyval = op;
        }
        else
        {
            yyval = 0;
        }
    }
    else
    {
        yyval = 0;
    }
}
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
#line 3098 "src/Slice/Grammar.cpp"
    break;

  case 98: /* operation_preamble: return_type keyword '('  */
#line 1316 "src/Slice/Grammar.y"
=======
#line 3100 "src/Slice/Grammar.cpp"
=======
#line 3104 "src/Slice/Grammar.cpp"
>>>>>>> Added support for type-alias metadata.
    break;

  case 101: /* operation_preamble: return_type keyword '('  */
#line 1301 "src/Slice/Grammar.y"
>>>>>>> Regenerated compilers, and fixed build errors.
=======
#line 3111 "src/Slice/Grammar.cpp"
=======
#line 3117 "src/Slice/Grammar.cpp"
>>>>>>> Added better error handling logic to the parser.
=======
#line 3103 "src/Slice/Grammar.cpp"
>>>>>>> More cosmetic changes.
    break;

  case 101: /* operation_preamble: return_type keyword '('  */
#line 1308 "src/Slice/Grammar.y"
>>>>>>> Added aliasing support into the parser.
=======
#line 3098 "src/Slice/Grammar.cpp"
    break;

  case 101: /* operation_preamble: return_type keyword '('  */
#line 1303 "src/Slice/Grammar.y"
>>>>>>> Fixed review comments.
{
    TaggedDefListTokPtr returnMembers = TaggedDefListTokPtr::dynamicCast(yyvsp[-2]);
    string name = StringTokPtr::dynamicCast(yyvsp[-1])->v;
    if (InterfaceDefPtr interface = InterfaceDefPtr::dynamicCast(unit->currentContainer()))
    {
        if (OperationPtr op = interface->createOperation(name))
        {
            unit->pushContainer(op);

            // Set the return members for the operation.
            for (const auto& returnMember : returnMembers->v)
            {
                MemberPtr p = op->createReturnMember(returnMember->name, returnMember->type, returnMember->isTagged,
                                                     returnMember->tag, returnMember->isStream);
                if (p && !returnMember->metadata.empty())
                {
                    p->setMetadata(returnMember->metadata);
                }
            }

            unit->error("keyword `" + name + "' cannot be used as operation name");
            yyval = op; // Dummy
        }
        else
        {
            yyval = 0;
        }
    }
    else
    {
        yyval = 0;
    }
}
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
#line 3136 "src/Slice/Grammar.cpp"
    break;

  case 99: /* operation_preamble: ICE_IDEMPOTENT return_type keyword '('  */
#line 1350 "src/Slice/Grammar.y"
=======
#line 3138 "src/Slice/Grammar.cpp"
=======
#line 3142 "src/Slice/Grammar.cpp"
>>>>>>> Added support for type-alias metadata.
    break;

  case 102: /* operation_preamble: ICE_IDEMPOTENT return_type keyword '('  */
#line 1335 "src/Slice/Grammar.y"
>>>>>>> Regenerated compilers, and fixed build errors.
=======
#line 3149 "src/Slice/Grammar.cpp"
=======
#line 3155 "src/Slice/Grammar.cpp"
>>>>>>> Added better error handling logic to the parser.
=======
#line 3141 "src/Slice/Grammar.cpp"
>>>>>>> More cosmetic changes.
    break;

  case 102: /* operation_preamble: ICE_IDEMPOTENT return_type keyword '('  */
#line 1342 "src/Slice/Grammar.y"
>>>>>>> Added aliasing support into the parser.
=======
#line 3136 "src/Slice/Grammar.cpp"
    break;

  case 102: /* operation_preamble: ICE_IDEMPOTENT return_type keyword '('  */
#line 1337 "src/Slice/Grammar.y"
>>>>>>> Fixed review comments.
{
    TaggedDefListTokPtr returnMembers = TaggedDefListTokPtr::dynamicCast(yyvsp[-2]);
    string name = StringTokPtr::dynamicCast(yyvsp[-1])->v;
    if (InterfaceDefPtr interface = InterfaceDefPtr::dynamicCast(unit->currentContainer()))
    {
        if (OperationPtr op = interface->createOperation(name, Operation::Idempotent))
        {
            unit->pushContainer(op);

            // Set the return members for the operation.
            for (const auto& returnMember : returnMembers->v)
            {
                MemberPtr p = op->createReturnMember(returnMember->name, returnMember->type, returnMember->isTagged,
                                                     returnMember->tag, returnMember->isStream);
                if (p && !returnMember->metadata.empty())
                {
                    p->setMetadata(returnMember->metadata);
                }
            }

            unit->error("keyword `" + name + "' cannot be used as operation name");
            yyval = op; // Dummy
        }
        else
        {
            yyval = 0;
        }
    }
    else
    {
        yyval = 0;
    }
}
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
#line 3174 "src/Slice/Grammar.cpp"
    break;

  case 100: /* @19: %empty  */
#line 1389 "src/Slice/Grammar.y"
=======
#line 3176 "src/Slice/Grammar.cpp"
=======
#line 3180 "src/Slice/Grammar.cpp"
>>>>>>> Added support for type-alias metadata.
    break;

  case 103: /* @20: %empty  */
#line 1374 "src/Slice/Grammar.y"
>>>>>>> Regenerated compilers, and fixed build errors.
=======
#line 3187 "src/Slice/Grammar.cpp"
=======
#line 3193 "src/Slice/Grammar.cpp"
>>>>>>> Added better error handling logic to the parser.
=======
#line 3179 "src/Slice/Grammar.cpp"
>>>>>>> More cosmetic changes.
    break;

  case 103: /* @20: %empty  */
#line 1381 "src/Slice/Grammar.y"
>>>>>>> Added aliasing support into the parser.
=======
#line 3174 "src/Slice/Grammar.cpp"
    break;

  case 103: /* @20: %empty  */
#line 1376 "src/Slice/Grammar.y"
>>>>>>> Fixed review comments.
{
    if(yyvsp[-2])
    {
        unit->popContainer();
        yyval = yyvsp[-2];
    }
    else
    {
        yyval = 0;
    }
}
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
#line 3190 "src/Slice/Grammar.cpp"
    break;

  case 101: /* operation: operation_preamble parameters ')' @19 throws  */
#line 1401 "src/Slice/Grammar.y"
=======
#line 3192 "src/Slice/Grammar.cpp"
=======
#line 3196 "src/Slice/Grammar.cpp"
>>>>>>> Added support for type-alias metadata.
    break;

  case 104: /* operation: operation_preamble parameters ')' @20 throws  */
#line 1386 "src/Slice/Grammar.y"
>>>>>>> Regenerated compilers, and fixed build errors.
=======
#line 3203 "src/Slice/Grammar.cpp"
=======
#line 3209 "src/Slice/Grammar.cpp"
>>>>>>> Added better error handling logic to the parser.
=======
#line 3195 "src/Slice/Grammar.cpp"
>>>>>>> More cosmetic changes.
    break;

  case 104: /* operation: operation_preamble parameters ')' @20 throws  */
#line 1393 "src/Slice/Grammar.y"
>>>>>>> Added aliasing support into the parser.
=======
#line 3190 "src/Slice/Grammar.cpp"
    break;

  case 104: /* operation: operation_preamble parameters ')' @20 throws  */
#line 1388 "src/Slice/Grammar.y"
>>>>>>> Fixed review comments.
{
    OperationPtr op = OperationPtr::dynamicCast(yyvsp[-1]);
    ExceptionListTokPtr el = ExceptionListTokPtr::dynamicCast(yyvsp[0]);
    assert(el);
    if(op)
    {
        op->setExceptionList(el->v);
    }
}
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
#line 3204 "src/Slice/Grammar.cpp"
    break;

  case 102: /* @20: %empty  */
#line 1411 "src/Slice/Grammar.y"
=======
#line 3206 "src/Slice/Grammar.cpp"
=======
#line 3210 "src/Slice/Grammar.cpp"
>>>>>>> Added support for type-alias metadata.
    break;

  case 105: /* @21: %empty  */
#line 1396 "src/Slice/Grammar.y"
>>>>>>> Regenerated compilers, and fixed build errors.
=======
#line 3217 "src/Slice/Grammar.cpp"
=======
#line 3223 "src/Slice/Grammar.cpp"
>>>>>>> Added better error handling logic to the parser.
=======
#line 3209 "src/Slice/Grammar.cpp"
>>>>>>> More cosmetic changes.
    break;

  case 105: /* @21: %empty  */
#line 1403 "src/Slice/Grammar.y"
>>>>>>> Added aliasing support into the parser.
=======
#line 3204 "src/Slice/Grammar.cpp"
    break;

  case 105: /* @21: %empty  */
#line 1398 "src/Slice/Grammar.y"
>>>>>>> Fixed review comments.
{
    if(yyvsp[-2])
    {
        unit->popContainer();
    }
    yyerrok;
}
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
#line 3216 "src/Slice/Grammar.cpp"
    break;

  case 103: /* operation: operation_preamble error ')' @20 throws  */
#line 1419 "src/Slice/Grammar.y"
=======
#line 3218 "src/Slice/Grammar.cpp"
=======
#line 3222 "src/Slice/Grammar.cpp"
>>>>>>> Added support for type-alias metadata.
    break;

  case 106: /* operation: operation_preamble error ')' @21 throws  */
#line 1404 "src/Slice/Grammar.y"
>>>>>>> Regenerated compilers, and fixed build errors.
=======
#line 3229 "src/Slice/Grammar.cpp"
=======
#line 3235 "src/Slice/Grammar.cpp"
>>>>>>> Added better error handling logic to the parser.
=======
#line 3221 "src/Slice/Grammar.cpp"
>>>>>>> More cosmetic changes.
    break;

  case 106: /* operation: operation_preamble error ')' @21 throws  */
#line 1411 "src/Slice/Grammar.y"
>>>>>>> Added aliasing support into the parser.
=======
#line 3216 "src/Slice/Grammar.cpp"
    break;

  case 106: /* operation: operation_preamble error ')' @21 throws  */
#line 1406 "src/Slice/Grammar.y"
>>>>>>> Fixed review comments.
{
    OperationPtr op = OperationPtr::dynamicCast(yyvsp[-1]);
    ExceptionListTokPtr el = ExceptionListTokPtr::dynamicCast(yyvsp[0]);
    assert(el);
    if(op)
    {
        op->setExceptionList(el->v); // Dummy
    }
}
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
#line 3230 "src/Slice/Grammar.cpp"
    break;

  case 104: /* operation_list: local_metadata operation ';' operation_list  */
#line 1434 "src/Slice/Grammar.y"
=======
#line 3232 "src/Slice/Grammar.cpp"
=======
#line 3236 "src/Slice/Grammar.cpp"
>>>>>>> Added support for type-alias metadata.
    break;

  case 107: /* operation_list: local_metadata operation ';' operation_list  */
#line 1419 "src/Slice/Grammar.y"
>>>>>>> Regenerated compilers, and fixed build errors.
=======
#line 3243 "src/Slice/Grammar.cpp"
=======
#line 3249 "src/Slice/Grammar.cpp"
>>>>>>> Added better error handling logic to the parser.
=======
#line 3235 "src/Slice/Grammar.cpp"
>>>>>>> More cosmetic changes.
    break;

  case 107: /* operation_list: local_metadata operation ';' operation_list  */
#line 1426 "src/Slice/Grammar.y"
>>>>>>> Added aliasing support into the parser.
=======
#line 3230 "src/Slice/Grammar.cpp"
    break;

  case 107: /* operation_list: local_metadata operation ';' operation_list  */
#line 1421 "src/Slice/Grammar.y"
>>>>>>> Fixed review comments.
{
    StringListTokPtr metadata = StringListTokPtr::dynamicCast(yyvsp[-3]);
    OperationPtr operation = OperationPtr::dynamicCast(yyvsp[-2]);
    if (operation && !metadata->v.empty())
    {
        operation->setMetadata(metadata->v);

        // If the operation had a single return type (not a return tuple), also apply the metadata to the return type.
        // TODO: once we introduce more concrete metadata validation, we could sort the metadata out between the return
        // type and the operation itself. So metadata relevant to operations would only be set for the operation, and
        // metadata only relevant to the return type would only be set on the return type.
        if (operation->hasSingleReturnType())
        {
            MemberPtr returnType = operation->returnType().front();
            StringList returnMetadata = returnType->getAllMetadata();

            // Merge any metadata specified on the operation into the return type.
            returnType->setMetadata(appendMetadata(metadata->v, returnMetadata));
        }
    }
}
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
#line 3252 "src/Slice/Grammar.cpp"
    break;

  case 105: /* operation_list: local_metadata operation  */
#line 1452 "src/Slice/Grammar.y"
{
    unit->error("`;' missing after definition");
}
#line 3260 "src/Slice/Grammar.cpp"
    break;

  case 108: /* interface_id: ICE_INTERFACE ICE_IDENTIFIER  */
#line 1463 "src/Slice/Grammar.y"
{
    yyval = yyvsp[0];
}
#line 3268 "src/Slice/Grammar.cpp"
    break;

  case 109: /* interface_id: ICE_INTERFACE keyword  */
#line 1467 "src/Slice/Grammar.y"
=======
#line 3254 "src/Slice/Grammar.cpp"
=======
#line 3258 "src/Slice/Grammar.cpp"
>>>>>>> Added support for type-alias metadata.
=======
#line 3268 "src/Slice/Grammar.cpp"
>>>>>>> Added aliasing support into the parser.
=======
#line 3274 "src/Slice/Grammar.cpp"
>>>>>>> Added better error handling logic to the parser.
=======
#line 3260 "src/Slice/Grammar.cpp"
>>>>>>> More cosmetic changes.
=======
#line 3255 "src/Slice/Grammar.cpp"
>>>>>>> Fixed review comments.
=======
#line 3256 "src/Slice/Grammar.cpp"
>>>>>>> Next batch of review fixes.
    break;

  case 108: /* operation_list: local_metadata operation  */
#line 1443 "src/Slice/Grammar.y"
{
    unit->error("`;' missing after definition");
}
#line 3264 "src/Slice/Grammar.cpp"
    break;

  case 111: /* interface_id: ICE_INTERFACE ICE_IDENTIFIER  */
#line 1454 "src/Slice/Grammar.y"
{
    yyval = yyvsp[0];
}
#line 3272 "src/Slice/Grammar.cpp"
    break;

  case 112: /* interface_id: ICE_INTERFACE keyword  */
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
#line 1452 "src/Slice/Grammar.y"
>>>>>>> Regenerated compilers, and fixed build errors.
=======
#line 1462 "src/Slice/Grammar.y"
>>>>>>> Added aliasing support into the parser.
=======
#line 1457 "src/Slice/Grammar.y"
>>>>>>> Fixed review comments.
=======
#line 1458 "src/Slice/Grammar.y"
>>>>>>> Next batch of review fixes.
{
    StringTokPtr ident = StringTokPtr::dynamicCast(yyvsp[0]);
    unit->error("keyword `" + ident->v + "' cannot be used as interface name");
    yyval = yyvsp[0]; // Dummy
}
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
#line 3278 "src/Slice/Grammar.cpp"
    break;

  case 110: /* interface_decl: interface_id  */
#line 1478 "src/Slice/Grammar.y"
=======
#line 3280 "src/Slice/Grammar.cpp"
=======
#line 3284 "src/Slice/Grammar.cpp"
>>>>>>> Added support for type-alias metadata.
    break;

  case 113: /* interface_decl: interface_id  */
#line 1463 "src/Slice/Grammar.y"
>>>>>>> Regenerated compilers, and fixed build errors.
=======
#line 3294 "src/Slice/Grammar.cpp"
=======
#line 3300 "src/Slice/Grammar.cpp"
>>>>>>> Added better error handling logic to the parser.
=======
#line 3286 "src/Slice/Grammar.cpp"
>>>>>>> More cosmetic changes.
    break;

  case 113: /* interface_decl: interface_id  */
#line 1473 "src/Slice/Grammar.y"
>>>>>>> Added aliasing support into the parser.
=======
#line 3281 "src/Slice/Grammar.cpp"
    break;

  case 113: /* interface_decl: interface_id  */
#line 1468 "src/Slice/Grammar.y"
>>>>>>> Fixed review comments.
=======
#line 3282 "src/Slice/Grammar.cpp"
    break;

  case 113: /* interface_decl: interface_id  */
#line 1469 "src/Slice/Grammar.y"
>>>>>>> Next batch of review fixes.
{
    StringTokPtr ident = StringTokPtr::dynamicCast(yyvsp[0]);
    ModulePtr cont = unit->currentModule();
    InterfaceDeclPtr cl = cont->createInterfaceDecl(ident->v);
    cont->checkIntroduced(ident->v, cl);
    yyval = cl;
}
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
#line 3290 "src/Slice/Grammar.cpp"
    break;

  case 111: /* @21: %empty  */
#line 1491 "src/Slice/Grammar.y"
=======
#line 3292 "src/Slice/Grammar.cpp"
=======
#line 3296 "src/Slice/Grammar.cpp"
>>>>>>> Added support for type-alias metadata.
    break;

  case 114: /* @22: %empty  */
#line 1476 "src/Slice/Grammar.y"
>>>>>>> Regenerated compilers, and fixed build errors.
=======
#line 3306 "src/Slice/Grammar.cpp"
=======
#line 3312 "src/Slice/Grammar.cpp"
>>>>>>> Added better error handling logic to the parser.
=======
#line 3298 "src/Slice/Grammar.cpp"
>>>>>>> More cosmetic changes.
    break;

  case 114: /* @22: %empty  */
#line 1486 "src/Slice/Grammar.y"
>>>>>>> Added aliasing support into the parser.
=======
#line 3293 "src/Slice/Grammar.cpp"
    break;

  case 114: /* @22: %empty  */
#line 1481 "src/Slice/Grammar.y"
>>>>>>> Fixed review comments.
=======
#line 3294 "src/Slice/Grammar.cpp"
    break;

  case 114: /* @22: %empty  */
#line 1482 "src/Slice/Grammar.y"
>>>>>>> Next batch of review fixes.
{
    StringTokPtr ident = StringTokPtr::dynamicCast(yyvsp[-1]);
    ModulePtr cont = unit->currentModule();
    InterfaceListTokPtr bases = InterfaceListTokPtr::dynamicCast(yyvsp[0]);
    InterfaceDefPtr interface = cont->createInterfaceDef(ident->v, bases->v);
    if(interface)
    {
        cont->checkIntroduced(ident->v, interface);
        unit->pushContainer(interface);
        yyval = interface;
    }
    else
    {
        yyval = 0;
    }
}
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
#line 3311 "src/Slice/Grammar.cpp"
    break;

  case 112: /* interface_def: interface_id interface_extends @21 '{' operation_list '}'  */
#line 1508 "src/Slice/Grammar.y"
=======
#line 3313 "src/Slice/Grammar.cpp"
=======
#line 3317 "src/Slice/Grammar.cpp"
>>>>>>> Added support for type-alias metadata.
    break;

  case 115: /* interface_def: interface_id interface_extends @22 '{' operation_list '}'  */
#line 1493 "src/Slice/Grammar.y"
>>>>>>> Regenerated compilers, and fixed build errors.
=======
#line 3327 "src/Slice/Grammar.cpp"
=======
#line 3333 "src/Slice/Grammar.cpp"
>>>>>>> Added better error handling logic to the parser.
=======
#line 3319 "src/Slice/Grammar.cpp"
>>>>>>> More cosmetic changes.
    break;

  case 115: /* interface_def: interface_id interface_extends @22 '{' operation_list '}'  */
#line 1503 "src/Slice/Grammar.y"
>>>>>>> Added aliasing support into the parser.
=======
#line 3314 "src/Slice/Grammar.cpp"
    break;

  case 115: /* interface_def: interface_id interface_extends @22 '{' operation_list '}'  */
#line 1498 "src/Slice/Grammar.y"
>>>>>>> Fixed review comments.
=======
#line 3315 "src/Slice/Grammar.cpp"
    break;

  case 115: /* interface_def: interface_id interface_extends @22 '{' operation_list '}'  */
#line 1499 "src/Slice/Grammar.y"
>>>>>>> Next batch of review fixes.
{
    if(yyvsp[-3])
    {
        unit->popContainer();
        yyval = yyvsp[-3];
    }
    else
    {
        yyval = 0;
    }
}
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
#line 3327 "src/Slice/Grammar.cpp"
    break;

  case 113: /* interface_list: scoped_name ',' interface_list  */
#line 1525 "src/Slice/Grammar.y"
=======
#line 3329 "src/Slice/Grammar.cpp"
=======
#line 3333 "src/Slice/Grammar.cpp"
>>>>>>> Added support for type-alias metadata.
    break;

  case 116: /* interface_list: scoped_name ',' interface_list  */
#line 1510 "src/Slice/Grammar.y"
>>>>>>> Regenerated compilers, and fixed build errors.
=======
#line 3343 "src/Slice/Grammar.cpp"
=======
#line 3349 "src/Slice/Grammar.cpp"
>>>>>>> Added better error handling logic to the parser.
=======
#line 3335 "src/Slice/Grammar.cpp"
>>>>>>> More cosmetic changes.
    break;

  case 116: /* interface_list: scoped_name ',' interface_list  */
#line 1520 "src/Slice/Grammar.y"
>>>>>>> Added aliasing support into the parser.
=======
#line 3330 "src/Slice/Grammar.cpp"
    break;

  case 116: /* interface_list: scoped_name ',' interface_list  */
#line 1515 "src/Slice/Grammar.y"
>>>>>>> Fixed review comments.
=======
#line 3331 "src/Slice/Grammar.cpp"
    break;

  case 116: /* interface_list: scoped_name ',' interface_list  */
#line 1516 "src/Slice/Grammar.y"
>>>>>>> Next batch of review fixes.
{
    InterfaceListTokPtr intfs = InterfaceListTokPtr::dynamicCast(yyvsp[0]);
    StringTokPtr scoped = StringTokPtr::dynamicCast(yyvsp[-2]);
    ContainerPtr cont = unit->currentContainer();
    TypeList types = cont->lookupType(scoped->v);
    if (!types.empty())
    {
        InterfaceDeclPtr interface = InterfaceDeclPtr::dynamicCast(types.front());
        if (!interface)
        {
            if (auto alias = TypeAliasPtr::dynamicCast(types.front()))
            {
                interface = InterfaceDeclPtr::dynamicCast(alias->underlying());
            }
        }

        if (interface)
        {
            InterfaceDefPtr def = interface->definition();
            if (!def)
            {
                unit->error("`" + scoped->v + "' has been declared but not defined");
            }
            else
            {
                cont->checkIntroduced(scoped->v);
                intfs->v.push_front(def);
            }
        }
        else
        {
            unit->error("`" + scoped->v + "' is not an interface");
        }
    }
    yyval = intfs;
}
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
#line 3366 "src/Slice/Grammar.cpp"
    break;

  case 114: /* interface_list: scoped_name  */
#line 1560 "src/Slice/Grammar.y"
=======
#line 3368 "src/Slice/Grammar.cpp"
=======
#line 3372 "src/Slice/Grammar.cpp"
>>>>>>> Added support for type-alias metadata.
    break;

  case 117: /* interface_list: scoped_name  */
#line 1545 "src/Slice/Grammar.y"
>>>>>>> Regenerated compilers, and fixed build errors.
=======
#line 3389 "src/Slice/Grammar.cpp"
=======
#line 3395 "src/Slice/Grammar.cpp"
>>>>>>> Added better error handling logic to the parser.
=======
#line 3381 "src/Slice/Grammar.cpp"
>>>>>>> More cosmetic changes.
    break;

  case 117: /* interface_list: scoped_name  */
#line 1562 "src/Slice/Grammar.y"
>>>>>>> Added aliasing support into the parser.
=======
#line 3371 "src/Slice/Grammar.cpp"
    break;

  case 117: /* interface_list: scoped_name  */
#line 1552 "src/Slice/Grammar.y"
>>>>>>> Fixed review comments.
=======
#line 3372 "src/Slice/Grammar.cpp"
    break;

  case 117: /* interface_list: scoped_name  */
#line 1553 "src/Slice/Grammar.y"
>>>>>>> Next batch of review fixes.
{
    InterfaceListTokPtr intfs = new InterfaceListTok;
    StringTokPtr scoped = StringTokPtr::dynamicCast(yyvsp[0]);
    ContainerPtr cont = unit->currentContainer();
    TypeList types = cont->lookupType(scoped->v);
    if (!types.empty())
    {
        InterfaceDeclPtr interface = InterfaceDeclPtr::dynamicCast(types.front());
        if (!interface)
        {
            if (auto alias = TypeAliasPtr::dynamicCast(types.front()))
            {
                interface = InterfaceDeclPtr::dynamicCast(alias->underlying());
            }
        }

        if (interface)
        {
            InterfaceDefPtr def = interface->definition();
            if (!def)
            {
                unit->error("`" + scoped->v + "' has been declared but not defined"); // $$ is a dummy
            }
            else
            {
                cont->checkIntroduced(scoped->v);
                intfs->v.push_front(def);
            }
        }
        else
        {
            unit->error("`" + scoped->v + "' is not an interface"); // $$ is a dummy
        }
    }
    yyval = intfs;
}
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
#line 3405 "src/Slice/Grammar.cpp"
    break;

  case 115: /* interface_list: ICE_OBJECT  */
#line 1595 "src/Slice/Grammar.y"
=======
#line 3407 "src/Slice/Grammar.cpp"
=======
#line 3411 "src/Slice/Grammar.cpp"
>>>>>>> Added support for type-alias metadata.
    break;

  case 118: /* interface_list: ICE_OBJECT  */
#line 1580 "src/Slice/Grammar.y"
>>>>>>> Regenerated compilers, and fixed build errors.
=======
#line 3435 "src/Slice/Grammar.cpp"
=======
#line 3441 "src/Slice/Grammar.cpp"
>>>>>>> Added better error handling logic to the parser.
=======
#line 3427 "src/Slice/Grammar.cpp"
>>>>>>> More cosmetic changes.
    break;

  case 118: /* interface_list: ICE_OBJECT  */
#line 1604 "src/Slice/Grammar.y"
>>>>>>> Added aliasing support into the parser.
=======
#line 3417 "src/Slice/Grammar.cpp"
    break;

  case 118: /* interface_list: ICE_OBJECT  */
#line 1594 "src/Slice/Grammar.y"
>>>>>>> Fixed review comments.
=======
#line 3412 "src/Slice/Grammar.cpp"
    break;

  case 118: /* interface_list: ICE_OBJECT  */
#line 1589 "src/Slice/Grammar.y"
>>>>>>> Fixed the tests.
=======
#line 3413 "src/Slice/Grammar.cpp"
    break;

  case 118: /* interface_list: ICE_OBJECT  */
#line 1590 "src/Slice/Grammar.y"
>>>>>>> Next batch of review fixes.
{
    unit->error("illegal inheritance from type Object");
    yyval = new InterfaceListTok; // Dummy
}
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
#line 3414 "src/Slice/Grammar.cpp"
    break;

  case 116: /* interface_list: ICE_ANYCLASS  */
#line 1600 "src/Slice/Grammar.y"
=======
#line 3416 "src/Slice/Grammar.cpp"
=======
#line 3420 "src/Slice/Grammar.cpp"
>>>>>>> Added support for type-alias metadata.
    break;

  case 119: /* interface_list: ICE_ANYCLASS  */
#line 1585 "src/Slice/Grammar.y"
>>>>>>> Regenerated compilers, and fixed build errors.
=======
#line 3444 "src/Slice/Grammar.cpp"
=======
#line 3450 "src/Slice/Grammar.cpp"
>>>>>>> Added better error handling logic to the parser.
=======
#line 3436 "src/Slice/Grammar.cpp"
>>>>>>> More cosmetic changes.
    break;

  case 119: /* interface_list: ICE_ANYCLASS  */
#line 1609 "src/Slice/Grammar.y"
>>>>>>> Added aliasing support into the parser.
=======
#line 3426 "src/Slice/Grammar.cpp"
    break;

  case 119: /* interface_list: ICE_ANYCLASS  */
#line 1599 "src/Slice/Grammar.y"
>>>>>>> Fixed review comments.
=======
#line 3421 "src/Slice/Grammar.cpp"
    break;

  case 119: /* interface_list: ICE_ANYCLASS  */
#line 1594 "src/Slice/Grammar.y"
>>>>>>> Fixed the tests.
=======
#line 3422 "src/Slice/Grammar.cpp"
    break;

  case 119: /* interface_list: ICE_ANYCLASS  */
#line 1595 "src/Slice/Grammar.y"
>>>>>>> Next batch of review fixes.
{
    unit->error("illegal inheritance from type AnyClass");
    yyval = new ClassListTok; // Dummy
}
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
#line 3423 "src/Slice/Grammar.cpp"
    break;

  case 117: /* interface_list: ICE_VALUE  */
#line 1605 "src/Slice/Grammar.y"
=======
#line 3425 "src/Slice/Grammar.cpp"
=======
#line 3429 "src/Slice/Grammar.cpp"
>>>>>>> Added support for type-alias metadata.
    break;

  case 120: /* interface_list: ICE_VALUE  */
#line 1590 "src/Slice/Grammar.y"
>>>>>>> Regenerated compilers, and fixed build errors.
=======
#line 3453 "src/Slice/Grammar.cpp"
=======
#line 3459 "src/Slice/Grammar.cpp"
>>>>>>> Added better error handling logic to the parser.
=======
#line 3445 "src/Slice/Grammar.cpp"
>>>>>>> More cosmetic changes.
    break;

  case 120: /* interface_list: ICE_VALUE  */
#line 1614 "src/Slice/Grammar.y"
>>>>>>> Added aliasing support into the parser.
=======
#line 3435 "src/Slice/Grammar.cpp"
    break;

  case 120: /* interface_list: ICE_VALUE  */
#line 1604 "src/Slice/Grammar.y"
>>>>>>> Fixed review comments.
=======
#line 3430 "src/Slice/Grammar.cpp"
    break;

  case 120: /* interface_list: ICE_VALUE  */
#line 1599 "src/Slice/Grammar.y"
>>>>>>> Fixed the tests.
=======
#line 3431 "src/Slice/Grammar.cpp"
    break;

  case 120: /* interface_list: ICE_VALUE  */
#line 1600 "src/Slice/Grammar.y"
>>>>>>> Next batch of review fixes.
{
    if (!unit->compatMode())
    {
        unit->warning(Deprecated, "the `Value' keyword is deprecated, use `AnyClass' instead");
    }
    unit->error("illegal inheritance from type Value");
    yyval = new ClassListTok; // Dummy
}
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
#line 3436 "src/Slice/Grammar.cpp"
    break;

  case 118: /* interface_extends: extends interface_list  */
#line 1619 "src/Slice/Grammar.y"
{
    yyval = yyvsp[0];
}
#line 3444 "src/Slice/Grammar.cpp"
    break;

  case 119: /* interface_extends: %empty  */
#line 1623 "src/Slice/Grammar.y"
{
    yyval = new InterfaceListTok;
}
#line 3452 "src/Slice/Grammar.cpp"
    break;

  case 120: /* exception_list: exception ',' exception_list  */
#line 1632 "src/Slice/Grammar.y"
=======
#line 3438 "src/Slice/Grammar.cpp"
=======
#line 3442 "src/Slice/Grammar.cpp"
>>>>>>> Added support for type-alias metadata.
=======
#line 3466 "src/Slice/Grammar.cpp"
>>>>>>> Added aliasing support into the parser.
=======
#line 3472 "src/Slice/Grammar.cpp"
>>>>>>> Added better error handling logic to the parser.
=======
#line 3458 "src/Slice/Grammar.cpp"
>>>>>>> More cosmetic changes.
=======
#line 3448 "src/Slice/Grammar.cpp"
>>>>>>> Fixed review comments.
=======
#line 3443 "src/Slice/Grammar.cpp"
>>>>>>> Fixed the tests.
=======
#line 3444 "src/Slice/Grammar.cpp"
>>>>>>> Next batch of review fixes.
    break;

  case 121: /* interface_extends: extends interface_list  */
#line 1614 "src/Slice/Grammar.y"
{
    yyval = yyvsp[0];
}
#line 3452 "src/Slice/Grammar.cpp"
    break;

  case 122: /* interface_extends: %empty  */
#line 1618 "src/Slice/Grammar.y"
{
    yyval = new InterfaceListTok;
}
#line 3460 "src/Slice/Grammar.cpp"
    break;

  case 123: /* exception_list: exception ',' exception_list  */
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
#line 1617 "src/Slice/Grammar.y"
>>>>>>> Regenerated compilers, and fixed build errors.
=======
#line 1641 "src/Slice/Grammar.y"
>>>>>>> Added aliasing support into the parser.
=======
#line 1631 "src/Slice/Grammar.y"
>>>>>>> Fixed review comments.
=======
#line 1626 "src/Slice/Grammar.y"
>>>>>>> Fixed the tests.
=======
#line 1627 "src/Slice/Grammar.y"
>>>>>>> Next batch of review fixes.
{
    ExceptionPtr exception = ExceptionPtr::dynamicCast(yyvsp[-2]);
    ExceptionListTokPtr exceptionList = ExceptionListTokPtr::dynamicCast(yyvsp[0]);
    exceptionList->v.push_front(exception);
    yyval = exceptionList;
}
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
#line 3463 "src/Slice/Grammar.cpp"
    break;

  case 121: /* exception_list: exception  */
#line 1639 "src/Slice/Grammar.y"
=======
#line 3465 "src/Slice/Grammar.cpp"
=======
#line 3469 "src/Slice/Grammar.cpp"
>>>>>>> Added support for type-alias metadata.
    break;

  case 124: /* exception_list: exception  */
#line 1624 "src/Slice/Grammar.y"
>>>>>>> Regenerated compilers, and fixed build errors.
=======
#line 3493 "src/Slice/Grammar.cpp"
=======
#line 3499 "src/Slice/Grammar.cpp"
>>>>>>> Added better error handling logic to the parser.
=======
#line 3485 "src/Slice/Grammar.cpp"
>>>>>>> More cosmetic changes.
    break;

  case 124: /* exception_list: exception  */
#line 1648 "src/Slice/Grammar.y"
>>>>>>> Added aliasing support into the parser.
=======
#line 3475 "src/Slice/Grammar.cpp"
    break;

  case 124: /* exception_list: exception  */
#line 1638 "src/Slice/Grammar.y"
>>>>>>> Fixed review comments.
=======
#line 3470 "src/Slice/Grammar.cpp"
    break;

  case 124: /* exception_list: exception  */
#line 1633 "src/Slice/Grammar.y"
>>>>>>> Fixed the tests.
=======
#line 3471 "src/Slice/Grammar.cpp"
    break;

  case 124: /* exception_list: exception  */
#line 1634 "src/Slice/Grammar.y"
>>>>>>> Next batch of review fixes.
{
    ExceptionPtr exception = ExceptionPtr::dynamicCast(yyvsp[0]);
    ExceptionListTokPtr exceptionList = new ExceptionListTok;
    exceptionList->v.push_front(exception);
    yyval = exceptionList;
}
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
#line 3474 "src/Slice/Grammar.cpp"
    break;

  case 122: /* exception: scoped_name  */
#line 1651 "src/Slice/Grammar.y"
=======
#line 3476 "src/Slice/Grammar.cpp"
=======
#line 3480 "src/Slice/Grammar.cpp"
>>>>>>> Added support for type-alias metadata.
    break;

  case 125: /* exception: scoped_name  */
#line 1636 "src/Slice/Grammar.y"
>>>>>>> Regenerated compilers, and fixed build errors.
=======
#line 3504 "src/Slice/Grammar.cpp"
=======
#line 3510 "src/Slice/Grammar.cpp"
>>>>>>> Added better error handling logic to the parser.
=======
#line 3496 "src/Slice/Grammar.cpp"
>>>>>>> More cosmetic changes.
    break;

  case 125: /* exception: scoped_name  */
#line 1660 "src/Slice/Grammar.y"
>>>>>>> Added aliasing support into the parser.
=======
#line 3486 "src/Slice/Grammar.cpp"
    break;

  case 125: /* exception: scoped_name  */
#line 1650 "src/Slice/Grammar.y"
>>>>>>> Fixed review comments.
=======
#line 3481 "src/Slice/Grammar.cpp"
    break;

  case 125: /* exception: scoped_name  */
#line 1645 "src/Slice/Grammar.y"
>>>>>>> Fixed the tests.
=======
#line 3482 "src/Slice/Grammar.cpp"
    break;

  case 125: /* exception: scoped_name  */
#line 1646 "src/Slice/Grammar.y"
>>>>>>> Next batch of review fixes.
{
    StringTokPtr scoped = StringTokPtr::dynamicCast(yyvsp[0]);
    ContainerPtr cont = unit->currentContainer();
    ExceptionPtr exception = cont->lookupException(scoped->v);
    if(!exception)
    {
        exception = unit->currentModule()->createException(IceUtil::generateUUID(), 0, Dummy); // Dummy
    }
    cont->checkIntroduced(scoped->v, exception);
    yyval = exception;
}
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
#line 3490 "src/Slice/Grammar.cpp"
    break;

  case 123: /* exception: keyword  */
#line 1663 "src/Slice/Grammar.y"
=======
#line 3492 "src/Slice/Grammar.cpp"
=======
#line 3496 "src/Slice/Grammar.cpp"
>>>>>>> Added support for type-alias metadata.
    break;

  case 126: /* exception: keyword  */
#line 1648 "src/Slice/Grammar.y"
>>>>>>> Regenerated compilers, and fixed build errors.
=======
#line 3520 "src/Slice/Grammar.cpp"
=======
#line 3526 "src/Slice/Grammar.cpp"
>>>>>>> Added better error handling logic to the parser.
=======
#line 3512 "src/Slice/Grammar.cpp"
>>>>>>> More cosmetic changes.
    break;

  case 126: /* exception: keyword  */
#line 1672 "src/Slice/Grammar.y"
>>>>>>> Added aliasing support into the parser.
=======
#line 3502 "src/Slice/Grammar.cpp"
    break;

  case 126: /* exception: keyword  */
#line 1662 "src/Slice/Grammar.y"
>>>>>>> Fixed review comments.
=======
#line 3497 "src/Slice/Grammar.cpp"
    break;

  case 126: /* exception: keyword  */
#line 1657 "src/Slice/Grammar.y"
>>>>>>> Fixed the tests.
=======
#line 3498 "src/Slice/Grammar.cpp"
    break;

  case 126: /* exception: keyword  */
#line 1658 "src/Slice/Grammar.y"
>>>>>>> Next batch of review fixes.
{
    StringTokPtr ident = StringTokPtr::dynamicCast(yyvsp[0]);
    unit->error("keyword `" + ident->v + "' cannot be used as exception name");
    yyval = unit->currentModule()->createException(IceUtil::generateUUID(), 0, Dummy); // Dummy
}
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
#line 3500 "src/Slice/Grammar.cpp"
    break;

  case 124: /* sequence_def: ICE_SEQUENCE '<' local_metadata type '>' ICE_IDENTIFIER  */
#line 1674 "src/Slice/Grammar.y"
=======
#line 3502 "src/Slice/Grammar.cpp"
=======
#line 3506 "src/Slice/Grammar.cpp"
>>>>>>> Added support for type-alias metadata.
=======
#line 3530 "src/Slice/Grammar.cpp"
>>>>>>> Added aliasing support into the parser.
=======
#line 3536 "src/Slice/Grammar.cpp"
>>>>>>> Added better error handling logic to the parser.
=======
#line 3522 "src/Slice/Grammar.cpp"
>>>>>>> More cosmetic changes.
=======
#line 3512 "src/Slice/Grammar.cpp"
>>>>>>> Fixed review comments.
=======
#line 3507 "src/Slice/Grammar.cpp"
>>>>>>> Fixed the tests.
=======
#line 3508 "src/Slice/Grammar.cpp"
>>>>>>> Next batch of review fixes.
    break;

  case 127: /* type_alias_def: ICE_USING ICE_IDENTIFIER '=' local_metadata type  */
#line 1669 "src/Slice/Grammar.y"
{
    StringTokPtr ident = StringTokPtr::dynamicCast(yyvsp[-3]);
    StringListTokPtr metadata = StringListTokPtr::dynamicCast(yyvsp[-1]);

    if (TypePtr type = TypePtr::dynamicCast(yyvsp[0]))
    {
        if (auto alias = TypeAliasPtr::dynamicCast(type))
        {
            appendMetadataInPlace(metadata->v, alias->typeMetadata());
            type = alias->underlying();
        }

        ModulePtr cont = unit->currentModule();
        yyval = cont->createTypeAlias(ident->v, type, metadata->v);
    }
    else
    {
        yyval = nullptr;
    }
}
#line 3533 "src/Slice/Grammar.cpp"
    break;

  case 128: /* type_alias_def: ICE_USING ICE_IDENTIFIER  */
#line 1690 "src/Slice/Grammar.y"
{
    StringTokPtr ident = StringTokPtr::dynamicCast(yyvsp[0]);
    unit->error("missing underlying type for typealias `" + ident->v + "'");
    yyval = nullptr;
}
#line 3543 "src/Slice/Grammar.cpp"
    break;

  case 129: /* type_alias_def: ICE_USING error  */
#line 1696 "src/Slice/Grammar.y"
{
    unit->error("unable to resolve underlying type");
    yyval = nullptr;
}
#line 3552 "src/Slice/Grammar.cpp"
    break;

<<<<<<< HEAD
  case 129: /* sequence_def: ICE_SEQUENCE '<' local_metadata type '>' ICE_IDENTIFIER  */
<<<<<<< HEAD
<<<<<<< HEAD
#line 1677 "src/Slice/Grammar.y"
>>>>>>> Regenerated compilers, and fixed build errors.
=======
#line 1678 "src/Slice/Grammar.y"
>>>>>>> Added support for type-alias metadata.
=======
#line 1708 "src/Slice/Grammar.y"
>>>>>>> Added aliasing support into the parser.
=======
  case 130: /* sequence_def: ICE_SEQUENCE '<' local_metadata type '>' ICE_IDENTIFIER  */
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
#line 1720 "src/Slice/Grammar.y"
>>>>>>> Added better error handling logic to the parser.
=======
#line 1719 "src/Slice/Grammar.y"
>>>>>>> More cosmetic changes.
=======
#line 1724 "src/Slice/Grammar.y"
>>>>>>> Fixed review comments.
=======
#line 1719 "src/Slice/Grammar.y"
>>>>>>> Fixed the tests.
=======
#line 1705 "src/Slice/Grammar.y"
>>>>>>> Next batch of review fixes.
{
    StringTokPtr ident = StringTokPtr::dynamicCast(yyvsp[0]);
    StringListTokPtr metadata = StringListTokPtr::dynamicCast(yyvsp[-3]);
    TypePtr type = TypePtr::dynamicCast(yyvsp[-2]);

    unalias(type, metadata->v);

    ModulePtr cont = unit->currentModule();
    yyval = cont->createSequence(ident->v, type, metadata->v);
}
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
#line 3512 "src/Slice/Grammar.cpp"
    break;

  case 125: /* sequence_def: ICE_SEQUENCE '<' local_metadata type '>' keyword  */
#line 1682 "src/Slice/Grammar.y"
=======
#line 3536 "src/Slice/Grammar.cpp"
    break;

  case 130: /* sequence_def: ICE_SEQUENCE '<' local_metadata type '>' keyword  */
#line 1685 "src/Slice/Grammar.y"
>>>>>>> Regenerated compilers, and fixed build errors.
=======
#line 3541 "src/Slice/Grammar.cpp"
    break;

  case 130: /* sequence_def: ICE_SEQUENCE '<' local_metadata type '>' keyword  */
#line 1686 "src/Slice/Grammar.y"
>>>>>>> Added support for type-alias metadata.
=======
#line 3578 "src/Slice/Grammar.cpp"
    break;

  case 130: /* sequence_def: ICE_SEQUENCE '<' local_metadata type '>' keyword  */
#line 1723 "src/Slice/Grammar.y"
>>>>>>> Added aliasing support into the parser.
=======
#line 3600 "src/Slice/Grammar.cpp"
    break;

  case 131: /* sequence_def: ICE_SEQUENCE '<' local_metadata type '>' keyword  */
#line 1735 "src/Slice/Grammar.y"
>>>>>>> Added better error handling logic to the parser.
=======
#line 3585 "src/Slice/Grammar.cpp"
    break;

  case 131: /* sequence_def: ICE_SEQUENCE '<' local_metadata type '>' keyword  */
#line 1734 "src/Slice/Grammar.y"
>>>>>>> More cosmetic changes.
=======
#line 3586 "src/Slice/Grammar.cpp"
    break;

  case 131: /* sequence_def: ICE_SEQUENCE '<' local_metadata type '>' keyword  */
#line 1735 "src/Slice/Grammar.y"
>>>>>>> Fixed review comments.
=======
#line 3581 "src/Slice/Grammar.cpp"
    break;

  case 131: /* sequence_def: ICE_SEQUENCE '<' local_metadata type '>' keyword  */
#line 1730 "src/Slice/Grammar.y"
>>>>>>> Fixed the tests.
=======
#line 3567 "src/Slice/Grammar.cpp"
    break;

  case 131: /* sequence_def: ICE_SEQUENCE '<' local_metadata type '>' keyword  */
#line 1716 "src/Slice/Grammar.y"
>>>>>>> Next batch of review fixes.
{
    StringTokPtr ident = StringTokPtr::dynamicCast(yyvsp[0]);
    StringListTokPtr metadata = StringListTokPtr::dynamicCast(yyvsp[-3]);
    TypePtr type = TypePtr::dynamicCast(yyvsp[-2]);

    unalias(type, metadata->v);

    ModulePtr cont = unit->currentModule();
    yyval = cont->createSequence(ident->v, type, metadata->v); // Dummy
    unit->error("keyword `" + ident->v + "' cannot be used as sequence name");
}
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
#line 3525 "src/Slice/Grammar.cpp"
    break;

  case 126: /* dictionary_def: ICE_DICTIONARY '<' local_metadata type ',' local_metadata type '>' ICE_IDENTIFIER  */
#line 1696 "src/Slice/Grammar.y"
=======
#line 3549 "src/Slice/Grammar.cpp"
    break;

  case 131: /* dictionary_def: ICE_DICTIONARY '<' local_metadata type ',' local_metadata type '>' ICE_IDENTIFIER  */
#line 1699 "src/Slice/Grammar.y"
>>>>>>> Regenerated compilers, and fixed build errors.
=======
#line 3554 "src/Slice/Grammar.cpp"
    break;

  case 131: /* dictionary_def: ICE_DICTIONARY '<' local_metadata type ',' local_metadata type '>' ICE_IDENTIFIER  */
#line 1700 "src/Slice/Grammar.y"
>>>>>>> Added support for type-alias metadata.
=======
#line 3598 "src/Slice/Grammar.cpp"
    break;

  case 131: /* dictionary_def: ICE_DICTIONARY '<' local_metadata type ',' local_metadata type '>' ICE_IDENTIFIER  */
#line 1744 "src/Slice/Grammar.y"
>>>>>>> Added aliasing support into the parser.
=======
#line 3620 "src/Slice/Grammar.cpp"
    break;

  case 132: /* dictionary_def: ICE_DICTIONARY '<' local_metadata type ',' local_metadata type '>' ICE_IDENTIFIER  */
#line 1756 "src/Slice/Grammar.y"
>>>>>>> Added better error handling logic to the parser.
=======
#line 3605 "src/Slice/Grammar.cpp"
    break;

  case 132: /* dictionary_def: ICE_DICTIONARY '<' local_metadata type ',' local_metadata type '>' ICE_IDENTIFIER  */
#line 1755 "src/Slice/Grammar.y"
>>>>>>> More cosmetic changes.
=======
#line 3602 "src/Slice/Grammar.cpp"
    break;

  case 132: /* dictionary_def: ICE_DICTIONARY '<' local_metadata type ',' local_metadata type '>' ICE_IDENTIFIER  */
#line 1752 "src/Slice/Grammar.y"
>>>>>>> Fixed review comments.
=======
#line 3597 "src/Slice/Grammar.cpp"
    break;

  case 132: /* dictionary_def: ICE_DICTIONARY '<' local_metadata type ',' local_metadata type '>' ICE_IDENTIFIER  */
#line 1747 "src/Slice/Grammar.y"
>>>>>>> Fixed the tests.
=======
#line 3583 "src/Slice/Grammar.cpp"
    break;

  case 132: /* dictionary_def: ICE_DICTIONARY '<' local_metadata type ',' local_metadata type '>' ICE_IDENTIFIER  */
#line 1733 "src/Slice/Grammar.y"
>>>>>>> Next batch of review fixes.
{
    StringTokPtr ident = StringTokPtr::dynamicCast(yyvsp[0]);
    StringListTokPtr keyMetadata = StringListTokPtr::dynamicCast(yyvsp[-6]);
    TypePtr keyType = TypePtr::dynamicCast(yyvsp[-5]);
    StringListTokPtr valueMetadata = StringListTokPtr::dynamicCast(yyvsp[-3]);
    TypePtr valueType = TypePtr::dynamicCast(yyvsp[-2]);

    unalias(keyType, keyMetadata->v);
    unalias(valueType, valueMetadata->v);

    ModulePtr cont = unit->currentModule();
    yyval = cont->createDictionary(ident->v, keyType, keyMetadata->v, valueType, valueMetadata->v);
}
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
#line 3539 "src/Slice/Grammar.cpp"
    break;

  case 127: /* dictionary_def: ICE_DICTIONARY '<' local_metadata type ',' local_metadata type '>' keyword  */
#line 1706 "src/Slice/Grammar.y"
=======
#line 3563 "src/Slice/Grammar.cpp"
    break;

  case 132: /* dictionary_def: ICE_DICTIONARY '<' local_metadata type ',' local_metadata type '>' keyword  */
#line 1709 "src/Slice/Grammar.y"
>>>>>>> Regenerated compilers, and fixed build errors.
=======
#line 3568 "src/Slice/Grammar.cpp"
    break;

  case 132: /* dictionary_def: ICE_DICTIONARY '<' local_metadata type ',' local_metadata type '>' keyword  */
#line 1710 "src/Slice/Grammar.y"
>>>>>>> Added support for type-alias metadata.
=======
#line 3624 "src/Slice/Grammar.cpp"
    break;

  case 132: /* dictionary_def: ICE_DICTIONARY '<' local_metadata type ',' local_metadata type '>' keyword  */
#line 1766 "src/Slice/Grammar.y"
>>>>>>> Added aliasing support into the parser.
=======
#line 3646 "src/Slice/Grammar.cpp"
    break;

  case 133: /* dictionary_def: ICE_DICTIONARY '<' local_metadata type ',' local_metadata type '>' keyword  */
#line 1778 "src/Slice/Grammar.y"
>>>>>>> Added better error handling logic to the parser.
=======
#line 3631 "src/Slice/Grammar.cpp"
    break;

  case 133: /* dictionary_def: ICE_DICTIONARY '<' local_metadata type ',' local_metadata type '>' keyword  */
#line 1777 "src/Slice/Grammar.y"
>>>>>>> More cosmetic changes.
=======
#line 3620 "src/Slice/Grammar.cpp"
    break;

  case 133: /* dictionary_def: ICE_DICTIONARY '<' local_metadata type ',' local_metadata type '>' keyword  */
#line 1766 "src/Slice/Grammar.y"
>>>>>>> Fixed review comments.
=======
#line 3615 "src/Slice/Grammar.cpp"
    break;

  case 133: /* dictionary_def: ICE_DICTIONARY '<' local_metadata type ',' local_metadata type '>' keyword  */
#line 1761 "src/Slice/Grammar.y"
>>>>>>> Fixed the tests.
=======
#line 3601 "src/Slice/Grammar.cpp"
    break;

  case 133: /* dictionary_def: ICE_DICTIONARY '<' local_metadata type ',' local_metadata type '>' keyword  */
#line 1747 "src/Slice/Grammar.y"
>>>>>>> Next batch of review fixes.
{
    StringTokPtr ident = StringTokPtr::dynamicCast(yyvsp[0]);
    StringListTokPtr keyMetadata = StringListTokPtr::dynamicCast(yyvsp[-6]);
    TypePtr keyType = TypePtr::dynamicCast(yyvsp[-5]);
    StringListTokPtr valueMetadata = StringListTokPtr::dynamicCast(yyvsp[-3]);
    TypePtr valueType = TypePtr::dynamicCast(yyvsp[-2]);

    unalias(keyType, keyMetadata->v);
    unalias(valueType, valueMetadata->v);

    ModulePtr cont = unit->currentModule();
    yyval = cont->createDictionary(ident->v, keyType, keyMetadata->v, valueType, valueMetadata->v); // Dummy
    unit->error("keyword `" + ident->v + "' cannot be used as dictionary name");
}
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
#line 3554 "src/Slice/Grammar.cpp"
    break;

  case 128: /* enum_start: ICE_UNCHECKED ICE_ENUM  */
#line 1722 "src/Slice/Grammar.y"
{
    yyval = new BoolTok(true);
}
#line 3562 "src/Slice/Grammar.cpp"
    break;

  case 129: /* enum_start: ICE_ENUM  */
#line 1726 "src/Slice/Grammar.y"
{
    yyval = new BoolTok(false);
}
#line 3570 "src/Slice/Grammar.cpp"
    break;

  case 130: /* enum_id: enum_start ICE_IDENTIFIER  */
#line 1735 "src/Slice/Grammar.y"
=======
#line 3578 "src/Slice/Grammar.cpp"
=======
#line 3583 "src/Slice/Grammar.cpp"
>>>>>>> Added support for type-alias metadata.
=======
#line 3651 "src/Slice/Grammar.cpp"
>>>>>>> Added aliasing support into the parser.
    break;

  case 133: /* enum_start: ICE_UNCHECKED ICE_ENUM  */
#line 1794 "src/Slice/Grammar.y"
{
    yyval = new BoolTok(true);
}
#line 3659 "src/Slice/Grammar.cpp"
    break;

  case 134: /* enum_start: ICE_ENUM  */
#line 1798 "src/Slice/Grammar.y"
{
    yyval = new BoolTok(false);
}
#line 3667 "src/Slice/Grammar.cpp"
    break;

  case 135: /* enum_id: enum_start ICE_IDENTIFIER  */
<<<<<<< HEAD
<<<<<<< HEAD
#line 1738 "src/Slice/Grammar.y"
>>>>>>> Regenerated compilers, and fixed build errors.
=======
#line 1739 "src/Slice/Grammar.y"
>>>>>>> Added support for type-alias metadata.
=======
#line 1807 "src/Slice/Grammar.y"
>>>>>>> Added aliasing support into the parser.
=======
#line 3673 "src/Slice/Grammar.cpp"
=======
#line 3658 "src/Slice/Grammar.cpp"
>>>>>>> More cosmetic changes.
    break;

  case 134: /* enum_start: ICE_UNCHECKED ICE_ENUM  */
#line 1805 "src/Slice/Grammar.y"
{
    yyval = new BoolTok(true);
}
#line 3666 "src/Slice/Grammar.cpp"
    break;

  case 135: /* enum_start: ICE_ENUM  */
#line 1809 "src/Slice/Grammar.y"
{
    yyval = new BoolTok(false);
}
#line 3674 "src/Slice/Grammar.cpp"
    break;

  case 136: /* enum_id: enum_start ICE_IDENTIFIER  */
<<<<<<< HEAD
#line 1819 "src/Slice/Grammar.y"
>>>>>>> Added better error handling logic to the parser.
=======
#line 1818 "src/Slice/Grammar.y"
>>>>>>> More cosmetic changes.
=======
#line 3639 "src/Slice/Grammar.cpp"
=======
#line 3634 "src/Slice/Grammar.cpp"
>>>>>>> Fixed the tests.
=======
#line 3620 "src/Slice/Grammar.cpp"
>>>>>>> Next batch of review fixes.
    break;

  case 134: /* enum_start: ICE_UNCHECKED ICE_ENUM  */
#line 1767 "src/Slice/Grammar.y"
{
    yyval = new BoolTok(true);
}
#line 3628 "src/Slice/Grammar.cpp"
    break;

  case 135: /* enum_start: ICE_ENUM  */
#line 1771 "src/Slice/Grammar.y"
{
    yyval = new BoolTok(false);
}
#line 3636 "src/Slice/Grammar.cpp"
    break;

  case 136: /* enum_id: enum_start ICE_IDENTIFIER  */
<<<<<<< HEAD
<<<<<<< HEAD
#line 1799 "src/Slice/Grammar.y"
>>>>>>> Fixed review comments.
=======
#line 1794 "src/Slice/Grammar.y"
>>>>>>> Fixed the tests.
=======
#line 1780 "src/Slice/Grammar.y"
>>>>>>> Next batch of review fixes.
{
    bool unchecked = BoolTokPtr::dynamicCast(yyvsp[-1])->v;
    StringTokPtr ident = StringTokPtr::dynamicCast(yyvsp[0]);
    ModulePtr cont = unit->currentModule();
    EnumPtr en = cont->createEnum(ident->v, unchecked);
    if (en)
    {
        cont->checkIntroduced(ident->v, en);
    }
    else
    {
        en = cont->createEnum(IceUtil::generateUUID(), unchecked, Dummy);
    }
    yyval = en;
}
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
#line 3590 "src/Slice/Grammar.cpp"
    break;

  case 131: /* enum_id: enum_start keyword  */
#line 1751 "src/Slice/Grammar.y"
=======
#line 3614 "src/Slice/Grammar.cpp"
    break;

  case 136: /* enum_id: enum_start keyword  */
#line 1754 "src/Slice/Grammar.y"
>>>>>>> Regenerated compilers, and fixed build errors.
=======
#line 3619 "src/Slice/Grammar.cpp"
    break;

  case 136: /* enum_id: enum_start keyword  */
#line 1755 "src/Slice/Grammar.y"
>>>>>>> Added support for type-alias metadata.
=======
#line 3687 "src/Slice/Grammar.cpp"
    break;

  case 136: /* enum_id: enum_start keyword  */
#line 1823 "src/Slice/Grammar.y"
>>>>>>> Added aliasing support into the parser.
=======
#line 3709 "src/Slice/Grammar.cpp"
    break;

  case 137: /* enum_id: enum_start keyword  */
#line 1835 "src/Slice/Grammar.y"
>>>>>>> Added better error handling logic to the parser.
=======
#line 3694 "src/Slice/Grammar.cpp"
    break;

  case 137: /* enum_id: enum_start keyword  */
#line 1834 "src/Slice/Grammar.y"
>>>>>>> More cosmetic changes.
=======
#line 3675 "src/Slice/Grammar.cpp"
    break;

  case 137: /* enum_id: enum_start keyword  */
#line 1815 "src/Slice/Grammar.y"
>>>>>>> Fixed review comments.
=======
#line 3670 "src/Slice/Grammar.cpp"
    break;

  case 137: /* enum_id: enum_start keyword  */
#line 1810 "src/Slice/Grammar.y"
>>>>>>> Fixed the tests.
=======
#line 3656 "src/Slice/Grammar.cpp"
    break;

  case 137: /* enum_id: enum_start keyword  */
#line 1796 "src/Slice/Grammar.y"
>>>>>>> Next batch of review fixes.
{
    bool unchecked = BoolTokPtr::dynamicCast(yyvsp[-1])->v;
    StringTokPtr ident = StringTokPtr::dynamicCast(yyvsp[0]);
    ModulePtr cont = unit->currentModule();
    unit->error("keyword `" + ident->v + "' cannot be used as enumeration name");
    yyval = cont->createEnum(IceUtil::generateUUID(), unchecked, Dummy);
}
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
#line 3602 "src/Slice/Grammar.cpp"
    break;

  case 132: /* @22: %empty  */
#line 1764 "src/Slice/Grammar.y"
=======
#line 3626 "src/Slice/Grammar.cpp"
    break;

  case 137: /* @23: %empty  */
#line 1767 "src/Slice/Grammar.y"
>>>>>>> Regenerated compilers, and fixed build errors.
=======
#line 3631 "src/Slice/Grammar.cpp"
    break;

  case 137: /* @23: %empty  */
#line 1768 "src/Slice/Grammar.y"
>>>>>>> Added support for type-alias metadata.
=======
#line 3699 "src/Slice/Grammar.cpp"
    break;

  case 137: /* @23: %empty  */
#line 1836 "src/Slice/Grammar.y"
>>>>>>> Added aliasing support into the parser.
=======
#line 3721 "src/Slice/Grammar.cpp"
    break;

  case 138: /* @23: %empty  */
#line 1848 "src/Slice/Grammar.y"
>>>>>>> Added better error handling logic to the parser.
=======
#line 3706 "src/Slice/Grammar.cpp"
    break;

  case 138: /* @23: %empty  */
#line 1847 "src/Slice/Grammar.y"
>>>>>>> More cosmetic changes.
=======
#line 3687 "src/Slice/Grammar.cpp"
    break;

  case 138: /* @23: %empty  */
#line 1828 "src/Slice/Grammar.y"
>>>>>>> Fixed review comments.
=======
#line 3682 "src/Slice/Grammar.cpp"
    break;

  case 138: /* @23: %empty  */
#line 1823 "src/Slice/Grammar.y"
>>>>>>> Fixed the tests.
=======
#line 3668 "src/Slice/Grammar.cpp"
    break;

  case 138: /* @23: %empty  */
#line 1809 "src/Slice/Grammar.y"
>>>>>>> Next batch of review fixes.
{
    EnumPtr en = EnumPtr::dynamicCast(yyvsp[-1]);
    TypePtr underlying = TypePtr::dynamicCast(yyvsp[0]);

    if (auto alias = TypeAliasPtr::dynamicCast(underlying))
    {
        if (!alias->typeMetadata().empty())
        {
            unit->error("illegal metadata: typealias metadata `" + alias->typeMetadata().front() +
                        "' cannot be used in enum declarations");
        }
        underlying = alias->underlying();
    }

    en->initUnderlying(underlying);
    unit->pushContainer(en);
    yyval = en;
}
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
#line 3613 "src/Slice/Grammar.cpp"
    break;

  case 133: /* enum_def: enum_id enum_underlying @22 '{' enumerator_list_or_empty '}'  */
#line 1771 "src/Slice/Grammar.y"
=======
#line 3637 "src/Slice/Grammar.cpp"
    break;

  case 138: /* enum_def: enum_id enum_underlying @23 '{' enumerator_list_or_empty '}'  */
#line 1774 "src/Slice/Grammar.y"
>>>>>>> Regenerated compilers, and fixed build errors.
=======
#line 3642 "src/Slice/Grammar.cpp"
    break;

  case 138: /* enum_def: enum_id enum_underlying @23 '{' enumerator_list_or_empty '}'  */
#line 1775 "src/Slice/Grammar.y"
>>>>>>> Added support for type-alias metadata.
=======
#line 3722 "src/Slice/Grammar.cpp"
    break;

  case 138: /* enum_def: enum_id enum_underlying @23 '{' enumerator_list_or_empty '}'  */
#line 1855 "src/Slice/Grammar.y"
>>>>>>> Added aliasing support into the parser.
=======
#line 3744 "src/Slice/Grammar.cpp"
    break;

  case 139: /* enum_def: enum_id enum_underlying @23 '{' enumerator_list_or_empty '}'  */
#line 1867 "src/Slice/Grammar.y"
>>>>>>> Added better error handling logic to the parser.
=======
#line 3729 "src/Slice/Grammar.cpp"
    break;

  case 139: /* enum_def: enum_id enum_underlying @23 '{' enumerator_list_or_empty '}'  */
#line 1866 "src/Slice/Grammar.y"
>>>>>>> More cosmetic changes.
=======
#line 3710 "src/Slice/Grammar.cpp"
    break;

  case 139: /* enum_def: enum_id enum_underlying @23 '{' enumerator_list_or_empty '}'  */
#line 1847 "src/Slice/Grammar.y"
>>>>>>> Fixed review comments.
=======
#line 3705 "src/Slice/Grammar.cpp"
    break;

  case 139: /* enum_def: enum_id enum_underlying @23 '{' enumerator_list_or_empty '}'  */
#line 1842 "src/Slice/Grammar.y"
>>>>>>> Fixed the tests.
=======
#line 3691 "src/Slice/Grammar.cpp"
    break;

  case 139: /* enum_def: enum_id enum_underlying @23 '{' enumerator_list_or_empty '}'  */
#line 1828 "src/Slice/Grammar.y"
>>>>>>> Next batch of review fixes.
{
    if (EnumPtr en = EnumPtr::dynamicCast(yyvsp[-3]))
    {
        EnumeratorListTokPtr enumerators = EnumeratorListTokPtr::dynamicCast(yyvsp[-1]);
        if (enumerators->v.empty() && (!en->underlying() || !en->isUnchecked()))
        {
            unit->error("enum `" + en->name() + "' must have at least one enumerator");
        }
        unit->popContainer();
    }
    yyval = yyvsp[-3];
}
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
#line 3630 "src/Slice/Grammar.cpp"
    break;

  case 134: /* @23: %empty  */
#line 1784 "src/Slice/Grammar.y"
=======
#line 3654 "src/Slice/Grammar.cpp"
    break;

  case 139: /* @24: %empty  */
#line 1787 "src/Slice/Grammar.y"
>>>>>>> Regenerated compilers, and fixed build errors.
=======
#line 3659 "src/Slice/Grammar.cpp"
    break;

  case 139: /* @24: %empty  */
#line 1788 "src/Slice/Grammar.y"
>>>>>>> Added support for type-alias metadata.
=======
#line 3739 "src/Slice/Grammar.cpp"
    break;

  case 139: /* @24: %empty  */
#line 1868 "src/Slice/Grammar.y"
>>>>>>> Added aliasing support into the parser.
=======
#line 3761 "src/Slice/Grammar.cpp"
    break;

  case 140: /* @24: %empty  */
#line 1880 "src/Slice/Grammar.y"
>>>>>>> Added better error handling logic to the parser.
=======
#line 3746 "src/Slice/Grammar.cpp"
    break;

  case 140: /* @24: %empty  */
#line 1879 "src/Slice/Grammar.y"
>>>>>>> More cosmetic changes.
=======
#line 3727 "src/Slice/Grammar.cpp"
    break;

  case 140: /* @24: %empty  */
#line 1860 "src/Slice/Grammar.y"
>>>>>>> Fixed review comments.
=======
#line 3722 "src/Slice/Grammar.cpp"
    break;

  case 140: /* @24: %empty  */
#line 1855 "src/Slice/Grammar.y"
>>>>>>> Fixed the tests.
=======
#line 3708 "src/Slice/Grammar.cpp"
    break;

  case 140: /* @24: %empty  */
#line 1841 "src/Slice/Grammar.y"
>>>>>>> Next batch of review fixes.
{
    bool unchecked = BoolTokPtr::dynamicCast(yyvsp[0])->v;
    unit->error("missing enumeration name");
    ModulePtr cont = unit->currentModule();
    EnumPtr en = cont->createEnum(IceUtil::generateUUID(), unchecked, Dummy);
    unit->pushContainer(en);
    yyval = en;
}
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
#line 3643 "src/Slice/Grammar.cpp"
    break;

  case 135: /* enum_def: enum_start @23 '{' enumerator_list_or_empty '}'  */
#line 1793 "src/Slice/Grammar.y"
=======
#line 3667 "src/Slice/Grammar.cpp"
    break;

  case 140: /* enum_def: enum_start @24 '{' enumerator_list_or_empty '}'  */
#line 1796 "src/Slice/Grammar.y"
>>>>>>> Regenerated compilers, and fixed build errors.
=======
#line 3672 "src/Slice/Grammar.cpp"
    break;

  case 140: /* enum_def: enum_start @24 '{' enumerator_list_or_empty '}'  */
#line 1797 "src/Slice/Grammar.y"
>>>>>>> Added support for type-alias metadata.
=======
#line 3752 "src/Slice/Grammar.cpp"
    break;

  case 140: /* enum_def: enum_start @24 '{' enumerator_list_or_empty '}'  */
#line 1877 "src/Slice/Grammar.y"
>>>>>>> Added aliasing support into the parser.
=======
#line 3774 "src/Slice/Grammar.cpp"
    break;

  case 141: /* enum_def: enum_start @24 '{' enumerator_list_or_empty '}'  */
#line 1889 "src/Slice/Grammar.y"
>>>>>>> Added better error handling logic to the parser.
=======
#line 3759 "src/Slice/Grammar.cpp"
    break;

  case 141: /* enum_def: enum_start @24 '{' enumerator_list_or_empty '}'  */
#line 1888 "src/Slice/Grammar.y"
>>>>>>> More cosmetic changes.
=======
#line 3740 "src/Slice/Grammar.cpp"
    break;

  case 141: /* enum_def: enum_start @24 '{' enumerator_list_or_empty '}'  */
#line 1869 "src/Slice/Grammar.y"
>>>>>>> Fixed review comments.
=======
#line 3735 "src/Slice/Grammar.cpp"
    break;

  case 141: /* enum_def: enum_start @24 '{' enumerator_list_or_empty '}'  */
#line 1864 "src/Slice/Grammar.y"
>>>>>>> Fixed the tests.
=======
#line 3721 "src/Slice/Grammar.cpp"
    break;

  case 141: /* enum_def: enum_start @24 '{' enumerator_list_or_empty '}'  */
#line 1850 "src/Slice/Grammar.y"
>>>>>>> Next batch of review fixes.
{
    unit->popContainer();
    yyval = yyvsp[-4];
}
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
#line 3652 "src/Slice/Grammar.cpp"
    break;

  case 136: /* enum_underlying: ':' type  */
#line 1803 "src/Slice/Grammar.y"
{
    yyval = yyvsp[0];
}
#line 3660 "src/Slice/Grammar.cpp"
    break;

  case 137: /* enum_underlying: %empty  */
#line 1807 "src/Slice/Grammar.y"
{
    yyval = 0;
}
#line 3668 "src/Slice/Grammar.cpp"
    break;

  case 140: /* enumerator_list_or_empty: %empty  */
#line 1818 "src/Slice/Grammar.y"
{
    yyval = new EnumeratorListTok;
}
#line 3676 "src/Slice/Grammar.cpp"
    break;

  case 141: /* enumerator_list: enumerator_list ',' enumerator  */
#line 1827 "src/Slice/Grammar.y"
=======
#line 3676 "src/Slice/Grammar.cpp"
=======
#line 3681 "src/Slice/Grammar.cpp"
>>>>>>> Added support for type-alias metadata.
=======
#line 3761 "src/Slice/Grammar.cpp"
>>>>>>> Added aliasing support into the parser.
=======
#line 3783 "src/Slice/Grammar.cpp"
>>>>>>> Added better error handling logic to the parser.
=======
#line 3768 "src/Slice/Grammar.cpp"
>>>>>>> More cosmetic changes.
=======
#line 3749 "src/Slice/Grammar.cpp"
>>>>>>> Fixed review comments.
=======
#line 3744 "src/Slice/Grammar.cpp"
>>>>>>> Fixed the tests.
=======
#line 3730 "src/Slice/Grammar.cpp"
>>>>>>> Next batch of review fixes.
    break;

  case 142: /* enum_underlying: ':' type  */
#line 1860 "src/Slice/Grammar.y"
{
    yyval = yyvsp[0];
}
#line 3738 "src/Slice/Grammar.cpp"
    break;

  case 143: /* enum_underlying: %empty  */
#line 1864 "src/Slice/Grammar.y"
{
    yyval = 0;
}
#line 3746 "src/Slice/Grammar.cpp"
    break;

  case 146: /* enumerator_list_or_empty: %empty  */
#line 1875 "src/Slice/Grammar.y"
{
    yyval = new EnumeratorListTok;
}
#line 3754 "src/Slice/Grammar.cpp"
    break;

<<<<<<< HEAD
  case 146: /* enumerator_list: enumerator_list ',' enumerator  */
<<<<<<< HEAD
<<<<<<< HEAD
#line 1830 "src/Slice/Grammar.y"
>>>>>>> Regenerated compilers, and fixed build errors.
=======
#line 1831 "src/Slice/Grammar.y"
>>>>>>> Added support for type-alias metadata.
=======
#line 1911 "src/Slice/Grammar.y"
>>>>>>> Added aliasing support into the parser.
=======
  case 147: /* enumerator_list: enumerator_list ',' enumerator  */
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
#line 1923 "src/Slice/Grammar.y"
>>>>>>> Added better error handling logic to the parser.
=======
#line 1922 "src/Slice/Grammar.y"
>>>>>>> More cosmetic changes.
=======
#line 1903 "src/Slice/Grammar.y"
>>>>>>> Fixed review comments.
=======
#line 1898 "src/Slice/Grammar.y"
>>>>>>> Fixed the tests.
=======
#line 1884 "src/Slice/Grammar.y"
>>>>>>> Next batch of review fixes.
{
    EnumeratorListTokPtr enumerators = EnumeratorListTokPtr::dynamicCast(yyvsp[-2]);
    if (EnumeratorPtr en = EnumeratorPtr::dynamicCast(yyvsp[0]))
    {
        enumerators->v.push_back(en);
    }
    yyval = enumerators;
}
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
#line 3689 "src/Slice/Grammar.cpp"
    break;

  case 142: /* enumerator_list: enumerator  */
#line 1836 "src/Slice/Grammar.y"
=======
#line 3713 "src/Slice/Grammar.cpp"
    break;

  case 147: /* enumerator_list: enumerator  */
#line 1839 "src/Slice/Grammar.y"
>>>>>>> Regenerated compilers, and fixed build errors.
=======
#line 3718 "src/Slice/Grammar.cpp"
    break;

  case 147: /* enumerator_list: enumerator  */
#line 1840 "src/Slice/Grammar.y"
>>>>>>> Added support for type-alias metadata.
=======
#line 3798 "src/Slice/Grammar.cpp"
    break;

  case 147: /* enumerator_list: enumerator  */
#line 1920 "src/Slice/Grammar.y"
>>>>>>> Added aliasing support into the parser.
=======
#line 3820 "src/Slice/Grammar.cpp"
    break;

  case 148: /* enumerator_list: enumerator  */
#line 1932 "src/Slice/Grammar.y"
>>>>>>> Added better error handling logic to the parser.
=======
#line 3805 "src/Slice/Grammar.cpp"
    break;

  case 148: /* enumerator_list: enumerator  */
#line 1931 "src/Slice/Grammar.y"
>>>>>>> More cosmetic changes.
=======
#line 3786 "src/Slice/Grammar.cpp"
    break;

  case 148: /* enumerator_list: enumerator  */
#line 1912 "src/Slice/Grammar.y"
>>>>>>> Fixed review comments.
=======
#line 3781 "src/Slice/Grammar.cpp"
    break;

  case 148: /* enumerator_list: enumerator  */
#line 1907 "src/Slice/Grammar.y"
>>>>>>> Fixed the tests.
=======
#line 3767 "src/Slice/Grammar.cpp"
    break;

  case 148: /* enumerator_list: enumerator  */
#line 1893 "src/Slice/Grammar.y"
>>>>>>> Next batch of review fixes.
{
    EnumeratorListTokPtr enumerators = new EnumeratorListTok;
    if (EnumeratorPtr en = EnumeratorPtr::dynamicCast(yyvsp[0]))
    {
        enumerators->v.push_back(en);
    }
    yyval = enumerators;
}
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
#line 3702 "src/Slice/Grammar.cpp"
    break;

  case 143: /* enumerator: local_metadata ICE_IDENTIFIER  */
#line 1850 "src/Slice/Grammar.y"
=======
#line 3726 "src/Slice/Grammar.cpp"
    break;

  case 148: /* enumerator: local_metadata ICE_IDENTIFIER  */
#line 1853 "src/Slice/Grammar.y"
>>>>>>> Regenerated compilers, and fixed build errors.
=======
#line 3731 "src/Slice/Grammar.cpp"
    break;

  case 148: /* enumerator: local_metadata ICE_IDENTIFIER  */
#line 1854 "src/Slice/Grammar.y"
>>>>>>> Added support for type-alias metadata.
=======
#line 3811 "src/Slice/Grammar.cpp"
    break;

  case 148: /* enumerator: local_metadata ICE_IDENTIFIER  */
#line 1934 "src/Slice/Grammar.y"
>>>>>>> Added aliasing support into the parser.
=======
#line 3833 "src/Slice/Grammar.cpp"
    break;

  case 149: /* enumerator: local_metadata ICE_IDENTIFIER  */
#line 1946 "src/Slice/Grammar.y"
>>>>>>> Added better error handling logic to the parser.
=======
#line 3818 "src/Slice/Grammar.cpp"
    break;

  case 149: /* enumerator: local_metadata ICE_IDENTIFIER  */
#line 1945 "src/Slice/Grammar.y"
>>>>>>> More cosmetic changes.
=======
#line 3799 "src/Slice/Grammar.cpp"
    break;

  case 149: /* enumerator: local_metadata ICE_IDENTIFIER  */
#line 1926 "src/Slice/Grammar.y"
>>>>>>> Fixed review comments.
=======
#line 3794 "src/Slice/Grammar.cpp"
    break;

  case 149: /* enumerator: local_metadata ICE_IDENTIFIER  */
#line 1921 "src/Slice/Grammar.y"
>>>>>>> Fixed the tests.
=======
#line 3780 "src/Slice/Grammar.cpp"
    break;

  case 149: /* enumerator: local_metadata ICE_IDENTIFIER  */
#line 1907 "src/Slice/Grammar.y"
>>>>>>> Next batch of review fixes.
{
    StringListTokPtr metadata = StringListTokPtr::dynamicCast(yyvsp[-1]);
    StringTokPtr ident = StringTokPtr::dynamicCast(yyvsp[0]);

    EnumPtr cont = EnumPtr::dynamicCast(unit->currentContainer());
    EnumeratorPtr en = cont->createEnumerator(ident->v);

    if (en && !metadata->v.empty())
    {
        en->setMetadata(metadata->v);
    }
    yyval = en;
}
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
#line 3720 "src/Slice/Grammar.cpp"
    break;

  case 144: /* enumerator: local_metadata ICE_IDENTIFIER '=' enumerator_initializer  */
#line 1864 "src/Slice/Grammar.y"
=======
#line 3744 "src/Slice/Grammar.cpp"
    break;

  case 149: /* enumerator: local_metadata ICE_IDENTIFIER '=' enumerator_initializer  */
#line 1867 "src/Slice/Grammar.y"
>>>>>>> Regenerated compilers, and fixed build errors.
=======
#line 3749 "src/Slice/Grammar.cpp"
    break;

  case 149: /* enumerator: local_metadata ICE_IDENTIFIER '=' enumerator_initializer  */
#line 1868 "src/Slice/Grammar.y"
>>>>>>> Added support for type-alias metadata.
=======
#line 3829 "src/Slice/Grammar.cpp"
    break;

  case 149: /* enumerator: local_metadata ICE_IDENTIFIER '=' enumerator_initializer  */
#line 1948 "src/Slice/Grammar.y"
>>>>>>> Added aliasing support into the parser.
=======
#line 3851 "src/Slice/Grammar.cpp"
    break;

  case 150: /* enumerator: local_metadata ICE_IDENTIFIER '=' enumerator_initializer  */
#line 1960 "src/Slice/Grammar.y"
>>>>>>> Added better error handling logic to the parser.
=======
#line 3836 "src/Slice/Grammar.cpp"
    break;

  case 150: /* enumerator: local_metadata ICE_IDENTIFIER '=' enumerator_initializer  */
#line 1959 "src/Slice/Grammar.y"
>>>>>>> More cosmetic changes.
=======
#line 3817 "src/Slice/Grammar.cpp"
    break;

  case 150: /* enumerator: local_metadata ICE_IDENTIFIER '=' enumerator_initializer  */
#line 1940 "src/Slice/Grammar.y"
>>>>>>> Fixed review comments.
=======
#line 3812 "src/Slice/Grammar.cpp"
    break;

  case 150: /* enumerator: local_metadata ICE_IDENTIFIER '=' enumerator_initializer  */
#line 1935 "src/Slice/Grammar.y"
>>>>>>> Fixed the tests.
=======
#line 3798 "src/Slice/Grammar.cpp"
    break;

  case 150: /* enumerator: local_metadata ICE_IDENTIFIER '=' enumerator_initializer  */
#line 1921 "src/Slice/Grammar.y"
>>>>>>> Next batch of review fixes.
{
    StringListTokPtr metadata = StringListTokPtr::dynamicCast(yyvsp[-3]);
    StringTokPtr ident = StringTokPtr::dynamicCast(yyvsp[-2]);
    IntegerTokPtr intVal = IntegerTokPtr::dynamicCast(yyvsp[0]);

    EnumPtr cont = EnumPtr::dynamicCast(unit->currentContainer());
    EnumeratorPtr en = cont->createEnumerator(ident->v, intVal->v);

    if (en && !metadata->v.empty())
    {
        en->setMetadata(metadata->v);
    }
    yyval = en;
}
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
#line 3739 "src/Slice/Grammar.cpp"
    break;

  case 145: /* enumerator: local_metadata keyword  */
#line 1879 "src/Slice/Grammar.y"
=======
#line 3763 "src/Slice/Grammar.cpp"
    break;

  case 150: /* enumerator: local_metadata keyword  */
#line 1882 "src/Slice/Grammar.y"
>>>>>>> Regenerated compilers, and fixed build errors.
=======
#line 3768 "src/Slice/Grammar.cpp"
    break;

  case 150: /* enumerator: local_metadata keyword  */
#line 1883 "src/Slice/Grammar.y"
>>>>>>> Added support for type-alias metadata.
=======
#line 3848 "src/Slice/Grammar.cpp"
    break;

  case 150: /* enumerator: local_metadata keyword  */
#line 1963 "src/Slice/Grammar.y"
>>>>>>> Added aliasing support into the parser.
=======
#line 3870 "src/Slice/Grammar.cpp"
    break;

  case 151: /* enumerator: local_metadata keyword  */
#line 1975 "src/Slice/Grammar.y"
>>>>>>> Added better error handling logic to the parser.
=======
#line 3855 "src/Slice/Grammar.cpp"
    break;

  case 151: /* enumerator: local_metadata keyword  */
#line 1974 "src/Slice/Grammar.y"
>>>>>>> More cosmetic changes.
=======
#line 3836 "src/Slice/Grammar.cpp"
    break;

  case 151: /* enumerator: local_metadata keyword  */
#line 1955 "src/Slice/Grammar.y"
>>>>>>> Fixed review comments.
=======
#line 3831 "src/Slice/Grammar.cpp"
    break;

  case 151: /* enumerator: local_metadata keyword  */
#line 1950 "src/Slice/Grammar.y"
>>>>>>> Fixed the tests.
=======
#line 3817 "src/Slice/Grammar.cpp"
    break;

  case 151: /* enumerator: local_metadata keyword  */
#line 1936 "src/Slice/Grammar.y"
>>>>>>> Next batch of review fixes.
{
    StringListTokPtr metadata = StringListTokPtr::dynamicCast(yyvsp[-1]);
    StringTokPtr ident = StringTokPtr::dynamicCast(yyvsp[0]);
    unit->error("keyword `" + ident->v + "' cannot be used as enumerator");

    EnumPtr cont = EnumPtr::dynamicCast(unit->currentContainer());
    EnumeratorPtr en = cont->createEnumerator(ident->v);

    if (en && !metadata->v.empty())
    {
        en->setMetadata(metadata->v);
    }
    yyval = en;
}
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
#line 3758 "src/Slice/Grammar.cpp"
    break;

  case 146: /* enumerator_initializer: ICE_INTEGER_LITERAL  */
#line 1899 "src/Slice/Grammar.y"
{
    yyval = yyvsp[0];
}
#line 3766 "src/Slice/Grammar.cpp"
    break;

  case 147: /* enumerator_initializer: scoped_name  */
#line 1903 "src/Slice/Grammar.y"
=======
#line 3782 "src/Slice/Grammar.cpp"
=======
#line 3787 "src/Slice/Grammar.cpp"
>>>>>>> Added support for type-alias metadata.
=======
#line 3867 "src/Slice/Grammar.cpp"
>>>>>>> Added aliasing support into the parser.
=======
#line 3889 "src/Slice/Grammar.cpp"
>>>>>>> Added better error handling logic to the parser.
=======
#line 3874 "src/Slice/Grammar.cpp"
>>>>>>> More cosmetic changes.
=======
#line 3855 "src/Slice/Grammar.cpp"
>>>>>>> Fixed review comments.
=======
#line 3850 "src/Slice/Grammar.cpp"
>>>>>>> Fixed the tests.
=======
#line 3836 "src/Slice/Grammar.cpp"
>>>>>>> Next batch of review fixes.
    break;

  case 152: /* enumerator_initializer: ICE_INTEGER_LITERAL  */
#line 1956 "src/Slice/Grammar.y"
{
    yyval = yyvsp[0];
}
#line 3844 "src/Slice/Grammar.cpp"
    break;

<<<<<<< HEAD
  case 152: /* enumerator_initializer: scoped_name  */
<<<<<<< HEAD
<<<<<<< HEAD
#line 1906 "src/Slice/Grammar.y"
>>>>>>> Regenerated compilers, and fixed build errors.
=======
#line 1907 "src/Slice/Grammar.y"
>>>>>>> Added support for type-alias metadata.
=======
#line 1987 "src/Slice/Grammar.y"
>>>>>>> Added aliasing support into the parser.
=======
  case 153: /* enumerator_initializer: scoped_name  */
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
#line 1999 "src/Slice/Grammar.y"
>>>>>>> Added better error handling logic to the parser.
=======
#line 1998 "src/Slice/Grammar.y"
>>>>>>> More cosmetic changes.
=======
#line 1979 "src/Slice/Grammar.y"
>>>>>>> Fixed review comments.
=======
#line 1974 "src/Slice/Grammar.y"
>>>>>>> Fixed the tests.
=======
#line 1960 "src/Slice/Grammar.y"
>>>>>>> Next batch of review fixes.
{
    StringTokPtr scoped = StringTokPtr::dynamicCast(yyvsp[0]);
    ContainedList cl = unit->currentContainer()->lookupContained(scoped->v);
    IntegerTokPtr tok;
    if(!cl.empty())
    {
        ConstPtr constant = ConstPtr::dynamicCast(cl.front());
        if(constant)
        {
            unit->currentContainer()->checkIntroduced(scoped->v, constant);
            BuiltinPtr b = BuiltinPtr::dynamicCast(constant->type());
            if(b && b->isIntegralType())
            {
                IceUtil::Int64 v;
                if(IceUtilInternal::stringToInt64(constant->value(), v))
                {
                    tok = new IntegerTok;
                    tok->v = v;
                    tok->literal = constant->value();
                }
            }
        }
    }

    if(!tok)
    {
        string msg = "illegal initializer: `" + scoped->v + "' is not an integer constant";
        unit->error(msg); // $$ is dummy
    }

    yyval = tok;
}
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
#line 3803 "src/Slice/Grammar.cpp"
    break;

  case 148: /* qualifier: ICE_OUT  */
#line 1941 "src/Slice/Grammar.y"
=======
#line 3827 "src/Slice/Grammar.cpp"
    break;

  case 153: /* out_qualifier: ICE_OUT  */
#line 1944 "src/Slice/Grammar.y"
>>>>>>> Regenerated compilers, and fixed build errors.
=======
#line 3832 "src/Slice/Grammar.cpp"
    break;

  case 153: /* out_qualifier: ICE_OUT  */
#line 1945 "src/Slice/Grammar.y"
>>>>>>> Added support for type-alias metadata.
=======
#line 3912 "src/Slice/Grammar.cpp"
    break;

  case 153: /* out_qualifier: ICE_OUT  */
#line 2025 "src/Slice/Grammar.y"
>>>>>>> Added aliasing support into the parser.
=======
#line 3934 "src/Slice/Grammar.cpp"
    break;

  case 154: /* out_qualifier: ICE_OUT  */
#line 2037 "src/Slice/Grammar.y"
>>>>>>> Added better error handling logic to the parser.
=======
#line 3919 "src/Slice/Grammar.cpp"
    break;

  case 154: /* out_qualifier: ICE_OUT  */
#line 2036 "src/Slice/Grammar.y"
>>>>>>> More cosmetic changes.
=======
#line 3900 "src/Slice/Grammar.cpp"
    break;

  case 154: /* out_qualifier: ICE_OUT  */
#line 2017 "src/Slice/Grammar.y"
>>>>>>> Fixed review comments.
=======
#line 3895 "src/Slice/Grammar.cpp"
    break;

  case 154: /* out_qualifier: ICE_OUT  */
#line 2012 "src/Slice/Grammar.y"
>>>>>>> Fixed the tests.
=======
#line 3881 "src/Slice/Grammar.cpp"
    break;

  case 154: /* out_qualifier: ICE_OUT  */
#line 1998 "src/Slice/Grammar.y"
>>>>>>> Next batch of review fixes.
{
    yyval = new IntegerTok(QUALIFIER_OUT);
}
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
#line 3811 "src/Slice/Grammar.cpp"
    break;

  case 149: /* qualifier: ICE_STREAM  */
#line 1945 "src/Slice/Grammar.y"
=======
#line 3835 "src/Slice/Grammar.cpp"
    break;

  case 154: /* out_qualifier: %empty  */
#line 1948 "src/Slice/Grammar.y"
>>>>>>> Regenerated compilers, and fixed build errors.
=======
#line 3840 "src/Slice/Grammar.cpp"
    break;

  case 154: /* out_qualifier: %empty  */
#line 1949 "src/Slice/Grammar.y"
>>>>>>> Added support for type-alias metadata.
=======
#line 3920 "src/Slice/Grammar.cpp"
    break;

  case 154: /* out_qualifier: %empty  */
#line 2029 "src/Slice/Grammar.y"
>>>>>>> Added aliasing support into the parser.
=======
#line 3942 "src/Slice/Grammar.cpp"
    break;

  case 155: /* out_qualifier: %empty  */
#line 2041 "src/Slice/Grammar.y"
>>>>>>> Added better error handling logic to the parser.
=======
#line 3927 "src/Slice/Grammar.cpp"
    break;

  case 155: /* out_qualifier: %empty  */
#line 2040 "src/Slice/Grammar.y"
>>>>>>> More cosmetic changes.
=======
#line 3908 "src/Slice/Grammar.cpp"
    break;

  case 155: /* out_qualifier: %empty  */
#line 2021 "src/Slice/Grammar.y"
>>>>>>> Fixed review comments.
=======
#line 3903 "src/Slice/Grammar.cpp"
    break;

  case 155: /* out_qualifier: %empty  */
#line 2016 "src/Slice/Grammar.y"
>>>>>>> Fixed the tests.
=======
#line 3889 "src/Slice/Grammar.cpp"
    break;

  case 155: /* out_qualifier: %empty  */
#line 2002 "src/Slice/Grammar.y"
>>>>>>> Next batch of review fixes.
{
    yyval = new IntegerTok(QUALIFIER_STREAM);
}
<<<<<<< HEAD
<<<<<<< HEAD
#line 3819 "src/Slice/Grammar.cpp"
    break;

  case 150: /* qualifier: ICE_STREAM ICE_OUT  */
#line 1949 "src/Slice/Grammar.y"
=======
#line 3843 "src/Slice/Grammar.cpp"
    break;

  case 155: /* parameter: out_qualifier member  */
#line 1957 "src/Slice/Grammar.y"
>>>>>>> Regenerated compilers, and fixed build errors.
{
    // Not allowed but we still allow the parsing to print an appropriate error message
    yyval = new IntegerTok(QUALIFIER_OUT | QUALIFIER_STREAM);
}
<<<<<<< HEAD
#line 3828 "src/Slice/Grammar.cpp"
    break;

  case 151: /* qualifier: ICE_OUT ICE_STREAM  */
#line 1954 "src/Slice/Grammar.y"
=======
#line 3848 "src/Slice/Grammar.cpp"
    break;

  case 155: /* parameter: out_qualifier member  */
#line 1958 "src/Slice/Grammar.y"
>>>>>>> Added support for type-alias metadata.
{
    // Not allowed but we still allow the parsing to print an appropriate error message
    yyval = new IntegerTok(QUALIFIER_OUT | QUALIFIER_STREAM);
}
<<<<<<< HEAD
<<<<<<< HEAD
#line 3837 "src/Slice/Grammar.cpp"
    break;

  case 152: /* qualifier: %empty  */
#line 1959 "src/Slice/Grammar.y"
{
    yyval = new IntegerTok(QUALIFIER_NONE);
}
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
#line 3845 "src/Slice/Grammar.cpp"
    break;

  case 153: /* parameter: qualifier member  */
#line 1968 "src/Slice/Grammar.y"
=======
#line 3928 "src/Slice/Grammar.cpp"
    break;

  case 155: /* parameter: out_qualifier member  */
#line 2038 "src/Slice/Grammar.y"
>>>>>>> Added aliasing support into the parser.
=======
#line 3950 "src/Slice/Grammar.cpp"
    break;

  case 156: /* parameter: out_qualifier member  */
#line 2050 "src/Slice/Grammar.y"
>>>>>>> Added better error handling logic to the parser.
=======
#line 3935 "src/Slice/Grammar.cpp"
    break;

  case 156: /* parameter: out_qualifier member  */
#line 2049 "src/Slice/Grammar.y"
>>>>>>> More cosmetic changes.
=======
#line 3916 "src/Slice/Grammar.cpp"
    break;

  case 156: /* parameter: out_qualifier member  */
#line 2030 "src/Slice/Grammar.y"
>>>>>>> Fixed review comments.
=======
#line 3911 "src/Slice/Grammar.cpp"
    break;

  case 156: /* parameter: out_qualifier member  */
#line 2025 "src/Slice/Grammar.y"
>>>>>>> Fixed the tests.
=======
#line 3897 "src/Slice/Grammar.cpp"
    break;

  case 156: /* parameter: out_qualifier member  */
#line 2011 "src/Slice/Grammar.y"
>>>>>>> Next batch of review fixes.
{
    IntegerTokPtr qualifier = IntegerTokPtr::dynamicCast(yyvsp[-1]);
    TaggedDefTokPtr def = TaggedDefTokPtr::dynamicCast(yyvsp[0]);

    if (OperationPtr op = OperationPtr::dynamicCast(unit->currentContainer()))
    {
        bool isOutParam = qualifier->v & QUALIFIER_OUT;
        bool isStreamParam = qualifier->v & QUALIFIER_STREAM;
        if (isOutParam && isStreamParam)
        {
            unit->error("`" + def->name + "': stream parameter cannot be marked as out");
        }

        MemberPtr param = op->createParameter(def->name, def->type, isOutParam, def->isTagged, def->tag, isStreamParam);
        unit->currentContainer()->checkIntroduced(def->name, param);
        if(param && !def->metadata.empty())
        {
            param->setMetadata(def->metadata);
        }
    }
}
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
#line 3871 "src/Slice/Grammar.cpp"
    break;

  case 158: /* throws: ICE_THROWS exception_list  */
#line 2008 "src/Slice/Grammar.y"
{
    yyval = yyvsp[0];
}
#line 3879 "src/Slice/Grammar.cpp"
    break;

  case 159: /* throws: %empty  */
#line 2012 "src/Slice/Grammar.y"
{
    yyval = new ExceptionListTok;
}
#line 3887 "src/Slice/Grammar.cpp"
    break;

  case 163: /* unscoped_name: ICE_SCOPED_IDENTIFIER  */
#line 2029 "src/Slice/Grammar.y"
=======
#line 3862 "src/Slice/Grammar.cpp"
=======
#line 3867 "src/Slice/Grammar.cpp"
>>>>>>> Added support for type-alias metadata.
=======
#line 3947 "src/Slice/Grammar.cpp"
>>>>>>> Added aliasing support into the parser.
=======
#line 3969 "src/Slice/Grammar.cpp"
>>>>>>> Added better error handling logic to the parser.
=======
#line 3954 "src/Slice/Grammar.cpp"
>>>>>>> More cosmetic changes.
=======
#line 3935 "src/Slice/Grammar.cpp"
>>>>>>> Fixed review comments.
=======
#line 3930 "src/Slice/Grammar.cpp"
>>>>>>> Fixed the tests.
=======
#line 3916 "src/Slice/Grammar.cpp"
>>>>>>> Next batch of review fixes.
    break;

  case 161: /* throws: ICE_THROWS exception_list  */
#line 2044 "src/Slice/Grammar.y"
{
    yyval = yyvsp[0];
}
#line 3924 "src/Slice/Grammar.cpp"
    break;

  case 162: /* throws: %empty  */
#line 2048 "src/Slice/Grammar.y"
{
    yyval = new ExceptionListTok;
}
#line 3932 "src/Slice/Grammar.cpp"
    break;

<<<<<<< HEAD
  case 165: /* unscoped_name: ICE_SCOPED_IDENTIFIER  */
<<<<<<< HEAD
<<<<<<< HEAD
#line 2011 "src/Slice/Grammar.y"
>>>>>>> Regenerated compilers, and fixed build errors.
=======
#line 2012 "src/Slice/Grammar.y"
>>>>>>> Added support for type-alias metadata.
=======
#line 2092 "src/Slice/Grammar.y"
>>>>>>> Added aliasing support into the parser.
=======
  case 166: /* unscoped_name: ICE_SCOPED_IDENTIFIER  */
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
#line 2104 "src/Slice/Grammar.y"
>>>>>>> Added better error handling logic to the parser.
=======
#line 2103 "src/Slice/Grammar.y"
>>>>>>> More cosmetic changes.
=======
#line 2084 "src/Slice/Grammar.y"
>>>>>>> Fixed review comments.
=======
#line 2079 "src/Slice/Grammar.y"
>>>>>>> Fixed the tests.
=======
#line 2065 "src/Slice/Grammar.y"
>>>>>>> Next batch of review fixes.
{
    StringTokPtr ident = StringTokPtr::dynamicCast(yyvsp[0]);
    unit->error("Identifier cannot be scoped: `" + (ident->v) + "'");
    yyval = yyvsp[0];
}
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
#line 3897 "src/Slice/Grammar.cpp"
    break;

  case 164: /* builtin: ICE_BOOL  */
#line 2039 "src/Slice/Grammar.y"
           {}
#line 3903 "src/Slice/Grammar.cpp"
    break;

  case 165: /* builtin: ICE_BYTE  */
#line 2040 "src/Slice/Grammar.y"
           {}
#line 3909 "src/Slice/Grammar.cpp"
    break;

  case 166: /* builtin: ICE_SHORT  */
#line 2041 "src/Slice/Grammar.y"
            {}
#line 3915 "src/Slice/Grammar.cpp"
    break;

  case 167: /* builtin: ICE_USHORT  */
#line 2042 "src/Slice/Grammar.y"
             {}
#line 3921 "src/Slice/Grammar.cpp"
    break;

  case 168: /* builtin: ICE_INT  */
#line 2043 "src/Slice/Grammar.y"
          {}
#line 3927 "src/Slice/Grammar.cpp"
    break;

  case 169: /* builtin: ICE_UINT  */
#line 2044 "src/Slice/Grammar.y"
           {}
#line 3933 "src/Slice/Grammar.cpp"
    break;

  case 170: /* builtin: ICE_VARINT  */
#line 2045 "src/Slice/Grammar.y"
             {}
#line 3939 "src/Slice/Grammar.cpp"
    break;

  case 171: /* builtin: ICE_VARUINT  */
#line 2046 "src/Slice/Grammar.y"
              {}
#line 3945 "src/Slice/Grammar.cpp"
    break;

  case 172: /* builtin: ICE_LONG  */
#line 2047 "src/Slice/Grammar.y"
           {}
#line 3951 "src/Slice/Grammar.cpp"
    break;

  case 173: /* builtin: ICE_ULONG  */
#line 2048 "src/Slice/Grammar.y"
            {}
#line 3957 "src/Slice/Grammar.cpp"
    break;

  case 174: /* builtin: ICE_VARLONG  */
#line 2049 "src/Slice/Grammar.y"
              {}
#line 3963 "src/Slice/Grammar.cpp"
    break;

  case 175: /* builtin: ICE_VARULONG  */
#line 2050 "src/Slice/Grammar.y"
               {}
#line 3969 "src/Slice/Grammar.cpp"
    break;

  case 176: /* builtin: ICE_FLOAT  */
#line 2051 "src/Slice/Grammar.y"
            {}
#line 3975 "src/Slice/Grammar.cpp"
    break;

  case 177: /* builtin: ICE_DOUBLE  */
#line 2052 "src/Slice/Grammar.y"
             {}
#line 3981 "src/Slice/Grammar.cpp"
    break;

  case 178: /* builtin: ICE_STRING  */
#line 2053 "src/Slice/Grammar.y"
             {}
#line 3987 "src/Slice/Grammar.cpp"
    break;

  case 179: /* type: ICE_OBJECT '*'  */
#line 2059 "src/Slice/Grammar.y"
{
    yyval = unit->optionalBuiltin(Builtin::KindObject);
}
#line 3995 "src/Slice/Grammar.cpp"
    break;

  case 180: /* type: ICE_OBJECT '?'  */
#line 2063 "src/Slice/Grammar.y"
{
    yyval = unit->optionalBuiltin(Builtin::KindObject);
}
#line 4003 "src/Slice/Grammar.cpp"
    break;

  case 181: /* type: ICE_ANYCLASS '?'  */
#line 2067 "src/Slice/Grammar.y"
{
    yyval = unit->optionalBuiltin(Builtin::KindAnyClass);
}
#line 4011 "src/Slice/Grammar.cpp"
    break;

  case 182: /* type: ICE_VALUE '?'  */
#line 2071 "src/Slice/Grammar.y"
=======
#line 3888 "src/Slice/Grammar.cpp"
=======
#line 3893 "src/Slice/Grammar.cpp"
>>>>>>> Added support for type-alias metadata.
=======
#line 3973 "src/Slice/Grammar.cpp"
>>>>>>> Added aliasing support into the parser.
=======
#line 3995 "src/Slice/Grammar.cpp"
>>>>>>> Added better error handling logic to the parser.
=======
#line 3980 "src/Slice/Grammar.cpp"
>>>>>>> More cosmetic changes.
=======
#line 3961 "src/Slice/Grammar.cpp"
>>>>>>> Fixed review comments.
=======
#line 3956 "src/Slice/Grammar.cpp"
>>>>>>> Fixed the tests.
=======
#line 3942 "src/Slice/Grammar.cpp"
>>>>>>> Next batch of review fixes.
    break;

  case 167: /* builtin: ICE_BOOL  */
#line 2075 "src/Slice/Grammar.y"
           {}
#line 3948 "src/Slice/Grammar.cpp"
    break;

  case 168: /* builtin: ICE_BYTE  */
#line 2076 "src/Slice/Grammar.y"
           {}
#line 3954 "src/Slice/Grammar.cpp"
    break;

  case 169: /* builtin: ICE_SHORT  */
#line 2077 "src/Slice/Grammar.y"
            {}
#line 3960 "src/Slice/Grammar.cpp"
    break;

  case 170: /* builtin: ICE_USHORT  */
#line 2078 "src/Slice/Grammar.y"
             {}
#line 3966 "src/Slice/Grammar.cpp"
    break;

  case 171: /* builtin: ICE_INT  */
#line 2079 "src/Slice/Grammar.y"
          {}
#line 3972 "src/Slice/Grammar.cpp"
    break;

  case 172: /* builtin: ICE_UINT  */
#line 2080 "src/Slice/Grammar.y"
           {}
#line 3978 "src/Slice/Grammar.cpp"
    break;

  case 173: /* builtin: ICE_VARINT  */
#line 2081 "src/Slice/Grammar.y"
             {}
#line 3984 "src/Slice/Grammar.cpp"
    break;

  case 174: /* builtin: ICE_VARUINT  */
#line 2082 "src/Slice/Grammar.y"
              {}
#line 3990 "src/Slice/Grammar.cpp"
    break;

  case 175: /* builtin: ICE_LONG  */
#line 2083 "src/Slice/Grammar.y"
           {}
#line 3996 "src/Slice/Grammar.cpp"
    break;

  case 176: /* builtin: ICE_ULONG  */
#line 2084 "src/Slice/Grammar.y"
            {}
#line 4002 "src/Slice/Grammar.cpp"
    break;

  case 177: /* builtin: ICE_VARLONG  */
#line 2085 "src/Slice/Grammar.y"
              {}
#line 4008 "src/Slice/Grammar.cpp"
    break;

  case 178: /* builtin: ICE_VARULONG  */
#line 2086 "src/Slice/Grammar.y"
               {}
#line 4014 "src/Slice/Grammar.cpp"
    break;

  case 179: /* builtin: ICE_FLOAT  */
#line 2087 "src/Slice/Grammar.y"
            {}
#line 4020 "src/Slice/Grammar.cpp"
    break;

  case 180: /* builtin: ICE_DOUBLE  */
#line 2088 "src/Slice/Grammar.y"
             {}
#line 4026 "src/Slice/Grammar.cpp"
    break;

  case 181: /* builtin: ICE_STRING  */
#line 2089 "src/Slice/Grammar.y"
             {}
#line 4032 "src/Slice/Grammar.cpp"
    break;

  case 182: /* type: ICE_OBJECT '*'  */
#line 2095 "src/Slice/Grammar.y"
{
    yyval = unit->optionalBuiltin(Builtin::KindObject);
}
#line 4040 "src/Slice/Grammar.cpp"
    break;

  case 183: /* type: ICE_OBJECT '?'  */
#line 2099 "src/Slice/Grammar.y"
{
    yyval = unit->optionalBuiltin(Builtin::KindObject);
}
#line 4048 "src/Slice/Grammar.cpp"
    break;

  case 184: /* type: ICE_ANYCLASS '?'  */
#line 2103 "src/Slice/Grammar.y"
{
    yyval = unit->optionalBuiltin(Builtin::KindAnyClass);
}
#line 4056 "src/Slice/Grammar.cpp"
    break;

<<<<<<< HEAD
  case 184: /* type: ICE_VALUE '?'  */
<<<<<<< HEAD
<<<<<<< HEAD
#line 2053 "src/Slice/Grammar.y"
>>>>>>> Regenerated compilers, and fixed build errors.
=======
#line 2054 "src/Slice/Grammar.y"
>>>>>>> Added support for type-alias metadata.
=======
#line 2134 "src/Slice/Grammar.y"
>>>>>>> Added aliasing support into the parser.
=======
  case 185: /* type: ICE_VALUE '?'  */
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
#line 2146 "src/Slice/Grammar.y"
>>>>>>> Added better error handling logic to the parser.
=======
#line 2145 "src/Slice/Grammar.y"
>>>>>>> More cosmetic changes.
=======
#line 2126 "src/Slice/Grammar.y"
>>>>>>> Fixed review comments.
=======
#line 2121 "src/Slice/Grammar.y"
>>>>>>> Fixed the tests.
=======
#line 2107 "src/Slice/Grammar.y"
>>>>>>> Next batch of review fixes.
{
    if (!unit->compatMode())
    {
        unit->warning(Deprecated, "the `Value' keyword is deprecated, use `AnyClass' instead");
    }
    yyval = unit->optionalBuiltin(Builtin::KindAnyClass);
}
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
#line 4023 "src/Slice/Grammar.cpp"
    break;

  case 183: /* type: builtin '?'  */
#line 2079 "src/Slice/Grammar.y"
=======
#line 4014 "src/Slice/Grammar.cpp"
    break;

  case 185: /* type: builtin '?'  */
#line 2061 "src/Slice/Grammar.y"
>>>>>>> Regenerated compilers, and fixed build errors.
=======
#line 4019 "src/Slice/Grammar.cpp"
    break;

  case 185: /* type: builtin '?'  */
#line 2062 "src/Slice/Grammar.y"
>>>>>>> Added support for type-alias metadata.
=======
#line 4099 "src/Slice/Grammar.cpp"
    break;

  case 185: /* type: builtin '?'  */
#line 2142 "src/Slice/Grammar.y"
>>>>>>> Added aliasing support into the parser.
=======
#line 4121 "src/Slice/Grammar.cpp"
    break;

  case 186: /* type: builtin '?'  */
#line 2154 "src/Slice/Grammar.y"
>>>>>>> Added better error handling logic to the parser.
=======
#line 4106 "src/Slice/Grammar.cpp"
    break;

  case 186: /* type: builtin '?'  */
#line 2153 "src/Slice/Grammar.y"
>>>>>>> More cosmetic changes.
=======
#line 4087 "src/Slice/Grammar.cpp"
    break;

  case 186: /* type: builtin '?'  */
#line 2134 "src/Slice/Grammar.y"
>>>>>>> Fixed review comments.
=======
#line 4082 "src/Slice/Grammar.cpp"
    break;

  case 186: /* type: builtin '?'  */
#line 2129 "src/Slice/Grammar.y"
>>>>>>> Fixed the tests.
=======
#line 4068 "src/Slice/Grammar.cpp"
    break;

  case 186: /* type: builtin '?'  */
#line 2115 "src/Slice/Grammar.y"
>>>>>>> Next batch of review fixes.
{
    StringTokPtr typeName = StringTokPtr::dynamicCast(yyvsp[-1]);
    yyval = unit->optionalBuiltin(Builtin::kindFromString(typeName->v).value());
}
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
#line 4032 "src/Slice/Grammar.cpp"
    break;

  case 184: /* type: ICE_OBJECT  */
#line 2084 "src/Slice/Grammar.y"
=======
#line 4023 "src/Slice/Grammar.cpp"
    break;

  case 186: /* type: ICE_OBJECT  */
#line 2066 "src/Slice/Grammar.y"
>>>>>>> Regenerated compilers, and fixed build errors.
=======
#line 4028 "src/Slice/Grammar.cpp"
    break;

  case 186: /* type: ICE_OBJECT  */
#line 2067 "src/Slice/Grammar.y"
>>>>>>> Added support for type-alias metadata.
=======
#line 4108 "src/Slice/Grammar.cpp"
    break;

  case 186: /* type: ICE_OBJECT  */
#line 2147 "src/Slice/Grammar.y"
>>>>>>> Added aliasing support into the parser.
=======
#line 4130 "src/Slice/Grammar.cpp"
    break;

  case 187: /* type: ICE_OBJECT  */
#line 2159 "src/Slice/Grammar.y"
>>>>>>> Added better error handling logic to the parser.
=======
#line 4115 "src/Slice/Grammar.cpp"
    break;

  case 187: /* type: ICE_OBJECT  */
#line 2158 "src/Slice/Grammar.y"
>>>>>>> More cosmetic changes.
=======
#line 4096 "src/Slice/Grammar.cpp"
    break;

  case 187: /* type: ICE_OBJECT  */
#line 2139 "src/Slice/Grammar.y"
>>>>>>> Fixed review comments.
=======
#line 4091 "src/Slice/Grammar.cpp"
    break;

  case 187: /* type: ICE_OBJECT  */
#line 2134 "src/Slice/Grammar.y"
>>>>>>> Fixed the tests.
{
    if (unit->compatMode())
    {
        yyval = unit->optionalBuiltin(Builtin::KindAnyClass);
    }
    else
    {
        yyval = unit->builtin(Builtin::KindObject);
    }
}
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
#line 4047 "src/Slice/Grammar.cpp"
    break;

  case 185: /* type: ICE_ANYCLASS  */
#line 2095 "src/Slice/Grammar.y"
{
    yyval = unit->builtin(Builtin::KindAnyClass);
}
#line 4055 "src/Slice/Grammar.cpp"
    break;

  case 186: /* type: ICE_VALUE  */
#line 2099 "src/Slice/Grammar.y"
=======
#line 4038 "src/Slice/Grammar.cpp"
=======
#line 4043 "src/Slice/Grammar.cpp"
>>>>>>> Added support for type-alias metadata.
=======
#line 4123 "src/Slice/Grammar.cpp"
>>>>>>> Added aliasing support into the parser.
=======
#line 4145 "src/Slice/Grammar.cpp"
>>>>>>> Added better error handling logic to the parser.
=======
#line 4130 "src/Slice/Grammar.cpp"
>>>>>>> More cosmetic changes.
=======
#line 4111 "src/Slice/Grammar.cpp"
>>>>>>> Fixed review comments.
=======
#line 4106 "src/Slice/Grammar.cpp"
>>>>>>> Fixed the tests.
    break;

  case 188: /* type: ICE_ANYCLASS  */
#line 2145 "src/Slice/Grammar.y"
=======
#line 4077 "src/Slice/Grammar.cpp"
    break;

  case 187: /* type: ICE_OBJECT  */
#line 2120 "src/Slice/Grammar.y"
{
    if (unit->compatMode())
    {
        yyval = unit->optionalBuiltin(Builtin::KindAnyClass);
    }
    else
    {
        yyval = unit->builtin(Builtin::KindObject);
    }
}
#line 4092 "src/Slice/Grammar.cpp"
    break;

  case 188: /* type: ICE_ANYCLASS  */
#line 2131 "src/Slice/Grammar.y"
>>>>>>> Next batch of review fixes.
{
    yyval = unit->builtin(Builtin::KindAnyClass);
}
#line 4100 "src/Slice/Grammar.cpp"
    break;

<<<<<<< HEAD
  case 188: /* type: ICE_VALUE  */
<<<<<<< HEAD
<<<<<<< HEAD
#line 2081 "src/Slice/Grammar.y"
>>>>>>> Regenerated compilers, and fixed build errors.
=======
#line 2082 "src/Slice/Grammar.y"
>>>>>>> Added support for type-alias metadata.
=======
#line 2162 "src/Slice/Grammar.y"
>>>>>>> Added aliasing support into the parser.
=======
  case 189: /* type: ICE_VALUE  */
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
#line 2174 "src/Slice/Grammar.y"
>>>>>>> Added better error handling logic to the parser.
=======
#line 2173 "src/Slice/Grammar.y"
>>>>>>> More cosmetic changes.
=======
#line 2154 "src/Slice/Grammar.y"
>>>>>>> Fixed review comments.
=======
#line 2149 "src/Slice/Grammar.y"
>>>>>>> Fixed the tests.
=======
#line 2135 "src/Slice/Grammar.y"
>>>>>>> Next batch of review fixes.
{
    if (unit->compatMode())
    {
        yyval = unit->optionalBuiltin(Builtin::KindAnyClass);
    }
    else
    {
        unit->warning(Deprecated, "the `Value' keyword is deprecated, use `AnyClass' instead");
        yyval = unit->builtin(Builtin::KindAnyClass);
    }
}
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
#line 4071 "src/Slice/Grammar.cpp"
    break;

  case 187: /* type: builtin  */
#line 2111 "src/Slice/Grammar.y"
=======
#line 4062 "src/Slice/Grammar.cpp"
    break;

  case 189: /* type: builtin  */
#line 2093 "src/Slice/Grammar.y"
>>>>>>> Regenerated compilers, and fixed build errors.
=======
#line 4067 "src/Slice/Grammar.cpp"
    break;

  case 189: /* type: builtin  */
#line 2094 "src/Slice/Grammar.y"
>>>>>>> Added support for type-alias metadata.
=======
#line 4147 "src/Slice/Grammar.cpp"
    break;

  case 189: /* type: builtin  */
#line 2174 "src/Slice/Grammar.y"
>>>>>>> Added aliasing support into the parser.
=======
#line 4169 "src/Slice/Grammar.cpp"
    break;

  case 190: /* type: builtin  */
#line 2186 "src/Slice/Grammar.y"
>>>>>>> Added better error handling logic to the parser.
=======
#line 4154 "src/Slice/Grammar.cpp"
    break;

  case 190: /* type: builtin  */
#line 2185 "src/Slice/Grammar.y"
>>>>>>> More cosmetic changes.
=======
#line 4135 "src/Slice/Grammar.cpp"
    break;

  case 190: /* type: builtin  */
#line 2166 "src/Slice/Grammar.y"
>>>>>>> Fixed review comments.
=======
#line 4130 "src/Slice/Grammar.cpp"
    break;

  case 190: /* type: builtin  */
#line 2161 "src/Slice/Grammar.y"
>>>>>>> Fixed the tests.
=======
#line 4116 "src/Slice/Grammar.cpp"
    break;

  case 190: /* type: builtin  */
#line 2147 "src/Slice/Grammar.y"
>>>>>>> Next batch of review fixes.
{
    StringTokPtr typeName = StringTokPtr::dynamicCast(yyvsp[0]);
    yyval = unit->builtin(Builtin::kindFromString(typeName->v).value());
}
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
#line 4080 "src/Slice/Grammar.cpp"
    break;

  case 188: /* type: scoped_name  */
#line 2116 "src/Slice/Grammar.y"
=======
#line 4071 "src/Slice/Grammar.cpp"
    break;

  case 190: /* type: scoped_name  */
#line 2098 "src/Slice/Grammar.y"
>>>>>>> Regenerated compilers, and fixed build errors.
=======
#line 4076 "src/Slice/Grammar.cpp"
    break;

  case 190: /* type: scoped_name  */
#line 2099 "src/Slice/Grammar.y"
>>>>>>> Added support for type-alias metadata.
=======
#line 4156 "src/Slice/Grammar.cpp"
    break;

  case 190: /* type: scoped_name  */
#line 2179 "src/Slice/Grammar.y"
>>>>>>> Added aliasing support into the parser.
=======
#line 4178 "src/Slice/Grammar.cpp"
    break;

  case 191: /* type: scoped_name  */
#line 2191 "src/Slice/Grammar.y"
>>>>>>> Added better error handling logic to the parser.
=======
#line 4163 "src/Slice/Grammar.cpp"
    break;

  case 191: /* type: scoped_name  */
#line 2190 "src/Slice/Grammar.y"
>>>>>>> More cosmetic changes.
=======
#line 4144 "src/Slice/Grammar.cpp"
    break;

  case 191: /* type: scoped_name  */
#line 2171 "src/Slice/Grammar.y"
>>>>>>> Fixed review comments.
=======
#line 4139 "src/Slice/Grammar.cpp"
    break;

  case 191: /* type: scoped_name  */
#line 2166 "src/Slice/Grammar.y"
>>>>>>> Fixed the tests.
=======
#line 4125 "src/Slice/Grammar.cpp"
    break;

  case 191: /* type: scoped_name  */
#line 2152 "src/Slice/Grammar.y"
>>>>>>> Next batch of review fixes.
{
    StringTokPtr scoped = StringTokPtr::dynamicCast(yyvsp[0]);
    ContainerPtr cont = unit->currentContainer();
    if(cont)
    {
        TypeList types = cont->lookupType(scoped->v);
        if(types.empty())
        {
            YYERROR; // Can't continue, jump to next yyerrok
        }
        cont->checkIntroduced(scoped->v);
        if (ClassDeclPtr::dynamicCast(types.front()) && unit->compatMode())
        {
            yyval = new Optional(types.front());
        }
        else
        {
            yyval = types.front();
        }
    }
    else
    {
        yyval = 0;
    }
}
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
#line 4110 "src/Slice/Grammar.cpp"
    break;

  case 189: /* type: scoped_name '*'  */
#line 2142 "src/Slice/Grammar.y"
=======
#line 4101 "src/Slice/Grammar.cpp"
    break;

  case 191: /* type: scoped_name '*'  */
#line 2124 "src/Slice/Grammar.y"
>>>>>>> Regenerated compilers, and fixed build errors.
=======
#line 4106 "src/Slice/Grammar.cpp"
    break;

  case 191: /* type: scoped_name '*'  */
#line 2125 "src/Slice/Grammar.y"
>>>>>>> Added support for type-alias metadata.
=======
#line 4186 "src/Slice/Grammar.cpp"
    break;

  case 191: /* type: scoped_name '*'  */
#line 2205 "src/Slice/Grammar.y"
>>>>>>> Added aliasing support into the parser.
=======
#line 4208 "src/Slice/Grammar.cpp"
    break;

  case 192: /* type: scoped_name '*'  */
#line 2217 "src/Slice/Grammar.y"
>>>>>>> Added better error handling logic to the parser.
=======
#line 4193 "src/Slice/Grammar.cpp"
    break;

  case 192: /* type: scoped_name '*'  */
#line 2216 "src/Slice/Grammar.y"
>>>>>>> More cosmetic changes.
=======
#line 4174 "src/Slice/Grammar.cpp"
    break;

  case 192: /* type: scoped_name '*'  */
#line 2197 "src/Slice/Grammar.y"
>>>>>>> Fixed review comments.
=======
#line 4169 "src/Slice/Grammar.cpp"
    break;

  case 192: /* type: scoped_name '*'  */
#line 2192 "src/Slice/Grammar.y"
>>>>>>> Fixed the tests.
=======
#line 4155 "src/Slice/Grammar.cpp"
    break;

  case 192: /* type: scoped_name '*'  */
#line 2178 "src/Slice/Grammar.y"
>>>>>>> Next batch of review fixes.
{
    StringTokPtr scoped = StringTokPtr::dynamicCast(yyvsp[-1]);
    ContainerPtr cont = unit->currentContainer();
    if(cont)
    {
        TypeList types = cont->lookupType(scoped->v);
        if(types.empty())
        {
            YYERROR; // Can't continue, jump to next yyerrok
        }
        for(TypeList::iterator p = types.begin(); p != types.end(); ++p)
        {
            InterfaceDeclPtr interface = InterfaceDeclPtr::dynamicCast(*p);
            if(!interface)
            {
                string msg = "`";
                msg += scoped->v;
                msg += "' must be an interface";
                unit->error(msg);
                YYERROR; // Can't continue, jump to next yyerrok
            }
            cont->checkIntroduced(scoped->v);
            *p = new Optional(interface);
        }
        yyval = types.front();
    }
    else
    {
        yyval = 0;
    }
}
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
#line 4146 "src/Slice/Grammar.cpp"
    break;

  case 190: /* type: scoped_name '?'  */
#line 2174 "src/Slice/Grammar.y"
=======
#line 4137 "src/Slice/Grammar.cpp"
    break;

  case 192: /* type: scoped_name '?'  */
#line 2156 "src/Slice/Grammar.y"
>>>>>>> Regenerated compilers, and fixed build errors.
=======
#line 4142 "src/Slice/Grammar.cpp"
    break;

  case 192: /* type: scoped_name '?'  */
#line 2157 "src/Slice/Grammar.y"
>>>>>>> Added support for type-alias metadata.
=======
#line 4222 "src/Slice/Grammar.cpp"
    break;

  case 192: /* type: scoped_name '?'  */
#line 2237 "src/Slice/Grammar.y"
>>>>>>> Added aliasing support into the parser.
=======
#line 4244 "src/Slice/Grammar.cpp"
    break;

  case 193: /* type: scoped_name '?'  */
#line 2249 "src/Slice/Grammar.y"
>>>>>>> Added better error handling logic to the parser.
=======
#line 4229 "src/Slice/Grammar.cpp"
    break;

  case 193: /* type: scoped_name '?'  */
#line 2248 "src/Slice/Grammar.y"
>>>>>>> More cosmetic changes.
=======
#line 4210 "src/Slice/Grammar.cpp"
    break;

  case 193: /* type: scoped_name '?'  */
#line 2229 "src/Slice/Grammar.y"
>>>>>>> Fixed review comments.
=======
#line 4205 "src/Slice/Grammar.cpp"
    break;

  case 193: /* type: scoped_name '?'  */
#line 2224 "src/Slice/Grammar.y"
>>>>>>> Fixed the tests.
=======
#line 4191 "src/Slice/Grammar.cpp"
    break;

  case 193: /* type: scoped_name '?'  */
#line 2210 "src/Slice/Grammar.y"
>>>>>>> Next batch of review fixes.
{
    StringTokPtr scoped = StringTokPtr::dynamicCast(yyvsp[-1]);
    ContainerPtr cont = unit->currentContainer();
    if(cont)
    {
        TypeList types = cont->lookupType(scoped->v);
        if(types.empty())
        {
            YYERROR; // Can't continue, jump to next yyerrok
        }
        cont->checkIntroduced(scoped->v);
        yyval = new Optional(types.front());
    }
    else
    {
        yyval = 0;
    }
}
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
#line 4173 "src/Slice/Grammar.cpp"
    break;

  case 191: /* tagged_type: tag type  */
#line 2202 "src/Slice/Grammar.y"
=======
#line 4164 "src/Slice/Grammar.cpp"
    break;

  case 193: /* tagged_type: tag type  */
#line 2184 "src/Slice/Grammar.y"
>>>>>>> Regenerated compilers, and fixed build errors.
=======
#line 4169 "src/Slice/Grammar.cpp"
    break;

  case 193: /* tagged_type: tag type  */
#line 2185 "src/Slice/Grammar.y"
>>>>>>> Added support for type-alias metadata.
=======
#line 4245 "src/Slice/Grammar.cpp"
    break;

  case 193: /* tagged_type: tag type  */
#line 2261 "src/Slice/Grammar.y"
>>>>>>> Added aliasing support into the parser.
=======
#line 4267 "src/Slice/Grammar.cpp"
    break;

  case 194: /* tagged_type: tag type  */
#line 2273 "src/Slice/Grammar.y"
>>>>>>> Added better error handling logic to the parser.
=======
#line 4252 "src/Slice/Grammar.cpp"
    break;

  case 194: /* tagged_type: tag type  */
#line 2272 "src/Slice/Grammar.y"
>>>>>>> More cosmetic changes.
=======
#line 4233 "src/Slice/Grammar.cpp"
    break;

  case 194: /* tagged_type: tag type  */
#line 2253 "src/Slice/Grammar.y"
>>>>>>> Fixed review comments.
=======
#line 4228 "src/Slice/Grammar.cpp"
    break;

  case 194: /* tagged_type: tag type  */
#line 2248 "src/Slice/Grammar.y"
>>>>>>> Fixed the tests.
=======
#line 4214 "src/Slice/Grammar.cpp"
    break;

  case 194: /* tagged_type: tag type  */
#line 2234 "src/Slice/Grammar.y"
>>>>>>> Next batch of review fixes.
{
    TaggedDefTokPtr taggedDef = TaggedDefTokPtr::dynamicCast(yyvsp[-1]);
    OptionalPtr type = OptionalPtr::dynamicCast(yyvsp[0]);

    if (!type)
    {
        // Infer the type to be optional so parsing can continue without nullptrs.
        type = new Optional(TypePtr::dynamicCast(yyvsp[0]));
        unit->error("only optional types can be tagged");
    }

    if (auto alias = TypeAliasPtr::dynamicCast(type->underlying()))
    {
        taggedDef->metadata = alias->typeMetadata();
        type = new Optional(alias->underlying());
    }

    taggedDef->type = type;
    yyval = taggedDef;
}
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
#line 4192 "src/Slice/Grammar.cpp"
    break;

  case 192: /* tagged_type: optional type  */
#line 2217 "src/Slice/Grammar.y"
=======
#line 4183 "src/Slice/Grammar.cpp"
    break;

  case 194: /* tagged_type: optional type  */
#line 2199 "src/Slice/Grammar.y"
>>>>>>> Regenerated compilers, and fixed build errors.
=======
#line 4188 "src/Slice/Grammar.cpp"
    break;

  case 194: /* tagged_type: optional type  */
#line 2200 "src/Slice/Grammar.y"
>>>>>>> Added support for type-alias metadata.
=======
#line 4270 "src/Slice/Grammar.cpp"
    break;

  case 194: /* tagged_type: optional type  */
#line 2282 "src/Slice/Grammar.y"
>>>>>>> Added aliasing support into the parser.
=======
#line 4292 "src/Slice/Grammar.cpp"
    break;

  case 195: /* tagged_type: optional type  */
#line 2294 "src/Slice/Grammar.y"
>>>>>>> Added better error handling logic to the parser.
=======
#line 4277 "src/Slice/Grammar.cpp"
    break;

  case 195: /* tagged_type: optional type  */
#line 2293 "src/Slice/Grammar.y"
>>>>>>> More cosmetic changes.
=======
#line 4258 "src/Slice/Grammar.cpp"
    break;

  case 195: /* tagged_type: optional type  */
#line 2274 "src/Slice/Grammar.y"
>>>>>>> Fixed review comments.
=======
#line 4253 "src/Slice/Grammar.cpp"
    break;

  case 195: /* tagged_type: optional type  */
#line 2269 "src/Slice/Grammar.y"
>>>>>>> Fixed the tests.
=======
#line 4239 "src/Slice/Grammar.cpp"
    break;

  case 195: /* tagged_type: optional type  */
#line 2255 "src/Slice/Grammar.y"
>>>>>>> Next batch of review fixes.
{
    TaggedDefTokPtr taggedDef = TaggedDefTokPtr::dynamicCast(yyvsp[-1]);
    OptionalPtr type = OptionalPtr::dynamicCast(yyvsp[0]);

    if (!type)
    {
        // Infer the type to be optional for backwards compatibility.
        type = new Optional(TypePtr::dynamicCast(yyvsp[0]));
    }

    if (auto alias = TypeAliasPtr::dynamicCast(type->underlying()))
    {
        taggedDef->metadata = alias->typeMetadata();
        type = new Optional(alias->underlying());
    }

    taggedDef->type = type;
    yyval = taggedDef;
}
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
#line 4210 "src/Slice/Grammar.cpp"
    break;

  case 193: /* tagged_type: type  */
#line 2231 "src/Slice/Grammar.y"
=======
#line 4201 "src/Slice/Grammar.cpp"
    break;

  case 195: /* tagged_type: type  */
#line 2213 "src/Slice/Grammar.y"
>>>>>>> Regenerated compilers, and fixed build errors.
=======
#line 4206 "src/Slice/Grammar.cpp"
    break;

  case 195: /* tagged_type: type  */
#line 2214 "src/Slice/Grammar.y"
>>>>>>> Added support for type-alias metadata.
=======
#line 4294 "src/Slice/Grammar.cpp"
    break;

  case 195: /* tagged_type: type  */
#line 2302 "src/Slice/Grammar.y"
>>>>>>> Added aliasing support into the parser.
=======
#line 4316 "src/Slice/Grammar.cpp"
    break;

  case 196: /* tagged_type: type  */
#line 2314 "src/Slice/Grammar.y"
>>>>>>> Added better error handling logic to the parser.
=======
#line 4301 "src/Slice/Grammar.cpp"
    break;

  case 196: /* tagged_type: type  */
#line 2313 "src/Slice/Grammar.y"
>>>>>>> More cosmetic changes.
=======
#line 4282 "src/Slice/Grammar.cpp"
    break;

  case 196: /* tagged_type: type  */
#line 2294 "src/Slice/Grammar.y"
>>>>>>> Fixed review comments.
=======
#line 4277 "src/Slice/Grammar.cpp"
    break;

  case 196: /* tagged_type: type  */
#line 2289 "src/Slice/Grammar.y"
>>>>>>> Fixed the tests.
=======
#line 4263 "src/Slice/Grammar.cpp"
    break;

  case 196: /* tagged_type: type  */
#line 2275 "src/Slice/Grammar.y"
>>>>>>> Next batch of review fixes.
{
    TaggedDefTokPtr taggedDef = new TaggedDefTok;
    taggedDef->type = TypePtr::dynamicCast(yyvsp[0]);

    unalias(taggedDef->type, taggedDef->metadata);

    yyval = taggedDef;
}
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
#line 4220 "src/Slice/Grammar.cpp"
    break;

  case 194: /* member: tagged_type ICE_IDENTIFIER  */
#line 2242 "src/Slice/Grammar.y"
=======
#line 4211 "src/Slice/Grammar.cpp"
    break;

  case 196: /* member: tagged_type ICE_IDENTIFIER  */
#line 2224 "src/Slice/Grammar.y"
>>>>>>> Regenerated compilers, and fixed build errors.
=======
#line 4216 "src/Slice/Grammar.cpp"
    break;

  case 196: /* member: tagged_type ICE_IDENTIFIER  */
#line 2225 "src/Slice/Grammar.y"
>>>>>>> Added support for type-alias metadata.
=======
#line 4312 "src/Slice/Grammar.cpp"
    break;

  case 196: /* member: tagged_type ICE_IDENTIFIER  */
#line 2321 "src/Slice/Grammar.y"
>>>>>>> Added aliasing support into the parser.
=======
#line 4334 "src/Slice/Grammar.cpp"
    break;

  case 197: /* member: tagged_type ICE_IDENTIFIER  */
#line 2333 "src/Slice/Grammar.y"
>>>>>>> Added better error handling logic to the parser.
=======
#line 4336 "src/Slice/Grammar.cpp"
    break;

  case 197: /* member: tagged_type ICE_IDENTIFIER  */
#line 2335 "src/Slice/Grammar.y"
>>>>>>> Cosmetic changes.
=======
#line 4321 "src/Slice/Grammar.cpp"
    break;

  case 197: /* member: tagged_type ICE_IDENTIFIER  */
#line 2334 "src/Slice/Grammar.y"
>>>>>>> More cosmetic changes.
=======
#line 4295 "src/Slice/Grammar.cpp"
    break;

  case 197: /* member: tagged_type ICE_IDENTIFIER  */
#line 2308 "src/Slice/Grammar.y"
>>>>>>> Fixed review comments.
=======
#line 4290 "src/Slice/Grammar.cpp"
    break;

  case 197: /* member: tagged_type ICE_IDENTIFIER  */
#line 2303 "src/Slice/Grammar.y"
>>>>>>> Fixed the tests.
=======
#line 4277 "src/Slice/Grammar.cpp"
    break;

  case 197: /* member: tagged_type ICE_IDENTIFIER  */
#line 2290 "src/Slice/Grammar.y"
>>>>>>> Next batch of review fixes.
=======
#line 4276 "src/Slice/Grammar.cpp"
    break;

  case 197: /* member: tagged_type ICE_IDENTIFIER  */
#line 2289 "src/Slice/Grammar.y"
>>>>>>> Missed some stuff I meant to git add.
{
    TaggedDefTokPtr def = TaggedDefTokPtr::dynamicCast(yyvsp[-1]);
    def->name = StringTokPtr::dynamicCast(yyvsp[0])->v;
    checkIdentifier(def->name);
    if (def->isTagged)
    {
        checkForTaggableType(def->type, def->name);
    }

    yyval = def;
}
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
#line 4236 "src/Slice/Grammar.cpp"
    break;

  case 195: /* member: tagged_type keyword  */
#line 2254 "src/Slice/Grammar.y"
=======
#line 4227 "src/Slice/Grammar.cpp"
    break;

  case 197: /* member: tagged_type keyword  */
#line 2236 "src/Slice/Grammar.y"
>>>>>>> Regenerated compilers, and fixed build errors.
=======
#line 4232 "src/Slice/Grammar.cpp"
    break;

  case 197: /* member: tagged_type keyword  */
#line 2237 "src/Slice/Grammar.y"
>>>>>>> Added support for type-alias metadata.
=======
#line 4328 "src/Slice/Grammar.cpp"
    break;

  case 197: /* member: tagged_type keyword  */
#line 2333 "src/Slice/Grammar.y"
>>>>>>> Added aliasing support into the parser.
=======
#line 4350 "src/Slice/Grammar.cpp"
    break;

  case 198: /* member: tagged_type keyword  */
#line 2345 "src/Slice/Grammar.y"
>>>>>>> Added better error handling logic to the parser.
=======
#line 4352 "src/Slice/Grammar.cpp"
    break;

  case 198: /* member: tagged_type keyword  */
#line 2347 "src/Slice/Grammar.y"
>>>>>>> Cosmetic changes.
=======
#line 4337 "src/Slice/Grammar.cpp"
    break;

  case 198: /* member: tagged_type keyword  */
#line 2346 "src/Slice/Grammar.y"
>>>>>>> More cosmetic changes.
=======
#line 4311 "src/Slice/Grammar.cpp"
    break;

  case 198: /* member: tagged_type keyword  */
#line 2320 "src/Slice/Grammar.y"
>>>>>>> Fixed review comments.
=======
#line 4306 "src/Slice/Grammar.cpp"
    break;

  case 198: /* member: tagged_type keyword  */
#line 2315 "src/Slice/Grammar.y"
>>>>>>> Fixed the tests.
=======
#line 4293 "src/Slice/Grammar.cpp"
    break;

  case 198: /* member: tagged_type keyword  */
#line 2302 "src/Slice/Grammar.y"
>>>>>>> Next batch of review fixes.
=======
#line 4292 "src/Slice/Grammar.cpp"
    break;

  case 198: /* member: tagged_type keyword  */
#line 2301 "src/Slice/Grammar.y"
>>>>>>> Missed some stuff I meant to git add.
{
    TaggedDefTokPtr def = TaggedDefTokPtr::dynamicCast(yyvsp[-1]);
    def->name = StringTokPtr::dynamicCast(yyvsp[0])->v;
    if (def->isTagged)
    {
        checkForTaggableType(def->type, def->name);
    }
    unit->error("keyword `" + def->name + "' cannot be used as an identifier");
    yyval = def;
}
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
#line 4251 "src/Slice/Grammar.cpp"
    break;

  case 196: /* member: tagged_type  */
#line 2265 "src/Slice/Grammar.y"
=======
#line 4242 "src/Slice/Grammar.cpp"
    break;

  case 198: /* member: tagged_type  */
#line 2247 "src/Slice/Grammar.y"
>>>>>>> Regenerated compilers, and fixed build errors.
=======
#line 4247 "src/Slice/Grammar.cpp"
    break;

  case 198: /* member: tagged_type  */
#line 2248 "src/Slice/Grammar.y"
>>>>>>> Added support for type-alias metadata.
=======
#line 4343 "src/Slice/Grammar.cpp"
    break;

  case 198: /* member: tagged_type  */
#line 2344 "src/Slice/Grammar.y"
>>>>>>> Added aliasing support into the parser.
=======
#line 4365 "src/Slice/Grammar.cpp"
    break;

  case 199: /* member: tagged_type  */
#line 2356 "src/Slice/Grammar.y"
>>>>>>> Added better error handling logic to the parser.
=======
#line 4367 "src/Slice/Grammar.cpp"
    break;

  case 199: /* member: tagged_type  */
#line 2358 "src/Slice/Grammar.y"
>>>>>>> Cosmetic changes.
=======
#line 4352 "src/Slice/Grammar.cpp"
    break;

  case 199: /* member: tagged_type  */
#line 2357 "src/Slice/Grammar.y"
>>>>>>> More cosmetic changes.
=======
#line 4326 "src/Slice/Grammar.cpp"
    break;

  case 199: /* member: tagged_type  */
#line 2331 "src/Slice/Grammar.y"
>>>>>>> Fixed review comments.
=======
#line 4321 "src/Slice/Grammar.cpp"
    break;

  case 199: /* member: tagged_type  */
#line 2326 "src/Slice/Grammar.y"
>>>>>>> Fixed the tests.
=======
#line 4308 "src/Slice/Grammar.cpp"
    break;

  case 199: /* member: tagged_type  */
#line 2313 "src/Slice/Grammar.y"
>>>>>>> Next batch of review fixes.
=======
#line 4307 "src/Slice/Grammar.cpp"
    break;

  case 199: /* member: tagged_type  */
#line 2312 "src/Slice/Grammar.y"
>>>>>>> Missed some stuff I meant to git add.
{
    TaggedDefTokPtr def = TaggedDefTokPtr::dynamicCast(yyvsp[0]);
    def->name = IceUtil::generateUUID(); // Dummy
    if (def->isTagged)
    {
        checkForTaggableType(def->type);
    }
    unit->error("missing identifier");
    yyval = def;
}
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
#line 4266 "src/Slice/Grammar.cpp"
    break;

  case 197: /* member: local_metadata member  */
#line 2276 "src/Slice/Grammar.y"
=======
#line 4257 "src/Slice/Grammar.cpp"
    break;

  case 199: /* member: local_metadata member  */
#line 2258 "src/Slice/Grammar.y"
>>>>>>> Regenerated compilers, and fixed build errors.
=======
#line 4262 "src/Slice/Grammar.cpp"
    break;

  case 199: /* member: local_metadata member  */
#line 2259 "src/Slice/Grammar.y"
>>>>>>> Added support for type-alias metadata.
=======
#line 4358 "src/Slice/Grammar.cpp"
    break;

  case 199: /* member: local_metadata member  */
#line 2355 "src/Slice/Grammar.y"
>>>>>>> Added aliasing support into the parser.
=======
#line 4380 "src/Slice/Grammar.cpp"
    break;

  case 200: /* member: local_metadata member  */
#line 2367 "src/Slice/Grammar.y"
>>>>>>> Added better error handling logic to the parser.
=======
#line 4382 "src/Slice/Grammar.cpp"
    break;

  case 200: /* member: local_metadata member  */
#line 2369 "src/Slice/Grammar.y"
>>>>>>> Cosmetic changes.
=======
#line 4367 "src/Slice/Grammar.cpp"
    break;

  case 200: /* member: local_metadata member  */
#line 2368 "src/Slice/Grammar.y"
>>>>>>> More cosmetic changes.
=======
#line 4341 "src/Slice/Grammar.cpp"
    break;

  case 200: /* member: local_metadata member  */
#line 2342 "src/Slice/Grammar.y"
>>>>>>> Fixed review comments.
=======
#line 4336 "src/Slice/Grammar.cpp"
    break;

  case 200: /* member: local_metadata member  */
#line 2337 "src/Slice/Grammar.y"
>>>>>>> Fixed the tests.
=======
#line 4323 "src/Slice/Grammar.cpp"
    break;

  case 200: /* member: local_metadata member  */
#line 2324 "src/Slice/Grammar.y"
>>>>>>> Next batch of review fixes.
=======
#line 4322 "src/Slice/Grammar.cpp"
    break;

  case 200: /* member: local_metadata member  */
#line 2323 "src/Slice/Grammar.y"
>>>>>>> Missed some stuff I meant to git add.
{
    StringListTokPtr metadata = StringListTokPtr::dynamicCast(yyvsp[-1]);
    TaggedDefTokPtr def = TaggedDefTokPtr::dynamicCast(yyvsp[0]);
    def->metadata = appendMetadata(metadata->v, def->metadata);
    yyval = def;
}
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
#line 4276 "src/Slice/Grammar.cpp"
    break;

  case 198: /* string_literal: ICE_STRING_LITERAL string_literal  */
#line 2287 "src/Slice/Grammar.y"
=======
#line 4267 "src/Slice/Grammar.cpp"
    break;

  case 200: /* string_literal: ICE_STRING_LITERAL string_literal  */
#line 2269 "src/Slice/Grammar.y"
>>>>>>> Regenerated compilers, and fixed build errors.
=======
#line 4272 "src/Slice/Grammar.cpp"
    break;

  case 200: /* string_literal: ICE_STRING_LITERAL string_literal  */
#line 2270 "src/Slice/Grammar.y"
>>>>>>> Added support for type-alias metadata.
=======
#line 4369 "src/Slice/Grammar.cpp"
    break;

  case 200: /* string_literal: ICE_STRING_LITERAL string_literal  */
#line 2367 "src/Slice/Grammar.y"
>>>>>>> Added aliasing support into the parser.
=======
#line 4391 "src/Slice/Grammar.cpp"
    break;

  case 201: /* string_literal: ICE_STRING_LITERAL string_literal  */
#line 2379 "src/Slice/Grammar.y"
>>>>>>> Added better error handling logic to the parser.
=======
#line 4393 "src/Slice/Grammar.cpp"
    break;

  case 201: /* string_literal: ICE_STRING_LITERAL string_literal  */
#line 2381 "src/Slice/Grammar.y"
>>>>>>> Cosmetic changes.
=======
#line 4378 "src/Slice/Grammar.cpp"
    break;

  case 201: /* string_literal: ICE_STRING_LITERAL string_literal  */
#line 2380 "src/Slice/Grammar.y"
>>>>>>> More cosmetic changes.
=======
#line 4352 "src/Slice/Grammar.cpp"
    break;

  case 201: /* string_literal: ICE_STRING_LITERAL string_literal  */
#line 2354 "src/Slice/Grammar.y"
>>>>>>> Fixed review comments.
=======
#line 4347 "src/Slice/Grammar.cpp"
    break;

  case 201: /* string_literal: ICE_STRING_LITERAL string_literal  */
#line 2349 "src/Slice/Grammar.y"
>>>>>>> Fixed the tests.
=======
#line 4334 "src/Slice/Grammar.cpp"
    break;

  case 201: /* string_literal: ICE_STRING_LITERAL string_literal  */
#line 2336 "src/Slice/Grammar.y"
>>>>>>> Next batch of review fixes.
=======
#line 4333 "src/Slice/Grammar.cpp"
    break;

  case 201: /* string_literal: ICE_STRING_LITERAL string_literal  */
#line 2335 "src/Slice/Grammar.y"
>>>>>>> Missed some stuff I meant to git add.
{
    StringTokPtr str1 = StringTokPtr::dynamicCast(yyvsp[-1]);
    StringTokPtr str2 = StringTokPtr::dynamicCast(yyvsp[0]);
    str1->v += str2->v;
}
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
#line 4286 "src/Slice/Grammar.cpp"
    break;

  case 200: /* string_list: string_list ',' string_literal  */
#line 2299 "src/Slice/Grammar.y"
=======
#line 4277 "src/Slice/Grammar.cpp"
    break;

  case 202: /* string_list: string_list ',' string_literal  */
#line 2281 "src/Slice/Grammar.y"
>>>>>>> Regenerated compilers, and fixed build errors.
=======
#line 4282 "src/Slice/Grammar.cpp"
    break;

  case 202: /* string_list: string_list ',' string_literal  */
#line 2282 "src/Slice/Grammar.y"
>>>>>>> Added support for type-alias metadata.
=======
#line 4379 "src/Slice/Grammar.cpp"
    break;

  case 202: /* string_list: string_list ',' string_literal  */
#line 2379 "src/Slice/Grammar.y"
>>>>>>> Added aliasing support into the parser.
=======
#line 4401 "src/Slice/Grammar.cpp"
    break;

  case 203: /* string_list: string_list ',' string_literal  */
#line 2391 "src/Slice/Grammar.y"
>>>>>>> Added better error handling logic to the parser.
=======
#line 4403 "src/Slice/Grammar.cpp"
    break;

  case 203: /* string_list: string_list ',' string_literal  */
#line 2393 "src/Slice/Grammar.y"
>>>>>>> Cosmetic changes.
=======
#line 4388 "src/Slice/Grammar.cpp"
    break;

  case 203: /* string_list: string_list ',' string_literal  */
#line 2392 "src/Slice/Grammar.y"
>>>>>>> More cosmetic changes.
=======
#line 4362 "src/Slice/Grammar.cpp"
    break;

  case 203: /* string_list: string_list ',' string_literal  */
#line 2366 "src/Slice/Grammar.y"
>>>>>>> Fixed review comments.
=======
#line 4357 "src/Slice/Grammar.cpp"
    break;

  case 203: /* string_list: string_list ',' string_literal  */
#line 2361 "src/Slice/Grammar.y"
>>>>>>> Fixed the tests.
=======
#line 4344 "src/Slice/Grammar.cpp"
    break;

  case 203: /* string_list: string_list ',' string_literal  */
#line 2348 "src/Slice/Grammar.y"
>>>>>>> Next batch of review fixes.
=======
#line 4343 "src/Slice/Grammar.cpp"
    break;

  case 203: /* string_list: string_list ',' string_literal  */
#line 2347 "src/Slice/Grammar.y"
>>>>>>> Missed some stuff I meant to git add.
{
    StringTokPtr str = StringTokPtr::dynamicCast(yyvsp[0]);
    StringListTokPtr stringList = StringListTokPtr::dynamicCast(yyvsp[-2]);
    stringList->v.push_back(str->v);
    yyval = stringList;
}
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
#line 4297 "src/Slice/Grammar.cpp"
    break;

  case 201: /* string_list: string_literal  */
#line 2306 "src/Slice/Grammar.y"
=======
#line 4288 "src/Slice/Grammar.cpp"
    break;

  case 203: /* string_list: string_literal  */
#line 2288 "src/Slice/Grammar.y"
>>>>>>> Regenerated compilers, and fixed build errors.
=======
#line 4293 "src/Slice/Grammar.cpp"
    break;

  case 203: /* string_list: string_literal  */
#line 2289 "src/Slice/Grammar.y"
>>>>>>> Added support for type-alias metadata.
=======
#line 4390 "src/Slice/Grammar.cpp"
    break;

  case 203: /* string_list: string_literal  */
#line 2386 "src/Slice/Grammar.y"
>>>>>>> Added aliasing support into the parser.
=======
#line 4412 "src/Slice/Grammar.cpp"
    break;

  case 204: /* string_list: string_literal  */
#line 2398 "src/Slice/Grammar.y"
>>>>>>> Added better error handling logic to the parser.
=======
#line 4414 "src/Slice/Grammar.cpp"
    break;

  case 204: /* string_list: string_literal  */
#line 2400 "src/Slice/Grammar.y"
>>>>>>> Cosmetic changes.
=======
#line 4399 "src/Slice/Grammar.cpp"
    break;

  case 204: /* string_list: string_literal  */
#line 2399 "src/Slice/Grammar.y"
>>>>>>> More cosmetic changes.
=======
#line 4373 "src/Slice/Grammar.cpp"
    break;

  case 204: /* string_list: string_literal  */
#line 2373 "src/Slice/Grammar.y"
>>>>>>> Fixed review comments.
=======
#line 4368 "src/Slice/Grammar.cpp"
    break;

  case 204: /* string_list: string_literal  */
#line 2368 "src/Slice/Grammar.y"
>>>>>>> Fixed the tests.
=======
#line 4355 "src/Slice/Grammar.cpp"
    break;

  case 204: /* string_list: string_literal  */
#line 2355 "src/Slice/Grammar.y"
>>>>>>> Next batch of review fixes.
=======
#line 4354 "src/Slice/Grammar.cpp"
    break;

  case 204: /* string_list: string_literal  */
#line 2354 "src/Slice/Grammar.y"
>>>>>>> Missed some stuff I meant to git add.
{
    StringTokPtr str = StringTokPtr::dynamicCast(yyvsp[0]);
    StringListTokPtr stringList = new StringListTok;
    stringList->v.push_back(str->v);
    yyval = stringList;
}
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
#line 4308 "src/Slice/Grammar.cpp"
    break;

  case 202: /* const_initializer: ICE_INTEGER_LITERAL  */
#line 2318 "src/Slice/Grammar.y"
=======
#line 4299 "src/Slice/Grammar.cpp"
    break;

  case 204: /* const_initializer: ICE_INTEGER_LITERAL  */
#line 2300 "src/Slice/Grammar.y"
>>>>>>> Regenerated compilers, and fixed build errors.
=======
#line 4304 "src/Slice/Grammar.cpp"
    break;

  case 204: /* const_initializer: ICE_INTEGER_LITERAL  */
#line 2301 "src/Slice/Grammar.y"
>>>>>>> Added support for type-alias metadata.
=======
#line 4401 "src/Slice/Grammar.cpp"
    break;

  case 204: /* const_initializer: ICE_INTEGER_LITERAL  */
#line 2398 "src/Slice/Grammar.y"
>>>>>>> Added aliasing support into the parser.
=======
#line 4423 "src/Slice/Grammar.cpp"
    break;

  case 205: /* const_initializer: ICE_INTEGER_LITERAL  */
#line 2410 "src/Slice/Grammar.y"
>>>>>>> Added better error handling logic to the parser.
=======
#line 4425 "src/Slice/Grammar.cpp"
    break;

  case 205: /* const_initializer: ICE_INTEGER_LITERAL  */
#line 2412 "src/Slice/Grammar.y"
>>>>>>> Cosmetic changes.
=======
#line 4410 "src/Slice/Grammar.cpp"
    break;

  case 205: /* const_initializer: ICE_INTEGER_LITERAL  */
#line 2411 "src/Slice/Grammar.y"
>>>>>>> More cosmetic changes.
=======
#line 4384 "src/Slice/Grammar.cpp"
    break;

  case 205: /* const_initializer: ICE_INTEGER_LITERAL  */
#line 2385 "src/Slice/Grammar.y"
>>>>>>> Fixed review comments.
=======
#line 4379 "src/Slice/Grammar.cpp"
    break;

  case 205: /* const_initializer: ICE_INTEGER_LITERAL  */
#line 2380 "src/Slice/Grammar.y"
>>>>>>> Fixed the tests.
=======
#line 4366 "src/Slice/Grammar.cpp"
    break;

  case 205: /* const_initializer: ICE_INTEGER_LITERAL  */
#line 2367 "src/Slice/Grammar.y"
>>>>>>> Next batch of review fixes.
=======
#line 4365 "src/Slice/Grammar.cpp"
    break;

  case 205: /* const_initializer: ICE_INTEGER_LITERAL  */
#line 2366 "src/Slice/Grammar.y"
>>>>>>> Missed some stuff I meant to git add.
{
    BuiltinPtr type = unit->builtin(Builtin::KindLong);
    IntegerTokPtr intVal = IntegerTokPtr::dynamicCast(yyvsp[0]);
    ostringstream sstr;
    sstr << intVal->v;
    ConstDefTokPtr def = new ConstDefTok(type, sstr.str(), intVal->literal);
    yyval = def;
}
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
#line 4321 "src/Slice/Grammar.cpp"
    break;

  case 203: /* const_initializer: ICE_FLOATING_POINT_LITERAL  */
#line 2327 "src/Slice/Grammar.y"
=======
#line 4312 "src/Slice/Grammar.cpp"
    break;

  case 205: /* const_initializer: ICE_FLOATING_POINT_LITERAL  */
#line 2309 "src/Slice/Grammar.y"
>>>>>>> Regenerated compilers, and fixed build errors.
=======
#line 4317 "src/Slice/Grammar.cpp"
    break;

  case 205: /* const_initializer: ICE_FLOATING_POINT_LITERAL  */
#line 2310 "src/Slice/Grammar.y"
>>>>>>> Added support for type-alias metadata.
=======
#line 4414 "src/Slice/Grammar.cpp"
    break;

  case 205: /* const_initializer: ICE_FLOATING_POINT_LITERAL  */
#line 2407 "src/Slice/Grammar.y"
>>>>>>> Added aliasing support into the parser.
=======
#line 4436 "src/Slice/Grammar.cpp"
    break;

  case 206: /* const_initializer: ICE_FLOATING_POINT_LITERAL  */
#line 2419 "src/Slice/Grammar.y"
>>>>>>> Added better error handling logic to the parser.
=======
#line 4438 "src/Slice/Grammar.cpp"
    break;

  case 206: /* const_initializer: ICE_FLOATING_POINT_LITERAL  */
#line 2421 "src/Slice/Grammar.y"
>>>>>>> Cosmetic changes.
=======
#line 4423 "src/Slice/Grammar.cpp"
    break;

  case 206: /* const_initializer: ICE_FLOATING_POINT_LITERAL  */
#line 2420 "src/Slice/Grammar.y"
>>>>>>> More cosmetic changes.
=======
#line 4397 "src/Slice/Grammar.cpp"
    break;

  case 206: /* const_initializer: ICE_FLOATING_POINT_LITERAL  */
#line 2394 "src/Slice/Grammar.y"
>>>>>>> Fixed review comments.
=======
#line 4392 "src/Slice/Grammar.cpp"
    break;

  case 206: /* const_initializer: ICE_FLOATING_POINT_LITERAL  */
#line 2389 "src/Slice/Grammar.y"
>>>>>>> Fixed the tests.
=======
#line 4379 "src/Slice/Grammar.cpp"
    break;

  case 206: /* const_initializer: ICE_FLOATING_POINT_LITERAL  */
#line 2376 "src/Slice/Grammar.y"
>>>>>>> Next batch of review fixes.
=======
#line 4378 "src/Slice/Grammar.cpp"
    break;

  case 206: /* const_initializer: ICE_FLOATING_POINT_LITERAL  */
#line 2375 "src/Slice/Grammar.y"
>>>>>>> Missed some stuff I meant to git add.
{
    BuiltinPtr type = unit->builtin(Builtin::KindDouble);
    FloatingTokPtr floatVal = FloatingTokPtr::dynamicCast(yyvsp[0]);
    ostringstream sstr;
    sstr << floatVal->v;
    ConstDefTokPtr def = new ConstDefTok(type, sstr.str(), floatVal->literal);
    yyval = def;
}
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
#line 4334 "src/Slice/Grammar.cpp"
    break;

  case 204: /* const_initializer: scoped_name  */
#line 2336 "src/Slice/Grammar.y"
=======
#line 4325 "src/Slice/Grammar.cpp"
    break;

  case 206: /* const_initializer: scoped_name  */
#line 2318 "src/Slice/Grammar.y"
>>>>>>> Regenerated compilers, and fixed build errors.
=======
#line 4330 "src/Slice/Grammar.cpp"
    break;

  case 206: /* const_initializer: scoped_name  */
#line 2319 "src/Slice/Grammar.y"
>>>>>>> Added support for type-alias metadata.
=======
#line 4427 "src/Slice/Grammar.cpp"
    break;

  case 206: /* const_initializer: scoped_name  */
#line 2416 "src/Slice/Grammar.y"
>>>>>>> Added aliasing support into the parser.
=======
#line 4449 "src/Slice/Grammar.cpp"
    break;

  case 207: /* const_initializer: scoped_name  */
#line 2428 "src/Slice/Grammar.y"
>>>>>>> Added better error handling logic to the parser.
=======
#line 4451 "src/Slice/Grammar.cpp"
    break;

  case 207: /* const_initializer: scoped_name  */
#line 2430 "src/Slice/Grammar.y"
>>>>>>> Cosmetic changes.
=======
#line 4436 "src/Slice/Grammar.cpp"
    break;

  case 207: /* const_initializer: scoped_name  */
#line 2429 "src/Slice/Grammar.y"
>>>>>>> More cosmetic changes.
=======
#line 4410 "src/Slice/Grammar.cpp"
    break;

  case 207: /* const_initializer: scoped_name  */
#line 2403 "src/Slice/Grammar.y"
>>>>>>> Fixed review comments.
=======
#line 4405 "src/Slice/Grammar.cpp"
    break;

  case 207: /* const_initializer: scoped_name  */
#line 2398 "src/Slice/Grammar.y"
>>>>>>> Fixed the tests.
=======
#line 4392 "src/Slice/Grammar.cpp"
    break;

  case 207: /* const_initializer: scoped_name  */
#line 2385 "src/Slice/Grammar.y"
>>>>>>> Next batch of review fixes.
=======
#line 4391 "src/Slice/Grammar.cpp"
    break;

  case 207: /* const_initializer: scoped_name  */
#line 2384 "src/Slice/Grammar.y"
>>>>>>> Missed some stuff I meant to git add.
{
    StringTokPtr scoped = StringTokPtr::dynamicCast(yyvsp[0]);
    ConstDefTokPtr def;
    ContainedList cl = unit->currentContainer()->lookupContained(scoped->v, false);
    if(cl.empty())
    {
        // Could be an enumerator
        def = new ConstDefTok(SyntaxTreeBasePtr(0), scoped->v, scoped->v);
    }
    else
    {
        EnumeratorPtr enumerator = EnumeratorPtr::dynamicCast(cl.front());
        ConstPtr constant = ConstPtr::dynamicCast(cl.front());
        if(enumerator)
        {
            unit->currentContainer()->checkIntroduced(scoped->v, enumerator);
            def = new ConstDefTok(enumerator, scoped->v, scoped->v);
        }
        else if(constant)
        {
            unit->currentContainer()->checkIntroduced(scoped->v, constant);
            def = new ConstDefTok(constant, constant->value(), constant->value());
        }
        else
        {
            def = new ConstDefTok;
            string msg = "illegal initializer: `" + scoped->v + "' is a";
            static const string vowels = "aeiou";
            string kindOf = cl.front()->kindOf();
            if(vowels.find_first_of(kindOf[0]) != string::npos)
            {
                msg += "n";
            }
            msg += " " + kindOf;
            unit->error(msg); // $$ is dummy
        }
    }
    yyval = def;
}
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
#line 4378 "src/Slice/Grammar.cpp"
    break;

  case 205: /* const_initializer: ICE_STRING_LITERAL  */
#line 2376 "src/Slice/Grammar.y"
=======
#line 4369 "src/Slice/Grammar.cpp"
    break;

  case 207: /* const_initializer: ICE_STRING_LITERAL  */
#line 2358 "src/Slice/Grammar.y"
>>>>>>> Regenerated compilers, and fixed build errors.
=======
#line 4374 "src/Slice/Grammar.cpp"
    break;

  case 207: /* const_initializer: ICE_STRING_LITERAL  */
#line 2359 "src/Slice/Grammar.y"
>>>>>>> Added support for type-alias metadata.
=======
#line 4471 "src/Slice/Grammar.cpp"
    break;

  case 207: /* const_initializer: ICE_STRING_LITERAL  */
#line 2456 "src/Slice/Grammar.y"
>>>>>>> Added aliasing support into the parser.
=======
#line 4493 "src/Slice/Grammar.cpp"
    break;

  case 208: /* const_initializer: ICE_STRING_LITERAL  */
#line 2468 "src/Slice/Grammar.y"
>>>>>>> Added better error handling logic to the parser.
=======
#line 4495 "src/Slice/Grammar.cpp"
    break;

  case 208: /* const_initializer: ICE_STRING_LITERAL  */
#line 2470 "src/Slice/Grammar.y"
>>>>>>> Cosmetic changes.
=======
#line 4480 "src/Slice/Grammar.cpp"
    break;

  case 208: /* const_initializer: ICE_STRING_LITERAL  */
#line 2469 "src/Slice/Grammar.y"
>>>>>>> More cosmetic changes.
=======
#line 4454 "src/Slice/Grammar.cpp"
    break;

  case 208: /* const_initializer: ICE_STRING_LITERAL  */
#line 2443 "src/Slice/Grammar.y"
>>>>>>> Fixed review comments.
=======
#line 4449 "src/Slice/Grammar.cpp"
    break;

  case 208: /* const_initializer: ICE_STRING_LITERAL  */
#line 2438 "src/Slice/Grammar.y"
>>>>>>> Fixed the tests.
=======
#line 4436 "src/Slice/Grammar.cpp"
    break;

  case 208: /* const_initializer: ICE_STRING_LITERAL  */
#line 2425 "src/Slice/Grammar.y"
>>>>>>> Next batch of review fixes.
=======
#line 4435 "src/Slice/Grammar.cpp"
    break;

  case 208: /* const_initializer: ICE_STRING_LITERAL  */
#line 2424 "src/Slice/Grammar.y"
>>>>>>> Missed some stuff I meant to git add.
{
    BuiltinPtr type = unit->builtin(Builtin::KindString);
    StringTokPtr literal = StringTokPtr::dynamicCast(yyvsp[0]);
    ConstDefTokPtr def = new ConstDefTok(type, literal->v, literal->literal);
    yyval = def;
}
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
#line 4389 "src/Slice/Grammar.cpp"
    break;

  case 206: /* const_initializer: ICE_FALSE  */
#line 2383 "src/Slice/Grammar.y"
=======
#line 4380 "src/Slice/Grammar.cpp"
    break;

  case 208: /* const_initializer: ICE_FALSE  */
#line 2365 "src/Slice/Grammar.y"
>>>>>>> Regenerated compilers, and fixed build errors.
=======
#line 4385 "src/Slice/Grammar.cpp"
    break;

  case 208: /* const_initializer: ICE_FALSE  */
#line 2366 "src/Slice/Grammar.y"
>>>>>>> Added support for type-alias metadata.
=======
#line 4482 "src/Slice/Grammar.cpp"
    break;

  case 208: /* const_initializer: ICE_FALSE  */
#line 2463 "src/Slice/Grammar.y"
>>>>>>> Added aliasing support into the parser.
=======
#line 4504 "src/Slice/Grammar.cpp"
    break;

  case 209: /* const_initializer: ICE_FALSE  */
#line 2475 "src/Slice/Grammar.y"
>>>>>>> Added better error handling logic to the parser.
=======
#line 4506 "src/Slice/Grammar.cpp"
    break;

  case 209: /* const_initializer: ICE_FALSE  */
#line 2477 "src/Slice/Grammar.y"
>>>>>>> Cosmetic changes.
=======
#line 4491 "src/Slice/Grammar.cpp"
    break;

  case 209: /* const_initializer: ICE_FALSE  */
#line 2476 "src/Slice/Grammar.y"
>>>>>>> More cosmetic changes.
=======
#line 4465 "src/Slice/Grammar.cpp"
    break;

  case 209: /* const_initializer: ICE_FALSE  */
#line 2450 "src/Slice/Grammar.y"
>>>>>>> Fixed review comments.
=======
#line 4460 "src/Slice/Grammar.cpp"
    break;

  case 209: /* const_initializer: ICE_FALSE  */
#line 2445 "src/Slice/Grammar.y"
>>>>>>> Fixed the tests.
=======
#line 4447 "src/Slice/Grammar.cpp"
    break;

  case 209: /* const_initializer: ICE_FALSE  */
#line 2432 "src/Slice/Grammar.y"
>>>>>>> Next batch of review fixes.
=======
#line 4446 "src/Slice/Grammar.cpp"
    break;

  case 209: /* const_initializer: ICE_FALSE  */
#line 2431 "src/Slice/Grammar.y"
>>>>>>> Missed some stuff I meant to git add.
{
    BuiltinPtr type = unit->builtin(Builtin::KindBool);
    StringTokPtr literal = StringTokPtr::dynamicCast(yyvsp[0]);
    ConstDefTokPtr def = new ConstDefTok(type, "false", "false");
    yyval = def;
}
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
#line 4400 "src/Slice/Grammar.cpp"
    break;

  case 207: /* const_initializer: ICE_TRUE  */
#line 2390 "src/Slice/Grammar.y"
=======
#line 4391 "src/Slice/Grammar.cpp"
    break;

  case 209: /* const_initializer: ICE_TRUE  */
#line 2372 "src/Slice/Grammar.y"
>>>>>>> Regenerated compilers, and fixed build errors.
=======
#line 4396 "src/Slice/Grammar.cpp"
    break;

  case 209: /* const_initializer: ICE_TRUE  */
#line 2373 "src/Slice/Grammar.y"
>>>>>>> Added support for type-alias metadata.
=======
#line 4493 "src/Slice/Grammar.cpp"
    break;

  case 209: /* const_initializer: ICE_TRUE  */
#line 2470 "src/Slice/Grammar.y"
>>>>>>> Added aliasing support into the parser.
=======
#line 4515 "src/Slice/Grammar.cpp"
    break;

  case 210: /* const_initializer: ICE_TRUE  */
#line 2482 "src/Slice/Grammar.y"
>>>>>>> Added better error handling logic to the parser.
=======
#line 4517 "src/Slice/Grammar.cpp"
    break;

  case 210: /* const_initializer: ICE_TRUE  */
#line 2484 "src/Slice/Grammar.y"
>>>>>>> Cosmetic changes.
=======
#line 4502 "src/Slice/Grammar.cpp"
    break;

  case 210: /* const_initializer: ICE_TRUE  */
#line 2483 "src/Slice/Grammar.y"
>>>>>>> More cosmetic changes.
=======
#line 4476 "src/Slice/Grammar.cpp"
    break;

  case 210: /* const_initializer: ICE_TRUE  */
#line 2457 "src/Slice/Grammar.y"
>>>>>>> Fixed review comments.
=======
#line 4471 "src/Slice/Grammar.cpp"
    break;

  case 210: /* const_initializer: ICE_TRUE  */
#line 2452 "src/Slice/Grammar.y"
>>>>>>> Fixed the tests.
=======
#line 4458 "src/Slice/Grammar.cpp"
    break;

  case 210: /* const_initializer: ICE_TRUE  */
#line 2439 "src/Slice/Grammar.y"
>>>>>>> Next batch of review fixes.
=======
#line 4457 "src/Slice/Grammar.cpp"
    break;

  case 210: /* const_initializer: ICE_TRUE  */
#line 2438 "src/Slice/Grammar.y"
>>>>>>> Missed some stuff I meant to git add.
{
    BuiltinPtr type = unit->builtin(Builtin::KindBool);
    StringTokPtr literal = StringTokPtr::dynamicCast(yyvsp[0]);
    ConstDefTokPtr def = new ConstDefTok(type, "true", "true");
    yyval = def;
}
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
#line 4411 "src/Slice/Grammar.cpp"
    break;

  case 208: /* const_def: ICE_CONST local_metadata type ICE_IDENTIFIER '=' const_initializer  */
#line 2402 "src/Slice/Grammar.y"
=======
#line 4402 "src/Slice/Grammar.cpp"
    break;

  case 210: /* const_def: ICE_CONST local_metadata type ICE_IDENTIFIER '=' const_initializer  */
#line 2384 "src/Slice/Grammar.y"
>>>>>>> Regenerated compilers, and fixed build errors.
=======
#line 4407 "src/Slice/Grammar.cpp"
    break;

  case 210: /* const_def: ICE_CONST local_metadata type ICE_IDENTIFIER '=' const_initializer  */
#line 2385 "src/Slice/Grammar.y"
>>>>>>> Added support for type-alias metadata.
=======
#line 4504 "src/Slice/Grammar.cpp"
    break;

  case 210: /* const_def: ICE_CONST local_metadata type ICE_IDENTIFIER '=' const_initializer  */
#line 2482 "src/Slice/Grammar.y"
>>>>>>> Added aliasing support into the parser.
=======
#line 4526 "src/Slice/Grammar.cpp"
    break;

  case 211: /* const_def: ICE_CONST local_metadata type ICE_IDENTIFIER '=' const_initializer  */
#line 2494 "src/Slice/Grammar.y"
>>>>>>> Added better error handling logic to the parser.
=======
#line 4528 "src/Slice/Grammar.cpp"
    break;

  case 211: /* const_def: ICE_CONST local_metadata type ICE_IDENTIFIER '=' const_initializer  */
#line 2496 "src/Slice/Grammar.y"
>>>>>>> Cosmetic changes.
=======
#line 4513 "src/Slice/Grammar.cpp"
    break;

  case 211: /* const_def: ICE_CONST local_metadata type ICE_IDENTIFIER '=' const_initializer  */
#line 2495 "src/Slice/Grammar.y"
>>>>>>> More cosmetic changes.
=======
#line 4487 "src/Slice/Grammar.cpp"
    break;

  case 211: /* const_def: ICE_CONST local_metadata type ICE_IDENTIFIER '=' const_initializer  */
#line 2469 "src/Slice/Grammar.y"
>>>>>>> Fixed review comments.
=======
#line 4482 "src/Slice/Grammar.cpp"
    break;

  case 211: /* const_def: ICE_CONST local_metadata type ICE_IDENTIFIER '=' const_initializer  */
#line 2464 "src/Slice/Grammar.y"
>>>>>>> Fixed the tests.
=======
#line 4469 "src/Slice/Grammar.cpp"
    break;

  case 211: /* const_def: ICE_CONST local_metadata type ICE_IDENTIFIER '=' const_initializer  */
#line 2451 "src/Slice/Grammar.y"
>>>>>>> Next batch of review fixes.
=======
#line 4468 "src/Slice/Grammar.cpp"
    break;

  case 211: /* const_def: ICE_CONST local_metadata type ICE_IDENTIFIER '=' const_initializer  */
#line 2450 "src/Slice/Grammar.y"
>>>>>>> Missed some stuff I meant to git add.
{
    StringListTokPtr metadata = StringListTokPtr::dynamicCast(yyvsp[-4]);
    TypePtr const_type = TypePtr::dynamicCast(yyvsp[-3]);
    StringTokPtr ident = StringTokPtr::dynamicCast(yyvsp[-2]);
    ConstDefTokPtr value = ConstDefTokPtr::dynamicCast(yyvsp[0]);

    unalias(const_type, metadata->v);

    yyval = unit->currentModule()->createConst(ident->v, const_type, metadata->v, value->v,
                                               value->valueAsString, value->valueAsLiteral);
}
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
#line 4424 "src/Slice/Grammar.cpp"
    break;

  case 209: /* const_def: ICE_CONST local_metadata type '=' const_initializer  */
#line 2411 "src/Slice/Grammar.y"
=======
#line 4415 "src/Slice/Grammar.cpp"
    break;

  case 211: /* const_def: ICE_CONST local_metadata type '=' const_initializer  */
#line 2393 "src/Slice/Grammar.y"
>>>>>>> Regenerated compilers, and fixed build errors.
=======
#line 4420 "src/Slice/Grammar.cpp"
    break;

  case 211: /* const_def: ICE_CONST local_metadata type '=' const_initializer  */
#line 2394 "src/Slice/Grammar.y"
>>>>>>> Added support for type-alias metadata.
=======
#line 4524 "src/Slice/Grammar.cpp"
    break;

  case 211: /* const_def: ICE_CONST local_metadata type '=' const_initializer  */
#line 2498 "src/Slice/Grammar.y"
>>>>>>> Added aliasing support into the parser.
=======
#line 4546 "src/Slice/Grammar.cpp"
    break;

  case 212: /* const_def: ICE_CONST local_metadata type '=' const_initializer  */
#line 2510 "src/Slice/Grammar.y"
>>>>>>> Added better error handling logic to the parser.
=======
#line 4548 "src/Slice/Grammar.cpp"
    break;

  case 212: /* const_def: ICE_CONST local_metadata type '=' const_initializer  */
#line 2512 "src/Slice/Grammar.y"
>>>>>>> Cosmetic changes.
=======
#line 4533 "src/Slice/Grammar.cpp"
    break;

  case 212: /* const_def: ICE_CONST local_metadata type '=' const_initializer  */
#line 2511 "src/Slice/Grammar.y"
>>>>>>> More cosmetic changes.
=======
#line 4503 "src/Slice/Grammar.cpp"
    break;

  case 212: /* const_def: ICE_CONST local_metadata type '=' const_initializer  */
#line 2481 "src/Slice/Grammar.y"
>>>>>>> Fixed review comments.
=======
#line 4498 "src/Slice/Grammar.cpp"
    break;

  case 212: /* const_def: ICE_CONST local_metadata type '=' const_initializer  */
#line 2476 "src/Slice/Grammar.y"
>>>>>>> Fixed the tests.
=======
#line 4485 "src/Slice/Grammar.cpp"
    break;

  case 212: /* const_def: ICE_CONST local_metadata type '=' const_initializer  */
#line 2463 "src/Slice/Grammar.y"
>>>>>>> Next batch of review fixes.
=======
#line 4484 "src/Slice/Grammar.cpp"
    break;

  case 212: /* const_def: ICE_CONST local_metadata type '=' const_initializer  */
#line 2462 "src/Slice/Grammar.y"
>>>>>>> Missed some stuff I meant to git add.
{
    StringListTokPtr metadata = StringListTokPtr::dynamicCast(yyvsp[-3]);
    TypePtr const_type = TypePtr::dynamicCast(yyvsp[-2]);
    ConstDefTokPtr value = ConstDefTokPtr::dynamicCast(yyvsp[0]);
    unit->error("missing constant name");

    unalias(const_type, metadata->v);

    yyval = unit->currentModule()->createConst(IceUtil::generateUUID(), const_type, metadata->v, value->v,
                                               value->valueAsString, value->valueAsLiteral, Dummy); // Dummy
}
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
#line 4437 "src/Slice/Grammar.cpp"
    break;

  case 210: /* keyword: ICE_MODULE  */
#line 2424 "src/Slice/Grammar.y"
             {}
#line 4443 "src/Slice/Grammar.cpp"
    break;

  case 211: /* keyword: ICE_CLASS  */
#line 2425 "src/Slice/Grammar.y"
            {}
#line 4449 "src/Slice/Grammar.cpp"
    break;

  case 212: /* keyword: ICE_INTERFACE  */
#line 2426 "src/Slice/Grammar.y"
                {}
#line 4455 "src/Slice/Grammar.cpp"
    break;

  case 213: /* keyword: ICE_EXCEPTION  */
#line 2427 "src/Slice/Grammar.y"
                {}
#line 4461 "src/Slice/Grammar.cpp"
    break;

  case 214: /* keyword: ICE_STRUCT  */
#line 2428 "src/Slice/Grammar.y"
             {}
#line 4467 "src/Slice/Grammar.cpp"
    break;

  case 215: /* keyword: ICE_SEQUENCE  */
#line 2429 "src/Slice/Grammar.y"
               {}
#line 4473 "src/Slice/Grammar.cpp"
    break;

  case 216: /* keyword: ICE_DICTIONARY  */
#line 2430 "src/Slice/Grammar.y"
                 {}
#line 4479 "src/Slice/Grammar.cpp"
    break;

  case 217: /* keyword: ICE_ENUM  */
#line 2431 "src/Slice/Grammar.y"
           {}
#line 4485 "src/Slice/Grammar.cpp"
    break;

  case 218: /* keyword: ICE_OUT  */
#line 2432 "src/Slice/Grammar.y"
          {}
#line 4491 "src/Slice/Grammar.cpp"
    break;

  case 219: /* keyword: ICE_STREAM  */
#line 2433 "src/Slice/Grammar.y"
             {}
#line 4497 "src/Slice/Grammar.cpp"
    break;

  case 220: /* keyword: ICE_EXTENDS  */
#line 2434 "src/Slice/Grammar.y"
              {}
#line 4503 "src/Slice/Grammar.cpp"
    break;

  case 221: /* keyword: ICE_IMPLEMENTS  */
#line 2435 "src/Slice/Grammar.y"
                 {}
#line 4509 "src/Slice/Grammar.cpp"
    break;

  case 222: /* keyword: ICE_THROWS  */
#line 2436 "src/Slice/Grammar.y"
             {}
#line 4515 "src/Slice/Grammar.cpp"
    break;

  case 223: /* keyword: ICE_VOID  */
#line 2437 "src/Slice/Grammar.y"
           {}
#line 4521 "src/Slice/Grammar.cpp"
    break;

  case 224: /* keyword: ICE_BOOL  */
#line 2438 "src/Slice/Grammar.y"
           {}
#line 4527 "src/Slice/Grammar.cpp"
    break;

  case 225: /* keyword: ICE_BYTE  */
#line 2439 "src/Slice/Grammar.y"
           {}
#line 4533 "src/Slice/Grammar.cpp"
    break;

  case 226: /* keyword: ICE_SHORT  */
#line 2440 "src/Slice/Grammar.y"
            {}
#line 4539 "src/Slice/Grammar.cpp"
    break;

  case 227: /* keyword: ICE_USHORT  */
#line 2441 "src/Slice/Grammar.y"
             {}
#line 4545 "src/Slice/Grammar.cpp"
    break;

  case 228: /* keyword: ICE_INT  */
#line 2442 "src/Slice/Grammar.y"
          {}
#line 4551 "src/Slice/Grammar.cpp"
    break;

  case 229: /* keyword: ICE_UINT  */
#line 2443 "src/Slice/Grammar.y"
           {}
#line 4557 "src/Slice/Grammar.cpp"
    break;

  case 230: /* keyword: ICE_VARINT  */
#line 2444 "src/Slice/Grammar.y"
             {}
#line 4563 "src/Slice/Grammar.cpp"
    break;

  case 231: /* keyword: ICE_VARUINT  */
#line 2445 "src/Slice/Grammar.y"
              {}
#line 4569 "src/Slice/Grammar.cpp"
    break;

  case 232: /* keyword: ICE_LONG  */
#line 2446 "src/Slice/Grammar.y"
           {}
#line 4575 "src/Slice/Grammar.cpp"
    break;

  case 233: /* keyword: ICE_ULONG  */
#line 2447 "src/Slice/Grammar.y"
            {}
#line 4581 "src/Slice/Grammar.cpp"
    break;

  case 234: /* keyword: ICE_VARLONG  */
#line 2448 "src/Slice/Grammar.y"
              {}
#line 4587 "src/Slice/Grammar.cpp"
    break;

  case 235: /* keyword: ICE_VARULONG  */
#line 2449 "src/Slice/Grammar.y"
               {}
#line 4593 "src/Slice/Grammar.cpp"
    break;

  case 236: /* keyword: ICE_FLOAT  */
#line 2450 "src/Slice/Grammar.y"
            {}
#line 4599 "src/Slice/Grammar.cpp"
    break;

  case 237: /* keyword: ICE_DOUBLE  */
#line 2451 "src/Slice/Grammar.y"
             {}
#line 4605 "src/Slice/Grammar.cpp"
    break;

  case 238: /* keyword: ICE_STRING  */
#line 2452 "src/Slice/Grammar.y"
             {}
#line 4611 "src/Slice/Grammar.cpp"
    break;

  case 239: /* keyword: ICE_OBJECT  */
#line 2453 "src/Slice/Grammar.y"
             {}
#line 4617 "src/Slice/Grammar.cpp"
    break;

  case 240: /* keyword: ICE_CONST  */
#line 2454 "src/Slice/Grammar.y"
            {}
#line 4623 "src/Slice/Grammar.cpp"
    break;

  case 241: /* keyword: ICE_FALSE  */
#line 2455 "src/Slice/Grammar.y"
            {}
#line 4629 "src/Slice/Grammar.cpp"
    break;

  case 242: /* keyword: ICE_TRUE  */
#line 2456 "src/Slice/Grammar.y"
           {}
#line 4635 "src/Slice/Grammar.cpp"
    break;

  case 243: /* keyword: ICE_IDEMPOTENT  */
#line 2457 "src/Slice/Grammar.y"
                 {}
#line 4641 "src/Slice/Grammar.cpp"
    break;

  case 244: /* keyword: ICE_TAG  */
#line 2458 "src/Slice/Grammar.y"
          {}
#line 4647 "src/Slice/Grammar.cpp"
    break;

  case 245: /* keyword: ICE_OPTIONAL  */
#line 2459 "src/Slice/Grammar.y"
               {}
#line 4653 "src/Slice/Grammar.cpp"
    break;

  case 246: /* keyword: ICE_ANYCLASS  */
#line 2460 "src/Slice/Grammar.y"
               {}
#line 4659 "src/Slice/Grammar.cpp"
    break;

  case 247: /* keyword: ICE_VALUE  */
#line 2461 "src/Slice/Grammar.y"
            {}
#line 4665 "src/Slice/Grammar.cpp"
    break;


#line 4669 "src/Slice/Grammar.cpp"
=======
#line 4428 "src/Slice/Grammar.cpp"
=======
#line 4433 "src/Slice/Grammar.cpp"
>>>>>>> Added support for type-alias metadata.
=======
#line 4544 "src/Slice/Grammar.cpp"
>>>>>>> Added aliasing support into the parser.
=======
#line 4566 "src/Slice/Grammar.cpp"
>>>>>>> Added better error handling logic to the parser.
=======
#line 4568 "src/Slice/Grammar.cpp"
>>>>>>> Cosmetic changes.
=======
#line 4553 "src/Slice/Grammar.cpp"
>>>>>>> More cosmetic changes.
=======
#line 4519 "src/Slice/Grammar.cpp"
>>>>>>> Fixed review comments.
=======
#line 4514 "src/Slice/Grammar.cpp"
>>>>>>> Fixed the tests.
=======
#line 4501 "src/Slice/Grammar.cpp"
>>>>>>> Next batch of review fixes.
=======
#line 4500 "src/Slice/Grammar.cpp"
>>>>>>> Missed some stuff I meant to git add.
    break;

  case 213: /* keyword: ICE_MODULE  */
#line 2478 "src/Slice/Grammar.y"
             {}
#line 4506 "src/Slice/Grammar.cpp"
    break;

  case 214: /* keyword: ICE_CLASS  */
#line 2479 "src/Slice/Grammar.y"
            {}
#line 4512 "src/Slice/Grammar.cpp"
    break;

  case 215: /* keyword: ICE_INTERFACE  */
#line 2480 "src/Slice/Grammar.y"
                {}
#line 4518 "src/Slice/Grammar.cpp"
    break;

  case 216: /* keyword: ICE_EXCEPTION  */
#line 2481 "src/Slice/Grammar.y"
                {}
#line 4524 "src/Slice/Grammar.cpp"
    break;

  case 217: /* keyword: ICE_STRUCT  */
#line 2482 "src/Slice/Grammar.y"
             {}
#line 4530 "src/Slice/Grammar.cpp"
    break;

  case 218: /* keyword: ICE_SEQUENCE  */
#line 2483 "src/Slice/Grammar.y"
               {}
#line 4536 "src/Slice/Grammar.cpp"
    break;

  case 219: /* keyword: ICE_DICTIONARY  */
#line 2484 "src/Slice/Grammar.y"
                 {}
#line 4542 "src/Slice/Grammar.cpp"
    break;

  case 220: /* keyword: ICE_ENUM  */
#line 2485 "src/Slice/Grammar.y"
           {}
#line 4548 "src/Slice/Grammar.cpp"
    break;

  case 221: /* keyword: ICE_OUT  */
#line 2486 "src/Slice/Grammar.y"
          {}
#line 4554 "src/Slice/Grammar.cpp"
    break;

  case 222: /* keyword: ICE_EXTENDS  */
#line 2487 "src/Slice/Grammar.y"
              {}
#line 4560 "src/Slice/Grammar.cpp"
    break;

  case 223: /* keyword: ICE_IMPLEMENTS  */
#line 2488 "src/Slice/Grammar.y"
                 {}
#line 4566 "src/Slice/Grammar.cpp"
    break;

  case 224: /* keyword: ICE_THROWS  */
#line 2489 "src/Slice/Grammar.y"
             {}
#line 4572 "src/Slice/Grammar.cpp"
    break;

  case 225: /* keyword: ICE_VOID  */
#line 2490 "src/Slice/Grammar.y"
           {}
#line 4578 "src/Slice/Grammar.cpp"
    break;

  case 226: /* keyword: ICE_BOOL  */
#line 2491 "src/Slice/Grammar.y"
           {}
#line 4584 "src/Slice/Grammar.cpp"
    break;

  case 227: /* keyword: ICE_BYTE  */
#line 2492 "src/Slice/Grammar.y"
           {}
#line 4590 "src/Slice/Grammar.cpp"
    break;

  case 228: /* keyword: ICE_SHORT  */
#line 2493 "src/Slice/Grammar.y"
            {}
#line 4596 "src/Slice/Grammar.cpp"
    break;

  case 229: /* keyword: ICE_USHORT  */
#line 2494 "src/Slice/Grammar.y"
             {}
#line 4602 "src/Slice/Grammar.cpp"
    break;

  case 230: /* keyword: ICE_INT  */
#line 2495 "src/Slice/Grammar.y"
          {}
#line 4608 "src/Slice/Grammar.cpp"
    break;

  case 231: /* keyword: ICE_UINT  */
#line 2496 "src/Slice/Grammar.y"
           {}
#line 4614 "src/Slice/Grammar.cpp"
    break;

  case 232: /* keyword: ICE_VARINT  */
#line 2497 "src/Slice/Grammar.y"
             {}
#line 4620 "src/Slice/Grammar.cpp"
    break;

  case 233: /* keyword: ICE_VARUINT  */
#line 2498 "src/Slice/Grammar.y"
              {}
#line 4626 "src/Slice/Grammar.cpp"
    break;

  case 234: /* keyword: ICE_LONG  */
#line 2499 "src/Slice/Grammar.y"
           {}
#line 4632 "src/Slice/Grammar.cpp"
    break;

  case 235: /* keyword: ICE_ULONG  */
#line 2500 "src/Slice/Grammar.y"
            {}
#line 4638 "src/Slice/Grammar.cpp"
    break;

  case 236: /* keyword: ICE_VARLONG  */
#line 2501 "src/Slice/Grammar.y"
              {}
#line 4644 "src/Slice/Grammar.cpp"
    break;

  case 237: /* keyword: ICE_VARULONG  */
#line 2502 "src/Slice/Grammar.y"
               {}
#line 4650 "src/Slice/Grammar.cpp"
    break;

  case 238: /* keyword: ICE_FLOAT  */
#line 2503 "src/Slice/Grammar.y"
            {}
#line 4656 "src/Slice/Grammar.cpp"
    break;

  case 239: /* keyword: ICE_DOUBLE  */
#line 2504 "src/Slice/Grammar.y"
             {}
#line 4662 "src/Slice/Grammar.cpp"
    break;

  case 240: /* keyword: ICE_STRING  */
#line 2505 "src/Slice/Grammar.y"
             {}
#line 4668 "src/Slice/Grammar.cpp"
    break;

  case 241: /* keyword: ICE_OBJECT  */
#line 2506 "src/Slice/Grammar.y"
             {}
#line 4674 "src/Slice/Grammar.cpp"
    break;

  case 242: /* keyword: ICE_CONST  */
#line 2507 "src/Slice/Grammar.y"
            {}
#line 4680 "src/Slice/Grammar.cpp"
    break;

  case 243: /* keyword: ICE_FALSE  */
#line 2508 "src/Slice/Grammar.y"
            {}
#line 4686 "src/Slice/Grammar.cpp"
    break;

  case 244: /* keyword: ICE_TRUE  */
#line 2509 "src/Slice/Grammar.y"
           {}
#line 4692 "src/Slice/Grammar.cpp"
    break;

  case 245: /* keyword: ICE_IDEMPOTENT  */
#line 2510 "src/Slice/Grammar.y"
                 {}
#line 4698 "src/Slice/Grammar.cpp"
    break;

  case 246: /* keyword: ICE_TAG  */
#line 2511 "src/Slice/Grammar.y"
          {}
#line 4704 "src/Slice/Grammar.cpp"
    break;

  case 247: /* keyword: ICE_OPTIONAL  */
#line 2512 "src/Slice/Grammar.y"
               {}
#line 4710 "src/Slice/Grammar.cpp"
    break;

  case 248: /* keyword: ICE_ANYCLASS  */
#line 2513 "src/Slice/Grammar.y"
               {}
#line 4716 "src/Slice/Grammar.cpp"
    break;

  case 249: /* keyword: ICE_VALUE  */
#line 2514 "src/Slice/Grammar.y"
            {}
#line 4722 "src/Slice/Grammar.cpp"
    break;


<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
#line 4654 "src/Slice/Grammar.cpp"
>>>>>>> Regenerated compilers, and fixed build errors.
=======
#line 4659 "src/Slice/Grammar.cpp"
>>>>>>> Added support for type-alias metadata.
=======
#line 4770 "src/Slice/Grammar.cpp"
>>>>>>> Added aliasing support into the parser.
=======
#line 4792 "src/Slice/Grammar.cpp"
>>>>>>> Added better error handling logic to the parser.
=======
#line 4794 "src/Slice/Grammar.cpp"
>>>>>>> Cosmetic changes.
=======
#line 4779 "src/Slice/Grammar.cpp"
>>>>>>> More cosmetic changes.
=======
#line 4745 "src/Slice/Grammar.cpp"
>>>>>>> Fixed review comments.
=======
#line 4740 "src/Slice/Grammar.cpp"
>>>>>>> Fixed the tests.
=======
#line 4727 "src/Slice/Grammar.cpp"
>>>>>>> Next batch of review fixes.
=======
#line 4726 "src/Slice/Grammar.cpp"
>>>>>>> Missed some stuff I meant to git add.

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;
  *++yylsp = yyloc;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
    }

  yyerror_range[1] = yylloc;
  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval, &yylloc);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  ++yylsp;
  YYLLOC_DEFAULT (*yylsp, yyerror_range, 2);

  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;


#if !defined yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturn;
#endif


/*-------------------------------------------------------.
| yyreturn -- parsing is finished, clean up and return.  |
`-------------------------------------------------------*/
yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval, &yylloc);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp, yylsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
<<<<<<< HEAD
#line 2464 "src/Slice/Grammar.y"
=======
#line 2445 "src/Slice/Grammar.y"
>>>>>>> Regenerated compilers, and fixed build errors.
=======
#line 2446 "src/Slice/Grammar.y"
>>>>>>> Added support for type-alias metadata.
=======
#line 2557 "src/Slice/Grammar.y"
>>>>>>> Added aliasing support into the parser.
=======
#line 2569 "src/Slice/Grammar.y"
>>>>>>> Added better error handling logic to the parser.
=======
#line 2571 "src/Slice/Grammar.y"
>>>>>>> Cosmetic changes.
=======
#line 2570 "src/Slice/Grammar.y"
>>>>>>> More cosmetic changes.
=======
#line 2536 "src/Slice/Grammar.y"
>>>>>>> Fixed review comments.
=======
#line 2531 "src/Slice/Grammar.y"
>>>>>>> Fixed the tests.
=======
#line 2518 "src/Slice/Grammar.y"
>>>>>>> Next batch of review fixes.
=======
#line 2517 "src/Slice/Grammar.y"
>>>>>>> Missed some stuff I meant to git add.

