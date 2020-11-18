/* A Bison parser, made by GNU Bison 3.7.1.  */

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

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.7.1"

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


#line 183 "src/Slice/Grammar.cpp"

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
  YYSYMBOL_ICE_USING = 8,                  /* ICE_USING  */
  YYSYMBOL_ICE_SEQUENCE = 9,               /* ICE_SEQUENCE  */
  YYSYMBOL_ICE_DICTIONARY = 10,            /* ICE_DICTIONARY  */
  YYSYMBOL_ICE_ENUM = 11,                  /* ICE_ENUM  */
  YYSYMBOL_ICE_OUT = 12,                   /* ICE_OUT  */
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
};
typedef enum yysymbol_kind_t yysymbol_kind_t;



/* Unqualified %code blocks.  */
#line 61 "src/Slice/Grammar.y"


// Forward declaration of the lexing function generated by flex, so bison knows about it.
// This must match the definition of 'yylex' (or 'slice_lex') in the generated scanner.
int slice_lex(YYSTYPE* lvalp, YYLTYPE* llocp);


#line 378 "src/Slice/Grammar.cpp"

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
#define YYLAST   1109

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  64
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  89
/* YYNRULES -- Number of rules.  */
#define YYNRULES  248
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  353

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
       0,   204,   204,   210,   211,   217,   228,   234,   243,   252,
     260,   269,   276,   275,   281,   280,   285,   290,   289,   295,
     294,   299,   304,   303,   309,   308,   313,   318,   317,   323,
     322,   327,   332,   331,   337,   336,   342,   341,   346,   350,
     355,   354,   359,   364,   363,   369,   368,   373,   377,   387,
     386,   425,   424,   502,   506,   517,   528,   527,   553,   561,
     570,   588,   662,   668,   679,   701,   779,   789,   804,   808,
     819,   830,   829,   870,   874,   885,   910,  1000,  1012,  1025,
    1024,  1058,  1092,  1101,  1102,  1108,  1123,  1145,  1146,  1147,
    1151,  1157,  1158,  1164,  1176,  1192,  1207,  1216,  1221,  1230,
    1265,  1300,  1334,  1374,  1373,  1396,  1395,  1418,  1436,  1440,
    1441,  1447,  1451,  1462,  1476,  1475,  1509,  1544,  1579,  1584,
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

#define YYPACT_NINF (-281)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-165)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
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
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
      11,     0,     8,     1,     0,     0,     9,     0,   201,   203,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   134,     8,     0,     0,    10,    12,    55,    26,    27,
      70,    31,    32,    78,    82,    16,    17,   113,    21,    22,
      38,    39,    42,   139,   142,    43,    47,   200,     6,     0,
       5,    48,    49,    51,   212,   213,   214,   215,   216,   217,
     218,   219,   220,   221,   222,   223,   224,   225,   226,   227,
     228,   229,   230,   231,   232,   233,   234,   235,   236,   237,
     238,   239,   240,   241,   242,   243,   244,   245,   246,   247,
     248,    73,   165,     0,    74,   111,   112,    53,    54,    68,
      69,   128,     8,     8,     0,   133,     0,     4,    83,    84,
      56,     0,     0,     4,     0,     0,     4,    79,     0,     0,
       4,     0,   114,     0,     4,     0,     0,     0,   135,     0,
     136,     0,   137,     4,     0,   202,     0,     0,     0,     0,
       0,     0,   166,   167,   168,   169,   170,   171,   172,   173,
     174,   175,   176,   177,   178,   179,   180,   186,   187,   188,
     162,   163,   190,   189,     0,     7,     3,    13,     0,    58,
      25,    28,     0,    30,    33,     0,    81,    15,    18,   118,
     119,   120,   121,   117,     0,    20,    23,    37,    35,    41,
       8,   141,     0,    44,    46,    11,    11,     0,     0,   127,
       0,     0,   181,   182,   183,   184,   191,   192,   185,     0,
       0,     0,     0,    63,    67,     0,     0,     0,    89,     0,
       0,   195,   198,    85,     0,     0,     0,     0,     0,   143,
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
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -281,  -281,    -5,  -281,    -2,    15,  -281,  -281,  -281,  -281,
    -281,  -281,  -281,  -281,  -281,  -281,  -281,  -281,  -281,  -281,
    -281,  -281,  -281,  -281,  -281,  -281,  -281,  -281,  -281,  -281,
    -281,  -281,  -281,  -281,  -281,  -281,  -281,  -281,  -281,  -281,
    -281,   161,  -281,  -212,   -97,  -281,   -45,  -281,  -281,  -281,
    -281,  -215,  -281,  -281,  -281,  -281,    20,  -281,   -58,  -281,
    -281,  -281,  -281,  -281,  -281,  -281,  -281,  -281,  -281,    63,
    -281,    28,  -281,  -254,   -37,  -281,  -281,   -44,  -105,  -280,
    -281,   -95,  -251,  -207,    24,     0,  -141,  -281,   -13
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,   167,     6,   215,     2,    25,   107,   119,   120,
     123,   124,   112,   113,   115,   116,   126,   125,   127,   133,
     134,    26,   136,   137,    27,    28,    29,   168,   110,   216,
     217,    30,    31,    32,   114,    33,    34,    35,    36,   175,
     117,   111,   218,   219,   220,   308,   290,   291,   292,   342,
     340,   264,    37,    38,    39,   184,   182,   122,   347,   348,
      40,    41,    42,    43,    44,    45,   192,   129,   132,   228,
     229,   230,   320,   314,   315,   316,   317,   345,   162,    93,
     163,   221,   222,   223,     9,    10,   245,    46,   350
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
       7,    94,    96,    98,   100,    11,   169,   255,   251,   164,
     311,     4,   293,   176,   209,   179,   183,    -2,  -145,   108,
     104,   306,   180,   181,   106,   323,     8,   210,   160,   161,
     130,   313,    47,   198,   108,   309,   191,   293,   325,   -77,
     108,   326,   306,   255,   199,   200,   201,  -154,  -154,  -154,
    -154,  -154,  -154,  -154,  -154,  -154,  -154,  -154,  -154,  -154,
    -154,  -154,  -154,   109,     4,   307,     5,  -154,  -154,  -154,
    -154,   304,   339,   135,   -59,  -154,  -154,  -154,   109,   -77,
    -122,    52,    53,   -77,   109,    12,  -159,    13,    14,    15,
      16,    17,    18,    19,    20,    21,   277,   275,   160,   161,
     140,   141,   327,   334,     3,   244,    51,   331,   171,   278,
     280,   174,   160,   161,   246,   178,   101,    22,   284,   186,
     183,   252,   253,   281,    48,    23,   102,   260,   193,   239,
     240,    24,   343,   244,   165,    49,     4,   241,   242,   243,
     160,   161,   303,   279,   282,    49,    50,   262,   103,     4,
       4,     5,     5,    49,   244,    49,   270,   271,   197,   105,
     160,   161,    -8,    -8,    -8,    -8,    -8,    -8,    -8,    -8,
      -8,    -8,    -8,    -8,    -8,    -8,    -8,    -8,    -8,   298,
       4,   -24,    -8,    -8,    -8,    -8,    -8,  -144,   227,   -71,
     321,    -8,    -8,     4,   319,   118,   160,   161,   121,   -29,
    -110,    -8,   160,   161,   202,   203,   206,   207,   -14,   258,
     232,   233,   -19,  -164,   266,   -36,   -34,   -40,   -45,   131,
     236,   166,   138,   273,   263,   170,   139,   172,   173,   227,
       7,     7,   177,   185,   187,   274,   188,   189,   194,   349,
     190,   195,   196,   305,   322,   261,   349,   211,   224,   226,
     283,   231,   225,   204,   205,   208,   234,   235,   237,   247,
     238,   248,   254,   249,   268,   256,   227,   259,   267,   276,
     285,   286,   294,   318,   297,   295,   306,   312,   299,   300,
     301,   302,   328,   329,   263,   330,   344,   333,   337,   332,
     338,   351,   324,   352,   269,   341,   296,     0,   346,     0,
       0,   212,     0,     0,     0,     0,     0,     0,     0,   336,
       0,     0,     0,     0,     0,     0,   263,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,     0,     0,     0,     0,   213,   214,   158,
     159,   212,     0,     0,     0,   160,   161,     4,     0,     0,
       0,     0,     0,     0,   -92,     0,     0,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,     0,     0,     0,     0,   213,   214,   158,
     159,   212,     0,     0,     0,   160,   161,     4,     0,     0,
       0,     0,     0,     0,   -91,     0,     0,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,     0,     0,     0,     0,   213,   214,   158,
     159,     0,     0,     0,     0,   160,   161,     4,     0,    54,
      55,    56,    57,    58,   -90,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,     0,     0,     0,
       0,   265,     0,    24,    54,    55,    56,    57,    58,     0,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,     0,     0,     0,     0,    91,    92,    54,    55,
      56,    57,    58,     0,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,     0,     0,     0,     0,
     310,    92,    54,    55,    56,    57,    58,     0,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
       0,     0,     0,     0,   160,   161,    54,    55,    56,    57,
      58,     0,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,    86,
      87,    88,    89,    90,     0,     0,     0,     0,    95,    54,
      55,    56,    57,    58,     0,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,     0,     0,     0,
       0,    97,    54,    55,    56,    57,    58,     0,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
       0,     0,     0,     0,    99,    54,    55,    56,    57,    58,
       0,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    86,    87,
      88,    89,    90,     0,     0,     0,     0,   128,    54,    55,
      56,    57,    58,     0,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,     0,     0,     0,     0,
     257,    54,    55,    56,    57,    58,     0,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    86,    87,    88,    89,    90,     0,
       0,     0,     0,   272,    54,    55,    56,    57,    58,     0,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
      89,    90,     0,     0,     0,     0,   335,   287,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,     0,     0,     0,   288,   213,   214,
     158,   159,     0,     0,     0,     0,   160,   161,    24,     0,
       0,     0,     0,     0,     0,     0,   289,   287,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,     0,     0,     0,     0,   213,   214,
     158,   159,     0,     0,     0,     0,   160,   161,     0,     0,
       0,     0,     0,     0,     0,     0,   289,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,     0,     0,     0,     0,   213,   214,   158,
     159,     0,     0,     0,     0,   160,   161,   250,   142,   143,
     144,   145,   146,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,     0,     0,     0,     0,   213,   214,
     158,   159,     0,     0,     0,     0,   160,   161,     4,   142,
     143,   144,   145,   146,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   156,   157,     0,     0,     0,     0,     0,
       0,   158,   159,     0,     0,     0,     0,   160,   161,    24,
     142,   143,   144,   145,   146,   147,   148,   149,   150,   151,
     152,   153,   154,   155,   156,   157,     0,     0,     0,     0,
       0,     0,   158,   159,     0,     0,     0,     0,   160,   161
};

