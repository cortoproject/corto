/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison implementation for Yacc-like parsers in C

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.0.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "src/fast.y" /* yacc.c:339  */


#include "hyve.h"
#include "Fast__type.h"
#include "Fast__api.h"

#include "fast_pp.h"
#include "Fast_Parser.h"
#include "Fast_CommaExpr.h"

/* Forward declarations of yacc functions */
void yyerror(const char *str);
int yylex(void);
int yylex_destroy(void);
int yy_scan_string(const char* str);

#define PUSHLVALUE(l) Fast_Parser_pushLvalue(yparser(), l, FALSE); fast_op;
#define PUSHASSIGN(l)    Fast_Parser_pushLvalue(yparser(), l, TRUE); fast_op;
#define POPLVALUE()   Fast_Parser_popLvalue(yparser()); fast_op;

#define PUSHCOMPLEX(l) Fast_Parser_pushComplexType(yparser(), l); fast_op;
#define POPCOMPLEX() Fast_Parser_popComplexType(yparser()); fast_op;

/* Thread local storage key for parser */
extern db_threadKey FAST_PARSER_KEY;

/* Obtain parser */
Fast_Parser yparser(void) {
	return (Fast_Parser)db_threadTlsGet(FAST_PARSER_KEY);
}

#define fast_err(...) _fast_err(__VA_ARGS__); YYERROR;
#define fast_op if (Fast_Parser_isAbortSet(yparser())) {YYABORT;} else if (Fast_Parser_isErrSet(yparser())) {YYERROR;}

/* Report error */
void _fast_err(db_string msg, ...) {
	va_list args;
	char msgbuff[1024];
	
	va_start(args, msg);	
	vsprintf(msgbuff, msg, args);	
	va_end(args);
	
	printf("%s:%d:%d error: %s near token '%s'\n", yparser()->filename, yparser()->line, yparser()->column, msgbuff, yparser()->token);
	
	yparser()->errors++;
}

void Fast_declarationSeqInsert( Fast_ParserDeclarationSeq *seq, Fast_ParserDeclaration *declaration )
{
	seq->length++;
	seq->buffer = db_realloc(seq->buffer, sizeof(Fast_ParserDeclaration) * seq->length);
	memcpy(&seq->buffer[seq->length-1], declaration, sizeof(Fast_ParserDeclaration));
	seq->buffer[seq->length-1].name = db_strdup(seq->buffer[seq->length-1].name);
}

Fast_Expression Fast_declarationSeqDo(Fast_Variable type, Fast_ParserDeclarationSeq *declarations, db_bool isReference)
{
	unsigned int i;
    Fast_CommaExpr result = Fast_CommaExpr__create();
    Fast_Expression expr = NULL;
    
    Fast_Parser_collect(yparser(), result);
	yparser()->variableCount = 0;
	for(i=0; i<declarations->length; i++)
	{
		if (!(declarations->buffer[i].variable = Fast_Parser_declaration(
			yparser(),
			type,
			declarations->buffer[i].name,
			isReference))) {
                return NULL;
        }
		db_dealloc(declarations->buffer[i].name);
        expr = Fast_Expression(declarations->buffer[i].variable);
        
        /* In a declaration of locals assignment is always a reference-assignment. */
        if (isReference) {
            expr = Fast_Expression(Fast_Parser_unaryExpr(yparser(), expr, DB_AND));
            Fast_Parser_collect(yparser(), expr);
        }
        
        Fast_CommaExpr_addExpression(result, expr);
	}
	db_dealloc(declarations->buffer);
	declarations->buffer = NULL;
	declarations->length = 0;

    return Fast_Expression(result);
}


#line 159 "src/y.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
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
#line 129 "src/fast.y" /* yacc.c:355  */

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

#line 334 "src/y.tab.c" /* yacc.c:355  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_SRC_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 349 "src/y.tab.c" /* yacc.c:358  */

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

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

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
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


#if ! defined yyoverflow || YYERROR_VERBOSE

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
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  109
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1296

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  83
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  116
/* YYNRULES -- Number of rules.  */
#define YYNRULES  257
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  351

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   312

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    73,     2,     2,     2,    76,    61,     2,
      62,    63,    74,    77,    64,    71,    70,    75,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    59,    58,
      80,    60,    81,    82,    67,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    68,     2,    69,    78,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    65,    79,    66,    72,     2,     2,     2,
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
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   200,   200,   204,   205,   206,   210,   211,   212,   213,
     214,   215,   215,   216,   217,   218,   219,   220,   227,   228,
     229,   229,   230,   230,   234,   235,   242,   246,   246,   247,
     247,   248,   255,   255,   256,   256,   268,   269,   277,   280,
     281,   289,   293,   294,   298,   299,   303,   304,   311,   312,
     312,   316,   317,   321,   322,   326,   333,   334,   338,   339,
     343,   344,   345,   349,   349,   349,   350,   354,   358,   359,
     363,   363,   364,   368,   368,   369,   376,   377,   378,   379,
     380,   381,   382,   386,   386,   390,   391,   392,   396,   397,
     397,   398,   399,   400,   401,   402,   406,   407,   411,   412,
     413,   414,   415,   416,   417,   421,   422,   422,   422,   426,
     427,   428,   432,   433,   433,   433,   437,   438,   442,   443,
     443,   443,   444,   444,   444,   448,   449,   449,   449,   453,
     454,   454,   454,   458,   459,   459,   459,   463,   464,   464,
     464,   468,   469,   470,   471,   475,   476,   476,   476,   480,
     481,   485,   486,   486,   486,   490,   491,   491,   491,   495,
     495,   496,   500,   501,   505,   506,   519,   520,   520,   520,
     526,   527,   528,   529,   530,   531,   532,   536,   537,   538,
     542,   543,   543,   549,   554,   554,   555,   556,   556,   569,
     576,   577,   577,   586,   587,   591,   592,   593,   594,   595,
     596,   597,   598,   599,   600,   601,   602,   603,   604,   605,
     606,   607,   608,   609,   610,   611,   612,   613,   614,   615,
     616,   623,   624,   625,   629,   636,   637,   641,   648,   649,
     653,   654,   655,   656,   660,   664,   665,   669,   670,   677,
     678,   682,   683,   687,   691,   692,   696,   697,   698,   702,
     703,   704,   705,   709,   710,   711,   718,   719
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "ERROR", "BOOLEAN", "CHARACTER",
  "INTEGER", "SIGNEDINTEGER", "FLOATINGPOINT", "STRING", "NUL", "ID",
  "GID", "MUL_ASSIGN", "DIV_ASSIGN", "ADD_ASSIGN", "SUB_ASSIGN",
  "OR_ASSIGN", "AND_ASSIGN", "LOR", "LAND", "LNOT", "LEQ", "GEQ", "EQ",
  "NEQ", "INC", "DEC", "SCOPE", "SCOPEPRE", "SHIFT_LEFT", "SHIFT_RIGHT",
  "ARROW_LEFT", "ARROW_RIGHT", "INDENT", "DEDENT", "KW_UPDATE",
  "KW_DECLARE", "KW_DEFINE", "KW_DESTRUCT", "KW_ON", "KW_SCOPE", "KW_SELF",
  "KW_SYNCHRONIZED", "KW_IF", "KW_ELSE", "KW_WHILE", "KW_SWITCH",
  "KW_CASE", "KW_DEFAULT", "KW_BREAK", "KW_FOR", "KW_WAIT", "KW_TRY",
  "KW_CATCH", "KW_IMPORT", "KW_LOCAL", "KW_VIRTUAL", "';'", "':'", "'='",
  "'&'", "'('", "')'", "','", "'{'", "'}'", "'@'", "'['", "']'", "'.'",
  "'-'", "'~'", "'!'", "'*'", "'/'", "'%'", "'+'", "'^'", "'|'", "'<'",
  "'>'", "'?'", "$accept", "code", "statements", "statement", "@1",
  "scope", "$@2", "$@3", "scope_statement", "block_start", "block", "$@4",
  "@5", "function_implementation", "@6", "@7", "function_declaration",
  "function_argumentList", "function_arguments", "function_argument",
  "declaration", "$@8", "declaration_ref", "declaration_list",
  "declaration_id", "initializer", "init_list_value", "init_value",
  "initializer_braces", "$@9", "$@10", "init_value_indent",
  "init_list_colon", "init_colon", "$@11", "init_key", "$@12",
  "literal_expr", "bracket_expr", "$@13", "primary_expr", "postfix_expr",
  "$@14", "unary_expr", "unary_operator", "multiplicative_expr", "$@15",
  "$@16", "multiplicative_operator", "additive_expr", "$@17", "$@18",
  "additive_operator", "shift_expr", "$@19", "$@20", "$@21", "$@22",
  "and_expr", "$@23", "$@24", "xor_expr", "$@25", "$@26", "or_expr",
  "$@27", "$@28", "boolean_expr", "$@29", "$@30", "boolean_operator",
  "equality_expr", "$@31", "$@32", "equality_operator", "logical_and_expr",
  "$@33", "$@34", "logical_or_expr", "$@35", "$@36", "initializer_expr",
  "@37", "conditional_expr", "comma_expr", "assignment_expr", "$@38",
  "$@39", "assignment_operator", "wait_expr", "declaration_expr", "$@40",
  "$@41", "$@42", "expr", "identifier", "@43", "identifier_id", "any_id",
  "if_statement", "if_start", "while_statement", "while_until",
  "switch_statement", "switch_statements", "case_statement", "case_list",
  "case_label", "observer_statement", "observer_declaration",
  "observer_dispatch", "event_mask", "event_flag", "event_baseflag",
  "event_childflag", "update_statement", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,    59,    58,
      61,    38,    40,    41,    44,   123,   125,    64,    91,    93,
      46,    45,   126,    33,    42,    47,    37,    43,    94,   124,
      60,    62,    63
};
# endif

#define YYPACT_NINF -283

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-283)))

