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
    WHILE = 293,                   /* WHILE  */
    DO = 294,                      /* DO  */
    FOR = 295,                     /* FOR  */
    EXTERN = 296                   /* EXTERN  */
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

#line 191 "parser.tab.c"

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
  YYSYMBOL_WHILE = 38,                     /* WHILE  */
  YYSYMBOL_DO = 39,                        /* DO  */
  YYSYMBOL_FOR = 40,                       /* FOR  */
  YYSYMBOL_EXTERN = 41,                    /* EXTERN  */
  YYSYMBOL_YYACCEPT = 42,                  /* $accept  */
  YYSYMBOL_program = 43,                   /* program  */
  YYSYMBOL_decls = 44,                     /* decls  */
  YYSYMBOL_decl = 45,                      /* decl  */
  YYSYMBOL_glob_decl = 46,                 /* glob_decl  */
  YYSYMBOL_glob_def = 47,                  /* glob_def  */
  YYSYMBOL_stmts = 48,                     /* stmts  */
  YYSYMBOL_stmt = 49,                      /* stmt  */
  YYSYMBOL_fundef = 50,                    /* fundef  */
  YYSYMBOL_funbody = 51,                   /* funbody  */
  YYSYMBOL_var_decl = 52,                  /* var_decl  */
  YYSYMBOL_assign = 53,                    /* assign  */
  YYSYMBOL_return_stmt = 54,               /* return_stmt  */
  YYSYMBOL_if_stmt = 55,                   /* if_stmt  */
  YYSYMBOL_while_stmt = 56,                /* while_stmt  */
  YYSYMBOL_do_while_stmt = 57,             /* do_while_stmt  */
  YYSYMBOL_for_stmt = 58,                  /* for_stmt  */
  YYSYMBOL_param = 59,                     /* param  */
  YYSYMBOL_varlet = 60,                    /* varlet  */
  YYSYMBOL_args = 61,                      /* args  */
  YYSYMBOL_call = 62,                      /* call  */
  YYSYMBOL_comparison = 63,                /* comparison  */
  YYSYMBOL_expr = 64,                      /* expr  */
  YYSYMBOL_constant = 65,                  /* constant  */
  YYSYMBOL_type = 66,                      /* type  */
  YYSYMBOL_floatval = 67,                  /* floatval  */
  YYSYMBOL_intval = 68,                    /* intval  */
  YYSYMBOL_boolval = 69,                   /* boolval  */
  YYSYMBOL_binop = 70                      /* binop  */
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
#define YYFINAL  16
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   474

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  42
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  29
/* YYNRULES -- Number of rules.  */
#define YYNRULES  83
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  166

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   296


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
      35,    36,    37,    38,    39,    40,    41
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    90,    90,    96,   100,   110,   114,   118,   123,   128,
     132,   136,   140,   145,   149,   157,   158,   159,   160,   161,
     162,   170,   174,   178,   182,   187,   191,   195,   199,   203,
     207,   236,   240,   244,   248,   261,   267,   271,   276,   280,
     285,   289,   294,   298,   306,   315,   324,   333,   341,   346,
     352,   358,   364,   374,   379,   385,   392,   396,   400,   404,
     408,   415,   419,   423,   428,   429,   430,   431,   433,   438,
     443,   447,   453,   454,   455,   456,   457,   458,   459,   460,
     461,   462,   463,   464
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
  "TYPE_VOID", "IF", "ELSE", "WHILE", "DO", "FOR", "EXTERN", "$accept",
  "program", "decls", "decl", "glob_decl", "glob_def", "stmts", "stmt",
  "fundef", "funbody", "var_decl", "assign", "return_stmt", "if_stmt",
  "while_stmt", "do_while_stmt", "for_stmt", "param", "varlet", "args",
  "call", "comparison", "expr", "constant", "type", "floatval", "intval",
  "boolval", "binop", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-76)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-51)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     433,   -16,   -76,   -76,   -76,   -76,   -16,    11,   -76,   433,
     -76,   -76,   -76,   -15,    -3,    -2,   -76,   -76,    18,    19,
      22,     8,   -76,   199,    16,   -76,   199,   -76,    23,    25,
       7,   199,   -76,   -76,   -76,   -76,    54,   -76,   -76,   308,
     -76,   -76,   -76,   -76,    23,    58,   323,    31,   -76,    23,
      69,    71,   439,    73,   -76,   -76,   -76,   -76,   -76,   -76,
     -76,   -76,   -76,   -76,   -76,   -76,   -76,   199,   -76,    23,
     -76,   -76,    28,   199,   199,    72,    75,    53,   182,    85,
     -76,   -76,   -76,   -76,   -76,    56,   338,    57,   -76,   -16,
     -76,   -76,    79,   277,   439,   -76,   412,   426,   108,   -16,
     -76,   125,    81,   -76,   -76,    60,   199,   -76,     9,   -76,
     -76,   199,   182,   135,    66,    84,    65,   -76,   353,   -76,
     -76,    87,   368,   -76,   199,   -76,    88,   -76,    97,   199,
      68,    89,   -76,   -76,   -76,   261,    70,   -76,   383,   199,
     199,   -76,   -16,   110,   -76,   398,   293,   -76,   182,   -76,
     199,   112,   225,   -76,   115,   199,   153,   242,   -76,   118,
     120,   -76,   176,   -76,   122,   -76
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,    64,    65,    66,    67,     0,     0,     2,     4,
       5,     7,     6,     0,     0,     0,     1,     3,     0,     0,
       0,     0,    12,     0,     0,    11,     0,     8,     0,     0,
       0,     0,    70,    71,    69,    68,    57,    58,    59,     0,
      56,    61,    62,    63,     0,     0,     0,     0,    24,     0,
      48,    59,     0,     0,    10,    73,    72,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,     0,    22,     0,
       9,    28,    57,     0,     0,     0,     0,     0,    14,     0,
      15,    16,    17,    18,    19,     0,     0,     0,    23,     0,
      60,    54,     0,    51,    55,    21,     0,     0,     0,     0,
      30,     0,     0,    13,    29,     0,     0,    20,     0,    49,
      53,     0,     0,     0,     0,     0,     0,    37,     0,    26,
      27,     0,     0,    31,     0,    52,     0,    41,     0,     0,
       0,     0,    36,    25,    35,     0,    39,    40,     0,     0,
       0,    33,    32,     0,    43,     0,     0,    34,     0,    42,
       0,     0,     0,    38,     0,     0,     0,     0,    44,     0,
       0,    46,     0,    45,     0,    47
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -76,   -76,   130,   -76,   -76,   -76,   -75,   -76,   -76,   -36,
      -1,   -76,    35,   -76,   -76,   -76,   -76,   -17,   -76,    34,
     -76,   124,   -21,   -76,     0,   -76,   -76,   -76,   -76
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     7,     8,     9,    10,    11,    77,    78,    12,    48,
      79,    80,   102,    81,    82,    83,    84,    29,    85,    92,
      37,    38,    86,    40,    30,    41,    42,    43,    67
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      13,    14,    39,   103,   105,    46,    15,    45,    68,    13,
      52,    16,    28,    88,    18,   123,     2,     3,     4,     5,
      44,    21,    24,   115,    22,    25,    19,    20,    27,    49,
      47,    53,    93,    95,    31,   124,    50,   126,   128,    71,
       2,     3,     4,     5,    23,    26,    94,    87,     2,     3,
       4,     5,    96,    97,   -50,    32,    33,    53,    34,    35,
      72,   100,    69,     2,     3,     4,     5,    73,   120,    74,
      75,    76,   109,   151,    89,    90,    31,    91,    99,    98,
     118,   159,   106,   110,   101,   122,   108,   164,    31,   119,
      93,   101,   130,   104,   131,   133,   136,    32,    33,   116,
      34,    35,    36,   135,   129,   137,   139,   143,   138,    32,
      33,    31,    34,    35,    72,   140,   114,   148,   145,   146,
     153,    73,   156,    74,    75,    76,   161,   162,    31,   152,
     165,   117,    32,    33,   157,    34,    35,    72,    31,    17,
     121,   147,    87,   127,    73,   125,    74,    75,    76,    32,
      33,     0,    34,    35,    36,    51,    31,     0,     0,    32,
      33,   158,    34,    35,    72,     0,     0,     0,     0,     0,
       0,    73,     0,    74,    75,    76,     0,    32,    33,    31,
      34,    35,    72,     0,   163,    31,     0,     0,     0,    73,
       0,    74,    75,    76,     0,     0,     0,     0,     0,     0,
      32,    33,    31,    34,    35,    72,    32,    33,     0,    34,
      35,    72,    73,     0,    74,    75,    76,     0,    73,     0,
      74,    75,    76,    32,    33,     0,    34,    35,    36,   154,
     155,     0,     0,     0,     0,     0,    55,    56,    57,    58,
      59,    60,    61,    62,    63,    64,   160,    65,    66,     0,
       0,     0,     0,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,     0,    65,    66,   141,   142,     0,     0,
       0,     0,    55,    56,    57,    58,    59,    60,    61,    62,
      63,    64,   111,    65,    66,     0,     0,     0,    55,    56,
      57,    58,    59,    60,    61,    62,    63,    64,   150,    65,
      66,     0,     0,     0,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    54,    65,    66,     0,     0,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    70,
      65,    66,     0,     0,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,   107,    65,    66,     0,     0,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,   132,
      65,    66,     0,     0,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,   134,    65,    66,     0,     0,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,   144,
      65,    66,     0,     0,    55,    56,    57,    58,    59,    60,
      61,    62,    63,    64,   149,    65,    66,     0,     0,    55,
      56,    57,    58,    59,    60,    61,    62,    63,    64,   112,
      65,    66,     0,    55,    56,    57,    58,    59,    60,    61,
      62,    63,    64,   113,    65,    66,     0,    55,    56,    57,
      58,    59,    60,    61,    62,    63,    64,     0,    65,    66,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
       0,    65,    66,     1,     0,     2,     3,     4,     5,     0,
       0,     0,     0,     0,     6
};