static const yytype_int16 yycheck[] =
{
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
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    -1,    -1,    -1,    -1,    45,    46,     3,     4,
       5,     6,     7,    -1,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    -1,    -1,    -1,    -1,
      45,    46,     3,     4,     5,     6,     7,    -1,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      -1,    -1,    -1,    -1,    45,    46,     3,     4,     5,     6,
       7,    -1,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    -1,    -1,    -1,    -1,    45,     3,
       4,     5,     6,     7,    -1,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    30,    31,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    -1,    -1,    -1,
      -1,    45,     3,     4,     5,     6,     7,    -1,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    40,
      -1,    -1,    -1,    -1,    45,     3,     4,     5,     6,     7,
      -1,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    -1,    -1,    -1,    -1,    45,     3,     4,
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
      39,    40,    -1,    -1,    -1,    -1,    45,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    -1,    -1,    -1,    36,    37,    38,
      39,    40,    -1,    -1,    -1,    -1,    45,    46,    47,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    55,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    -1,    -1,    -1,    -1,    37,    38,
      39,    40,    -1,    -1,    -1,    -1,    45,    46,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    55,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      30,    31,    32,    -1,    -1,    -1,    -1,    37,    38,    39,
      40,    -1,    -1,    -1,    -1,    45,    46,    47,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    30,    31,    32,    -1,    -1,    -1,    -1,    37,    38,
      39,    40,    -1,    -1,    -1,    -1,    45,    46,    47,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    30,    31,    32,    -1,    -1,    -1,    -1,    -1,
      -1,    39,    40,    -1,    -1,    -1,    -1,    45,    46,    47,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    30,    31,    32,    -1,    -1,    -1,    -1,
      -1,    -1,    39,    40,    -1,    -1,    -1,    -1,    45,    46
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
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
     152,    45,    60,    60,    68,    11,   149,    71,    13,    57,
      92,   105,    76,    77,    98,    78,    79,   104,   105,    72,
      73,   105,   121,    74,    75,    81,    80,    82,    45,   131,
     152,    57,   132,    83,    84,   148,    86,    87,    55,    58,
      68,    68,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    39,    40,
      45,    46,   142,   144,   145,    48,    52,    66,    91,   142,
      52,    66,    53,    52,    66,   103,   142,    52,    66,    32,
      39,    40,   120,   142,   119,    52,    66,    52,    52,    52,
      53,   145,   130,    66,    52,    53,    53,    43,   142,   145,
     145,   145,    62,    63,    63,    63,    62,    63,    63,    45,
      58,    53,     1,    37,    38,    68,    93,    94,   106,   107,
     108,   145,   146,   147,    53,    59,    53,    68,   133,   134,
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
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    64,    65,    66,    66,    67,    68,    68,    68,    69,
      69,    69,    71,    70,    72,    70,    70,    73,    70,    74,
      70,    70,    75,    70,    76,    70,    70,    77,    70,    78,
      70,    70,    79,    70,    80,    70,    81,    70,    70,    70,
      82,    70,    70,    83,    70,    84,    70,    70,    70,    86,
      85,    87,    85,    88,    88,    89,    91,    90,    92,    92,
      93,    93,    93,    93,    94,    94,    94,    94,    95,    95,
      96,    98,    97,    99,    99,   100,   100,   100,   101,   103,
     102,   104,   104,   105,   105,   106,   106,   107,   107,   107,
     107,   108,   108,   109,   109,   110,   110,   110,   110,   111,
     111,   111,   111,   113,   112,   114,   112,   115,   115,   115,
     115,   116,   116,   117,   119,   118,   120,   120,   120,   120,
     120,   121,   121,   122,   122,   123,   123,   124,   124,   125,
     125,   126,   126,   127,   127,   128,   128,   130,   129,   131,
     129,   132,   132,   133,   133,   133,   134,   134,   135,   135,
     135,   136,   136,   137,   137,   138,   139,   139,   140,   140,
     141,   141,   142,   142,   143,   143,   144,   144,   144,   144,
     144,   144,   144,   144,   144,   144,   144,   144,   144,   144,
     144,   145,   145,   145,   145,   145,   145,   145,   145,   145,
     145,   145,   145,   146,   146,   146,   147,   147,   147,   147,
     148,   148,   149,   149,   150,   150,   150,   150,   150,   150,
     151,   151,   152,   152,   152,   152,   152,   152,   152,   152,
     152,   152,   152,   152,   152,   152,   152,   152,   152,   152,
     152,   152,   152,   152,   152,   152,   152,   152,   152,   152,
     152,   152,   152,   152,   152,   152,   152,   152,   152
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     0,     3,     3,     4,     0,     2,
       3,     0,     0,     3,     0,     3,     1,     0,     3,     0,
       3,     1,     0,     3,     0,     3,     1,     0,     3,     0,
       3,     1,     0,     3,     0,     3,     0,     3,     1,     1,
       0,     3,     1,     0,     3,     0,     3,     1,     2,     0,
       6,     0,     6,     2,     2,     1,     0,     6,     2,     0,
       4,     4,     3,     1,     4,     4,     3,     1,     2,     2,
       1,     0,     5,     2,     2,     5,     5,     1,     1,     0,
       6,     2,     0,     1,     1,     1,     3,     2,     2,     1,
       2,     1,     0,     2,     4,     1,     3,     2,     1,     3,
       4,     3,     4,     0,     5,     0,     5,     4,     2,     3,
       0,     2,     2,     1,     0,     6,     3,     1,     1,     1,
       1,     2,     0,     3,     1,     1,     1,     4,     2,     6,
       6,     9,     9,     2,     1,     2,     2,     0,     6,     0,
       5,     2,     0,     1,     2,     0,     3,     1,     2,     4,
       2,     1,     1,     1,     0,     2,     1,     3,     1,     0,
       2,     0,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     2,     2,     2,     2,     2,     1,     1,     1,     1,
       1,     2,     2,     2,     2,     1,     2,     2,     1,     2,
       2,     1,     3,     1,     1,     1,     1,     1,     1,     1,
       6,     5,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1
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
#line 218 "src/Slice/Grammar.y"
{
    StringListTokPtr metadata = StringListTokPtr::dynamicCast(yyvsp[-1]);
    convertMetadata(metadata);
    yyval = metadata;
}
#line 1877 "src/Slice/Grammar.cpp"
    break;

  case 6: /* local_metadata: ICE_LOCAL_METADATA_OPEN string_list ICE_LOCAL_METADATA_CLOSE  */
#line 229 "src/Slice/Grammar.y"
{
    StringListTokPtr metadata = StringListTokPtr::dynamicCast(yyvsp[-1]);
    convertMetadata(metadata);
    yyval = metadata;
}
#line 1887 "src/Slice/Grammar.cpp"
    break;

  case 7: /* local_metadata: local_metadata ICE_LOCAL_METADATA_OPEN string_list ICE_LOCAL_METADATA_CLOSE  */
#line 235 "src/Slice/Grammar.y"
{
    StringListTokPtr metadata1 = StringListTokPtr::dynamicCast(yyvsp[-3]);
    StringListTokPtr metadata2 = StringListTokPtr::dynamicCast(yyvsp[-1]);
    metadata1->v.splice(metadata1->v.end(), metadata2->v);

    convertMetadata(metadata1);
    yyval = metadata1;
}
#line 1900 "src/Slice/Grammar.cpp"
    break;

  case 8: /* local_metadata: %empty  */
#line 244 "src/Slice/Grammar.y"
{
    yyval = new StringListTok;
}
#line 1908 "src/Slice/Grammar.cpp"
    break;

  case 9: /* definitions: definitions file_metadata  */
#line 253 "src/Slice/Grammar.y"
{
    StringListTokPtr metadata = StringListTokPtr::dynamicCast(yyvsp[0]);
    if(!metadata->v.empty())
    {
        unit->addFileMetadata(metadata->v);
    }
}
#line 1920 "src/Slice/Grammar.cpp"
    break;

  case 10: /* definitions: definitions local_metadata definition  */
#line 261 "src/Slice/Grammar.y"
{
    StringListTokPtr metadata = StringListTokPtr::dynamicCast(yyvsp[-1]);
    ContainedPtr contained = ContainedPtr::dynamicCast(yyvsp[0]);
    if(contained && !metadata->v.empty())
    {
        contained->setMetadata(metadata->v);
    }
}
#line 1933 "src/Slice/Grammar.cpp"
    break;

  case 12: /* $@1: %empty  */
#line 276 "src/Slice/Grammar.y"
{
    assert(yyvsp[0] == 0 || ModulePtr::dynamicCast(yyvsp[0]));
}
#line 1941 "src/Slice/Grammar.cpp"
    break;

  case 14: /* $@2: %empty  */
#line 281 "src/Slice/Grammar.y"
{
    assert(yyvsp[0] == 0 || ClassDeclPtr::dynamicCast(yyvsp[0]));
}
#line 1949 "src/Slice/Grammar.cpp"
    break;

  case 16: /* definition: class_decl  */
#line 286 "src/Slice/Grammar.y"
{
    unit->error("`;' missing after class forward declaration");
}
#line 1957 "src/Slice/Grammar.cpp"
    break;

  case 17: /* $@3: %empty  */
#line 290 "src/Slice/Grammar.y"
{
    assert(yyvsp[0] == 0 || ClassDefPtr::dynamicCast(yyvsp[0]));
}
#line 1965 "src/Slice/Grammar.cpp"
    break;

  case 19: /* $@4: %empty  */
#line 295 "src/Slice/Grammar.y"
{
    assert(yyvsp[0] == 0 || InterfaceDeclPtr::dynamicCast(yyvsp[0]));
}
#line 1973 "src/Slice/Grammar.cpp"
    break;

  case 21: /* definition: interface_decl  */
#line 300 "src/Slice/Grammar.y"
{
    unit->error("`;' missing after interface forward declaration");
}
#line 1981 "src/Slice/Grammar.cpp"
    break;

  case 22: /* $@5: %empty  */
#line 304 "src/Slice/Grammar.y"
{
    assert(yyvsp[0] == 0 || InterfaceDefPtr::dynamicCast(yyvsp[0]));
}
#line 1989 "src/Slice/Grammar.cpp"
    break;

  case 24: /* $@6: %empty  */
#line 309 "src/Slice/Grammar.y"
{
    assert(yyvsp[0] == 0);
}
#line 1997 "src/Slice/Grammar.cpp"
    break;

  case 26: /* definition: exception_decl  */
#line 314 "src/Slice/Grammar.y"
{
    unit->error("`;' missing after exception forward declaration");
}
#line 2005 "src/Slice/Grammar.cpp"
    break;

  case 27: /* $@7: %empty  */
#line 318 "src/Slice/Grammar.y"
{
    assert(yyvsp[0] == 0 || ExceptionPtr::dynamicCast(yyvsp[0]));
}
#line 2013 "src/Slice/Grammar.cpp"
    break;

  case 29: /* $@8: %empty  */
#line 323 "src/Slice/Grammar.y"
{
    assert(yyvsp[0] == 0);
}
#line 2021 "src/Slice/Grammar.cpp"
    break;

  case 31: /* definition: struct_decl  */
#line 328 "src/Slice/Grammar.y"
{
    unit->error("`;' missing after struct forward declaration");
}
#line 2029 "src/Slice/Grammar.cpp"
    break;

  case 32: /* $@9: %empty  */
#line 332 "src/Slice/Grammar.y"
{
    assert(yyvsp[0] == 0 || StructPtr::dynamicCast(yyvsp[0]));
}
#line 2037 "src/Slice/Grammar.cpp"
    break;

  case 34: /* $@10: %empty  */
#line 337 "src/Slice/Grammar.y"
{
    assert(yyvsp[0] == 0 || SequencePtr::dynamicCast(yyvsp[0]));
}
#line 2045 "src/Slice/Grammar.cpp"
    break;

  case 36: /* $@11: %empty  */
#line 342 "src/Slice/Grammar.y"
{
    assert(yyvsp[0] == 0 || TypeAliasPtr::dynamicCast(yyvsp[0]));
}
#line 2053 "src/Slice/Grammar.cpp"
    break;

  case 38: /* definition: type_alias_def  */
#line 347 "src/Slice/Grammar.y"
{
    unit->error("`;' missing after type-alias");
}
#line 2061 "src/Slice/Grammar.cpp"
    break;

  case 39: /* definition: sequence_def  */
#line 351 "src/Slice/Grammar.y"
{
    unit->error("`;' missing after sequence definition");
}
#line 2069 "src/Slice/Grammar.cpp"
    break;

  case 40: /* $@12: %empty  */
#line 355 "src/Slice/Grammar.y"
{
    assert(yyvsp[0] == 0 || DictionaryPtr::dynamicCast(yyvsp[0]));
}
#line 2077 "src/Slice/Grammar.cpp"
    break;

  case 42: /* definition: dictionary_def  */
#line 360 "src/Slice/Grammar.y"
{
    unit->error("`;' missing after dictionary definition");
}
#line 2085 "src/Slice/Grammar.cpp"
    break;

  case 43: /* $@13: %empty  */
#line 364 "src/Slice/Grammar.y"
{
    assert(yyvsp[0] == 0 || EnumPtr::dynamicCast(yyvsp[0]));
}
#line 2093 "src/Slice/Grammar.cpp"
    break;

  case 45: /* $@14: %empty  */
#line 369 "src/Slice/Grammar.y"
{
    assert(yyvsp[0] == 0 || ConstPtr::dynamicCast(yyvsp[0]));
}
#line 2101 "src/Slice/Grammar.cpp"
    break;

  case 47: /* definition: const_def  */
#line 374 "src/Slice/Grammar.y"
{
    unit->error("`;' missing after const definition");
}
#line 2109 "src/Slice/Grammar.cpp"
    break;

  case 48: /* definition: error ';'  */
#line 378 "src/Slice/Grammar.y"
{
    yyerrok;
}
#line 2117 "src/Slice/Grammar.cpp"
    break;

  case 49: /* @15: %empty  */
#line 387 "src/Slice/Grammar.y"
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
#line 2147 "src/Slice/Grammar.cpp"
    break;

  case 50: /* module_def: ICE_MODULE ICE_IDENTIFIER @15 '{' definitions '}'  */
#line 413 "src/Slice/Grammar.y"
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
#line 2163 "src/Slice/Grammar.cpp"
    break;

  case 51: /* @16: %empty  */
#line 425 "src/Slice/Grammar.y"
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
#line 2222 "src/Slice/Grammar.cpp"
    break;

  case 52: /* module_def: ICE_MODULE ICE_SCOPED_IDENTIFIER @16 '{' definitions '}'  */
#line 480 "src/Slice/Grammar.y"
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
#line 2244 "src/Slice/Grammar.cpp"
    break;

  case 53: /* exception_id: ICE_EXCEPTION ICE_IDENTIFIER  */
#line 503 "src/Slice/Grammar.y"
{
    yyval = yyvsp[0];
}
#line 2252 "src/Slice/Grammar.cpp"
    break;

  case 54: /* exception_id: ICE_EXCEPTION keyword  */
#line 507 "src/Slice/Grammar.y"
{
    StringTokPtr ident = StringTokPtr::dynamicCast(yyvsp[0]);
    unit->error("keyword `" + ident->v + "' cannot be used as exception name");
    yyval = yyvsp[0]; // Dummy
}
#line 2262 "src/Slice/Grammar.cpp"
    break;

  case 55: /* exception_decl: exception_id  */
#line 518 "src/Slice/Grammar.y"
{
    unit->error("exceptions cannot be forward declared");
    yyval = 0;
}
#line 2271 "src/Slice/Grammar.cpp"
    break;

  case 56: /* @17: %empty  */
#line 528 "src/Slice/Grammar.y"
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
#line 2288 "src/Slice/Grammar.cpp"
    break;

  case 57: /* exception_def: exception_id exception_extends @17 '{' data_members '}'  */
#line 541 "src/Slice/Grammar.y"
{
    if(yyvsp[-3])
    {
        unit->popContainer();
    }
    yyval = yyvsp[-3];
}
#line 2300 "src/Slice/Grammar.cpp"
    break;

  case 58: /* exception_extends: extends scoped_name  */
#line 554 "src/Slice/Grammar.y"
{
    StringTokPtr scoped = StringTokPtr::dynamicCast(yyvsp[0]);
    ContainerPtr cont = unit->currentContainer();
    ContainedPtr contained = cont->lookupException(scoped->v);
    cont->checkIntroduced(scoped->v);
    yyval = contained;
}
#line 2312 "src/Slice/Grammar.cpp"
    break;

  case 59: /* exception_extends: %empty  */
#line 562 "src/Slice/Grammar.y"
{
    yyval = 0;
}
#line 2320 "src/Slice/Grammar.cpp"
    break;

  case 60: /* tag: ICE_TAG '(' ICE_INTEGER_LITERAL ')'  */
#line 571 "src/Slice/Grammar.y"
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
#line 2342 "src/Slice/Grammar.cpp"
    break;

  case 61: /* tag: ICE_TAG '(' scoped_name ')'  */
#line 589 "src/Slice/Grammar.y"
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
#line 2420 "src/Slice/Grammar.cpp"
    break;

  case 62: /* tag: ICE_TAG '(' ')'  */
#line 663 "src/Slice/Grammar.y"
{
    unit->error("missing tag");
    TaggedDefTokPtr m = new TaggedDefTok; // Dummy
    yyval = m;
}
#line 2430 "src/Slice/Grammar.cpp"
    break;

  case 63: /* tag: ICE_TAG  */
#line 669 "src/Slice/Grammar.y"
{
    unit->error("missing tag");
    TaggedDefTokPtr m = new TaggedDefTok; // Dummy
    yyval = m;
}
#line 2440 "src/Slice/Grammar.cpp"
    break;

  case 64: /* optional: ICE_OPTIONAL '(' ICE_INTEGER_LITERAL ')'  */
#line 680 "src/Slice/Grammar.y"
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
#line 2466 "src/Slice/Grammar.cpp"
    break;

  case 65: /* optional: ICE_OPTIONAL '(' scoped_name ')'  */
#line 702 "src/Slice/Grammar.y"
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
#line 2548 "src/Slice/Grammar.cpp"
    break;

  case 66: /* optional: ICE_OPTIONAL '(' ')'  */
#line 780 "src/Slice/Grammar.y"
{
    if (!unit->compatMode())
    {
        unit->warning(Deprecated, string("The `optional' keyword is deprecated, use `tag' instead"));
    }
    unit->error("missing tag");
    TaggedDefTokPtr m = new TaggedDefTok; // Dummy
    yyval = m;
}
#line 2562 "src/Slice/Grammar.cpp"
    break;

  case 67: /* optional: ICE_OPTIONAL  */
#line 790 "src/Slice/Grammar.y"
{
    if (!unit->compatMode())
    {
        unit->warning(Deprecated, string("The `optional' keyword is deprecated, use `tag' instead"));
    }
    unit->error("missing tag");
    TaggedDefTokPtr m = new TaggedDefTok; // Dummy
    yyval = m;
}
#line 2576 "src/Slice/Grammar.cpp"
    break;

  case 68: /* struct_id: ICE_STRUCT ICE_IDENTIFIER  */
#line 805 "src/Slice/Grammar.y"
{
    yyval = yyvsp[0];
}
#line 2584 "src/Slice/Grammar.cpp"
    break;

  case 69: /* struct_id: ICE_STRUCT keyword  */
#line 809 "src/Slice/Grammar.y"
{
    StringTokPtr ident = StringTokPtr::dynamicCast(yyvsp[0]);
    unit->error("keyword `" + ident->v + "' cannot be used as struct name");
    yyval = yyvsp[0]; // Dummy
}
#line 2594 "src/Slice/Grammar.cpp"
    break;

  case 70: /* struct_decl: struct_id  */
#line 820 "src/Slice/Grammar.y"
{
    unit->error("structs cannot be forward declared");
    yyval = 0; // Dummy
}
#line 2603 "src/Slice/Grammar.cpp"
    break;

  case 71: /* @18: %empty  */
#line 830 "src/Slice/Grammar.y"
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
#line 2625 "src/Slice/Grammar.cpp"
    break;

  case 72: /* struct_def: struct_id @18 '{' data_members '}'  */
#line 848 "src/Slice/Grammar.y"
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
#line 2647 "src/Slice/Grammar.cpp"
    break;

  case 73: /* class_name: ICE_CLASS ICE_IDENTIFIER  */
#line 871 "src/Slice/Grammar.y"
{
    yyval = yyvsp[0];
}
#line 2655 "src/Slice/Grammar.cpp"
    break;

  case 74: /* class_name: ICE_CLASS keyword  */
#line 875 "src/Slice/Grammar.y"
{
    StringTokPtr ident = StringTokPtr::dynamicCast(yyvsp[0]);
    unit->error("keyword `" + ident->v + "' cannot be used as class name");
    yyval = yyvsp[0]; // Dummy
}
#line 2665 "src/Slice/Grammar.cpp"
    break;

  case 75: /* class_id: ICE_CLASS unscoped_name '(' ICE_INTEGER_LITERAL ')'  */
#line 886 "src/Slice/Grammar.y"
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
#line 2694 "src/Slice/Grammar.cpp"
    break;

  case 76: /* class_id: ICE_CLASS unscoped_name '(' scoped_name ')'  */
#line 911 "src/Slice/Grammar.y"
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
#line 2788 "src/Slice/Grammar.cpp"
    break;

  case 77: /* class_id: class_name  */
#line 1001 "src/Slice/Grammar.y"
{
    ClassIdTokPtr classId = new ClassIdTok();
    classId->v = StringTokPtr::dynamicCast(yyvsp[0])->v;
    classId->t = -1;
    yyval = classId;
}
#line 2799 "src/Slice/Grammar.cpp"
    break;

  case 78: /* class_decl: class_name  */
#line 1013 "src/Slice/Grammar.y"
{
    StringTokPtr ident = StringTokPtr::dynamicCast(yyvsp[0]);
    ModulePtr cont = unit->currentModule();
    ClassDeclPtr cl = cont->createClassDecl(ident->v);
    yyval = cl;
}
#line 2810 "src/Slice/Grammar.cpp"
    break;

  case 79: /* @19: %empty  */
#line 1025 "src/Slice/Grammar.y"
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
#line 2831 "src/Slice/Grammar.cpp"
    break;

  case 80: /* class_def: class_id class_extends @19 '{' data_members '}'  */
#line 1042 "src/Slice/Grammar.y"
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
#line 2847 "src/Slice/Grammar.cpp"
    break;

  case 81: /* class_extends: extends scoped_name  */
#line 1059 "src/Slice/Grammar.y"
{
    StringTokPtr scoped = StringTokPtr::dynamicCast(yyvsp[0]);
    ContainerPtr cont = unit->currentContainer();
    TypeList types = cont->lookupType(scoped->v);
    yyval = 0;
    if(!types.empty())
    {
        ClassDeclPtr cl = ClassDeclPtr::dynamicCast(types.front());
        if(!cl)
        {
            string msg = "`";
            msg += scoped->v;
            msg += "' is not a class";
            unit->error(msg);
        }
        else
        {
            ClassDefPtr def = cl->definition();
            if(!def)
            {
                string msg = "`";
                msg += scoped->v;
                msg += "' has been declared but not defined";
                unit->error(msg);
            }
            else
            {
                cont->checkIntroduced(scoped->v);
                yyval = def;
            }
        }
    }
}
#line 2885 "src/Slice/Grammar.cpp"
    break;

  case 82: /* class_extends: %empty  */
#line 1093 "src/Slice/Grammar.y"
{
    yyval = 0;
}
#line 2893 "src/Slice/Grammar.cpp"
    break;

  case 85: /* data_member: member  */
#line 1109 "src/Slice/Grammar.y"
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
#line 2912 "src/Slice/Grammar.cpp"
    break;

  case 86: /* data_member: member '=' const_initializer  */
#line 1124 "src/Slice/Grammar.y"
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
#line 2933 "src/Slice/Grammar.cpp"
    break;

  case 89: /* data_member_list: data_member  */
#line 1148 "src/Slice/Grammar.y"
{
    unit->error("`;' missing after definition");
}
#line 2941 "src/Slice/Grammar.cpp"
    break;

  case 93: /* return_tuple: out_qualifier member  */
#line 1165 "src/Slice/Grammar.y"
{
    TaggedDefTokPtr returnMember = TaggedDefTokPtr::dynamicCast(yyvsp[0]);
    if (BoolTokPtr::dynamicCast(yyvsp[-1])->v)
    {
        unit->error("`" + returnMember->name + "': return members cannot be marked as out");
    }

    TaggedDefListTokPtr returnMembers = new TaggedDefListTok();
    returnMembers->v.push_back(returnMember);
    yyval = returnMembers;
}
#line 2957 "src/Slice/Grammar.cpp"
    break;

  case 94: /* return_tuple: return_tuple ',' out_qualifier member  */
#line 1177 "src/Slice/Grammar.y"
{
    TaggedDefTokPtr returnMember = TaggedDefTokPtr::dynamicCast(yyvsp[0]);
    if (BoolTokPtr::dynamicCast(yyvsp[-1])->v)
    {
        unit->error("`" + returnMember->name + "': return members cannot be marked as out");
    }

    TaggedDefListTokPtr returnMembers = TaggedDefListTokPtr::dynamicCast(yyvsp[-3]);
    returnMembers->v.push_back(returnMember);
    yyval = returnMembers;
}
#line 2973 "src/Slice/Grammar.cpp"
    break;

  case 95: /* return_type: tagged_type  */
#line 1193 "src/Slice/Grammar.y"
{
    TaggedDefTokPtr returnMember = TaggedDefTokPtr::dynamicCast(yyvsp[0]);
    // For unnamed return types we infer their name to be 'returnValue'.
    returnMember->name = "returnValue";

    if (returnMember->isTagged)
    {
        checkForTaggableType(returnMember->type);
    }

    TaggedDefListTokPtr returnMembers = new TaggedDefListTok();
    returnMembers->v.push_back(returnMember);
    yyval = returnMembers;
}
#line 2992 "src/Slice/Grammar.cpp"
    break;

  case 96: /* return_type: '(' return_tuple ')'  */
#line 1208 "src/Slice/Grammar.y"
{
    TaggedDefListTokPtr returnMembers = TaggedDefListTokPtr::dynamicCast(yyvsp[-1]);
    if (returnMembers->v.size() == 1)
    {
        unit->error("return tuples must contain at least 2 elements");
    }
    yyval = yyvsp[-1];
}
#line 3005 "src/Slice/Grammar.cpp"
    break;

  case 97: /* return_type: '(' ')'  */
#line 1217 "src/Slice/Grammar.y"
{
    unit->error("return tuples must contain at least 2 elements");
    yyval = new TaggedDefListTok();
}
#line 3014 "src/Slice/Grammar.cpp"
    break;

  case 98: /* return_type: ICE_VOID  */
#line 1222 "src/Slice/Grammar.y"
{
    yyval = new TaggedDefListTok();
}
#line 3022 "src/Slice/Grammar.cpp"
    break;

  case 99: /* operation_preamble: return_type unscoped_name '('  */
#line 1231 "src/Slice/Grammar.y"
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
                                                     returnMember->tag);
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
#line 3061 "src/Slice/Grammar.cpp"
    break;

  case 100: /* operation_preamble: ICE_IDEMPOTENT return_type unscoped_name '('  */
