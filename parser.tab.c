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
  node_st *generate_indices(node_st *length_node);



#line 95 "parser.tab.c"

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
    CAST = 258,                    /* CAST  */
    BRACKET_L = 259,               /* BRACKET_L  */
    BRACKET_R = 260,               /* BRACKET_R  */
    COMMA = 261,                   /* COMMA  */
    SEMICOLON = 262,               /* SEMICOLON  */
    CURLY_L = 263,                 /* CURLY_L  */
    CURLY_R = 264,                 /* CURLY_R  */
    SQUARE_L = 265,                /* SQUARE_L  */
    SQUARE_R = 266,                /* SQUARE_R  */
    MINUS = 267,                   /* MINUS  */
    PLUS = 268,                    /* PLUS  */
    STAR = 269,                    /* STAR  */
    SLASH = 270,                   /* SLASH  */
    PERCENT = 271,                 /* PERCENT  */
    LE = 272,                      /* LE  */
    LT = 273,                      /* LT  */
    GE = 274,                      /* GE  */
    GT = 275,                      /* GT  */
    EQ = 276,                      /* EQ  */
    NE = 277,                      /* NE  */
    OR = 278,                      /* OR  */
    AND = 279,                     /* AND  */
    PLUSEQ = 280,                  /* PLUSEQ  */
    MINUSEQ = 281,                 /* MINUSEQ  */
    STAREQ = 282,                  /* STAREQ  */
    SLASHEQ = 283,                 /* SLASHEQ  */
    PERCENTEQ = 284,               /* PERCENTEQ  */
    TRUEVAL = 285,                 /* TRUEVAL  */
    FALSEVAL = 286,                /* FALSEVAL  */
    LET = 287,                     /* LET  */
    NUM = 288,                     /* NUM  */
    FLOAT = 289,                   /* FLOAT  */
    ID = 290,                      /* ID  */
    EXPORT = 291,                  /* EXPORT  */
    RETURN = 292,                  /* RETURN  */
    TYPE_INT = 293,                /* TYPE_INT  */
    TYPE_FLOAT = 294,              /* TYPE_FLOAT  */
    TYPE_BOOL = 295,               /* TYPE_BOOL  */
    TYPE_VOID = 296,               /* TYPE_VOID  */
    IF = 297,                      /* IF  */
    ELSE = 298,                    /* ELSE  */
    WHILE = 299,                   /* WHILE  */
    DO = 300,                      /* DO  */
    FOR = 301,                     /* FOR  */
    EXTERN = 302                   /* EXTERN  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 25 "./src/scanparse/parser.y"

	 char               *id;
	 int                 cint;
	 float               cflt;
	 enum BinOpType     cbinop;
	 enum Type           ctype;
	 node_st             *node;

#line 198 "parser.tab.c"

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
  YYSYMBOL_CAST = 3,                       /* CAST  */
  YYSYMBOL_BRACKET_L = 4,                  /* BRACKET_L  */
  YYSYMBOL_BRACKET_R = 5,                  /* BRACKET_R  */
  YYSYMBOL_COMMA = 6,                      /* COMMA  */
  YYSYMBOL_SEMICOLON = 7,                  /* SEMICOLON  */
  YYSYMBOL_CURLY_L = 8,                    /* CURLY_L  */
  YYSYMBOL_CURLY_R = 9,                    /* CURLY_R  */
  YYSYMBOL_SQUARE_L = 10,                  /* SQUARE_L  */
  YYSYMBOL_SQUARE_R = 11,                  /* SQUARE_R  */
  YYSYMBOL_MINUS = 12,                     /* MINUS  */
  YYSYMBOL_PLUS = 13,                      /* PLUS  */
  YYSYMBOL_STAR = 14,                      /* STAR  */
  YYSYMBOL_SLASH = 15,                     /* SLASH  */
  YYSYMBOL_PERCENT = 16,                   /* PERCENT  */
  YYSYMBOL_LE = 17,                        /* LE  */
  YYSYMBOL_LT = 18,                        /* LT  */
  YYSYMBOL_GE = 19,                        /* GE  */
  YYSYMBOL_GT = 20,                        /* GT  */
  YYSYMBOL_EQ = 21,                        /* EQ  */
  YYSYMBOL_NE = 22,                        /* NE  */
  YYSYMBOL_OR = 23,                        /* OR  */
  YYSYMBOL_AND = 24,                       /* AND  */
  YYSYMBOL_PLUSEQ = 25,                    /* PLUSEQ  */
  YYSYMBOL_MINUSEQ = 26,                   /* MINUSEQ  */
  YYSYMBOL_STAREQ = 27,                    /* STAREQ  */
  YYSYMBOL_SLASHEQ = 28,                   /* SLASHEQ  */
  YYSYMBOL_PERCENTEQ = 29,                 /* PERCENTEQ  */
  YYSYMBOL_TRUEVAL = 30,                   /* TRUEVAL  */
  YYSYMBOL_FALSEVAL = 31,                  /* FALSEVAL  */
  YYSYMBOL_LET = 32,                       /* LET  */
  YYSYMBOL_NUM = 33,                       /* NUM  */
  YYSYMBOL_FLOAT = 34,                     /* FLOAT  */
  YYSYMBOL_ID = 35,                        /* ID  */
  YYSYMBOL_EXPORT = 36,                    /* EXPORT  */
  YYSYMBOL_RETURN = 37,                    /* RETURN  */
  YYSYMBOL_TYPE_INT = 38,                  /* TYPE_INT  */
  YYSYMBOL_TYPE_FLOAT = 39,                /* TYPE_FLOAT  */
  YYSYMBOL_TYPE_BOOL = 40,                 /* TYPE_BOOL  */
  YYSYMBOL_TYPE_VOID = 41,                 /* TYPE_VOID  */
  YYSYMBOL_IF = 42,                        /* IF  */
  YYSYMBOL_ELSE = 43,                      /* ELSE  */
  YYSYMBOL_WHILE = 44,                     /* WHILE  */
  YYSYMBOL_DO = 45,                        /* DO  */
  YYSYMBOL_FOR = 46,                       /* FOR  */
  YYSYMBOL_EXTERN = 47,                    /* EXTERN  */
  YYSYMBOL_YYACCEPT = 48,                  /* $accept  */
  YYSYMBOL_program = 49,                   /* program  */
  YYSYMBOL_decls = 50,                     /* decls  */
  YYSYMBOL_ids = 51,                       /* ids  */
  YYSYMBOL_decl = 52,                      /* decl  */
  YYSYMBOL_glob_decl = 53,                 /* glob_decl  */
  YYSYMBOL_glob_def = 54,                  /* glob_def  */
  YYSYMBOL_stmts = 55,                     /* stmts  */
  YYSYMBOL_stmt = 56,                      /* stmt  */
  YYSYMBOL_fundef = 57,                    /* fundef  */
  YYSYMBOL_funbody = 58,                   /* funbody  */
  YYSYMBOL_exprs = 59,                     /* exprs  */
  YYSYMBOL_var_decl = 60,                  /* var_decl  */
  YYSYMBOL_assign = 61,                    /* assign  */
  YYSYMBOL_return_stmt = 62,               /* return_stmt  */
  YYSYMBOL_if_stmt = 63,                   /* if_stmt  */
  YYSYMBOL_while_stmt = 64,                /* while_stmt  */
  YYSYMBOL_do_while_stmt = 65,             /* do_while_stmt  */
  YYSYMBOL_for_stmt = 66,                  /* for_stmt  */
  YYSYMBOL_param = 67,                     /* param  */
  YYSYMBOL_varlet = 68,                    /* varlet  */
  YYSYMBOL_args = 69,                      /* args  */
  YYSYMBOL_call = 70,                      /* call  */
  YYSYMBOL_arithmetic = 71,                /* arithmetic  */
  YYSYMBOL_cast = 72,                      /* cast  */
  YYSYMBOL_expr = 73,                      /* expr  */
  YYSYMBOL_constant = 74,                  /* constant  */
  YYSYMBOL_type = 75,                      /* type  */
  YYSYMBOL_floatval = 76,                  /* floatval  */
  YYSYMBOL_intval = 77,                    /* intval  */
  YYSYMBOL_boolval = 78                    /* boolval  */
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
#define YYLAST   738

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  48
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  31
/* YYNRULES -- Number of rules.  */
#define YYNRULES  102
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  232

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   302


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
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    93,    93,    99,   103,   109,   115,   125,   129,   133,
     138,   143,   147,   151,   155,   160,   164,   173,   174,   175,
     176,   177,   178,   186,   190,   194,   198,   203,   207,   211,
     215,   219,   223,   241,   245,   251,   255,   259,   263,   269,
     280,   291,   309,   327,   340,   363,   367,   371,   375,   379,
     383,   388,   392,   397,   401,   406,   410,   415,   419,   427,
     436,   445,   454,   462,   467,   473,   478,   484,   490,   496,
     506,   511,   517,   521,   525,   529,   533,   537,   541,   545,
     549,   553,   557,   561,   565,   569,   575,   581,   582,   583,
     584,   585,   588,   592,   596,   601,   602,   603,   604,   606,
     611,   616,   620
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
  "\"end of file\"", "error", "\"invalid token\"", "CAST", "BRACKET_L",
  "BRACKET_R", "COMMA", "SEMICOLON", "CURLY_L", "CURLY_R", "SQUARE_L",
  "SQUARE_R", "MINUS", "PLUS", "STAR", "SLASH", "PERCENT", "LE", "LT",
  "GE", "GT", "EQ", "NE", "OR", "AND", "PLUSEQ", "MINUSEQ", "STAREQ",
  "SLASHEQ", "PERCENTEQ", "TRUEVAL", "FALSEVAL", "LET", "NUM", "FLOAT",
  "ID", "EXPORT", "RETURN", "TYPE_INT", "TYPE_FLOAT", "TYPE_BOOL",
  "TYPE_VOID", "IF", "ELSE", "WHILE", "DO", "FOR", "EXTERN", "$accept",
  "program", "decls", "ids", "decl", "glob_decl", "glob_def", "stmts",
  "stmt", "fundef", "funbody", "exprs", "var_decl", "assign",
  "return_stmt", "if_stmt", "while_stmt", "do_while_stmt", "for_stmt",
  "param", "varlet", "args", "call", "arithmetic", "cast", "expr",
  "constant", "type", "floatval", "intval", "boolval", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-116)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-68)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -27,   -22,  -116,  -116,  -116,  -116,   -22,    33,  -116,   -27,
    -116,  -116,  -116,   -31,    31,    32,  -116,  -116,    17,    23,
      66,    20,  -116,   264,    24,  -116,   264,  -116,    79,    72,
      -9,   248,  -116,  -116,  -116,  -116,    84,  -116,  -116,  -116,
     489,  -116,  -116,  -116,  -116,    79,    85,   507,    77,  -116,
      79,    54,    86,   315,    88,   169,  -116,   264,   264,   264,
     264,   264,   264,   264,   264,   264,   264,   264,   264,   264,
    -116,    79,  -116,  -116,   109,   264,    92,    90,    95,    45,
     231,   120,  -116,  -116,  -116,  -116,  -116,   117,   525,    -4,
    -116,   103,   114,   -22,  -116,   264,  -116,   121,   433,    69,
      69,  -116,  -116,  -116,   290,   290,   290,   290,   718,   718,
     694,   707,  -116,   668,   264,   163,   -22,  -116,   214,   118,
    -116,  -116,    60,   264,   264,   264,   264,   264,   264,  -116,
      97,    43,    54,    93,  -116,   681,  -116,   264,   231,   335,
      87,   123,   112,  -116,   543,  -116,  -116,   139,   561,   579,
     597,   615,   633,   651,     4,  -116,   264,  -116,   146,  -116,
     150,   152,   165,   127,   143,  -116,  -116,  -116,  -116,  -116,
    -116,  -116,  -116,   144,   141,   414,   -22,   136,   180,   264,
     176,   264,   171,    44,  -116,   -22,  -116,   175,  -116,   177,
     355,   264,   452,   153,   -22,   181,  -116,   231,  -116,   178,
     375,   264,   183,  -116,   264,   203,  -116,   209,   295,   -22,
     206,   471,  -116,  -116,   179,   264,  -116,   212,   264,   197,
     395,   -22,  -116,  -116,   211,   228,  -116,  -116,   225,  -116,
     224,  -116
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,    95,    96,    97,    98,     0,     0,     2,     4,
       7,     9,     8,     0,     0,     0,     1,     3,     0,     0,
       0,     0,    14,     0,     0,    13,     0,    10,     0,     0,
       0,     0,   101,   102,   100,    99,    88,    89,    91,    90,
       0,    87,    92,    93,    94,     0,     0,     0,     0,    26,
       0,     0,    63,     0,     0,     0,    12,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      24,     0,    11,    30,    88,     0,     0,     0,     0,     0,
      16,     0,    17,    18,    19,    20,    21,     0,     0,     0,
      25,     5,     0,     0,    85,     0,    71,     0,    68,    73,
      72,    74,    75,    76,    78,    77,    80,    79,    81,    82,
      84,    83,    23,     0,     0,     0,     0,    32,     0,     0,
      15,    31,     0,     0,     0,     0,     0,     0,     0,    22,
       0,     0,     0,     0,    64,    86,    70,     0,     0,     0,
       0,     0,     0,    52,     0,    28,    29,     0,     0,     0,
       0,     0,     0,     0,     0,    35,     0,     6,    65,    69,
       0,     0,     0,     0,     0,    51,    27,    46,    47,    48,
      49,    50,    45,     0,     0,     0,     0,    54,     0,     0,
       0,     0,     0,     0,    37,    36,    66,     0,    56,     0,
       0,     0,     0,     0,    39,     0,    38,     0,    55,     0,
       0,     0,     0,    40,     0,     0,    58,     0,     0,    41,
       0,    33,    53,    57,     0,     0,    42,     0,     0,     0,
       0,    43,    34,    59,     0,     0,    44,    61,     0,    60,
       0,    62
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -116,  -116,   229,   105,  -116,  -116,  -116,   -58,  -116,  -116,
     -43,    22,  -115,  -116,   124,  -116,  -116,  -116,  -116,   -19,
    -116,   113,  -116,  -116,  -116,   -23,  -116,    47,  -116,  -116,
    -116
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     7,     8,    92,     9,    10,    11,    79,    80,    12,
      49,   210,    81,    82,   119,    83,    84,    85,    86,    29,
      87,    97,    37,    38,    39,    88,    41,    89,    42,    43,
      44
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      40,    51,    70,    47,    18,    46,   130,    90,    53,     1,
     173,     2,     3,     4,     5,   174,     2,     3,     4,     5,
       6,    21,   120,   122,    22,    28,    52,    24,   112,    45,
      25,   131,    98,    16,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,    13,    14,    23,
     155,   194,   113,    15,   117,    26,    13,   141,     2,     3,
       4,     5,     2,     3,     4,     5,    19,    20,    30,   146,
     196,    30,   135,    27,   134,   156,   195,    50,    54,   203,
     160,    31,   118,    59,    60,    61,    73,    48,    55,    91,
      71,   139,    93,    95,   216,   144,   114,   118,   115,   116,
     148,   149,   150,   151,   152,   153,   226,    32,    33,   132,
      34,    35,    74,    55,    98,     2,     3,     4,     5,    75,
     189,    76,    77,    78,    31,   133,   136,   145,   158,   121,
     154,   162,   163,   175,   -67,   -67,   -67,   -67,   -67,   205,
      30,   -67,   123,   124,   125,   126,   127,   164,   166,   128,
      32,    33,   176,    34,    35,    74,   190,   186,   192,   177,
     178,   224,    75,   142,    76,    77,    78,    31,   200,   179,
     230,   180,   140,    31,    96,   181,   183,   182,   208,   187,
     191,   211,   193,   197,    31,   206,   198,   219,   202,   188,
     209,   204,   220,    32,    33,   211,    34,    35,    74,    32,
      33,    31,    34,    35,    36,    75,   223,    76,    77,    78,
      32,    33,   212,    34,    35,    74,   213,   217,    31,   221,
     227,   143,    75,    30,    76,    77,    78,    32,    33,    31,
      34,    35,    74,   231,   229,    31,   228,   157,    17,    75,
     222,    76,    77,    78,    32,    33,   147,    34,    35,    36,
     159,     0,    31,     0,     0,    32,    33,     0,    34,    35,
      74,    32,    33,     0,    34,    35,    74,    75,    31,    76,
      77,    78,     0,    75,     0,    76,    77,    78,    32,    33,
       0,    34,    35,    36,     0,     0,     2,     3,     4,     5,
       0,     0,     0,     0,    32,    33,     0,    34,    35,    36,
     214,   215,    57,    58,    59,    60,    61,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      94,     0,     0,     0,     0,     0,     0,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
     161,     0,     0,     0,     0,     0,     0,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
     199,     0,     0,     0,     0,     0,     0,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
     207,     0,     0,     0,     0,     0,     0,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
     225,     0,     0,     0,     0,     0,     0,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
     184,   185,     0,     0,     0,     0,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,   137,
       0,     0,     0,     0,     0,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,   201,     0,
       0,     0,     0,     0,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,   218,     0,     0,
       0,     0,     0,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    56,     0,     0,     0,
       0,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    72,     0,     0,     0,     0,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,   129,     0,     0,     0,     0,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
     165,     0,     0,     0,     0,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,   167,     0,
       0,     0,     0,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,   168,     0,     0,     0,
       0,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,   169,     0,     0,     0,     0,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,   170,     0,     0,     0,     0,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
     171,     0,     0,     0,     0,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,   172,     0,
       0,     0,     0,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,   138,     0,     0,     0,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,     0,    69,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      57,    58,    59,    60,    61,    62,    63,    64,    65
};

