/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

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
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "./src/scanparse/parser.y"



#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "palm/memory.h"
#include "palm/ctinfo.h"
#include "palm/dbug.h"
#include "palm/str.h"
#include "ccngen/ast.h"
#include "ccngen/enum.h"
#include "global/globals.h"

static node_st *parseresult = NULL;
extern int yylex();
int yyerror(char *errname);
extern FILE *yyin;
void AddLocToNode(node_st *node, void *begin_loc, void *end_loc);



#line 94 "parser.tab.c"

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


/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    BRACKET_L = 258,               /* BRACKET_L  */
    BRACKET_R = 259,               /* BRACKET_R  */
    COMMA = 260,                   /* COMMA  */
    SEMICOLON = 261,               /* SEMICOLON  */
    CURLY_L = 262,                 /* CURLY_L  */
    CURLY_R = 263,                 /* CURLY_R  */
    SQUARE_L = 264,                /* SQUARE_L  */
    SQUARE_R = 265,                /* SQUARE_R  */
    MINUS = 266,                   /* MINUS  */
    PLUS = 267,                    /* PLUS  */
    STAR = 268,                    /* STAR  */
    SLASH = 269,                   /* SLASH  */
    PERCENT = 270,                 /* PERCENT  */
    LE = 271,                      /* LE  */
    LT = 272,                      /* LT  */
    GE = 273,                      /* GE  */
    GT = 274,                      /* GT  */
    EQ = 275,                      /* EQ  */
    NE = 276,                      /* NE  */
    OR = 277,                      /* OR  */
    AND = 278,                     /* AND  */
    TRUEVAL = 279,                 /* TRUEVAL  */
    FALSEVAL = 280,                /* FALSEVAL  */
    LET = 281,                     /* LET  */
    NUM = 282,                     /* NUM  */
    FLOAT = 283,                   /* FLOAT  */
    ID = 284,                      /* ID  */
    EXPORT = 285,                  /* EXPORT  */
    RETURN = 286,                  /* RETURN  */
    TYPE_INT = 287,                /* TYPE_INT  */
    TYPE_FLOAT = 288,              /* TYPE_FLOAT  */
    TYPE_BOOL = 289,               /* TYPE_BOOL  */
    TYPE_VOID = 290,               /* TYPE_VOID  */
    IF = 291,                      /* IF  */
    ELSE = 292,                    /* ELSE  */
    EXTERN = 293                   /* EXTERN  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 24 "./src/scanparse/parser.y"

 char               *id;
 int                 cint;
 float               cflt;
 enum BinOpType     cbinop;
 enum Type           ctype;
 node_st             *node;

#line 188 "parser.tab.c"

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



/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_BRACKET_L = 3,                  /* BRACKET_L  */
  YYSYMBOL_BRACKET_R = 4,                  /* BRACKET_R  */
  YYSYMBOL_COMMA = 5,                      /* COMMA  */
  YYSYMBOL_SEMICOLON = 6,                  /* SEMICOLON  */
  YYSYMBOL_CURLY_L = 7,                    /* CURLY_L  */
  YYSYMBOL_CURLY_R = 8,                    /* CURLY_R  */
  YYSYMBOL_SQUARE_L = 9,                   /* SQUARE_L  */
  YYSYMBOL_SQUARE_R = 10,                  /* SQUARE_R  */
  YYSYMBOL_MINUS = 11,                     /* MINUS  */
  YYSYMBOL_PLUS = 12,                      /* PLUS  */
  YYSYMBOL_STAR = 13,                      /* STAR  */
  YYSYMBOL_SLASH = 14,                     /* SLASH  */
  YYSYMBOL_PERCENT = 15,                   /* PERCENT  */
  YYSYMBOL_LE = 16,                        /* LE  */
  YYSYMBOL_LT = 17,                        /* LT  */
  YYSYMBOL_GE = 18,                        /* GE  */
  YYSYMBOL_GT = 19,                        /* GT  */
  YYSYMBOL_EQ = 20,                        /* EQ  */
  YYSYMBOL_NE = 21,                        /* NE  */
  YYSYMBOL_OR = 22,                        /* OR  */
  YYSYMBOL_AND = 23,                       /* AND  */
  YYSYMBOL_TRUEVAL = 24,                   /* TRUEVAL  */
  YYSYMBOL_FALSEVAL = 25,                  /* FALSEVAL  */
  YYSYMBOL_LET = 26,                       /* LET  */
  YYSYMBOL_NUM = 27,                       /* NUM  */
  YYSYMBOL_FLOAT = 28,                     /* FLOAT  */
  YYSYMBOL_ID = 29,                        /* ID  */
  YYSYMBOL_EXPORT = 30,                    /* EXPORT  */
  YYSYMBOL_RETURN = 31,                    /* RETURN  */
  YYSYMBOL_TYPE_INT = 32,                  /* TYPE_INT  */
  YYSYMBOL_TYPE_FLOAT = 33,                /* TYPE_FLOAT  */
  YYSYMBOL_TYPE_BOOL = 34,                 /* TYPE_BOOL  */
  YYSYMBOL_TYPE_VOID = 35,                 /* TYPE_VOID  */
  YYSYMBOL_IF = 36,                        /* IF  */
  YYSYMBOL_ELSE = 37,                      /* ELSE  */
  YYSYMBOL_EXTERN = 38,                    /* EXTERN  */
  YYSYMBOL_YYACCEPT = 39,                  /* $accept  */
  YYSYMBOL_program = 40,                   /* program  */
  YYSYMBOL_decls = 41,                     /* decls  */
  YYSYMBOL_decl = 42,                      /* decl  */
  YYSYMBOL_glob_decl = 43,                 /* glob_decl  */
  YYSYMBOL_stmts = 44,                     /* stmts  */
  YYSYMBOL_stmt = 45,                      /* stmt  */
  YYSYMBOL_fundef = 46,                    /* fundef  */
  YYSYMBOL_funbody = 47,                   /* funbody  */
  YYSYMBOL_var_decl = 48,                  /* var_decl  */
  YYSYMBOL_assign = 49,                    /* assign  */
  YYSYMBOL_return_stmt = 50,               /* return_stmt  */
  YYSYMBOL_if_stmt = 51,                   /* if_stmt  */
  YYSYMBOL_param = 52,                     /* param  */
  YYSYMBOL_varlet = 53,                    /* varlet  */
  YYSYMBOL_expr = 54,                      /* expr  */
  YYSYMBOL_constant = 55,                  /* constant  */
  YYSYMBOL_type = 56,                      /* type  */
  YYSYMBOL_floatval = 57,                  /* floatval  */
  YYSYMBOL_intval = 58,                    /* intval  */
  YYSYMBOL_boolval = 59,                   /* boolval  */
  YYSYMBOL_binop = 60                      /* binop  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




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

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
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
typedef yytype_int8 yy_state_t;

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
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
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
#define YYFINAL  15
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   128

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  39
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  22
/* YYNRULES -- Number of rules.  */
#define YYNRULES  58
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  110

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   293


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
      35,    36,    37,    38
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    77,    77,    83,    87,    94,    98,   104,   110,   114,
     123,   128,   134,   138,   142,   146,   152,   156,   160,   164,
     168,   197,   201,   205,   211,   216,   222,   226,   232,   236,
     242,   247,   254,   262,   266,   270,   277,   281,   285,   291,
     292,   293,   294,   296,   302,   308,   312,   318,   319,   320,
     321,   322,   323,   324,   325,   326,   327,   328,   329
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
  "\"end of file\"", "error", "\"invalid token\"", "BRACKET_L",
  "BRACKET_R", "COMMA", "SEMICOLON", "CURLY_L", "CURLY_R", "SQUARE_L",
  "SQUARE_R", "MINUS", "PLUS", "STAR", "SLASH", "PERCENT", "LE", "LT",
  "GE", "GT", "EQ", "NE", "OR", "AND", "TRUEVAL", "FALSEVAL", "LET", "NUM",
  "FLOAT", "ID", "EXPORT", "RETURN", "TYPE_INT", "TYPE_FLOAT", "TYPE_BOOL",
  "TYPE_VOID", "IF", "ELSE", "EXTERN", "$accept", "program", "decls",
  "decl", "glob_decl", "stmts", "stmt", "fundef", "funbody", "var_decl",
  "assign", "return_stmt", "if_stmt", "param", "varlet", "expr",
  "constant", "type", "floatval", "intval", "boolval", "binop", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-43)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-1)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      73,    85,   -43,   -43,   -43,   -43,    85,    12,   -43,    73,
     -43,   -43,   -16,   -10,    -5,   -43,   -43,    22,    27,     8,
       6,    19,   -43,    25,    38,    14,    25,    40,    26,   -43,
      25,    24,   -43,    25,   -43,   -43,    53,    15,    80,    39,
     -43,   -43,    31,    21,   -43,    85,   -43,    53,   -43,   -43,
     -43,   -43,   -43,    41,   -43,   -43,   -43,   -43,    60,    56,
     -43,    36,   -43,    -4,    53,    11,    43,   -43,    79,    80,
     -43,    61,   -43,   -43,    68,    77,   -43,    53,    53,   -43,
     -43,   -43,   -43,   -43,   -43,   -43,   -43,   -43,   -43,   -43,
     -43,    53,    71,   -43,   -43,   -43,    98,   104,    82,    84,
      85,   -43,   -43,   115,   -43,    94,    80,    11,   116,   -43
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,    39,    40,    41,    42,     0,     0,     2,     4,
       5,     6,     0,     0,     0,     1,     3,     0,     0,     0,
       0,     0,     7,     0,     0,     0,     0,     0,     0,    15,
       0,    30,    13,     0,    19,    32,     0,     0,     9,     0,
      10,    11,     0,     0,    14,     0,    12,     0,    45,    46,
      44,    43,    34,     0,    33,    36,    37,    38,     0,     0,
       8,     0,    20,     0,     0,     0,     0,    31,     0,     0,
      27,     0,    17,    18,     0,     0,    21,     0,     0,    48,
      47,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,     0,     0,    26,    16,    24,     0,     0,     0,    29,
      22,    25,    35,     0,    23,     0,     0,     0,     0,    28
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -43,   -43,   117,   -43,   -43,   -36,   -43,   -43,   -15,    28,
     -43,    62,   -43,   -14,   -35,   -42,   -43,     0,   -43,   -43,
     -43,   -43
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     7,     8,     9,    10,    37,    38,    11,    29,    39,
      40,    59,    41,    24,    42,    53,    54,    61,    55,    56,
      57,    91
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      12,    13,    60,    63,    73,    68,    14,    27,    66,    12,
      23,    32,    15,    17,    22,    44,    71,    76,    46,    18,
      25,    25,    75,    26,    19,    20,    66,    58,    43,    45,
      21,    67,    28,    92,    34,    96,    97,    77,     2,     3,
       4,     5,    30,    31,    33,    25,    58,    62,    69,    98,
      65,     2,     3,     4,     5,    35,    47,    64,     2,     3,
       4,     5,    36,    47,    72,    35,    70,    93,    35,    78,
     108,     2,     3,     4,     5,    36,    94,    48,    49,    99,
      50,    51,    52,    95,    48,    49,   102,    50,    51,    52,
      79,    80,    81,    82,    83,    84,    85,    86,    87,    88,
     105,    89,    90,     1,   100,     2,     3,     4,     5,    35,
     101,     6,     2,     3,     4,     5,    36,     2,     3,     4,
       5,   103,   106,   107,   109,    74,    16,     0,   104
};

