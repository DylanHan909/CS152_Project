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
#line 2 "miniL.y" /* yacc.c:339  */

 #define YY_NO_UNPUT
 #include <stdio.h>
 #include <stdlib.h>

 #include <map>
 #include <set>
 #include <string.h>
 #include <iostream>
 int tempCount = 0;
 int labelCount = 0;
 extern char* yytext;
 std::map<std::string, std::string> tempVars;
 std::map<std::string, int> arrSize;
 bool mainFunc = false;
 std::set<std::string> funcs;
 std::set<std::string> reserved = {"FUNCTION", "BEGIN_PARAMS", "END_PARAMS", "BEGIN_LOCALS", "END_LOCALS", "BEGIN_BODY", "END_BODY", "INTEGER",
    "ARRAY", "OF", "IF", "THEN", "ENDIF", "ELSE", "WHILE", "DO", "FOREACH", "IN", "BEGINLOOP", "ENDLOOP", "CONTINUE", "READ", "WRITE", "AND", "OR", 
    "NOT", "TRUE", "FALSE", "RETURN", "SUB", "ADD", "MULT", "DIV", "MOD", "EQ", "NEQ", "LT", "GT", "LTE", "GTE", "L_PAREN", "R_PAREN", "L_SQUARE_BRACKET",
    "R_SQUARE_BRACKET", "COLON", "SEMICOLON", "COMMA", "ASSIGN", "function", "Ident", "beginparams", "endparams", "beginlocals", "endlocals", "integer", 
    "beginbody", "endbody", "beginloop", "endloop", "if", "endif", "foreach", "continue", "while", "else", "read", "do", "write"};
 int yylex();
 std::string newTemp();
 std::string newLabel();

 void yyerror(const char *msg);
 extern int currLine;
 extern int currPos;
 FILE * yyin;

#line 97 "miniL.tab.c" /* yacc.c:339  */

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
# define YYERROR_VERBOSE 1
#endif

/* In a future release of Bison, this section will be replaced
   by #include "miniL.tab.h".  */
#ifndef YY_YY_MINIL_TAB_H_INCLUDED
# define YY_YY_MINIL_TAB_H_INCLUDED
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
    FUNCTION = 258,
    BEGIN_PARAMS = 259,
    END_PARAMS = 260,
    BEGIN_LOCALS = 261,
    END_LOCALS = 262,
    BEGIN_BODY = 263,
    END_BODY = 264,
    INTEGER = 265,
    ARRAY = 266,
    ENUM = 267,
    OF = 268,
    IF = 269,
    THEN = 270,
    ENDIF = 271,
    ELSE = 272,
    FOR = 273,
    WHILE = 274,
    DO = 275,
    BEGINLOOP = 276,
    ENDLOOP = 277,
    CONTINUE = 278,
    READ = 279,
    WRITE = 280,
    AND = 281,
    OR = 282,
    NOT = 283,
    TRUE = 284,
    FALSE = 285,
    RETURN = 286,
    SUB = 287,
    ADD = 288,
    MULT = 289,
    DIV = 290,
    MOD = 291,
    EQ = 292,
    NEQ = 293,
    LT = 294,
    GT = 295,
    LTE = 296,
    GTE = 297,
    IDENT = 298,
    NUMBER = 299,
    SEMICOLON = 300,
    COLON = 301,
    COMMA = 302,
    L_PAREN = 303,
    R_PAREN = 304,
    L_SQUARE_BRACKET = 305,
    R_SQUARE_BRACKET = 306,
    ASSIGN = 307,
    UMINUS = 308
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 33 "miniL.y" /* yacc.c:355  */

  char * iVal;
  int nVal;

  struct S{
    char* code;
  } statement;

  struct E{
    char* place;
    char* code;
    bool isArr;
  } expression;

#line 206 "miniL.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif

/* Location type.  */
#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE YYLTYPE;
struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
};
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif


extern YYSTYPE yylval;
extern YYLTYPE yylloc;
int yyparse (void);

#endif /* !YY_YY_MINIL_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 237 "miniL.tab.c" /* yacc.c:358  */

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
         || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
             && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE) + sizeof (YYLTYPE)) \
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
#define YYFINAL  6
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   176

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  54
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  22
/* YYNRULES -- Number of rules.  */
#define YYNRULES  65
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  133

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   308

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
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    79,    79,    79,    82,    82,    84,   109,   109,   111,
     113,   113,   113,   113,   115,   115,   118,   119,   120,   121,
     122,   123,   124,   125,   126,   128,   128,   130,   130,   133,
     133,   136,   136,   139,   139,   141,   142,   143,   144,   147,
     147,   147,   147,   147,   147,   150,   150,   150,   152,   152,
     152,   155,   155,   155,   155,   158,   158,   158,   159,   159,
     159,   160,   163,   163,   165,   165
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 1
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "FUNCTION", "BEGIN_PARAMS", "END_PARAMS",
  "BEGIN_LOCALS", "END_LOCALS", "BEGIN_BODY", "END_BODY", "INTEGER",
  "ARRAY", "ENUM", "OF", "IF", "THEN", "ENDIF", "ELSE", "FOR", "WHILE",
  "DO", "BEGINLOOP", "ENDLOOP", "CONTINUE", "READ", "WRITE", "AND", "OR",
  "NOT", "TRUE", "FALSE", "RETURN", "\"-\"", "\"+\"", "\"*\"", "\"/\"",
  "\"%\"", "\"=\"", "\"!=\"", "\"<\"", "\">\"", "\"<=\"", "\">=\"",
  "IDENT", "NUMBER", "\";\"", "\":\"", "\",\"", "\"(\"", "\")\"", "\"[\"",
  "\"]\"", "\":=\"", "UMINUS", "$accept", "PROGRAM", "FUNCTION_LOOP",
  "FUNCTIONS", "IDENTIFIER_LOOP", "Ident", "DECLARATION",
  "DECLARATION_LOOP", "STATEMENT", "ELSE_BRANCH", "STATEMENT_LOOP",
  "BOOL-EXPR", "RELATION-AND-EXPR", "RELATION-EXPR", "RELATION_EXPR_BODY",
  "COMP", "EXPRESSION", "EXPRESSION_LOOP", "MULTIPLICATIVE_EXPR", "TERM",
  "VAR_LOOP", "VAR", YY_NULLPTR
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
     305,   306,   307,   308
};
# endif

#define YYPACT_NINF -59

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-59)))

