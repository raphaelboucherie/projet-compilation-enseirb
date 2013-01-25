/* A Bison parser, made by GNU Bison 2.5.  */

/* Bison implementation for Yacc-like parsers in C
   
      Copyright (C) 1984, 1989-1990, 2000-2011 Free Software Foundation, Inc.
   
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
#define YYBISON_VERSION "2.5"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 268 of yacc.c  */
#line 1 "parse.y"

#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include "userdef.h"
#include "node.h"
#include "y.tab.h"


  int yylex(void);
  void yyerror(char *);
  extern VarIndex strMem[10000];
  int tab_plus[4][4];
  int tab_mult[4][4];
  int tab_comp[4][4];
  int iMaxIndex=0;
  int iCurIndex=0;
  char sBuff[10][20]={0};
  int iBuffX=0;
  int iBuffY=0;
  extern int lineno;
  extern int column;
  float NodeExecute(Node *p);

  /* typedef union { */

/*     float val;  /\* 变量值 *\/ */
/*     int index;  /\* 用于存放 变量数组索引 或 一元操作符值 或 多元操作符索引 *\/ */
/*     Node *node; /\* 结点地址 *\/ */

/*   }yystype; */
/* #define YYSTYPE yystype */

/*   void debug_vsp(YYSTYPE , char * ,YYSTYPE *, char * ); */

  void add_var(char *);
  int G_iVarMaxIndex = 0;  /* 变量最大个数 */
  int G_iVarCurIndex = -1; /* 变量当前索引 */

  struct VarIndex G_Var[MAX_VARS];  /* 变量内存数组 */




/* Line 268 of yacc.c  */
#line 117 "y.tab.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     STRING = 258,
     FLOAT = 259,
     INT = 260,
     ID = 261,
     CLASS = 262,
     IF = 263,
     THEN = 264,
     ELSE = 265,
     END = 266,
     WHILE = 267,
     DO = 268,
     UNLESS = 269,
     DEF = 270,
     LEQ = 271,
     GEQ = 272,
     FOR = 273,
     TO = 274,
     RETURN = 275,
     IN = 276,
     PRINT = 277,
     NEQ = 278,
     EQ = 279,
     OR = 280,
     AND = 281,
     MUS_TT = 282,
     MUS_T = 283,
     ADD_TT = 284,
     ADD_T = 285
   };
#endif
/* Tokens.  */
#define STRING 258
#define FLOAT 259
#define INT 260
#define ID 261
#define CLASS 262
#define IF 263
#define THEN 264
#define ELSE 265
#define END 266
#define WHILE 267
#define DO 268
#define UNLESS 269
#define DEF 270
#define LEQ 271
#define GEQ 272
#define FOR 273
#define TO 274
#define RETURN 275
#define IN 276
#define PRINT 277
#define NEQ 278
#define EQ 279
#define OR 280
#define AND 281
#define MUS_TT 282
#define MUS_T 283
#define ADD_TT 284
#define ADD_T 285




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 293 of yacc.c  */
#line 46 "parse.y"

  int index;
  int ival;
  float fval;
  char *sval;
  Node *node;



