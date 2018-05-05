/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

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
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "bison.y" /* yacc.c:339  */

  #include <math.h>
  #include <stdio.h>
  #include <stdlib.h>
  #include <string.h>
  #include <ctype.h>
  #include <stdint.h>
  extern FILE *yyin;
  
  int yylex (void);
  void yyerror (char const *);
  int check_divider (double);
  int check_mod (int);
  void init_file();
  void fprint(char*,char*);
  void fprintln();
  int addText(char *);
  void asmPrint(int,int);
  void asmLineOnly();
  void endFile();
  struct exp *createExp(double,char,int,struct exp*,struct exp*);
  struct loop *createLoop(int,int);
  void printExp(struct exp*);
  void addValue(int);
  void condition(char*);
  void loopFirst(struct loop*);
  void loopEnd(struct loop*);
  void printDec();
  void printHex();
  void println();
  void pushAll();
  void popAll();
  
  struct text {
    int id;
    char *txt;
    struct text *next;
  };

  struct exp {
    char operation;
    double value;
    int type;
    char position;
    struct exp *left,*right;
  };

  struct loop {
    int id;
    int number;
  };

  struct text *str;

  int errors = 0;
  int done = 0;
  int id=0,pow_id=0,if_id=0,loop_id=0;
  double variable[26]={0};
  char tmp[2];
  FILE *fp;

  

#line 130 "bison.tab.c" /* yacc.c:339  */

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
   by #include "bison.tab.h".  */
#ifndef YY_YY_BISON_TAB_H_INCLUDED
# define YY_YY_BISON_TAB_H_INCLUDED
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
    END_OF_FILE = 0,
    T_GRATHER = 258,
    T_LESS = 259,
    T_GE = 260,
    T_LE = 261,
    T_NE = 262,
    T_NOT = 263,
    T_EQUAL = 264,
    T_POW = 265,
    T_PLUS = 266,
    T_MINUS = 267,
    T_MULTIPLY = 268,
    T_DIVIDE = 269,
    T_LEFT = 270,
    T_RIGHT = 271,
    T_NUM = 272,
    T_COND = 273,
    T_ELSE = 274,
    T_LOOP = 275,
    T_VAL = 276,
    T_PRINT = 277,
    T_PRINTLN = 278,
    T_HEX = 279,
    T_COLON = 280,
    T_QUOTE = 281,
    T_LINE = 282,
    T_COMMA = 283,
    T_ROUND = 284,
    T_STR = 285,
    T_MOD = 286,
    NEG = 287
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 65 "bison.y" /* yacc.c:355  */

	double f;
  char *s;
  struct exp *e;
  struct loop *l;

#line 211 "bison.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_BISON_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 228 "bison.tab.c" /* yacc.c:358  */

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
#define YYFINAL  23
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   137

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  33
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  8
/* YYNRULES -- Number of rules.  */
#define YYNRULES  42
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  102

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   287

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    90,    90,    94,    95,    98,   101,   108,   109,   110,
     113,   119,   120,   127,   133,   134,   140,   146,   153,   159,
     166,   167,   168,   169,   170,   171,   174,   175,   176,   181,
     186,   191,   196,   201,   206,   210,   213,   220,   227,   234,
     241,   248,   257
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "END_OF_FILE", "error", "$undefined", "T_GRATHER", "T_LESS", "T_GE",
  "T_LE", "T_NE", "T_NOT", "T_EQUAL", "T_POW", "T_PLUS", "T_MINUS",
  "T_MULTIPLY", "T_DIVIDE", "T_LEFT", "T_RIGHT", "T_NUM", "T_COND",
  "T_ELSE", "T_LOOP", "T_VAL", "T_PRINT", "T_PRINTLN", "T_HEX", "T_COLON",
  "T_QUOTE", "T_LINE", "T_COMMA", "T_ROUND", "T_STR", "T_MOD", "NEG",
  "$accept", "prog", "input", "line", "command", "exp", "check", "round", YY_NULLPTR
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
     285,   286,   287
};
# endif

#define YYPACT_NINF -71

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-71)))