#define YYTABLE_NINF -29

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      19,   -39,    28,   -59,    19,    -7,   -59,   -59,    38,    35,
     -59,   -59,     4,     0,     8,    50,    59,    15,    22,    55,
     -59,    12,    24,   -59,   -59,     5,    39,    15,    92,    47,
      54,    93,    96,   -59,   113,   105,   -59,    52,    52,    97,
     -59,    15,    15,   -13,    67,    77,   119,    78,   -59,    91,
     -59,   -59,     1,   -59,    52,    29,   114,   115,   117,   -59,
     121,    60,    51,   -59,   120,   113,   -59,   104,   -59,   -13,
     -59,   -13,    88,   -59,   -13,   -59,   -59,   -13,   -59,   103,
     108,   -13,   113,    52,    52,   -59,   -59,   -59,   -59,   -59,
     -59,   -13,   -13,   -13,   -13,   -13,   -13,   113,   118,    15,
     106,   102,   -59,   -59,   116,   -59,   -59,   107,   122,   147,
     -59,   -59,   -59,   -59,   -59,   -59,   -59,   -59,   144,   148,
     -59,   -59,   -59,   -13,   -59,   113,   152,   -59,    52,   -59,
     -59,   -59,   -59
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       3,     0,     0,     2,     5,     0,     1,     4,     0,     0,
      13,     9,     0,     7,     0,     0,     0,     0,     0,     0,
      11,     0,     0,     8,    14,     0,     0,     0,     0,     0,
       0,     0,     0,    12,     0,     0,    24,     0,     0,     0,
      22,     0,     0,     0,    64,     0,     0,     0,    10,     0,
      36,    37,     0,    56,     0,    64,     0,    29,    31,    34,
       0,    45,    51,    55,     0,     0,    20,    62,    21,     0,
      23,     0,     0,     6,     0,    33,    59,     0,    58,     0,
       0,    50,     0,     0,     0,    39,    40,    41,    42,    43,
      44,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    27,    16,     0,    38,    57,    48,     0,    26,
      30,    32,    35,    47,    46,    52,    53,    54,     0,     0,
      63,    65,    60,    50,    61,     0,     0,    18,     0,    49,
      25,    17,    19
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -59,   -59,   165,   -59,   -12,    -9,   -59,    -5,   -59,   -59,
     -58,   -37,    86,   -59,   123,   -59,   -17,    53,    30,   -59,
     -40,   -31
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,     3,     4,    12,    55,    14,    15,    45,   126,
      46,    56,    57,    58,    59,    91,    60,   108,    61,    62,
      66,    63
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      13,    64,    68,    47,     5,    23,    10,    98,    13,    13,
      67,    67,   -15,    24,   102,    30,    13,    79,    13,    52,
      28,    78,     1,    10,   109,    44,    70,   -15,     6,   -15,
      11,    53,    44,    44,    47,    69,    10,    80,     8,   118,
     -15,    47,     9,    44,    11,    76,   110,    17,    11,    77,
      16,    47,   100,    18,   101,    19,    44,   103,    11,   120,
     104,    25,    26,    44,   107,    11,    47,   130,    67,    20,
      21,    22,    27,    44,   112,   113,   114,    81,    11,    71,
      49,    50,    51,    29,    52,    94,    95,    96,    44,    36,
      44,   132,    92,    93,    47,    11,    53,   -28,    32,    31,
      54,    34,    37,    33,   -28,   -28,   107,    38,    39,    35,
     -28,    40,    41,    42,    36,    48,    44,    71,    65,    43,
      50,    51,    72,    52,   115,   116,   117,    37,    73,    82,
      74,    11,    38,    39,    11,    53,    40,    41,    42,    54,
     119,    97,    83,    84,    43,    85,    86,    87,    88,    89,
      90,    99,   105,   121,   123,   106,    11,   106,    85,    86,
      87,    88,    89,    90,   125,   122,   127,   128,   131,     7,
     111,   124,    75,     0,     0,     0,   129
};