/* Line 293 of yacc.c  */
#line 223 "y.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 343 of yacc.c  */
#line 235 "y.tab.c"

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
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
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
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
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
#   if ! defined malloc && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
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
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  35
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   441

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  45
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  18
/* YYNRULES -- Number of rules.  */
#define YYNRULES  63
/* YYNRULES -- Number of states.  */
#define YYNSTATES  150

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   285

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      43,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,    44,     2,     2,     2,     2,     2,     2,     2,
      38,    39,    23,    25,    40,    26,    41,    24,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    42,
      27,    37,    28,     2,     2,     2,     2,     2,     2,     2,
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
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    29,    30,
      31,    32,    33,    34,    35,    36
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     6,     8,    12,    19,    27,    29,    31,
      33,    37,    44,    54,    60,    69,    76,    86,    92,   101,
     112,   120,   124,   127,   135,   138,   142,   146,   148,   150,
     154,   159,   163,   165,   169,   173,   175,   179,   183,   187,
     191,   195,   199,   201,   203,   207,   211,   215,   219,   221,
     223,   225,   227,   229,   233,   234,   236,   239,   242,   244,
     246,   248,   250,   252
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      46,     0,    -1,    47,    60,    -1,    48,    -1,    47,    61,
      48,    -1,     7,     6,    62,    49,    62,    11,    -1,     7,
       6,    27,     6,    62,    49,    11,    -1,    50,    -1,    54,
      -1,    50,    -1,    49,    61,    50,    -1,     8,    55,     9,
      49,    61,    11,    -1,     8,    55,     9,    49,    61,    10,
      49,    61,    11,    -1,     8,    55,    49,    61,    11,    -1,
       8,    55,    49,    61,    10,    49,    61,    11,    -1,    14,
      55,     9,    49,    61,    11,    -1,    14,    55,     9,    49,
      61,    10,    49,    61,    11,    -1,    14,    55,    49,    61,
      11,    -1,    14,    55,    49,    61,    10,    49,    61,    11,
      -1,    18,    54,    21,    55,    19,    55,    62,    49,    61,
      11,    -1,    12,    55,    13,    62,    49,    61,    11,    -1,
      53,    37,    55,    -1,    20,    55,    -1,    15,     6,    51,
      62,    49,    61,    11,    -1,    38,    39,    -1,    38,    52,
      39,    -1,     6,    40,    52,    -1,     6,    -1,     6,    -1,
       6,    41,    59,    -1,     6,    38,    54,    39,    -1,    54,
      40,    55,    -1,    55,    -1,    55,    32,    56,    -1,    55,
      31,    56,    -1,    56,    -1,    57,    27,    57,    -1,    57,
      28,    57,    -1,    57,    16,    57,    -1,    57,    17,    57,
      -1,    57,    30,    57,    -1,    57,    29,    57,    -1,    57,
      -1,    58,    -1,    57,    25,    58,    -1,    57,    26,    58,
      -1,    58,    23,    59,    -1,    58,    24,    59,    -1,    59,
      -1,    53,    -1,     3,    -1,     4,    -1,     5,    -1,    38,
      55,    39,    -1,    -1,    61,    -1,    61,    42,    -1,    61,
      43,    -1,    42,    -1,    43,    -1,    44,    -1,    42,    -1,
      43,    -1,    44,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    85,    85,    88,    89,    93,    94,    95,    96,   100,
     101,   105,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,   116,   117,   121,   122,   125,   126,   129,   130,
     131,   134,   135,   138,   139,   140,   143,   144,   145,   146,
     147,   148,   149,   152,   153,   154,   157,   158,   159,   162,
     163,   164,   165,   166,   168,   169,   172,   173,   174,   175,
     176,   179,   180,   181
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "STRING", "FLOAT", "INT", "ID", "CLASS",
  "IF", "THEN", "ELSE", "END", "WHILE", "DO", "UNLESS", "DEF", "LEQ",
  "GEQ", "FOR", "TO", "RETURN", "IN", "PRINT", "'*'", "'/'", "'+'", "'-'",
  "'<'", "'>'", "NEQ", "EQ", "OR", "AND", "MUS_TT", "MUS_T", "ADD_TT",
  "ADD_T", "'='", "'('", "')'", "','", "'.'", "';'", "'\\n'", "' '",
  "$accept", "program", "topstmts", "topstmt", "stmts", "stmt",
  "opt_params", "params", "lhs", "exprs", "expr", "comp_expr",
  "additive_expr", "multiplicative_expr", "primary", "opt_terms", "terms",
  "term", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,    42,    47,    43,    45,    60,    62,   278,
     279,   280,   281,   282,   283,   284,   285,    61,    40,    41,
      44,    46,    59,    10,    32
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    45,    46,    47,    47,    48,    48,    48,    48,    49,
      49,    50,    50,    50,    50,    50,    50,    50,    50,    50,
      50,    50,    50,    50,    51,    51,    52,    52,    53,    53,
      53,    54,    54,    55,    55,    55,    56,    56,    56,    56,
      56,    56,    56,    57,    57,    57,    58,    58,    58,    59,
      59,    59,    59,    59,    60,    60,    61,    61,    61,    61,
      61,    62,    62,    62
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     1,     3,     6,     7,     1,     1,     1,
       3,     6,     9,     5,     8,     6,     9,     5,     8,    10,
       7,     3,     2,     7,     2,     3,     3,     1,     1,     3,
       4,     3,     1,     3,     3,     1,     3,     3,     3,     3,
       3,     3,     1,     1,     3,     3,     3,     3,     1,     1,
       1,     1,     1,     3,     0,     1,     2,     2,     1,     1,
       1,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    50,    51,    52,    28,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    54,     3,     7,    49,     8,    32,
      35,    42,    43,    48,     0,     0,     0,    49,     0,     0,
       0,     0,     0,    22,     0,     1,    58,    59,    60,     2,
      55,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    29,     0,    61,    62,
      63,     0,     0,     0,     9,     0,     0,     0,     0,     0,
       0,     0,    53,    56,    57,     4,    21,    31,    34,    33,
      38,    39,    44,    45,    36,    37,    41,    40,    46,    47,
      30,     0,     0,     0,     0,     0,     0,     0,    27,    24,
       0,     0,     0,     0,    58,    59,    60,     0,     0,     0,
       0,    13,    10,     0,     0,     0,    17,     0,    25,     0,
       0,     0,     5,     0,    11,     0,     0,     0,    15,     0,
      26,     0,     0,     6,     0,     0,    20,     0,     0,    23,
       0,     0,    14,     0,    18,     0,    12,    16,     0,    19
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,    13,    14,    15,    63,    64,    70,   100,    65,    18,
      19,    20,    21,    22,    23,    39,   107,    61
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -56
static const yytype_int16 yypact[] =
{
     362,   -56,   -56,   -56,   -20,    10,     1,     1,     1,    14,
       1,     1,     1,    22,     4,   -56,   -56,   -11,   -10,    47,
     -56,   170,    69,   -56,     1,     1,    60,   -56,   383,    43,
     398,    11,    -2,    47,    50,   -56,   -56,   -56,   -56,   -56,
     151,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,    56,   -56,    78,   -56,   -56,
     -56,   413,   413,     4,   -56,   -11,     9,   413,     4,     6,
       9,     1,   -56,   -56,   -56,   -56,    47,    47,   -56,   -56,
     124,   124,    69,    69,   124,   124,   124,   124,   -56,   -56,
     -56,     9,   102,     4,   162,   413,     4,   200,    32,   -56,
      62,   413,    79,   413,    88,    94,    97,   344,   104,   211,
     413,   -56,   -56,     4,   226,   413,   -56,   107,   -56,     4,
       1,    -9,   -56,   413,   -56,     4,   244,   413,   -56,     4,
     -56,   259,    86,   -56,     4,   270,   -56,     4,   285,   -56,
     413,   303,   -56,   318,   -56,     4,   -56,   -56,   329,   -56
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -56,   -56,   -56,    80,    24,     0,   -56,    16,    17,    66,
       2,   109,   389,   113,   -22,   -56,   -13,   -55
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -64
static const yytype_int16 yytable[] =
{
      16,    40,   133,    56,     1,     2,     3,     4,    28,    29,
      30,    95,    98,    33,    34,   101,    26,    17,    24,    71,
      31,    25,    35,    27,    27,    27,    41,    27,    27,    27,
      42,    88,    89,    36,    37,    38,   103,   108,    42,    12,
      16,    27,    27,    76,    77,    99,    36,    37,    38,    69,
      94,    58,    59,    60,    68,    97,    66,    17,    27,    27,
      27,    27,    27,    27,    27,    27,    27,    27,    27,    27,
      27,    27,   117,   102,    43,    44,    32,   140,    43,    44,
     109,    43,    44,   114,    91,    92,    93,    57,    27,    72,
      55,    96,    53,    54,   112,    90,    42,   112,   120,   -61,
     126,   118,    58,    59,    60,   -62,   131,   112,   -63,   112,
      43,    44,   135,    98,   112,   122,   138,    43,    44,   113,
      75,   141,   132,     0,   143,   119,   112,   121,    58,    59,
      60,   112,   148,   130,   125,   112,     0,    27,   112,   129,
       0,   112,     0,   112,   104,   105,   106,   134,   112,    47,
      48,   137,    78,    79,     1,     2,     3,     4,     5,     6,
      82,    83,     0,     7,   145,     8,     9,     0,     4,    10,
       6,    11,   110,   111,     7,     0,     8,     9,     0,     0,
      10,     0,    11,     0,     0,     0,    45,    46,     0,    12,
       0,     0,     0,    73,    74,    47,    48,    49,    50,    51,
      52,     0,     0,     0,    73,    74,     4,     0,     6,     0,
     115,   116,     7,     0,     8,     9,     0,     4,    10,     6,
      11,   123,   124,     7,     0,     8,     9,     0,     0,    10,
       0,    11,     4,     0,     6,     0,   127,   128,     7,     0,
       8,     9,    73,    74,    10,     0,    11,     0,     0,     0,
       4,     0,     6,    73,    74,   136,     7,     0,     8,     9,
       0,     0,    10,     0,    11,     4,     0,     6,    73,    74,
     139,     7,     0,     8,     9,     0,     4,    10,     6,    11,
       0,   142,     7,     0,     8,     9,    73,    74,    10,     0,
      11,     4,     0,     6,     0,     0,   144,     7,     0,     8,
       9,    73,    74,    10,     0,    11,     0,     0,     0,     4,
       0,     6,    73,    74,   146,     7,     0,     8,     9,     0,
       0,    10,     0,    11,     4,     0,     6,    73,    74,   147,
       7,     0,     8,     9,     0,     4,    10,     6,    11,     0,
     149,     7,     0,     8,     9,    73,    74,    10,     0,    11,
       4,     0,     6,     0,     0,     0,     7,     0,     8,     9,
      73,    74,    10,     0,    11,     1,     2,     3,     4,     5,
       6,    73,    74,     0,     7,     0,     8,     9,     0,     0,
      10,     0,    11,     0,     0,     0,    73,    74,     0,     4,
       0,     6,    62,     0,     0,     7,     0,     8,     9,     0,
      12,    10,     0,    11,     4,     0,     6,    67,     0,     0,
       7,     0,     8,     9,    43,    44,    10,     0,    11,     4,
       0,     6,     0,     0,     0,     7,     0,     8,     9,    43,
      44,    10,     0,    11,    80,    81,     0,     0,    84,    85,
      86,    87
};

#define yypact_value_is_default(yystate) \
  ((yystate) == (-56))

#define yytable_value_is_error(yytable_value) \
  YYID (0)

static const yytype_int16 yycheck[] =
{
       0,    14,    11,    25,     3,     4,     5,     6,     6,     7,
       8,    66,     6,    11,    12,    70,     6,     0,    38,    21,
       6,    41,     0,     6,     7,     8,    37,    10,    11,    12,
      40,    53,    54,    42,    43,    44,    91,    92,    40,    38,
      40,    24,    25,    41,    42,    39,    42,    43,    44,    38,
      63,    42,    43,    44,    30,    68,    13,    40,    41,    42,
      43,    44,    45,    46,    47,    48,    49,    50,    51,    52,
      53,    54,    40,    71,    31,    32,    10,   132,    31,    32,
      93,    31,    32,    96,     6,    61,    62,    27,    71,    39,
      24,    67,    23,    24,    94,    39,    40,    97,    19,    11,
     113,    39,    42,    43,    44,    11,   119,   107,    11,   109,
      31,    32,   125,     6,   114,    11,   129,    31,    32,    95,
      40,   134,   120,    -1,   137,   101,   126,   103,    42,    43,
      44,   131,   145,   117,   110,   135,    -1,   120,   138,   115,
      -1,   141,    -1,   143,    42,    43,    44,   123,   148,    25,
      26,   127,    43,    44,     3,     4,     5,     6,     7,     8,
      47,    48,    -1,    12,   140,    14,    15,    -1,     6,    18,
       8,    20,    10,    11,    12,    -1,    14,    15,    -1,    -1,
      18,    -1,    20,    -1,    -1,    -1,    16,    17,    -1,    38,
      -1,    -1,    -1,    42,    43,    25,    26,    27,    28,    29,
      30,    -1,    -1,    -1,    42,    43,     6,    -1,     8,    -1,
      10,    11,    12,    -1,    14,    15,    -1,     6,    18,     8,
      20,    10,    11,    12,    -1,    14,    15,    -1,    -1,    18,
      -1,    20,     6,    -1,     8,    -1,    10,    11,    12,    -1,
      14,    15,    42,    43,    18,    -1,    20,    -1,    -1,    -1,
       6,    -1,     8,    42,    43,    11,    12,    -1,    14,    15,
      -1,    -1,    18,    -1,    20,     6,    -1,     8,    42,    43,
      11,    12,    -1,    14,    15,    -1,     6,    18,     8,    20,
      -1,    11,    12,    -1,    14,    15,    42,    43,    18,    -1,
      20,     6,    -1,     8,    -1,    -1,    11,    12,    -1,    14,
      15,    42,    43,    18,    -1,    20,    -1,    -1,    -1,     6,
      -1,     8,    42,    43,    11,    12,    -1,    14,    15,    -1,
      -1,    18,    -1,    20,     6,    -1,     8,    42,    43,    11,
      12,    -1,    14,    15,    -1,     6,    18,     8,    20,    -1,
      11,    12,    -1,    14,    15,    42,    43,    18,    -1,    20,
       6,    -1,     8,    -1,    -1,    -1,    12,    -1,    14,    15,
      42,    43,    18,    -1,    20,     3,     4,     5,     6,     7,
       8,    42,    43,    -1,    12,    -1,    14,    15,    -1,    -1,
      18,    -1,    20,    -1,    -1,    -1,    42,    43,    -1,     6,
      -1,     8,     9,    -1,    -1,    12,    -1,    14,    15,    -1,
      38,    18,    -1,    20,     6,    -1,     8,     9,    -1,    -1,
      12,    -1,    14,    15,    31,    32,    18,    -1,    20,     6,
      -1,     8,    -1,    -1,    -1,    12,    -1,    14,    15,    31,
      32,    18,    -1,    20,    45,    46,    -1,    -1,    49,    50,
      51,    52
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     4,     5,     6,     7,     8,    12,    14,    15,
      18,    20,    38,    46,    47,    48,    50,    53,    54,    55,
      56,    57,    58,    59,    38,    41,     6,    53,    55,    55,
      55,     6,    54,    55,    55,     0,    42,    43,    44,    60,
      61,    37,    40,    31,    32,    16,    17,    25,    26,    27,
      28,    29,    30,    23,    24,    54,    59,    27,    42,    43,
      44,    62,     9,    49,    50,    53,    13,     9,    49,    38,
      51,    21,    39,    42,    43,    48,    55,    55,    56,    56,
      57,    57,    58,    58,    57,    57,    57,    57,    59,    59,
      39,     6,    49,    49,    61,    62,    49,    61,     6,    39,
      52,    62,    55,    62,    42,    43,    44,    61,    62,    61,
      10,    11,    50,    49,    61,    10,    11,    40,    39,    49,
      19,    49,    11,    10,    11,    49,    61,    10,    11,    49,
      52,    61,    55,    11,    49,    61,    11,    49,    61,    11,
      62,    61,    11,    61,    11,    49,    11,    11,    61,    11
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  However,
   YYFAIL appears to be in use.  Nevertheless, it is formally deprecated
   in Bison 2.4.2's NEWS entry, where a plan to phase it out is
   discussed.  */

#define YYFAIL		goto yyerrlab
#if defined YYFAIL
  /* This is here to suppress warnings from the GCC cpp's
     -Wunused-macros.  Normally we don't worry about that warning, but
     some users do, and we want to make it easy for users to remove
     YYFAIL uses, which will produce warnings from Bison 2.5.  */
#endif

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* This macro is provided for backward compatibility. */

#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

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
#ifndef	YYINITDEPTH
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
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
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
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
  YYSIZE_T yysize0 = yytnamerr (0, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  YYSIZE_T yysize1;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = 0;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - Assume YYFAIL is not used.  It's too flawed to consider.  See
       <http://lists.gnu.org/archive/html/bison-patches/2009-12/msg00024.html>
       for details.  YYERROR is fine as it does not invoke this
       function.
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
                yysize1 = yysize + yytnamerr (0, yytname[yyx]);
                if (! (yysize <= yysize1
                       && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                  return 2;
                yysize = yysize1;
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

  yysize1 = yysize + yystrlen (yyformat);
  if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
    return 2;
  yysize = yysize1;

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

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
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
  int yytoken;
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

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

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
      yychar = YYLEX;
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
  *++yyvsp = yylval;

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
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:

/* Line 1806 of yacc.c  */
#line 85 "parse.y"
    {printf("fini");}
    break;

  case 3:

/* Line 1806 of yacc.c  */
#line 88 "parse.y"
    {(yyval.node) = (yyvsp[(1) - (1)].node);;printf("I am in topstmt\n");}
    break;

  case 4:

/* Line 1806 of yacc.c  */
#line 89 "parse.y"
    {}
    break;

  case 5:

/* Line 1806 of yacc.c  */
#line 93 "parse.y"
    {printf("--------------------------------class\n");}
    break;

  case 6:

/* Line 1806 of yacc.c  */
#line 94 "parse.y"
    {}
    break;

  case 7:

/* Line 1806 of yacc.c  */
#line 95 "parse.y"
    {(yyval.node) = (yyvsp[(1) - (1)].node);}
    break;

  case 8:

/* Line 1806 of yacc.c  */
#line 96 "parse.y"
    {(yyval.node) = (yyvsp[(1) - (1)].node);printf("I am in exprs\n");}
    break;

  case 9:

/* Line 1806 of yacc.c  */
#line 100 "parse.y"
    {(yyval.node) = (yyvsp[(1) - (1)].node);}
    break;

  case 10:

/* Line 1806 of yacc.c  */
#line 101 "parse.y"
    {}
    break;

  case 11:

/* Line 1806 of yacc.c  */
#line 105 "parse.y"
    {(yyval.node) = opr(IF, 2, (yyvsp[(2) - (6)].node), (yyvsp[(4) - (6)].node)); printf("\tif\n");}
    break;

  case 12:

/* Line 1806 of yacc.c  */
#line 106 "parse.y"
    {(yyval.node) = opr(IF, 3, (yyvsp[(2) - (9)].node), (yyvsp[(4) - (9)].node), (yyvsp[(7) - (9)].node));printf("\tif\n");}
    break;

  case 13:

/* Line 1806 of yacc.c  */
#line 107 "parse.y"
    {(yyval.node) = opr(IF, 2, (yyvsp[(2) - (5)].node), (yyvsp[(3) - (5)].node));printf("if\n");}
    break;

  case 14:

/* Line 1806 of yacc.c  */
#line 108 "parse.y"
    {(yyval.node) = opr(IF, 3, (yyvsp[(2) - (8)].node), (yyvsp[(4) - (8)].node), (yyvsp[(6) - (8)].node));printf("\tif\n");}
    break;

  case 15:

/* Line 1806 of yacc.c  */
#line 109 "parse.y"
    {(yyval.node) = opr(UNLESS, 2, (yyvsp[(2) - (6)].node), (yyvsp[(4) - (6)].node));printf("\tunless\n");}
    break;

  case 16:

/* Line 1806 of yacc.c  */
#line 110 "parse.y"
    {(yyval.node) = opr(UNLESS, 3, (yyvsp[(2) - (9)].node), (yyvsp[(4) - (9)].node), (yyvsp[(7) - (9)].node));printf("\tunless\n");}
    break;

  case 17:

/* Line 1806 of yacc.c  */
#line 111 "parse.y"
    {(yyval.node) = opr(UNLESS, 2, (yyvsp[(2) - (5)].node), (yyvsp[(3) - (5)].node));printf("\tunless\n");}
    break;

  case 18:

/* Line 1806 of yacc.c  */
#line 112 "parse.y"
    {(yyval.node) = opr(IF, 3, (yyvsp[(2) - (8)].node), (yyvsp[(4) - (8)].node), (yyvsp[(6) - (8)].node));printf("\tunless\n");}
    break;

  case 19:

/* Line 1806 of yacc.c  */
#line 113 "parse.y"
    {(yyval.node) = opr(FOR, 4, (yyvsp[(2) - (10)].node), (yyvsp[(4) - (10)].node), (yyvsp[(6) - (10)].node), (yyvsp[(8) - (10)].node));printf("\tfor\n");}
    break;

  case 20:

/* Line 1806 of yacc.c  */
#line 114 "parse.y"
    {(yyval.node) = opr(WHILE,2,(yyvsp[(2) - (7)].node),(yyvsp[(5) - (7)].node));printf("\twhile\n");}
    break;

  case 21:

/* Line 1806 of yacc.c  */
#line 115 "parse.y"
    {(yyval.node) = opr('=', 2, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));}
    break;

  case 22:

/* Line 1806 of yacc.c  */
#line 116 "parse.y"
    {(yyval.node) = (yyvsp[(2) - (2)].node);}
    break;

  case 23:

/* Line 1806 of yacc.c  */
#line 117 "parse.y"
    {(yyval.node) = opr(DEF,3,(yyvsp[(2) - (7)].index),(yyvsp[(3) - (7)].node),(yyvsp[(5) - (7)].node));printf("\t\tdef\n");}
    break;

  case 24:

/* Line 1806 of yacc.c  */
#line 121 "parse.y"
    {}
    break;

  case 25:

/* Line 1806 of yacc.c  */
#line 122 "parse.y"
    {(yyval.node) = (yyvsp[(2) - (3)].node);}
    break;

  case 26:

/* Line 1806 of yacc.c  */
#line 125 "parse.y"
    {}
    break;

  case 27:

/* Line 1806 of yacc.c  */
#line 126 "parse.y"
    {(yyval.node) = set_index((yyvsp[(1) - (1)].index)); printf("id\n");}
    break;

  case 28:

/* Line 1806 of yacc.c  */
#line 129 "parse.y"
    {(yyval.node) = set_index((yyvsp[(1) - (1)].index));printf("id\n");}
    break;

  case 29:

/* Line 1806 of yacc.c  */
#line 130 "parse.y"
    {}
    break;

  case 30:

/* Line 1806 of yacc.c  */
#line 131 "parse.y"
    {(yyval.node) = opr('=', 2, set_index((yyvsp[(1) - (4)].index)), (yyvsp[(3) - (4)].node));}
    break;

  case 31:

/* Line 1806 of yacc.c  */
#line 134 "parse.y"
    {}
    break;

  case 32:

/* Line 1806 of yacc.c  */
#line 135 "parse.y"
    {(yyval.node) = (yyvsp[(1) - (1)].node);printf("I am in expr\n");}
    break;

  case 33:

/* Line 1806 of yacc.c  */
#line 138 "parse.y"
    {(yyval.node) = opr(AND, 2, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));}
    break;

  case 34:

/* Line 1806 of yacc.c  */
#line 139 "parse.y"
    {(yyval.node) = opr(OR, 2, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));}
    break;

  case 35:

/* Line 1806 of yacc.c  */
#line 140 "parse.y"
    {(yyval.node) = (yyvsp[(1) - (1)].node);printf("I am in com_expr\n");}
    break;

  case 36:

/* Line 1806 of yacc.c  */
#line 143 "parse.y"
    {(yyval.node) = opr('<', 2, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));(yyval.node)->valuetype = tab_comp[(yyvsp[(1) - (3)].node)->valuetype][(yyvsp[(3) - (3)].node)->valuetype];}
    break;

  case 37:

/* Line 1806 of yacc.c  */
#line 144 "parse.y"
    {(yyval.node) = opr('>', 2, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));(yyval.node)->valuetype = tab_comp[(yyvsp[(1) - (3)].node)->valuetype][(yyvsp[(3) - (3)].node)->valuetype];}
    break;

  case 38:

/* Line 1806 of yacc.c  */
#line 145 "parse.y"
    {(yyval.node) = opr(LEQ, 2, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));(yyval.node)->valuetype = tab_comp[(yyvsp[(1) - (3)].node)->valuetype][(yyvsp[(3) - (3)].node)->valuetype];}
    break;

  case 39:

/* Line 1806 of yacc.c  */
#line 146 "parse.y"
    {(yyval.node) = opr(GEQ, 2, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));(yyval.node)->valuetype = tab_comp[(yyvsp[(1) - (3)].node)->valuetype][(yyvsp[(3) - (3)].node)->valuetype];}
    break;

  case 40:

/* Line 1806 of yacc.c  */
#line 147 "parse.y"
    {(yyval.node) = opr(EQ , 2, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));(yyval.node)->valuetype = tab_comp[(yyvsp[(1) - (3)].node)->valuetype][(yyvsp[(3) - (3)].node)->valuetype];}
    break;

  case 41:

/* Line 1806 of yacc.c  */
#line 148 "parse.y"
    {(yyval.node) = opr(NEQ, 2, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));(yyval.node)->valuetype = tab_comp[(yyvsp[(1) - (3)].node)->valuetype][(yyvsp[(3) - (3)].node)->valuetype];}
    break;

  case 42:

/* Line 1806 of yacc.c  */
#line 149 "parse.y"
    {(yyval.node) = (yyvsp[(1) - (1)].node);printf("I am in additive_expr\n");}
    break;

  case 43:

/* Line 1806 of yacc.c  */
#line 152 "parse.y"
    {(yyval.node) = (yyvsp[(1) - (1)].node);printf("I am in multipicative_expr\n");}
    break;

  case 44:

/* Line 1806 of yacc.c  */
#line 153 "parse.y"
    {(yyval.node) = opr('+', 2, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));(yyval.node)->valuetype = tab_plus[(yyvsp[(1) - (3)].node)->valuetype][(yyvsp[(3) - (3)].node)->valuetype];}
    break;

  case 45:

/* Line 1806 of yacc.c  */
#line 154 "parse.y"
    {(yyval.node) = opr('-', 2, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));(yyval.node)->valuetype = tab_plus[(yyvsp[(1) - (3)].node)->valuetype][(yyvsp[(3) - (3)].node)->valuetype];}
    break;

  case 46:

/* Line 1806 of yacc.c  */
#line 157 "parse.y"
    {(yyval.node) = opr('*', 2, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));(yyval.node)->valuetype = tab_mult[(yyvsp[(1) - (3)].node)->valuetype][(yyvsp[(3) - (3)].node)->valuetype];}
    break;

  case 47:

/* Line 1806 of yacc.c  */
#line 158 "parse.y"
    {(yyval.node) = opr('/', 2, (yyvsp[(1) - (3)].node), (yyvsp[(3) - (3)].node));(yyval.node)->valuetype = tab_mult[(yyvsp[(1) - (3)].node)->valuetype][(yyvsp[(3) - (3)].node)->valuetype];}
    break;

  case 48:

/* Line 1806 of yacc.c  */
#line 159 "parse.y"
    {(yyval.node) = (yyvsp[(1) - (1)].node);printf("I am in primary\n");}
    break;

  case 50:

/* Line 1806 of yacc.c  */
#line 163 "parse.y"
    {(yyval.node) = NewNodeString((yyvsp[(1) - (1)].sval));printf("string");}
    break;

  case 51:

/* Line 1806 of yacc.c  */
#line 164 "parse.y"
    {(yyval.node) = NewNodeFloat((yyvsp[(1) - (1)].fval));printf("float");}
    break;

  case 52:

/* Line 1806 of yacc.c  */
#line 165 "parse.y"
    {(yyval.node) = NewNodeInt((yyvsp[(1) - (1)].ival));printf("int");}
    break;

  case 53:

/* Line 1806 of yacc.c  */
#line 166 "parse.y"
    {(yyval.node) = (yyvsp[(2) - (3)].node);}
    break;

  case 57:

/* Line 1806 of yacc.c  */
#line 173 "parse.y"
    {}
    break;

  case 58:

/* Line 1806 of yacc.c  */
#line 174 "parse.y"
    {(yyval.node) = opr(';', 2, NULL, NULL);}
    break;

  case 59:

/* Line 1806 of yacc.c  */
#line 175 "parse.y"
    {}
    break;

  case 60:

/* Line 1806 of yacc.c  */
#line 176 "parse.y"
    {}
    break;

  case 61:

/* Line 1806 of yacc.c  */
#line 179 "parse.y"
    {(yyval.node) = opr(';', 2, NULL, NULL);}
    break;

  case 62:

/* Line 1806 of yacc.c  */
#line 180 "parse.y"
    {}
    break;

  case 63:

/* Line 1806 of yacc.c  */
#line 181 "parse.y"
    {}
    break;



/* Line 1806 of yacc.c  */
#line 2045 "y.tab.c"
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

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
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

  /* Do not reclaim the symbols of the rule which action triggered
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
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

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

  *++yyvsp = yylval;


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

#if !defined(yyoverflow) || YYERROR_VERBOSE
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
  /* Do not reclaim the symbols of the rule which action triggered
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
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



/* Line 2067 of yacc.c  */
#line 184 "parse.y"


