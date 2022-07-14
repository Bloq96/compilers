/* A Bison parser, made by GNU Bison 3.5.1.  */

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

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.5.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1


/* Substitute the variable and function names.  */
#define yyparse         cool_yyparse
#define yylex           cool_yylex
#define yyerror         cool_yyerror
#define yydebug         cool_yydebug
#define yynerrs         cool_yynerrs
#define yylval          cool_yylval
#define yychar          cool_yychar

/* First part of user prologue.  */
#line 6 "cool.y"

#include <iostream>
#include "cool-tree.h"
#include "stringtab.h"
#include "utilities.h"
#include <vector>

extern char *curr_filename;

void yyerror(char *s);        /*  defined below; called for each parse error */
extern int yylex();           /*  the entry point to the lexer  */
extern int node_lineno;

typedef struct {
  Symbol id;
  Symbol type;
  Expression init;
} Let_structure;

typedef std::vector<Let_structure> ListLet;


Expression letConstruct(ListLet* list, Let_structure letD, Expression expr){
  Expression aux = let(letD.id, letD.type, letD.init, expr);
  if(list->size() == 0) {
    return aux;
  }
  for(int i = list->size() - 1; 0 < i  ; i--){
    aux = let((*list)[i].id, (*list)[i].type, (*list)[i].init, aux);
  }
  return let((*list)[0].id, (*list)[0].type, (*list)[0].init, aux);
}


/************************************************************************/
/*                DONT CHANGE ANYTHING IN THIS SECTION                  */

Program ast_root;	      /* the result of the parse  */
Classes parse_results;        /* for use in semantic analysis */
int omerrs = 0;               /* number of errors in lexing and parsing */


#line 120 "cool.tab.c"

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

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_COOL_YY_COOL_TAB_H_INCLUDED
# define YY_COOL_YY_COOL_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif
#if YYDEBUG
extern int cool_yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    CLASS = 258,
    ELSE = 259,
    FI = 260,
    IF = 261,
    IN = 262,
    INHERITS = 263,
    LET = 264,
    LOOP = 265,
    POOL = 266,
    THEN = 267,
    WHILE = 268,
    CASE = 269,
    ESAC = 270,
    OF = 271,
    DARROW = 272,
    NEW = 273,
    ISVOID = 274,
    STR_CONST = 275,
    INT_CONST = 276,
    BOOL_CONST = 277,
    TYPEID = 278,
    OBJECTID = 279,
    ASSIGN = 280,
    NOT = 281,
    LE = 282,
    ERROR = 283,
    LETPREC = 285,
    CALLPREC = 286
  };
#endif
/* Tokens.  */
#define CLASS 258
#define ELSE 259
#define FI 260
#define IF 261
#define IN 262
#define INHERITS 263
#define LET 264
#define LOOP 265
#define POOL 266
#define THEN 267
#define WHILE 268
#define CASE 269
#define ESAC 270
#define OF 271
#define DARROW 272
#define NEW 273
#define ISVOID 274
#define STR_CONST 275
#define INT_CONST 276
#define BOOL_CONST 277
#define TYPEID 278
#define OBJECTID 279
#define ASSIGN 280
#define NOT 281
#define LE 282
#define ERROR 283
#define LETPREC 285
#define CALLPREC 286

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 50 "cool.y"

  Boolean boolean;
  Symbol symbol;
  Program program;
  Class_ class_;
  Classes classes;
  Feature feature;
  Features features;
  Formal formal;
  Formals formals;
  Case case_;
  Cases cases;
  Expression expression;
  Expressions expressions;
  char *error_msg;
  Let_structure letS;
  ListLet * listLet;

#line 251 "cool.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE cool_yylval;

int cool_yyparse (void);

#endif /* !YY_COOL_YY_COOL_TAB_H_INCLUDED  */



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
typedef yytype_uint8 yy_state_t;

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
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
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
#define YYFINAL  8
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   531

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  47
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  15
/* YYNRULES -- Number of rules.  */
#define YYNRULES  66
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  178