#line 1266 "src/Slice/Grammar.y"
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
                                                     returnMember->tag);
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
#line 3100 "src/Slice/Grammar.cpp"
    break;

  case 101: /* operation_preamble: return_type keyword '('  */
#line 1301 "src/Slice/Grammar.y"
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
                                                     returnMember->tag);
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
#line 3138 "src/Slice/Grammar.cpp"
    break;

  case 102: /* operation_preamble: ICE_IDEMPOTENT return_type keyword '('  */
#line 1335 "src/Slice/Grammar.y"
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
                                                     returnMember->tag);
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
#line 3176 "src/Slice/Grammar.cpp"
    break;

  case 103: /* @20: %empty  */
#line 1374 "src/Slice/Grammar.y"
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
#line 3192 "src/Slice/Grammar.cpp"
    break;

  case 104: /* operation: operation_preamble parameters ')' @20 throws  */
#line 1386 "src/Slice/Grammar.y"
{
    OperationPtr op = OperationPtr::dynamicCast(yyvsp[-1]);
    ExceptionListTokPtr el = ExceptionListTokPtr::dynamicCast(yyvsp[0]);
    assert(el);
    if(op)
    {
        op->setExceptionList(el->v);
    }
}
#line 3206 "src/Slice/Grammar.cpp"
    break;

  case 105: /* @21: %empty  */