static const yytype_int16 yycheck[] =
{
      23,    10,    45,    26,    35,    24,    10,    50,    31,    36,
       6,    38,    39,    40,    41,    11,    38,    39,    40,    41,
      47,     4,    80,    81,     7,     5,    35,     4,    71,     5,
       7,    35,    55,     0,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,     0,     1,    32,
       7,     7,    75,     6,     9,    32,     9,   115,    38,    39,
      40,    41,    38,    39,    40,    41,    35,    35,    21,     9,
     185,    24,    95,     7,    93,    32,    32,     5,    31,   194,
     138,     4,    37,    14,    15,    16,     9,     8,     4,    35,
       5,   114,     6,     5,   209,   118,     4,    37,     8,     4,
     123,   124,   125,   126,   127,   128,   221,    30,    31,     6,
      33,    34,    35,     4,   137,    38,    39,    40,    41,    42,
     178,    44,    45,    46,     4,    11,     5,     9,    35,     9,
      33,    44,     9,   156,    25,    26,    27,    28,    29,   197,
      93,    32,    25,    26,    27,    28,    29,    35,     9,    32,
      30,    31,     6,    33,    34,    35,   179,   176,   181,     9,
       8,   219,    42,   116,    44,    45,    46,     4,   191,     4,
     228,    44,     9,     4,     5,    32,    35,    33,   201,    43,
       4,   204,    11,     8,     4,     7,     9,     8,    35,     9,
       7,    10,   215,    30,    31,   218,    33,    34,    35,    30,
      31,     4,    33,    34,    35,    42,     9,    44,    45,    46,
      30,    31,     9,    33,    34,    35,     7,    11,     4,     7,
       9,     7,    42,   176,    44,    45,    46,    30,    31,     4,
      33,    34,    35,     9,     9,     4,     8,   132,     9,    42,
     218,    44,    45,    46,    30,    31,   122,    33,    34,    35,
     137,    -1,     4,    -1,    -1,    30,    31,    -1,    33,    34,
      35,    30,    31,    -1,    33,    34,    35,    42,     4,    44,
      45,    46,    -1,    42,    -1,    44,    45,    46,    30,    31,
      -1,    33,    34,    35,    -1,    -1,    38,    39,    40,    41,
      -1,    -1,    -1,    -1,    30,    31,    -1,    33,    34,    35,
       5,     6,    12,    13,    14,    15,    16,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
       5,    -1,    -1,    -1,    -1,    -1,    -1,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
       5,    -1,    -1,    -1,    -1,    -1,    -1,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
       5,    -1,    -1,    -1,    -1,    -1,    -1,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
       5,    -1,    -1,    -1,    -1,    -1,    -1,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
       5,    -1,    -1,    -1,    -1,    -1,    -1,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
       6,     7,    -1,    -1,    -1,    -1,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,     6,
      -1,    -1,    -1,    -1,    -1,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,     6,    -1,
      -1,    -1,    -1,    -1,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,     6,    -1,    -1,
      -1,    -1,    -1,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,     7,    -1,    -1,    -1,
      -1,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,     7,    -1,    -1,    -1,    -1,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,     7,    -1,    -1,    -1,    -1,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
       7,    -1,    -1,    -1,    -1,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,     7,    -1,
      -1,    -1,    -1,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,     7,    -1,    -1,    -1,
      -1,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,     7,    -1,    -1,    -1,    -1,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,     7,    -1,    -1,    -1,    -1,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
       7,    -1,    -1,    -1,    -1,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,     7,    -1,
      -1,    -1,    -1,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,     8,    -1,    -1,    -1,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    -1,    24,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      12,    13,    14,    15,    16,    17,    18,    19,    20
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    36,    38,    39,    40,    41,    47,    49,    50,    52,
      53,    54,    57,    75,    75,    75,     0,    50,    35,    35,
      35,     4,     7,    32,     4,     7,    32,     7,     5,    67,
      75,     4,    30,    31,    33,    34,    35,    70,    71,    72,
      73,    74,    76,    77,    78,     5,    67,    73,     8,    58,
       5,    10,    35,    73,    75,     4,     7,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      58,     5,     7,     9,    35,    42,    44,    45,    46,    55,
      56,    60,    61,    63,    64,    65,    66,    68,    73,    75,
      58,    35,    51,     6,     5,     5,     5,    69,    73,    73,
      73,    73,    73,    73,    73,    73,    73,    73,    73,    73,
      73,    73,    58,    73,     4,     8,     4,     9,    37,    62,
      55,     9,    55,    25,    26,    27,    28,    29,    32,     7,
      10,    35,     6,    11,    67,    73,     5,     6,     8,    73,
       9,    55,    75,     7,    73,     9,     9,    62,    73,    73,
      73,    73,    73,    73,    33,     7,    32,    51,    35,    69,
      55,     5,    44,     9,    35,     7,     9,     7,     7,     7,
       7,     7,     7,     6,    11,    73,     6,     9,     8,     4,
      44,    32,    33,    35,     6,     7,    67,    43,     9,    55,
      73,     4,    73,    11,     7,    32,    60,     8,     9,     5,
      73,     6,    35,    60,    10,    55,     7,     5,    73,     7,
      59,    73,     9,     7,     5,     6,    60,    11,     6,     8,
      73,     7,    59,     9,    55,     5,    60,     9,     8,     9,
      55,     9
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    48,    49,    50,    50,    51,    51,    52,    52,    52,
      53,    54,    54,    54,    54,    55,    55,    56,    56,    56,
      56,    56,    56,    57,    57,    57,    57,    58,    58,    58,
      58,    58,    58,    59,    59,    60,    60,    60,    60,    60,
      60,    60,    60,    60,    60,    61,    61,    61,    61,    61,
      61,    62,    62,    63,    63,    64,    64,    65,    65,    66,
      66,    66,    66,    67,    67,    67,    67,    68,    69,    69,
      70,    70,    71,    71,    71,    71,    71,    71,    71,    71,
      71,    71,    71,    71,    71,    71,    72,    73,    73,    73,
      73,    73,    74,    74,    74,    75,    75,    75,    75,    76,
      77,    78,    78
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     3,     1,     1,     1,
       4,     6,     5,     4,     3,     2,     1,     1,     1,     1,
       1,     1,     2,     7,     6,     6,     5,     5,     4,     4,
       2,     3,     3,     1,     3,     3,     5,     5,     6,     6,
       7,     8,     9,    10,    11,     4,     4,     4,     4,     4,
       4,     3,     2,     9,     5,     7,     6,     9,     8,    11,
      13,    12,    14,     2,     4,     5,     7,     1,     1,     3,
       4,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     4,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1
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
#line 94 "./src/scanparse/parser.y"
        {
		parseresult = ASTprogram((yyvsp[0].node));
	}
#line 1639 "parser.tab.c"
    break;

  case 3: /* decls: decl decls  */
#line 100 "./src/scanparse/parser.y"
        {
		(yyval.node) = ASTdecls((yyvsp[-1].node), (yyvsp[0].node));
	}
#line 1647 "parser.tab.c"
    break;

  case 4: /* decls: decl  */
#line 104 "./src/scanparse/parser.y"
        {
		(yyval.node) = ASTdecls((yyvsp[0].node), NULL);
	}
#line 1655 "parser.tab.c"
    break;

  case 5: /* ids: ID  */
#line 110 "./src/scanparse/parser.y"
  {
    //single dimensions
    (yyval.node) = ASTids(NULL, (yyvsp[0].id));
  }
#line 1664 "parser.tab.c"
    break;

  case 6: /* ids: ID COMMA ids  */
#line 116 "./src/scanparse/parser.y"
  {
    //multi dimensional
    (yyval.node) = ASTids((yyvsp[0].node), (yyvsp[-2].id));  
  }
#line 1673 "parser.tab.c"
    break;

  case 7: /* decl: glob_decl  */
#line 126 "./src/scanparse/parser.y"
  {
    (yyval.node) = (yyvsp[0].node);
  }
#line 1681 "parser.tab.c"
    break;

  case 8: /* decl: fundef  */
#line 130 "./src/scanparse/parser.y"
  {
    (yyval.node) = (yyvsp[0].node);
  }
#line 1689 "parser.tab.c"
    break;

  case 9: /* decl: glob_def  */
#line 134 "./src/scanparse/parser.y"
  {
    (yyval.node) = (yyvsp[0].node);
  }
#line 1697 "parser.tab.c"
    break;

  case 10: /* glob_decl: EXTERN type ID SEMICOLON  */
#line 139 "./src/scanparse/parser.y"
  {
    (yyval.node) = ASTglobdecl(NULL, (yyvsp[-1].id), (yyvsp[-2].ctype));
  }
#line 1705 "parser.tab.c"
    break;

  case 11: /* glob_def: EXPORT type ID LET expr SEMICOLON  */
#line 144 "./src/scanparse/parser.y"
  {
    (yyval.node) = ASTglobdef(NULL,(yyvsp[-1].node), (yyvsp[-3].id), (yyvsp[-4].ctype), true);
  }
#line 1713 "parser.tab.c"
    break;

  case 12: /* glob_def: type ID LET expr SEMICOLON  */
#line 148 "./src/scanparse/parser.y"
  {
    (yyval.node) = ASTglobdef(NULL,(yyvsp[-1].node), (yyvsp[-3].id), (yyvsp[-4].ctype), false);
  }
#line 1721 "parser.tab.c"
    break;

  case 13: /* glob_def: EXPORT type ID SEMICOLON  */
#line 152 "./src/scanparse/parser.y"
  {
    (yyval.node) = ASTglobdef(NULL,NULL, (yyvsp[-1].id), (yyvsp[-2].ctype), true);
  }
#line 1729 "parser.tab.c"
    break;

  case 14: /* glob_def: type ID SEMICOLON  */
#line 156 "./src/scanparse/parser.y"
  {
    (yyval.node) = ASTglobdef(NULL,NULL, (yyvsp[-1].id), (yyvsp[-2].ctype), true);
  }
#line 1737 "parser.tab.c"
    break;

  case 15: /* stmts: stmt stmts  */
#line 161 "./src/scanparse/parser.y"
  {
    (yyval.node) = ASTstmts((yyvsp[-1].node), (yyvsp[0].node));
  }
#line 1745 "parser.tab.c"
    break;

  case 16: /* stmts: stmt  */
#line 165 "./src/scanparse/parser.y"
  {
    (yyval.node) = ASTstmts((yyvsp[0].node), NULL);
  }
#line 1753 "parser.tab.c"
    break;

  case 17: /* stmt: assign  */
#line 173 "./src/scanparse/parser.y"
             { (yyval.node) = (yyvsp[0].node); }
#line 1759 "parser.tab.c"
    break;

  case 18: /* stmt: if_stmt  */
#line 174 "./src/scanparse/parser.y"
              { (yyval.node) = (yyvsp[0].node); }
#line 1765 "parser.tab.c"
    break;

  case 19: /* stmt: while_stmt  */
#line 175 "./src/scanparse/parser.y"
                 { (yyval.node) = (yyvsp[0].node); }
#line 1771 "parser.tab.c"
    break;

  case 20: /* stmt: do_while_stmt  */
#line 176 "./src/scanparse/parser.y"
                    { (yyval.node) = (yyvsp[0].node); }
#line 1777 "parser.tab.c"
    break;

  case 21: /* stmt: for_stmt  */
#line 177 "./src/scanparse/parser.y"
               { (yyval.node) = (yyvsp[0].node); }
#line 1783 "parser.tab.c"
    break;

  case 22: /* stmt: expr SEMICOLON  */
#line 178 "./src/scanparse/parser.y"
                     { (yyval.node) = ASTexprstmt((yyvsp[-1].node)); 
}
#line 1790 "parser.tab.c"
    break;

  case 23: /* fundef: EXPORT type ID BRACKET_L param BRACKET_R funbody  */
#line 187 "./src/scanparse/parser.y"
  {
    (yyval.node) = ASTfundef((yyvsp[0].node), (yyvsp[-2].node), (yyvsp[-4].id), (yyvsp[-5].ctype), true); // Exported function
  }
#line 1798 "parser.tab.c"
    break;

  case 24: /* fundef: EXPORT type ID BRACKET_L BRACKET_R funbody  */
#line 191 "./src/scanparse/parser.y"
  {
    (yyval.node) = ASTfundef((yyvsp[0].node), NULL, (yyvsp[-3].id), (yyvsp[-4].ctype), true);
  }
#line 1806 "parser.tab.c"
    break;

  case 25: /* fundef: type ID BRACKET_L param BRACKET_R funbody  */
#line 195 "./src/scanparse/parser.y"
  {
    (yyval.node) = ASTfundef((yyvsp[0].node), (yyvsp[-2].node), (yyvsp[-4].id), (yyvsp[-5].ctype), false); // Non-exported function
  }
#line 1814 "parser.tab.c"
    break;

  case 26: /* fundef: type ID BRACKET_L BRACKET_R funbody  */
#line 199 "./src/scanparse/parser.y"
  {
    (yyval.node) = ASTfundef((yyvsp[0].node), NULL, (yyvsp[-3].id), (yyvsp[-4].ctype), false);
  }
#line 1822 "parser.tab.c"
    break;

  case 27: /* funbody: CURLY_L var_decl stmts return_stmt CURLY_R  */
#line 204 "./src/scanparse/parser.y"
  {
    (yyval.node) = ASTfunbody((yyvsp[-3].node), NULL, ASTstmts((yyvsp[-2].node), (yyvsp[-1].node)));
  }
#line 1830 "parser.tab.c"
    break;

  case 28: /* funbody: CURLY_L stmts return_stmt CURLY_R  */
#line 208 "./src/scanparse/parser.y"
  {
    (yyval.node) = ASTfunbody(NULL, NULL, ASTstmts((yyvsp[-2].node), (yyvsp[-1].node)));
  }
#line 1838 "parser.tab.c"
    break;

  case 29: /* funbody: CURLY_L var_decl stmts CURLY_R  */
#line 212 "./src/scanparse/parser.y"
  {
    (yyval.node) = ASTfunbody((yyvsp[-2].node), NULL, (yyvsp[-1].node));
  }
#line 1846 "parser.tab.c"
    break;

  case 30: /* funbody: CURLY_L CURLY_R  */
#line 216 "./src/scanparse/parser.y"
  {
    (yyval.node) = ASTfunbody(NULL, NULL, NULL);
  }
#line 1854 "parser.tab.c"
    break;

  case 31: /* funbody: CURLY_L var_decl CURLY_R  */
#line 220 "./src/scanparse/parser.y"
  {
    (yyval.node) = ASTfunbody((yyvsp[-1].node), NULL, NULL);
  }
#line 1862 "parser.tab.c"
    break;

  case 32: /* funbody: CURLY_L stmts CURLY_R  */
#line 224 "./src/scanparse/parser.y"
  {
    (yyval.node) = ASTfunbody(NULL, NULL, (yyvsp[-1].node));
  }
#line 1870 "parser.tab.c"
    break;

  case 33: /* exprs: expr  */
#line 242 "./src/scanparse/parser.y"
  {
      (yyval.node) = ASTexprs((yyvsp[0].node), NULL);
  }
#line 1878 "parser.tab.c"
    break;

  case 34: /* exprs: expr COMMA exprs  */
#line 246 "./src/scanparse/parser.y"
  {
      (yyval.node) = ASTexprs((yyvsp[-2].node), (yyvsp[0].node));
  }
#line 1886 "parser.tab.c"
    break;

  case 35: /* var_decl: type ID SEMICOLON  */
#line 252 "./src/scanparse/parser.y"
  {
    (yyval.node) = ASTvardecl(NULL, NULL, NULL, (yyvsp[-1].id), (yyvsp[-2].ctype));
  }
#line 1894 "parser.tab.c"
    break;

  case 36: /* var_decl: type ID LET expr SEMICOLON  */
#line 256 "./src/scanparse/parser.y"
  {
    (yyval.node) = ASTvardecl(NULL, (yyvsp[-1].node), NULL, (yyvsp[-3].id), (yyvsp[-4].ctype));
  }
#line 1902 "parser.tab.c"
    break;

  case 37: /* var_decl: type ID LET expr COMMA  */
#line 260 "./src/scanparse/parser.y"
  {
    (yyval.node) = ASTvardecl(NULL, (yyvsp[-1].node), NULL, (yyvsp[-3].id), (yyvsp[-4].ctype));
  }
#line 1910 "parser.tab.c"
    break;

  case 38: /* var_decl: type ID LET expr SEMICOLON var_decl  */
#line 264 "./src/scanparse/parser.y"
  {
    (yyval.node) = ASTvardecl(NULL, (yyvsp[-2].node), (yyvsp[0].node), (yyvsp[-4].id), (yyvsp[-5].ctype));
  }
#line 1918 "parser.tab.c"
    break;

  case 39: /* var_decl: type SQUARE_L NUM SQUARE_R ID SEMICOLON  */
#line 270 "./src/scanparse/parser.y"
  {
        (yyval.node) = ASTvardecl(ASTexprs(ASTnum((yyvsp[-3].cint)), NULL),
            NULL,
            NULL,
            (yyvsp[-1].id),
            (yyvsp[-5].ctype)
        );
  }
#line 1931 "parser.tab.c"
    break;

  case 40: /* var_decl: type SQUARE_L NUM SQUARE_R ID SEMICOLON var_decl  */
#line 281 "./src/scanparse/parser.y"
  {
        (yyval.node) = ASTvardecl(ASTexprs(ASTnum((yyvsp[-4].cint)), NULL),
            NULL,
            (yyvsp[0].node),
            (yyvsp[-2].id),
            (yyvsp[-6].ctype)
        );
  }
#line 1944 "parser.tab.c"
    break;

  case 41: /* var_decl: type SQUARE_L NUM COMMA NUM SQUARE_R ID SEMICOLON  */
#line 292 "./src/scanparse/parser.y"
  {
      (yyval.node) = ASTvardecl(
          ASTexprs(
              ASTnum((yyvsp[-5].cint)),  
              ASTexprs(
                  ASTnum((yyvsp[-3].cint)),
                  NULL
              )
          ),
          NULL,  
          NULL,  
          (yyvsp[-1].id),    
          (yyvsp[-7].ctype)
      );
  }
#line 1964 "parser.tab.c"
    break;

  case 42: /* var_decl: type SQUARE_L NUM COMMA NUM SQUARE_R ID SEMICOLON var_decl  */
#line 310 "./src/scanparse/parser.y"
  {
      (yyval.node) = ASTvardecl(
          ASTexprs(
              ASTnum((yyvsp[-6].cint)), 
              ASTexprs(
                  ASTnum((yyvsp[-4].cint)),
                  NULL
              )
          ),
          NULL,  
          (yyvsp[0].node),
          (yyvsp[-2].id),   
          (yyvsp[-8].ctype)
      );
  }
#line 1984 "parser.tab.c"
    break;

  case 43: /* var_decl: type SQUARE_L NUM SQUARE_R ID LET SQUARE_L exprs SQUARE_R SEMICOLON  */
#line 328 "./src/scanparse/parser.y"
  {
      node_st *size_node = ASTnum((yyvsp[-7].cint));
      (yyval.node) = ASTvardecl(
          ASTexprs(size_node, NULL), 
          ASTarrexpr((yyvsp[-2].node), generate_indices(size_node)),
          NULL,  
          (yyvsp[-5].id),
          (yyvsp[-9].ctype)
      );
  }
#line 1999 "parser.tab.c"
    break;

  case 44: /* var_decl: type SQUARE_L NUM SQUARE_R ID LET SQUARE_L exprs SQUARE_R SEMICOLON var_decl  */
#line 341 "./src/scanparse/parser.y"
  {
      node_st *size_node = ASTnum((yyvsp[-8].cint));
      (yyval.node) = ASTvardecl(
          ASTexprs(size_node, NULL), 
          ASTarrexpr((yyvsp[-3].node), generate_indices(size_node)),
          NULL,  
          (yyvsp[-6].id),
          (yyvsp[-10].ctype)
      );
  }
#line 2014 "parser.tab.c"
    break;

  case 45: /* assign: varlet LET expr SEMICOLON  */
#line 364 "./src/scanparse/parser.y"
{
  (yyval.node) = ASTassign((yyvsp[-3].node), (yyvsp[-1].node));
}
#line 2022 "parser.tab.c"
    break;

  case 46: /* assign: varlet PLUSEQ expr SEMICOLON  */
#line 368 "./src/scanparse/parser.y"
{
  (yyval.node) = ASTassign((yyvsp[-3].node), ASTbinop((yyvsp[-3].node), (yyvsp[-1].node), BO_add));
}
#line 2030 "parser.tab.c"
    break;

  case 47: /* assign: varlet MINUSEQ expr SEMICOLON  */
#line 372 "./src/scanparse/parser.y"
{
  (yyval.node) = ASTassign((yyvsp[-3].node), ASTbinop((yyvsp[-3].node), (yyvsp[-1].node), BO_sub));
}
#line 2038 "parser.tab.c"
    break;

  case 48: /* assign: varlet STAREQ expr SEMICOLON  */
#line 376 "./src/scanparse/parser.y"
{
  (yyval.node) = ASTassign((yyvsp[-3].node), ASTbinop((yyvsp[-3].node), (yyvsp[-1].node), BO_mul));
}
#line 2046 "parser.tab.c"
    break;

  case 49: /* assign: varlet SLASHEQ expr SEMICOLON  */
#line 380 "./src/scanparse/parser.y"
{
  (yyval.node) = ASTassign((yyvsp[-3].node), ASTbinop((yyvsp[-3].node), (yyvsp[-1].node), BO_div));
}
#line 2054 "parser.tab.c"
    break;

  case 50: /* assign: varlet PERCENTEQ expr SEMICOLON  */
#line 384 "./src/scanparse/parser.y"
{
  (yyval.node) = ASTassign((yyvsp[-3].node), ASTbinop((yyvsp[-3].node), (yyvsp[-1].node), BO_mod));
}
#line 2062 "parser.tab.c"
    break;

  case 51: /* return_stmt: RETURN expr SEMICOLON  */
#line 389 "./src/scanparse/parser.y"
  {
    (yyval.node) = ASTreturn((yyvsp[-1].node));
  }
#line 2070 "parser.tab.c"
    break;

  case 52: /* return_stmt: RETURN SEMICOLON  */
#line 393 "./src/scanparse/parser.y"
  {
    (yyval.node) = ASTreturn(NULL);
  }
#line 2078 "parser.tab.c"
    break;

  case 53: /* if_stmt: IF expr CURLY_L stmts CURLY_R ELSE CURLY_L stmts CURLY_R  */
#line 398 "./src/scanparse/parser.y"
  {
    (yyval.node) = ASTifelse((yyvsp[-7].node), (yyvsp[-5].node), (yyvsp[-1].node));
  }
#line 2086 "parser.tab.c"
    break;

  case 54: /* if_stmt: IF expr CURLY_L stmts CURLY_R  */
#line 402 "./src/scanparse/parser.y"
  {
    (yyval.node) = ASTifelse((yyvsp[-3].node), (yyvsp[-1].node), NULL);
  }
#line 2094 "parser.tab.c"
    break;

  case 55: /* while_stmt: WHILE BRACKET_L expr BRACKET_R CURLY_L stmts CURLY_R  */
#line 407 "./src/scanparse/parser.y"
  {
    (yyval.node) = ASTwhile((yyvsp[-4].node), (yyvsp[-1].node));
  }
#line 2102 "parser.tab.c"
    break;

  case 56: /* while_stmt: WHILE BRACKET_L expr BRACKET_R CURLY_L CURLY_R  */
#line 411 "./src/scanparse/parser.y"
  {
    (yyval.node) = ASTwhile((yyvsp[-3].node), NULL);
  }
#line 2110 "parser.tab.c"
    break;

  case 57: /* do_while_stmt: DO CURLY_L stmts CURLY_R WHILE BRACKET_L expr BRACKET_R SEMICOLON  */
#line 416 "./src/scanparse/parser.y"
  {
    (yyval.node) = ASTdowhile((yyvsp[-2].node), (yyvsp[-6].node));
  }
#line 2118 "parser.tab.c"
    break;

  case 58: /* do_while_stmt: DO CURLY_L CURLY_R WHILE BRACKET_L expr BRACKET_R SEMICOLON  */
#line 420 "./src/scanparse/parser.y"
  {
    (yyval.node) = ASTdowhile((yyvsp[-2].node), NULL);
  }
#line 2126 "parser.tab.c"
    break;

  case 59: /* for_stmt: FOR BRACKET_L type ID LET expr COMMA expr BRACKET_R CURLY_L CURLY_R  */
#line 428 "./src/scanparse/parser.y"
  {
    // printf("no step size, default to 1, no statements\n");
    (yyval.node) = ASTfor((yyvsp[-5].node), (yyvsp[-3].node), ASTnum(1), NULL);
        free((yyvsp[-7].id));

  }
#line 2137 "parser.tab.c"
    break;

  case 60: /* for_stmt: FOR BRACKET_L type ID LET expr COMMA expr COMMA expr BRACKET_R CURLY_L CURLY_R  */
#line 437 "./src/scanparse/parser.y"
  {
    printf("with step size, no statements\n");
    (yyval.node) = ASTfor((yyvsp[-7].node), (yyvsp[-5].node), (yyvsp[-3].node), NULL);
        free((yyvsp[-9].id));

  }
#line 2148 "parser.tab.c"
    break;

  case 61: /* for_stmt: FOR BRACKET_L type ID LET expr COMMA expr BRACKET_R CURLY_L stmts CURLY_R  */
#line 446 "./src/scanparse/parser.y"
  {
    printf("no step size, default to 1, with statements\n");
    (yyval.node) = ASTfor((yyvsp[-6].node), (yyvsp[-4].node), ASTnum(1), (yyvsp[-1].node));
        free((yyvsp[-8].id));

  }
#line 2159 "parser.tab.c"
    break;

  case 62: /* for_stmt: FOR BRACKET_L type ID LET expr COMMA expr COMMA expr BRACKET_R CURLY_L stmts CURLY_R  */
#line 455 "./src/scanparse/parser.y"
  {
    // printf("with step size, with statements\n");
    (yyval.node) = ASTfor((yyvsp[-8].node), (yyvsp[-6].node), (yyvsp[-4].node), (yyvsp[-1].node));
        free((yyvsp[-10].id));
  }
#line 2169 "parser.tab.c"
    break;

  case 63: /* param: type ID  */
#line 463 "./src/scanparse/parser.y"
  {
    (yyval.node) = ASTparam(NULL, NULL, (yyvsp[0].id), (yyvsp[-1].ctype));
  }
#line 2177 "parser.tab.c"
    break;

  case 64: /* param: type ID COMMA param  */
#line 468 "./src/scanparse/parser.y"
  {
    (yyval.node) = ASTparam(NULL, (yyvsp[0].node), (yyvsp[-2].id), (yyvsp[-3].ctype));
  }
#line 2185 "parser.tab.c"
    break;

  case 65: /* param: type SQUARE_L ids SQUARE_R ID  */
#line 473 "./src/scanparse/parser.y"
                                 {
      (yyval.node) = ASTparam((yyvsp[-2].node), NULL, (yyvsp[0].id), (yyvsp[-4].ctype));
  }
#line 2193 "parser.tab.c"
    break;

  case 66: /* param: type SQUARE_L ids SQUARE_R ID COMMA param  */
#line 479 "./src/scanparse/parser.y"
  {
    (yyval.node) = ASTparam((yyvsp[-4].node), (yyvsp[0].node), (yyvsp[-2].id), (yyvsp[-6].ctype));  
  }
#line 2201 "parser.tab.c"
    break;

  case 67: /* varlet: ID  */
#line 485 "./src/scanparse/parser.y"
  {
    (yyval.node) = ASTvarlet(NULL, (yyvsp[0].id));
    AddLocToNode((yyval.node), &(yylsp[0]), &(yylsp[0]));
  }
#line 2210 "parser.tab.c"
    break;

  case 68: /* args: expr  */
#line 492 "./src/scanparse/parser.y"
  {
    (yyval.node) = ASTexprs((yyvsp[0].node), NULL); 
  }
#line 2218 "parser.tab.c"
    break;

  case 69: /* args: expr COMMA args  */
#line 497 "./src/scanparse/parser.y"
  {
    (yyval.node) = ASTexprs((yyvsp[-2].node), (yyvsp[0].node));
  }
#line 2226 "parser.tab.c"
    break;

  case 70: /* call: ID BRACKET_L args BRACKET_R  */
#line 507 "./src/scanparse/parser.y"
  {
    (yyval.node) = ASTfuncall((yyvsp[-1].node), (yyvsp[-3].id));
  }
#line 2234 "parser.tab.c"
    break;

  case 71: /* call: ID BRACKET_L BRACKET_R  */
#line 512 "./src/scanparse/parser.y"
  {
    (yyval.node) = ASTfuncall(NULL, (yyvsp[-2].id));
  }
#line 2242 "parser.tab.c"
    break;

  case 72: /* arithmetic: expr PLUS expr  */
#line 518 "./src/scanparse/parser.y"
{
    (yyval.node) = ASTbinop((yyvsp[-2].node), (yyvsp[0].node), BO_add);
}
#line 2250 "parser.tab.c"
    break;

  case 73: /* arithmetic: expr MINUS expr  */
#line 522 "./src/scanparse/parser.y"
{
    (yyval.node) = ASTbinop((yyvsp[-2].node), (yyvsp[0].node), BO_sub);
}
#line 2258 "parser.tab.c"
    break;

  case 74: /* arithmetic: expr STAR expr  */
#line 526 "./src/scanparse/parser.y"
{
    (yyval.node) = ASTbinop((yyvsp[-2].node), (yyvsp[0].node), BO_mul);
}
#line 2266 "parser.tab.c"
    break;

  case 75: /* arithmetic: expr SLASH expr  */
#line 530 "./src/scanparse/parser.y"
{
    (yyval.node) = ASTbinop((yyvsp[-2].node), (yyvsp[0].node), BO_div);
}
#line 2274 "parser.tab.c"
    break;

  case 76: /* arithmetic: expr PERCENT expr  */
#line 534 "./src/scanparse/parser.y"
{
    (yyval.node) = ASTbinop((yyvsp[-2].node), (yyvsp[0].node), BO_mod);
}
#line 2282 "parser.tab.c"
    break;

  case 77: /* arithmetic: expr LT expr  */
#line 538 "./src/scanparse/parser.y"
{
    (yyval.node) = ASTbinop((yyvsp[-2].node), (yyvsp[0].node), BO_lt);
}
#line 2290 "parser.tab.c"
    break;

  case 78: /* arithmetic: expr LE expr  */
#line 542 "./src/scanparse/parser.y"
{
    (yyval.node) = ASTbinop((yyvsp[-2].node), (yyvsp[0].node), BO_le);
}
#line 2298 "parser.tab.c"
    break;

  case 79: /* arithmetic: expr GT expr  */
#line 546 "./src/scanparse/parser.y"
{
    (yyval.node) = ASTbinop((yyvsp[-2].node), (yyvsp[0].node), BO_gt);
}
#line 2306 "parser.tab.c"
    break;

  case 80: /* arithmetic: expr GE expr  */
#line 550 "./src/scanparse/parser.y"
{
    (yyval.node) = ASTbinop((yyvsp[-2].node), (yyvsp[0].node), BO_ge);
}
#line 2314 "parser.tab.c"
    break;

  case 81: /* arithmetic: expr EQ expr  */
#line 554 "./src/scanparse/parser.y"
{
    (yyval.node) = ASTbinop((yyvsp[-2].node), (yyvsp[0].node), BO_eq);
}
#line 2322 "parser.tab.c"
    break;

  case 82: /* arithmetic: expr NE expr  */
#line 558 "./src/scanparse/parser.y"
{
    (yyval.node) = ASTbinop((yyvsp[-2].node), (yyvsp[0].node), BO_ne);
}
#line 2330 "parser.tab.c"
    break;

  case 83: /* arithmetic: expr AND expr  */
#line 562 "./src/scanparse/parser.y"
{
    (yyval.node) = ASTbinop((yyvsp[-2].node), (yyvsp[0].node), BO_and);
}
#line 2338 "parser.tab.c"
    break;

  case 84: /* arithmetic: expr OR expr  */
#line 566 "./src/scanparse/parser.y"
{
    (yyval.node) = ASTbinop((yyvsp[-2].node), (yyvsp[0].node), BO_or);
}
#line 2346 "parser.tab.c"
    break;

  case 85: /* arithmetic: BRACKET_L expr BRACKET_R  */
#line 570 "./src/scanparse/parser.y"
{
    (yyval.node) = (yyvsp[-1].node);
}
#line 2354 "parser.tab.c"
    break;

  case 86: /* cast: BRACKET_L type BRACKET_R expr  */
#line 576 "./src/scanparse/parser.y"
  {
    (yyval.node) = ASTcast((yyvsp[0].node), (yyvsp[-2].ctype));
  }
#line 2362 "parser.tab.c"
    break;

  case 87: /* expr: constant  */
#line 581 "./src/scanparse/parser.y"
               { (yyval.node) = (yyvsp[0].node); }
#line 2368 "parser.tab.c"
    break;

  case 88: /* expr: ID  */
#line 582 "./src/scanparse/parser.y"
        {(yyval.node) = ASTvar((yyvsp[0].id));}
#line 2374 "parser.tab.c"
    break;

  case 92: /* constant: floatval  */
#line 589 "./src/scanparse/parser.y"
  {
    (yyval.node) = (yyvsp[0].node);
  }
#line 2382 "parser.tab.c"
    break;

  case 93: /* constant: intval  */
#line 593 "./src/scanparse/parser.y"
  {
    (yyval.node) = (yyvsp[0].node);
  }
#line 2390 "parser.tab.c"
    break;

  case 94: /* constant: boolval  */
#line 597 "./src/scanparse/parser.y"
  {
    (yyval.node) = (yyvsp[0].node);
  }
#line 2398 "parser.tab.c"
    break;

  case 95: /* type: TYPE_INT  */
#line 601 "./src/scanparse/parser.y"
                 { (yyval.ctype) = CT_int; }
#line 2404 "parser.tab.c"
    break;

  case 96: /* type: TYPE_FLOAT  */
#line 602 "./src/scanparse/parser.y"
                 { (yyval.ctype) = CT_float; }
#line 2410 "parser.tab.c"
    break;

  case 97: /* type: TYPE_BOOL  */
#line 603 "./src/scanparse/parser.y"
                 { (yyval.ctype) = CT_bool; }
#line 2416 "parser.tab.c"
    break;

  case 98: /* type: TYPE_VOID  */
#line 604 "./src/scanparse/parser.y"
                 { (yyval.ctype) = CT_void; }
#line 2422 "parser.tab.c"
    break;

  case 99: /* floatval: FLOAT  */
#line 607 "./src/scanparse/parser.y"
  {
    (yyval.node) = ASTfloat((yyvsp[0].cflt));
  }
#line 2430 "parser.tab.c"
    break;

  case 100: /* intval: NUM  */
#line 612 "./src/scanparse/parser.y"
  {
    (yyval.node) = ASTnum((yyvsp[0].cint));
  }
#line 2438 "parser.tab.c"
    break;

  case 101: /* boolval: TRUEVAL  */
#line 617 "./src/scanparse/parser.y"
  {
    (yyval.node) = ASTbool(true);
  }
#line 2446 "parser.tab.c"
    break;

  case 102: /* boolval: FALSEVAL  */
#line 621 "./src/scanparse/parser.y"
  {
    (yyval.node) = ASTbool(false);
  }
#line 2454 "parser.tab.c"
    break;


#line 2458 "parser.tab.c"

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

#line 624 "./src/scanparse/parser.y"


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

//own function to create the indices based on the array lenght
node_st *generate_indices(node_st *length_node) {
    node_st *expr_list = NULL;
    for (int i = 0; i < NUM_VAL(length_node); i++) {
        
        node_st *num_node = ASTnum(i);
        
        expr_list = ASTexprs(num_node, expr_list);
    }
    return expr_list;
}



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
