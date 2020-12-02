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
#define YYLAST   1080

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  64
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  89
/* YYNRULES -- Number of rules.  */
#define YYNRULES  249
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  355

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
     322,   327,   332,   331,   337,   336,   341,   346,   345,   350,
     355,   354,   359,   364,   363,   369,   368,   373,   377,   387,
     386,   425,   424,   502,   506,   517,   528,   527,   553,   561,
     570,   588,   662,   668,   679,   701,   779,   789,   804,   808,
     819,   830,   829,   870,   874,   885,   910,  1000,  1012,  1025,
    1024,  1058,  1094,  1103,  1104,  1110,  1125,  1147,  1148,  1149,
    1153,  1159,  1160,  1166,  1178,  1194,  1209,  1218,  1223,  1232,
    1267,  1302,  1336,  1376,  1375,  1398,  1397,  1420,  1441,  1445,
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

#define YYPACT_NINF (-279)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-166)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
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
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
      11,     0,     8,     1,     0,     0,     9,     0,   202,   204,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   135,     8,     0,     0,    10,    12,    55,    26,    27,
      70,    31,    32,    78,    82,    16,    17,   113,    21,    22,
      39,    36,    42,   140,   143,    43,    47,   201,     6,     0,
       5,    48,    49,    51,   213,   214,   215,   216,   217,   218,
     219,   220,   221,   222,   223,   224,   225,   226,   227,   228,
     229,   230,   231,   232,   233,   234,   235,   236,   237,   238,
     239,   240,   241,   242,   243,   244,   245,   246,   247,   248,
     249,    73,   166,     0,    74,   111,   112,    53,    54,    68,
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
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -279,  -279,    -1,  -279,    -2,    12,  -279,  -279,  -279,  -279,
    -279,  -279,  -279,  -279,  -279,  -279,  -279,  -279,  -279,  -279,
    -279,  -279,  -279,  -279,  -279,  -279,  -279,  -279,  -279,  -279,
    -279,  -279,  -279,  -279,  -279,  -279,  -279,  -279,  -279,  -279,
    -279,   112,  -279,  -213,  -114,  -279,    46,  -279,  -279,  -279,
    -279,  -273,  -279,  -279,  -279,  -279,    91,  -279,   -16,  -279,
    -279,  -279,  -279,  -279,  -279,  -279,  -279,  -279,  -279,   106,
    -279,    74,  -279,  -219,    11,  -279,  -279,     2,  -111,  -278,
    -279,   -96,  -253,  -206,    34,     1,  -227,  -279,   -12
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,   168,     6,   216,     2,    25,   108,   120,   121,
     124,   125,   113,   114,   116,   117,   127,   126,   128,   134,
     135,    26,   137,   138,    27,    28,    29,   169,   111,   217,
     218,    30,    31,    32,   115,    33,    34,    35,    36,   176,
     118,   112,   219,   220,   221,   310,   292,   293,   294,   344,
     342,   266,    37,    38,    39,   185,   183,   123,   349,   350,
      40,    41,    42,    43,    44,    45,   193,   130,   133,   229,
     230,   231,   322,   316,   317,   318,   319,   347,   163,    93,
     164,   222,   223,   224,     9,    10,   247,    46,   352
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
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
};