#line 1396 "src/Slice/Grammar.y"
{
    if(yyvsp[-2])
    {
        unit->popContainer();
    }
    yyerrok;
}
#line 3218 "src/Slice/Grammar.cpp"
    break;

  case 106: /* operation: operation_preamble error ')' @21 throws  */
#line 1404 "src/Slice/Grammar.y"
{
    OperationPtr op = OperationPtr::dynamicCast(yyvsp[-1]);
    ExceptionListTokPtr el = ExceptionListTokPtr::dynamicCast(yyvsp[0]);
    assert(el);
    if(op)
    {
        op->setExceptionList(el->v); // Dummy
    }
}
#line 3232 "src/Slice/Grammar.cpp"
    break;

  case 107: /* operation_list: local_metadata operation ';' operation_list  */
#line 1419 "src/Slice/Grammar.y"
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
            operation->returnType().front()->setMetadata(metadata->v);
        }
    }
}
#line 3254 "src/Slice/Grammar.cpp"
    break;

  case 108: /* operation_list: local_metadata operation  */
#line 1437 "src/Slice/Grammar.y"
{
    unit->error("`;' missing after definition");
}
#line 3262 "src/Slice/Grammar.cpp"
    break;

  case 111: /* interface_id: ICE_INTERFACE ICE_IDENTIFIER  */
