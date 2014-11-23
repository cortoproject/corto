/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.

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

#ifndef YY_YY_SRC_Y_TAB_H_INCLUDED
# define YY_YY_SRC_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    ERROR = 258,
    BOOLEAN = 259,
    CHARACTER = 260,
    INTEGER = 261,
    SIGNEDINTEGER = 262,
    FLOATINGPOINT = 263,
    STRING = 264,
    NUL = 265,
    ID = 266,
    GID = 267,
    MUL_ASSIGN = 268,
    DIV_ASSIGN = 269,
    ADD_ASSIGN = 270,
    SUB_ASSIGN = 271,
    OR_ASSIGN = 272,
    AND_ASSIGN = 273,
    LOR = 274,
    LAND = 275,
    LNOT = 276,
    LEQ = 277,
    GEQ = 278,
    EQ = 279,
    NEQ = 280,
    INC = 281,
    DEC = 282,
    SCOPE = 283,
    SCOPEPRE = 284,
    SHIFT_LEFT = 285,
    SHIFT_RIGHT = 286,
    ARROW_LEFT = 287,
    ARROW_RIGHT = 288,
    INDENT = 289,
    DEDENT = 290,
    KW_UPDATE = 291,
    KW_DECLARE = 292,
    KW_DEFINE = 293,
    KW_DESTRUCT = 294,
    KW_ON = 295,
    KW_SCOPE = 296,
    KW_SELF = 297,
    KW_SYNCHRONIZED = 298,
    KW_IF = 299,
    KW_ELSE = 300,
    KW_WHILE = 301,
    KW_SWITCH = 302,
    KW_CASE = 303,
    KW_DEFAULT = 304,
    KW_BREAK = 305,
    KW_FOR = 306,
    KW_WAIT = 307,
    KW_TRY = 308,
    KW_CATCH = 309,
    KW_IMPORT = 310,
    KW_LOCAL = 311,
    KW_VIRTUAL = 312
  };
#endif
/* Tokens.  */
#define ERROR 258
#define BOOLEAN 259
#define CHARACTER 260
#define INTEGER 261
#define SIGNEDINTEGER 262
#define FLOATINGPOINT 263
#define STRING 264
#define NUL 265
#define ID 266
#define GID 267
#define MUL_ASSIGN 268
#define DIV_ASSIGN 269
#define ADD_ASSIGN 270
#define SUB_ASSIGN 271
#define OR_ASSIGN 272
#define AND_ASSIGN 273
#define LOR 274
#define LAND 275
#define LNOT 276
#define LEQ 277
#define GEQ 278
#define EQ 279
#define NEQ 280
#define INC 281
#define DEC 282
#define SCOPE 283
#define SCOPEPRE 284
#define SHIFT_LEFT 285
#define SHIFT_RIGHT 286
#define ARROW_LEFT 287
#define ARROW_RIGHT 288
#define INDENT 289
#define DEDENT 290
#define KW_UPDATE 291
#define KW_DECLARE 292
#define KW_DEFINE 293
#define KW_DESTRUCT 294
#define KW_ON 295
#define KW_SCOPE 296
#define KW_SELF 297
#define KW_SYNCHRONIZED 298
#define KW_IF 299
#define KW_ELSE 300
#define KW_WHILE 301
#define KW_SWITCH 302
#define KW_CASE 303
#define KW_DEFAULT 304
#define KW_BREAK 305
#define KW_FOR 306
#define KW_WAIT 307
#define KW_TRY 308
#define KW_CATCH 309
#define KW_IMPORT 310
#define KW_LOCAL 311
#define KW_VIRTUAL 312

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 129 "src/fast.y" /* yacc.c:1909  */

	/* Literals */
    db_bool Boolean;
    db_char Character;
    db_uint64 Integer;
    db_int64 SignedInteger;
    db_float64 FloatingPoint;
    db_string String;
    db_object Reference;
    db_string Identifier;
    db_ll List;
    void *Null;
    void *Fast;
    db_operatorKind Operator;
    int Mask;
    Fast_ParserDeclaration Declaration;
    Fast_ParserDeclarationSeq Declarations;
    Fast_ParserNew New;
    Fast_Variable Variable;

#line 189 "src/y.tab.h" /* yacc.c:1909  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_SRC_Y_TAB_H_INCLUDED  */