static const yytype_int16 yycheck[] =
{
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
      -1,    -1,    39,    40,    -1,    -1,    -1,    -1,    45,    46,
      47,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    30,    31,    32,    -1,    -1,    -1,
      -1,    -1,    -1,    39,    40,    -1,    -1,    -1,    -1,    45,
      46
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
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    64,    65,    66,    66,    67,    68,    68,    68,    69,
      69,    69,    71,    70,    72,    70,    70,    73,    70,    74,
      70,    70,    75,    70,    76,    70,    70,    77,    70,    78,
      70,    70,    79,    70,    80,    70,    70,    81,    70,    70,
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
     152,   152,   152,   152,   152,   152,   152,   152,   152,   152
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     0,     3,     3,     4,     0,     2,
       3,     0,     0,     3,     0,     3,     1,     0,     3,     0,
       3,     1,     0,     3,     0,     3,     1,     0,     3,     0,
       3,     1,     0,     3,     0,     3,     1,     0,     3,     1,
       0,     3,     1,     0,     3,     0,     3,     1,     2,     0,
       6,     0,     6,     2,     2,     1,     0,     6,     2,     0,
       4,     4,     3,     1,     4,     4,     3,     1,     2,     2,
       1,     0,     5,     2,     2,     5,     5,     1,     1,     0,
       6,     2,     0,     1,     1,     1,     3,     2,     2,     1,
       2,     1,     0,     2,     4,     1,     3,     2,     1,     3,
       4,     3,     4,     0,     5,     0,     5,     4,     2,     3,
       0,     2,     2,     1,     0,     6,     3,     1,     1,     1,
       1,     2,     0,     3,     1,     1,     1,     5,     2,     2,
       6,     6,     9,     9,     2,     1,     2,     2,     0,     6,
       0,     5,     2,     0,     1,     2,     0,     3,     1,     2,
       4,     2,     1,     1,     1,     0,     2,     1,     3,     1,
       0,     2,     0,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     2,     2,     2,     2,     2,     1,     1,     1,
       1,     1,     2,     2,     2,     2,     1,     2,     2,     1,
       2,     2,     1,     3,     1,     1,     1,     1,     1,     1,
       1,     6,     5,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1
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
#line 1873 "src/Slice/Grammar.cpp"
    break;

  case 6: /* local_metadata: ICE_LOCAL_METADATA_OPEN string_list ICE_LOCAL_METADATA_CLOSE  */
#line 229 "src/Slice/Grammar.y"
{
    StringListTokPtr metadata = StringListTokPtr::dynamicCast(yyvsp[-1]);
    convertMetadata(metadata);
    yyval = metadata;
}
#line 1883 "src/Slice/Grammar.cpp"
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
#line 1896 "src/Slice/Grammar.cpp"
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
{
    StringListTokPtr metadata = StringListTokPtr::dynamicCast(yyvsp[0]);
    if(!metadata->v.empty())
    {
        unit->addFileMetadata(metadata->v);
    }
}
#line 1916 "src/Slice/Grammar.cpp"
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
#line 1929 "src/Slice/Grammar.cpp"
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
#line 2143 "src/Slice/Grammar.cpp"
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
#line 2159 "src/Slice/Grammar.cpp"
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
#line 2218 "src/Slice/Grammar.cpp"
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
#line 2240 "src/Slice/Grammar.cpp"
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
{
    StringTokPtr ident = StringTokPtr::dynamicCast(yyvsp[0]);
    unit->error("keyword `" + ident->v + "' cannot be used as exception name");
    yyval = yyvsp[0]; // Dummy
}
#line 2258 "src/Slice/Grammar.cpp"
    break;

  case 55: /* exception_decl: exception_id  */
#line 518 "src/Slice/Grammar.y"
{
    unit->error("exceptions cannot be forward declared");
    yyval = 0;
}
#line 2267 "src/Slice/Grammar.cpp"
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
#line 2284 "src/Slice/Grammar.cpp"
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
#line 2296 "src/Slice/Grammar.cpp"
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
#line 2308 "src/Slice/Grammar.cpp"
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
#line 2338 "src/Slice/Grammar.cpp"
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
#line 2416 "src/Slice/Grammar.cpp"
    break;

  case 62: /* tag: ICE_TAG '(' ')'  */
#line 663 "src/Slice/Grammar.y"
{
    unit->error("missing tag");
    TaggedDefTokPtr m = new TaggedDefTok; // Dummy
    yyval = m;
}
#line 2426 "src/Slice/Grammar.cpp"
    break;

  case 63: /* tag: ICE_TAG  */
#line 669 "src/Slice/Grammar.y"
{
    unit->error("missing tag");
    TaggedDefTokPtr m = new TaggedDefTok; // Dummy
    yyval = m;
}
#line 2436 "src/Slice/Grammar.cpp"
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
#line 2462 "src/Slice/Grammar.cpp"
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
#line 2544 "src/Slice/Grammar.cpp"
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
#line 2558 "src/Slice/Grammar.cpp"
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
#line 2572 "src/Slice/Grammar.cpp"
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
{
    StringTokPtr ident = StringTokPtr::dynamicCast(yyvsp[0]);
    unit->error("keyword `" + ident->v + "' cannot be used as struct name");
    yyval = yyvsp[0]; // Dummy
}
#line 2590 "src/Slice/Grammar.cpp"
    break;

  case 70: /* struct_decl: struct_id  */
#line 820 "src/Slice/Grammar.y"
{
    unit->error("structs cannot be forward declared");
    yyval = 0; // Dummy
}
#line 2599 "src/Slice/Grammar.cpp"
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
#line 2621 "src/Slice/Grammar.cpp"
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
#line 2643 "src/Slice/Grammar.cpp"
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
{
    StringTokPtr ident = StringTokPtr::dynamicCast(yyvsp[0]);
    unit->error("keyword `" + ident->v + "' cannot be used as class name");
    yyval = yyvsp[0]; // Dummy
}
#line 2661 "src/Slice/Grammar.cpp"
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
#line 2690 "src/Slice/Grammar.cpp"
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
#line 2784 "src/Slice/Grammar.cpp"
    break;

  case 77: /* class_id: class_name  */
#line 1001 "src/Slice/Grammar.y"
{
    ClassIdTokPtr classId = new ClassIdTok();
    classId->v = StringTokPtr::dynamicCast(yyvsp[0])->v;
    classId->t = -1;
    yyval = classId;
}
#line 2795 "src/Slice/Grammar.cpp"
    break;

  case 78: /* class_decl: class_name  */
#line 1013 "src/Slice/Grammar.y"
{
    StringTokPtr ident = StringTokPtr::dynamicCast(yyvsp[0]);
    ModulePtr cont = unit->currentModule();
    ClassDeclPtr cl = cont->createClassDecl(ident->v);
    yyval = cl;
}
#line 2806 "src/Slice/Grammar.cpp"
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
#line 2827 "src/Slice/Grammar.cpp"
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
#line 2843 "src/Slice/Grammar.cpp"
    break;

  case 81: /* class_extends: extends scoped_name  */
#line 1059 "src/Slice/Grammar.y"
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
#line 2883 "src/Slice/Grammar.cpp"
    break;

  case 82: /* class_extends: %empty  */
#line 1095 "src/Slice/Grammar.y"
{
    yyval = 0;
}
#line 2891 "src/Slice/Grammar.cpp"
    break;

  case 85: /* data_member: member  */
#line 1111 "src/Slice/Grammar.y"
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
#line 2910 "src/Slice/Grammar.cpp"
    break;

  case 86: /* data_member: member '=' const_initializer  */
#line 1126 "src/Slice/Grammar.y"
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
#line 2931 "src/Slice/Grammar.cpp"
    break;

  case 89: /* data_member_list: data_member  */
#line 1150 "src/Slice/Grammar.y"
{
    unit->error("`;' missing after definition");
}
#line 2939 "src/Slice/Grammar.cpp"
    break;

  case 93: /* return_tuple: out_qualifier member  */
#line 1167 "src/Slice/Grammar.y"
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
#line 2955 "src/Slice/Grammar.cpp"
    break;

  case 94: /* return_tuple: return_tuple ',' out_qualifier member  */
#line 1179 "src/Slice/Grammar.y"
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
#line 2971 "src/Slice/Grammar.cpp"
    break;

  case 95: /* return_type: tagged_type  */
#line 1195 "src/Slice/Grammar.y"
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
#line 2990 "src/Slice/Grammar.cpp"
    break;

  case 96: /* return_type: '(' return_tuple ')'  */
#line 1210 "src/Slice/Grammar.y"
{
    TaggedDefListTokPtr returnMembers = TaggedDefListTokPtr::dynamicCast(yyvsp[-1]);
    if (returnMembers->v.size() == 1)
    {
        unit->error("return tuples must contain at least 2 elements");
    }
    yyval = yyvsp[-1];
}
#line 3003 "src/Slice/Grammar.cpp"
    break;

  case 97: /* return_type: '(' ')'  */
#line 1219 "src/Slice/Grammar.y"
{
    unit->error("return tuples must contain at least 2 elements");
    yyval = new TaggedDefListTok();
}
#line 3012 "src/Slice/Grammar.cpp"
    break;

  case 98: /* return_type: ICE_VOID  */
#line 1224 "src/Slice/Grammar.y"
{
    yyval = new TaggedDefListTok();
}
#line 3020 "src/Slice/Grammar.cpp"
    break;

  case 99: /* operation_preamble: return_type unscoped_name '('  */
#line 1233 "src/Slice/Grammar.y"
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
#line 3059 "src/Slice/Grammar.cpp"
    break;

  case 100: /* operation_preamble: ICE_IDEMPOTENT return_type unscoped_name '('  */
#line 1268 "src/Slice/Grammar.y"
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
#line 3098 "src/Slice/Grammar.cpp"
    break;

  case 101: /* operation_preamble: return_type keyword '('  */
#line 1303 "src/Slice/Grammar.y"
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
#line 3136 "src/Slice/Grammar.cpp"
    break;

  case 102: /* operation_preamble: ICE_IDEMPOTENT return_type keyword '('  */
#line 1337 "src/Slice/Grammar.y"
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
#line 3174 "src/Slice/Grammar.cpp"
    break;

  case 103: /* @20: %empty  */
#line 1376 "src/Slice/Grammar.y"
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
#line 3190 "src/Slice/Grammar.cpp"
    break;

  case 104: /* operation: operation_preamble parameters ')' @20 throws  */
#line 1388 "src/Slice/Grammar.y"
{
    OperationPtr op = OperationPtr::dynamicCast(yyvsp[-1]);
    ExceptionListTokPtr el = ExceptionListTokPtr::dynamicCast(yyvsp[0]);
    assert(el);
    if(op)
    {
        op->setExceptionList(el->v);
    }
}
#line 3204 "src/Slice/Grammar.cpp"
    break;

  case 105: /* @21: %empty  */
#line 1398 "src/Slice/Grammar.y"
{
    if(yyvsp[-2])
    {
        unit->popContainer();
    }
    yyerrok;
}
#line 3216 "src/Slice/Grammar.cpp"
    break;

  case 106: /* operation: operation_preamble error ')' @21 throws  */
#line 1406 "src/Slice/Grammar.y"
{
    OperationPtr op = OperationPtr::dynamicCast(yyvsp[-1]);
    ExceptionListTokPtr el = ExceptionListTokPtr::dynamicCast(yyvsp[0]);
    assert(el);
    if(op)
    {
        op->setExceptionList(el->v); // Dummy
    }
}
#line 3230 "src/Slice/Grammar.cpp"
    break;

  case 107: /* operation_list: local_metadata operation ';' operation_list  */
#line 1421 "src/Slice/Grammar.y"
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

            returnType->setMetadata(mergeMetadata(metadata->v, returnMetadata));
        }
    }
}
#line 3255 "src/Slice/Grammar.cpp"
    break;

  case 108: /* operation_list: local_metadata operation  */