#define YYTABLE_NINF -1

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      82,    94,    94,   -71,    -2,     1,    48,    36,    56,    86,
      23,   -71,   -71,    35,   -71,   -71,    79,    49,    94,    62,
      94,    75,    67,   -71,   -71,    71,    82,    94,    94,    94,
      94,    94,    94,    94,    94,    94,    94,    94,    94,   -71,
      35,    91,   -71,    92,    64,   -14,   -12,    -6,   -71,   -13,
      51,    42,    82,   -71,    64,    64,    64,    64,    64,    64,
      79,    54,    54,    79,    79,    79,    85,    87,   -71,    89,
      95,    97,   -71,    98,   -71,   100,    99,   101,   -71,   102,
     -71,    96,    96,   104,   112,   113,   114,   115,   116,   117,
     118,    48,   -71,   -71,   -71,   -71,   -71,   -71,   -71,   -71,
     -71,   -71
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       3,     0,     0,    26,     0,     0,    27,     0,     0,     0,
       0,     4,     8,     7,     9,    27,    34,     0,     0,     0,
       0,     0,     0,     1,     2,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    35,
       0,     0,    42,     0,    11,    27,     0,     0,    14,    27,
       0,     0,     0,     5,    36,    37,    38,    39,    40,    41,
      33,    28,    29,    30,    31,    32,     0,     0,    10,     0,
       0,     0,    13,     0,    12,     0,     0,     0,    15,     0,
       6,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    24,    25,    16,    22,    20,    18,    17,    23,
      21,    19
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -71,   -71,   -71,    17,   -70,    -1,   119,   -71
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     9,    10,    11,    12,    13,    14,    43
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_uint8 yytable[] =
{
      16,    17,    68,    74,    33,    34,    35,    36,    37,    70,
      72,    92,    93,    18,    69,    75,    19,    40,    71,    44,
      47,    51,    73,    24,    25,    38,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    27,    28,
      29,    30,    31,    53,    32,    33,    34,    35,    36,    37,
      26,    21,    33,    34,    35,    36,    37,    20,    78,    33,
      34,    35,    36,    37,    33,    39,    38,    36,    37,    80,
      79,    22,    76,    38,    33,    34,    35,    36,    37,     1,
      38,    77,     2,    48,     3,    38,    23,     1,    49,    33,
       2,    42,     3,    50,     1,    38,    45,     2,    52,     3,
       4,    46,     5,     6,     7,     8,     1,    66,    67,     2,
      81,     3,    82,    83,     4,    15,     5,    91,     7,     8,
      94,    84,    86,    85,    87,    88,    90,    89,    95,    96,
      97,    98,    99,   100,   101,     0,     0,    41
};