#define YYTABLE_NINF -243

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     337,  -283,  -283,  -283,  -283,  -283,  -283,  -283,  -283,  -283,
    -283,  -283,  -283,  -283,  1184,  -283,  1184,  1184,  1184,  1223,
    -283,    19,  -283,  -283,  1222,  -283,  -283,  -283,    18,   477,
    -283,  -283,   337,  -283,  -283,   141,   167,  -283,  -283,  -283,
     109,  -283,    33,   154,   -41,   143,   -26,   -21,    -6,     5,
      74,    96,   101,    64,    75,  -283,   117,   133,   129,  -283,
     137,    54,  -283,  -283,  -283,   144,  -283,   148,  -283,  -283,
     151,  1037,  -283,   164,   102,  -283,  -283,   160,   131,    35,
    -283,  -283,   967,  1184,  -283,  -283,  -283,  -283,  -283,  -283,
    -283,  -283,  -283,  -283,  -283,  -283,  -283,  -283,  -283,  -283,
    -283,  -283,  -283,  -283,  -283,  -283,  -283,  -283,  -283,  -283,
    -283,   206,   477,  -283,   144,   172,  -283,    20,  -283,  -283,
    -283,   190,    44,  -283,   210,   109,   163,    68,   228,   242,
     218,   202,   204,    11,   219,   264,   266,  1223,   220,  -283,
    1223,   116,   135,  -283,   225,    47,   224,  -283,    75,   225,
     244,  -283,  -283,  -283,  -283,  -283,  -283,  -283,  -283,  -283,
    -283,  -283,   188,   255,  -283,   199,  -283,  -283,  -283,   407,
    1223,  -283,    57,  -283,   227,   547,   257,  -283,   258,  -283,
    1079,  1111,  1223,  -283,  -283,  1079,  -283,  -283,  -283,  1223,
    -283,  -283,  1223,  1223,  1223,  1223,  1223,  1223,  -283,  -283,
    -283,  -283,  1223,  -283,  -283,  1223,  1223,  1223,   233,  -283,
    1111,  -283,  -283,  -283,  -283,  -283,  -283,  -283,  -283,  1223,
    1111,    13,  -283,   225,   225,    44,  -283,    44,   124,   175,
     191,  -283,   203,  1184,   235,  -283,   617,  -283,   103,  -283,
     101,    44,   224,  -283,  -283,   337,  -283,   261,   967,  -283,
     196,   238,    58,  1111,  1222,   234,  -283,  -283,  -283,  -283,
      99,  -283,   240,   243,   101,   246,   117,   232,  -283,   154,
     -41,   -41,   143,   -26,   -21,    -6,     5,    74,    96,  1223,
     234,   117,   234,  -283,   205,  -283,    61,  -283,    44,  -283,
    -283,  -283,  -283,  -283,   108,   247,  -283,   203,  -283,  -283,
     687,  -283,   224,   757,   337,  -283,  -283,    17,    75,  1111,
    -283,  -283,   246,  1153,  -283,  -283,  -283,  -283,  -283,  -283,
    -283,  -283,  -283,  -283,  -283,  -283,  -283,  -283,   231,  -283,
    -283,    35,    44,  -283,  -283,  -283,  -283,   827,  -283,   897,
    -283,  -283,  -283,  -283,  1153,  -283,  -283,  -283,   203,  -283,
    -283
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       0,     5,    76,    77,    78,    79,    80,    81,    82,   195,
     193,   101,   102,   103,   159,   243,   159,   159,   159,   159,
      49,    29,   104,    83,     0,    98,    99,   100,     0,     2,
       3,    11,     0,    17,    14,    32,    25,    86,    85,    88,
      96,   105,     0,   112,   118,   125,   129,   133,   137,   145,
     151,   155,   161,   162,     0,   164,   166,   167,   180,   189,
      24,    87,   190,   194,     7,     0,     8,     0,     9,    15,
       0,   159,    16,     0,    87,   224,   227,     0,   167,     0,
      26,    31,   159,   159,   219,   218,   220,   197,   198,   199,
     200,   202,   196,   203,   204,   205,   206,   207,   208,   209,
     210,   211,   212,   201,   213,   214,   215,   216,   217,     1,
       4,     0,    27,    13,     0,     0,    10,   184,   187,    94,
      95,    83,     0,    92,     0,    97,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   159,    63,   160,
     159,     0,   181,     6,     0,     0,    48,    53,     0,    55,
     221,   226,   225,   240,   239,   249,   250,   251,   252,   254,
     253,   255,   167,   159,   244,   246,   247,   256,   257,   159,
       0,    50,   191,    30,     0,   159,    22,    12,     0,    33,
     159,     0,   159,    91,    93,   159,   109,   110,   111,     0,
     117,   116,     0,     0,     0,     0,     0,     0,   143,   144,
     141,   142,     0,   149,   150,     0,     0,     0,     0,    66,
       0,   165,   173,   174,   171,   172,   176,   175,   170,   159,
       0,     0,    38,     0,     0,     0,   192,    36,     0,     0,
     167,   248,     0,   159,     0,   230,   159,   231,     0,   235,
     179,     0,    51,    55,    84,     0,    19,     0,   159,    28,
       0,     0,    87,     0,    73,   185,    56,    58,    60,    62,
      59,    68,     0,    86,    61,   194,   188,     0,   107,   114,
     120,   123,   127,   131,   135,   139,   147,   153,   157,   159,
      64,   168,   182,    42,     0,    44,   191,    41,    39,    54,
      37,   222,   223,   245,     0,     0,   238,   229,   232,   233,
     159,   236,    52,   159,     0,    23,    35,     0,     0,     0,
      69,    75,     0,     0,    70,    90,   108,   115,   121,   124,
     128,   132,   136,   140,   148,   154,   158,   163,     0,   169,
      43,     0,     0,    46,    40,   234,   237,   159,    18,   159,
      67,    74,    57,    72,     0,    65,    45,    47,   228,    21,
      71
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -283,  -283,   -30,   -28,  -283,  -283,  -283,  -283,  -283,  -283,
     -50,  -283,  -283,  -283,  -283,  -283,  -283,  -136,  -283,   -24,
    -110,  -283,  -283,  -158,    83,   -66,     1,  -282,   -51,  -283,
    -283,  -283,  -283,    52,  -283,  -283,  -283,  -159,   -29,  -283,
    -283,   271,  -283,   125,  -283,   123,  -283,  -283,  -283,    77,
    -283,  -283,  -283,   126,  -283,  -283,  -283,  -283,   122,  -283,
    -283,   127,  -283,  -283,   118,  -283,  -283,   114,  -283,  -283,
    -283,   119,  -283,  -283,  -283,   128,  -283,  -283,  -160,  -283,
    -283,  -283,  -283,  -121,  -156,   -15,  -283,  -283,  -283,    -9,
    -283,  -283,  -283,  -283,   -42,     0,  -283,  -283,   -55,    95,
    -283,  -283,  -283,  -283,    29,  -224,   161,  -167,  -283,  -283,
    -283,  -283,   104,  -283,   171,  -283
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    28,    29,    30,   111,   177,   247,   248,    31,    32,
      33,   178,    82,    34,   114,   115,    35,   222,   284,   285,
      36,    79,   171,   146,   147,   255,   256,   257,   258,   210,
     328,   259,   260,   261,   344,   262,   308,    37,    38,    83,
      39,    40,   124,    41,    42,    43,   126,   316,   189,    44,
     127,   317,   192,    45,   128,   318,   129,   319,    46,   130,
     320,    47,   131,   321,    48,   132,   322,    49,   133,   323,
     202,    50,   134,   324,   205,    51,   135,   325,    52,   136,
     326,    53,    54,    55,    56,    57,   141,   329,   219,    58,
      59,   220,   181,   182,    60,    74,   148,    62,    63,    64,
      65,    66,    67,    68,   236,   237,   294,   239,    69,    70,
      71,   163,   164,   165,   166,    72
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      61,   110,   112,   139,    78,    73,   149,    75,    76,    77,
     240,   123,   299,   227,   242,   150,   208,   152,   109,   211,
     154,   264,   263,   168,     9,    10,   266,  -138,  -138,    61,
    -113,   343,    61,   198,   199,  -126,  -113,     2,     3,     4,
       5,     6,     7,     8,     9,    10,     9,    10,  -186,  -186,
     264,   263,   340,    80,   173,     9,   162,  -130,     9,   223,
     264,   263,   350,   281,   179,     9,   144,   184,     9,     9,
     250,   301,     9,  -134,   174,   250,   283,    81,  -186,   172,
      24,   309,    61,   302,   110,  -138,  -138,   287,   288,  -186,
     224,   200,   201,   264,   263,    23,   123,   226,  -146,  -146,
      24,   311,    24,     2,     3,     4,     5,     6,     7,     8,
       9,    24,    61,   299,    24,   145,  -152,   243,   241,  -191,
    -156,    24,   332,  -191,    24,    24,   265,   301,    24,   212,
     213,   214,   215,   216,   217,   119,   120,   300,   251,   190,
     138,   235,   335,   267,   280,   191,   137,   246,   230,   264,
     263,   233,   234,   264,   282,   265,   233,   234,   327,  -178,
    -178,  -177,  -177,  -183,  -183,   265,   254,  -191,    16,    61,
     243,   121,   290,  -119,  -122,    61,   218,   -89,   291,   122,
     252,   140,   170,    21,   264,   252,   243,   307,   142,  -178,
    -178,  -177,  -177,  -183,  -178,   143,  -177,   243,   265,   113,
    -178,   -34,  -177,    21,  -183,   312,   151,    21,   298,   153,
      21,   155,   156,   157,   158,   303,   159,   160,   161,   169,
     305,   286,   167,    21,   295,   116,   117,   118,  -106,  -106,
    -106,   333,   180,   334,   175,   176,    61,   186,   187,   188,
     159,   160,   161,   203,   204,    61,  -242,  -242,    61,  -241,
    -241,   233,   234,   183,   265,   117,   118,   341,   193,     2,
       3,     4,     5,     6,     7,     8,     9,    10,   330,   331,
     270,   271,   235,   194,   339,   110,    11,   347,   185,   195,
     196,    12,    13,   197,   206,   207,   209,   221,   225,   228,
     244,   -20,   279,   249,   296,   304,   306,   345,   309,   313,
      61,   315,   -75,    61,    61,   314,   336,   346,   289,   298,
     342,   110,   310,   125,   268,   269,    22,    23,   273,   276,
     275,   272,    24,   292,   274,   277,    25,    26,    27,   337,
     238,   286,     0,   293,   229,   278,   231,    61,     1,    61,
       0,     2,     3,     4,     5,     6,     7,     8,     9,    10,
       0,     0,     0,     0,     0,     0,     0,     0,    11,     0,
       0,     0,     0,    12,    13,     0,     0,     0,     0,     0,
       0,     0,     0,    14,     0,     0,     0,    15,     0,     0,
       0,    16,     0,    17,    18,     0,     0,     0,     0,    19,
       0,     0,     0,    20,     0,     0,    21,     0,    22,    23,
       0,     0,  -159,     0,    24,     0,     0,     0,    25,    26,
      27,     2,     3,     4,     5,     6,     7,     8,     9,    10,
       0,     0,     0,     0,     0,     0,     0,     0,    11,     0,
       0,     0,     0,    12,    13,     0,     0,     0,     0,     0,
       0,     0,   232,    14,     0,     0,     0,    15,     0,     0,
       0,    16,     0,    17,    18,   233,   234,     0,     0,    19,
       0,     0,     0,    20,     0,     0,    21,     0,    22,    23,
       0,     0,     0,     0,    24,     0,     0,     0,    25,    26,
      27,     2,     3,     4,     5,     6,     7,     8,     9,    10,
       0,     0,     0,     0,     0,     0,     0,     0,    11,     0,
       0,     0,     0,    12,    13,     0,     0,     0,     0,     0,
       0,     0,     0,    14,     0,     0,     0,    15,     0,     0,
       0,    16,     0,    17,    18,     0,     0,     0,     0,    19,
       0,     0,     0,    20,     0,     0,    21,     0,    22,    23,
       0,     0,  -159,     0,    24,     0,     0,     0,    25,    26,
      27,     2,     3,     4,     5,     6,     7,     8,     9,    10,
       0,     0,     0,     0,     0,     0,     0,     0,    11,     0,
       0,     0,     0,    12,    13,     0,     0,     0,     0,     0,
       0,   245,     0,    14,     0,     0,     0,    15,     0,     0,
       0,    16,     0,    17,    18,     0,     0,     0,     0,    19,
       0,     0,     0,    20,     0,     0,    21,     0,    22,    23,
       0,     0,     0,     0,    24,     0,     0,     0,    25,    26,
      27,     2,     3,     4,     5,     6,     7,     8,     9,    10,
       0,     0,     0,     0,     0,     0,     0,     0,    11,     0,
       0,     0,     0,    12,    13,     0,     0,     0,     0,     0,
       0,     0,   297,    14,     0,     0,     0,    15,     0,     0,
       0,    16,     0,    17,    18,     0,     0,     0,     0,    19,
       0,     0,     0,    20,     0,     0,    21,     0,    22,    23,
       0,     0,     0,     0,    24,     0,     0,     0,    25,    26,
      27,     2,     3,     4,     5,     6,     7,     8,     9,    10,
       0,     0,     0,     0,     0,     0,     0,     0,    11,     0,
       0,     0,     0,    12,    13,     0,     0,     0,     0,     0,
       0,     0,   232,    14,     0,     0,     0,    15,     0,     0,
       0,    16,     0,    17,    18,     0,     0,     0,     0,    19,
       0,     0,     0,    20,     0,     0,    21,     0,    22,    23,
       0,     0,     0,     0,    24,     0,     0,     0,    25,    26,
      27,     2,     3,     4,     5,     6,     7,     8,     9,    10,
       0,     0,     0,     0,     0,     0,     0,     0,    11,     0,
       0,     0,     0,    12,    13,     0,     0,     0,     0,     0,
       0,     0,   338,    14,     0,     0,     0,    15,     0,     0,
       0,    16,     0,    17,    18,     0,     0,     0,     0,    19,
       0,     0,     0,    20,     0,     0,    21,     0,    22,    23,
       0,     0,     0,     0,    24,     0,     0,     0,    25,    26,
      27,     2,     3,     4,     5,     6,     7,     8,     9,    10,
       0,     0,     0,     0,     0,     0,     0,     0,    11,     0,
       0,     0,     0,    12,    13,     0,     0,     0,     0,     0,
       0,     0,   348,    14,     0,     0,     0,    15,     0,     0,
       0,    16,     0,    17,    18,     0,     0,     0,     0,    19,
       0,     0,     0,    20,     0,     0,    21,     0,    22,    23,
       0,     0,     0,     0,    24,     0,     0,     0,    25,    26,
      27,     2,     3,     4,     5,     6,     7,     8,     9,    10,
       0,     0,     0,     0,     0,     0,     0,     0,    11,     0,
       0,     0,     0,    12,    13,     0,     0,     0,     0,     0,
       0,     0,   349,    14,     0,     0,     0,    15,     0,     0,
       0,    16,     0,    17,    18,     0,     0,     0,     0,    19,
       0,     0,     0,    20,     0,     0,    21,     0,    22,    23,
       0,     0,     0,     0,    24,     0,     0,     0,    25,    26,
      27,     2,     3,     4,     5,     6,     7,     8,     9,    10,
       0,     0,     0,     0,     0,     0,     0,     0,    11,     0,
       0,     0,     0,    12,    13,     0,     0,     0,     0,     0,
       0,     0,     0,    14,     0,     0,     0,    15,     0,     0,
       0,    16,     0,    17,    18,     0,     0,     0,     0,    19,
       0,     0,     0,    20,     0,     0,    21,     0,    22,    23,
       0,     0,     0,     0,    24,     0,     0,     0,    25,    26,
      27,     2,     3,     4,     5,     6,     7,     8,     9,    10,
       0,     0,     0,     0,     0,     0,     0,     0,    11,     0,
       0,     0,     0,    12,    13,     0,     0,     0,     0,     0,
       0,     0,     0,   155,   156,   157,   158,     0,   159,   160,
     161,     0,     0,     2,     3,     4,     5,     6,     7,     8,
       9,    10,     0,     0,     0,     0,     0,     0,    22,    23,
      11,     0,     0,     0,    24,    12,    13,     0,    25,    26,
      27,     0,     0,     0,     0,     2,     3,     4,     5,     6,
       7,     8,     9,    10,     0,     0,     0,     0,     0,     0,
       0,    19,    11,     0,     0,    20,     0,    12,    13,     0,
      22,    23,     0,     0,     0,   253,    24,     0,     0,     0,
      25,    26,    27,     0,     0,     0,     0,     2,     3,     4,
       5,     6,     7,     8,     9,    10,     0,     0,     0,     0,
       0,     0,    22,    23,    11,     0,   138,     0,   254,    12,
      13,     0,    25,    26,    27,     0,     0,   253,     2,     3,
       4,     5,     6,     7,     8,     9,    10,     0,     0,     0,
       0,     0,     0,     0,     0,    11,     0,     0,     0,     0,
      12,    13,     0,     0,    22,    23,     0,     0,   138,     0,
      24,     0,     0,     0,    25,    26,    27,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    19,     0,     0,     0,
       0,    84,    85,    86,    11,    22,    23,     0,     0,    12,
      13,    24,     0,     0,     0,    25,    26,    27,    87,    88,
      89,    90,    91,    92,    93,    94,    95,    96,    97,    98,
      99,   100,   101,   102,   103,   104,   105,   106,   107,   108,
       0,     0,     0,     0,    22,    23,     0,     0,     0,     0,
      24,     0,     0,     0,    25,    26,    27
};