static const yytype_int16 yycheck[] =
{
       0,     1,    23,    78,    79,    26,     6,    24,    44,     9,
      31,     0,     4,    49,    29,     6,    32,    33,    34,    35,
       4,     3,     3,    98,     6,     6,    29,    29,     6,     4,
       7,     3,    53,    69,     3,    26,    29,   112,   113,     8,
      32,    33,    34,    35,    26,    26,    67,    47,    32,    33,
      34,    35,    73,    74,    26,    24,    25,     3,    27,    28,
      29,     8,     4,    32,    33,    34,    35,    36,     8,    38,
      39,    40,    89,   148,     5,     4,     3,     4,     3,     7,
     101,   156,    26,     4,    31,   106,    29,   162,     3,     8,
     111,    31,     8,     8,    29,     8,     8,    24,    25,    99,
      27,    28,    29,   124,    38,     8,    38,    37,   129,    24,
      25,     3,    27,    28,    29,    26,     8,     7,   139,   140,
       8,    36,     7,    38,    39,    40,     8,     7,     3,   150,
       8,     6,    24,    25,   155,    27,    28,    29,     3,     9,
     105,   142,   142,     8,    36,   111,    38,    39,    40,    24,
      25,    -1,    27,    28,    29,    31,     3,    -1,    -1,    24,
      25,     8,    27,    28,    29,    -1,    -1,    -1,    -1,    -1,
      -1,    36,    -1,    38,    39,    40,    -1,    24,    25,     3,
      27,    28,    29,    -1,     8,     3,    -1,    -1,    -1,    36,
      -1,    38,    39,    40,    -1,    -1,    -1,    -1,    -1,    -1,
      24,    25,     3,    27,    28,    29,    24,    25,    -1,    27,
      28,    29,    36,    -1,    38,    39,    40,    -1,    36,    -1,
      38,    39,    40,    24,    25,    -1,    27,    28,    29,     4,
       5,    -1,    -1,    -1,    -1,    -1,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,     4,    22,    23,    -1,
      -1,    -1,    -1,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    -1,    22,    23,     5,     6,    -1,    -1,
      -1,    -1,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,     5,    22,    23,    -1,    -1,    -1,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,     5,    22,
      23,    -1,    -1,    -1,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,     6,    22,    23,    -1,    -1,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,     6,
      22,    23,    -1,    -1,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,     6,    22,    23,    -1,    -1,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,     6,
      22,    23,    -1,    -1,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,     6,    22,    23,    -1,    -1,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,     6,
      22,    23,    -1,    -1,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,     6,    22,    23,    -1,    -1,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,     7,
      22,    23,    -1,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,     7,    22,    23,    -1,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    -1,    22,    23,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      -1,    22,    23,    30,    -1,    32,    33,    34,    35,    -1,
      -1,    -1,    -1,    -1,    41
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    30,    32,    33,    34,    35,    41,    43,    44,    45,
      46,    47,    50,    66,    66,    66,     0,    44,    29,    29,
      29,     3,     6,    26,     3,     6,    26,     6,     4,    59,
      66,     3,    24,    25,    27,    28,    29,    62,    63,    64,
      65,    67,    68,    69,     4,    59,    64,     7,    51,     4,
      29,    63,    64,     3,     6,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    22,    23,    70,    51,     4,
       6,     8,    29,    36,    38,    39,    40,    48,    49,    52,
      53,    55,    56,    57,    58,    60,    64,    66,    51,     5,
       4,     4,    61,    64,    64,    51,    64,    64,     7,     3,
       8,    31,    54,    48,     8,    48,    26,     6,    29,    59,
       4,     5,     7,     7,     8,    48,    66,     6,    64,     8,
       8,    54,    64,     6,    26,    61,    48,     8,    48,    38,
       8,    29,     6,     8,     6,    64,     8,     8,    64,    38,
      26,     5,     6,    37,     6,    64,    64,    52,     7,     6,
       5,    48,    64,     8,     4,     5,     7,    64,     8,    48,
       4,     8,     7,     8,    48,     8
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    42,    43,    44,    44,    45,    45,    45,    46,    47,
      47,    47,    47,    48,    48,    49,    49,    49,    49,    49,
      49,    50,    50,    50,    50,    51,    51,    51,    51,    51,
      51,    52,    52,    52,    52,    53,    54,    54,    55,    55,
      56,    56,    57,    57,    58,    58,    58,    58,    59,    59,
      60,    61,    61,    62,    62,    63,    64,    64,    64,    64,
      64,    65,    65,    65,    66,    66,    66,    66,    67,    68,
      69,    69,    70,    70,    70,    70,    70,    70,    70,    70,
      70,    70,    70,    70
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     1,     1,     4,     6,
       5,     4,     3,     2,     1,     1,     1,     1,     1,     1,
       2,     7,     6,     6,     5,     5,     4,     4,     2,     3,
       3,     3,     5,     5,     6,     4,     3,     2,     9,     5,
       5,     4,     7,     6,    11,    13,    12,    14,     2,     4,
       1,     1,     3,     4,     3,     3,     1,     1,     1,     1,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1
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
#line 91 "./src/scanparse/parser.y"
        {
		parseresult = ASTprogram((yyvsp[0].node));
	}
#line 1541 "parser.tab.c"
    break;

  case 3: /* decls: decl decls  */
#line 97 "./src/scanparse/parser.y"
        {
		(yyval.node) = ASTdecls((yyvsp[-1].node), (yyvsp[0].node));
	}
#line 1549 "parser.tab.c"
    break;

  case 4: /* decls: decl  */
#line 101 "./src/scanparse/parser.y"
        {
		(yyval.node) = ASTdecls((yyvsp[0].node), NULL);
	}
#line 1557 "parser.tab.c"
    break;

  case 5: /* decl: glob_decl  */
#line 111 "./src/scanparse/parser.y"
  {
    (yyval.node) = (yyvsp[0].node);
  }
#line 1565 "parser.tab.c"
    break;

  case 6: /* decl: fundef  */
#line 115 "./src/scanparse/parser.y"
  {
    (yyval.node) = (yyvsp[0].node);
  }
#line 1573 "parser.tab.c"
    break;

  case 7: /* decl: glob_def  */
#line 119 "./src/scanparse/parser.y"
  {
    (yyval.node) = (yyvsp[0].node);
  }
#line 1581 "parser.tab.c"
    break;

  case 8: /* glob_decl: EXTERN type ID SEMICOLON  */
#line 124 "./src/scanparse/parser.y"
  {
    (yyval.node) = ASTglobdecl((yyvsp[-1].id), (yyvsp[-2].ctype));
  }
#line 1589 "parser.tab.c"
    break;

  case 9: /* glob_def: EXPORT type ID LET expr SEMICOLON  */
#line 129 "./src/scanparse/parser.y"
  {
    (yyval.node) = ASTglobdef((yyvsp[-1].node), (yyvsp[-3].id), (yyvsp[-4].ctype), true);
  }
#line 1597 "parser.tab.c"
    break;

  case 10: /* glob_def: type ID LET expr SEMICOLON  */
#line 133 "./src/scanparse/parser.y"
  {
    (yyval.node) = ASTglobdef((yyvsp[-1].node), (yyvsp[-3].id), (yyvsp[-4].ctype), false);
  }
#line 1605 "parser.tab.c"
    break;

  case 11: /* glob_def: EXPORT type ID SEMICOLON  */
#line 137 "./src/scanparse/parser.y"
  {
    (yyval.node) = ASTglobdef(NULL, (yyvsp[-1].id), (yyvsp[-2].ctype), true);
  }
#line 1613 "parser.tab.c"
    break;

  case 12: /* glob_def: type ID SEMICOLON  */
#line 141 "./src/scanparse/parser.y"
  {
    (yyval.node) = ASTglobdef(NULL, (yyvsp[-1].id), (yyvsp[-2].ctype), true);
  }
#line 1621 "parser.tab.c"
    break;

  case 13: /* stmts: stmt stmts  */
#line 146 "./src/scanparse/parser.y"
  {
    (yyval.node) = ASTstmts((yyvsp[-1].node), (yyvsp[0].node));
  }
#line 1629 "parser.tab.c"
    break;

  case 14: /* stmts: stmt  */
#line 150 "./src/scanparse/parser.y"
  {
    (yyval.node) = ASTstmts((yyvsp[0].node), NULL);
  }
#line 1637 "parser.tab.c"
    break;

  case 15: /* stmt: assign  */
#line 157 "./src/scanparse/parser.y"
             { (yyval.node) = (yyvsp[0].node); }
#line 1643 "parser.tab.c"
    break;

  case 16: /* stmt: if_stmt  */
#line 158 "./src/scanparse/parser.y"
              { (yyval.node) = (yyvsp[0].node); }
#line 1649 "parser.tab.c"
    break;

  case 17: /* stmt: while_stmt  */
#line 159 "./src/scanparse/parser.y"
                 { (yyval.node) = (yyvsp[0].node); }
#line 1655 "parser.tab.c"
    break;

  case 18: /* stmt: do_while_stmt  */
#line 160 "./src/scanparse/parser.y"
                    { (yyval.node) = (yyvsp[0].node); }
#line 1661 "parser.tab.c"
    break;

  case 19: /* stmt: for_stmt  */
#line 161 "./src/scanparse/parser.y"
               { (yyval.node) = (yyvsp[0].node); }
#line 1667 "parser.tab.c"
    break;

  case 20: /* stmt: expr SEMICOLON  */
#line 162 "./src/scanparse/parser.y"
                     { (yyval.node) = ASTexprstmt((yyvsp[-1].node)); 
}
#line 1674 "parser.tab.c"
    break;

  case 21: /* fundef: EXPORT type ID BRACKET_L param BRACKET_R funbody  */
#line 171 "./src/scanparse/parser.y"
  {
    (yyval.node) = ASTfundef((yyvsp[0].node), (yyvsp[-2].node), (yyvsp[-4].id), (yyvsp[-5].ctype), true); // Exported function
  }
#line 1682 "parser.tab.c"
    break;

  case 22: /* fundef: EXPORT type ID BRACKET_L BRACKET_R funbody  */
#line 175 "./src/scanparse/parser.y"
  {
    (yyval.node) = ASTfundef((yyvsp[0].node), NULL, (yyvsp[-3].id), (yyvsp[-4].ctype), true);
  }
#line 1690 "parser.tab.c"
    break;

  case 23: /* fundef: type ID BRACKET_L param BRACKET_R funbody  */
#line 179 "./src/scanparse/parser.y"
  {
    (yyval.node) = ASTfundef((yyvsp[0].node), (yyvsp[-2].node), (yyvsp[-4].id), (yyvsp[-5].ctype), false); // Non-exported function
  }
#line 1698 "parser.tab.c"
    break;

  case 24: /* fundef: type ID BRACKET_L BRACKET_R funbody  */
#line 183 "./src/scanparse/parser.y"
  {
    (yyval.node) = ASTfundef((yyvsp[0].node), NULL, (yyvsp[-3].id), (yyvsp[-4].ctype), false);
  }
#line 1706 "parser.tab.c"
    break;

  case 25: /* funbody: CURLY_L var_decl stmts return_stmt CURLY_R  */
#line 188 "./src/scanparse/parser.y"
  {
    (yyval.node) = ASTfunbody((yyvsp[-3].node), NULL, ASTstmts((yyvsp[-2].node), (yyvsp[-1].node)));
  }
#line 1714 "parser.tab.c"
    break;

  case 26: /* funbody: CURLY_L stmts return_stmt CURLY_R  */
#line 192 "./src/scanparse/parser.y"
  {
    (yyval.node) = ASTfunbody(NULL, NULL, ASTstmts((yyvsp[-2].node), (yyvsp[-1].node)));
  }
#line 1722 "parser.tab.c"
    break;

  case 27: /* funbody: CURLY_L var_decl stmts CURLY_R  */
#line 196 "./src/scanparse/parser.y"
  {
    (yyval.node) = ASTfunbody((yyvsp[-2].node), NULL, (yyvsp[-1].node));
  }
#line 1730 "parser.tab.c"
    break;

  case 28: /* funbody: CURLY_L CURLY_R  */
#line 200 "./src/scanparse/parser.y"
  {
    (yyval.node) = ASTfunbody(NULL, NULL, NULL);
  }
#line 1738 "parser.tab.c"
    break;

  case 29: /* funbody: CURLY_L var_decl CURLY_R  */
#line 204 "./src/scanparse/parser.y"
  {
    (yyval.node) = ASTfunbody((yyvsp[-1].node), NULL, NULL);
  }
#line 1746 "parser.tab.c"
    break;

  case 30: /* funbody: CURLY_L stmts CURLY_R  */
#line 208 "./src/scanparse/parser.y"
  {
    (yyval.node) = ASTfunbody(NULL, NULL, (yyvsp[-1].node));
  }
#line 1754 "parser.tab.c"
    break;

  case 31: /* var_decl: type ID SEMICOLON  */
#line 237 "./src/scanparse/parser.y"
  {
    (yyval.node) = ASTvardecl(NULL, NULL, (yyvsp[-1].id), (yyvsp[-2].ctype));
  }
#line 1762 "parser.tab.c"
    break;

  case 32: /* var_decl: type ID LET expr SEMICOLON  */
#line 241 "./src/scanparse/parser.y"
  {
    (yyval.node) = ASTvardecl((yyvsp[-1].node), NULL, (yyvsp[-3].id), (yyvsp[-4].ctype));
  }
#line 1770 "parser.tab.c"
    break;

  case 33: /* var_decl: type ID LET expr COMMA  */
#line 245 "./src/scanparse/parser.y"
  {
    (yyval.node) = ASTvardecl((yyvsp[-1].node), NULL, (yyvsp[-3].id), (yyvsp[-4].ctype));
  }
#line 1778 "parser.tab.c"
    break;

  case 34: /* var_decl: type ID LET expr SEMICOLON var_decl  */
#line 249 "./src/scanparse/parser.y"
  {
    (yyval.node) = ASTvardecl((yyvsp[-2].node), (yyvsp[0].node), (yyvsp[-4].id), (yyvsp[-5].ctype));
  }
#line 1786 "parser.tab.c"
    break;

  case 35: /* assign: varlet LET expr SEMICOLON  */
#line 262 "./src/scanparse/parser.y"
{
  (yyval.node) = ASTassign((yyvsp[-3].node), (yyvsp[-1].node));
}
#line 1794 "parser.tab.c"
    break;

  case 36: /* return_stmt: RETURN expr SEMICOLON  */
#line 268 "./src/scanparse/parser.y"
  {
    (yyval.node) = ASTreturn((yyvsp[-1].node));
  }
#line 1802 "parser.tab.c"
    break;

  case 37: /* return_stmt: RETURN SEMICOLON  */
#line 272 "./src/scanparse/parser.y"
  {
    (yyval.node) = ASTreturn(NULL);
  }
#line 1810 "parser.tab.c"
    break;

  case 38: /* if_stmt: IF expr CURLY_L stmts CURLY_R ELSE CURLY_L stmts CURLY_R  */
#line 277 "./src/scanparse/parser.y"
  {
    (yyval.node) = ASTifelse((yyvsp[-7].node), (yyvsp[-5].node), (yyvsp[-1].node));
  }
#line 1818 "parser.tab.c"
    break;

  case 39: /* if_stmt: IF expr CURLY_L stmts CURLY_R  */
#line 281 "./src/scanparse/parser.y"
  {
    (yyval.node) = ASTifelse((yyvsp[-3].node), (yyvsp[-1].node), NULL);
  }
#line 1826 "parser.tab.c"
    break;

  case 40: /* while_stmt: WHILE expr CURLY_L stmts CURLY_R  */
#line 286 "./src/scanparse/parser.y"
  {
    (yyval.node) = ASTwhile((yyvsp[-3].node), (yyvsp[-1].node));
  }
#line 1834 "parser.tab.c"
    break;

  case 41: /* while_stmt: WHILE expr CURLY_L CURLY_R  */
#line 290 "./src/scanparse/parser.y"
  {
    (yyval.node) = ASTwhile((yyvsp[-2].node), NULL);
  }
#line 1842 "parser.tab.c"
    break;

  case 42: /* do_while_stmt: DO CURLY_L stmts CURLY_R WHILE expr SEMICOLON  */
#line 295 "./src/scanparse/parser.y"
  {
    (yyval.node) = ASTdowhile((yyvsp[-1].node), (yyvsp[-4].node));
  }
#line 1850 "parser.tab.c"
    break;

  case 43: /* do_while_stmt: DO CURLY_L CURLY_R WHILE expr SEMICOLON  */
#line 299 "./src/scanparse/parser.y"
  {
    (yyval.node) = ASTdowhile((yyvsp[-1].node), NULL);
  }
#line 1858 "parser.tab.c"
    break;

  case 44: /* for_stmt: FOR BRACKET_L type ID LET expr COMMA expr BRACKET_R CURLY_L CURLY_R  */
#line 307 "./src/scanparse/parser.y"
  {
    // printf("no step size, default to 1, no statements\n");
    (yyval.node) = ASTfor((yyvsp[-5].node), (yyvsp[-3].node), ASTnum(1), NULL);
        free((yyvsp[-7].id));

  }
#line 1869 "parser.tab.c"
    break;

  case 45: /* for_stmt: FOR BRACKET_L type ID LET expr COMMA expr COMMA expr BRACKET_R CURLY_L CURLY_R  */
#line 316 "./src/scanparse/parser.y"
  {
    printf("with step size, no statements\n");
    (yyval.node) = ASTfor((yyvsp[-7].node), (yyvsp[-5].node), (yyvsp[-3].node), NULL);
        free((yyvsp[-9].id));

  }
#line 1880 "parser.tab.c"
    break;

  case 46: /* for_stmt: FOR BRACKET_L type ID LET expr COMMA expr BRACKET_R CURLY_L stmts CURLY_R  */
#line 325 "./src/scanparse/parser.y"
  {
    printf("no step size, default to 1, with statements\n");
    (yyval.node) = ASTfor((yyvsp[-6].node), (yyvsp[-4].node), ASTnum(1), (yyvsp[-1].node));
        free((yyvsp[-8].id));

  }
#line 1891 "parser.tab.c"
    break;

  case 47: /* for_stmt: FOR BRACKET_L type ID LET expr COMMA expr COMMA expr BRACKET_R CURLY_L stmts CURLY_R  */
#line 334 "./src/scanparse/parser.y"
  {
    // printf("with step size, with statements\n");
    (yyval.node) = ASTfor((yyvsp[-8].node), (yyvsp[-6].node), (yyvsp[-4].node), (yyvsp[-1].node));
        free((yyvsp[-10].id));
  }
#line 1901 "parser.tab.c"
    break;

  case 48: /* param: type ID  */
#line 342 "./src/scanparse/parser.y"
  {
    (yyval.node) = ASTparam(NULL, (yyvsp[0].id), (yyvsp[-1].ctype));
  }
#line 1909 "parser.tab.c"
    break;

  case 49: /* param: type ID COMMA param  */
#line 347 "./src/scanparse/parser.y"
  {
    (yyval.node) = ASTparam((yyvsp[0].node), (yyvsp[-2].id), (yyvsp[-3].ctype));
  }
#line 1917 "parser.tab.c"
    break;

  case 50: /* varlet: ID  */
#line 353 "./src/scanparse/parser.y"
  {
    (yyval.node) = ASTvarlet((yyvsp[0].id));
    AddLocToNode((yyval.node), &(yylsp[0]), &(yylsp[0]));
  }
#line 1926 "parser.tab.c"
    break;

  case 51: /* args: expr  */
#line 360 "./src/scanparse/parser.y"
  {
    (yyval.node) = ASTexprs((yyvsp[0].node), NULL); 
  }
#line 1934 "parser.tab.c"
    break;

  case 52: /* args: expr COMMA args  */
#line 365 "./src/scanparse/parser.y"
  {
    (yyval.node) = ASTexprs((yyvsp[-2].node), (yyvsp[0].node));
  }
#line 1942 "parser.tab.c"
    break;

  case 53: /* call: ID BRACKET_L args BRACKET_R  */
#line 375 "./src/scanparse/parser.y"
  {
    (yyval.node) = ASTfuncall((yyvsp[-1].node), (yyvsp[-3].id));
  }
#line 1950 "parser.tab.c"
    break;

  case 54: /* call: ID BRACKET_L BRACKET_R  */
#line 380 "./src/scanparse/parser.y"
  {
    (yyval.node) = ASTfuncall(NULL, (yyvsp[-2].id));
  }
#line 1958 "parser.tab.c"
    break;

  case 55: /* comparison: expr binop expr  */
#line 386 "./src/scanparse/parser.y"
      {
        (yyval.node) = ASTbinop( (yyvsp[-2].node), (yyvsp[0].node), (yyvsp[-1].cbinop));
        AddLocToNode((yyval.node), &(yylsp[-2]), &(yylsp[0]));
      }
#line 1967 "parser.tab.c"
    break;

  case 56: /* expr: constant  */
#line 393 "./src/scanparse/parser.y"
      {
        (yyval.node) = (yyvsp[0].node);
      }
#line 1975 "parser.tab.c"
    break;

  case 57: /* expr: ID  */
#line 397 "./src/scanparse/parser.y"
      {
        (yyval.node) = ASTvar((yyvsp[0].id));
      }
#line 1983 "parser.tab.c"
    break;

  case 58: /* expr: call  */
#line 401 "./src/scanparse/parser.y"
      {
        (yyval.node) = (yyvsp[0].node);
      }
#line 1991 "parser.tab.c"
    break;

  case 59: /* expr: comparison  */
#line 405 "./src/scanparse/parser.y"
      {
        (yyval.node) = (yyvsp[0].node);
      }
#line 1999 "parser.tab.c"
    break;

  case 60: /* expr: BRACKET_L comparison BRACKET_R  */
#line 409 "./src/scanparse/parser.y"
      {
        (yyval.node) = (yyvsp[-1].node);
      }
#line 2007 "parser.tab.c"
    break;

  case 61: /* constant: floatval  */
#line 416 "./src/scanparse/parser.y"
  {
    (yyval.node) = (yyvsp[0].node);
  }
#line 2015 "parser.tab.c"
    break;

  case 62: /* constant: intval  */
#line 420 "./src/scanparse/parser.y"
  {
    (yyval.node) = (yyvsp[0].node);
  }
#line 2023 "parser.tab.c"
    break;

  case 63: /* constant: boolval  */
#line 424 "./src/scanparse/parser.y"
  {
    (yyval.node) = (yyvsp[0].node);
  }
#line 2031 "parser.tab.c"
    break;

  case 64: /* type: TYPE_INT  */
#line 428 "./src/scanparse/parser.y"
                 { (yyval.ctype) = CT_int; }
#line 2037 "parser.tab.c"
    break;

  case 65: /* type: TYPE_FLOAT  */
#line 429 "./src/scanparse/parser.y"
                 { (yyval.ctype) = CT_float; }
#line 2043 "parser.tab.c"
    break;

  case 66: /* type: TYPE_BOOL  */
#line 430 "./src/scanparse/parser.y"
                 { (yyval.ctype) = CT_bool; }
#line 2049 "parser.tab.c"
    break;

  case 67: /* type: TYPE_VOID  */
#line 431 "./src/scanparse/parser.y"
                 { (yyval.ctype) = CT_void; }
#line 2055 "parser.tab.c"
    break;

  case 68: /* floatval: FLOAT  */
#line 434 "./src/scanparse/parser.y"
  {
    (yyval.node) = ASTfloat((yyvsp[0].cflt));
  }
#line 2063 "parser.tab.c"
    break;

  case 69: /* intval: NUM  */
#line 439 "./src/scanparse/parser.y"
  {
    (yyval.node) = ASTnum((yyvsp[0].cint));
  }
#line 2071 "parser.tab.c"
    break;

  case 70: /* boolval: TRUEVAL  */
#line 444 "./src/scanparse/parser.y"
  {
    (yyval.node) = ASTbool(true);
  }
#line 2079 "parser.tab.c"
    break;

  case 71: /* boolval: FALSEVAL  */
#line 448 "./src/scanparse/parser.y"
  {
    (yyval.node) = ASTbool(false);
  }
#line 2087 "parser.tab.c"
    break;

  case 72: /* binop: PLUS  */
#line 453 "./src/scanparse/parser.y"
                 { (yyval.cbinop) = BO_add; }
#line 2093 "parser.tab.c"
    break;

  case 73: /* binop: MINUS  */
#line 454 "./src/scanparse/parser.y"
                 { (yyval.cbinop) = BO_sub; }
#line 2099 "parser.tab.c"
    break;

  case 74: /* binop: STAR  */
#line 455 "./src/scanparse/parser.y"
                 { (yyval.cbinop) = BO_mul; }
#line 2105 "parser.tab.c"
    break;

  case 75: /* binop: SLASH  */
#line 456 "./src/scanparse/parser.y"
                 { (yyval.cbinop) = BO_div; }
#line 2111 "parser.tab.c"
    break;

  case 76: /* binop: PERCENT  */
#line 457 "./src/scanparse/parser.y"
                 { (yyval.cbinop) = BO_mod; }
#line 2117 "parser.tab.c"
    break;

  case 77: /* binop: LE  */
#line 458 "./src/scanparse/parser.y"
                 { (yyval.cbinop) = BO_le; }
#line 2123 "parser.tab.c"
    break;

  case 78: /* binop: LT  */
#line 459 "./src/scanparse/parser.y"
                 { (yyval.cbinop) = BO_lt; }
#line 2129 "parser.tab.c"
    break;

  case 79: /* binop: GE  */
#line 460 "./src/scanparse/parser.y"
                 { (yyval.cbinop) = BO_ge; }
#line 2135 "parser.tab.c"
    break;

  case 80: /* binop: GT  */
#line 461 "./src/scanparse/parser.y"
                 { (yyval.cbinop) = BO_gt; }
#line 2141 "parser.tab.c"
    break;

  case 81: /* binop: EQ  */
#line 462 "./src/scanparse/parser.y"
                 { (yyval.cbinop) = BO_eq; }
#line 2147 "parser.tab.c"
    break;

  case 82: /* binop: OR  */
#line 463 "./src/scanparse/parser.y"
                 { (yyval.cbinop) = BO_or; }
#line 2153 "parser.tab.c"
    break;

  case 83: /* binop: AND  */
#line 464 "./src/scanparse/parser.y"
                 { (yyval.cbinop) = BO_and; }
#line 2159 "parser.tab.c"
    break;


#line 2163 "parser.tab.c"

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

#line 467 "./src/scanparse/parser.y"


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