static const yytype_int8 yycheck[] =
{
       1,     2,    16,    16,    10,    11,    12,    13,    14,    21,
      16,    81,    82,    15,    28,    28,    15,    18,    30,    20,
      21,    22,    28,     0,     1,    31,    27,    28,    29,    30,
      31,    32,    33,    34,    35,    36,    37,    38,     3,     4,
       5,     6,     7,    26,     9,    10,    11,    12,    13,    14,
      27,    15,    10,    11,    12,    13,    14,     9,    16,    10,
      11,    12,    13,    14,    10,    16,    31,    13,    14,    52,
      28,    15,    21,    31,    10,    11,    12,    13,    14,    12,
      31,    30,    15,    16,    17,    31,     0,    12,    21,    10,
      15,    29,    17,    26,    12,    31,    21,    15,    27,    17,
      18,    26,    20,    21,    22,    23,    12,    16,    16,    15,
      25,    17,    25,    24,    18,    21,    20,    21,    22,    23,
      16,    26,    24,    26,    24,    26,    24,    26,    16,    16,
      16,    16,    16,    16,    16,    -1,    -1,    18
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    12,    15,    17,    18,    20,    21,    22,    23,    34,
      35,    36,    37,    38,    39,    21,    38,    38,    15,    15,
       9,    15,    15,     0,     0,     1,    27,     3,     4,     5,
       6,     7,     9,    10,    11,    12,    13,    14,    31,    16,
      38,    39,    29,    40,    38,    21,    26,    38,    16,    21,
      26,    38,    27,    36,    38,    38,    38,    38,    38,    38,
      38,    38,    38,    38,    38,    38,    16,    16,    16,    28,
      21,    30,    16,    28,    16,    28,    21,    30,    16,    28,
      36,    25,    25,    24,    26,    26,    24,    24,    26,    26,
      24,    21,    37,    37,    16,    16,    16,    16,    16,    16,
      16,    16
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    33,    34,    35,    35,    35,    35,    36,    36,    36,
      37,    37,    37,    37,    37,    37,    37,    37,    37,    37,
      37,    37,    37,    37,    37,    37,    38,    38,    38,    38,
      38,    38,    38,    38,    38,    38,    39,    39,    39,    39,
      39,    39,    40
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     2,     0,     1,     3,     4,     1,     1,     1,
       4,     3,     4,     4,     3,     4,     6,     6,     6,     6,
       6,     6,     6,     6,     6,     6,     1,     1,     3,     3,
       3,     3,     3,     3,     2,     3,     3,     3,     3,     3,
       3,     3,     1
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
        case 2:
#line 90 "bison.y" /* yacc.c:1646  */
    { endFile(); }
#line 1371 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 95 "bison.y" /* yacc.c:1646  */
    {

  }
#line 1379 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 98 "bison.y" /* yacc.c:1646  */
    {
      errors=0;
  }
#line 1387 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 101 "bison.y" /* yacc.c:1646  */
    {
      errors = 0;
      YYABORT;
  }
#line 1396 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 108 "bison.y" /* yacc.c:1646  */
    { printExp((yyvsp[0].e)); }
#line 1402 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 113 "bison.y" /* yacc.c:1646  */
    { 
                                                                  fprintf(fp,"\tMOV\trax,[value+%d]\n",(int)(yyvsp[-1].f)*8);  
                                                                  pushAll();
                                                                  fprintf(fp,"\tCALL\tprintDec\n\n"); 
                                                                  popAll();
                                                               }
#line 1413 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 119 "bison.y" /* yacc.c:1646  */
    { printExp((yyvsp[0].e)); addValue((int)(yyvsp[-2].f)); }
#line 1419 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 120 "bison.y" /* yacc.c:1646  */
    { 
                                                                  fprintf(fp,"\tMOV\trax,[value+%d]\n",(int)(yyvsp[-1].f)*8);  
                                                                  pushAll();
                                                                  fprintf(fp,"\tCALL\tprintDec\n\n"); 
                                                                  popAll();
                                                                  fprintf(fp,"\tCALL\tprintLineOnly\n\n");
                                                               }
#line 1431 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 127 "bison.y" /* yacc.c:1646  */
    { 
                                                                  printExp((yyvsp[-1].e));  
                                                                  pushAll();
                                                                  fprintf(fp,"\tCALL\tprintDec\n\n"); 
                                                                  popAll();
                                                               }
#line 1442 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 133 "bison.y" /* yacc.c:1646  */
    { fprintf(fp,"\tCALL\tprintLineOnly\n\n"); }
#line 1448 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 134 "bison.y" /* yacc.c:1646  */
    { 
                                                                  printExp((yyvsp[-1].e));
                                                                  pushAll(); 
                                                                  fprintf(fp,"\tCALL\tprintDec\n\n"); 
                                                                  popAll();
                                                               }
#line 1459 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 140 "bison.y" /* yacc.c:1646  */
    {  
                                                                  fprintf(fp,"\tMOV\trax,[value+%d]\n",(int)(yyvsp[-3].f)*8);  
                                                                  pushAll();
                                                                  fprintf(fp,"\tCALL\tprintHex\n\n"); 
                                                                  popAll();
                                                               }
#line 1470 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 146 "bison.y" /* yacc.c:1646  */
    {  
                                                                  fprintf(fp,"\tMOV\trax,[value+%d]\n",(int)(yyvsp[-3].f)*8);  
                                                                  pushAll();
                                                                  fprintf(fp,"\tCALL\tprintHex\n\n"); 
                                                                  popAll();
                                                                  fprintf(fp,"\tCALL\tprintLineOnly\n\n");
                                                               }
#line 1482 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 153 "bison.y" /* yacc.c:1646  */
    { 
                                                                  printExp((yyvsp[-3].e)); 
                                                                  pushAll();
                                                                  fprintf(fp,"\tCALL\tprintHex\n\n"); 
                                                                  popAll();
                                                               }
#line 1493 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 159 "bison.y" /* yacc.c:1646  */
    { 
                                                                  printExp((yyvsp[-3].e)); 
                                                                  pushAll();
                                                                  fprintf(fp,"\tCALL\tprintHex\n\n"); 
                                                                  popAll(); 
                                                                  fprintf(fp,"\tCALL\tprintLineOnly\n\n");
                                                               }
#line 1505 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 166 "bison.y" /* yacc.c:1646  */
    { asmPrint(addText((yyvsp[-2].s)),strlen((yyvsp[-2].s))); }
#line 1511 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 167 "bison.y" /* yacc.c:1646  */
    { asmPrint(addText((yyvsp[-2].s)),strlen((yyvsp[-2].s))+1); }
#line 1517 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 168 "bison.y" /* yacc.c:1646  */
    { sprintf(tmp,"%c",'A'+(int)(yyvsp[-2].f)); asmPrint(addText(tmp),1); }
#line 1523 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 169 "bison.y" /* yacc.c:1646  */
    { sprintf(tmp,"%c",'A'+(int)(yyvsp[-2].f)); asmPrint(addText(tmp),2); }
#line 1529 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 170 "bison.y" /* yacc.c:1646  */
    { fprintf(fp,"if_done%d:\n",if_id++); }
#line 1535 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 171 "bison.y" /* yacc.c:1646  */
    { loopEnd((yyvsp[-3].l)); }
#line 1541 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 174 "bison.y" /* yacc.c:1646  */
    { (yyval.e) = createExp((yyvsp[0].f),' ',1,NULL,NULL); }
#line 1547 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 175 "bison.y" /* yacc.c:1646  */
    { (yyval.e) = createExp((yyvsp[0].f),' ',2,NULL,NULL); }
#line 1553 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 176 "bison.y" /* yacc.c:1646  */
    { 
                                              (yyvsp[-2].e)->position = 'l';
                                              (yyvsp[0].e)->position = 'r';
                                              (yyval.e) = createExp(0,'+',0,(yyvsp[-2].e),(yyvsp[0].e));
                                             }
#line 1563 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 181 "bison.y" /* yacc.c:1646  */
    { 
                                              (yyvsp[-2].e)->position = 'l';
                                              (yyvsp[0].e)->position = 'r';
                                              (yyval.e) = createExp(0,'-',0,(yyvsp[-2].e),(yyvsp[0].e));
                                             }
#line 1573 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 186 "bison.y" /* yacc.c:1646  */
    { 
                                              (yyvsp[-2].e)->position = 'l';
                                              (yyvsp[0].e)->position = 'r';
                                              (yyval.e) = createExp(0,'*',0,(yyvsp[-2].e),(yyvsp[0].e));
                                            }
#line 1583 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 191 "bison.y" /* yacc.c:1646  */
    { 
                                              (yyvsp[-2].e)->position = 'l';
                                              (yyvsp[0].e)->position = 'r';
                                              (yyval.e) = createExp(0,'/',0,(yyvsp[-2].e),(yyvsp[0].e));
                                            }
#line 1593 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 196 "bison.y" /* yacc.c:1646  */
    { 
                                              (yyvsp[-2].e)->position = 'l';
                                              (yyvsp[0].e)->position = 'r';
                                              (yyval.e) = createExp(0,'%',0,(yyvsp[-2].e),(yyvsp[0].e));
                                            }
#line 1603 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 201 "bison.y" /* yacc.c:1646  */
    { 
                                              (yyvsp[-2].e)->position = 'l';
                                              (yyvsp[0].e)->position = 'r';
                                              (yyval.e) = createExp(0,'^',0,(yyvsp[-2].e),(yyvsp[0].e));
                                            }
#line 1613 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 206 "bison.y" /* yacc.c:1646  */
    { 
                                              (yyvsp[0].e)->position = 'r';
                                              (yyval.e) = createExp(0,'_',0,NULL,(yyvsp[0].e)); 
                                            }
#line 1622 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 210 "bison.y" /* yacc.c:1646  */
    { (yyval.e) = createExp(0,(yyvsp[-1].e),1,NULL,NULL); }
#line 1628 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 213 "bison.y" /* yacc.c:1646  */
    { 
                                              printExp((yyvsp[-2].e));
                                              fprintf(fp,"\tPUSH\trax\n");
                                              printExp((yyvsp[0].e));
                                              fprintf(fp,"\tPOP\trbx\n");
                                              condition(">");
                                            }
#line 1640 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 220 "bison.y" /* yacc.c:1646  */
    { 
                                              printExp((yyvsp[-2].e));
                                              fprintf(fp,"\tPUSH\trax\n");
                                              printExp((yyvsp[0].e));
                                              fprintf(fp,"\tPOP\trbx\n");
                                              condition("<");
                                            }
#line 1652 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 227 "bison.y" /* yacc.c:1646  */
    { 
                                              printExp((yyvsp[-2].e));
                                              fprintf(fp,"\tPUSH\trax\n");
                                              printExp((yyvsp[0].e));
                                              fprintf(fp,"\tPOP\trbx\n");
                                              condition(">=");
                                            }
#line 1664 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 234 "bison.y" /* yacc.c:1646  */
    { 
                                              printExp((yyvsp[-2].e));
                                              fprintf(fp,"\tPUSH\trax\n");
                                              printExp((yyvsp[0].e));
                                              fprintf(fp,"\tPOP\trbx\n");
                                              condition("<=");
                                            }
#line 1676 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 241 "bison.y" /* yacc.c:1646  */
    { 
                                              printExp((yyvsp[-2].e));
                                              fprintf(fp,"\tPUSH\trax\n");
                                              printExp((yyvsp[0].e));
                                              fprintf(fp,"\tPOP\trbx\n");
                                              condition("!=");
                                            }
#line 1688 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 248 "bison.y" /* yacc.c:1646  */
    { 
                                              printExp((yyvsp[-2].e));
                                              fprintf(fp,"\tPUSH\trax\n");
                                              printExp((yyvsp[0].e));
                                              fprintf(fp,"\tPOP\trbx\n");
                                              condition("=");
                                            }
#line 1700 "bison.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 257 "bison.y" /* yacc.c:1646  */
    {
                                              (yyval.l)=createLoop(loop_id++,(int)(yyvsp[0].f));
                                              loopFirst((yyval.l));
                                            }
#line 1709 "bison.tab.c" /* yacc.c:1646  */
    break;


#line 1713 "bison.tab.c" /* yacc.c:1646  */
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
#line 261 "bison.y" /* yacc.c:1906  */


int main(){
  
    init_file();
    
    yyin = fopen("com.txt","r");
    
    yyparse();

    fclose(yyin);
    
}

void yyerror(const char *s)
{
  errors++;
  printf("%s\n",s);
}

int check_divider(double div)
{
  if(div == 0)
  {
    printf("can't divider by zero\n");
    errors = 1;
    return 0;
  }
  return 1;
}

int check_mod(int mod)
{
  if(mod == 0)
  {
    printf("can't mod\n");
    return 0;
  }
  return 1;
}

struct exp * createExp(double value,char operation,int type,struct exp *left,struct exp *right){
  struct exp *exps = malloc(sizeof(struct exp));
  exps->value = value;
  exps->operation = operation;
  exps->type = type;
  exps->position = ' ';
  exps->left = left;
  exps->right = right;
  return exps;
}

void init_file(){
  fp = fopen("file.asm","w");
  fprint("section",".text");
  fprintln("");
  fprint("\tglobal","_start");
  fprintln("");
  fprintln("_start:");
}
void fprint(char *first,char *second){
  fprintf(fp,"%s\t%s",first,second);
}
void fprintln(char *label){
  fprintf(fp,"%s\n",label);
}
void asmPrint(int id,int length){
  fprintf(fp,"\tMOV\trax,1\n");
  fprintf(fp,"\tMOV\trdi,1\n");
  fprintf(fp,"\tMOV\trsi,text%d\n",id);
  fprintf(fp,"\tMOV\trdx,%d\n",length);
  fprintf(fp,"\tsyscall\n\n");
}
void asmLineOnly(){
  fprintf(fp,"\tMOV\trax,1\n");
  fprintf(fp,"\tMOV\trdi,1\n");
  fprintf(fp,"\tMOV\trsi,line\n");
  fprintf(fp,"\tMOV\trdx,1\n");
  fprintf(fp,"\tsyscall\n\n");
}
int addText(char *txt){
  struct text *tmp_str = str;
  int id_return=0;
  if(tmp_str==NULL){
    tmp_str = malloc(sizeof(struct text));
    tmp_str->txt = txt;
    tmp_str->id=id++;
    tmp_str->next=NULL;
    str = tmp_str;
    id_return=tmp_str->id;
  }else {
    while(tmp_str->next!=NULL){
      tmp_str=tmp_str->next;
    }
    tmp_str->next = malloc(sizeof(struct text));
    tmp_str->next->txt = txt;
    tmp_str->next->id=id++;
    id_return=tmp_str->next->id;
  }
  return id_return;
}
void endFile(){
  fprintf(fp,"\tMOV\trax,60\n");
  fprintf(fp,"\tMOV\trdi,0\n");
  fprintf(fp,"\tsyscall\n\n");
  printDec();
  printHex();
  println();
  fprint("section",".data");
  fprintln("");
  fprintf(fp,"\tline\tdb 0x0A\n");
  fprintf(fp,"\tvalue\tTIMES 26 DQ 0\n");
  fprintf(fp,"\tbuffer\tresb\t20\n");
  fprintf(fp,"\tminus\tdb\t\'-\'\n");
  if(str!=NULL){
    while(str->next!=NULL){
      fprintf(fp,"\ttext%d\tdb\t\'%s\',10",str->id,str->txt);
      fprintln("");
      str=str->next;
    }
    fprintf(fp,"\ttext%d\tdb\t\'%s\',10",str->id,str->txt);
    fprintln("");
  }
  fclose(fp);
}
void printExp(struct exp *exps){

  if(exps->left!=NULL)
    printExp(exps->left);
  if(exps->right!=NULL){
    fprintf(fp,"\tPUSH\tr8\n");
    printExp(exps->right);
    fprintf(fp,"\tPOP\tr8\n");
  }

  if(exps->type==0){
    if(exps->operation=='+'){
        if(exps->position=='l'){
          fprintf(fp,"\tADD\tr8,r9\n");
        }else if(exps->position=='r') {
          fprintf(fp,"\tADD\tr9,r8\n");
        }else if(exps->position==' ') {
          fprintf(fp,"\tADD\tr8,r9\n");
          fprintf(fp,"\tMOV\trax,r8\n\n");
        }
    } else if(exps->operation=='-'){ 
        if(exps->position=='l'){
          fprintf(fp,"\tSUB\tr8,r9\n");
        }else if(exps->position=='r'){
          fprintf(fp,"\tSUB\tr9,r8\n");
        }else {
          fprintf(fp,"\tSUB\tr8,r9\n");
          fprintf(fp,"\tMOV\trax,r8\n\n");
        }
    } else if(exps->operation=='*'){ 
        fprintf(fp,"\tMOV\trax,r8\n");
        fprintf(fp,"\tIMUL\tr9\n");
        if(exps->position=='l'){
          fprintf(fp,"\tMOV\tr8,rax\n");
        }else if(exps->position=='r'){
          fprintf(fp,"\tMOV\tr9,rax\n");
        }else {
          fprintf(fp,"\n");
        }
    } else if(exps->operation=='/'){ 
        fprintf(fp,"\tMOV\trax,r8\n");
        fprintf(fp,"\tIDIV\tr9\n");
        if(exps->position=='l'){
          fprintf(fp,"\tMOV\tr8,rax");
        }else if(exps->position=='r'){
          fprintf(fp,"\tMOV\tr9,rax\n");
        }else {
          fprintf(fp,"\n");
        }
    } else if(exps->operation=='%'){
        fprintf(fp,"\tMOV\trax,r8\n");
        fprintf(fp,"\tIDIV\tr9\n");
        if(exps->position=='l'){
          fprintf(fp,"\tMOV\tr8,rdx");
        }else if(exps->position=='r'){
          fprintf(fp,"\tMOV\tr9,rdx\n");
        }else {
          fprintf(fp,"\n");
        }
    } else if(exps->operation=='_'){
        fprintf(fp,"\tNEG\tr9\n");
        if(exps->position=='l'){
          fprintf(fp,"\tMOV\tr8,r9\n");
        }else if(exps->position=='r'){
          //fprintf(fp,"\tMOV\tr9,rdx\n");
        }else {
          fprintf(fp,"\tMOV\trax,r9\n\n");
        }
    }
  } else if(exps->type==1){
    if(exps->position=='l'){
      fprintf(fp,"\tMOV\tr8,%d\n",(int)exps->value);
    }else if(exps->position=='r'){
      fprintf(fp,"\tMOV\tr9,%d\n",(int)exps->value);
    }else if(exps->position==' '){
      fprintf(fp,"\tMOV\trax,%d\n\n",(int)exps->value);
    }
    
  } else if(exps->type==2){
    if(exps->position=='l'){
      fprintf(fp,"\tMOV\tr8,[value+%d]\n",(int)exps->value*8);
    }else if(exps->position=='r'){
      fprintf(fp,"\tMOV\tr9,[value+%d]\n",(int)exps->value*8);
    }else if(exps->position==' '){
      fprintf(fp,"\tMOV\trax,[value+%d]\n",(int)exps->value*8);
    }
  }
}
void addValue(int id){
  fprintf(fp,"\tMOV\t[value+%d],rax\n",id*8);
}
void condition(char *operation){
  fprintf(fp,"\tCMP\trbx,rax\n");
  if(!strcmp(operation,">")){
    fprintf(fp,"\tJLE\tif_done%d\n",if_id);
  }else if(!strcmp(operation,"<")){
    fprintf(fp,"\tJGE\tif_done%d\n",if_id);
  }else if(!strcmp(operation,">=")){
    fprintf(fp,"\tJL\tif_done%d\n",if_id);
  }else if(!strcmp(operation,"!=")){
    fprintf(fp,"\tJE\tif_done%d\n",if_id);
  }else if(!strcmp(operation,"=")){
    fprintf(fp,"\tJNE\tif_done%d\n",if_id);
  }
  //fprintf();
}
struct loop *createLoop(int id,int number){
  struct loop *loops = malloc(sizeof(struct loop));
  loops->id = id;
  loops->number = number;
  return loops;
}
void loopFirst(struct loop* loops){
  fprintf(fp,"\tPUSH\tr10\n");
  fprintf(fp,"\tMOV\tr10,%d\n",loops->number);
  fprintf(fp,"loop%d:\n",loops->id);
}
void loopEnd(struct loop* loops){
  fprintf(fp,"\tDEC\tr10\n");
  fprintf(fp,"\tCMP\tr10,1\n");
  fprintf(fp,"\tJGE\tloop%d\n",loops->id);
  fprintf(fp,"\tPOP\tr10\n");
}
void printDec(){
  fprintf(fp,"printDec:\n");
  fprintf(fp,"\tMOV\tr10,0\n");
  fprintf(fp,"\tMOV\tr11,0\n");
  fprintf(fp,"\tLEA\trdi,[buffer+19]\n");
  fprintf(fp,"\tXOR\trdx,rdx\n");
  fprintf(fp,"\tCMP\trax,0\n");
  fprintf(fp,"\tJGE\tnot_zero\n");
  fprintf(fp,"\tNEG\trax\n");
  fprintf(fp,"\tMOV\tr11,1\n");
  fprintf(fp,"not_zero:\n");
  fprintf(fp,"\tMOV\trbx,10\n");
  fprintf(fp,"\tdiv\trbx\n");
  fprintf(fp,"\tadd\trdx,'0'\n");
  fprintf(fp,"\tmov\tbyte[rdi],dl\n");
  fprintf(fp,"\tdec\trdi\n");
  fprintf(fp,"\tinc\tr10\n");
  fprintf(fp,"\txor\trdx,rdx\n");
  fprintf(fp,"\tcmp\trax,0\n");
  fprintf(fp,"\tjne\tnot_zero\n");
  fprintf(fp,"\tcmp\tr11,1\n");
  fprintf(fp,"\tJNE\tplus\n");
  fprintf(fp,"\tPUSH\trax\n");
  fprintf(fp,"\tPUSH\trdi\n");
  fprintf(fp,"\tPUSH\trdx\n");
  fprintf(fp,"\tMOV\trax,1\n");
  fprintf(fp,"\tMOV\trdi,1\n");
  fprintf(fp,"\tMOV\trsi,minus\n");
  fprintf(fp,"\tMOV\trdx,1\n");
  fprintf(fp,"\tsyscall\n");
  fprintf(fp,"\tPOP\trax\n");
  fprintf(fp,"\tPOP\trdi\n");
  fprintf(fp,"\tPOP\trdx\n");
  fprintf(fp,"plus:\n");
  fprintf(fp,"\tINC\trdi\n");
  fprintf(fp,"\tMOV\trbx,rdi\n");
  fprintf(fp,"\tMOV\trax,1\n");
  fprintf(fp,"\tMOV\trdi,1\n");
  fprintf(fp,"\tMOV\trsi,rbx\n");
  fprintf(fp,"\tMOV\trdx,r10\n");
  fprintf(fp,"\tsyscall\n");
  fprintf(fp,"\tret\n\n");
}
void printHex(){
  fprintf(fp,"printHex:\n");
  fprintf(fp,"\tMOV\tr10,0\n");
  fprintf(fp,"\tMOV\tr11,0\n");
  fprintf(fp,"\tLEA\trdi,[buffer+19]\n");
  fprintf(fp,"\tXOR\trdx,rdx\n");
  fprintf(fp,"\tCMP\trax,0\n");
  fprintf(fp,"\tJGE\tnot_zeroHex\n");
  fprintf(fp,"\tNEG\trax\n");
  fprintf(fp,"\tMOV\tr11,1\n");
  fprintf(fp,"not_zeroHex:\n");
  fprintf(fp,"\tMOV\trbx,16\n");
  fprintf(fp,"\tdiv\trbx\n");
  fprintf(fp,"\tCALL\tconvert\n");
  fprintf(fp,"\tmov\tbyte[rdi],dl\n");
  fprintf(fp,"\tdec\trdi\n");
  fprintf(fp,"\tinc\tr10\n");
  fprintf(fp,"\txor\trdx,rdx\n");
  fprintf(fp,"\tcmp\trax,0\n");
  fprintf(fp,"\tjne\tnot_zeroHex\n");
  fprintf(fp,"\tcmp\tr11,1\n");
  fprintf(fp,"\tJNE\tplusHex\n");
  fprintf(fp,"\tPUSH\trax\n");
  fprintf(fp,"\tPUSH\trdi\n");
  fprintf(fp,"\tPUSH\trdx\n");
  fprintf(fp,"\tMOV\trax,1\n");
  fprintf(fp,"\tMOV\trdi,1\n");
  fprintf(fp,"\tMOV\trsi,minus\n");
  fprintf(fp,"\tMOV\trdx,1\n");
  fprintf(fp,"\tsyscall\n");
  fprintf(fp,"\tPOP\trax\n");
  fprintf(fp,"\tPOP\trdi\n");
  fprintf(fp,"\tPOP\trdx\n");
  fprintf(fp,"plusHex:\n");
  fprintf(fp,"\tINC\trdi\n");
  fprintf(fp,"\tMOV\trbx,rdi\n");
  fprintf(fp,"\tMOV\trax,1\n");
  fprintf(fp,"\tMOV\trdi,1\n");
  fprintf(fp,"\tMOV\trsi,rbx\n");
  fprintf(fp,"\tMOV\trdx,r10\n");
  fprintf(fp,"\tsyscall\n");
  fprintf(fp,"\tret\n\n");
  fprintf(fp,"convert:\n");
  fprintf(fp,"\tCMP\trdx,10\n");
  fprintf(fp,"\tJL\tconvert_done\n");
  fprintf(fp,"\tADD\trdx,0x7\n");
  fprintf(fp,"convert_done:\n");
  fprintf(fp,"\tADD\trdx,0x30\n");
  fprintf(fp,"\tret\n\n");
}
void pushAll(){
  fprintf(fp,"\tPUSH\tr10\n");
  fprintf(fp,"\tPUSH\tr11\n");
  fprintf(fp,"\tPUSH\trdi\n");
  fprintf(fp,"\tPUSH\trdx\n");
  fprintf(fp,"\tPUSH\trax\n");
  fprintf(fp,"\tPUSH\trbx\n\n");
}
void popAll(){
  fprintf(fp,"\tPOP\trbx\n");
  fprintf(fp,"\tPOP\trax\n");
  fprintf(fp,"\tPOP\trdx\n");
  fprintf(fp,"\tPOP\trdi\n");
  fprintf(fp,"\tPOP\tr11\n");
  fprintf(fp,"\tPOP\tr10\n\n");
}
void println(){
  fprintf(fp,"printLineOnly:\n");
  fprintf(fp,"\tMOV\trax,1\n");
  fprintf(fp,"\tMOV\trdi,1\n");
  fprintf(fp,"\tMOV\trsi,line\n");
  fprintf(fp,"\tMOV\trdx,1\n");
  fprintf(fp,"\tsyscall\n");
  fprintf(fp,"\tret\n\n");
}
/* 
print:
    mov rax,1
    mov rdi,1
    mov rsi,text
    mov rdx,3
    syscall
    
    MOV	rax,60
    MOV	rdi,0
    syscall

*/