static const yytype_int16 yycheck[] =
{
       0,    29,    32,    54,    19,    14,    61,    16,    17,    18,
     170,    40,   236,   149,   172,    65,   137,    67,     0,   140,
      70,   181,   181,    73,    11,    12,   182,    22,    23,    29,
      71,   313,    32,    22,    23,    61,    77,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    11,    12,    28,    29,
     210,   210,    35,    34,    82,    11,    71,    78,    11,    12,
     220,   220,   344,   219,   114,    11,    12,   122,    11,    11,
     180,   238,    11,    79,    83,   185,    63,    58,    58,    79,
      67,    64,    82,   241,   112,    80,    81,   223,   224,    69,
     145,    80,    81,   253,   253,    62,   125,   148,    24,    25,
      67,   260,    67,     4,     5,     6,     7,     8,     9,    10,
      11,    67,   112,   337,    67,    61,    20,   172,    61,    65,
      19,    67,    61,    65,    67,    67,   181,   294,    67,    13,
      14,    15,    16,    17,    18,    26,    27,    34,   180,    71,
      65,   169,    34,   185,   210,    77,    82,   175,   163,   309,
     309,    48,    49,   313,   220,   210,    48,    49,   279,    28,
      29,    28,    29,    28,    29,   220,    67,    65,    44,   169,
     225,    62,   227,    30,    31,   175,    60,    68,   228,    70,
     180,    64,    51,    59,   344,   185,   241,   253,    59,    58,
      59,    58,    59,    58,    63,    58,    63,   252,   253,    58,
      69,    60,    69,    59,    69,   260,    58,    59,   236,    58,
      59,    36,    37,    38,    39,   245,    41,    42,    43,    59,
     248,   221,    58,    59,   233,    58,    59,    60,    74,    75,
      76,   286,    60,   288,    28,    29,   236,    74,    75,    76,
      41,    42,    43,    24,    25,   245,    58,    59,   248,    58,
      59,    48,    49,    63,   309,    59,    60,   308,    30,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    63,    64,
     193,   194,   300,    31,   304,   303,    21,   332,    68,    61,
      78,    26,    27,    79,    20,    19,    66,    62,    64,    45,
      63,    34,    59,    35,    59,    34,    58,    66,    64,    59,
     300,    69,    59,   303,   304,    59,    59,   331,   225,   337,
     309,   339,   260,    42,   189,   192,    61,    62,   196,   205,
     202,   195,    67,   228,   197,   206,    71,    72,    73,   300,
     169,   331,    -1,   229,    79,   207,   165,   337,     1,   339,
      -1,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    21,    -1,
      -1,    -1,    -1,    26,    27,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    36,    -1,    -1,    -1,    40,    -1,    -1,
      -1,    44,    -1,    46,    47,    -1,    -1,    -1,    -1,    52,
      -1,    -1,    -1,    56,    -1,    -1,    59,    -1,    61,    62,
      -1,    -1,    65,    -1,    67,    -1,    -1,    -1,    71,    72,
      73,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    21,    -1,
      -1,    -1,    -1,    26,    27,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    35,    36,    -1,    -1,    -1,    40,    -1,    -1,
      -1,    44,    -1,    46,    47,    48,    49,    -1,    -1,    52,
      -1,    -1,    -1,    56,    -1,    -1,    59,    -1,    61,    62,
      -1,    -1,    -1,    -1,    67,    -1,    -1,    -1,    71,    72,
      73,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    21,    -1,
      -1,    -1,    -1,    26,    27,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    36,    -1,    -1,    -1,    40,    -1,    -1,
      -1,    44,    -1,    46,    47,    -1,    -1,    -1,    -1,    52,
      -1,    -1,    -1,    56,    -1,    -1,    59,    -1,    61,    62,
      -1,    -1,    65,    -1,    67,    -1,    -1,    -1,    71,    72,
      73,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    21,    -1,
      -1,    -1,    -1,    26,    27,    -1,    -1,    -1,    -1,    -1,
      -1,    34,    -1,    36,    -1,    -1,    -1,    40,    -1,    -1,
      -1,    44,    -1,    46,    47,    -1,    -1,    -1,    -1,    52,
      -1,    -1,    -1,    56,    -1,    -1,    59,    -1,    61,    62,
      -1,    -1,    -1,    -1,    67,    -1,    -1,    -1,    71,    72,
      73,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    21,    -1,
      -1,    -1,    -1,    26,    27,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    35,    36,    -1,    -1,    -1,    40,    -1,    -1,
      -1,    44,    -1,    46,    47,    -1,    -1,    -1,    -1,    52,
      -1,    -1,    -1,    56,    -1,    -1,    59,    -1,    61,    62,
      -1,    -1,    -1,    -1,    67,    -1,    -1,    -1,    71,    72,
      73,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    21,    -1,
      -1,    -1,    -1,    26,    27,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    35,    36,    -1,    -1,    -1,    40,    -1,    -1,
      -1,    44,    -1,    46,    47,    -1,    -1,    -1,    -1,    52,
      -1,    -1,    -1,    56,    -1,    -1,    59,    -1,    61,    62,
      -1,    -1,    -1,    -1,    67,    -1,    -1,    -1,    71,    72,
      73,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    21,    -1,
      -1,    -1,    -1,    26,    27,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    35,    36,    -1,    -1,    -1,    40,    -1,    -1,
      -1,    44,    -1,    46,    47,    -1,    -1,    -1,    -1,    52,
      -1,    -1,    -1,    56,    -1,    -1,    59,    -1,    61,    62,
      -1,    -1,    -1,    -1,    67,    -1,    -1,    -1,    71,    72,
      73,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    21,    -1,
      -1,    -1,    -1,    26,    27,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    35,    36,    -1,    -1,    -1,    40,    -1,    -1,
      -1,    44,    -1,    46,    47,    -1,    -1,    -1,    -1,    52,
      -1,    -1,    -1,    56,    -1,    -1,    59,    -1,    61,    62,
      -1,    -1,    -1,    -1,    67,    -1,    -1,    -1,    71,    72,
      73,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    21,    -1,
      -1,    -1,    -1,    26,    27,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    35,    36,    -1,    -1,    -1,    40,    -1,    -1,
      -1,    44,    -1,    46,    47,    -1,    -1,    -1,    -1,    52,
      -1,    -1,    -1,    56,    -1,    -1,    59,    -1,    61,    62,
      -1,    -1,    -1,    -1,    67,    -1,    -1,    -1,    71,    72,
      73,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    21,    -1,
      -1,    -1,    -1,    26,    27,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    36,    -1,    -1,    -1,    40,    -1,    -1,
      -1,    44,    -1,    46,    47,    -1,    -1,    -1,    -1,    52,
      -1,    -1,    -1,    56,    -1,    -1,    59,    -1,    61,    62,
      -1,    -1,    -1,    -1,    67,    -1,    -1,    -1,    71,    72,
      73,     4,     5,     6,     7,     8,     9,    10,    11,    12,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    21,    -1,
      -1,    -1,    -1,    26,    27,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    36,    37,    38,    39,    -1,    41,    42,
      43,    -1,    -1,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    -1,    -1,    -1,    -1,    -1,    -1,    61,    62,
      21,    -1,    -1,    -1,    67,    26,    27,    -1,    71,    72,
      73,    -1,    -1,    -1,    -1,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    52,    21,    -1,    -1,    56,    -1,    26,    27,    -1,
      61,    62,    -1,    -1,    -1,    34,    67,    -1,    -1,    -1,
      71,    72,    73,    -1,    -1,    -1,    -1,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    -1,    -1,    -1,    -1,
      -1,    -1,    61,    62,    21,    -1,    65,    -1,    67,    26,
      27,    -1,    71,    72,    73,    -1,    -1,    34,     4,     5,
       6,     7,     8,     9,    10,    11,    12,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    21,    -1,    -1,    -1,    -1,
      26,    27,    -1,    -1,    61,    62,    -1,    -1,    65,    -1,
      67,    -1,    -1,    -1,    71,    72,    73,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    52,    -1,    -1,    -1,
      -1,    19,    20,    21,    21,    61,    62,    -1,    -1,    26,
      27,    67,    -1,    -1,    -1,    71,    72,    73,    36,    37,
      38,    39,    40,    41,    42,    43,    44,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      -1,    -1,    -1,    -1,    61,    62,    -1,    -1,    -1,    -1,
      67,    -1,    -1,    -1,    71,    72,    73
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    21,    26,    27,    36,    40,    44,    46,    47,    52,
      56,    59,    61,    62,    67,    71,    72,    73,    84,    85,
      86,    91,    92,    93,    96,    99,   103,   120,   121,   123,
     124,   126,   127,   128,   132,   136,   141,   144,   147,   150,
     154,   158,   161,   164,   165,   166,   167,   168,   172,   173,
     177,   178,   180,   181,   182,   183,   184,   185,   186,   191,
     192,   193,   198,   172,   178,   172,   172,   172,   168,   104,
      34,    58,    95,   122,    19,    20,    21,    36,    37,    38,
      39,    40,    41,    42,    43,    44,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,     0,
      86,    87,    85,    58,    97,    98,    58,    59,    60,    26,
      27,    62,    70,   121,   125,   124,   129,   133,   137,   139,
     142,   145,   148,   151,   155,   159,   162,    82,    65,   111,
      64,   169,    59,    58,    12,    61,   106,   107,   179,   181,
      93,    58,    93,    58,    93,    36,    37,    38,    39,    41,
      42,    43,   168,   194,   195,   196,   197,    58,    93,    59,
      51,   105,   178,    86,   172,    28,    29,    88,    94,    93,
      60,   175,   176,    63,   181,    68,    74,    75,    76,   131,
      71,    77,   135,    30,    31,    61,    78,    79,    22,    23,
      80,    81,   153,    24,    25,   157,    20,    19,   166,    66,
     112,   166,    13,    14,    15,    16,    17,    18,    60,   171,
     174,    62,   100,    12,   181,    64,   111,   100,    45,    79,
     168,   197,    35,    48,    49,    86,   187,   188,   189,   190,
     161,    61,   106,   181,    63,    34,    86,    89,    90,    35,
     103,   177,   178,    34,    67,   108,   109,   110,   111,   114,
     115,   116,   118,   120,   161,   181,   167,   177,   126,   128,
     132,   132,   136,   141,   144,   147,   150,   154,   158,    59,
     108,   167,   108,    63,   101,   102,   178,   100,   100,   107,
     181,    93,   182,   195,   189,   172,    59,    35,    86,   188,
      34,   190,   106,    85,    34,    86,    58,   108,   119,    64,
     116,   120,   181,    59,    59,    69,   130,   134,   138,   140,
     143,   146,   149,   152,   156,   160,   163,   166,   113,   170,
      63,    64,    61,   181,   181,    34,    59,   187,    35,    85,
      35,   111,   109,   110,   117,    66,   102,   181,    35,    35,
     110
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    83,    84,    85,    85,    85,    86,    86,    86,    86,
      86,    87,    86,    86,    86,    86,    86,    86,    88,    88,
      89,    88,    90,    88,    91,    91,    92,    94,    93,    95,
      93,    93,    97,    96,    98,    96,    99,    99,    99,    99,
      99,    99,   100,   100,   101,   101,   102,   102,   103,   104,
     103,   105,   105,   106,   106,   107,   108,   108,   109,   109,
     110,   110,   110,   112,   113,   111,   111,   114,   115,   115,
     117,   116,   116,   119,   118,   118,   120,   120,   120,   120,
     120,   120,   120,   122,   121,   123,   123,   123,   124,   125,
     124,   124,   124,   124,   124,   124,   126,   126,   127,   127,
     127,   127,   127,   127,   127,   128,   129,   130,   128,   131,
     131,   131,   132,   133,   134,   132,   135,   135,   136,   137,
     138,   136,   139,   140,   136,   141,   142,   143,   141,   144,
     145,   146,   144,   147,   148,   149,   147,   150,   151,   152,
     150,   153,   153,   153,   153,   154,   155,   156,   154,   157,
     157,   158,   159,   160,   158,   161,   162,   163,   161,   165,
     164,   164,   166,   166,   167,   167,   168,   169,   170,   168,
     171,   171,   171,   171,   171,   171,   171,   172,   172,   172,
     173,   174,   173,   173,   175,   173,   173,   176,   173,   177,
     178,   179,   178,   180,   180,   181,   181,   181,   181,   181,
     181,   181,   181,   181,   181,   181,   181,   181,   181,   181,
     181,   181,   181,   181,   181,   181,   181,   181,   181,   181,
     181,   182,   182,   182,   183,   184,   184,   185,   186,   186,
     187,   187,   187,   187,   188,   189,   189,   190,   190,   191,
     191,   192,   192,   193,   194,   194,   195,   195,   195,   196,
     196,   196,   196,   197,   197,   197,   198,   198
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     2,     1,     2,     1,     1,     1,
       2,     0,     3,     2,     1,     1,     1,     1,     4,     2,
       0,     5,     0,     3,     1,     1,     2,     0,     4,     0,
       3,     2,     0,     3,     0,     5,     3,     4,     3,     4,
       5,     4,     2,     3,     1,     3,     2,     3,     2,     0,
       3,     2,     3,     1,     3,     1,     1,     3,     1,     1,
       1,     1,     1,     0,     0,     5,     2,     3,     1,     2,
       0,     4,     3,     0,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     0,     4,     1,     1,     1,     1,     0,
       5,     3,     2,     3,     2,     2,     1,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     0,     0,     5,     1,
       1,     1,     1,     0,     0,     5,     1,     1,     1,     0,
       0,     5,     0,     0,     5,     1,     0,     0,     5,     1,
       0,     0,     5,     1,     0,     0,     5,     1,     0,     0,
       5,     1,     1,     1,     1,     1,     0,     0,     5,     1,
       1,     1,     0,     0,     5,     1,     0,     0,     5,     0,
       2,     1,     1,     5,     1,     3,     1,     0,     0,     5,
       1,     1,     1,     1,     1,     1,     1,     1,     2,     4,
       1,     0,     4,     2,     0,     4,     2,     0,     4,     1,
       1,     0,     3,     1,     1,     1,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     4,     4,     2,     2,     2,     2,     7,     5,
       1,     1,     2,     2,     3,     1,     2,     3,     2,     2,
       2,     3,     2,     1,     1,     3,     1,     1,     2,     1,
       1,     1,     1,     1,     1,     1,     3,     3
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
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

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



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

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
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


#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
static YYSIZE_T
yystrlen (const char *yystr)
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            /* Fall through.  */
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        YYSTYPE *yyvs1 = yyvs;
        yytype_int16 *yyss1 = yyss;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yystacksize);

        yyss = yyss1;
        yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yytype_int16 *yyss1 = yyss;
        union yyalloc *yyptr =
          (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
                  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

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

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
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

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
| yyreduce -- Do a reduction.  |
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


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 3:
#line 204 "src/fast.y" /* yacc.c:1646  */
    { Fast_Parser_reset(yparser()); fast_op;}
#line 1922 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 205 "src/fast.y" /* yacc.c:1646  */
    { Fast_Parser_reset(yparser()); fast_op;}
#line 1928 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 206 "src/fast.y" /* yacc.c:1646  */
    {(yyval.Fast)=NULL; /*printf("parser exit: Fast_Parser.c:%d\n", yparser()->errLine); */ exit(1);}
#line 1934 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 210 "src/fast.y" /* yacc.c:1646  */
    {Fast_Parser_addStatement(yparser(), (yyvsp[-1].Fast)); fast_op; Fast_Parser_define(yparser()); fast_op;}
#line 1940 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 211 "src/fast.y" /* yacc.c:1646  */
    {Fast_Parser_addStatement(yparser(), (yyvsp[0].Fast)); fast_op;}
#line 1946 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 212 "src/fast.y" /* yacc.c:1646  */
    {Fast_Parser_addStatement(yparser(), (yyvsp[0].Fast)); fast_op;}
#line 1952 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 213 "src/fast.y" /* yacc.c:1646  */
    {Fast_Parser_addStatement(yparser(), (yyvsp[0].Fast)); fast_op;}
#line 1958 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 214 "src/fast.y" /* yacc.c:1646  */
    {(yyval.Fast)=NULL;}
#line 1964 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 215 "src/fast.y" /* yacc.c:1646  */
    {(yyval.Variable) = Fast_Parser_pushScope(yparser()); Fast_Parser_pushLvalue(yparser(),NULL, FALSE); fast_op;}
#line 1970 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 215 "src/fast.y" /* yacc.c:1646  */
    {Fast_Parser_popScope(yparser(),(yyvsp[-1].Variable)); fast_op;}
#line 1976 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 216 "src/fast.y" /* yacc.c:1646  */
    {(yyval.Fast)=NULL;}
#line 1982 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 217 "src/fast.y" /* yacc.c:1646  */
    {(yyval.Fast)=NULL;}
#line 1988 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 218 "src/fast.y" /* yacc.c:1646  */
    {(yyval.Fast)=NULL;}
#line 1994 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 219 "src/fast.y" /* yacc.c:1646  */
    {Fast_Parser_addStatement(yparser(), (yyvsp[0].Fast)); fast_op;}
#line 2000 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 220 "src/fast.y" /* yacc.c:1646  */
    {Fast_Parser_addStatement(yparser(), (yyvsp[0].Fast)); fast_op;}
#line 2006 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 227 "src/fast.y" /* yacc.c:1646  */
    {Fast_Parser_defineScope(yparser()); fast_op;}
#line 2012 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 228 "src/fast.y" /* yacc.c:1646  */
    {Fast_Parser_defineScope(yparser()); fast_op;}
#line 2018 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 229 "src/fast.y" /* yacc.c:1646  */
    {Fast_Parser_defineScope(yparser()); fast_op;}
#line 2024 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 230 "src/fast.y" /* yacc.c:1646  */
    {Fast_Parser_defineScope(yparser()); fast_op;}
#line 2030 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 234 "src/fast.y" /* yacc.c:1646  */
    {if (!yparser()->variableCount) {yparser()->variables[0] = (yyvsp[0].Fast); yparser()->variableCount=1;}}
#line 2036 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 242 "src/fast.y" /* yacc.c:1646  */
    {(yyval.Fast) = Fast_Parser_blockPush(yparser(), FALSE); fast_op;}
#line 2042 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 246 "src/fast.y" /* yacc.c:1646  */
    {Fast_Parser_blockPop(yparser()); fast_op;}
#line 2048 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 246 "src/fast.y" /* yacc.c:1646  */
    {(yyval.Fast)=(yyvsp[-3].Fast);}
#line 2054 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 247 "src/fast.y" /* yacc.c:1646  */
    {(yyval.Fast)=Fast_Parser_blockPush(yparser(), FALSE); fast_op;}
#line 2060 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 247 "src/fast.y" /* yacc.c:1646  */
    {Fast_Parser_blockPop(yparser()); fast_op; (yyval.Fast)=(yyvsp[-1].Fast);}
#line 2066 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 248 "src/fast.y" /* yacc.c:1646  */
    {(yyval.Fast)=NULL;}
#line 2072 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 255 "src/fast.y" /* yacc.c:1646  */
    {(yyval.Fast) = Fast_Parser_declareFunctionParams(yparser(),(yyvsp[0].Fast)); fast_op;}
#line 2078 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 255 "src/fast.y" /* yacc.c:1646  */
    {Fast_Parser_bind(yparser(), (yyvsp[-2].Fast), (yyvsp[-1].Fast)); fast_op;}
#line 2084 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 256 "src/fast.y" /* yacc.c:1646  */
    {
        (yyval.Fast) = Fast_Parser_declareFunctionParams(yparser(),(yyvsp[0].Fast)); fast_op;
        Fast_Parser_blockPush(yparser(), FALSE); fast_op;
        Fast_Parser_pushReturnAsLvalue(yparser(), (yyvsp[0].Fast)); fast_op; /* Set lvalue to return-variable of function */
    }
#line 2094 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 260 "src/fast.y" /* yacc.c:1646  */
    {
        Fast_Parser_popLvalue(yparser()); fast_op;
        Fast_Parser_bindOneliner(yparser(), (yyvsp[-4].Fast), (yyvsp[-3].Fast), (yyvsp[-1].Fast)); fast_op; 
        Fast_Parser_blockPop(yparser()); fast_op;
    }
#line 2104 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 268 "src/fast.y" /* yacc.c:1646  */
    {db_id id; sprintf(id, "%s(%s)", (yyvsp[-1].String), (yyvsp[0].String)); db_dealloc((yyvsp[0].String)); (yyval.Fast) = Fast_Parser_declareFunction(yparser(), (yyvsp[-2].Reference), id, NULL, FALSE); fast_op; }
#line 2110 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 269 "src/fast.y" /* yacc.c:1646  */
    {
        db_id id;
        db_procedure kind = db_resolve(NULL, (yyvsp[0].String));
        sprintf(id, "%s(%s)", (yyvsp[-2].String), (yyvsp[-1].String)); 
        db_dealloc((yyvsp[-1].String)); 
        (yyval.Fast) = Fast_Parser_declareFunction(yparser(), (yyvsp[-3].Reference), id, kind, FALSE); fast_op; 
        db_free(kind);
    }
#line 2123 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 277 "src/fast.y" /* yacc.c:1646  */
    {db_id id; sprintf(id, "%s(%s)", (yyvsp[-1].String), (yyvsp[0].String)); db_dealloc((yyvsp[0].String)); (yyval.Fast) = Fast_Parser_declareFunction(yparser(), (yyvsp[-2].Reference), id, NULL, FALSE); fast_op; }
#line 2129 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 280 "src/fast.y" /* yacc.c:1646  */
    {db_id id; sprintf(id, "%s(%s)", (yyvsp[-1].String), (yyvsp[0].String)); db_dealloc((yyvsp[0].String)); (yyval.Fast) = Fast_Parser_declareFunction(yparser(), (yyvsp[-3].Reference), id, NULL, TRUE); fast_op; }
#line 2135 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 281 "src/fast.y" /* yacc.c:1646  */
    {
        db_id id;
        db_procedure kind = db_resolve(NULL, (yyvsp[0].String));
        sprintf(id, "%s(%s)", (yyvsp[-2].String), (yyvsp[-1].String)); 
        db_dealloc((yyvsp[-2].String)); 
        (yyval.Fast) = Fast_Parser_declareFunction(yparser(), (yyvsp[-4].Reference), id, kind, TRUE); fast_op; 
        db_free(kind);
    }
#line 2148 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 289 "src/fast.y" /* yacc.c:1646  */
    {db_id id; sprintf(id, "%s(%s)", (yyvsp[-1].String), (yyvsp[0].String)); db_dealloc((yyvsp[0].String)); (yyval.Fast) = Fast_Parser_declareFunction(yparser(), (yyvsp[-3].Reference), id, NULL, TRUE); fast_op; }
#line 2154 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 293 "src/fast.y" /* yacc.c:1646  */
    {(yyval.String) = db_strdup("");}
#line 2160 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 294 "src/fast.y" /* yacc.c:1646  */
    {(yyval.String) = (yyvsp[-1].String);}
#line 2166 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 298 "src/fast.y" /* yacc.c:1646  */
    {(yyval.String)=db_malloc(sizeof(db_id));strcpy((yyval.String),(yyvsp[0].String)); db_dealloc((yyvsp[0].String));}
#line 2172 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 299 "src/fast.y" /* yacc.c:1646  */
    {(yyval.String)=(yyvsp[-2].String); strcat((yyval.String),","); strcat((yyval.String),(yyvsp[0].String)); db_dealloc((yyvsp[0].String));}
#line 2178 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 303 "src/fast.y" /* yacc.c:1646  */
    {(yyval.String)=Fast_Parser_argumentToString(yparser(), (yyvsp[-1].Reference), (yyvsp[0].String), FALSE); fast_op;}
#line 2184 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 304 "src/fast.y" /* yacc.c:1646  */
    {(yyval.String)=Fast_Parser_argumentToString(yparser(), (yyvsp[-2].Reference), (yyvsp[0].String), TRUE); fast_op;}
#line 2190 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 311 "src/fast.y" /* yacc.c:1646  */
    {(yyval.Fast)=Fast_declarationSeqDo((yyvsp[-1].Reference), &(yyvsp[0].Declarations), FALSE); fast_op; (yyval.Fast)=NULL;}
#line 2196 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 312 "src/fast.y" /* yacc.c:1646  */
    {yparser()->isLocal = TRUE;}
#line 2202 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 312 "src/fast.y" /* yacc.c:1646  */
    {(yyval.Fast)=(yyvsp[0].Fast);}
#line 2208 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 316 "src/fast.y" /* yacc.c:1646  */
    {(yyval.Fast)=Fast_declarationSeqDo((yyvsp[-1].Reference), &(yyvsp[0].Declarations), FALSE); fast_op;}
#line 2214 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 317 "src/fast.y" /* yacc.c:1646  */
    {(yyval.Fast)=Fast_declarationSeqDo((yyvsp[-2].Reference), &(yyvsp[0].Declarations), TRUE); fast_op;}
#line 2220 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 321 "src/fast.y" /* yacc.c:1646  */
    {(yyval.Declarations).length = 0; (yyval.Declarations).buffer = NULL; Fast_declarationSeqInsert(&(yyval.Declarations), &(yyvsp[0].Declaration));}
#line 2226 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 322 "src/fast.y" /* yacc.c:1646  */
    {Fast_declarationSeqInsert(&(yyvsp[-2].Declarations), &(yyvsp[0].Declaration)); (yyval.Declarations) = (yyvsp[-2].Declarations);}
#line 2232 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 326 "src/fast.y" /* yacc.c:1646  */
    {(yyval.Declaration).name = (yyvsp[0].String);}
#line 2238 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 333 "src/fast.y" /* yacc.c:1646  */
    {(yyval.Fast)=NULL;}
#line 2244 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 344 "src/fast.y" /* yacc.c:1646  */
    {if ((yyvsp[0].Fast)) Fast_Parser_initValue(yparser(), (yyvsp[0].Fast)); fast_op}
#line 2250 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 349 "src/fast.y" /* yacc.c:1646  */
    {Fast_Parser_initPush(yparser()); fast_op;}
#line 2256 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 349 "src/fast.y" /* yacc.c:1646  */
    {Fast_Parser_initPop(yparser()); fast_op;}
#line 2262 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 349 "src/fast.y" /* yacc.c:1646  */
    {(yyval.Fast)=(yyvsp[-2].Fast);}
#line 2268 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 350 "src/fast.y" /* yacc.c:1646  */
    {Fast_Parser_initPush(yparser()); fast_op; Fast_Parser_initPop(yparser()); fast_op; (yyval.Fast)=NULL;}
#line 2274 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 363 "src/fast.y" /* yacc.c:1646  */
    {Fast_Parser_initMember(yparser(), (yyvsp[-1].String)); fast_op;}
#line 2280 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 368 "src/fast.y" /* yacc.c:1646  */
    {Fast_Parser_initKeyValuePush(yparser());}
#line 2286 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 368 "src/fast.y" /* yacc.c:1646  */
    {Fast_Parser_initKeyValuePop(yparser());}
#line 2292 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 369 "src/fast.y" /* yacc.c:1646  */
    {Fast_Parser_initKeyValueSet(yparser(), (yyvsp[0].Fast));}
#line 2298 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 76:
#line 376 "src/fast.y" /* yacc.c:1646  */
    {(yyval.Fast)=Fast_Boolean__create((yyvsp[0].Boolean)); Fast_Parser_collect(yparser(), (yyval.Fast));}
#line 2304 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 77:
#line 377 "src/fast.y" /* yacc.c:1646  */
    {(yyval.Fast)=Fast_Character__create((yyvsp[0].Character)); Fast_Parser_collect(yparser(), (yyval.Fast));}
#line 2310 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 78:
#line 378 "src/fast.y" /* yacc.c:1646  */
    {(yyval.Fast)=Fast_Integer__create((yyvsp[0].Integer)); Fast_Parser_collect(yparser(), (yyval.Fast));}
#line 2316 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 79:
#line 379 "src/fast.y" /* yacc.c:1646  */
    {(yyval.Fast)=Fast_SignedInteger__create((yyvsp[0].SignedInteger)); Fast_Parser_collect(yparser(), (yyval.Fast));}
#line 2322 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 80:
#line 380 "src/fast.y" /* yacc.c:1646  */
    {(yyval.Fast)=Fast_FloatingPoint__create((yyvsp[0].FloatingPoint)); Fast_Parser_collect(yparser(), (yyval.Fast));}
#line 2328 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 81:
#line 381 "src/fast.y" /* yacc.c:1646  */
    {(yyval.Fast)=Fast_String__create((yyvsp[0].String)); Fast_Parser_collect(yparser(), (yyval.Fast));}
#line 2334 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 82:
#line 382 "src/fast.y" /* yacc.c:1646  */
    {(yyval.Fast)=Fast_Null__create(); Fast_Parser_collect(yparser(), (yyval.Fast));}
#line 2340 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 83:
#line 386 "src/fast.y" /* yacc.c:1646  */
    {PUSHLVALUE(NULL)}
#line 2346 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 84:
#line 386 "src/fast.y" /* yacc.c:1646  */
    {POPLVALUE(); (yyval.Fast)=(yyvsp[-1].Fast);}
#line 2352 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 86:
#line 391 "src/fast.y" /* yacc.c:1646  */
    {(yyval.Fast)=(yyvsp[0].Fast);}
#line 2358 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 87:
#line 392 "src/fast.y" /* yacc.c:1646  */
    {(yyval.Fast)=(yyvsp[0].Reference);}
#line 2364 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 89:
#line 397 "src/fast.y" /* yacc.c:1646  */
    {PUSHCOMPLEX((yyvsp[0].Fast))}
#line 2370 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 90:
#line 397 "src/fast.y" /* yacc.c:1646  */
    {(yyval.Fast) = Fast_Parser_elementExpr(yparser(), (yyvsp[-4].Fast), (yyvsp[-1].Fast)); fast_op; POPCOMPLEX()}
#line 2376 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 91:
#line 398 "src/fast.y" /* yacc.c:1646  */
    {(yyval.Fast) = Fast_Parser_callExpr(yparser(), (yyvsp[-2].Fast), NULL); fast_op;}
#line 2382 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 92:
#line 399 "src/fast.y" /* yacc.c:1646  */
    {(yyval.Fast) = Fast_Parser_callExpr(yparser(), (yyvsp[-1].Fast), (yyvsp[0].Fast)); fast_op;}
#line 2388 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 93:
#line 400 "src/fast.y" /* yacc.c:1646  */
    {Fast_String str = Fast_String__create((yyvsp[0].String)); if (!str) {YYERROR;} (yyval.Fast) = Fast_Parser_memberExpr(yparser(), (yyvsp[-2].Fast), Fast_Expression(str)); db_free(str); fast_op;}
#line 2394 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 94:
#line 401 "src/fast.y" /* yacc.c:1646  */
    {(yyval.Fast) = Fast_Parser_postfixExpr(yparser(), (yyvsp[-1].Fast), DB_INC); fast_op}
#line 2400 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 95:
#line 402 "src/fast.y" /* yacc.c:1646  */
    {(yyval.Fast) = Fast_Parser_postfixExpr(yparser(), (yyvsp[-1].Fast), DB_DEC); fast_op}
#line 2406 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 97:
#line 407 "src/fast.y" /* yacc.c:1646  */
    {(yyval.Fast) = Fast_Parser_unaryExpr(yparser(), (yyvsp[0].Fast), (yyvsp[-1].Operator)); fast_op;}
#line 2412 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 98:
#line 411 "src/fast.y" /* yacc.c:1646  */
    {(yyval.Operator) = DB_SUB;}
#line 2418 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 99:
#line 412 "src/fast.y" /* yacc.c:1646  */
    {(yyval.Operator) = DB_NOT;}
#line 2424 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 100:
#line 413 "src/fast.y" /* yacc.c:1646  */
    {(yyval.Operator) = DB_COND_NOT;}
#line 2430 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 101:
#line 414 "src/fast.y" /* yacc.c:1646  */
    {(yyval.Operator) = DB_COND_NOT;}
#line 2436 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 102:
#line 415 "src/fast.y" /* yacc.c:1646  */
    {(yyval.Operator) = DB_INC;}
#line 2442 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 103:
#line 416 "src/fast.y" /* yacc.c:1646  */
    {(yyval.Operator) = DB_DEC;}
#line 2448 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 104:
#line 417 "src/fast.y" /* yacc.c:1646  */
    {(yyval.Operator) = DB_AND;}
#line 2454 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 106:
#line 422 "src/fast.y" /* yacc.c:1646  */
    {PUSHLVALUE((yyvsp[0].Fast))}
#line 2460 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 107:
#line 422 "src/fast.y" /* yacc.c:1646  */
    {POPLVALUE()}
#line 2466 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 108:
#line 422 "src/fast.y" /* yacc.c:1646  */
    {(yyval.Fast) = Fast_Parser_binaryExpr(yparser(), (yyvsp[-4].Fast), (yyvsp[-1].Fast), (yyvsp[-2].Operator)); fast_op;}
#line 2472 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 109:
#line 426 "src/fast.y" /* yacc.c:1646  */
    {(yyval.Operator) = DB_MUL;}
#line 2478 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 110:
#line 427 "src/fast.y" /* yacc.c:1646  */
    {(yyval.Operator) = DB_DIV;}
#line 2484 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 111:
#line 428 "src/fast.y" /* yacc.c:1646  */
    {(yyval.Operator) = DB_MOD;}
#line 2490 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 113:
#line 433 "src/fast.y" /* yacc.c:1646  */
    {PUSHLVALUE((yyvsp[0].Fast))}
#line 2496 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 114:
#line 433 "src/fast.y" /* yacc.c:1646  */
    {POPLVALUE()}
#line 2502 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 115:
#line 433 "src/fast.y" /* yacc.c:1646  */
    {(yyval.Fast) = Fast_Parser_binaryExpr(yparser(), (yyvsp[-4].Fast), (yyvsp[-1].Fast), (yyvsp[-2].Operator)); fast_op;}
#line 2508 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 116:
#line 437 "src/fast.y" /* yacc.c:1646  */
    {(yyval.Operator) = DB_ADD;}
#line 2514 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 117:
#line 438 "src/fast.y" /* yacc.c:1646  */
    {(yyval.Operator) = DB_SUB;}
#line 2520 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 119:
#line 443 "src/fast.y" /* yacc.c:1646  */
    {PUSHLVALUE((yyvsp[0].Fast))}
#line 2526 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 120:
#line 443 "src/fast.y" /* yacc.c:1646  */
    {POPLVALUE()}
#line 2532 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 121:
#line 443 "src/fast.y" /* yacc.c:1646  */
    {(yyval.Fast) = Fast_Parser_binaryExpr(yparser(), (yyvsp[-4].Fast), (yyvsp[-1].Fast), DB_SHIFT_LEFT); fast_op;}
#line 2538 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 122:
#line 444 "src/fast.y" /* yacc.c:1646  */
    {PUSHLVALUE((yyvsp[0].Fast))}
#line 2544 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 123:
#line 444 "src/fast.y" /* yacc.c:1646  */
    {POPLVALUE()}
#line 2550 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 124:
#line 444 "src/fast.y" /* yacc.c:1646  */
    {(yyval.Fast) = Fast_Parser_binaryExpr(yparser(), (yyvsp[-4].Fast), (yyvsp[-1].Fast), DB_SHIFT_RIGHT); fast_op;}
#line 2556 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 126:
#line 449 "src/fast.y" /* yacc.c:1646  */
    {PUSHLVALUE((yyvsp[0].Fast))}
#line 2562 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 127:
#line 449 "src/fast.y" /* yacc.c:1646  */
    {POPLVALUE()}
#line 2568 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 128:
#line 449 "src/fast.y" /* yacc.c:1646  */
    {(yyval.Fast) = Fast_Parser_binaryExpr(yparser(), (yyvsp[-4].Fast), (yyvsp[-1].Fast), DB_AND); fast_op;}
#line 2574 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 130:
#line 454 "src/fast.y" /* yacc.c:1646  */
    {PUSHLVALUE((yyvsp[0].Fast))}
#line 2580 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 131:
#line 454 "src/fast.y" /* yacc.c:1646  */
    {POPLVALUE()}
#line 2586 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 132:
#line 454 "src/fast.y" /* yacc.c:1646  */
    {(yyval.Fast) = Fast_Parser_binaryExpr(yparser(), (yyvsp[-4].Fast), (yyvsp[-1].Fast), DB_XOR); fast_op;}
#line 2592 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 134:
#line 459 "src/fast.y" /* yacc.c:1646  */
    {PUSHLVALUE((yyvsp[0].Fast))}
#line 2598 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 135:
#line 459 "src/fast.y" /* yacc.c:1646  */
    {POPLVALUE()}
#line 2604 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 136:
#line 459 "src/fast.y" /* yacc.c:1646  */
    {(yyval.Fast) = Fast_Parser_binaryExpr(yparser(), (yyvsp[-4].Fast), (yyvsp[-1].Fast), DB_OR); fast_op;}
#line 2610 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 138:
#line 464 "src/fast.y" /* yacc.c:1646  */
    {PUSHLVALUE((yyvsp[0].Fast))}
#line 2616 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 139:
#line 464 "src/fast.y" /* yacc.c:1646  */
    {POPLVALUE()}
#line 2622 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 140:
#line 464 "src/fast.y" /* yacc.c:1646  */
    {(yyval.Fast) = Fast_Parser_binaryExpr(yparser(), (yyvsp[-4].Fast), (yyvsp[-1].Fast), (yyvsp[-2].Operator)); fast_op;}
#line 2628 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 141:
#line 468 "src/fast.y" /* yacc.c:1646  */
    {(yyval.Operator) = DB_COND_LT;}
#line 2634 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 142:
#line 469 "src/fast.y" /* yacc.c:1646  */
    {(yyval.Operator) = DB_COND_GT;}
#line 2640 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 143:
#line 470 "src/fast.y" /* yacc.c:1646  */
    {(yyval.Operator) = DB_COND_LTEQ;}
#line 2646 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 144:
#line 471 "src/fast.y" /* yacc.c:1646  */
    {(yyval.Operator) = DB_COND_GTEQ;}
#line 2652 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 146:
#line 476 "src/fast.y" /* yacc.c:1646  */
    {PUSHLVALUE((yyvsp[0].Fast))}
#line 2658 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 147:
#line 476 "src/fast.y" /* yacc.c:1646  */
    {POPLVALUE()}
#line 2664 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 148:
#line 476 "src/fast.y" /* yacc.c:1646  */
    {(yyval.Fast) = Fast_Parser_binaryExpr(yparser(), (yyvsp[-4].Fast), (yyvsp[-1].Fast), (yyvsp[-2].Operator)); fast_op;}
#line 2670 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 149:
#line 480 "src/fast.y" /* yacc.c:1646  */
    {(yyval.Operator) = DB_COND_EQ;}
#line 2676 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 150:
#line 481 "src/fast.y" /* yacc.c:1646  */
    {(yyval.Operator) = DB_COND_NEQ;}
#line 2682 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 152:
#line 486 "src/fast.y" /* yacc.c:1646  */
    {PUSHLVALUE((yyvsp[0].Fast))}
#line 2688 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 153:
#line 486 "src/fast.y" /* yacc.c:1646  */
    {POPLVALUE()}
#line 2694 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 154:
#line 486 "src/fast.y" /* yacc.c:1646  */
    {(yyval.Fast) = Fast_Parser_binaryExpr(yparser(), (yyvsp[-4].Fast), (yyvsp[-1].Fast), DB_COND_AND); fast_op;}
#line 2700 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 156:
#line 491 "src/fast.y" /* yacc.c:1646  */
    {PUSHLVALUE((yyvsp[0].Fast))}
#line 2706 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 157:
#line 491 "src/fast.y" /* yacc.c:1646  */
    {POPLVALUE()}
#line 2712 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 158:
#line 491 "src/fast.y" /* yacc.c:1646  */
    {(yyval.Fast) = Fast_Parser_binaryExpr(yparser(), (yyvsp[-4].Fast), (yyvsp[-1].Fast), DB_COND_OR); fast_op;}
#line 2718 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 159:
#line 495 "src/fast.y" /* yacc.c:1646  */
    {(yyval.Fast) = Fast_Parser_initPushExpression(yparser()); fast_op;}
#line 2724 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 160:
#line 495 "src/fast.y" /* yacc.c:1646  */
    {(yyval.Fast)=(yyvsp[-1].Fast);}
#line 2730 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 163:
#line 501 "src/fast.y" /* yacc.c:1646  */
    {(yyval.Fast)=Fast_Parser_ternaryExpr(yparser(), (yyvsp[-4].Fast), (yyvsp[-2].Fast), (yyvsp[0].Fast)); fast_op;}
#line 2736 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 165:
#line 506 "src/fast.y" /* yacc.c:1646  */
    {
        if ((yyvsp[-2].Fast)) {
            if (Fast_Node((yyvsp[-2].Fast))->kind != FAST_CommaExpr) {
                (yyval.Fast) = Fast_CommaExpr__create(); fast_op;
                Fast_CommaExpr_addExpression((yyval.Fast), (yyvsp[-2].Fast)); fast_op;
                Fast_Parser_collect(yparser(), (yyval.Fast)); fast_op;
            }
            Fast_CommaExpr_addExpression((yyval.Fast), (yyvsp[0].Fast)); fast_op;
        }
    }
#line 2751 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 167:
#line 520 "src/fast.y" /* yacc.c:1646  */
    {PUSHASSIGN((yyvsp[0].Fast))}
#line 2757 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 168:
#line 520 "src/fast.y" /* yacc.c:1646  */
    {POPLVALUE()}
#line 2763 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 169:
#line 520 "src/fast.y" /* yacc.c:1646  */
    {
        (yyval.Fast) = Fast_Parser_binaryExpr(yparser(), (yyvsp[-4].Fast), (yyvsp[-1].Fast), (yyvsp[-2].Operator)); fast_op; 
    }
#line 2771 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 170:
#line 526 "src/fast.y" /* yacc.c:1646  */
    {(yyval.Operator) = DB_ASSIGN;}
#line 2777 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 171:
#line 527 "src/fast.y" /* yacc.c:1646  */
    {(yyval.Operator) = DB_ASSIGN_ADD;}
#line 2783 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 172:
#line 528 "src/fast.y" /* yacc.c:1646  */
    {(yyval.Operator) = DB_ASSIGN_SUB;}
#line 2789 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 173:
#line 529 "src/fast.y" /* yacc.c:1646  */
    {(yyval.Operator) = DB_ASSIGN_MUL;}
#line 2795 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 174:
#line 530 "src/fast.y" /* yacc.c:1646  */
    {(yyval.Operator) = DB_ASSIGN_DIV;}
#line 2801 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 175:
#line 531 "src/fast.y" /* yacc.c:1646  */
    {(yyval.Operator) = DB_ASSIGN_AND;}
#line 2807 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 176:
#line 532 "src/fast.y" /* yacc.c:1646  */
    {(yyval.Operator) = DB_ASSIGN_OR;}
#line 2813 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 178:
#line 537 "src/fast.y" /* yacc.c:1646  */
    {(yyval.Fast) = Fast_Parser_waitExpr(yparser(), (yyvsp[0].Fast), NULL); fast_op;}
#line 2819 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 179:
#line 538 "src/fast.y" /* yacc.c:1646  */
    {(yyval.Fast) = Fast_Parser_waitExpr(yparser(), (yyvsp[-2].Fast), (yyvsp[0].Fast)); fast_op;}
#line 2825 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 181:
#line 543 "src/fast.y" /* yacc.c:1646  */
    {
        Fast_Parser_initDeclareStaged(yparser(), NULL); fast_op;
        Fast_Parser_initPushStatic(yparser()); fast_op;
    }
#line 2834 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 182:
#line 546 "src/fast.y" /* yacc.c:1646  */
    {
        Fast_Parser_initPop(yparser()); fast_op;
    }
#line 2842 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 183:
#line 549 "src/fast.y" /* yacc.c:1646  */
    {
        Fast_Parser_initDeclareStaged(yparser(), NULL); fast_op;
        Fast_Parser_initPushStatic(yparser()); fast_op;
        Fast_Parser_initPop(yparser()); fast_op;
    }
#line 2852 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 184:
#line 554 "src/fast.y" /* yacc.c:1646  */
    {Fast_Parser_initPushStatic(yparser()); fast_op;}
#line 2858 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 185:
#line 554 "src/fast.y" /* yacc.c:1646  */
    {Fast_Parser_initPop(yparser()); fast_op;}
#line 2864 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 186:
#line 555 "src/fast.y" /* yacc.c:1646  */
    {Fast_Parser_initPushStatic(yparser()); fast_op; Fast_Parser_initPop(yparser()); fast_op;}
#line 2870 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 187:
#line 556 "src/fast.y" /* yacc.c:1646  */
    {
        if (!yparser()->isLocal) {
            _fast_err("invalid usage of assignment operator, initialize objects with ':'");
            YYERROR;
        }
        Fast_Parser_pushLvalue(yparser(), (yyvsp[-1].Fast), TRUE);
    }
#line 2882 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 188:
#line 562 "src/fast.y" /* yacc.c:1646  */
    {
        (yyval.Fast) = Fast_Parser_binaryExpr(yparser(), (yyvsp[-3].Fast), (yyvsp[0].Fast), DB_ASSIGN); fast_op;
        Fast_Parser_popLvalue(yparser());
    }
#line 2891 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 191:
#line 577 "src/fast.y" /* yacc.c:1646  */
    {
        (yyval.Variable) = Fast_Variable(Fast_Parser_initPushIdentifier(yparser(), (Fast_Expression)(yyvsp[0].Reference))); fast_op
    }
#line 2899 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 192:
#line 579 "src/fast.y" /* yacc.c:1646  */
    {
        Fast_Parser_define(yparser()); fast_op;
        (yyval.Reference) = (yyvsp[-1].Variable);
    }
#line 2908 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 193:
#line 586 "src/fast.y" /* yacc.c:1646  */
    {(yyval.Reference) = Fast_Parser_lookup(yparser(), (yyvsp[0].String), NULL); fast_op;}
#line 2914 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 194:
#line 587 "src/fast.y" /* yacc.c:1646  */
    {(yyval.Reference) = Fast_Parser_lookup(yparser(), (yyvsp[0].String), NULL); fast_op;}
#line 2920 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 196:
#line 592 "src/fast.y" /* yacc.c:1646  */
    {(yyval.String) = "scope";}
#line 2926 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 197:
#line 593 "src/fast.y" /* yacc.c:1646  */
    {(yyval.String) = "update";}
#line 2932 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 198:
#line 594 "src/fast.y" /* yacc.c:1646  */
    {(yyval.String) = "declare";}
#line 2938 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 199:
#line 595 "src/fast.y" /* yacc.c:1646  */
    {(yyval.String) = "define";}
#line 2944 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 200:
#line 596 "src/fast.y" /* yacc.c:1646  */
    {(yyval.String) = "destruct";}
#line 2950 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 201:
#line 597 "src/fast.y" /* yacc.c:1646  */
    {(yyval.String) = "wait";}
#line 2956 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 202:
#line 598 "src/fast.y" /* yacc.c:1646  */
    {(yyval.String) = "on";}
#line 2962 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 203:
#line 599 "src/fast.y" /* yacc.c:1646  */
    {(yyval.String) = "self";}
#line 2968 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 204:
#line 600 "src/fast.y" /* yacc.c:1646  */
    {(yyval.String) = "synchronized";}
#line 2974 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 205:
#line 601 "src/fast.y" /* yacc.c:1646  */
    {(yyval.String) = "if";}
#line 2980 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 206:
#line 602 "src/fast.y" /* yacc.c:1646  */
    {(yyval.String) = "else";}
#line 2986 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 207:
#line 603 "src/fast.y" /* yacc.c:1646  */
    {(yyval.String) = "while";}
#line 2992 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 208:
#line 604 "src/fast.y" /* yacc.c:1646  */
    {(yyval.String) = "switch";}
#line 2998 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 209:
#line 605 "src/fast.y" /* yacc.c:1646  */
    {(yyval.String) = "case";}
#line 3004 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 210:
#line 606 "src/fast.y" /* yacc.c:1646  */
    {(yyval.String) = "default";}
#line 3010 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 211:
#line 607 "src/fast.y" /* yacc.c:1646  */
    {(yyval.String) = "break";}
#line 3016 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 212:
#line 608 "src/fast.y" /* yacc.c:1646  */
    {(yyval.String) = "for";}
#line 3022 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 213:
#line 609 "src/fast.y" /* yacc.c:1646  */
    {(yyval.String) = "try";}
#line 3028 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 214:
#line 610 "src/fast.y" /* yacc.c:1646  */
    {(yyval.String) = "catch";}
#line 3034 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 215:
#line 611 "src/fast.y" /* yacc.c:1646  */
    {(yyval.String) = "import";}
#line 3040 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 216:
#line 612 "src/fast.y" /* yacc.c:1646  */
    {(yyval.String) = "local";}
#line 3046 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 217:
#line 613 "src/fast.y" /* yacc.c:1646  */
    {(yyval.String) = "virtual";}
#line 3052 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 218:
#line 614 "src/fast.y" /* yacc.c:1646  */
    {(yyval.String) = "and";}
#line 3058 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 219:
#line 615 "src/fast.y" /* yacc.c:1646  */
    {(yyval.String) = "or";}
#line 3064 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 220:
#line 616 "src/fast.y" /* yacc.c:1646  */
    {(yyval.String) = "not";}
#line 3070 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 221:
#line 623 "src/fast.y" /* yacc.c:1646  */
    {(yyval.Fast)=Fast_Parser_ifStatement(yparser(), (yyvsp[-1].Fast), (yyvsp[0].Fast), NULL); fast_op;}
#line 3076 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 222:
#line 624 "src/fast.y" /* yacc.c:1646  */
    {Fast_If nestedIf = Fast_If(Fast_Parser_ifStatement(yparser(), NULL, (yyvsp[0].Fast), NULL)); fast_op; (yyval.Fast)=Fast_Parser_ifStatement(yparser(), (yyvsp[-3].Fast), (yyvsp[-2].Fast), nestedIf); fast_op;}
#line 3082 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 223:
#line 625 "src/fast.y" /* yacc.c:1646  */
    {(yyval.Fast)=Fast_Parser_ifStatement(yparser(), (yyvsp[-3].Fast), (yyvsp[-2].Fast), (yyvsp[0].Fast)); fast_op;}
#line 3088 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 224:
#line 629 "src/fast.y" /* yacc.c:1646  */
    {(yyval.Fast)=(yyvsp[0].Fast);}
#line 3094 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 225:
#line 636 "src/fast.y" /* yacc.c:1646  */
    {(yyval.Fast) = Fast_Parser_whileStatement(yparser(), (yyvsp[-1].Fast), (yyvsp[0].Fast), FALSE); fast_op;}
#line 3100 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 226:
#line 637 "src/fast.y" /* yacc.c:1646  */
    {(yyval.Fast) = Fast_Parser_whileStatement(yparser(), (yyvsp[-1].Fast), yparser()->block, TRUE); fast_op;}
#line 3106 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 227:
#line 641 "src/fast.y" /* yacc.c:1646  */
    {(yyval.Fast)=(yyvsp[0].Fast);}
#line 3112 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 228:
#line 648 "src/fast.y" /* yacc.c:1646  */
    {(yyval.Fast)=NULL;}
#line 3118 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 229:
#line 649 "src/fast.y" /* yacc.c:1646  */
    {(yyval.Fast)=NULL;}
#line 3124 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 234:
#line 660 "src/fast.y" /* yacc.c:1646  */
    {(yyval.Fast)=NULL;}
#line 3130 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 239:
#line 677 "src/fast.y" /* yacc.c:1646  */
    {Fast_Parser_observerPop(yparser()); fast_op;}
#line 3136 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 240:
#line 678 "src/fast.y" /* yacc.c:1646  */
    {Fast_Parser_observerPop(yparser()); fast_op;}
#line 3142 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 241:
#line 682 "src/fast.y" /* yacc.c:1646  */
    {(yyval.Fast)=NULL; Fast_Parser_observerDeclaration(yparser(), NULL, (yyvsp[0].Fast), (yyvsp[-1].Mask), (yyvsp[-2].Reference)); fast_op;}
#line 3148 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 242:
#line 683 "src/fast.y" /* yacc.c:1646  */
    {(yyval.Fast)=NULL; Fast_Parser_observerDeclaration(yparser(), NULL, (yyvsp[0].Fast), DB_ON_UPDATE, (yyvsp[-1].Reference)); fast_op;}
#line 3154 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 243:
#line 687 "src/fast.y" /* yacc.c:1646  */
    {(yyval.Reference)=NULL; Fast_Parser_observerPush(yparser());}
#line 3160 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 245:
#line 692 "src/fast.y" /* yacc.c:1646  */
    {(yyval.Mask) = (yyvsp[-2].Mask) | (yyvsp[0].Mask);}
#line 3166 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 248:
#line 698 "src/fast.y" /* yacc.c:1646  */
    {(yyval.Mask) = (yyvsp[-1].Mask) | (yyvsp[0].Mask);}
#line 3172 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 249:
#line 702 "src/fast.y" /* yacc.c:1646  */
    {(yyval.Mask) = DB_ON_UPDATE;}
#line 3178 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 250:
#line 703 "src/fast.y" /* yacc.c:1646  */
    {(yyval.Mask) = DB_ON_DECLARE;}
#line 3184 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 251:
#line 704 "src/fast.y" /* yacc.c:1646  */
    {(yyval.Mask) = DB_ON_DEFINE;}
#line 3190 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 252:
#line 705 "src/fast.y" /* yacc.c:1646  */
    {(yyval.Mask) = DB_ON_DESTRUCT;}
#line 3196 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 253:
#line 709 "src/fast.y" /* yacc.c:1646  */
    {(yyval.Mask) = DB_ON_SELF;}
#line 3202 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 254:
#line 710 "src/fast.y" /* yacc.c:1646  */
    {(yyval.Mask) = DB_ON_SCOPE;}
#line 3208 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 255:
#line 711 "src/fast.y" /* yacc.c:1646  */
    {(yyval.Mask) = DB_ON_VALUE;}
#line 3214 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 256:
#line 718 "src/fast.y" /* yacc.c:1646  */
    {(yyval.Fast) = Fast_Parser_updateStatement(yparser(), (yyvsp[-1].Fast), NULL); fast_op;}
#line 3220 "src/y.tab.c" /* yacc.c:1646  */
    break;

  case 257:
#line 719 "src/fast.y" /* yacc.c:1646  */
    {(yyval.Fast) = Fast_Parser_updateStatement(yparser(), (yyvsp[-1].Fast), (yyvsp[0].Fast)); fast_op;}
#line 3226 "src/y.tab.c" /* yacc.c:1646  */
    break;


#line 3230 "src/y.tab.c" /* yacc.c:1646  */
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
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



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
                      yytoken, &yylval);
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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

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

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYTERROR;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

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

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  return yyresult;
}
#line 723 "src/fast.y" /* yacc.c:1906  */


