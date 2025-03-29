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
#line 1 "src/scanparse/parser.y"



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
  node_st *generate_matrix_indices(int width, int height);


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
    TYPE_ARRAY = 297,              /* TYPE_ARRAY  */
    IF = 298,                      /* IF  */
    ELSE = 299,                    /* ELSE  */
    IF_WITHOUT_ELSE = 300,         /* IF_WITHOUT_ELSE  */
    WHILE = 301,                   /* WHILE  */
    DO = 302,                      /* DO  */
    FOR = 303,                     /* FOR  */
    EXTERN = 304,                  /* EXTERN  */
    LOWER = 305,                   /* LOWER  */
    HIGHER = 306,                  /* HIGHER  */
    FUNDEC = 307                   /* FUNDEC  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 26 "src/scanparse/parser.y"

	 char               *id;
	 int                 cint;
	 float               cflt;
	 enum BinOpType     cbinop;
	 enum Type           ctype;
	 node_st             *node;

#line 203 "parser.tab.c"

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
  YYSYMBOL_TYPE_ARRAY = 42,                /* TYPE_ARRAY  */
  YYSYMBOL_IF = 43,                        /* IF  */
  YYSYMBOL_ELSE = 44,                      /* ELSE  */
  YYSYMBOL_IF_WITHOUT_ELSE = 45,           /* IF_WITHOUT_ELSE  */
  YYSYMBOL_WHILE = 46,                     /* WHILE  */
  YYSYMBOL_DO = 47,                        /* DO  */
  YYSYMBOL_FOR = 48,                       /* FOR  */
  YYSYMBOL_EXTERN = 49,                    /* EXTERN  */
  YYSYMBOL_50_ = 50,                       /* '='  */
  YYSYMBOL_LOWER = 51,                     /* LOWER  */
  YYSYMBOL_HIGHER = 52,                    /* HIGHER  */
  YYSYMBOL_FUNDEC = 53,                    /* FUNDEC  */
  YYSYMBOL_YYACCEPT = 54,                  /* $accept  */
  YYSYMBOL_program = 55,                   /* program  */
  YYSYMBOL_decls = 56,                     /* decls  */
  YYSYMBOL_ids = 57,                       /* ids  */
  YYSYMBOL_decl = 58,                      /* decl  */
  YYSYMBOL_fun_dec = 59,                   /* fun_dec  */
  YYSYMBOL_glob_decl = 60,                 /* glob_decl  */
  YYSYMBOL_glob_def = 61,                  /* glob_def  */
  YYSYMBOL_stmts = 62,                     /* stmts  */
  YYSYMBOL_stmt = 63,                      /* stmt  */
  YYSYMBOL_funContents = 64,               /* funContents  */
  YYSYMBOL_funContent = 65,                /* funContent  */
  YYSYMBOL_fundef = 66,                    /* fundef  */
  YYSYMBOL_funbody = 67,                   /* funbody  */
  YYSYMBOL_exprs = 68,                     /* exprs  */
  YYSYMBOL_var_decl = 69,                  /* var_decl  */
  YYSYMBOL_assign = 70,                    /* assign  */
  YYSYMBOL_return_stmt = 71,               /* return_stmt  */
  YYSYMBOL_if_stmt = 72,                   /* if_stmt  */
  YYSYMBOL_while_stmt = 73,                /* while_stmt  */
  YYSYMBOL_do_while_stmt = 74,             /* do_while_stmt  */
  YYSYMBOL_for_stmt = 75,                  /* for_stmt  */
  YYSYMBOL_param = 76,                     /* param  */
  YYSYMBOL_varlet = 77,                    /* varlet  */
  YYSYMBOL_args = 78,                      /* args  */
  YYSYMBOL_call = 79,                      /* call  */
  YYSYMBOL_arithmetic = 80,                /* arithmetic  */
  YYSYMBOL_cast = 81,                      /* cast  */
  YYSYMBOL_arrVar = 82,                    /* arrVar  */
  YYSYMBOL_matVar = 83,                    /* matVar  */
  YYSYMBOL_arrVarlet = 84,                 /* arrVarlet  */
  YYSYMBOL_matVarlet = 85,                 /* matVarlet  */
  YYSYMBOL_arrExpr = 86,                   /* arrExpr  */
  YYSYMBOL_expr = 87,                      /* expr  */
  YYSYMBOL_constant = 88,                  /* constant  */
  YYSYMBOL_type = 89,                      /* type  */
  YYSYMBOL_floatval = 90,                  /* floatval  */
  YYSYMBOL_intval = 91,                    /* intval  */
  YYSYMBOL_boolval = 92                    /* boolval  */
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
typedef yytype_int16 yy_state_t;

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
#define YYFINAL  18
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1357

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  54
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  39
/* YYNRULES -- Number of rules.  */
#define YYNRULES  129
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  306

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   307


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
       2,    50,     2,     2,     2,     2,     2,     2,     2,     2,
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
      45,    46,    47,    48,    49,    51,    52,    53
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   106,   106,   113,   118,   125,   131,   141,   145,   149,
     153,   158,   163,   170,   177,   183,   188,   193,   198,   203,
     208,   213,   218,   223,   228,   233,   239,   244,   255,   256,
     257,   258,   259,   260,   261,   264,   268,   273,   274,   275,
     278,   284,   290,   296,   303,   310,   314,   320,   326,   343,
     355,   406,   420,   435,   441,   447,   453,   458,   464,   469,
     474,   480,   486,   494,   499,   505,   510,   516,   525,   533,
     540,   547,   554,   561,   567,   573,   580,   587,   594,   600,
     607,   619,   625,   632,   637,   642,   647,   652,   657,   662,
     667,   672,   677,   682,   687,   692,   697,   702,   707,   712,
     717,   722,   729,   736,   743,   748,   754,   760,   765,   766,
     779,   780,   784,   785,   786,   787,   790,   794,   798,   803,
     804,   805,   806,   807,   809,   814,   820,   825,   831,   836
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
  "TYPE_VOID", "TYPE_ARRAY", "IF", "ELSE", "IF_WITHOUT_ELSE", "WHILE",
  "DO", "FOR", "EXTERN", "'='", "LOWER", "HIGHER", "FUNDEC", "$accept",
  "program", "decls", "ids", "decl", "fun_dec", "glob_decl", "glob_def",
  "stmts", "stmt", "funContents", "funContent", "fundef", "funbody",
  "exprs", "var_decl", "assign", "return_stmt", "if_stmt", "while_stmt",
  "do_while_stmt", "for_stmt", "param", "varlet", "args", "call",
  "arithmetic", "cast", "arrVar", "matVar", "arrVarlet", "matVarlet",
  "arrExpr", "expr", "constant", "type", "floatval", "intval", "boolval", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-179)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-107)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -17,    93,  -179,  -179,  -179,  -179,  -179,    93,    18,  -179,
     -17,  -179,  -179,  -179,  -179,     3,    54,   -15,  -179,  -179,
     226,     5,   226,    10,     4,   126,   226,   -18,  -179,  -179,
    -179,  -179,    72,  -179,  -179,  -179,  -179,  -179,  -179,   725,
    -179,  -179,  -179,  -179,   106,  -179,   226,   749,   136,  -179,
     226,   147,  -179,   551,    22,    66,   845,  -179,  -179,   488,
     226,   226,    -6,   226,   226,   226,   226,   226,   226,   226,
     226,   226,   226,   226,   226,   226,   226,   226,   226,   226,
     226,    75,    82,    80,   916,   226,    56,    75,   113,   939,
     115,   132,  -179,   226,  -179,   226,  -179,   134,   869,   773,
    1234,    87,    65,    65,  -179,  -179,  -179,   252,   252,   252,
     252,   277,   277,   305,   365,  1328,  1328,  1328,  1328,  1328,
      62,  -179,    75,    85,   120,  -179,  1253,   118,  -179,    75,
    -179,  -179,   133,  1328,  -179,  -179,   226,   226,  -179,   107,
    -179,   226,    74,    93,   495,   145,   175,   186,   187,  -179,
     183,    62,  -179,  -179,  -179,  -179,  -179,  -179,  -179,  -179,
     161,   163,   169,   962,   119,  -179,   196,   194,    93,   172,
    -179,   226,  -179,  -179,  -179,  1272,   121,   985,   226,   173,
    -179,  1008,   226,   226,   240,   164,    93,  -179,  -179,   226,
     226,   226,  -179,   226,    81,    85,   176,  -179,   148,  1031,
    -179,  -179,   226,  -179,   797,   210,  -179,   576,   601,   178,
     206,   448,   221,   191,  1054,  1077,  1100,   821,  -179,   226,
    -179,   229,  -179,   226,  -179,  1123,   226,   195,   268,   231,
     233,   199,  -179,   226,   208,  -179,  -179,  -179,   226,   207,
    1146,    93,  1169,  -179,  1291,   448,   197,   300,   226,   242,
     626,   226,  1310,   177,  -179,  -179,  -179,   219,   244,   448,
    -179,   245,   651,   226,   251,   893,   227,  -179,   226,   235,
    -179,  -179,   274,   676,  -179,   226,   190,  1192,    -7,  -179,
     275,   526,  -179,   226,  -179,   448,  -179,  -179,   328,   226,
    1215,   276,   360,  -179,   701,  -179,  -179,  -179,   291,   388,
    -179,   420,  -179,  -179,   297,  -179
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,   119,   120,   121,   122,   123,     0,     0,     2,
       4,    10,     7,     9,     8,     0,     0,     0,     1,     3,
       0,     0,     0,     0,     0,     0,     0,     0,   128,   129,
     126,   124,   111,   112,   114,   113,   108,   109,   115,     0,
     110,   116,   117,   118,     0,    25,     0,     0,     0,    24,
       0,     0,    13,     0,     0,     0,    45,   127,   125,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   101,     0,   107,     0,    82,     0,    79,     0,
       0,     0,    84,    83,    85,    86,    87,    89,    88,    91,
      90,    92,    93,    95,    94,    96,    97,    98,    99,   100,
      36,    43,     0,     0,    74,    23,     0,     0,    41,     0,
      22,    12,     0,   102,    46,    81,     0,     0,   103,     0,
      20,     0,   111,     0,     0,     0,     0,     0,     0,    38,
       0,    36,    37,    39,    28,    32,    29,    30,    31,    33,
       0,     0,     0,     0,     0,    42,     5,     0,     0,     0,
      16,     0,    40,    11,    80,     0,     0,     0,     0,     0,
      57,     0,     0,     0,     0,     0,     0,    44,    35,     0,
       0,     0,    34,     0,     0,     0,     0,    75,     0,     0,
     104,    21,     0,    19,     0,     0,    56,     0,     0,     0,
       0,    27,     0,     0,     0,     0,     0,     0,    47,     0,
       6,    76,    17,     0,    14,     0,     0,   103,     0,     0,
       0,     0,    26,     0,     0,    53,    54,    55,     0,     0,
       0,     0,     0,    18,     0,     0,    61,     0,     0,     0,
       0,     0,     0,     0,    48,    77,    15,   104,     0,     0,
      64,     0,     0,     0,     0,     0,     0,    49,     0,    60,
      62,    63,     0,     0,    67,     0,     0,     0,     0,    66,
       0,     0,    50,     0,    52,     0,    58,    65,     0,     0,
       0,     0,     0,    72,     0,    51,    59,    68,     0,     0,
      70,     0,    73,    69,     0,    71
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -179,  -179,   298,    89,  -179,  -179,  -179,  -179,  -178,  -116,
     156,  -179,  -117,   -59,   218,  -179,  -179,  -179,    50,  -179,
    -179,  -179,   -41,  -179,   203,  -179,  -179,  -179,  -179,  -179,
    -179,  -179,  -179,   -20,  -179,    61,  -179,  -179,  -179
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     8,     9,   167,    10,    11,    12,    13,   210,   211,
     150,   151,    14,   121,    55,   153,   154,   155,   156,   157,
     158,   159,    82,   160,    97,    33,    34,    35,    36,    37,
     161,   162,    38,   163,    40,    83,    41,    42,    43
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      39,   285,    47,   152,   149,    53,    56,    88,    51,    44,
      91,    52,    45,    20,    48,    57,    58,    49,    18,     1,
      24,     2,     3,     4,     5,     6,    84,    93,   128,   101,
      89,   185,     7,   232,   152,   149,   145,    46,    21,    98,
      99,   100,    50,   102,   103,   104,   105,   106,   107,   108,
     109,   110,   111,   112,   113,   114,   115,   116,   117,   118,
     119,    15,    16,   165,    22,   126,    25,   258,    17,   261,
     172,    15,    26,   133,    27,    56,    59,    94,    59,    65,
      66,    67,    60,   120,   178,    44,    54,   122,   218,    23,
     123,   127,    28,    29,   140,    30,    31,   142,   143,   144,
       2,     3,     4,     5,     6,   145,   -78,   291,   146,   147,
     148,    81,   246,   219,   298,   124,    98,   175,   129,   141,
     166,   177,   131,   304,   181,   170,   168,   197,   201,   193,
      25,     2,     3,     4,     5,     6,    26,   132,    27,   135,
     173,    87,   176,   270,     2,     3,     4,     5,     6,   182,
     171,   199,    90,   202,   194,   222,    28,    29,   204,    30,
      31,    32,   207,   208,     2,     3,     4,     5,     6,   214,
     215,   216,   293,   217,     2,     3,     4,     5,     6,   183,
     223,   164,   225,   302,   267,     2,     3,     4,     5,     6,
      25,   186,   187,   189,   184,   190,    26,   282,    27,   240,
     255,   191,   195,   242,   179,   196,   244,   198,   205,   268,
     212,   221,   164,   250,    48,   231,    28,    29,   252,    30,
      31,   142,   283,   144,   230,   233,   234,  -105,   262,   145,
      25,   265,   146,   147,   148,   241,    26,   248,    27,   247,
     251,   259,   253,   273,    25,   249,   263,   213,   277,   209,
      26,  -106,    27,   269,   271,   281,    28,    29,   274,    30,
      31,    32,   276,   290,    63,    64,    65,    66,    67,   294,
      28,    29,    25,    30,    31,   142,   245,   144,    26,   278,
      27,   279,   287,   145,   220,   296,   146,   147,   148,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    28,    29,
     300,    30,    31,   142,    25,   144,   305,   188,    19,   260,
      26,   145,    27,   134,   146,   147,   148,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,   286,    75,
      28,    29,    25,    30,    31,   142,   292,   144,    26,   174,
      27,     0,     0,   145,     0,     0,   146,   147,   148,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    28,    29,
       0,    30,    31,   142,    25,   144,     0,     0,     0,   297,
      26,   145,    27,     0,   146,   147,   148,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,     0,     0,
      28,    29,    25,    30,    31,   142,   301,   144,    26,     0,
      27,     0,     0,   145,     0,     0,   146,   147,   148,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    28,    29,
       0,    30,    31,   142,    25,   144,     0,     0,     0,   303,
      26,   145,    27,     0,   146,   147,   148,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      28,    29,    25,    30,    31,   142,     0,   144,    26,     0,
      27,     0,     0,   145,     0,     0,   146,   147,   148,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    28,    29,
       0,    30,    31,   142,     0,   144,     0,     0,     0,     0,
       0,   145,    25,    96,   146,   147,   148,     0,    26,    25,
      27,     0,   180,     0,     0,    26,     0,    27,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    28,    29,
       0,    30,    31,    32,     0,    28,    29,     0,    30,    31,
      32,   288,   289,     0,     0,     0,     0,     0,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    92,     0,     0,     0,
       0,     0,     0,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,   228,     0,     0,     0,     0,     0,     0,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,   229,     0,     0,     0,
       0,     0,     0,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,   264,     0,     0,     0,     0,     0,     0,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,   272,     0,     0,     0,
       0,     0,     0,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,   280,     0,     0,     0,     0,     0,     0,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,   299,     0,     0,     0,
       0,     0,     0,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    61,     0,     0,     0,     0,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    85,     0,     0,     0,     0,
      86,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,   137,
       0,     0,     0,     0,   138,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,   226,     0,     0,     0,     0,   227,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,   238,     0,     0,
       0,     0,   239,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    95,     0,     0,     0,     0,     0,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,   136,     0,     0,     0,     0,
       0,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,   275,
       0,     0,     0,     0,     0,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,   125,     0,     0,     0,     0,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,   130,     0,     0,     0,
       0,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,   192,
       0,     0,     0,     0,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,   203,     0,     0,     0,     0,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,   206,     0,     0,     0,     0,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,   224,     0,
       0,     0,     0,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,   235,     0,     0,     0,     0,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,   236,     0,     0,     0,     0,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,   237,     0,     0,
       0,     0,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
     243,     0,     0,     0,     0,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,   254,     0,     0,     0,     0,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,   256,     0,     0,     0,
       0,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,   284,
       0,     0,     0,     0,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,   295,     0,     0,     0,     0,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,   139,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,   169,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,   200,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,   257,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,   266,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80
};