#line 1442 "src/Slice/Grammar.y"
{
    unit->error("`;' missing after definition");
}
#line 3263 "src/Slice/Grammar.cpp"
    break;

  case 111: /* interface_id: ICE_INTERFACE ICE_IDENTIFIER  */
#line 1453 "src/Slice/Grammar.y"
{
    yyval = yyvsp[0];
}
#line 3271 "src/Slice/Grammar.cpp"
    break;

  case 112: /* interface_id: ICE_INTERFACE keyword  */
#line 1457 "src/Slice/Grammar.y"
{
    StringTokPtr ident = StringTokPtr::dynamicCast(yyvsp[0]);
    unit->error("keyword `" + ident->v + "' cannot be used as interface name");
    yyval = yyvsp[0]; // Dummy
}
#line 3281 "src/Slice/Grammar.cpp"
    break;

  case 113: /* interface_decl: interface_id  */
#line 1468 "src/Slice/Grammar.y"
{
    StringTokPtr ident = StringTokPtr::dynamicCast(yyvsp[0]);
    ModulePtr cont = unit->currentModule();
    InterfaceDeclPtr cl = cont->createInterfaceDecl(ident->v);
    cont->checkIntroduced(ident->v, cl);
    yyval = cl;
}
#line 3293 "src/Slice/Grammar.cpp"
    break;

  case 114: /* @22: %empty  */
#line 1481 "src/Slice/Grammar.y"
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
#line 3314 "src/Slice/Grammar.cpp"
    break;

  case 115: /* interface_def: interface_id interface_extends @22 '{' operation_list '}'  */
#line 1498 "src/Slice/Grammar.y"
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
#line 3330 "src/Slice/Grammar.cpp"
    break;

  case 116: /* interface_list: scoped_name ',' interface_list  */
#line 1515 "src/Slice/Grammar.y"
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
#line 3371 "src/Slice/Grammar.cpp"
    break;

  case 117: /* interface_list: scoped_name  */
#line 1552 "src/Slice/Grammar.y"
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
                if (!alias->typeMetadata().empty())
                {
                    unit->error("illegal metadata: typealias metadata `" + alias->typeMetadata().front() +
                                "' cannot be used in inheritance declarations");
                }
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
#line 3417 "src/Slice/Grammar.cpp"
    break;

  case 118: /* interface_list: ICE_OBJECT  */
#line 1594 "src/Slice/Grammar.y"
{
    unit->error("illegal inheritance from type Object");
    yyval = new InterfaceListTok; // Dummy
}
#line 3426 "src/Slice/Grammar.cpp"
    break;

  case 119: /* interface_list: ICE_ANYCLASS  */
#line 1599 "src/Slice/Grammar.y"
{
    unit->error("illegal inheritance from type AnyClass");
    yyval = new ClassListTok; // Dummy
}
#line 3435 "src/Slice/Grammar.cpp"
    break;

  case 120: /* interface_list: ICE_VALUE  */
#line 1604 "src/Slice/Grammar.y"
{
    if (!unit->compatMode())
    {
        unit->warning(Deprecated, "the `Value' keyword is deprecated, use `AnyClass' instead");
    }
    unit->error("illegal inheritance from type Value");
    yyval = new ClassListTok; // Dummy
}
#line 3448 "src/Slice/Grammar.cpp"
    break;

  case 121: /* interface_extends: extends interface_list  */
#line 1618 "src/Slice/Grammar.y"
{
    yyval = yyvsp[0];
}
#line 3456 "src/Slice/Grammar.cpp"
    break;

  case 122: /* interface_extends: %empty  */
#line 1622 "src/Slice/Grammar.y"
{
    yyval = new InterfaceListTok;
}
#line 3464 "src/Slice/Grammar.cpp"
    break;

  case 123: /* exception_list: exception ',' exception_list  */
#line 1631 "src/Slice/Grammar.y"
{
    ExceptionPtr exception = ExceptionPtr::dynamicCast(yyvsp[-2]);
    ExceptionListTokPtr exceptionList = ExceptionListTokPtr::dynamicCast(yyvsp[0]);
    exceptionList->v.push_front(exception);
    yyval = exceptionList;
}
#line 3475 "src/Slice/Grammar.cpp"
    break;

  case 124: /* exception_list: exception  */
#line 1638 "src/Slice/Grammar.y"
{
    ExceptionPtr exception = ExceptionPtr::dynamicCast(yyvsp[0]);
    ExceptionListTokPtr exceptionList = new ExceptionListTok;
    exceptionList->v.push_front(exception);
    yyval = exceptionList;
}
#line 3486 "src/Slice/Grammar.cpp"
    break;

  case 125: /* exception: scoped_name  */
