/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
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
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_SRC_ICESTORM_GRAMMAR_H_INCLUDED
#define YY_YY_SRC_ICESTORM_GRAMMAR_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
#    define YYDEBUG 1
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 9 "src/IceStorm/Grammar.y"

// I must set the initial stack depth to the maximum stack depth to
// disable bison stack resizing. The bison stack resizing routines use
// simple malloc/alloc/memcpy calls, which do not work for the
// YYSTYPE, since YYSTYPE is a C++ type, with constructor, destructor,
// assignment operator, etc.
#define YYMAXDEPTH 10000       // 10000 should suffice. Bison default is 10000 as maximum.
#define YYINITDEPTH YYMAXDEPTH // Initial depth is set to max depth, for the reasons described above.

// Newer bison versions allow to disable stack resizing by defining yyoverflow.
#define yyoverflow(a, b, c, d, e, f) yyerror(a)

#line 64 "src/IceStorm/Grammar.h"

/* Token kinds.  */
#ifndef YYTOKENTYPE
#    define YYTOKENTYPE
enum yytokentype
{
    YYEMPTY = -2,
    YYEOF = 0,                   /* "end of file"  */
    YYerror = 256,               /* error  */
    YYUNDEF = 257,               /* "invalid token"  */
    ICE_STORM_HELP = 258,        /* ICE_STORM_HELP  */
    ICE_STORM_EXIT = 259,        /* ICE_STORM_EXIT  */
    ICE_STORM_CURRENT = 260,     /* ICE_STORM_CURRENT  */
    ICE_STORM_CREATE = 261,      /* ICE_STORM_CREATE  */
    ICE_STORM_DESTROY = 262,     /* ICE_STORM_DESTROY  */
    ICE_STORM_LINK = 263,        /* ICE_STORM_LINK  */
    ICE_STORM_UNLINK = 264,      /* ICE_STORM_UNLINK  */
    ICE_STORM_LINKS = 265,       /* ICE_STORM_LINKS  */
    ICE_STORM_TOPICS = 266,      /* ICE_STORM_TOPICS  */
    ICE_STORM_REPLICA = 267,     /* ICE_STORM_REPLICA  */
    ICE_STORM_SUBSCRIBERS = 268, /* ICE_STORM_SUBSCRIBERS  */
    ICE_STORM_STRING = 269       /* ICE_STORM_STRING  */
};
typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if !defined YYSTYPE && !defined YYSTYPE_IS_DECLARED
typedef std::list<std::string> YYSTYPE;
#    define YYSTYPE_IS_TRIVIAL 1
#    define YYSTYPE_IS_DECLARED 1
#endif

int yyparse(void);

#endif /* !YY_YY_SRC_ICESTORM_GRAMMAR_H_INCLUDED  */