static const yytype_int16 yycheck[] =
{
      20,     8,    22,   120,   120,    25,    26,    48,     4,     4,
      51,     7,     7,    10,     4,    33,    34,     7,     0,    36,
      35,    38,    39,    40,    41,    42,    46,     5,    87,    35,
      50,   147,    49,   211,   151,   151,    43,    32,    35,    59,
      60,    61,    32,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,     0,     1,   122,    10,    85,     4,   245,     7,   247,
     129,    10,    10,    93,    12,    95,     4,    11,     4,    14,
      15,    16,    10,     8,    10,     4,    25,     5,     7,    35,
      10,    35,    30,    31,     7,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    43,    32,   285,    46,    47,
      48,     5,   228,    32,   292,    35,   136,   137,     5,    32,
      35,   141,     7,   301,   144,     7,     6,   168,     7,    10,
       4,    38,    39,    40,    41,    42,    10,     5,    12,     5,
       7,     5,    35,   259,    38,    39,    40,    41,    42,     4,
      32,   171,     5,    32,    35,     7,    30,    31,   178,    33,
      34,    35,   182,   183,    38,    39,    40,    41,    42,   189,
     190,   191,   288,   193,    38,    39,    40,    41,    42,     4,
      32,   120,   202,   299,     7,    38,    39,    40,    41,    42,
       4,     4,     9,    32,     8,    32,    10,     7,    12,   219,
     241,    32,     6,   223,   143,    11,   226,    35,    35,    32,
      46,    35,   151,   233,     4,     9,    30,    31,   238,    33,
      34,    35,    32,    37,    46,     4,    35,    32,   248,    43,
       4,   251,    46,    47,    48,     6,    10,     4,    12,     8,
      32,    44,    35,   263,     4,    46,     4,   186,   268,     9,
      10,    32,    12,     9,     9,   275,    30,    31,     7,    33,
      34,    35,    35,   283,    12,    13,    14,    15,    16,   289,
      30,    31,     4,    33,    34,    35,     8,    37,    10,    44,
      12,     7,     7,    43,   195,     9,    46,    47,    48,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    30,    31,
       9,    33,    34,    35,     4,    37,     9,   151,    10,     9,
      10,    43,    12,    95,    46,    47,    48,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,   278,    24,
      30,    31,     4,    33,    34,    35,     8,    37,    10,   136,
      12,    -1,    -1,    43,    -1,    -1,    46,    47,    48,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,    31,
      -1,    33,    34,    35,     4,    37,    -1,    -1,    -1,     9,
      10,    43,    12,    -1,    46,    47,    48,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    -1,    -1,
      30,    31,     4,    33,    34,    35,     8,    37,    10,    -1,
      12,    -1,    -1,    43,    -1,    -1,    46,    47,    48,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,    31,
      -1,    33,    34,    35,     4,    37,    -1,    -1,    -1,     9,
      10,    43,    12,    -1,    46,    47,    48,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      30,    31,     4,    33,    34,    35,    -1,    37,    10,    -1,
      12,    -1,    -1,    43,    -1,    -1,    46,    47,    48,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,    31,
      -1,    33,    34,    35,    -1,    37,    -1,    -1,    -1,    -1,
      -1,    43,     4,     5,    46,    47,    48,    -1,    10,     4,
      12,    -1,     7,    -1,    -1,    10,    -1,    12,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,    31,
      -1,    33,    34,    35,    -1,    30,    31,    -1,    33,    34,
      35,     5,     6,    -1,    -1,    -1,    -1,    -1,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,     5,    -1,    -1,    -1,
      -1,    -1,    -1,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,     5,    -1,    -1,    -1,    -1,    -1,    -1,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,     5,    -1,    -1,    -1,
      -1,    -1,    -1,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,     5,    -1,    -1,    -1,    -1,    -1,    -1,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,     5,    -1,    -1,    -1,
      -1,    -1,    -1,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,     5,    -1,    -1,    -1,    -1,    -1,    -1,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,     5,    -1,    -1,    -1,
      -1,    -1,    -1,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,     6,    -1,    -1,    -1,    -1,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,     6,    -1,    -1,    -1,    -1,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,     6,
      -1,    -1,    -1,    -1,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,     6,    -1,    -1,    -1,    -1,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,     6,    -1,    -1,
      -1,    -1,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,     6,    -1,    -1,    -1,    -1,    -1,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,     6,    -1,    -1,    -1,    -1,
      -1,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,     6,
      -1,    -1,    -1,    -1,    -1,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,     7,    -1,    -1,    -1,    -1,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,     7,    -1,    -1,    -1,
      -1,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,     7,
      -1,    -1,    -1,    -1,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,     7,    -1,    -1,    -1,    -1,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,     7,    -1,    -1,    -1,    -1,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,     7,    -1,
      -1,    -1,    -1,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,     7,    -1,    -1,    -1,    -1,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,     7,    -1,    -1,    -1,    -1,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,     7,    -1,    -1,
      -1,    -1,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
       7,    -1,    -1,    -1,    -1,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,     7,    -1,    -1,    -1,    -1,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,     7,    -1,    -1,    -1,
      -1,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,     7,
      -1,    -1,    -1,    -1,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,     7,    -1,    -1,    -1,    -1,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    11,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    36,    38,    39,    40,    41,    42,    49,    55,    56,
      58,    59,    60,    61,    66,    89,    89,    89,     0,    56,
      10,    35,    10,    35,    35,     4,    10,    12,    30,    31,
      33,    34,    35,    79,    80,    81,    82,    83,    86,    87,
      88,    90,    91,    92,     4,     7,    32,    87,     4,     7,
      32,     4,     7,    87,    89,    68,    87,    33,    34,     4,
      10,     6,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,     5,    76,    89,    87,     6,    11,     5,    76,    87,
       5,    76,     5,     5,    11,     6,     5,    78,    87,    87,
      87,    35,    87,    87,    87,    87,    87,    87,    87,    87,
      87,    87,    87,    87,    87,    87,    87,    87,    87,    87,
       8,    67,     5,    10,    35,     7,    87,    35,    67,     5,
       7,     7,     5,    87,    68,     5,     6,     6,    11,    11,
       7,    32,    35,    36,    37,    43,    46,    47,    48,    63,
      64,    65,    66,    69,    70,    71,    72,    73,    74,    75,
      77,    84,    85,    87,    89,    67,    35,    57,     6,    11,
       7,    32,    67,     7,    78,    87,    35,    87,    10,    89,
       7,    87,     4,     4,     8,    63,     4,     9,    64,    32,
      32,    32,     7,    10,    35,     6,    11,    76,    35,    87,
      11,     7,    32,     7,    87,    35,     7,    87,    87,     9,
      62,    63,    46,    89,    87,    87,    87,    87,     7,    32,
      57,    35,     7,    32,     7,    87,     6,    11,     5,     5,
      46,     9,    62,     4,    35,     7,     7,     7,     6,    11,
      87,     6,    87,     7,    87,     8,    63,     8,     4,    46,
      87,    32,    87,    35,     7,    76,     7,    11,    62,    44,
       9,    62,    87,     4,     5,    87,    11,     7,    32,     9,
      63,     9,     5,    87,     7,     6,    35,    87,    44,     7,
       5,    87,     7,    32,     7,     8,    72,     7,     5,     6,
      87,    62,     8,    63,    87,     7,     9,     9,    62,     5,
       9,     8,    63,     9,    62,     9
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    54,    55,    56,    56,    57,    57,    58,    58,    58,
      58,    59,    59,    60,    61,    61,    61,    61,    61,    61,
      61,    61,    61,    61,    61,    61,    62,    62,    63,    63,
      63,    63,    63,    63,    63,    64,    64,    65,    65,    65,
      66,    66,    66,    66,    67,    68,    68,    69,    69,    69,
      69,    69,    69,    70,    70,    70,    71,    71,    72,    72,
      72,    72,    72,    73,    73,    74,    74,    74,    75,    75,
      75,    75,    75,    75,    76,    76,    76,    76,    77,    78,
      78,    79,    79,    80,    80,    80,    80,    80,    80,    80,
      80,    80,    80,    80,    80,    80,    80,    80,    80,    80,
      80,    80,    81,    82,    83,    84,    85,    86,    86,    86,
      87,    87,    87,    87,    87,    87,    88,    88,    88,    89,
      89,    89,    89,    89,    90,    90,    91,    91,    92,    92
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     3,     1,     1,     1,
       1,     7,     6,     4,     9,    11,     7,     9,    10,     8,
       6,     8,     6,     5,     4,     3,     2,     1,     1,     1,
       1,     1,     1,     1,     2,     2,     0,     1,     1,     1,
       7,     6,     6,     5,     3,     1,     3,     3,     5,     6,
       8,    10,     8,     4,     4,     4,     3,     2,     9,    11,
       7,     5,     7,     7,     6,     9,     8,     7,    11,    13,
      12,    14,    10,    12,     2,     4,     5,     7,     1,     1,
       3,     4,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     4,     4,     6,     4,     6,     3,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     2,     1,     2,     1,     1
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
#line 107 "src/scanparse/parser.y"
        {
		parseresult = ASTprogram((yyvsp[0].node));
		AddLocToNode(parseresult, &(yylsp[0]), &(yylsp[0]));
	}
#line 1812 "parser.tab.c"
    break;

  case 3: /* decls: decl decls  */
#line 114 "src/scanparse/parser.y"
        {
		(yyval.node) = ASTdecls((yyvsp[-1].node), (yyvsp[0].node));
		AddLocToNode((yyval.node), &(yylsp[-1]), &(yylsp[0]));
	}
#line 1821 "parser.tab.c"
    break;

  case 4: /* decls: decl  */
#line 119 "src/scanparse/parser.y"
        {
		(yyval.node) = ASTdecls((yyvsp[0].node), NULL);
		AddLocToNode((yyval.node), &(yylsp[0]), &(yylsp[0]));
	}
#line 1830 "parser.tab.c"
    break;

  case 5: /* ids: ID  */
#line 126 "src/scanparse/parser.y"
  {
    //single dimensions
    (yyval.node) = ASTids(NULL, (yyvsp[0].id));
  }
#line 1839 "parser.tab.c"
    break;

  case 6: /* ids: ID COMMA ids  */
#line 132 "src/scanparse/parser.y"
  {
    //multi dimensional
    (yyval.node) = ASTids((yyvsp[0].node), (yyvsp[-2].id));  
  }
#line 1848 "parser.tab.c"
    break;

  case 7: /* decl: glob_decl  */
#line 142 "src/scanparse/parser.y"
  {
    (yyval.node) = (yyvsp[0].node);
  }
#line 1856 "parser.tab.c"
    break;

  case 8: /* decl: fundef  */
#line 146 "src/scanparse/parser.y"
  {
    (yyval.node) = (yyvsp[0].node);
  }
#line 1864 "parser.tab.c"
    break;

  case 9: /* decl: glob_def  */
#line 150 "src/scanparse/parser.y"
  {
    (yyval.node) = (yyvsp[0].node);
  }
#line 1872 "parser.tab.c"
    break;

  case 10: /* decl: fun_dec  */
#line 154 "src/scanparse/parser.y"
  {
    (yyval.node) = (yyvsp[0].node);
  }
#line 1880 "parser.tab.c"
    break;

  case 11: /* fun_dec: EXTERN type ID BRACKET_L param BRACKET_R SEMICOLON  */
#line 159 "src/scanparse/parser.y"
  {
    (yyval.node) = ASTfundec((yyvsp[-2].node), (yyvsp[-4].id), (yyvsp[-5].ctype));
    AddLocToNode((yyval.node), &(yylsp[-6]), &(yylsp[-1]));
  }
#line 1889 "parser.tab.c"
    break;

  case 12: /* fun_dec: EXTERN type ID BRACKET_L BRACKET_R SEMICOLON  */
#line 164 "src/scanparse/parser.y"
  {
    (yyval.node) = ASTfundec(NULL, (yyvsp[-3].id), (yyvsp[-4].ctype));
    AddLocToNode((yyval.node), &(yylsp[-5]), &(yylsp[-1]));
  }
#line 1898 "parser.tab.c"
    break;

  case 13: /* glob_decl: EXTERN type ID SEMICOLON  */
#line 171 "src/scanparse/parser.y"
  {
    (yyval.node) = ASTglobdecl(NULL, (yyvsp[-1].id), (yyvsp[-2].ctype));
    AddLocToNode((yyval.node), &(yylsp[-3]), &(yylsp[0]));
  }
#line 1907 "parser.tab.c"
    break;

  case 14: /* glob_def: EXPORT type SQUARE_L expr SQUARE_R ID LET expr SEMICOLON  */
#line 178 "src/scanparse/parser.y"
  {
    (yyval.node) = ASTglobdef(ASTexprs((yyvsp[-5].node), NULL), (yyvsp[-1].node), (yyvsp[-3].id), (yyvsp[-7].ctype), true);
    AddLocToNode((yyval.node), &(yylsp[-8]), &(yylsp[-1]));
  }
#line 1916 "parser.tab.c"
    break;

  case 15: /* glob_def: EXPORT type SQUARE_L expr COMMA expr SQUARE_R ID LET expr SEMICOLON  */
#line 184 "src/scanparse/parser.y"
  {
    (yyval.node) = ASTglobdef(ASTexprs((yyvsp[-7].node), ASTexprs((yyvsp[-5].node), NULL)), (yyvsp[-1].node), (yyvsp[-3].id), (yyvsp[-9].ctype), true);
    AddLocToNode((yyval.node), &(yylsp[-10]), &(yylsp[-1]));
  }
#line 1925 "parser.tab.c"
    break;

  case 16: /* glob_def: EXPORT type SQUARE_L expr SQUARE_R ID SEMICOLON  */
#line 189 "src/scanparse/parser.y"
  {
    (yyval.node) = ASTglobdef(ASTexprs((yyvsp[-3].node), NULL), NULL, (yyvsp[-1].id), (yyvsp[-5].ctype), true);
    AddLocToNode((yyval.node), &(yylsp[-6]), &(yylsp[-1]));
  }
#line 1934 "parser.tab.c"
    break;

  case 17: /* glob_def: EXPORT type SQUARE_L expr COMMA expr SQUARE_R ID SEMICOLON  */
#line 194 "src/scanparse/parser.y"
  {
    (yyval.node) = ASTglobdef(ASTexprs((yyvsp[-5].node), ASTexprs((yyvsp[-3].node), NULL)), NULL, (yyvsp[-1].id), (yyvsp[-7].ctype), true);
    AddLocToNode((yyval.node), &(yylsp[-8]), &(yylsp[-1]));
  }
#line 1943 "parser.tab.c"
    break;

  case 18: /* glob_def: type SQUARE_L expr COMMA expr SQUARE_R ID LET expr SEMICOLON  */
#line 199 "src/scanparse/parser.y"
  {
    (yyval.node) = ASTglobdef(ASTexprs((yyvsp[-7].node), ASTexprs((yyvsp[-5].node), NULL)), (yyvsp[-1].node), (yyvsp[-3].id), (yyvsp[-9].ctype), false);
    AddLocToNode((yyval.node), &(yylsp[-9]), &(yylsp[0]));
  }
#line 1952 "parser.tab.c"
    break;

  case 19: /* glob_def: type SQUARE_L expr SQUARE_R ID LET expr SEMICOLON  */
#line 204 "src/scanparse/parser.y"
  {
    (yyval.node) = ASTglobdef(ASTexprs((yyvsp[-5].node), NULL), (yyvsp[-1].node), (yyvsp[-3].id), (yyvsp[-7].ctype), false);
    AddLocToNode((yyval.node), &(yylsp[-7]), &(yylsp[0]));
  }
#line 1961 "parser.tab.c"
    break;

  case 20: /* glob_def: type SQUARE_L expr SQUARE_R ID SEMICOLON  */
#line 209 "src/scanparse/parser.y"
  {
    (yyval.node) = ASTglobdef(ASTexprs((yyvsp[-3].node), NULL), NULL, (yyvsp[-1].id), (yyvsp[-5].ctype), false);
    AddLocToNode((yyval.node), &(yylsp[-5]), &(yylsp[0]));
  }
#line 1970 "parser.tab.c"
    break;

  case 21: /* glob_def: type SQUARE_L expr COMMA expr SQUARE_R ID SEMICOLON  */
#line 214 "src/scanparse/parser.y"
  {
    (yyval.node) = ASTglobdef(ASTexprs((yyvsp[-5].node), ASTexprs((yyvsp[-3].node), NULL)), NULL, (yyvsp[-1].id), (yyvsp[-7].ctype), false);
    AddLocToNode((yyval.node), &(yylsp[-7]), &(yylsp[-1]));
  }
#line 1979 "parser.tab.c"
    break;

  case 22: /* glob_def: EXPORT type ID LET expr SEMICOLON  */
#line 219 "src/scanparse/parser.y"
  {
    (yyval.node) = ASTglobdef(NULL,(yyvsp[-1].node), (yyvsp[-3].id), (yyvsp[-4].ctype), true);
    AddLocToNode((yyval.node), &(yylsp[-5]), &(yylsp[0]));
  }
#line 1988 "parser.tab.c"
    break;

  case 23: /* glob_def: type ID LET expr SEMICOLON  */
#line 224 "src/scanparse/parser.y"
  {
    (yyval.node) = ASTglobdef(NULL,(yyvsp[-1].node), (yyvsp[-3].id), (yyvsp[-4].ctype), false);
    AddLocToNode((yyval.node), &(yylsp[-4]), &(yylsp[0]));
  }
#line 1997 "parser.tab.c"
    break;

  case 24: /* glob_def: EXPORT type ID SEMICOLON  */
#line 229 "src/scanparse/parser.y"
  {
    (yyval.node) = ASTglobdef(NULL,NULL, (yyvsp[-1].id), (yyvsp[-2].ctype), true);
    AddLocToNode((yyval.node), &(yylsp[-3]), &(yylsp[0]));
  }
#line 2006 "parser.tab.c"
    break;

  case 25: /* glob_def: type ID SEMICOLON  */
#line 234 "src/scanparse/parser.y"
  {
    (yyval.node) = ASTglobdef(NULL,NULL, (yyvsp[-1].id), (yyvsp[-2].ctype), true);
    AddLocToNode((yyval.node), &(yylsp[-2]), &(yylsp[0]));
  }
#line 2015 "parser.tab.c"
    break;

  case 26: /* stmts: stmt stmts  */
#line 240 "src/scanparse/parser.y"
  {
    (yyval.node) = ASTstmts((yyvsp[-1].node), (yyvsp[0].node));
    AddLocToNode((yyval.node), &(yylsp[-1]), &(yylsp[0]));
  }
#line 2024 "parser.tab.c"
    break;

  case 27: /* stmts: stmt  */
#line 245 "src/scanparse/parser.y"
  {
    (yyval.node) = ASTstmts((yyvsp[0].node), NULL);
    AddLocToNode((yyval.node), &(yylsp[0]), &(yylsp[0]));
  }
#line 2033 "parser.tab.c"
    break;

  case 28: /* stmt: assign  */
#line 255 "src/scanparse/parser.y"
              { (yyval.node) = (yyvsp[0].node); }
#line 2039 "parser.tab.c"
    break;

  case 29: /* stmt: if_stmt  */
#line 256 "src/scanparse/parser.y"
              { (yyval.node) = (yyvsp[0].node); }
#line 2045 "parser.tab.c"
    break;

  case 30: /* stmt: while_stmt  */
#line 257 "src/scanparse/parser.y"
                 { (yyval.node) = (yyvsp[0].node); }
#line 2051 "parser.tab.c"
    break;

  case 31: /* stmt: do_while_stmt  */
#line 258 "src/scanparse/parser.y"
                    { (yyval.node) = (yyvsp[0].node); }
#line 2057 "parser.tab.c"
    break;

  case 32: /* stmt: return_stmt  */
#line 259 "src/scanparse/parser.y"
                  { (yyval.node) = (yyvsp[0].node); }
#line 2063 "parser.tab.c"
    break;

  case 33: /* stmt: for_stmt  */
#line 260 "src/scanparse/parser.y"
               { (yyval.node) = (yyvsp[0].node); }
#line 2069 "parser.tab.c"
    break;

  case 34: /* stmt: expr SEMICOLON  */
#line 261 "src/scanparse/parser.y"
                     { (yyval.node) = ASTexprstmt((yyvsp[-1].node));
}
#line 2076 "parser.tab.c"
    break;

  case 35: /* funContents: funContent funContents  */
#line 265 "src/scanparse/parser.y"
  {
    (yyval.node) = ASTfuncontents((yyvsp[-1].node), (yyvsp[0].node));
  }
#line 2084 "parser.tab.c"
    break;

  case 36: /* funContents: %empty  */
#line 269 "src/scanparse/parser.y"
  {
    (yyval.node) = NULL;
  }
#line 2092 "parser.tab.c"
    break;

  case 37: /* funContent: fundef  */
#line 273 "src/scanparse/parser.y"
                   { (yyval.node) = (yyvsp[0].node); }
#line 2098 "parser.tab.c"
    break;

  case 38: /* funContent: stmt  */
#line 274 "src/scanparse/parser.y"
                 { (yyval.node) = (yyvsp[0].node); }
#line 2104 "parser.tab.c"
    break;

  case 39: /* funContent: var_decl  */
#line 275 "src/scanparse/parser.y"
                     { (yyval.node) = (yyvsp[0].node); }
#line 2110 "parser.tab.c"
    break;

  case 40: /* fundef: EXPORT type ID BRACKET_L param BRACKET_R funbody  */
#line 280 "src/scanparse/parser.y"
  {
    (yyval.node) = ASTfundef((yyvsp[-2].node), (yyvsp[0].node), (yyvsp[-4].id), (yyvsp[-5].ctype), true); // Exported function
    AddLocToNode((yyval.node), &(yylsp[-6]), &(yylsp[0]));
  }
#line 2119 "parser.tab.c"
    break;

  case 41: /* fundef: EXPORT type ID BRACKET_L BRACKET_R funbody  */
#line 286 "src/scanparse/parser.y"
  {
    (yyval.node) = ASTfundef(NULL, (yyvsp[0].node), (yyvsp[-3].id), (yyvsp[-4].ctype), true);
    AddLocToNode((yyval.node), &(yylsp[-5]), &(yylsp[0]));
  }
#line 2128 "parser.tab.c"
    break;

  case 42: /* fundef: type ID BRACKET_L param BRACKET_R funbody  */
#line 292 "src/scanparse/parser.y"
  {
    (yyval.node) = ASTfundef((yyvsp[-2].node), (yyvsp[0].node), (yyvsp[-4].id), (yyvsp[-5].ctype), false); // Non-exported function
    AddLocToNode((yyval.node), &(yylsp[-5]), &(yylsp[0]));
  }
#line 2137 "parser.tab.c"
    break;

  case 43: /* fundef: type ID BRACKET_L BRACKET_R funbody  */
#line 298 "src/scanparse/parser.y"
  {
    (yyval.node) = ASTfundef(NULL, (yyvsp[0].node), (yyvsp[-3].id), (yyvsp[-4].ctype), false);
    AddLocToNode((yyval.node), &(yylsp[-4]), &(yylsp[0]));
  }
#line 2146 "parser.tab.c"
    break;

  case 44: /* funbody: CURLY_L funContents CURLY_R  */
#line 304 "src/scanparse/parser.y"
  {
    (yyval.node) = ASTfunbody((yyvsp[-1].node));
    AddLocToNode((yyval.node), &(yylsp[-2]), &(yylsp[0]));
  }
#line 2155 "parser.tab.c"
    break;

  case 45: /* exprs: expr  */
#line 311 "src/scanparse/parser.y"
  {
      (yyval.node) = ASTexprs((yyvsp[0].node), NULL);
  }
#line 2163 "parser.tab.c"
    break;

  case 46: /* exprs: expr COMMA exprs  */
#line 315 "src/scanparse/parser.y"
  {
      (yyval.node) = ASTexprs((yyvsp[-2].node), (yyvsp[0].node));
  }
#line 2171 "parser.tab.c"
    break;

  case 47: /* var_decl: type ID SEMICOLON  */
#line 322 "src/scanparse/parser.y"
  {
    (yyval.node) = ASTvardecl(NULL, NULL, (yyvsp[-1].id), (yyvsp[-2].ctype));
    AddLocToNode((yyval.node), &(yylsp[-2]), &(yylsp[0]));
  }
#line 2180 "parser.tab.c"
    break;

  case 48: /* var_decl: type ID LET expr SEMICOLON  */
#line 328 "src/scanparse/parser.y"
  {
    (yyval.node) = ASTvardecl(NULL, (yyvsp[-1].node), (yyvsp[-3].id), (yyvsp[-4].ctype));
    AddLocToNode((yyval.node), &(yylsp[-4]), &(yylsp[0]));
  }
#line 2189 "parser.tab.c"
    break;

  case 49: /* var_decl: type SQUARE_L expr SQUARE_R ID SEMICOLON  */
#line 345 "src/scanparse/parser.y"
  {
        (yyval.node) = ASTvardecl(ASTexprs((yyvsp[-3].node), NULL),
            NULL,
            (yyvsp[-1].id),
            (yyvsp[-5].ctype)
        );
    AddLocToNode((yyval.node), &(yylsp[-5]), &(yylsp[0]));
  }
#line 2202 "parser.tab.c"
    break;

  case 50: /* var_decl: type SQUARE_L expr COMMA expr SQUARE_R ID SEMICOLON  */
#line 357 "src/scanparse/parser.y"
  {
      (yyval.node) = ASTvardecl(
          ASTexprs(
              (yyvsp[-5].node),  
              ASTexprs(
                  (yyvsp[-3].node),
                  NULL
              )
          ),
          NULL,  
          (yyvsp[-1].id),    
          (yyvsp[-7].ctype)
      );
    AddLocToNode((yyval.node), &(yylsp[-7]), &(yylsp[-1]));
  }
#line 2222 "parser.tab.c"
    break;

  case 51: /* var_decl: type SQUARE_L expr COMMA expr SQUARE_R ID LET expr SEMICOLON  */
#line 407 "src/scanparse/parser.y"
{
      //construct dimensions
    node_st *dims = ASTexprs((yyvsp[-7].node), ASTexprs((yyvsp[-5].node), NULL));

    //create vardecl
    (yyval.node) = ASTvardecl(
        dims,
        (yyvsp[-1].node),
        (yyvsp[-3].id),
        (yyvsp[-9].ctype)
    );
    AddLocToNode((yyval.node), &(yylsp[-9]), &(yylsp[0]));
}
#line 2240 "parser.tab.c"
    break;

  case 52: /* var_decl: type SQUARE_L expr SQUARE_R ID LET expr SEMICOLON  */
#line 421 "src/scanparse/parser.y"
{
    //construct dimensions
    node_st *dims = ASTexprs((yyvsp[-5].node), NULL);

    //create vardecl
    (yyval.node) = ASTvardecl(
        dims,
        (yyvsp[-1].node),
        (yyvsp[-3].id),
        (yyvsp[-7].ctype)
    );
    AddLocToNode((yyval.node), &(yylsp[-7]), &(yylsp[0]));
}
#line 2258 "parser.tab.c"
    break;

  case 53: /* assign: varlet LET expr SEMICOLON  */
#line 436 "src/scanparse/parser.y"
{
  (yyval.node) = ASTassign((yyvsp[-3].node), (yyvsp[-1].node));
  AddLocToNode((yyval.node), &(yylsp[-3]), &(yylsp[0]));
}
#line 2267 "parser.tab.c"
    break;

  case 54: /* assign: arrVarlet LET expr SEMICOLON  */
#line 442 "src/scanparse/parser.y"
{
  (yyval.node) = ASTassign((yyvsp[-3].node), (yyvsp[-1].node));
  AddLocToNode((yyval.node), &(yylsp[-3]), &(yylsp[0]));
}
#line 2276 "parser.tab.c"
    break;

  case 55: /* assign: matVarlet LET expr SEMICOLON  */
#line 448 "src/scanparse/parser.y"
{
  (yyval.node) = ASTassign((yyvsp[-3].node), (yyvsp[-1].node));
  AddLocToNode((yyval.node), &(yylsp[-3]), &(yylsp[0]));
}
#line 2285 "parser.tab.c"
    break;

  case 56: /* return_stmt: RETURN expr SEMICOLON  */
#line 454 "src/scanparse/parser.y"
  {
    (yyval.node) = ASTreturn((yyvsp[-1].node));
    AddLocToNode((yyval.node), &(yylsp[-2]), &(yylsp[0]));
  }
#line 2294 "parser.tab.c"
    break;

  case 57: /* return_stmt: RETURN SEMICOLON  */
#line 459 "src/scanparse/parser.y"
  {
    (yyval.node) = ASTreturn(NULL);
    AddLocToNode((yyval.node), &(yylsp[-1]), &(yylsp[0]));
  }
#line 2303 "parser.tab.c"
    break;

  case 58: /* if_stmt: IF BRACKET_L expr BRACKET_R CURLY_L stmts CURLY_R ELSE if_stmt  */
#line 465 "src/scanparse/parser.y"
  {
    (yyval.node) = ASTifelse((yyvsp[-6].node), (yyvsp[-3].node), ASTstmts((yyvsp[0].node), NULL));
    AddLocToNode((yyval.node), &(yylsp[-8]), &(yylsp[0]));
  }
#line 2312 "parser.tab.c"
    break;

  case 59: /* if_stmt: IF BRACKET_L expr BRACKET_R CURLY_L stmts CURLY_R ELSE CURLY_L stmts CURLY_R  */
#line 470 "src/scanparse/parser.y"
  {
    (yyval.node) = ASTifelse((yyvsp[-8].node), (yyvsp[-5].node), (yyvsp[-1].node));
    AddLocToNode((yyval.node), &(yylsp[-10]), &(yylsp[-1]));
  }
#line 2321 "parser.tab.c"
    break;

  case 60: /* if_stmt: IF BRACKET_L expr BRACKET_R CURLY_L stmts CURLY_R  */
#line 475 "src/scanparse/parser.y"
  {
    (yyval.node) = ASTifelse((yyvsp[-4].node), (yyvsp[-1].node), NULL);
    AddLocToNode((yyval.node), &(yylsp[-6]), &(yylsp[-1]));
  }
#line 2330 "parser.tab.c"
    break;

  case 61: /* if_stmt: IF BRACKET_L expr BRACKET_R stmt  */
#line 481 "src/scanparse/parser.y"
  {
    (yyval.node) = ASTifelse((yyvsp[-2].node), ASTstmts((yyvsp[0].node), NULL), NULL);
    AddLocToNode((yyval.node), &(yylsp[-4]), &(yylsp[-2]));
  }
#line 2339 "parser.tab.c"
    break;

  case 62: /* if_stmt: IF BRACKET_L expr BRACKET_R stmt ELSE stmt  */
#line 487 "src/scanparse/parser.y"
  {
    (yyval.node) = ASTifelse((yyvsp[-4].node), ASTstmts((yyvsp[-2].node), NULL), ASTstmts((yyvsp[0].node), NULL));
    AddLocToNode((yyval.node), &(yylsp[-6]), &(yylsp[-4]));
  }
#line 2348 "parser.tab.c"
    break;

  case 63: /* while_stmt: WHILE BRACKET_L expr BRACKET_R CURLY_L stmts CURLY_R  */
#line 495 "src/scanparse/parser.y"
  {
    (yyval.node) = ASTwhile((yyvsp[-4].node), (yyvsp[-1].node));
    AddLocToNode((yyval.node), &(yylsp[-6]), &(yylsp[-1]));
  }
#line 2357 "parser.tab.c"
    break;

  case 64: /* while_stmt: WHILE BRACKET_L expr BRACKET_R CURLY_L CURLY_R  */
#line 500 "src/scanparse/parser.y"
  {
    (yyval.node) = ASTwhile((yyvsp[-3].node), NULL);
    AddLocToNode((yyval.node), &(yylsp[-5]), &(yylsp[-1]));
  }
#line 2366 "parser.tab.c"
    break;

  case 65: /* do_while_stmt: DO CURLY_L stmts CURLY_R WHILE BRACKET_L expr BRACKET_R SEMICOLON  */
#line 506 "src/scanparse/parser.y"
  {
    (yyval.node) = ASTdowhile((yyvsp[-2].node), (yyvsp[-6].node));
    AddLocToNode((yyval.node), &(yylsp[-8]), &(yylsp[0]));
  }
#line 2375 "parser.tab.c"
    break;

  case 66: /* do_while_stmt: DO CURLY_L CURLY_R WHILE BRACKET_L expr BRACKET_R SEMICOLON  */
#line 511 "src/scanparse/parser.y"
  {
    (yyval.node) = ASTdowhile((yyvsp[-2].node), NULL);
    AddLocToNode((yyval.node), &(yylsp[-7]), &(yylsp[0]));
  }
#line 2384 "parser.tab.c"
    break;

  case 67: /* do_while_stmt: DO stmt WHILE BRACKET_L expr BRACKET_R SEMICOLON  */
#line 517 "src/scanparse/parser.y"
  {
    (yyval.node) = ASTdowhile((yyvsp[-2].node), ASTstmts((yyvsp[-5].node), NULL));
    AddLocToNode((yyval.node), &(yylsp[-6]), &(yylsp[-5]));
  }
#line 2393 "parser.tab.c"
    break;

  case 68: /* for_stmt: FOR BRACKET_L type ID LET expr COMMA expr BRACKET_R CURLY_L CURLY_R  */
#line 526 "src/scanparse/parser.y"
  {
    (yyval.node) = ASTfor((yyvsp[-5].node), (yyvsp[-3].node), ASTnum(1), NULL, (yyvsp[-7].id));
    AddLocToNode((yyval.node), &(yylsp[-10]), &(yylsp[0]));

  }
#line 2403 "parser.tab.c"
    break;

  case 69: /* for_stmt: FOR BRACKET_L type ID LET expr COMMA expr COMMA expr BRACKET_R CURLY_L CURLY_R  */
#line 534 "src/scanparse/parser.y"
  {
    (yyval.node) = ASTfor((yyvsp[-7].node), (yyvsp[-5].node), (yyvsp[-3].node), NULL, (yyvsp[-9].id));
    AddLocToNode((yyval.node), &(yylsp[-12]), &(yylsp[0]));
  }
#line 2412 "parser.tab.c"
    break;

  case 70: /* for_stmt: FOR BRACKET_L type ID LET expr COMMA expr BRACKET_R CURLY_L stmts CURLY_R  */
#line 541 "src/scanparse/parser.y"
  {
    (yyval.node) = ASTfor((yyvsp[-6].node), (yyvsp[-4].node), ASTnum(1), (yyvsp[-1].node), (yyvsp[-8].id));
    AddLocToNode((yyval.node), &(yylsp[-11]), &(yylsp[0]));
  }
#line 2421 "parser.tab.c"
    break;

  case 71: /* for_stmt: FOR BRACKET_L type ID LET expr COMMA expr COMMA expr BRACKET_R CURLY_L stmts CURLY_R  */
#line 548 "src/scanparse/parser.y"
  {
    (yyval.node) = ASTfor((yyvsp[-8].node), (yyvsp[-6].node), (yyvsp[-4].node), (yyvsp[-1].node), (yyvsp[-10].id));
    AddLocToNode((yyval.node), &(yylsp[-13]), &(yylsp[0]));
  }
#line 2430 "parser.tab.c"
    break;

  case 72: /* for_stmt: FOR BRACKET_L type ID LET expr COMMA expr BRACKET_R stmt  */
#line 555 "src/scanparse/parser.y"
  {
    (yyval.node) = ASTfor((yyvsp[-4].node), (yyvsp[-2].node), ASTnum(1), ASTstmts((yyvsp[0].node), NULL), (yyvsp[-6].id));
    AddLocToNode((yyval.node), &(yylsp[-9]), &(yylsp[0]));
  }
#line 2439 "parser.tab.c"
    break;

  case 73: /* for_stmt: FOR BRACKET_L type ID LET expr COMMA expr COMMA expr BRACKET_R stmt  */
#line 562 "src/scanparse/parser.y"
  {
    (yyval.node) = ASTfor((yyvsp[-6].node), (yyvsp[-4].node), (yyvsp[-2].node), ASTstmts((yyvsp[0].node), NULL), (yyvsp[-8].id));
    AddLocToNode((yyval.node), &(yylsp[-11]), &(yylsp[0]));
  }
#line 2448 "parser.tab.c"
    break;

  case 74: /* param: type ID  */
#line 568 "src/scanparse/parser.y"
  {
    (yyval.node) = ASTparam(NULL, NULL, (yyvsp[0].id), (yyvsp[-1].ctype));
    AddLocToNode((yyval.node), &(yylsp[-1]), &(yylsp[0]));
  }
#line 2457 "parser.tab.c"
    break;

  case 75: /* param: type ID COMMA param  */
#line 574 "src/scanparse/parser.y"
  {
    (yyval.node) = ASTparam(NULL, (yyvsp[0].node), (yyvsp[-2].id), (yyvsp[-3].ctype));
    AddLocToNode((yyval.node), &(yylsp[-3]), &(yylsp[0]));
  }
#line 2466 "parser.tab.c"
    break;

  case 76: /* param: type SQUARE_L ids SQUARE_R ID  */
#line 581 "src/scanparse/parser.y"
  {
    (yyval.node) = ASTparam((yyvsp[-2].node), NULL, (yyvsp[0].id), CT_array);
    AddLocToNode((yyval.node), &(yylsp[-4]), &(yylsp[0]));
  }
#line 2475 "parser.tab.c"
    break;

  case 77: /* param: type SQUARE_L ids SQUARE_R ID COMMA param  */
#line 588 "src/scanparse/parser.y"
  {
    (yyval.node) = ASTparam((yyvsp[-4].node), (yyvsp[0].node), (yyvsp[-2].id), CT_array);
    AddLocToNode((yyval.node), &(yylsp[-6]), &(yylsp[0]));
  }
#line 2484 "parser.tab.c"
    break;

  case 78: /* varlet: ID  */
#line 595 "src/scanparse/parser.y"
  {
    (yyval.node) = ASTvarlet(NULL, (yyvsp[0].id));
    AddLocToNode((yyval.node), &(yylsp[0]), &(yylsp[0]));
  }
#line 2493 "parser.tab.c"
    break;

  case 79: /* args: expr  */
#line 602 "src/scanparse/parser.y"
  {
    (yyval.node) = ASTexprs((yyvsp[0].node), NULL);
    AddLocToNode((yyval.node), &(yylsp[0]), &(yylsp[0]));
  }
#line 2502 "parser.tab.c"
    break;

  case 80: /* args: expr COMMA args  */
#line 608 "src/scanparse/parser.y"
  {
    (yyval.node) = ASTexprs((yyvsp[-2].node), (yyvsp[0].node));
    AddLocToNode((yyval.node), &(yylsp[-2]), &(yylsp[0]));
  }
#line 2511 "parser.tab.c"
    break;

  case 81: /* call: ID BRACKET_L args BRACKET_R  */
#line 620 "src/scanparse/parser.y"
  {
    (yyval.node) = ASTfuncall((yyvsp[-1].node), (yyvsp[-3].id));
    AddLocToNode((yyval.node), &(yylsp[-3]), &(yylsp[0]));
  }
#line 2520 "parser.tab.c"
    break;

  case 82: /* call: ID BRACKET_L BRACKET_R  */
#line 626 "src/scanparse/parser.y"
  {
    (yyval.node) = ASTfuncall(NULL, (yyvsp[-2].id));
    AddLocToNode((yyval.node), &(yylsp[-2]), &(yylsp[0]));
  }
#line 2529 "parser.tab.c"
    break;

  case 83: /* arithmetic: expr PLUS expr  */
#line 633 "src/scanparse/parser.y"
{
    (yyval.node) = ASTbinop((yyvsp[-2].node), (yyvsp[0].node), BO_add);
    AddLocToNode((yyval.node), &(yylsp[-2]), &(yylsp[0]));
}
#line 2538 "parser.tab.c"
    break;

  case 84: /* arithmetic: expr MINUS expr  */
#line 638 "src/scanparse/parser.y"
{
    (yyval.node) = ASTbinop((yyvsp[-2].node), (yyvsp[0].node), BO_sub);
    AddLocToNode((yyval.node), &(yylsp[-2]), &(yylsp[0]));
}
#line 2547 "parser.tab.c"
    break;

  case 85: /* arithmetic: expr STAR expr  */
#line 643 "src/scanparse/parser.y"
{
    (yyval.node) = ASTbinop((yyvsp[-2].node), (yyvsp[0].node), BO_mul);
    AddLocToNode((yyval.node), &(yylsp[-2]), &(yylsp[0]));
}
#line 2556 "parser.tab.c"
    break;

  case 86: /* arithmetic: expr SLASH expr  */
#line 648 "src/scanparse/parser.y"
{
    (yyval.node) = ASTbinop((yyvsp[-2].node), (yyvsp[0].node), BO_div);
    AddLocToNode((yyval.node), &(yylsp[-2]), &(yylsp[0]));
}
#line 2565 "parser.tab.c"
    break;

  case 87: /* arithmetic: expr PERCENT expr  */
#line 653 "src/scanparse/parser.y"
{
    (yyval.node) = ASTbinop((yyvsp[-2].node), (yyvsp[0].node), BO_mod);
    AddLocToNode((yyval.node), &(yylsp[-2]), &(yylsp[0]));
}
#line 2574 "parser.tab.c"
    break;

  case 88: /* arithmetic: expr LT expr  */
#line 658 "src/scanparse/parser.y"
{
    (yyval.node) = ASTbinop((yyvsp[-2].node), (yyvsp[0].node), BO_lt);
    AddLocToNode((yyval.node), &(yylsp[-2]), &(yylsp[0]));
}
#line 2583 "parser.tab.c"
    break;

  case 89: /* arithmetic: expr LE expr  */
#line 663 "src/scanparse/parser.y"
{
    (yyval.node) = ASTbinop((yyvsp[-2].node), (yyvsp[0].node), BO_le);
    AddLocToNode((yyval.node), &(yylsp[-2]), &(yylsp[0]));
}
#line 2592 "parser.tab.c"
    break;

  case 90: /* arithmetic: expr GT expr  */
#line 668 "src/scanparse/parser.y"
{
    (yyval.node) = ASTbinop((yyvsp[-2].node), (yyvsp[0].node), BO_gt);
    AddLocToNode((yyval.node), &(yylsp[-2]), &(yylsp[0]));
}
#line 2601 "parser.tab.c"
    break;

  case 91: /* arithmetic: expr GE expr  */
#line 673 "src/scanparse/parser.y"
{
    (yyval.node) = ASTbinop((yyvsp[-2].node), (yyvsp[0].node), BO_ge);
    AddLocToNode((yyval.node), &(yylsp[-2]), &(yylsp[0]));
}
#line 2610 "parser.tab.c"
    break;

  case 92: /* arithmetic: expr EQ expr  */
#line 678 "src/scanparse/parser.y"
{
    (yyval.node) = ASTbinop((yyvsp[-2].node), (yyvsp[0].node), BO_eq);
    AddLocToNode((yyval.node), &(yylsp[-2]), &(yylsp[0]));
}
#line 2619 "parser.tab.c"
    break;

  case 93: /* arithmetic: expr NE expr  */
#line 683 "src/scanparse/parser.y"
{
    (yyval.node) = ASTbinop((yyvsp[-2].node), (yyvsp[0].node), BO_ne);
    AddLocToNode((yyval.node), &(yylsp[-2]), &(yylsp[0]));
}
#line 2628 "parser.tab.c"
    break;

  case 94: /* arithmetic: expr AND expr  */
#line 688 "src/scanparse/parser.y"
{
    (yyval.node) = ASTbinop((yyvsp[-2].node), (yyvsp[0].node), BO_and);
    AddLocToNode((yyval.node), &(yylsp[-2]), &(yylsp[0]));
}
#line 2637 "parser.tab.c"
    break;

  case 95: /* arithmetic: expr OR expr  */
#line 693 "src/scanparse/parser.y"
{
    (yyval.node) = ASTbinop((yyvsp[-2].node), (yyvsp[0].node), BO_or);
    AddLocToNode((yyval.node), &(yylsp[-2]), &(yylsp[0]));
}
#line 2646 "parser.tab.c"
    break;

  case 96: /* arithmetic: expr PLUSEQ expr  */
#line 698 "src/scanparse/parser.y"
{
  (yyval.node) = ASTbinop((yyvsp[-2].node), (yyvsp[0].node), BO_add);
  AddLocToNode((yyval.node), &(yylsp[-2]), &(yylsp[0]));
}
#line 2655 "parser.tab.c"
    break;

  case 97: /* arithmetic: expr MINUSEQ expr  */
#line 703 "src/scanparse/parser.y"
{
  (yyval.node) = ASTbinop((yyvsp[-2].node), (yyvsp[0].node), BO_sub);
  AddLocToNode((yyval.node), &(yylsp[-2]), &(yylsp[0]));
}
#line 2664 "parser.tab.c"
    break;

  case 98: /* arithmetic: expr STAREQ expr  */
#line 708 "src/scanparse/parser.y"
{
  (yyval.node) = ASTbinop((yyvsp[-2].node), (yyvsp[0].node), BO_mul);
  AddLocToNode((yyval.node), &(yylsp[-2]), &(yylsp[0]));
}
#line 2673 "parser.tab.c"
    break;

  case 99: /* arithmetic: expr SLASHEQ expr  */
#line 713 "src/scanparse/parser.y"
{
  (yyval.node) = ASTbinop((yyvsp[-2].node), (yyvsp[0].node), BO_div);
  AddLocToNode((yyval.node), &(yylsp[-2]), &(yylsp[0]));
}
#line 2682 "parser.tab.c"
    break;

  case 100: /* arithmetic: expr PERCENTEQ expr  */
#line 718 "src/scanparse/parser.y"
{
  (yyval.node) = ASTbinop((yyvsp[-2].node), (yyvsp[0].node), BO_mod);
  AddLocToNode((yyval.node), &(yylsp[-2]), &(yylsp[0]));
}
#line 2691 "parser.tab.c"
    break;

  case 101: /* arithmetic: BRACKET_L expr BRACKET_R  */
#line 723 "src/scanparse/parser.y"
{
  (yyval.node) = (yyvsp[-1].node);
  AddLocToNode((yyval.node), &(yylsp[-2]), &(yylsp[0]));
}
#line 2700 "parser.tab.c"
    break;

  case 102: /* cast: BRACKET_L type BRACKET_R expr  */
#line 730 "src/scanparse/parser.y"
  {
    (yyval.node) = ASTcast((yyvsp[0].node), (yyvsp[-2].ctype));
    AddLocToNode((yyval.node), &(yylsp[-3]), &(yylsp[0]));
  }
#line 2709 "parser.tab.c"
    break;

  case 103: /* arrVar: ID SQUARE_L expr SQUARE_R  */
#line 737 "src/scanparse/parser.y"
{
    (yyval.node) = ASTvar(ASTexprs((yyvsp[-1].node), NULL), (yyvsp[-3].id));
    AddLocToNode((yyval.node), &(yylsp[-3]), &(yylsp[0]));
}
#line 2718 "parser.tab.c"
    break;

  case 104: /* matVar: ID SQUARE_L expr COMMA expr SQUARE_R  */
#line 743 "src/scanparse/parser.y"
                                            {
    (yyval.node) = ASTvar(ASTexprs((yyvsp[-3].node), ASTexprs((yyvsp[-1].node), NULL)), (yyvsp[-5].id));
    AddLocToNode((yyval.node), &(yylsp[-5]), &(yylsp[0]));
}
#line 2727 "parser.tab.c"
    break;

  case 105: /* arrVarlet: ID SQUARE_L expr SQUARE_R  */
#line 749 "src/scanparse/parser.y"
{
    (yyval.node) = ASTvarlet(ASTexprs((yyvsp[-1].node), NULL), (yyvsp[-3].id));
    AddLocToNode((yyval.node), &(yylsp[-3]), &(yylsp[0]));
}
#line 2736 "parser.tab.c"
    break;

  case 106: /* matVarlet: ID SQUARE_L expr COMMA expr SQUARE_R  */
#line 755 "src/scanparse/parser.y"
{
    (yyval.node) = ASTvarlet(ASTexprs((yyvsp[-3].node), ASTexprs((yyvsp[-1].node), NULL)), (yyvsp[-5].id));
    AddLocToNode((yyval.node), &(yylsp[-5]), &(yylsp[0]));
}
#line 2745 "parser.tab.c"
    break;

  case 107: /* arrExpr: SQUARE_L exprs SQUARE_R  */
#line 761 "src/scanparse/parser.y"
{
    (yyval.node) = ASTarrexpr((yyvsp[-1].node), NULL);
    AddLocToNode((yyval.node), &(yylsp[-2]), &(yylsp[0]));
}
#line 2754 "parser.tab.c"
    break;

  case 110: /* expr: constant  */
#line 779 "src/scanparse/parser.y"
               { (yyval.node) = (yyvsp[0].node); }
#line 2760 "parser.tab.c"
    break;

  case 111: /* expr: ID  */
#line 780 "src/scanparse/parser.y"
        {
      (yyval.node) = ASTvar(NULL, (yyvsp[0].id));
      AddLocToNode((yyval.node), &(yylsp[0]), &(yylsp[0]));
    }
#line 2769 "parser.tab.c"
    break;

  case 116: /* constant: floatval  */
#line 791 "src/scanparse/parser.y"
  {
    (yyval.node) = (yyvsp[0].node);
  }
#line 2777 "parser.tab.c"
    break;

  case 117: /* constant: intval  */
#line 795 "src/scanparse/parser.y"
  {
    (yyval.node) = (yyvsp[0].node);
  }
#line 2785 "parser.tab.c"
    break;

  case 118: /* constant: boolval  */
#line 799 "src/scanparse/parser.y"
  {
    (yyval.node) = (yyvsp[0].node);
  }
#line 2793 "parser.tab.c"
    break;

  case 119: /* type: TYPE_INT  */
#line 803 "src/scanparse/parser.y"
                 { (yyval.ctype) = CT_int; }
#line 2799 "parser.tab.c"
    break;

  case 120: /* type: TYPE_FLOAT  */
#line 804 "src/scanparse/parser.y"
                 { (yyval.ctype) = CT_float; }
#line 2805 "parser.tab.c"
    break;

  case 121: /* type: TYPE_BOOL  */
#line 805 "src/scanparse/parser.y"
                 { (yyval.ctype) = CT_bool; }
#line 2811 "parser.tab.c"
    break;

  case 122: /* type: TYPE_VOID  */
#line 806 "src/scanparse/parser.y"
                 { (yyval.ctype) = CT_void; }
#line 2817 "parser.tab.c"
    break;

  case 123: /* type: TYPE_ARRAY  */
#line 807 "src/scanparse/parser.y"
                 { (yyval.ctype) = CT_array;}
#line 2823 "parser.tab.c"
    break;

  case 124: /* floatval: FLOAT  */
#line 810 "src/scanparse/parser.y"
  {
    (yyval.node) = ASTfloat((yyvsp[0].cflt));
    AddLocToNode((yyval.node), &(yylsp[0]), &(yylsp[0]));
  }
#line 2832 "parser.tab.c"
    break;

  case 125: /* floatval: MINUS FLOAT  */
#line 815 "src/scanparse/parser.y"
  {
    (yyval.node) = ASTnum(-(yyvsp[0].cflt));
    AddLocToNode((yyval.node), &(yylsp[-1]), &(yylsp[-1]));
  }
#line 2841 "parser.tab.c"
    break;

  case 126: /* intval: NUM  */
#line 821 "src/scanparse/parser.y"
  {
    (yyval.node) = ASTnum((yyvsp[0].cint));
    AddLocToNode((yyval.node), &(yylsp[0]), &(yylsp[0]));
  }
#line 2850 "parser.tab.c"
    break;

  case 127: /* intval: MINUS NUM  */
#line 826 "src/scanparse/parser.y"
  {
    (yyval.node) = ASTnum(-(yyvsp[0].cint));
    AddLocToNode((yyval.node), &(yylsp[-1]), &(yylsp[-1]));
  }
#line 2859 "parser.tab.c"
    break;

  case 128: /* boolval: TRUEVAL  */
#line 832 "src/scanparse/parser.y"
  {
    (yyval.node) = ASTbool(true);
    AddLocToNode((yyval.node), &(yylsp[0]), &(yylsp[0]));
  }
#line 2868 "parser.tab.c"
    break;

  case 129: /* boolval: FALSEVAL  */
#line 837 "src/scanparse/parser.y"
  {
    (yyval.node) = ASTbool(false);
    AddLocToNode((yyval.node), &(yylsp[0]), &(yylsp[0]));
  }
#line 2877 "parser.tab.c"
    break;


#line 2881 "parser.tab.c"

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

#line 841 "src/scanparse/parser.y"


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

//own function create indices for matrix
// node_st *generate_matrix_indices(int width, int height) {
//     // printf("Width: %d height: %d \n", width, height);
//     return ASTexprs(width, ASTexprs(height, NULL));
// }

//own function to create the indices based on the array lenght
node_st *generate_indices(node_st *exprs) {
    int length = 0;
    node_st *temp = exprs;

    //traverse the linked list of Exprs nodes to count them
    while (temp) {
        length++;
        temp = EXPRS_NEXT(temp);
    }

    //generate index nodes
    node_st *expr_list = NULL;
    for (int i = 0; i < length; i++) {
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