#line 1448 "src/Slice/Grammar.y"
{
    yyval = yyvsp[0];
}
#line 3270 "src/Slice/Grammar.cpp"
    break;

  case 112: /* interface_id: ICE_INTERFACE keyword  */
#line 1452 "src/Slice/Grammar.y"
{
    StringTokPtr ident = StringTokPtr::dynamicCast(yyvsp[0]);
    unit->error("keyword `" + ident->v + "' cannot be used as interface name");
    yyval = yyvsp[0]; // Dummy
}
#line 3280 "src/Slice/Grammar.cpp"
    break;

  case 113: /* interface_decl: interface_id  */
#line 1463 "src/Slice/Grammar.y"
{
    StringTokPtr ident = StringTokPtr::dynamicCast(yyvsp[0]);
    ModulePtr cont = unit->currentModule();
    InterfaceDeclPtr cl = cont->createInterfaceDecl(ident->v);
    cont->checkIntroduced(ident->v, cl);
    yyval = cl;
}
#line 3292 "src/Slice/Grammar.cpp"
    break;

  case 114: /* @22: %empty  */
#line 1476 "src/Slice/Grammar.y"
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
#line 3313 "src/Slice/Grammar.cpp"
    break;

  case 115: /* interface_def: interface_id interface_extends @22 '{' operation_list '}'  */
#line 1493 "src/Slice/Grammar.y"
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
#line 3329 "src/Slice/Grammar.cpp"
    break;

  case 116: /* interface_list: scoped_name ',' interface_list  */
#line 1510 "src/Slice/Grammar.y"
{
    InterfaceListTokPtr intfs = InterfaceListTokPtr::dynamicCast(yyvsp[0]);
    StringTokPtr scoped = StringTokPtr::dynamicCast(yyvsp[-2]);
    ContainerPtr cont = unit->currentContainer();
    TypeList types = cont->lookupType(scoped->v);
    if(!types.empty())
    {
        InterfaceDeclPtr interface = InterfaceDeclPtr::dynamicCast(types.front());
        if(!interface)
        {
            string msg = "`";
            msg += scoped->v;
            msg += "' is not an interface";
            unit->error(msg);
        }
        else
        {
            InterfaceDefPtr def = interface->definition();
            if(!def)
            {
                string msg = "`";
                msg += scoped->v;
                msg += "' has been declared but not defined";
                unit->error(msg);
            }
            else
            {
                cont->checkIntroduced(scoped->v);
                intfs->v.push_front(def);
            }
        }
    }
    yyval = intfs;
}
#line 3368 "src/Slice/Grammar.cpp"
    break;

  case 117: /* interface_list: scoped_name  */
#line 1545 "src/Slice/Grammar.y"
{
    InterfaceListTokPtr intfs = new InterfaceListTok;
    StringTokPtr scoped = StringTokPtr::dynamicCast(yyvsp[0]);
    ContainerPtr cont = unit->currentContainer();
    TypeList types = cont->lookupType(scoped->v);
    if(!types.empty())
    {
        InterfaceDeclPtr interface = InterfaceDeclPtr::dynamicCast(types.front());
        if(!interface)
        {
            string msg = "`";
            msg += scoped->v;
            msg += "' is not an interface";
            unit->error(msg); // $$ is a dummy
        }
        else
        {
            InterfaceDefPtr def = interface->definition();
            if(!def)
            {
                string msg = "`";
                msg += scoped->v;
                msg += "' has been declared but not defined";
                unit->error(msg); // $$ is a dummy
            }
            else
            {
                cont->checkIntroduced(scoped->v);
                intfs->v.push_front(def);
            }
        }
    }
    yyval = intfs;
}
#line 3407 "src/Slice/Grammar.cpp"
    break;

  case 118: /* interface_list: ICE_OBJECT  */
#line 1580 "src/Slice/Grammar.y"
{
    unit->error("illegal inheritance from type Object");
    yyval = new InterfaceListTok; // Dummy
}
#line 3416 "src/Slice/Grammar.cpp"
    break;

  case 119: /* interface_list: ICE_ANYCLASS  */
#line 1585 "src/Slice/Grammar.y"
{
    unit->error("illegal inheritance from type AnyClass");
    yyval = new ClassListTok; // Dummy
}
#line 3425 "src/Slice/Grammar.cpp"
    break;

  case 120: /* interface_list: ICE_VALUE  */
#line 1590 "src/Slice/Grammar.y"
{
    if (!unit->compatMode())
    {
        unit->warning(Deprecated, "the `Value' keyword is deprecated, use `AnyClass' instead");
    }
    unit->error("illegal inheritance from type Value");
    yyval = new ClassListTok; // Dummy
}
#line 3438 "src/Slice/Grammar.cpp"
    break;

  case 121: /* interface_extends: extends interface_list  */
#line 1604 "src/Slice/Grammar.y"
{
    yyval = yyvsp[0];
}
#line 3446 "src/Slice/Grammar.cpp"
    break;

  case 122: /* interface_extends: %empty  */
#line 1608 "src/Slice/Grammar.y"
{
    yyval = new InterfaceListTok;
}
#line 3454 "src/Slice/Grammar.cpp"
    break;

  case 123: /* exception_list: exception ',' exception_list  */
#line 1617 "src/Slice/Grammar.y"
{
    ExceptionPtr exception = ExceptionPtr::dynamicCast(yyvsp[-2]);
    ExceptionListTokPtr exceptionList = ExceptionListTokPtr::dynamicCast(yyvsp[0]);
    exceptionList->v.push_front(exception);
    yyval = exceptionList;
}
#line 3465 "src/Slice/Grammar.cpp"
    break;

  case 124: /* exception_list: exception  */
#line 1624 "src/Slice/Grammar.y"
{
    ExceptionPtr exception = ExceptionPtr::dynamicCast(yyvsp[0]);
    ExceptionListTokPtr exceptionList = new ExceptionListTok;
    exceptionList->v.push_front(exception);
    yyval = exceptionList;
}
#line 3476 "src/Slice/Grammar.cpp"
    break;

  case 125: /* exception: scoped_name  */
#line 1636 "src/Slice/Grammar.y"
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
#line 3492 "src/Slice/Grammar.cpp"
    break;

  case 126: /* exception: keyword  */
#line 1648 "src/Slice/Grammar.y"
{
    StringTokPtr ident = StringTokPtr::dynamicCast(yyvsp[0]);
    unit->error("keyword `" + ident->v + "' cannot be used as exception name");
    yyval = unit->currentModule()->createException(IceUtil::generateUUID(), 0, Dummy); // Dummy
}
#line 3502 "src/Slice/Grammar.cpp"
    break;

  case 127: /* type_alias_def: ICE_USING ICE_IDENTIFIER '=' type  */
#line 1659 "src/Slice/Grammar.y"
{
    StringTokPtr ident = StringTokPtr::dynamicCast(yyvsp[-2]);
    TypePtr type = TypePtr::dynamicCast(yyvsp[0]);

    ModulePtr cont = unit->currentModule();
    yyval = cont->createTypeAlias(ident->v, type);
}
#line 3514 "src/Slice/Grammar.cpp"
    break;

  case 128: /* type_alias_def: ICE_USING ICE_IDENTIFIER  */
#line 1667 "src/Slice/Grammar.y"
{
    StringTokPtr ident = StringTokPtr::dynamicCast(yyvsp[0]);
    unit->error("missing underlying type");
    yyval = nullptr;
}
#line 3524 "src/Slice/Grammar.cpp"
    break;

  case 129: /* sequence_def: ICE_SEQUENCE '<' local_metadata type '>' ICE_IDENTIFIER  */
#line 1677 "src/Slice/Grammar.y"
{
    StringTokPtr ident = StringTokPtr::dynamicCast(yyvsp[0]);
    StringListTokPtr metadata = StringListTokPtr::dynamicCast(yyvsp[-3]);
    TypePtr type = TypePtr::dynamicCast(yyvsp[-2]);
    ModulePtr cont = unit->currentModule();
    yyval = cont->createSequence(ident->v, type, metadata->v);
}
#line 3536 "src/Slice/Grammar.cpp"
    break;

  case 130: /* sequence_def: ICE_SEQUENCE '<' local_metadata type '>' keyword  */
#line 1685 "src/Slice/Grammar.y"
{
    StringTokPtr ident = StringTokPtr::dynamicCast(yyvsp[0]);
    StringListTokPtr metadata = StringListTokPtr::dynamicCast(yyvsp[-3]);
    TypePtr type = TypePtr::dynamicCast(yyvsp[-2]);
    ModulePtr cont = unit->currentModule();
    yyval = cont->createSequence(ident->v, type, metadata->v); // Dummy
    unit->error("keyword `" + ident->v + "' cannot be used as sequence name");
}
#line 3549 "src/Slice/Grammar.cpp"
    break;

  case 131: /* dictionary_def: ICE_DICTIONARY '<' local_metadata type ',' local_metadata type '>' ICE_IDENTIFIER  */