#line 1650 "src/Slice/Grammar.y"
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
#line 3502 "src/Slice/Grammar.cpp"
    break;

  case 126: /* exception: keyword  */
#line 1662 "src/Slice/Grammar.y"
{
    StringTokPtr ident = StringTokPtr::dynamicCast(yyvsp[0]);
    unit->error("keyword `" + ident->v + "' cannot be used as exception name");
    yyval = unit->currentModule()->createException(IceUtil::generateUUID(), 0, Dummy); // Dummy
}
#line 3512 "src/Slice/Grammar.cpp"
    break;

  case 127: /* type_alias_def: ICE_USING ICE_IDENTIFIER '=' local_metadata type  */
#line 1673 "src/Slice/Grammar.y"
{
    StringTokPtr ident = StringTokPtr::dynamicCast(yyvsp[-3]);
    StringListTokPtr metadata = StringListTokPtr::dynamicCast(yyvsp[-1]);

    if (TypePtr type = TypePtr::dynamicCast(yyvsp[0]))
    {
        if (auto alias = TypeAliasPtr::dynamicCast(type))
        {
            mergeMetadataInPlace(metadata->v, alias->typeMetadata());
            type = alias->underlying();
        }

        // Metadata cannot be specified on aliases of classes and interfaces.
        if (!metadata->v.empty())
        {
            if (ClassDeclPtr::dynamicCast(type))
            {
                unit->error("illegal metadata on `" + ident->v +
                            "': metadata cannot be specified on aliases of classes");
            }
            else if (InterfaceDeclPtr::dynamicCast(type))
            {
                unit->error("illegal metadata on `" + ident->v +
                            "': metadata cannot be specified on aliases of interfaces");
            }
        }

        ModulePtr cont = unit->currentModule();
        yyval = cont->createTypeAlias(ident->v, type, metadata->v);
    }
    else
    {
        yyval = nullptr;
    }
}
#line 3552 "src/Slice/Grammar.cpp"
    break;

  case 128: /* type_alias_def: ICE_USING ICE_IDENTIFIER  */
#line 1709 "src/Slice/Grammar.y"
{
    StringTokPtr ident = StringTokPtr::dynamicCast(yyvsp[0]);
    unit->error("missing underlying type for typealias `" + ident->v + "'");
    yyval = nullptr;
}
#line 3562 "src/Slice/Grammar.cpp"
    break;

  case 129: /* type_alias_def: ICE_USING error  */
#line 1715 "src/Slice/Grammar.y"
{
    unit->error("unable to resolve underlying type");
    yyval = nullptr;
}
#line 3571 "src/Slice/Grammar.cpp"
    break;

  case 130: /* sequence_def: ICE_SEQUENCE '<' local_metadata type '>' ICE_IDENTIFIER  */
#line 1724 "src/Slice/Grammar.y"
{
    StringTokPtr ident = StringTokPtr::dynamicCast(yyvsp[0]);
    StringListTokPtr metadata = StringListTokPtr::dynamicCast(yyvsp[-3]);
    TypePtr type = TypePtr::dynamicCast(yyvsp[-2]);

    resolveAlias(type, metadata->v);

    ModulePtr cont = unit->currentModule();
    yyval = cont->createSequence(ident->v, type, metadata->v);
}
#line 3586 "src/Slice/Grammar.cpp"
    break;

  case 131: /* sequence_def: ICE_SEQUENCE '<' local_metadata type '>' keyword  */
#line 1735 "src/Slice/Grammar.y"
{
    StringTokPtr ident = StringTokPtr::dynamicCast(yyvsp[0]);
    StringListTokPtr metadata = StringListTokPtr::dynamicCast(yyvsp[-3]);
    TypePtr type = TypePtr::dynamicCast(yyvsp[-2]);

    resolveAlias(type, metadata->v);

    ModulePtr cont = unit->currentModule();
    yyval = cont->createSequence(ident->v, type, metadata->v); // Dummy
    unit->error("keyword `" + ident->v + "' cannot be used as sequence name");
}
#line 3602 "src/Slice/Grammar.cpp"
    break;

  case 132: /* dictionary_def: ICE_DICTIONARY '<' local_metadata type ',' local_metadata type '>' ICE_IDENTIFIER  */
#line 1752 "src/Slice/Grammar.y"
{
    StringTokPtr ident = StringTokPtr::dynamicCast(yyvsp[0]);
    StringListTokPtr keyMetadata = StringListTokPtr::dynamicCast(yyvsp[-6]);
    TypePtr keyType = TypePtr::dynamicCast(yyvsp[-5]);
    StringListTokPtr valueMetadata = StringListTokPtr::dynamicCast(yyvsp[-3]);
    TypePtr valueType = TypePtr::dynamicCast(yyvsp[-2]);

    resolveAlias(keyType, keyMetadata->v);
    resolveAlias(valueType, valueMetadata->v);

    ModulePtr cont = unit->currentModule();
    yyval = cont->createDictionary(ident->v, keyType, keyMetadata->v, valueType, valueMetadata->v);
}
#line 3620 "src/Slice/Grammar.cpp"
    break;

  case 133: /* dictionary_def: ICE_DICTIONARY '<' local_metadata type ',' local_metadata type '>' keyword  */
#line 1766 "src/Slice/Grammar.y"
{
    StringTokPtr ident = StringTokPtr::dynamicCast(yyvsp[0]);
    StringListTokPtr keyMetadata = StringListTokPtr::dynamicCast(yyvsp[-6]);
    TypePtr keyType = TypePtr::dynamicCast(yyvsp[-5]);
    StringListTokPtr valueMetadata = StringListTokPtr::dynamicCast(yyvsp[-3]);
    TypePtr valueType = TypePtr::dynamicCast(yyvsp[-2]);

    resolveAlias(keyType, keyMetadata->v);
    resolveAlias(valueType, valueMetadata->v);

    ModulePtr cont = unit->currentModule();
    yyval = cont->createDictionary(ident->v, keyType, keyMetadata->v, valueType, valueMetadata->v); // Dummy
    unit->error("keyword `" + ident->v + "' cannot be used as dictionary name");
}
#line 3639 "src/Slice/Grammar.cpp"
    break;

  case 134: /* enum_start: ICE_UNCHECKED ICE_ENUM  */
#line 1786 "src/Slice/Grammar.y"
{
    yyval = new BoolTok(true);
}
#line 3647 "src/Slice/Grammar.cpp"
    break;

  case 135: /* enum_start: ICE_ENUM  */