/* ======================================================================== */
/* Parser */
/* ======================================================================== */	

void yyerror(const char *str)
{
	Fast_Parser p = yparser();
	printf("%s:%d:%d: %s (near token '%s').\n", p->filename, p->line, p->column, str, p->token);
	p->errors++;
}

/* Parse sourcecode */
int fast_yparse(Fast_Parser parser, db_uint32 line, db_uint32 column) {
	db_char *preprocessed;

	/* Preprocess code */
	preprocessed = fast_pp(parser->filename, parser->source);
	if (parser->preprocessed) {
		db_dealloc(parser->preprocessed);
	}
	parser->preprocessed = preprocessed;
	
	/* List code */
	/* fast_ppList(preprocessed);*/
	
	/* Set pointer to source */
	yy_scan_string((char *) preprocessed);
	
	/* Start parsing */
	parser->line = line;
	parser->column = column;

	if (!parser->block) {
		parser->block = Fast_Block__create(NULL);
	}
	
	if (!parser->scope) {
		parser->scope = Fast_Variable(Fast_Object__create(root_o));
	}
	
	yyparse();
	
	/* Destroy lexer resources */
	/*yylex_destroy();*/
	
	/* Set token to NULL - it points to lexer-memory */
	yparser()->token = NULL;

	return yparser()->errors;
}