#define YYUNDEFTOK  2
#define YYMAXUTOK   286


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      31,    44,    36,    34,    46,    35,    40,    37,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    45,    41,
      32,    33,     2,     2,    39,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    42,     2,    43,    38,     2,     2,     2,
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
      25,    26,    27,    28,     2,    29,    30
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   128,   128,   131,   133,   135,   139,   142,   147,   148,
     150,   153,   155,   157,   159,   161,   162,   163,   164,   167,
     168,   172,   176,   178,   180,   183,   184,   187,   191,   196,
     201,   204,   207,   209,   212,   214,   218,   220,   222,   224,
     226,   228,   231,   234,   236,   238,   240,   242,   244,   246,
     248,   250,   252,   254,   256,   258,   260,   262,   264,   266,
     268,   270,   272,   274,   276,   278,   279
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "CLASS", "ELSE", "FI", "IF", "IN",
  "INHERITS", "LET", "LOOP", "POOL", "THEN", "WHILE", "CASE", "ESAC", "OF",
  "DARROW", "NEW", "ISVOID", "STR_CONST", "INT_CONST", "BOOL_CONST",
  "TYPEID", "OBJECTID", "ASSIGN", "NOT", "LE", "ERROR", "LETPREC",
  "CALLPREC", "'('", "'<'", "'='", "'+'", "'-'", "'*'", "'/'", "'~'",
  "'@'", "'.'", "';'", "'{'", "'}'", "')'", "':'", "','", "$accept",
  "program", "class_list", "class", "dummy_feature_list", "feature",
  "formal_list", "formal", "expr_list", "dummy_expr_list", "let_declare",
  "let_list", "case_match", "case_match_list", "expr", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   284,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   285,
     286,    40,    60,    61,    43,    45,    42,    47,   126,    64,
      46,    59,   123,   125,    41,    58,    44
};
# endif