#line 1790 "src/Slice/Grammar.y"
{
    yyval = new BoolTok(false);
}
#line 3655 "src/Slice/Grammar.cpp"
    break;

  case 136: /* enum_id: enum_start ICE_IDENTIFIER  */
#line 1799 "src/Slice/Grammar.y"
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
#line 3675 "src/Slice/Grammar.cpp"
    break;

  case 137: /* enum_id: enum_start keyword  */
#line 1815 "src/Slice/Grammar.y"
{
    bool unchecked = BoolTokPtr::dynamicCast(yyvsp[-1])->v;
    StringTokPtr ident = StringTokPtr::dynamicCast(yyvsp[0]);
    ModulePtr cont = unit->currentModule();
    unit->error("keyword `" + ident->v + "' cannot be used as enumeration name");
    yyval = cont->createEnum(IceUtil::generateUUID(), unchecked, Dummy);
}
#line 3687 "src/Slice/Grammar.cpp"
    break;

  case 138: /* @23: %empty  */
#line 1828 "src/Slice/Grammar.y"
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
#line 3710 "src/Slice/Grammar.cpp"
    break;

  case 139: /* enum_def: enum_id enum_underlying @23 '{' enumerator_list_or_empty '}'  */
#line 1847 "src/Slice/Grammar.y"
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
#line 3727 "src/Slice/Grammar.cpp"
    break;

  case 140: /* @24: %empty  */
#line 1860 "src/Slice/Grammar.y"
{
    bool unchecked = BoolTokPtr::dynamicCast(yyvsp[0])->v;
    unit->error("missing enumeration name");
    ModulePtr cont = unit->currentModule();
    EnumPtr en = cont->createEnum(IceUtil::generateUUID(), unchecked, Dummy);
    unit->pushContainer(en);
    yyval = en;
}
#line 3740 "src/Slice/Grammar.cpp"
    break;

  case 141: /* enum_def: enum_start @24 '{' enumerator_list_or_empty '}'  */
#line 1869 "src/Slice/Grammar.y"
{
    unit->popContainer();
    yyval = yyvsp[-4];
}
#line 3749 "src/Slice/Grammar.cpp"
    break;

  case 142: /* enum_underlying: ':' type  */
#line 1879 "src/Slice/Grammar.y"
{
    yyval = yyvsp[0];
}
#line 3757 "src/Slice/Grammar.cpp"
    break;

  case 143: /* enum_underlying: %empty  */
#line 1883 "src/Slice/Grammar.y"
{
    yyval = 0;
}
#line 3765 "src/Slice/Grammar.cpp"
    break;

  case 146: /* enumerator_list_or_empty: %empty  */
#line 1894 "src/Slice/Grammar.y"
{
    yyval = new EnumeratorListTok;
}
#line 3773 "src/Slice/Grammar.cpp"
    break;

  case 147: /* enumerator_list: enumerator_list ',' enumerator  */
#line 1903 "src/Slice/Grammar.y"
{
    EnumeratorListTokPtr enumerators = EnumeratorListTokPtr::dynamicCast(yyvsp[-2]);
    if (EnumeratorPtr en = EnumeratorPtr::dynamicCast(yyvsp[0]))
    {
        enumerators->v.push_back(en);
    }
    yyval = enumerators;
}
#line 3786 "src/Slice/Grammar.cpp"
    break;

  case 148: /* enumerator_list: enumerator  */
#line 1912 "src/Slice/Grammar.y"
{
    EnumeratorListTokPtr enumerators = new EnumeratorListTok;
    if (EnumeratorPtr en = EnumeratorPtr::dynamicCast(yyvsp[0]))
    {
        enumerators->v.push_back(en);
    }
    yyval = enumerators;
}
#line 3799 "src/Slice/Grammar.cpp"
    break;

  case 149: /* enumerator: local_metadata ICE_IDENTIFIER  */
#line 1926 "src/Slice/Grammar.y"
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
#line 3817 "src/Slice/Grammar.cpp"
    break;

  case 150: /* enumerator: local_metadata ICE_IDENTIFIER '=' enumerator_initializer  */
#line 1940 "src/Slice/Grammar.y"
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
#line 3836 "src/Slice/Grammar.cpp"
    break;

  case 151: /* enumerator: local_metadata keyword  */
#line 1955 "src/Slice/Grammar.y"
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
#line 3855 "src/Slice/Grammar.cpp"
    break;

  case 152: /* enumerator_initializer: ICE_INTEGER_LITERAL  */
#line 1975 "src/Slice/Grammar.y"
{
    yyval = yyvsp[0];
}
#line 3863 "src/Slice/Grammar.cpp"
    break;

  case 153: /* enumerator_initializer: scoped_name  */
#line 1979 "src/Slice/Grammar.y"
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
#line 3900 "src/Slice/Grammar.cpp"
    break;

  case 154: /* out_qualifier: ICE_OUT  */
#line 2017 "src/Slice/Grammar.y"
{
    yyval = new BoolTok(true);
}
#line 3908 "src/Slice/Grammar.cpp"
    break;

  case 155: /* out_qualifier: %empty  */
#line 2021 "src/Slice/Grammar.y"
{
    yyval = new BoolTok(false);
}
#line 3916 "src/Slice/Grammar.cpp"
    break;

  case 156: /* parameter: out_qualifier member  */
#line 2030 "src/Slice/Grammar.y"
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
#line 3935 "src/Slice/Grammar.cpp"
    break;

  case 161: /* throws: ICE_THROWS exception_list  */
#line 2063 "src/Slice/Grammar.y"
{
    yyval = yyvsp[0];
}
#line 3943 "src/Slice/Grammar.cpp"
    break;

  case 162: /* throws: %empty  */
#line 2067 "src/Slice/Grammar.y"
{
    yyval = new ExceptionListTok;
}
#line 3951 "src/Slice/Grammar.cpp"
    break;

  case 166: /* unscoped_name: ICE_SCOPED_IDENTIFIER  */
#line 2084 "src/Slice/Grammar.y"
{
    StringTokPtr ident = StringTokPtr::dynamicCast(yyvsp[0]);
    unit->error("Identifier cannot be scoped: `" + (ident->v) + "'");
    yyval = yyvsp[0];
}
#line 3961 "src/Slice/Grammar.cpp"
    break;

  case 167: /* builtin: ICE_BOOL  */
#line 2094 "src/Slice/Grammar.y"
           {}
#line 3967 "src/Slice/Grammar.cpp"
    break;

  case 168: /* builtin: ICE_BYTE  */
#line 2095 "src/Slice/Grammar.y"
           {}