static const yytype_int16 yycheck[] =
{
       9,    38,    42,    34,    43,    17,     1,    65,    17,    18,
      41,    42,     7,    18,    72,    27,    25,    54,    27,    32,
      25,    52,     3,     1,    82,    34,    43,     5,     0,     7,
      43,    44,    41,    42,    65,    48,     1,    54,    45,    97,
       5,    72,     4,    52,    43,    44,    83,    47,    43,    48,
      46,    82,    69,    45,    71,     5,    65,    74,    43,    99,
      77,     6,    50,    72,    81,    43,    97,   125,    99,    10,
      11,    12,    48,    82,    91,    92,    93,    48,    43,    50,
      28,    29,    30,    44,    32,    34,    35,    36,    97,     1,
      99,   128,    32,    33,   125,    43,    44,     9,    51,     7,
      48,     8,    14,    49,    16,    17,   123,    19,    20,    13,
      22,    23,    24,    25,     1,    10,   125,    50,    21,    31,
      29,    30,    45,    32,    94,    95,    96,    14,     9,    15,
      52,    43,    19,    20,    43,    44,    23,    24,    25,    48,
      22,    21,    27,    26,    31,    37,    38,    39,    40,    41,
      42,    47,    49,    51,    47,    49,    43,    49,    37,    38,
      39,    40,    41,    42,    17,    49,    22,    19,    16,     4,
      84,    49,    49,    -1,    -1,    -1,   123
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,    55,    56,    57,    43,     0,    56,    45,     4,
       1,    43,    58,    59,    60,    61,    46,    47,    45,     5,
      10,    11,    12,    58,    61,     6,    50,    48,    61,    44,
      58,     7,    51,    49,     8,    13,     1,    14,    19,    20,
      23,    24,    25,    31,    59,    62,    64,    75,    10,    28,
      29,    30,    32,    44,    48,    59,    65,    66,    67,    68,
      70,    72,    73,    75,    65,    21,    74,    75,    74,    48,
      70,    50,    45,     9,    52,    68,    44,    48,    75,    65,
      70,    48,    15,    27,    26,    37,    38,    39,    40,    41,
      42,    69,    32,    33,    34,    35,    36,    21,    64,    47,
      70,    70,    64,    70,    70,    49,    49,    70,    71,    64,
      65,    66,    70,    70,    70,    72,    72,    72,    64,    22,
      74,    51,    49,    47,    49,    17,    63,    22,    19,    71,
      64,    16,    65
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    54,    55,    55,    56,    56,    57,    58,    58,    59,
      60,    60,    60,    60,    61,    61,    62,    62,    62,    62,
      62,    62,    62,    62,    62,    63,    63,    64,    64,    65,
      65,    66,    66,    67,    67,    68,    68,    68,    68,    69,
      69,    69,    69,    69,    69,    70,    70,    70,    71,    71,
      71,    72,    72,    72,    72,    73,    73,    73,    73,    73,
      73,    73,    74,    74,    75,    75
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     0,     2,     0,    12,     1,     3,     1,
       8,     3,     6,     1,     3,     0,     3,     6,     5,     6,
       2,     2,     1,     2,     1,     2,     0,     3,     2,     1,
       3,     1,     3,     2,     1,     3,     1,     1,     3,     1,
       1,     1,     1,     1,     1,     1,     3,     3,     1,     3,
       0,     1,     3,     3,     3,     1,     1,     3,     2,     2,
       4,     4,     1,     3,     1,     4
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

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

YY_ATTRIBUTE_UNUSED
static unsigned
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  unsigned res = 0;
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

#  define YY_LOCATION_PRINT(File, Loc)          \
  yy_location_print_ (File, &(Loc))

# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value, Location); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  YYUSE (yylocationp);
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
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  YY_LOCATION_PRINT (yyoutput, *yylocationp);
  YYFPRINTF (yyoutput, ": ");
  yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp);
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule)
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
                       , &(yylsp[(yyi + 1) - (yynrhs)])                       );
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
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);
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
/* Location data for the lookahead symbol.  */
YYLTYPE yylloc
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;
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
       'yyls': related to locations.

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

    /* The location stack.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls;
    YYLTYPE *yylsp;

    /* The locations where the error started and ended.  */
    YYLTYPE yyerror_range[3];

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yylsp = yyls = yylsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  yylsp[0] = yylloc;
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
        YYLTYPE *yyls1 = yyls;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yyls1, yysize * sizeof (*yylsp),
                    &yystacksize);

        yyls = yyls1;
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
        YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

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
  *++yylsp = yylloc;
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

  /* Default location.  */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 79 "miniL.y" /* yacc.c:1646  */
    {printf("PROGRAM -> FUNCTION_LOOP\n");}
#line 1513 "miniL.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 79 "miniL.y" /* yacc.c:1646  */
    {printf("PROGRAM -> ε\n");}
#line 1519 "miniL.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 82 "miniL.y" /* yacc.c:1646  */
    {printf("FUNCTION_LOOP -> FUNCTIONS FUNCTION_LOOP\n");}
#line 1525 "miniL.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 82 "miniL.y" /* yacc.c:1646  */
    {printf("FUNCTION_LOOP -> ε\n");}