#line 1699 "src/Slice/Grammar.y"
{
    StringTokPtr ident = StringTokPtr::dynamicCast(yyvsp[0]);
    StringListTokPtr keyMetadata = StringListTokPtr::dynamicCast(yyvsp[-6]);
    TypePtr keyType = TypePtr::dynamicCast(yyvsp[-5]);
    StringListTokPtr valueMetadata = StringListTokPtr::dynamicCast(yyvsp[-3]);
    TypePtr valueType = TypePtr::dynamicCast(yyvsp[-2]);
    ModulePtr cont = unit->currentModule();
    yyval = cont->createDictionary(ident->v, keyType, keyMetadata->v, valueType, valueMetadata->v);
}
#line 3563 "src/Slice/Grammar.cpp"
    break;

  case 132: /* dictionary_def: ICE_DICTIONARY '<' local_metadata type ',' local_metadata type '>' keyword  */
#line 1709 "src/Slice/Grammar.y"
{
    StringTokPtr ident = StringTokPtr::dynamicCast(yyvsp[0]);
    StringListTokPtr keyMetadata = StringListTokPtr::dynamicCast(yyvsp[-6]);
    TypePtr keyType = TypePtr::dynamicCast(yyvsp[-5]);
    StringListTokPtr valueMetadata = StringListTokPtr::dynamicCast(yyvsp[-3]);
    TypePtr valueType = TypePtr::dynamicCast(yyvsp[-2]);
    ModulePtr cont = unit->currentModule();
    yyval = cont->createDictionary(ident->v, keyType, keyMetadata->v, valueType, valueMetadata->v); // Dummy
    unit->error("keyword `" + ident->v + "' cannot be used as dictionary name");
}
#line 3578 "src/Slice/Grammar.cpp"
    break;

  case 133: /* enum_start: ICE_UNCHECKED ICE_ENUM  */
#line 1725 "src/Slice/Grammar.y"
{
    yyval = new BoolTok(true);
}
#line 3586 "src/Slice/Grammar.cpp"
    break;

  case 134: /* enum_start: ICE_ENUM  */
#line 1729 "src/Slice/Grammar.y"
{
    yyval = new BoolTok(false);
}
#line 3594 "src/Slice/Grammar.cpp"
    break;

  case 135: /* enum_id: enum_start ICE_IDENTIFIER  */
#line 1738 "src/Slice/Grammar.y"
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
#line 3614 "src/Slice/Grammar.cpp"
    break;

  case 136: /* enum_id: enum_start keyword  */
#line 1754 "src/Slice/Grammar.y"
{
    bool unchecked = BoolTokPtr::dynamicCast(yyvsp[-1])->v;
    StringTokPtr ident = StringTokPtr::dynamicCast(yyvsp[0]);
    ModulePtr cont = unit->currentModule();
    unit->error("keyword `" + ident->v + "' cannot be used as enumeration name");
    yyval = cont->createEnum(IceUtil::generateUUID(), unchecked, Dummy);
}
#line 3626 "src/Slice/Grammar.cpp"
    break;

  case 137: /* @23: %empty  */
#line 1767 "src/Slice/Grammar.y"
{
    EnumPtr en = EnumPtr::dynamicCast(yyvsp[-1]);
    en->initUnderlying(TypePtr::dynamicCast(yyvsp[0]));
    unit->pushContainer(en);
    yyval = en;
}
#line 3637 "src/Slice/Grammar.cpp"
    break;

  case 138: /* enum_def: enum_id enum_underlying @23 '{' enumerator_list_or_empty '}'  */
#line 1774 "src/Slice/Grammar.y"
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
#line 3654 "src/Slice/Grammar.cpp"
    break;

  case 139: /* @24: %empty  */
#line 1787 "src/Slice/Grammar.y"
{
    bool unchecked = BoolTokPtr::dynamicCast(yyvsp[0])->v;
    unit->error("missing enumeration name");
    ModulePtr cont = unit->currentModule();
    EnumPtr en = cont->createEnum(IceUtil::generateUUID(), unchecked, Dummy);
    unit->pushContainer(en);
    yyval = en;
}
#line 3667 "src/Slice/Grammar.cpp"
    break;

  case 140: /* enum_def: enum_start @24 '{' enumerator_list_or_empty '}'  */
#line 1796 "src/Slice/Grammar.y"
{
    unit->popContainer();
    yyval = yyvsp[-4];
}
#line 3676 "src/Slice/Grammar.cpp"
    break;

  case 141: /* enum_underlying: ':' type  */
#line 1806 "src/Slice/Grammar.y"
{
    yyval = yyvsp[0];
}
#line 3684 "src/Slice/Grammar.cpp"
    break;

  case 142: /* enum_underlying: %empty  */
#line 1810 "src/Slice/Grammar.y"
{
    yyval = 0;
}
#line 3692 "src/Slice/Grammar.cpp"
    break;

  case 145: /* enumerator_list_or_empty: %empty  */
#line 1821 "src/Slice/Grammar.y"
{
    yyval = new EnumeratorListTok;
}
#line 3700 "src/Slice/Grammar.cpp"
    break;

  case 146: /* enumerator_list: enumerator_list ',' enumerator  */
#line 1830 "src/Slice/Grammar.y"
{
    EnumeratorListTokPtr enumerators = EnumeratorListTokPtr::dynamicCast(yyvsp[-2]);
    if (EnumeratorPtr en = EnumeratorPtr::dynamicCast(yyvsp[0]))
    {
        enumerators->v.push_back(en);
    }
    yyval = enumerators;
}
#line 3713 "src/Slice/Grammar.cpp"
    break;

  case 147: /* enumerator_list: enumerator  */
#line 1839 "src/Slice/Grammar.y"
{
    EnumeratorListTokPtr enumerators = new EnumeratorListTok;
    if (EnumeratorPtr en = EnumeratorPtr::dynamicCast(yyvsp[0]))
    {
        enumerators->v.push_back(en);
    }
    yyval = enumerators;
}
#line 3726 "src/Slice/Grammar.cpp"
    break;

  case 148: /* enumerator: local_metadata ICE_IDENTIFIER  */
#line 1853 "src/Slice/Grammar.y"
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
#line 3744 "src/Slice/Grammar.cpp"
    break;

  case 149: /* enumerator: local_metadata ICE_IDENTIFIER '=' enumerator_initializer  */
#line 1867 "src/Slice/Grammar.y"
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
#line 3763 "src/Slice/Grammar.cpp"
    break;

  case 150: /* enumerator: local_metadata keyword  */
#line 1882 "src/Slice/Grammar.y"
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
#line 3782 "src/Slice/Grammar.cpp"
    break;

  case 151: /* enumerator_initializer: ICE_INTEGER_LITERAL  */
#line 1902 "src/Slice/Grammar.y"
{
    yyval = yyvsp[0];
}
#line 3790 "src/Slice/Grammar.cpp"
    break;

  case 152: /* enumerator_initializer: scoped_name  */
#line 1906 "src/Slice/Grammar.y"
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
#line 3827 "src/Slice/Grammar.cpp"
    break;

  case 153: /* out_qualifier: ICE_OUT  */
#line 1944 "src/Slice/Grammar.y"
{
    yyval = new BoolTok(true);
}
#line 3835 "src/Slice/Grammar.cpp"
    break;

  case 154: /* out_qualifier: %empty  */
#line 1948 "src/Slice/Grammar.y"
{
    yyval = new BoolTok(false);
}
#line 3843 "src/Slice/Grammar.cpp"
    break;

  case 155: /* parameter: out_qualifier member  */
#line 1957 "src/Slice/Grammar.y"
{
    BoolTokPtr isOutParam = BoolTokPtr::dynamicCast(yyvsp[-1]);
    TaggedDefTokPtr def = TaggedDefTokPtr::dynamicCast(yyvsp[0]);

    if (OperationPtr op = OperationPtr::dynamicCast(unit->currentContainer()))
    {
        MemberPtr param = op->createParameter(def->name, def->type, isOutParam->v, def->isTagged, def->tag);
        unit->currentContainer()->checkIntroduced(def->name, param);
        if(param && !def->metadata.empty())
        {
            param->setMetadata(def->metadata);
        }
    }
}
#line 3862 "src/Slice/Grammar.cpp"
    break;

  case 160: /* throws: ICE_THROWS exception_list  */
#line 1990 "src/Slice/Grammar.y"
{
    yyval = yyvsp[0];
}
#line 3870 "src/Slice/Grammar.cpp"
    break;

  case 161: /* throws: %empty  */
#line 1994 "src/Slice/Grammar.y"
{
    yyval = new ExceptionListTok;
}
#line 3878 "src/Slice/Grammar.cpp"
    break;

  case 165: /* unscoped_name: ICE_SCOPED_IDENTIFIER  */
#line 2011 "src/Slice/Grammar.y"
{
    StringTokPtr ident = StringTokPtr::dynamicCast(yyvsp[0]);
    unit->error("Identifier cannot be scoped: `" + (ident->v) + "'");
    yyval = yyvsp[0];
}
#line 3888 "src/Slice/Grammar.cpp"
    break;

  case 166: /* builtin: ICE_BOOL  */
#line 2021 "src/Slice/Grammar.y"
           {}
#line 3894 "src/Slice/Grammar.cpp"
    break;

  case 167: /* builtin: ICE_BYTE  */
#line 2022 "src/Slice/Grammar.y"
           {}
#line 3900 "src/Slice/Grammar.cpp"
    break;

  case 168: /* builtin: ICE_SHORT  */
#line 2023 "src/Slice/Grammar.y"
            {}
#line 3906 "src/Slice/Grammar.cpp"
    break;

  case 169: /* builtin: ICE_USHORT  */
#line 2024 "src/Slice/Grammar.y"
             {}
#line 3912 "src/Slice/Grammar.cpp"
    break;

  case 170: /* builtin: ICE_INT  */