#line 3973 "src/Slice/Grammar.cpp"
    break;

  case 169: /* builtin: ICE_SHORT  */
#line 2096 "src/Slice/Grammar.y"
            {}
#line 3979 "src/Slice/Grammar.cpp"
    break;

  case 170: /* builtin: ICE_USHORT  */
#line 2097 "src/Slice/Grammar.y"
             {}
#line 3985 "src/Slice/Grammar.cpp"
    break;

  case 171: /* builtin: ICE_INT  */
#line 2098 "src/Slice/Grammar.y"
          {}
#line 3991 "src/Slice/Grammar.cpp"
    break;

  case 172: /* builtin: ICE_UINT  */
#line 2099 "src/Slice/Grammar.y"
           {}
#line 3997 "src/Slice/Grammar.cpp"
    break;

  case 173: /* builtin: ICE_VARINT  */
#line 2100 "src/Slice/Grammar.y"
             {}
#line 4003 "src/Slice/Grammar.cpp"
    break;

  case 174: /* builtin: ICE_VARUINT  */
#line 2101 "src/Slice/Grammar.y"
              {}
#line 4009 "src/Slice/Grammar.cpp"
    break;

  case 175: /* builtin: ICE_LONG  */
#line 2102 "src/Slice/Grammar.y"
           {}
#line 4015 "src/Slice/Grammar.cpp"
    break;

  case 176: /* builtin: ICE_ULONG  */
#line 2103 "src/Slice/Grammar.y"
            {}
#line 4021 "src/Slice/Grammar.cpp"
    break;

  case 177: /* builtin: ICE_VARLONG  */
#line 2104 "src/Slice/Grammar.y"
              {}
#line 4027 "src/Slice/Grammar.cpp"
    break;

  case 178: /* builtin: ICE_VARULONG  */
#line 2105 "src/Slice/Grammar.y"
               {}
#line 4033 "src/Slice/Grammar.cpp"
    break;

  case 179: /* builtin: ICE_FLOAT  */
#line 2106 "src/Slice/Grammar.y"
            {}
#line 4039 "src/Slice/Grammar.cpp"
    break;

  case 180: /* builtin: ICE_DOUBLE  */
#line 2107 "src/Slice/Grammar.y"
             {}
#line 4045 "src/Slice/Grammar.cpp"
    break;

  case 181: /* builtin: ICE_STRING  */
#line 2108 "src/Slice/Grammar.y"
             {}
#line 4051 "src/Slice/Grammar.cpp"
    break;

  case 182: /* type: ICE_OBJECT '*'  */
#line 2114 "src/Slice/Grammar.y"
{
    yyval = unit->optionalBuiltin(Builtin::KindObject);
}
#line 4059 "src/Slice/Grammar.cpp"
    break;

  case 183: /* type: ICE_OBJECT '?'  */
#line 2118 "src/Slice/Grammar.y"
{
    yyval = unit->optionalBuiltin(Builtin::KindObject);
}
#line 4067 "src/Slice/Grammar.cpp"
    break;

  case 184: /* type: ICE_ANYCLASS '?'  */
#line 2122 "src/Slice/Grammar.y"
{
    yyval = unit->optionalBuiltin(Builtin::KindAnyClass);
}
#line 4075 "src/Slice/Grammar.cpp"
    break;

  case 185: /* type: ICE_VALUE '?'  */
#line 2126 "src/Slice/Grammar.y"
{
    if (!unit->compatMode())
    {
        unit->warning(Deprecated, "the `Value' keyword is deprecated, use `AnyClass' instead");
    }
    yyval = unit->optionalBuiltin(Builtin::KindAnyClass);
}
#line 4087 "src/Slice/Grammar.cpp"
    break;

  case 186: /* type: builtin '?'  */
#line 2134 "src/Slice/Grammar.y"
{
    StringTokPtr typeName = StringTokPtr::dynamicCast(yyvsp[-1]);
    yyval = unit->optionalBuiltin(Builtin::kindFromString(typeName->v).value());
}
#line 4096 "src/Slice/Grammar.cpp"
    break;

  case 187: /* type: ICE_OBJECT  */
#line 2139 "src/Slice/Grammar.y"
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
#line 4111 "src/Slice/Grammar.cpp"
    break;

  case 188: /* type: ICE_ANYCLASS  */
#line 2150 "src/Slice/Grammar.y"
{
    yyval = unit->builtin(Builtin::KindAnyClass);
}
#line 4119 "src/Slice/Grammar.cpp"
    break;

  case 189: /* type: ICE_VALUE  */
#line 2154 "src/Slice/Grammar.y"
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
#line 4135 "src/Slice/Grammar.cpp"
    break;

  case 190: /* type: builtin  */
#line 2166 "src/Slice/Grammar.y"
{
    StringTokPtr typeName = StringTokPtr::dynamicCast(yyvsp[0]);
    yyval = unit->builtin(Builtin::kindFromString(typeName->v).value());
}
#line 4144 "src/Slice/Grammar.cpp"
    break;

  case 191: /* type: scoped_name  */
#line 2171 "src/Slice/Grammar.y"
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
#line 4174 "src/Slice/Grammar.cpp"
    break;

  case 192: /* type: scoped_name '*'  */
#line 2197 "src/Slice/Grammar.y"
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
#line 4210 "src/Slice/Grammar.cpp"
    break;

  case 193: /* type: scoped_name '?'  */
#line 2229 "src/Slice/Grammar.y"
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
#line 4233 "src/Slice/Grammar.cpp"
    break;

  case 194: /* tagged_type: tag type  */
#line 2253 "src/Slice/Grammar.y"
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
#line 4258 "src/Slice/Grammar.cpp"
    break;

  case 195: /* tagged_type: optional type  */
#line 2274 "src/Slice/Grammar.y"
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
#line 4282 "src/Slice/Grammar.cpp"
    break;

  case 196: /* tagged_type: type  */
#line 2294 "src/Slice/Grammar.y"
{
    TaggedDefTokPtr taggedDef = new TaggedDefTok;
    taggedDef->type = TypePtr::dynamicCast(yyvsp[0]);

    resolveAlias(taggedDef->type, taggedDef->metadata);

    yyval = taggedDef;
}
#line 4295 "src/Slice/Grammar.cpp"
    break;

  case 197: /* member: tagged_type ICE_IDENTIFIER  */
#line 2308 "src/Slice/Grammar.y"
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
#line 4311 "src/Slice/Grammar.cpp"
    break;

  case 198: /* member: tagged_type keyword  */
#line 2320 "src/Slice/Grammar.y"
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
#line 4326 "src/Slice/Grammar.cpp"
    break;

  case 199: /* member: tagged_type  */