#line 1531 "miniL.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 85 "miniL.y" /* yacc.c:1646  */
    {
        std::string temp = "func";


        std::cout << temp;
        /* func fibonacci

        */
        /*
          function fibonacci;
          beginparams
            k : integer;
          endparams
          beginlocals
          endlocals
          beginbody
            if (k <= 1) then return 1; endif;
            return fibonacci(k - 1) + fibonacci(k - 2);
          endbody
        */
        
      }
#line 1558 "miniL.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 109 "miniL.y" /* yacc.c:1646  */
    {printf("IDENTIFIER_LOOP -> IDENT\n");}
#line 1564 "miniL.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 109 "miniL.y" /* yacc.c:1646  */
    {printf("IDENTIFIER_LOOP -> IDENT COMMA IDENTIFIER_LOOP\n");}
#line 1570 "miniL.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 111 "miniL.y" /* yacc.c:1646  */
    {printf("Ident -> IDENT %s\n", (yyvsp[0].iVal));}
#line 1576 "miniL.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 113 "miniL.y" /* yacc.c:1646  */
    {printf("DECLARATION -> IDENTIFIER_LOOP COLON ARRAY L_SQUARE_BRACKET NUMBER R_SQUARE_BRACKET OF INTEGER\n");}
#line 1582 "miniL.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 113 "miniL.y" /* yacc.c:1646  */
    {printf("DECLARATION -> IDENTIFIER_LOOP COLON INTEGER\n");}
#line 1588 "miniL.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 113 "miniL.y" /* yacc.c:1646  */
    {printf("DECLARATION -> IDENTIFIER_LOOP COLON ENUM L_PAREN IDENTIFIER_LOOP R_PAREN\n");}
#line 1594 "miniL.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 113 "miniL.y" /* yacc.c:1646  */
    {yyerror("invalid declaration"); yyerrok; yyclearin; }
#line 1600 "miniL.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 115 "miniL.y" /* yacc.c:1646  */
    {printf("DECLARATION_LOOP -> DECLARATION SEMICOLON DECLARATION_LOOP\n");}
#line 1606 "miniL.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 115 "miniL.y" /* yacc.c:1646  */
    {printf("DECLARATION_LOOP -> ε\n");}
#line 1612 "miniL.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 118 "miniL.y" /* yacc.c:1646  */
    {printf("STATEMENT -> VAR ASSIGN EXPRESSION\n");}
#line 1618 "miniL.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 119 "miniL.y" /* yacc.c:1646  */
    {printf("STATEMENT -> IF BOOL-EXPR THEN STATEMENT_LOOP ELSE_BRANCH ENDIF\n");}
#line 1624 "miniL.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 120 "miniL.y" /* yacc.c:1646  */
    {printf("STATEMENT -> WHILE BOOL-EXPR BEGINLOOP STATEMENT_LOOP ENDLOOP\n");}
#line 1630 "miniL.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 121 "miniL.y" /* yacc.c:1646  */
    {printf("\n");}
#line 1636 "miniL.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 122 "miniL.y" /* yacc.c:1646  */
    {printf("STATEMENT -> READ VAR_LOOP\n");}
#line 1642 "miniL.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 123 "miniL.y" /* yacc.c:1646  */
    {printf("STATEMENT -> WRITE VAR_LOOP\n");}
#line 1648 "miniL.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 124 "miniL.y" /* yacc.c:1646  */
    {printf("STATEMENT -> CONTINUE\n");}
#line 1654 "miniL.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 125 "miniL.y" /* yacc.c:1646  */
    {printf("STATEMENT -> RETURN EXPRESSION\n");}
#line 1660 "miniL.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 126 "miniL.y" /* yacc.c:1646  */
    {yyerror("invalid statement"); yyerrok; yyclearin; }
#line 1666 "miniL.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 128 "miniL.y" /* yacc.c:1646  */
    {printf("ELSE_BRANCH -> ELSE STATEMENT_LOOP\n");}