#define YYPACT_NINF (-123)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-9)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
      18,   -27,     9,    23,    49,  -123,  -123,    17,  -123,  -123,
      58,     3,    20,    43,   -17,     3,  -123,   -11,    60,  -123,
     -15,     0,    83,  -123,    76,    30,    73,    81,  -123,    -8,
    -123,    85,   117,   130,    33,   287,  -123,   133,  -123,   109,
     112,   134,   287,    75,   287,    47,   146,   287,  -123,  -123,
    -123,    39,   287,   287,   287,    74,   447,   129,   101,   156,
    -123,   366,    -1,   132,     8,   157,   337,   166,   380,  -123,
      51,   287,   180,   491,   391,    51,   142,   261,   458,   287,
     287,   287,   287,   287,   287,   287,   161,   163,  -123,   128,
     147,   405,   148,   287,  -123,  -123,   168,   287,  -123,    11,
     287,   107,   107,   491,  -123,   491,  -123,  -123,  -123,   469,
    -123,   280,   280,   280,   125,   125,    51,    51,   155,   172,
     164,   419,  -123,   167,   154,   306,   182,   491,   287,  -123,
     348,   169,   152,  -123,     7,    48,    65,  -123,   185,   207,
    -123,   171,  -123,   173,   433,   287,   287,   491,  -123,  -123,
     192,  -123,  -123,  -123,  -123,   287,   186,  -123,   491,  -123,
    -123,   178,   317,   491,   206,   491,   234,    89,  -123,  -123,
     287,  -123,   491,  -123,   480,    92,  -123,  -123
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     0,     0,     2,     3,     5,     0,     1,     4,
       0,     0,     0,     0,     0,     0,    10,     0,     0,     9,
       0,     0,     0,     6,     0,     0,     0,     0,    19,     0,
       7,     0,     0,     0,     0,     0,    13,     0,    21,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    63,    62,
      64,    61,     0,     0,     0,     0,     0,     0,     0,     0,
      20,     0,     0,     0,     0,     0,     0,     0,     0,    49,
      50,     0,     0,    59,     0,    55,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    14,     0,
       0,     0,     0,     0,    65,    31,     0,     0,    29,     0,
       0,     0,     0,    36,    41,    25,    60,    24,    45,     0,
      22,    57,    56,    58,    51,    52,    53,    54,     0,     0,
       0,     0,    15,     0,     0,     0,    27,    46,     0,    30,
       0,     0,     0,    34,     0,     0,     0,    23,     0,     0,
      17,     0,    11,     0,     0,     0,     0,    47,    44,    33,
       0,    66,    35,    48,    42,     0,     0,    37,    25,    18,
      16,     0,     0,    28,     0,    26,     0,     0,    12,    43,
       0,    39,    25,    38,     0,     0,    32,    40
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -123,  -123,  -123,   226,   217,  -123,  -123,   193,  -123,  -122,
     170,  -123,    10,   135,   -42
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     3,     4,     5,    14,    19,    34,    28,    77,   136,
      64,    65,   133,   134,    56
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      61,    25,    66,    68,    13,    70,    94,    17,   131,    17,
      73,    74,    75,    78,     6,    97,    91,    35,   128,     1,
      21,     2,   151,     8,    26,    10,    18,    -8,    24,   103,
     105,   132,     7,    36,    22,   109,   167,   111,   112,   113,
     114,   115,   116,   117,    27,    95,    -8,   121,    67,   131,
     175,   125,     2,    42,    98,   127,    43,   129,   130,    11,
      44,    45,    15,   153,    71,    46,    47,    48,    49,    50,
      72,    51,   132,    52,    31,    76,    62,    40,    53,    41,
      42,    12,   144,    43,    16,    54,   147,    44,    45,    55,
      86,    87,    46,    47,    48,    49,    50,   158,    51,    63,
      52,    23,    90,   162,   163,    53,    29,    42,   131,   154,
      43,   155,    54,   165,    44,    45,    55,    30,    32,    46,
      47,    48,    49,    50,   172,    51,    33,    52,   174,   120,
      37,   132,    53,   173,    42,   155,   177,    43,   155,    54,
      38,    44,    45,    55,   152,   152,    46,    47,    48,    49,
      50,    58,    51,    39,    52,   143,    57,    59,    26,    53,
      42,    84,    85,    43,    86,    87,    54,    44,    45,    69,
      55,    89,    46,    47,    48,    49,    50,    96,    51,    92,
      52,    63,   101,   107,   118,    53,    42,   119,   122,    43,
     124,   126,    54,    44,    45,   138,    55,   150,    46,    47,
      48,    49,    50,   139,    51,   140,    52,   146,   142,   156,
     149,    53,   159,    42,   160,   164,    43,   166,    54,   168,
      44,    45,    55,   170,   104,    46,    47,    48,    49,    50,
       9,    51,    20,    52,    60,    99,     0,   135,    53,     0,
      42,     0,     0,    43,     0,    54,     0,    44,    45,    55,
       0,   157,    46,    47,    48,    49,    50,     0,    51,     0,
      52,     0,     0,     0,     0,    53,     0,    42,     0,     0,
      43,     0,    54,     0,    44,    45,    55,     0,   171,    46,
      47,    48,    49,    50,     0,    51,     0,    52,     0,     0,
       0,     0,    53,    42,     0,     0,    43,     0,     0,    54,
      44,    45,     0,    55,   108,    46,    47,    48,    49,    50,
     145,    51,     0,    52,    82,    83,    84,    85,    53,    86,
      87,     0,   169,     0,     0,    54,     0,     0,     0,    55,
       0,     0,     0,    79,     0,     0,     0,     0,    80,    81,
      82,    83,    84,    85,    79,    86,    87,   100,     0,    80,
      81,    82,    83,    84,    85,     0,    86,    87,     0,   148,
       0,     0,     0,     0,    79,     0,     0,     0,     0,    80,
      81,    82,    83,    84,    85,    79,    86,    87,    93,     0,
      80,    81,    82,    83,    84,    85,     0,    86,    87,     0,
       0,     0,     0,    79,     0,     0,   102,     0,    80,    81,
      82,    83,    84,    85,     0,    86,    87,    79,     0,     0,
       0,     0,    80,    81,    82,    83,    84,    85,    79,    86,
      87,     0,     0,    80,    81,    82,    83,    84,    85,     0,
      86,    87,    79,     0,     0,   106,     0,    80,    81,    82,
      83,    84,    85,     0,    86,    87,    79,     0,   123,     0,
       0,    80,    81,    82,    83,    84,    85,     0,    86,    87,
      79,     0,   141,     0,     0,    80,    81,    82,    83,    84,
      85,     0,    86,    87,    79,     0,   161,     0,     0,    80,
      81,    82,    83,    84,    85,    79,    86,    87,    88,     0,
      80,    81,    82,    83,    84,    85,    79,    86,    87,   110,
       0,    80,    81,    82,    83,    84,    85,    79,    86,    87,
     137,     0,    80,    81,    82,    83,    84,    85,    79,    86,
      87,   176,     0,    80,    81,    82,    83,    84,    85,     0,
      86,    87
};