#line 2331 "src/Slice/Grammar.y"
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
#line 4341 "src/Slice/Grammar.cpp"
    break;

  case 200: /* member: local_metadata member  */
#line 2342 "src/Slice/Grammar.y"
{
    StringListTokPtr metadata = StringListTokPtr::dynamicCast(yyvsp[-1]);
    TaggedDefTokPtr def = TaggedDefTokPtr::dynamicCast(yyvsp[0]);
    def->metadata = mergeMetadata(metadata->v, def->metadata);
    yyval = def;
}
#line 4352 "src/Slice/Grammar.cpp"
    break;

  case 201: /* string_literal: ICE_STRING_LITERAL string_literal  */
#line 2354 "src/Slice/Grammar.y"
{
    StringTokPtr str1 = StringTokPtr::dynamicCast(yyvsp[-1]);
    StringTokPtr str2 = StringTokPtr::dynamicCast(yyvsp[0]);
    str1->v += str2->v;
}
#line 4362 "src/Slice/Grammar.cpp"
    break;

  case 203: /* string_list: string_list ',' string_literal  */
#line 2366 "src/Slice/Grammar.y"
{
    StringTokPtr str = StringTokPtr::dynamicCast(yyvsp[0]);
    StringListTokPtr stringList = StringListTokPtr::dynamicCast(yyvsp[-2]);
    stringList->v.push_back(str->v);
    yyval = stringList;
}
#line 4373 "src/Slice/Grammar.cpp"
    break;

  case 204: /* string_list: string_literal  */
#line 2373 "src/Slice/Grammar.y"
{
    StringTokPtr str = StringTokPtr::dynamicCast(yyvsp[0]);
    StringListTokPtr stringList = new StringListTok;
    stringList->v.push_back(str->v);
    yyval = stringList;
}
#line 4384 "src/Slice/Grammar.cpp"
    break;

  case 205: /* const_initializer: ICE_INTEGER_LITERAL  */
#line 2385 "src/Slice/Grammar.y"
{
    BuiltinPtr type = unit->builtin(Builtin::KindLong);
    IntegerTokPtr intVal = IntegerTokPtr::dynamicCast(yyvsp[0]);
    ostringstream sstr;
    sstr << intVal->v;
    ConstDefTokPtr def = new ConstDefTok(type, sstr.str(), intVal->literal);
    yyval = def;
}
#line 4397 "src/Slice/Grammar.cpp"
    break;

  case 206: /* const_initializer: ICE_FLOATING_POINT_LITERAL  */
#line 2394 "src/Slice/Grammar.y"
{
    BuiltinPtr type = unit->builtin(Builtin::KindDouble);
    FloatingTokPtr floatVal = FloatingTokPtr::dynamicCast(yyvsp[0]);
    ostringstream sstr;
    sstr << floatVal->v;
    ConstDefTokPtr def = new ConstDefTok(type, sstr.str(), floatVal->literal);
    yyval = def;
}
#line 4410 "src/Slice/Grammar.cpp"
    break;

  case 207: /* const_initializer: scoped_name  */
#line 2403 "src/Slice/Grammar.y"
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
#line 4454 "src/Slice/Grammar.cpp"
    break;

  case 208: /* const_initializer: ICE_STRING_LITERAL  */
#line 2443 "src/Slice/Grammar.y"
{
    BuiltinPtr type = unit->builtin(Builtin::KindString);
    StringTokPtr literal = StringTokPtr::dynamicCast(yyvsp[0]);
    ConstDefTokPtr def = new ConstDefTok(type, literal->v, literal->literal);
    yyval = def;
}
#line 4465 "src/Slice/Grammar.cpp"
    break;

  case 209: /* const_initializer: ICE_FALSE  */
#line 2450 "src/Slice/Grammar.y"
{
    BuiltinPtr type = unit->builtin(Builtin::KindBool);
    StringTokPtr literal = StringTokPtr::dynamicCast(yyvsp[0]);
    ConstDefTokPtr def = new ConstDefTok(type, "false", "false");
    yyval = def;
}
#line 4476 "src/Slice/Grammar.cpp"
    break;

  case 210: /* const_initializer: ICE_TRUE  */
#line 2457 "src/Slice/Grammar.y"
{
    BuiltinPtr type = unit->builtin(Builtin::KindBool);
    StringTokPtr literal = StringTokPtr::dynamicCast(yyvsp[0]);
    ConstDefTokPtr def = new ConstDefTok(type, "true", "true");
    yyval = def;
}
#line 4487 "src/Slice/Grammar.cpp"
    break;

  case 211: /* const_def: ICE_CONST local_metadata type ICE_IDENTIFIER '=' const_initializer  */
#line 2469 "src/Slice/Grammar.y"
{
    StringListTokPtr metadata = StringListTokPtr::dynamicCast(yyvsp[-4]);
    TypePtr const_type = TypePtr::dynamicCast(yyvsp[-3]);
    StringTokPtr ident = StringTokPtr::dynamicCast(yyvsp[-2]);
    ConstDefTokPtr value = ConstDefTokPtr::dynamicCast(yyvsp[0]);

    resolveAlias(const_type, metadata->v);

    yyval = unit->currentModule()->createConst(ident->v, const_type, metadata->v, value->v,
                                               value->valueAsString, value->valueAsLiteral);
}
#line 4503 "src/Slice/Grammar.cpp"
    break;

  case 212: /* const_def: ICE_CONST local_metadata type '=' const_initializer  */
#line 2481 "src/Slice/Grammar.y"
{
    StringListTokPtr metadata = StringListTokPtr::dynamicCast(yyvsp[-3]);
    TypePtr const_type = TypePtr::dynamicCast(yyvsp[-2]);
    ConstDefTokPtr value = ConstDefTokPtr::dynamicCast(yyvsp[0]);
    unit->error("missing constant name");

    resolveAlias(const_type, metadata->v);

    yyval = unit->currentModule()->createConst(IceUtil::generateUUID(), const_type, metadata->v, value->v,
                                               value->valueAsString, value->valueAsLiteral, Dummy); // Dummy
}
#line 4519 "src/Slice/Grammar.cpp"
    break;

  case 213: /* keyword: ICE_MODULE  */
#line 2497 "src/Slice/Grammar.y"
             {}
#line 4525 "src/Slice/Grammar.cpp"
    break;

  case 214: /* keyword: ICE_CLASS  */
#line 2498 "src/Slice/Grammar.y"
            {}
#line 4531 "src/Slice/Grammar.cpp"
    break;

  case 215: /* keyword: ICE_INTERFACE  */