#line 1672 "miniL.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 128 "miniL.y" /* yacc.c:1646  */
    {printf("ELSE_BRANCH -> ε\n");}
#line 1678 "miniL.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 130 "miniL.y" /* yacc.c:1646  */
    {printf("STATEMENT_LOOP -> STATEMENT SEMICOLON STATEMENT_LOOP\n");}
#line 1684 "miniL.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 130 "miniL.y" /* yacc.c:1646  */
    {printf("STATEMENT_LOOP -> STATEMENT SEMICOLON\n");}
#line 1690 "miniL.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 133 "miniL.y" /* yacc.c:1646  */
    {printf("BOOL-EXPR -> RELATION-AND-EXPR\n");}
#line 1696 "miniL.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 133 "miniL.y" /* yacc.c:1646  */
    {printf("BOOL-EXPR -> RELATION-AND-EXPR OR BOOL-EXPR\n");}
#line 1702 "miniL.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 136 "miniL.y" /* yacc.c:1646  */
    {printf("RELATION-AND-EXPR -> RELATION-EXPR\n");}
#line 1708 "miniL.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 136 "miniL.y" /* yacc.c:1646  */
    {printf("RELATION-AND-EXPR -> RELATION-EXPR AND RELATION-AND-EXPR\n");}
#line 1714 "miniL.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 139 "miniL.y" /* yacc.c:1646  */
    {printf("RELATION-EXPR -> NOT RELATION_EXPR_BODY\n");}
#line 1720 "miniL.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 139 "miniL.y" /* yacc.c:1646  */
    {printf("RELATION-EXPR -> RELATION_EXPR_BODY\n");}
#line 1726 "miniL.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 141 "miniL.y" /* yacc.c:1646  */
    {printf("RELATION_EXPR_BODY -> EXPRESSION COMP EXPRESSION\n");}
#line 1732 "miniL.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 142 "miniL.y" /* yacc.c:1646  */
    {printf("RELATION_EXPR_BODY -> TRUE\n");}
#line 1738 "miniL.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 143 "miniL.y" /* yacc.c:1646  */
    {printf("RELATION_EXPR_BODY -> FALSE\n");}
#line 1744 "miniL.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 144 "miniL.y" /* yacc.c:1646  */
    {printf("RELATION_EXPR_BODY -> L_PARN BOOL-EXPR R_PAREN\n");}
#line 1750 "miniL.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 147 "miniL.y" /* yacc.c:1646  */
    {printf("COMP -> EQ\n");}
#line 1756 "miniL.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 147 "miniL.y" /* yacc.c:1646  */
    {printf("COMP -> NEQ\n");}
#line 1762 "miniL.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 147 "miniL.y" /* yacc.c:1646  */
    {printf("COMP -> LT\n");}
#line 1768 "miniL.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 147 "miniL.y" /* yacc.c:1646  */
    {printf("COMP -> GT\n");}
#line 1774 "miniL.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 147 "miniL.y" /* yacc.c:1646  */
    {printf("COMP -> LTE\n");}
#line 1780 "miniL.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 147 "miniL.y" /* yacc.c:1646  */
    {printf("COMP -> GTE\n");}
#line 1786 "miniL.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 150 "miniL.y" /* yacc.c:1646  */
    {printf("EXPRESSION -> MULTIPLICATIVE_EXPR\n");}
#line 1792 "miniL.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 150 "miniL.y" /* yacc.c:1646  */
    {printf("EXPRESSION -> MULTIPLICATIVE_EXPR ADD EXPRESSION\n");}
#line 1798 "miniL.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 150 "miniL.y" /* yacc.c:1646  */
    {printf("EXPRESSION -> MULTIPLICATIVE_EXPR SUB EXPRESSION\n");}
#line 1804 "miniL.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 152 "miniL.y" /* yacc.c:1646  */
    {printf("EXPRESSION_LOOP -> EXPRESSION\n");}