void add_var(char *mark) {

 if(G_iVarMaxIndex==0){
  strcpy(G_Var[0].mark,mark);
  G_iVarMaxIndex++;
  G_iVarCurIndex=0;
  return;
 }

 int i;

 for(i=0;i<=G_iVarMaxIndex-1;i++) {

  if(strcmp(G_Var[i].mark,mark)==0) {
   G_iVarCurIndex=i;
   return;

  }
 }

 strcpy(G_Var[G_iVarMaxIndex].mark,mark);
 G_iVarCurIndex=G_iVarMaxIndex;
 G_iVarMaxIndex++;
}

float NodeExecute(Node *p) {

 if (!p) return 0;

 switch(p->type) {
  case TYPE_CONTENT: return p->content->f;
  case TYPE_INDEX:   return G_Var[p->index].val;
  case TYPE_OP:

   switch(p->op.name) {
   case DEF:
     NodeExecute(p->op.node[0]);
     return 0;
   
   case CLASS:
     return 0;
     
   case WHILE:  
     while(NodeExecute(p->op.node[0]))
       NodeExecute(p->op.node[1]);
     return 0;              

   case FOR:    
     while((NodeExecute(p->op.node[0]) <= NodeExecute(p->op.node[1]))
	   && (NodeExecute(p->op.node[0]) >= NodeExecute(p->op.node[2]))) {
       NodeExecute(p->op.node[3]);
     }
     return 0;
   

   case IF:     
     if (NodeExecute(p->op.node[0]))
       NodeExecute(p->op.node[1]);
     else
       if (p->op.num>2)
	 NodeExecute(p->op.node[2]);
     return 0;
     
   case UNLESS:
     if(!NodeExecute(p->op.node[0]))
       NodeExecute(p->op.node[1]);
     else
       if(!p->op.num>2)
	 NodeExecute(p->op.node[2]);
     return 0;

   case PRINT:  
     //printf("%g\n", NodeExecute(p->op.node[0]));
     NodePrint(p->op.node[0]);
     return 0;         

   case ';':    NodeExecute(p->op.node[0]);
                return NodeExecute(p->op.node[1]);
   case '=':    return G_Var[p->op.node[0]->index].val = NodeExecute(p->op.node[1]);
   case '+':    return NodeExecute(p->op.node[0]) + NodeExecute(p->op.node[1]);
   case '-':    return NodeExecute(p->op.node[0]) - NodeExecute(p->op.node[1]);
   case '*':    return NodeExecute(p->op.node[0]) * NodeExecute(p->op.node[1]);
   case '/':    return NodeExecute(p->op.node[0]) / NodeExecute(p->op.node[1]);
   case '<':    return NodeExecute(p->op.node[0]) < NodeExecute(p->op.node[1]);
   case '>':    return NodeExecute(p->op.node[0]) > NodeExecute(p->op.node[1]);
   case GEQ:    return NodeExecute(p->op.node[0]) >= NodeExecute(p->op.node[1]);
   case LEQ:    return NodeExecute(p->op.node[0]) <= NodeExecute(p->op.node[1]);
   case NEQ:    return NodeExecute(p->op.node[0]) != NodeExecute(p->op.node[1]);
   case EQ:     return NodeExecute(p->op.node[0]) == NodeExecute(p->op.node[1]);
   case AND:    return NodeExecute(p->op.node[0]) && NodeExecute(p->op.node[1]);
   case OR:     return NodeExecute(p->op.node[0]) || NodeExecute(p->op.node[1]);  
   case ADD_T:  return ++G_Var[p->op.node[0]->index].val;
   case MUS_T:  return --G_Var[p->op.node[0]->index].val;
   case ADD_TT: return G_Var[p->op.node[0]->index].val++;
   case MUS_TT: return G_Var[p->op.node[0]->index].val--;
   }
 }
 return 0;

}


int main(void) {
  init_tab(tab_plus,tab_mult,tab_comp);

  //creer le fichier
  
  yyparse();
  return 0;

}