#line 2499 "src/Slice/Grammar.y"
                {}
#line 4537 "src/Slice/Grammar.cpp"
    break;

  case 216: /* keyword: ICE_EXCEPTION  */
#line 2500 "src/Slice/Grammar.y"
                {}
#line 4543 "src/Slice/Grammar.cpp"
    break;

  case 217: /* keyword: ICE_STRUCT  */
#line 2501 "src/Slice/Grammar.y"
             {}
#line 4549 "src/Slice/Grammar.cpp"
    break;

  case 218: /* keyword: ICE_SEQUENCE  */
#line 2502 "src/Slice/Grammar.y"
               {}
#line 4555 "src/Slice/Grammar.cpp"
    break;

  case 219: /* keyword: ICE_DICTIONARY  */
#line 2503 "src/Slice/Grammar.y"
                 {}
#line 4561 "src/Slice/Grammar.cpp"
    break;

  case 220: /* keyword: ICE_ENUM  */
#line 2504 "src/Slice/Grammar.y"
           {}
#line 4567 "src/Slice/Grammar.cpp"
    break;

  case 221: /* keyword: ICE_OUT  */
#line 2505 "src/Slice/Grammar.y"
          {}
#line 4573 "src/Slice/Grammar.cpp"
    break;

  case 222: /* keyword: ICE_EXTENDS  */
#line 2506 "src/Slice/Grammar.y"
              {}
#line 4579 "src/Slice/Grammar.cpp"
    break;

  case 223: /* keyword: ICE_IMPLEMENTS  */
#line 2507 "src/Slice/Grammar.y"
                 {}
#line 4585 "src/Slice/Grammar.cpp"
    break;

  case 224: /* keyword: ICE_THROWS  */
#line 2508 "src/Slice/Grammar.y"
             {}
#line 4591 "src/Slice/Grammar.cpp"
    break;

  case 225: /* keyword: ICE_VOID  */
#line 2509 "src/Slice/Grammar.y"
           {}
#line 4597 "src/Slice/Grammar.cpp"
    break;

  case 226: /* keyword: ICE_BOOL  */
#line 2510 "src/Slice/Grammar.y"
           {}
#line 4603 "src/Slice/Grammar.cpp"
    break;

  case 227: /* keyword: ICE_BYTE  */
#line 2511 "src/Slice/Grammar.y"
           {}
#line 4609 "src/Slice/Grammar.cpp"
    break;

  case 228: /* keyword: ICE_SHORT  */
#line 2512 "src/Slice/Grammar.y"
            {}
#line 4615 "src/Slice/Grammar.cpp"
    break;

  case 229: /* keyword: ICE_USHORT  */
#line 2513 "src/Slice/Grammar.y"
             {}
#line 4621 "src/Slice/Grammar.cpp"
    break;

  case 230: /* keyword: ICE_INT  */
#line 2514 "src/Slice/Grammar.y"
          {}
#line 4627 "src/Slice/Grammar.cpp"
    break;

  case 231: /* keyword: ICE_UINT  */
#line 2515 "src/Slice/Grammar.y"
           {}
#line 4633 "src/Slice/Grammar.cpp"
    break;

  case 232: /* keyword: ICE_VARINT  */
#line 2516 "src/Slice/Grammar.y"
             {}
#line 4639 "src/Slice/Grammar.cpp"
    break;

  case 233: /* keyword: ICE_VARUINT  */
#line 2517 "src/Slice/Grammar.y"
              {}
#line 4645 "src/Slice/Grammar.cpp"
    break;

  case 234: /* keyword: ICE_LONG  */
#line 2518 "src/Slice/Grammar.y"
           {}
#line 4651 "src/Slice/Grammar.cpp"
    break;

  case 235: /* keyword: ICE_ULONG  */
#line 2519 "src/Slice/Grammar.y"
            {}
#line 4657 "src/Slice/Grammar.cpp"
    break;

  case 236: /* keyword: ICE_VARLONG  */
#line 2520 "src/Slice/Grammar.y"
              {}
#line 4663 "src/Slice/Grammar.cpp"
    break;

  case 237: /* keyword: ICE_VARULONG  */
#line 2521 "src/Slice/Grammar.y"
               {}
#line 4669 "src/Slice/Grammar.cpp"
    break;

  case 238: /* keyword: ICE_FLOAT  */
#line 2522 "src/Slice/Grammar.y"
            {}
#line 4675 "src/Slice/Grammar.cpp"
    break;

  case 239: /* keyword: ICE_DOUBLE  */
#line 2523 "src/Slice/Grammar.y"
             {}
#line 4681 "src/Slice/Grammar.cpp"
    break;

  case 240: /* keyword: ICE_STRING  */
#line 2524 "src/Slice/Grammar.y"
             {}
#line 4687 "src/Slice/Grammar.cpp"
    break;

  case 241: /* keyword: ICE_OBJECT  */
#line 2525 "src/Slice/Grammar.y"
             {}
#line 4693 "src/Slice/Grammar.cpp"
    break;

  case 242: /* keyword: ICE_CONST  */
#line 2526 "src/Slice/Grammar.y"
            {}
#line 4699 "src/Slice/Grammar.cpp"
    break;

  case 243: /* keyword: ICE_FALSE  */
#line 2527 "src/Slice/Grammar.y"
            {}
#line 4705 "src/Slice/Grammar.cpp"
    break;

  case 244: /* keyword: ICE_TRUE  */
#line 2528 "src/Slice/Grammar.y"
           {}
#line 4711 "src/Slice/Grammar.cpp"
    break;

  case 245: /* keyword: ICE_IDEMPOTENT  */
#line 2529 "src/Slice/Grammar.y"
                 {}
#line 4717 "src/Slice/Grammar.cpp"
    break;

  case 246: /* keyword: ICE_TAG  */
#line 2530 "src/Slice/Grammar.y"
          {}
#line 4723 "src/Slice/Grammar.cpp"
    break;

  case 247: /* keyword: ICE_OPTIONAL  */
#line 2531 "src/Slice/Grammar.y"
               {}
#line 4729 "src/Slice/Grammar.cpp"
    break;

  case 248: /* keyword: ICE_ANYCLASS  */
#line 2532 "src/Slice/Grammar.y"
               {}
#line 4735 "src/Slice/Grammar.cpp"
    break;

  case 249: /* keyword: ICE_VALUE  */
#line 2533 "src/Slice/Grammar.y"
            {}
#line 4741 "src/Slice/Grammar.cpp"
    break;


#line 4745 "src/Slice/Grammar.cpp"

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

#line 2536 "src/Slice/Grammar.y"