#line 2025 "src/Slice/Grammar.y"
          {}
#line 3918 "src/Slice/Grammar.cpp"
    break;

  case 171: /* builtin: ICE_UINT  */
#line 2026 "src/Slice/Grammar.y"
           {}
#line 3924 "src/Slice/Grammar.cpp"
    break;

  case 172: /* builtin: ICE_VARINT  */
#line 2027 "src/Slice/Grammar.y"
             {}
#line 3930 "src/Slice/Grammar.cpp"
    break;

  case 173: /* builtin: ICE_VARUINT  */
#line 2028 "src/Slice/Grammar.y"
              {}
#line 3936 "src/Slice/Grammar.cpp"
    break;

  case 174: /* builtin: ICE_LONG  */
#line 2029 "src/Slice/Grammar.y"
           {}
#line 3942 "src/Slice/Grammar.cpp"
    break;

  case 175: /* builtin: ICE_ULONG  */
#line 2030 "src/Slice/Grammar.y"
            {}
#line 3948 "src/Slice/Grammar.cpp"
    break;

  case 176: /* builtin: ICE_VARLONG  */
#line 2031 "src/Slice/Grammar.y"
              {}
#line 3954 "src/Slice/Grammar.cpp"
    break;

  case 177: /* builtin: ICE_VARULONG  */
#line 2032 "src/Slice/Grammar.y"
               {}
#line 3960 "src/Slice/Grammar.cpp"
    break;

  case 178: /* builtin: ICE_FLOAT  */
#line 2033 "src/Slice/Grammar.y"
            {}
#line 3966 "src/Slice/Grammar.cpp"
    break;

  case 179: /* builtin: ICE_DOUBLE  */
#line 2034 "src/Slice/Grammar.y"
             {}
#line 3972 "src/Slice/Grammar.cpp"
    break;

  case 180: /* builtin: ICE_STRING  */
#line 2035 "src/Slice/Grammar.y"
             {}
#line 3978 "src/Slice/Grammar.cpp"
    break;

  case 181: /* type: ICE_OBJECT '*'  */
#line 2041 "src/Slice/Grammar.y"
{
    yyval = unit->optionalBuiltin(Builtin::KindObject);
}
#line 3986 "src/Slice/Grammar.cpp"
    break;

  case 182: /* type: ICE_OBJECT '?'  */
#line 2045 "src/Slice/Grammar.y"
{
    yyval = unit->optionalBuiltin(Builtin::KindObject);
}
#line 3994 "src/Slice/Grammar.cpp"
    break;

  case 183: /* type: ICE_ANYCLASS '?'  */
#line 2049 "src/Slice/Grammar.y"
{
    yyval = unit->optionalBuiltin(Builtin::KindAnyClass);
}
#line 4002 "src/Slice/Grammar.cpp"
    break;

  case 184: /* type: ICE_VALUE '?'  */
#line 2053 "src/Slice/Grammar.y"
{
    if (!unit->compatMode())
    {
        unit->warning(Deprecated, "the `Value' keyword is deprecated, use `AnyClass' instead");
    }
    yyval = unit->optionalBuiltin(Builtin::KindAnyClass);
}
#line 4014 "src/Slice/Grammar.cpp"
    break;

  case 185: /* type: builtin '?'  */
#line 2061 "src/Slice/Grammar.y"
{
    StringTokPtr typeName = StringTokPtr::dynamicCast(yyvsp[-1]);
    yyval = unit->optionalBuiltin(Builtin::kindFromString(typeName->v).value());
}
#line 4023 "src/Slice/Grammar.cpp"
    break;

  case 186: /* type: ICE_OBJECT  */
#line 2066 "src/Slice/Grammar.y"
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
#line 4038 "src/Slice/Grammar.cpp"
    break;

  case 187: /* type: ICE_ANYCLASS  */
#line 2077 "src/Slice/Grammar.y"
{
    yyval = unit->builtin(Builtin::KindAnyClass);
}
#line 4046 "src/Slice/Grammar.cpp"
    break;

  case 188: /* type: ICE_VALUE  */
#line 2081 "src/Slice/Grammar.y"
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
#line 4062 "src/Slice/Grammar.cpp"
    break;

  case 189: /* type: builtin  */
#line 2093 "src/Slice/Grammar.y"
{
    StringTokPtr typeName = StringTokPtr::dynamicCast(yyvsp[0]);
    yyval = unit->builtin(Builtin::kindFromString(typeName->v).value());
}
#line 4071 "src/Slice/Grammar.cpp"
    break;

  case 190: /* type: scoped_name  */
#line 2098 "src/Slice/Grammar.y"
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
#line 4101 "src/Slice/Grammar.cpp"
    break;

  case 191: /* type: scoped_name '*'  */
#line 2124 "src/Slice/Grammar.y"
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
#line 4137 "src/Slice/Grammar.cpp"
    break;

  case 192: /* type: scoped_name '?'  */
#line 2156 "src/Slice/Grammar.y"
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
            cont->checkIntroduced(scoped->v);
            *p = new Optional(*p);
        }
        yyval = types.front();
    }
    else
    {
        yyval = 0;
    }
}
#line 4164 "src/Slice/Grammar.cpp"
    break;

  case 193: /* tagged_type: tag type  */
#line 2184 "src/Slice/Grammar.y"
{
    TaggedDefTokPtr taggedDef = TaggedDefTokPtr::dynamicCast(yyvsp[-1]);
    OptionalPtr type = OptionalPtr::dynamicCast(yyvsp[0]);

    if (!type)
    {
        // Infer the type to be optional so parsing can continue without nullptrs.
        type = new Optional(TypePtr::dynamicCast(yyvsp[0]));
        unit->error("only optional types can be tagged");
    }

    taggedDef->type = type;
    yyval = taggedDef;
}
#line 4183 "src/Slice/Grammar.cpp"
    break;

  case 194: /* tagged_type: optional type  */
#line 2199 "src/Slice/Grammar.y"
{
    TaggedDefTokPtr taggedDef = TaggedDefTokPtr::dynamicCast(yyvsp[-1]);
    OptionalPtr type = OptionalPtr::dynamicCast(yyvsp[0]);

    if (!type)
    {
        // Infer the type to be optional for backwards compatibility.
        type = new Optional(TypePtr::dynamicCast(yyvsp[0]));
    }

    taggedDef->type = type;
    yyval = taggedDef;
}
#line 4201 "src/Slice/Grammar.cpp"
    break;

  case 195: /* tagged_type: type  */
#line 2213 "src/Slice/Grammar.y"
{
    TaggedDefTokPtr taggedDef = new TaggedDefTok;
    taggedDef->type = TypePtr::dynamicCast(yyvsp[0]);
    yyval = taggedDef;
}
#line 4211 "src/Slice/Grammar.cpp"
    break;

  case 196: /* member: tagged_type ICE_IDENTIFIER  */
#line 2224 "src/Slice/Grammar.y"
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
#line 4227 "src/Slice/Grammar.cpp"
    break;

  case 197: /* member: tagged_type keyword  */
#line 2236 "src/Slice/Grammar.y"
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
#line 4242 "src/Slice/Grammar.cpp"
    break;

  case 198: /* member: tagged_type  */
#line 2247 "src/Slice/Grammar.y"
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
#line 4257 "src/Slice/Grammar.cpp"
    break;

  case 199: /* member: local_metadata member  */
#line 2258 "src/Slice/Grammar.y"
{
    TaggedDefTokPtr def = TaggedDefTokPtr::dynamicCast(yyvsp[0]);
    def->metadata = StringListTokPtr::dynamicCast(yyvsp[-1])->v;
    yyval = def;
}
#line 4267 "src/Slice/Grammar.cpp"
    break;

  case 200: /* string_literal: ICE_STRING_LITERAL string_literal  */
#line 2269 "src/Slice/Grammar.y"
{
    StringTokPtr str1 = StringTokPtr::dynamicCast(yyvsp[-1]);
    StringTokPtr str2 = StringTokPtr::dynamicCast(yyvsp[0]);
    str1->v += str2->v;
}
#line 4277 "src/Slice/Grammar.cpp"
    break;

  case 202: /* string_list: string_list ',' string_literal  */
#line 2281 "src/Slice/Grammar.y"
{
    StringTokPtr str = StringTokPtr::dynamicCast(yyvsp[0]);
    StringListTokPtr stringList = StringListTokPtr::dynamicCast(yyvsp[-2]);
    stringList->v.push_back(str->v);
    yyval = stringList;
}
#line 4288 "src/Slice/Grammar.cpp"
    break;

  case 203: /* string_list: string_literal  */
#line 2288 "src/Slice/Grammar.y"
{
    StringTokPtr str = StringTokPtr::dynamicCast(yyvsp[0]);
    StringListTokPtr stringList = new StringListTok;
    stringList->v.push_back(str->v);
    yyval = stringList;
}
#line 4299 "src/Slice/Grammar.cpp"
    break;

  case 204: /* const_initializer: ICE_INTEGER_LITERAL  */
#line 2300 "src/Slice/Grammar.y"
{
    BuiltinPtr type = unit->builtin(Builtin::KindLong);
    IntegerTokPtr intVal = IntegerTokPtr::dynamicCast(yyvsp[0]);
    ostringstream sstr;
    sstr << intVal->v;
    ConstDefTokPtr def = new ConstDefTok(type, sstr.str(), intVal->literal);
    yyval = def;
}
#line 4312 "src/Slice/Grammar.cpp"
    break;

  case 205: /* const_initializer: ICE_FLOATING_POINT_LITERAL  */
#line 2309 "src/Slice/Grammar.y"
{
    BuiltinPtr type = unit->builtin(Builtin::KindDouble);
    FloatingTokPtr floatVal = FloatingTokPtr::dynamicCast(yyvsp[0]);
    ostringstream sstr;
    sstr << floatVal->v;
    ConstDefTokPtr def = new ConstDefTok(type, sstr.str(), floatVal->literal);
    yyval = def;
}
#line 4325 "src/Slice/Grammar.cpp"
    break;

  case 206: /* const_initializer: scoped_name  */