static const yytype_int8 yycheck[] =
{
       0,     1,    38,    39,     8,    47,     6,    21,    43,     9,
       4,    26,     0,    29,     6,    30,    58,     6,    33,    29,
      20,    21,    64,     4,    29,     3,    61,    31,    28,     5,
       3,    45,     7,    69,     8,    77,    78,    26,    32,    33,
      34,    35,     4,    29,     4,    45,    31,     8,     7,    91,
      29,    32,    33,    34,    35,    29,     3,    26,    32,    33,
      34,    35,    36,     3,     8,    29,     6,     6,    29,    26,
     106,    32,    33,    34,    35,    36,     8,    24,    25,     8,
      27,    28,    29,     6,    24,    25,     4,    27,    28,    29,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
     100,    22,    23,    30,     6,    32,    33,    34,    35,    29,
       6,    38,    32,    33,    34,    35,    36,    32,    33,    34,
      35,    37,     7,    29,     8,    63,     9,    -1,   100
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    30,    32,    33,    34,    35,    38,    40,    41,    42,
      43,    46,    56,    56,    56,     0,    41,    29,    29,    29,
       3,     3,     6,     4,    52,    56,     4,    52,     7,    47,
       4,    29,    47,     4,     8,    29,    36,    44,    45,    48,
      49,    51,    53,    56,    47,     5,    47,     3,    24,    25,
      27,    28,    29,    54,    55,    57,    58,    59,    31,    50,
      44,    56,     8,    44,    26,    29,    53,    52,    54,     7,
       6,    54,     8,     8,    50,    54,     6,    26,    26,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    22,
      23,    60,    44,     6,     8,     6,    54,    54,    54,     8,
       6,     6,     4,    37,    48,    56,     7,    29,    44,     8
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    39,    40,    41,    41,    42,    42,    43,    44,    44,
      45,    45,    46,    46,    46,    46,    47,    47,    47,    47,
      47,    48,    48,    48,    49,    49,    50,    50,    51,    51,
      52,    52,    53,    54,    54,    54,    55,    55,    55,    56,
      56,    56,    56,    57,    58,    59,    59,    60,    60,    60,
      60,    60,    60,    60,    60,    60,    60,    60,    60
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     4,     2,     1,
       1,     1,     7,     6,     6,     5,     5,     4,     4,     2,
       3,     3,     5,     6,     4,     5,     3,     2,     9,     5,
       2,     4,     1,     1,     1,     5,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


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


/* YYLOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

# ifndef YYLOCATION_PRINT

#  if defined YY_LOCATION_PRINT

   /* Temporary convenience wrapper in case some people defined the
      undocumented and private YY_LOCATION_PRINT macros.  */
#   define YYLOCATION_PRINT(File, Loc)  YY_LOCATION_PRINT(File, *(Loc))

#  elif defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

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

#   define YYLOCATION_PRINT  yy_location_print_

    /* Temporary convenience wrapper in case some people defined the
       undocumented and private YY_LOCATION_PRINT macros.  */
#   define YY_LOCATION_PRINT(File, Loc)  YYLOCATION_PRINT(File, &(Loc))

#  else

#   define YYLOCATION_PRINT(File, Loc) ((void) 0)
    /* Temporary convenience wrapper in case some people defined the
       undocumented and private YY_LOCATION_PRINT macros.  */
#   define YY_LOCATION_PRINT  YYLOCATION_PRINT

#  endif
# endif /* !defined YYLOCATION_PRINT */


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
  YY_USE (yyoutput);
  YY_USE (yylocationp);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
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

  YYLOCATION_PRINT (yyo, yylocationp);
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
  YY_USE (yyvaluep);
  YY_USE (yylocationp);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
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
    YYNOMEM;
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
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
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
      yychar = yylex ();
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
  case 2: /* program: decls  */
#line 78 "./src/scanparse/parser.y"
         {
           parseresult = ASTprogram((yyvsp[0].node));
         }
#line 1429 "parser.tab.c"
    break;

  case 3: /* decls: decl decls  */
#line 84 "./src/scanparse/parser.y"
        {
          (yyval.node) = ASTdecls((yyvsp[-1].node), (yyvsp[0].node));
        }
#line 1437 "parser.tab.c"
    break;

  case 4: /* decls: decl  */
#line 88 "./src/scanparse/parser.y"
        {
          (yyval.node) = ASTdecls((yyvsp[0].node), NULL);
        }
#line 1445 "parser.tab.c"
    break;

  case 5: /* decl: glob_decl  */
#line 95 "./src/scanparse/parser.y"
      {
        (yyval.node) = (yyvsp[0].node);
      }
#line 1453 "parser.tab.c"
    break;

  case 6: /* decl: fundef  */
#line 99 "./src/scanparse/parser.y"
      {
        (yyval.node) = (yyvsp[0].node);
      }
#line 1461 "parser.tab.c"
    break;

  case 7: /* glob_decl: EXTERN type ID SEMICOLON  */
#line 105 "./src/scanparse/parser.y"
           {
             (yyval.node) = ASTglobdecl((yyvsp[-1].id), (yyvsp[-2].ctype));
           }
#line 1469 "parser.tab.c"
    break;

  case 8: /* stmts: stmt stmts  */
#line 111 "./src/scanparse/parser.y"
        {
          (yyval.node) = ASTstmts((yyvsp[-1].node), (yyvsp[0].node));
        }
#line 1477 "parser.tab.c"
    break;

  case 9: /* stmts: stmt  */
#line 115 "./src/scanparse/parser.y"
        {
          (yyval.node) = ASTstmts((yyvsp[0].node), NULL);
        }
#line 1485 "parser.tab.c"
    break;

  case 10: /* stmt: assign  */
#line 124 "./src/scanparse/parser.y"
       {
         (yyval.node) = (yyvsp[0].node);
       }
#line 1493 "parser.tab.c"
    break;

  case 11: /* stmt: if_stmt  */
#line 129 "./src/scanparse/parser.y"
       {
         (yyval.node) = (yyvsp[0].node);
       }
#line 1501 "parser.tab.c"
    break;

  case 12: /* fundef: EXPORT type ID BRACKET_L param BRACKET_R funbody  */
#line 135 "./src/scanparse/parser.y"
        {
          (yyval.node) = ASTfundef((yyvsp[0].node), (yyvsp[-2].node), (yyvsp[-4].id), (yyvsp[-5].ctype), true); // Exported function
        }
#line 1509 "parser.tab.c"
    break;

  case 13: /* fundef: EXPORT type ID BRACKET_L BRACKET_R funbody  */
#line 139 "./src/scanparse/parser.y"
        {
          (yyval.node) = ASTfundef((yyvsp[0].node), NULL, (yyvsp[-3].id), (yyvsp[-4].ctype), true);
        }
#line 1517 "parser.tab.c"
    break;

  case 14: /* fundef: type ID BRACKET_L param BRACKET_R funbody  */
#line 143 "./src/scanparse/parser.y"
        {
          (yyval.node) = ASTfundef((yyvsp[0].node), (yyvsp[-2].node), (yyvsp[-4].id), (yyvsp[-5].ctype), false); // Non-exported function
        }
#line 1525 "parser.tab.c"
    break;

  case 15: /* fundef: type ID BRACKET_L BRACKET_R funbody  */
#line 147 "./src/scanparse/parser.y"
        {
          (yyval.node) = ASTfundef((yyvsp[0].node), NULL, (yyvsp[-3].id), (yyvsp[-4].ctype), false);
        }
#line 1533 "parser.tab.c"
    break;

  case 16: /* funbody: CURLY_L var_decl stmts return_stmt CURLY_R  */
#line 153 "./src/scanparse/parser.y"
         {
           (yyval.node) = ASTfunbody((yyvsp[-3].node), NULL, ASTstmts((yyvsp[-2].node), (yyvsp[-1].node)));
         }
#line 1541 "parser.tab.c"
    break;

  case 17: /* funbody: CURLY_L stmts return_stmt CURLY_R  */
#line 157 "./src/scanparse/parser.y"
         {
           (yyval.node) = ASTfunbody(NULL, NULL, ASTstmts((yyvsp[-2].node), (yyvsp[-1].node)));
         }
#line 1549 "parser.tab.c"
    break;

  case 18: /* funbody: CURLY_L var_decl stmts CURLY_R  */
#line 161 "./src/scanparse/parser.y"
         {
           (yyval.node) = ASTfunbody((yyvsp[-2].node), NULL, ASTstmts((yyvsp[-1].node), NULL));
         }
#line 1557 "parser.tab.c"
    break;

  case 19: /* funbody: CURLY_L CURLY_R  */
#line 165 "./src/scanparse/parser.y"
         {
           (yyval.node) = ASTfunbody(NULL, NULL, NULL);
         }
#line 1565 "parser.tab.c"
    break;

  case 20: /* funbody: CURLY_L var_decl CURLY_R  */
#line 169 "./src/scanparse/parser.y"
         {
           (yyval.node) = ASTfunbody((yyvsp[-1].node), NULL, NULL);
         }
#line 1573 "parser.tab.c"
    break;

  case 21: /* var_decl: type ID SEMICOLON  */
#line 198 "./src/scanparse/parser.y"
         {
           (yyval.node) = ASTvardecl(NULL, NULL, (yyvsp[-1].id), (yyvsp[-2].ctype));
         }
#line 1581 "parser.tab.c"
    break;

  case 22: /* var_decl: type ID LET expr SEMICOLON  */
#line 202 "./src/scanparse/parser.y"
         {
           (yyval.node) = ASTvardecl((yyvsp[-1].node), NULL, (yyvsp[-3].id), (yyvsp[-4].ctype));
         }
#line 1589 "parser.tab.c"
    break;

  case 23: /* var_decl: type ID LET expr SEMICOLON var_decl  */
#line 206 "./src/scanparse/parser.y"
         {
           (yyval.node) = ASTvardecl((yyvsp[-2].node), (yyvsp[0].node), (yyvsp[-4].id), (yyvsp[-5].ctype));
         }
#line 1597 "parser.tab.c"
    break;

  case 24: /* assign: varlet LET expr SEMICOLON  */
#line 212 "./src/scanparse/parser.y"
        {
          (yyval.node) = ASTassign((yyvsp[-3].node), (yyvsp[-1].node));
        }
#line 1605 "parser.tab.c"
    break;

  case 25: /* assign: type varlet LET expr SEMICOLON  */
#line 217 "./src/scanparse/parser.y"
        {
          (yyval.node) = ASTassign((yyvsp[-3].node), (yyvsp[-1].node));
        }
#line 1613 "parser.tab.c"
    break;

  case 26: /* return_stmt: RETURN expr SEMICOLON  */
#line 223 "./src/scanparse/parser.y"
            {
              (yyval.node) = ASTreturn((yyvsp[-1].node));
            }
#line 1621 "parser.tab.c"
    break;

  case 27: /* return_stmt: RETURN SEMICOLON  */
#line 227 "./src/scanparse/parser.y"
            {
              (yyval.node) = ASTreturn(NULL);
            }
#line 1629 "parser.tab.c"
    break;

  case 28: /* if_stmt: IF expr CURLY_L stmts CURLY_R ELSE CURLY_L stmts CURLY_R  */
#line 233 "./src/scanparse/parser.y"
        {
          (yyval.node) = ASTifelse((yyvsp[-7].node), (yyvsp[-5].node), (yyvsp[-1].node));
        }
#line 1637 "parser.tab.c"
    break;

  case 29: /* if_stmt: IF expr CURLY_L stmts CURLY_R  */
#line 237 "./src/scanparse/parser.y"
        {
          (yyval.node) = ASTifelse((yyvsp[-3].node), (yyvsp[-1].node), NULL);
        }
#line 1645 "parser.tab.c"
    break;

  case 30: /* param: type ID  */
#line 243 "./src/scanparse/parser.y"
        {
          (yyval.node) = ASTparam(NULL, (yyvsp[0].id), (yyvsp[-1].ctype));
        }
#line 1653 "parser.tab.c"
    break;

  case 31: /* param: type ID COMMA param  */
#line 248 "./src/scanparse/parser.y"
        {
          (yyval.node) = ASTparam((yyvsp[0].node), (yyvsp[-2].id), (yyvsp[-3].ctype));
        }
#line 1661 "parser.tab.c"
    break;

  case 32: /* varlet: ID  */
#line 255 "./src/scanparse/parser.y"
        {
          (yyval.node) = ASTvarlet((yyvsp[0].id));
          AddLocToNode((yyval.node), &(yylsp[0]), &(yylsp[0]));
        }
#line 1670 "parser.tab.c"
    break;

  case 33: /* expr: constant  */
#line 263 "./src/scanparse/parser.y"
      {
        (yyval.node) = (yyvsp[0].node);
      }
#line 1678 "parser.tab.c"
    break;

  case 34: /* expr: ID  */
#line 267 "./src/scanparse/parser.y"
      {
        (yyval.node) = ASTvar((yyvsp[0].id));
      }
#line 1686 "parser.tab.c"
    break;

  case 35: /* expr: BRACKET_L expr binop expr BRACKET_R  */
#line 271 "./src/scanparse/parser.y"
      {
        (yyval.node) = ASTbinop( (yyvsp[-3].node), (yyvsp[-1].node), (yyvsp[-2].cbinop));
        AddLocToNode((yyval.node), &(yylsp[-3]), &(yylsp[-1]));
      }
#line 1695 "parser.tab.c"
    break;

  case 36: /* constant: floatval  */
#line 278 "./src/scanparse/parser.y"
          {
            (yyval.node) = (yyvsp[0].node);
          }
#line 1703 "parser.tab.c"
    break;

  case 37: /* constant: intval  */
#line 282 "./src/scanparse/parser.y"
          {
            (yyval.node) = (yyvsp[0].node);
          }
#line 1711 "parser.tab.c"
    break;

  case 38: /* constant: boolval  */
#line 286 "./src/scanparse/parser.y"
          {
            (yyval.node) = (yyvsp[0].node);
          }
#line 1719 "parser.tab.c"
    break;

  case 39: /* type: TYPE_INT  */
#line 291 "./src/scanparse/parser.y"
                 { (yyval.ctype) = CT_int; }
#line 1725 "parser.tab.c"
    break;

  case 40: /* type: TYPE_FLOAT  */
#line 292 "./src/scanparse/parser.y"
                 { (yyval.ctype) = CT_float; }
#line 1731 "parser.tab.c"
    break;

  case 41: /* type: TYPE_BOOL  */
#line 293 "./src/scanparse/parser.y"
                 { (yyval.ctype) = CT_bool; }
#line 1737 "parser.tab.c"
    break;

  case 42: /* type: TYPE_VOID  */
#line 294 "./src/scanparse/parser.y"
                 { (yyval.ctype) = CT_void; }
#line 1743 "parser.tab.c"
    break;

  case 43: /* floatval: FLOAT  */
#line 297 "./src/scanparse/parser.y"
           {
             (yyval.node) = ASTfloat((yyvsp[0].cflt));
           }
#line 1751 "parser.tab.c"
    break;

  case 44: /* intval: NUM  */
#line 303 "./src/scanparse/parser.y"
        {
          (yyval.node) = ASTnum((yyvsp[0].cint));
        }
#line 1759 "parser.tab.c"
    break;

  case 45: /* boolval: TRUEVAL  */
#line 309 "./src/scanparse/parser.y"
         {
           (yyval.node) = ASTbool(true);
         }
#line 1767 "parser.tab.c"
    break;

  case 46: /* boolval: FALSEVAL  */
#line 313 "./src/scanparse/parser.y"
         {
           (yyval.node) = ASTbool(false);
         }
#line 1775 "parser.tab.c"
    break;

  case 47: /* binop: PLUS  */
#line 318 "./src/scanparse/parser.y"
                 { (yyval.cbinop) = BO_add; }
#line 1781 "parser.tab.c"
    break;

  case 48: /* binop: MINUS  */
#line 319 "./src/scanparse/parser.y"
                 { (yyval.cbinop) = BO_sub; }
#line 1787 "parser.tab.c"
    break;

  case 49: /* binop: STAR  */
#line 320 "./src/scanparse/parser.y"
                 { (yyval.cbinop) = BO_mul; }
#line 1793 "parser.tab.c"
    break;

  case 50: /* binop: SLASH  */
#line 321 "./src/scanparse/parser.y"
                 { (yyval.cbinop) = BO_div; }
#line 1799 "parser.tab.c"
    break;

  case 51: /* binop: PERCENT  */
#line 322 "./src/scanparse/parser.y"
                 { (yyval.cbinop) = BO_mod; }
#line 1805 "parser.tab.c"
    break;

  case 52: /* binop: LE  */
#line 323 "./src/scanparse/parser.y"
                 { (yyval.cbinop) = BO_le; }
#line 1811 "parser.tab.c"
    break;

  case 53: /* binop: LT  */
#line 324 "./src/scanparse/parser.y"
                 { (yyval.cbinop) = BO_lt; }
#line 1817 "parser.tab.c"
    break;

  case 54: /* binop: GE  */
#line 325 "./src/scanparse/parser.y"
                 { (yyval.cbinop) = BO_ge; }
#line 1823 "parser.tab.c"
    break;

  case 55: /* binop: GT  */
#line 326 "./src/scanparse/parser.y"
                 { (yyval.cbinop) = BO_gt; }
#line 1829 "parser.tab.c"
    break;

  case 56: /* binop: EQ  */
#line 327 "./src/scanparse/parser.y"
                 { (yyval.cbinop) = BO_eq; }
#line 1835 "parser.tab.c"
    break;

  case 57: /* binop: OR  */
#line 328 "./src/scanparse/parser.y"
                 { (yyval.cbinop) = BO_or; }
#line 1841 "parser.tab.c"
    break;

  case 58: /* binop: AND  */
#line 329 "./src/scanparse/parser.y"
                 { (yyval.cbinop) = BO_and; }
#line 1847 "parser.tab.c"
    break;


#line 1851 "parser.tab.c"

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
  ++yynerrs;

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
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
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

#line 332 "./src/scanparse/parser.y"


void AddLocToNode(node_st *node, void *begin_loc, void *end_loc)
{
    // Needed because YYLTYPE unpacks later than top-level decl.
    YYLTYPE *loc_b = (YYLTYPE*)begin_loc;
    YYLTYPE *loc_e = (YYLTYPE*)end_loc;
    NODE_BLINE(node) = loc_b->first_line;
    NODE_BCOL(node) = loc_b->first_column;
    NODE_ELINE(node) = loc_e->last_line;
    NODE_ECOL(node) = loc_e->last_column;
}

//21-2-2025 Ruben Edited it plus 1 for vs code actual line
// I think indexing starts at 0 
int yyerror(char *error)
{
  CTI(CTI_ERROR, true, "line %d, col %d\nError parsing source code: %s\n",
            global.line + 1, global.col, error);
  CTIabortOnError();
  return 0;
}

// int yyerror(char *error)
// {
//     FILE *input_file = fopen(global.input_file, "r");
//     if (input_file == NULL) {
//         fprintf(stderr, "Cannot open input file '%s' for error reporting.\n", global.input_file);
//         CTIabortOnError();
//         return 0;
//     }

//     // Read the file line by line until we reach the error line
//     char line[256];
//     int current_line = 1;
//     bool error_line_found = false;

//     while (fgets(line, sizeof(line), input_file)) {
//         if (current_line == global.line + 1) { // Adjust line number to match editor's convention
//             // Print the error location
//             fprintf(stderr, "error: line %d, col %d\n", global.line + 1, global.col);

//             // Print the line where the error occurred
//             fprintf(stderr, "%s", line);

//             // Print an indicator (^) under the error column
//             for (int i = 1; i < global.col; i++) {
//                 fprintf(stderr, " ");
//             }
//             fprintf(stderr, "^\n");

//             // Print the error message
//             fprintf(stderr, "Error parsing source code: %s\n", error);

//             error_line_found = true;
//             break;
//         }
//         current_line++;
//     }

//     // Close the file
//     fclose(input_file);

//     if (!error_line_found) {
//         fprintf(stderr, "error: line %d, col %d\n", global.line + 1, global.col);
//         fprintf(stderr, "Error parsing source code: %s\n", error);
//     }

//     CTIabortOnError();
//     return 0;
// }

node_st *SPdoScanParse(node_st *root)
{
    DBUG_ASSERT(root == NULL, "Started parsing with existing syntax tree.");
    yyin = fopen(global.input_file, "r");
    if (yyin == NULL) {
        CTI(CTI_ERROR, true, "Cannot open file '%s'.", global.input_file);
        CTIabortOnError();
    }
    yyparse();
    return parseresult;
}