#line 1810 "miniL.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 152 "miniL.y" /* yacc.c:1646  */
    {printf("EXPRESSION_LOOP -> EXPRESSION COMMA EXPRESSION_LOOP\n");}
#line 1816 "miniL.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 152 "miniL.y" /* yacc.c:1646  */
    {printf("EXPRESSION_LOOP -> ε\n");}
#line 1822 "miniL.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 155 "miniL.y" /* yacc.c:1646  */
    {printf("MULTIPLICATIVE_EXPR -> TERM\n");}
#line 1828 "miniL.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 155 "miniL.y" /* yacc.c:1646  */
    {printf("MULTIPLICATIVE_EXPR -> TERM MULT MULTIPLICATIVE_EXPR\n");}
#line 1834 "miniL.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 155 "miniL.y" /* yacc.c:1646  */
    {printf("MULTIPLICATIVE_EXPR -> TERM DIV MULTIPLICATIVE_EXPR\n");}
#line 1840 "miniL.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 155 "miniL.y" /* yacc.c:1646  */
    {printf("MULTIPLICATIVE_EXPR -> TERM MOD MULTIPLICATIVE_EXPR\n");}
#line 1846 "miniL.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 158 "miniL.y" /* yacc.c:1646  */
    {printf("TERM -> VAR\n");}
#line 1852 "miniL.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 158 "miniL.y" /* yacc.c:1646  */
    {printf("TERM -> NUMBER %d\n", (yyvsp[0].nVal));}
#line 1858 "miniL.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 158 "miniL.y" /* yacc.c:1646  */
    {printf("TERM -> L_PAREN EXPRESSION R_PAREN\n");}
#line 1864 "miniL.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 159 "miniL.y" /* yacc.c:1646  */
    {printf("TERM -> SUB VAR %PREC UMINUS\n");}
#line 1870 "miniL.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 159 "miniL.y" /* yacc.c:1646  */
    {printf("TERM -> SUB NUMBER %PREC UMINUS %d\n", (yyvsp[0].nVal));}
#line 1876 "miniL.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 159 "miniL.y" /* yacc.c:1646  */
    {printf("TERM -> SUB L_PAREN EXPRESSION R_PAREN %PREC UMINUS\n");}
#line 1882 "miniL.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 160 "miniL.y" /* yacc.c:1646  */
    {printf("TERM -> IDENT L_PAREN EXPRESSION_LOOP R_PAREN\n");}
#line 1888 "miniL.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 163 "miniL.y" /* yacc.c:1646  */
    {printf("VAR_LOOP -> VAR\n");}
#line 1894 "miniL.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 163 "miniL.y" /* yacc.c:1646  */
    {printf("VAR_LOOP -> VAR COMMA VAR_LOOP\n");}
#line 1900 "miniL.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 165 "miniL.y" /* yacc.c:1646  */
    {printf("VAR -> IDENT\n");}
#line 1906 "miniL.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 165 "miniL.y" /* yacc.c:1646  */
    {printf("VAR -> IDENT L_SQUARE_BRACKET EXPRESSION R_SQUARE_BRACKET\n");}
#line 1912 "miniL.tab.c" /* yacc.c:1646  */
    break;


#line 1916 "miniL.tab.c" /* yacc.c:1646  */
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
  *++yylsp = yyloc;

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

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  yyerror_range[1] = yylsp[1-yylen];
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

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  /* Using YYLLOC is tempting, but would change the location of
     the lookahead.  YYLOC is available though.  */
  YYLLOC_DEFAULT (yyloc, yyerror_range, 2);
  *++yylsp = yyloc;

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
                  yytoken, &yylval, &yylloc);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp, yylsp);
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
#line 167 "miniL.y" /* yacc.c:1906  */
 


void yyerror(const char *msg) {
   printf("** Line %d, position %d: %s\n", currLine, currPos, msg);
}