#line 2318 "src/Slice/Grammar.y"
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
#line 4369 "src/Slice/Grammar.cpp"
    break;

  case 207: /* const_initializer: ICE_STRING_LITERAL  */
#line 2358 "src/Slice/Grammar.y"
{
    BuiltinPtr type = unit->builtin(Builtin::KindString);
    StringTokPtr literal = StringTokPtr::dynamicCast(yyvsp[0]);
    ConstDefTokPtr def = new ConstDefTok(type, literal->v, literal->literal);
    yyval = def;
}
#line 4380 "src/Slice/Grammar.cpp"
    break;

  case 208: /* const_initializer: ICE_FALSE  */
#line 2365 "src/Slice/Grammar.y"
{
    BuiltinPtr type = unit->builtin(Builtin::KindBool);
    StringTokPtr literal = StringTokPtr::dynamicCast(yyvsp[0]);
    ConstDefTokPtr def = new ConstDefTok(type, "false", "false");
    yyval = def;
}
#line 4391 "src/Slice/Grammar.cpp"
    break;

  case 209: /* const_initializer: ICE_TRUE  */
#line 2372 "src/Slice/Grammar.y"
{
    BuiltinPtr type = unit->builtin(Builtin::KindBool);
    StringTokPtr literal = StringTokPtr::dynamicCast(yyvsp[0]);
    ConstDefTokPtr def = new ConstDefTok(type, "true", "true");
    yyval = def;
}
#line 4402 "src/Slice/Grammar.cpp"
    break;

  case 210: /* const_def: ICE_CONST local_metadata type ICE_IDENTIFIER '=' const_initializer  */
#line 2384 "src/Slice/Grammar.y"
{
    StringListTokPtr metadata = StringListTokPtr::dynamicCast(yyvsp[-4]);
    TypePtr const_type = TypePtr::dynamicCast(yyvsp[-3]);
    StringTokPtr ident = StringTokPtr::dynamicCast(yyvsp[-2]);
    ConstDefTokPtr value = ConstDefTokPtr::dynamicCast(yyvsp[0]);
    yyval = unit->currentModule()->createConst(ident->v, const_type, metadata->v, value->v,
                                               value->valueAsString, value->valueAsLiteral);
}
#line 4415 "src/Slice/Grammar.cpp"
    break;

  case 211: /* const_def: ICE_CONST local_metadata type '=' const_initializer  */
#line 2393 "src/Slice/Grammar.y"
{
    StringListTokPtr metadata = StringListTokPtr::dynamicCast(yyvsp[-3]);
    TypePtr const_type = TypePtr::dynamicCast(yyvsp[-2]);
    ConstDefTokPtr value = ConstDefTokPtr::dynamicCast(yyvsp[0]);
    unit->error("missing constant name");
    yyval = unit->currentModule()->createConst(IceUtil::generateUUID(), const_type, metadata->v, value->v,
                                               value->valueAsString, value->valueAsLiteral, Dummy); // Dummy
}
#line 4428 "src/Slice/Grammar.cpp"
    break;

  case 212: /* keyword: ICE_MODULE  */
#line 2406 "src/Slice/Grammar.y"
             {}
#line 4434 "src/Slice/Grammar.cpp"
    break;

  case 213: /* keyword: ICE_CLASS  */
#line 2407 "src/Slice/Grammar.y"
            {}
#line 4440 "src/Slice/Grammar.cpp"
    break;

  case 214: /* keyword: ICE_INTERFACE  */
#line 2408 "src/Slice/Grammar.y"
                {}
#line 4446 "src/Slice/Grammar.cpp"
    break;

  case 215: /* keyword: ICE_EXCEPTION  */
#line 2409 "src/Slice/Grammar.y"
                {}
#line 4452 "src/Slice/Grammar.cpp"
    break;

  case 216: /* keyword: ICE_STRUCT  */
#line 2410 "src/Slice/Grammar.y"
             {}
#line 4458 "src/Slice/Grammar.cpp"
    break;

  case 217: /* keyword: ICE_SEQUENCE  */
#line 2411 "src/Slice/Grammar.y"
               {}
#line 4464 "src/Slice/Grammar.cpp"
    break;

  case 218: /* keyword: ICE_DICTIONARY  */
#line 2412 "src/Slice/Grammar.y"
                 {}
#line 4470 "src/Slice/Grammar.cpp"
    break;

  case 219: /* keyword: ICE_ENUM  */
#line 2413 "src/Slice/Grammar.y"
           {}
#line 4476 "src/Slice/Grammar.cpp"
    break;

  case 220: /* keyword: ICE_OUT  */
#line 2414 "src/Slice/Grammar.y"
          {}
#line 4482 "src/Slice/Grammar.cpp"
    break;

  case 221: /* keyword: ICE_EXTENDS  */
#line 2415 "src/Slice/Grammar.y"
              {}
#line 4488 "src/Slice/Grammar.cpp"
    break;

  case 222: /* keyword: ICE_IMPLEMENTS  */
#line 2416 "src/Slice/Grammar.y"
                 {}
#line 4494 "src/Slice/Grammar.cpp"
    break;

  case 223: /* keyword: ICE_THROWS  */
#line 2417 "src/Slice/Grammar.y"
             {}
#line 4500 "src/Slice/Grammar.cpp"
    break;

  case 224: /* keyword: ICE_VOID  */
#line 2418 "src/Slice/Grammar.y"
           {}
#line 4506 "src/Slice/Grammar.cpp"
    break;

  case 225: /* keyword: ICE_BOOL  */
#line 2419 "src/Slice/Grammar.y"
           {}
#line 4512 "src/Slice/Grammar.cpp"
    break;

  case 226: /* keyword: ICE_BYTE  */
#line 2420 "src/Slice/Grammar.y"
           {}
#line 4518 "src/Slice/Grammar.cpp"
    break;

  case 227: /* keyword: ICE_SHORT  */
#line 2421 "src/Slice/Grammar.y"
            {}
#line 4524 "src/Slice/Grammar.cpp"
    break;

  case 228: /* keyword: ICE_USHORT  */
#line 2422 "src/Slice/Grammar.y"
             {}
#line 4530 "src/Slice/Grammar.cpp"
    break;

  case 229: /* keyword: ICE_INT  */
#line 2423 "src/Slice/Grammar.y"
          {}
#line 4536 "src/Slice/Grammar.cpp"
    break;

  case 230: /* keyword: ICE_UINT  */
#line 2424 "src/Slice/Grammar.y"
           {}
#line 4542 "src/Slice/Grammar.cpp"
    break;

  case 231: /* keyword: ICE_VARINT  */
#line 2425 "src/Slice/Grammar.y"
             {}
#line 4548 "src/Slice/Grammar.cpp"
    break;

  case 232: /* keyword: ICE_VARUINT  */
#line 2426 "src/Slice/Grammar.y"
              {}
#line 4554 "src/Slice/Grammar.cpp"
    break;

  case 233: /* keyword: ICE_LONG  */
#line 2427 "src/Slice/Grammar.y"
           {}
#line 4560 "src/Slice/Grammar.cpp"
    break;

  case 234: /* keyword: ICE_ULONG  */
#line 2428 "src/Slice/Grammar.y"
            {}
#line 4566 "src/Slice/Grammar.cpp"
    break;

  case 235: /* keyword: ICE_VARLONG  */
#line 2429 "src/Slice/Grammar.y"
              {}
#line 4572 "src/Slice/Grammar.cpp"
    break;

  case 236: /* keyword: ICE_VARULONG  */
#line 2430 "src/Slice/Grammar.y"
               {}
#line 4578 "src/Slice/Grammar.cpp"
    break;

  case 237: /* keyword: ICE_FLOAT  */
#line 2431 "src/Slice/Grammar.y"
            {}
#line 4584 "src/Slice/Grammar.cpp"
    break;

  case 238: /* keyword: ICE_DOUBLE  */
#line 2432 "src/Slice/Grammar.y"
             {}
#line 4590 "src/Slice/Grammar.cpp"
    break;

  case 239: /* keyword: ICE_STRING  */
#line 2433 "src/Slice/Grammar.y"
             {}
#line 4596 "src/Slice/Grammar.cpp"
    break;

  case 240: /* keyword: ICE_OBJECT  */
#line 2434 "src/Slice/Grammar.y"
             {}
#line 4602 "src/Slice/Grammar.cpp"
    break;

  case 241: /* keyword: ICE_CONST  */
#line 2435 "src/Slice/Grammar.y"
            {}
#line 4608 "src/Slice/Grammar.cpp"
    break;

  case 242: /* keyword: ICE_FALSE  */
#line 2436 "src/Slice/Grammar.y"
            {}
#line 4614 "src/Slice/Grammar.cpp"
    break;

  case 243: /* keyword: ICE_TRUE  */
#line 2437 "src/Slice/Grammar.y"
           {}
#line 4620 "src/Slice/Grammar.cpp"
    break;

  case 244: /* keyword: ICE_IDEMPOTENT  */
#line 2438 "src/Slice/Grammar.y"
                 {}
#line 4626 "src/Slice/Grammar.cpp"
    break;

  case 245: /* keyword: ICE_TAG  */
#line 2439 "src/Slice/Grammar.y"
          {}
#line 4632 "src/Slice/Grammar.cpp"
    break;

  case 246: /* keyword: ICE_OPTIONAL  */
#line 2440 "src/Slice/Grammar.y"
               {}
#line 4638 "src/Slice/Grammar.cpp"
    break;

  case 247: /* keyword: ICE_ANYCLASS  */
#line 2441 "src/Slice/Grammar.y"
               {}
#line 4644 "src/Slice/Grammar.cpp"
    break;

  case 248: /* keyword: ICE_VALUE  */
#line 2442 "src/Slice/Grammar.y"
            {}
#line 4650 "src/Slice/Grammar.cpp"
    break;


#line 4654 "src/Slice/Grammar.cpp"

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

#line 2445 "src/Slice/Grammar.y"