static const yytype_int16 yycheck[] =
{
      42,     1,    44,    45,     1,    47,     7,    24,     1,    24,
      52,    53,    54,    55,    41,     7,    58,    25,     7,     1,
      31,     3,    15,     0,    24,     8,    43,    24,    43,    71,
      72,    24,    23,    41,    45,    77,   158,    79,    80,    81,
      82,    83,    84,    85,    44,    46,    43,    89,     1,     1,
     172,    93,     3,     6,    46,    97,     9,    46,   100,    42,
      13,    14,    42,    15,    25,    18,    19,    20,    21,    22,
      31,    24,    24,    26,    44,     1,     1,    44,    31,    46,
       6,    23,   124,     9,    41,    38,   128,    13,    14,    42,
      39,    40,    18,    19,    20,    21,    22,   139,    24,    24,
      26,    41,     1,   145,   146,    31,    23,     6,     1,    44,
       9,    46,    38,   155,    13,    14,    42,    41,    45,    18,
      19,    20,    21,    22,   166,    24,    45,    26,   170,     1,
      45,    24,    31,    44,     6,    46,    44,     9,    46,    38,
      23,    13,    14,    42,   134,   135,    18,    19,    20,    21,
      22,    42,    24,    23,    26,     1,    23,    45,    24,    31,
       6,    36,    37,     9,    39,    40,    38,    13,    14,    23,
      42,    42,    18,    19,    20,    21,    22,    45,    24,    23,
      26,    24,    16,    41,    23,    31,     6,    24,    41,     9,
      42,    23,    38,    13,    14,    40,    42,    45,    18,    19,
      20,    21,    22,    31,    24,    41,    26,    25,    41,    24,
      41,    31,    41,     6,    41,    23,     9,    31,    38,    41,
      13,    14,    42,    17,    44,    18,    19,    20,    21,    22,
       4,    24,    15,    26,    41,    65,    -1,   102,    31,    -1,
       6,    -1,    -1,     9,    -1,    38,    -1,    13,    14,    42,
      -1,    44,    18,    19,    20,    21,    22,    -1,    24,    -1,
      26,    -1,    -1,    -1,    -1,    31,    -1,     6,    -1,    -1,
       9,    -1,    38,    -1,    13,    14,    42,    -1,    44,    18,
      19,    20,    21,    22,    -1,    24,    -1,    26,    -1,    -1,
      -1,    -1,    31,     6,    -1,    -1,     9,    -1,    -1,    38,
      13,    14,    -1,    42,    43,    18,    19,    20,    21,    22,
       4,    24,    -1,    26,    34,    35,    36,    37,    31,    39,
      40,    -1,     5,    -1,    -1,    38,    -1,    -1,    -1,    42,
      -1,    -1,    -1,    27,    -1,    -1,    -1,    -1,    32,    33,
      34,    35,    36,    37,    27,    39,    40,    10,    -1,    32,
      33,    34,    35,    36,    37,    -1,    39,    40,    -1,    11,
      -1,    -1,    -1,    -1,    27,    -1,    -1,    -1,    -1,    32,
      33,    34,    35,    36,    37,    27,    39,    40,    12,    -1,
      32,    33,    34,    35,    36,    37,    -1,    39,    40,    -1,
      -1,    -1,    -1,    27,    -1,    -1,    16,    -1,    32,    33,
      34,    35,    36,    37,    -1,    39,    40,    27,    -1,    -1,
      -1,    -1,    32,    33,    34,    35,    36,    37,    27,    39,
      40,    -1,    -1,    32,    33,    34,    35,    36,    37,    -1,
      39,    40,    27,    -1,    -1,    44,    -1,    32,    33,    34,
      35,    36,    37,    -1,    39,    40,    27,    -1,    43,    -1,
      -1,    32,    33,    34,    35,    36,    37,    -1,    39,    40,
      27,    -1,    43,    -1,    -1,    32,    33,    34,    35,    36,
      37,    -1,    39,    40,    27,    -1,    43,    -1,    -1,    32,
      33,    34,    35,    36,    37,    27,    39,    40,    41,    -1,
      32,    33,    34,    35,    36,    37,    27,    39,    40,    41,
      -1,    32,    33,    34,    35,    36,    37,    27,    39,    40,
      41,    -1,    32,    33,    34,    35,    36,    37,    27,    39,
      40,    41,    -1,    32,    33,    34,    35,    36,    37,    -1,
      39,    40
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     1,     3,    48,    49,    50,    41,    23,     0,    50,
       8,    42,    23,     1,    51,    42,    41,    24,    43,    52,
      51,    31,    45,    41,    43,     1,    24,    44,    54,    23,
      41,    44,    45,    45,    53,    25,    41,    45,    23,    23,
      44,    46,     6,     9,    13,    14,    18,    19,    20,    21,
      22,    24,    26,    31,    38,    42,    61,    23,    42,    45,
      54,    61,     1,    24,    57,    58,    61,     1,    61,    23,
      61,    25,    31,    61,    61,    61,     1,    55,    61,    27,
      32,    33,    34,    35,    36,    37,    39,    40,    41,    42,
       1,    61,    23,    12,     7,    46,    45,     7,    46,    57,
      10,    16,    16,    61,    44,    61,    44,    41,    43,    61,
      41,    61,    61,    61,    61,    61,    61,    61,    23,    24,
       1,    61,    41,    43,    42,    61,    23,    61,     7,    46,
      61,     1,    24,    59,    60,    60,    56,    41,    40,    31,
      41,    43,    41,     1,    61,     4,    25,    61,    11,    41,
      45,    15,    59,    15,    44,    46,    24,    44,    61,    41,
      41,    43,    61,    61,    23,    61,    31,    56,    41,     5,
      17,    44,    61,    44,    61,    56,    41,    44
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
{
       0,    47,    48,    49,    49,    49,    50,    50,    51,    51,
      51,    52,    52,    52,    52,    52,    52,    52,    52,    53,
      53,    54,    55,    55,    55,    56,    56,    57,    57,    58,
      58,    58,    59,    59,    60,    60,    61,    61,    61,    61,
      61,    61,    61,    61,    61,    61,    61,    61,    61,    61,
      61,    61,    61,    61,    61,    61,    61,    61,    61,    61,
      61,    61,    61,    61,    61,    61,    61
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     2,     2,     6,     8,     0,     2,
       2,     9,    11,     4,     6,     8,    10,     9,    10,     0,
       3,     3,     2,     3,     2,     0,     3,     3,     5,     2,
       3,     2,     6,     2,     1,     2,     3,     5,     7,     7,
       9,     3,     5,     7,     5,     3,     4,     5,     5,     2,
       2,     3,     3,     3,     3,     2,     3,     3,     3,     2,
       3,     1,     1,     1,     1,     3,     5
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

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


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, int yyrule)
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
                       yystos[+yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
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
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
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
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
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
            else
              goto append;

          append:
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

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
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
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

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
      int yyn = yypact[+*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
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
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
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
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
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
          ++yyp;
          ++yyformat;
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
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYPTRDIFF_T yystacksize;

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
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
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

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
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
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

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
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 2:
#line 128 "cool.y"
                        { ast_root = program((yyvsp[0].classes));}
#line 1604 "cool.tab.c"
    break;

  case 3:
#line 132 "cool.y"
             { (yyval.classes) = single_Classes((yyvsp[0].class_)); parse_results = (yyval.classes); }
#line 1610 "cool.tab.c"
    break;

  case 4:
#line 134 "cool.y"
             { (yyval.classes) = append_Classes((yyvsp[-1].classes), single_Classes((yyvsp[0].class_))); parse_results = (yyval.classes); }
#line 1616 "cool.tab.c"
    break;

  case 5:
#line 135 "cool.y"
                       {}
#line 1622 "cool.tab.c"
    break;

  case 6:
#line 140 "cool.y"
        { (yyval.class_) = class_((yyvsp[-4].symbol),idtable.add_string((char *)"Object"),(yyvsp[-2].features),
			             stringtable.add_string(curr_filename)); }
#line 1629 "cool.tab.c"
    break;

  case 7:
#line 143 "cool.y"
        { (yyval.class_) = class_((yyvsp[-6].symbol),(yyvsp[-4].symbol),(yyvsp[-2].features),stringtable.add_string(curr_filename)); }
#line 1635 "cool.tab.c"
    break;

  case 8:
#line 147 "cool.y"
                                             { (yyval.features) = nil_Features(); }
#line 1641 "cool.tab.c"
    break;

  case 9:
#line 149 "cool.y"
                     { (yyval.features) = append_Features((yyvsp[-1].features),single_Features((yyvsp[0].feature)));}
#line 1647 "cool.tab.c"
    break;

  case 10:
#line 150 "cool.y"
                               {}
#line 1653 "cool.tab.c"
    break;

  case 11:
#line 154 "cool.y"
          { (yyval.feature) = method((yyvsp[-8].symbol), nil_Formals(), (yyvsp[-4].symbol), (yyvsp[-2].expression)); }
#line 1659 "cool.tab.c"
    break;

  case 12:
#line 156 "cool.y"
          { (yyval.feature) = method((yyvsp[-10].symbol), append_Formals((yyvsp[-7].formals), single_Formals((yyvsp[-8].formal))), (yyvsp[-4].symbol), (yyvsp[-2].expression)); }
#line 1665 "cool.tab.c"
    break;

  case 13:
#line 158 "cool.y"
          { (yyval.feature) = attr((yyvsp[-3].symbol), (yyvsp[-1].symbol), no_expr());}
#line 1671 "cool.tab.c"
    break;

  case 14:
#line 160 "cool.y"
          { (yyval.feature) = attr((yyvsp[-5].symbol), (yyvsp[-3].symbol), (yyvsp[-1].expression));}
#line 1677 "cool.tab.c"
    break;

  case 15:
#line 161 "cool.y"
                                                     {}
#line 1683 "cool.tab.c"
    break;

  case 16:
#line 162 "cool.y"
                                                                       {}
#line 1689 "cool.tab.c"
    break;

  case 17:
#line 163 "cool.y"
                                                          {}
#line 1695 "cool.tab.c"
    break;

  case 18:
#line 164 "cool.y"
                                                             {}
#line 1701 "cool.tab.c"
    break;

  case 19:
#line 167 "cool.y"
                           { (yyval.formals) = nil_Formals();}
#line 1707 "cool.tab.c"
    break;

  case 20:
#line 169 "cool.y"
              { (yyval.formals) = append_Formals((yyvsp[-2].formals), single_Formals((yyvsp[0].formal)));}
#line 1713 "cool.tab.c"
    break;

  case 21:
#line 173 "cool.y"
         { (yyval.formal) = formal((yyvsp[-2].symbol), (yyvsp[0].symbol));}
#line 1719 "cool.tab.c"
    break;

  case 22:
#line 177 "cool.y"
            { (yyval.expressions) = single_Expressions((yyvsp[-1].expression)); }
#line 1725 "cool.tab.c"
    break;

  case 23:
#line 179 "cool.y"
            { (yyval.expressions) = append_Expressions((yyvsp[-2].expressions),  single_Expressions((yyvsp[-1].expression))); }
#line 1731 "cool.tab.c"
    break;

  case 24:
#line 180 "cool.y"
                      {}
#line 1737 "cool.tab.c"
    break;

  case 25:
#line 183 "cool.y"
                               { (yyval.expressions) = nil_Expressions(); }
#line 1743 "cool.tab.c"
    break;

  case 26:
#line 185 "cool.y"
                  { (yyval.expressions) = append_Expressions((yyvsp[-2].expressions), single_Expressions((yyvsp[0].expression)));}
#line 1749 "cool.tab.c"
    break;

  case 27:
#line 188 "cool.y"
              { Let_structure letD;
                letD.id = (yyvsp[-2].symbol); letD.type = (yyvsp[0].symbol); letD.init = no_expr();
                (yyval.letS) = letD; }
#line 1757 "cool.tab.c"
    break;

  case 28:
#line 192 "cool.y"
              { Let_structure letD;
                letD.id = (yyvsp[-4].symbol); letD.type = (yyvsp[-2].symbol); letD.init = (yyvsp[0].expression);
                (yyval.letS) = letD; }
#line 1765 "cool.tab.c"
    break;

  case 29:
#line 197 "cool.y"
           { ListLet * tmp = new ListLet();
             tmp->size();
             tmp->push_back((yyvsp[-1].letS));
             (yyval.listLet) = tmp; }
#line 1774 "cool.tab.c"
    break;

  case 30:
#line 202 "cool.y"
           { (yyvsp[-2].listLet)->push_back((yyvsp[-1].letS));
             (yyval.listLet) = (yyvsp[-2].listLet); }
#line 1781 "cool.tab.c"
    break;

  case 31:
#line 204 "cool.y"
                     { (yyval.listLet) = new ListLet();}
#line 1787 "cool.tab.c"
    break;

  case 32:
#line 208 "cool.y"
             { (yyval.case_) = branch((yyvsp[-5].symbol), (yyvsp[-3].symbol), (yyvsp[-1].expression));}
#line 1793 "cool.tab.c"
    break;

  case 33:
#line 209 "cool.y"
                       {}
#line 1799 "cool.tab.c"
    break;

  case 34:
#line 213 "cool.y"
                  { (yyval.cases) = single_Cases((yyvsp[0].case_)); }
#line 1805 "cool.tab.c"
    break;

  case 35:
#line 215 "cool.y"
                  { (yyval.cases) = append_Cases((yyvsp[-1].cases), single_Cases((yyvsp[0].case_))); }
#line 1811 "cool.tab.c"
    break;

  case 36:
#line 219 "cool.y"
       { (yyval.expression) = assign((yyvsp[-2].symbol), (yyvsp[0].expression)); }
#line 1817 "cool.tab.c"
    break;

  case 37:
#line 221 "cool.y"
       { (yyval.expression) = dispatch((yyvsp[-4].expression), (yyvsp[-2].symbol), nil_Expressions()); }
#line 1823 "cool.tab.c"
    break;

  case 38:
#line 223 "cool.y"
       { (yyval.expression) = dispatch((yyvsp[-6].expression), (yyvsp[-4].symbol), append_Expressions((yyvsp[-1].expressions), single_Expressions((yyvsp[-2].expression))));}
#line 1829 "cool.tab.c"
    break;

  case 39:
#line 225 "cool.y"
       { (yyval.expression) = static_dispatch((yyvsp[-6].expression), (yyvsp[-4].symbol), (yyvsp[-2].symbol), nil_Expressions()); }
#line 1835 "cool.tab.c"
    break;

  case 40:
#line 227 "cool.y"
       { (yyval.expression) = static_dispatch((yyvsp[-8].expression), (yyvsp[-6].symbol), (yyvsp[-4].symbol), append_Expressions((yyvsp[-1].expressions), single_Expressions((yyvsp[-2].expression)))); }
#line 1841 "cool.tab.c"
    break;

  case 41:
#line 229 "cool.y"
       { (yyval.expression) = dispatch(object(idtable.add_string((char *)"self")), 
                       (yyvsp[-2].symbol), nil_Expressions()); }
#line 1848 "cool.tab.c"
    break;

  case 42:
#line 232 "cool.y"
       {(yyval.expression) = dispatch(object(idtable.add_string((char *)"self")), 
                      (yyvsp[-4].symbol), append_Expressions((yyvsp[-1].expressions),single_Expressions((yyvsp[-2].expression)))); }
#line 1855 "cool.tab.c"
    break;

  case 43:
#line 235 "cool.y"
       { (yyval.expression) = cond((yyvsp[-5].expression), (yyvsp[-3].expression), (yyvsp[-1].expression)); }
#line 1861 "cool.tab.c"
    break;

  case 44:
#line 237 "cool.y"
       { (yyval.expression) = loop((yyvsp[-3].expression), (yyvsp[-1].expression)); }
#line 1867 "cool.tab.c"
    break;

  case 45:
#line 239 "cool.y"
       { (yyval.expression) = block((yyvsp[-1].expressions)); }
#line 1873 "cool.tab.c"
    break;

  case 46:
#line 241 "cool.y"
       { (yyval.expression) = let((yyvsp[-2].letS).id, (yyvsp[-2].letS).type, (yyvsp[-2].letS).init, (yyvsp[0].expression)); }
#line 1879 "cool.tab.c"
    break;

  case 47:
#line 243 "cool.y"
       { (yyval.expression) = letConstruct((yyvsp[-3].listLet), (yyvsp[-2].letS), (yyvsp[0].expression)); }
#line 1885 "cool.tab.c"
    break;

  case 48:
#line 245 "cool.y"
       { (yyval.expression) = typcase((yyvsp[-3].expression), (yyvsp[-1].cases)); }
#line 1891 "cool.tab.c"
    break;

  case 49:
#line 247 "cool.y"
       { (yyval.expression) = new_((yyvsp[0].symbol)); }
#line 1897 "cool.tab.c"
    break;

  case 50:
#line 249 "cool.y"
       { (yyval.expression) = isvoid((yyvsp[0].expression)); }
#line 1903 "cool.tab.c"
    break;

  case 51:
#line 251 "cool.y"
       { (yyval.expression) = plus((yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 1909 "cool.tab.c"
    break;

  case 52:
#line 253 "cool.y"
       { (yyval.expression) = sub((yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 1915 "cool.tab.c"
    break;

  case 53:
#line 255 "cool.y"
       { (yyval.expression) = mul((yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 1921 "cool.tab.c"
    break;

  case 54:
#line 257 "cool.y"
       { (yyval.expression) = divide((yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 1927 "cool.tab.c"
    break;

  case 55:
#line 259 "cool.y"
       { (yyval.expression) = neg((yyvsp[0].expression)); }
#line 1933 "cool.tab.c"
    break;

  case 56:
#line 261 "cool.y"
       { (yyval.expression) = lt((yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 1939 "cool.tab.c"
    break;

  case 57:
#line 263 "cool.y"
       { (yyval.expression) = leq((yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 1945 "cool.tab.c"
    break;

  case 58:
#line 265 "cool.y"
       { (yyval.expression) = eq((yyvsp[-2].expression), (yyvsp[0].expression)); }
#line 1951 "cool.tab.c"
    break;

  case 59:
#line 267 "cool.y"
       { (yyval.expression) = neg((yyvsp[0].expression)); }
#line 1957 "cool.tab.c"
    break;

  case 60:
#line 269 "cool.y"
       { (yyval.expression) = (yyvsp[-1].expression); }
#line 1963 "cool.tab.c"
    break;

  case 61:
#line 271 "cool.y"
       { (yyval.expression) = object((yyvsp[0].symbol)); }
#line 1969 "cool.tab.c"
    break;

  case 62:
#line 273 "cool.y"
       { (yyval.expression) = int_const((yyvsp[0].symbol)); }
#line 1975 "cool.tab.c"
    break;

  case 63:
#line 275 "cool.y"
       { (yyval.expression) = string_const((yyvsp[0].symbol)); }
#line 1981 "cool.tab.c"
    break;

  case 64:
#line 277 "cool.y"
       { (yyval.expression) = bool_const((yyvsp[0].boolean)); }
#line 1987 "cool.tab.c"
    break;

  case 65:
#line 278 "cool.y"
                    {}
#line 1993 "cool.tab.c"
    break;

  case 66:
#line 279 "cool.y"
                                           {}
#line 1999 "cool.tab.c"
    break;


#line 2003 "cool.tab.c"

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
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
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


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
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
                  yystos[+*yyssp], yyvsp);
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
#line 284 "cool.y"


/* This function is called automatically when Bison detects a parse error. */
void yyerror(char *s)
{
  extern int curr_lineno;

  cerr << "\"" << curr_filename << "\", line " << curr_lineno << ": " \
    << s << " at or near ";
  print_cool_token(yychar);
  cerr << endl;
  omerrs++;

  if(omerrs>50) {fprintf(stdout, "More than 50 errors\n"); exit(1);}
}

