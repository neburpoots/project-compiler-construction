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
    IF = 297,                      /* IF  */
    ELSE = 298,                    /* ELSE  */
    WHILE = 299,                   /* WHILE  */
    DO = 300,                      /* DO  */
    FOR = 301,                     /* FOR  */
    EXTERN = 302,                  /* EXTERN  */
    LOWER = 303,                   /* LOWER  */
    HIGHER = 304,                  /* HIGHER  */
    FUNDEC = 305                   /* FUNDEC  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 26 "./src/scanparse/parser.y"

	 char               *id;
	 int                 cint;
	 float               cflt;
	 enum BinOpType     cbinop;
	 enum Type           ctype;
	 node_st             *node;

#line 201 "parser.tab.c"

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
  YYSYMBOL_48_ = 48,                       /* '='  */
  YYSYMBOL_LOWER = 49,                     /* LOWER  */
  YYSYMBOL_HIGHER = 50,                    /* HIGHER  */
  YYSYMBOL_FUNDEC = 51,                    /* FUNDEC  */
  YYSYMBOL_YYACCEPT = 52,                  /* $accept  */
  YYSYMBOL_program = 53,                   /* program  */
  YYSYMBOL_decls = 54,                     /* decls  */
  YYSYMBOL_ids = 55,                       /* ids  */
  YYSYMBOL_decl = 56,                      /* decl  */
  YYSYMBOL_fun_dec = 57,                   /* fun_dec  */
  YYSYMBOL_glob_decl = 58,                 /* glob_decl  */
  YYSYMBOL_glob_def = 59,                  /* glob_def  */
  YYSYMBOL_stmts = 60,                     /* stmts  */
  YYSYMBOL_stmt = 61,                      /* stmt  */
  YYSYMBOL_funContents = 62,               /* funContents  */
  YYSYMBOL_funContent = 63,                /* funContent  */
  YYSYMBOL_fundef = 64,                    /* fundef  */
  YYSYMBOL_funbody = 65,                   /* funbody  */
  YYSYMBOL_exprs = 66,                     /* exprs  */
  YYSYMBOL_var_decl = 67,                  /* var_decl  */
  YYSYMBOL_assign = 68,                    /* assign  */
  YYSYMBOL_return_stmt = 69,               /* return_stmt  */
  YYSYMBOL_if_stmt = 70,                   /* if_stmt  */
  YYSYMBOL_while_stmt = 71,                /* while_stmt  */
  YYSYMBOL_do_while_stmt = 72,             /* do_while_stmt  */
  YYSYMBOL_for_stmt = 73,                  /* for_stmt  */
  YYSYMBOL_param = 74,                     /* param  */
  YYSYMBOL_varlet = 75,                    /* varlet  */
  YYSYMBOL_args = 76,                      /* args  */
  YYSYMBOL_call = 77,                      /* call  */
  YYSYMBOL_arithmetic = 78,                /* arithmetic  */
  YYSYMBOL_cast = 79,                      /* cast  */
  YYSYMBOL_arrVar = 80,                    /* arrVar  */
  YYSYMBOL_matVar = 81,                    /* matVar  */
  YYSYMBOL_arrVarlet = 82,                 /* arrVarlet  */
  YYSYMBOL_matVarlet = 83,                 /* matVarlet  */
  YYSYMBOL_arrExpr = 84,                   /* arrExpr  */
  YYSYMBOL_arrExprs = 85,                  /* arrExprs  */
  YYSYMBOL_expr = 86,                      /* expr  */
  YYSYMBOL_constant = 87,                  /* constant  */
  YYSYMBOL_type = 88,                      /* type  */
  YYSYMBOL_floatval = 89,                  /* floatval  */
  YYSYMBOL_intval = 90,                    /* intval  */
  YYSYMBOL_boolval = 91                    /* boolval  */
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
#define YYFINAL  17
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   956

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  52
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  40
/* YYNRULES -- Number of rules.  */
#define YYNRULES  115
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  265

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   305


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
       2,    48,     2,     2,     2,     2,     2,     2,     2,     2,
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
      45,    46,    47,    49,    50,    51
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,   103,   103,   109,   113,   119,   125,   135,   139,   143,
     147,   152,   156,   162,   167,   171,   175,   179,   184,   188,
     198,   199,   200,   201,   202,   203,   204,   207,   211,   216,
     217,   218,   221,   226,   231,   236,   242,   248,   252,   258,
     263,   279,   302,   339,   366,   403,   408,   413,   418,   422,
     427,   431,   435,   441,   445,   450,   454,   462,   469,   476,
     483,   490,   495,   501,   506,   512,   518,   524,   535,   540,
     546,   550,   554,   558,   562,   566,   570,   574,   578,   582,
     586,   590,   594,   598,   602,   606,   610,   614,   618,   624,
     630,   636,   640,   645,   650,   654,   655,   657,   661,   666,
     667,   668,   669,   670,   671,   674,   678,   682,   687,   688,
     689,   690,   692,   697,   702,   706
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
  "TYPE_VOID", "IF", "ELSE", "WHILE", "DO", "FOR", "EXTERN", "'='",
  "LOWER", "HIGHER", "FUNDEC", "$accept", "program", "decls", "ids",
  "decl", "fun_dec", "glob_decl", "glob_def", "stmts", "stmt",
  "funContents", "funContent", "fundef", "funbody", "exprs", "var_decl",
  "assign", "return_stmt", "if_stmt", "while_stmt", "do_while_stmt",
  "for_stmt", "param", "varlet", "args", "call", "arithmetic", "cast",
  "arrVar", "matVar", "arrVarlet", "matVarlet", "arrExpr", "arrExprs",
  "expr", "constant", "type", "floatval", "intval", "boolval", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-178)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-94)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     -13,   160,  -178,  -178,  -178,  -178,   160,    14,  -178,   -13,
    -178,  -178,  -178,  -178,   -17,   -11,    -6,  -178,  -178,    89,
     131,     9,    35,  -178,   310,    61,  -178,   310,   112,  -178,
      12,    17,    -2,   260,   310,  -178,  -178,  -178,  -178,     7,
    -178,  -178,  -178,  -178,  -178,  -178,   658,  -178,  -178,  -178,
    -178,    12,    27,   681,    28,    32,    74,  -178,    12,    33,
      64,   366,    72,    79,   587,   282,   310,  -178,   310,   310,
     310,   310,   310,   310,   310,   310,   310,   310,   310,   310,
     310,   310,   310,   310,   310,   310,  -178,    12,  -178,  -178,
      76,   133,   160,   298,    87,   119,   123,   126,  -178,   130,
      74,  -178,  -178,  -178,  -178,  -178,  -178,  -178,  -178,   108,
     109,   125,   704,    57,  -178,   149,   147,   160,  -178,   310,
    -178,   310,  -178,   155,   611,   515,    65,    65,  -178,  -178,
    -178,    73,    73,    73,    73,   936,   936,   912,   925,   894,
     894,   894,   894,   894,  -178,  -178,   310,   127,  -178,   727,
     310,   310,   138,   160,  -178,  -178,   310,   310,   310,  -178,
     310,   163,    33,   129,  -178,   894,  -178,  -178,   310,   310,
    -178,   539,   170,  -178,   391,   416,   132,   169,   221,   144,
     750,   773,   796,   563,  -178,   310,  -178,   183,  -178,   838,
     310,   156,   185,   186,   192,   146,  -178,   172,  -178,  -178,
    -178,   310,   167,   819,   160,  -178,   857,   221,   182,   310,
     201,   310,   876,    96,  -178,  -178,   175,   202,  -178,   205,
     441,   310,   635,   187,  -178,   114,   177,  -178,   203,   466,
     310,   122,   208,   216,    -4,  -178,   228,   341,  -178,   227,
    -178,   221,  -178,  -178,   230,   310,   114,   231,   199,   491,
     233,   235,  -178,  -178,   240,   242,   114,   246,  -178,   238,
    -178,  -178,  -178,   248,  -178
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,   108,   109,   110,   111,     0,     0,     2,     4,
      10,     7,     9,     8,     0,     0,     0,     1,     3,     0,
       0,     0,     0,    17,     0,     0,    16,     0,     0,    13,
       0,     0,     0,     0,     0,   114,   115,   113,   112,   100,
     101,   103,   102,    95,    96,   104,     0,    99,   105,   106,
     107,     0,     0,     0,     0,     0,    28,    35,     0,     0,
      61,     0,     0,     0,    37,     0,     0,    15,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    33,     0,    14,    12,
       0,   100,     0,     0,     0,     0,     0,     0,    30,     0,
      28,    29,    31,    20,    24,    21,    22,    23,    25,     0,
       0,     0,     0,     0,    34,     5,     0,     0,    88,     0,
      94,     0,    69,     0,    66,     0,    71,    70,    72,    73,
      74,    76,    75,    78,    77,    79,    80,    82,    81,    83,
      84,    85,    86,    87,    32,    11,     0,     0,    49,     0,
       0,     0,     0,     0,    36,    27,     0,     0,     0,    26,
       0,     0,     0,     0,    62,    89,    38,    68,     0,     0,
      90,     0,     0,    48,     0,     0,     0,     0,    19,     0,
       0,     0,     0,     0,    39,     0,     6,    63,    67,     0,
       0,    90,     0,     0,     0,     0,    18,     0,    45,    46,
      47,     0,     0,     0,     0,    91,     0,     0,     0,     0,
       0,     0,     0,     0,    40,    64,    91,     0,    54,     0,
       0,     0,     0,     0,    41,     0,    52,    53,     0,     0,
       0,     0,     0,     0,     0,    56,     0,     0,    42,     0,
      43,     0,    50,    55,     0,     0,     0,     0,     0,     0,
      97,     0,    51,    57,     0,     0,     0,     0,    59,     0,
      98,    44,    58,     0,    60
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -178,  -178,   250,    98,  -178,  -178,  -178,  -178,  -177,   -37,
     161,  -178,   -35,   -15,   141,  -178,  -178,  -178,    40,  -178,
    -178,  -178,   -23,  -178,   110,  -178,  -178,  -178,  -178,  -178,
    -178,  -178,  -100,    20,   -24,  -178,     6,  -178,  -178,  -178
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     7,     8,   116,     9,    10,    11,    12,   177,   178,
      99,   100,    13,    57,    63,   102,   103,   104,   105,   106,
     107,   108,    31,   109,   123,    40,    41,    42,    43,    44,
     110,   111,    45,   251,   112,    47,    32,    48,    49,    50
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      46,   196,    52,    53,   241,    55,    14,    15,    59,    61,
      64,    65,    16,    28,    17,    14,    29,    66,    19,    98,
      56,   101,    58,     1,    20,     2,     3,     4,     5,    21,
     217,   219,    87,    60,     6,    89,    86,    90,    94,    62,
      30,   124,   125,   114,   126,   127,   128,   129,   130,   131,
     132,   133,   134,   135,   136,   137,   138,   139,   140,   141,
     142,   143,   113,    98,   247,   101,    51,   160,   115,   149,
     117,   254,   144,     2,     3,     4,     5,   119,    33,    70,
      71,    72,   263,   145,    34,    68,    69,    70,    71,    72,
     120,   150,   161,    22,   164,   165,    23,    64,   147,     2,
       3,     4,     5,   224,    35,    36,   113,    37,    38,    91,
      92,    93,     2,     3,     4,     5,    94,    54,    95,    96,
      97,    24,   171,   151,    34,   233,   174,   175,   225,   238,
     153,   152,   180,   181,   182,    25,   183,    65,    26,   154,
     156,   157,    33,   146,   124,   189,   250,   176,    34,   232,
       2,     3,     4,     5,   239,   162,   250,   158,   163,   179,
     167,   203,   172,    27,   187,   -65,   206,    22,    35,    36,
     184,    37,    38,    91,    25,    93,   194,   212,   195,   197,
      94,   215,    95,    96,    97,   220,    33,   222,   -92,   204,
     210,   218,    34,   207,   208,   185,   209,   229,     2,     3,
       4,     5,   213,    33,   211,   221,   237,   -93,   253,    34,
     235,   226,    35,    36,   227,    37,    38,    91,    66,    93,
     234,   249,   231,   240,    94,    33,    95,    96,    97,    35,
      36,    34,    37,    38,    91,   243,    93,   246,   248,   256,
     252,    94,    33,    95,    96,    97,   257,   262,    34,   258,
     259,    35,    36,   261,    37,    38,    91,   264,    93,    18,
     186,   155,   166,    94,    33,    95,    96,    97,    35,    36,
      34,    37,    38,    91,   242,    93,   260,     0,   188,     0,
      94,     0,    95,    96,    97,     0,    33,   122,     0,     0,
      35,    36,    34,    37,    38,    39,     0,     0,     2,     3,
       4,     5,    33,     0,     0,   148,     0,     0,    34,     0,
       0,     0,    35,    36,    33,    37,    38,    39,     0,     0,
      34,     0,     0,     0,     0,     0,     0,     0,    35,    36,
       0,    37,    38,    39,     0,     0,     0,     0,     0,     0,
      35,    36,     0,    37,    38,    39,   244,   245,     0,     0,
       0,     0,     0,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,   118,     0,     0,     0,     0,     0,     0,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,   192,     0,     0,     0,
       0,     0,     0,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,   193,     0,     0,     0,     0,     0,     0,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,   228,     0,     0,     0,
       0,     0,     0,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,   236,     0,     0,     0,     0,     0,     0,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,   255,     0,     0,     0,
       0,     0,     0,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,   169,     0,     0,     0,     0,   170,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,   190,     0,     0,     0,     0,
     191,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,   201,
       0,     0,     0,     0,   202,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,   121,     0,     0,     0,     0,     0,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,   168,     0,     0,
       0,     0,     0,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,   230,     0,     0,     0,     0,     0,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    67,     0,     0,     0,     0,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,    88,     0,
       0,     0,     0,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,   159,     0,     0,     0,     0,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,   173,     0,     0,     0,     0,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,   198,     0,     0,
       0,     0,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    81,    82,    83,    84,    85,
     199,     0,     0,     0,     0,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    81,    82,
      83,    84,    85,   200,     0,     0,     0,     0,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,   214,     0,     0,     0,
       0,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    81,    82,    83,    84,    85,   205,
      68,    69,    70,    71,    72,    73,    74,    75,    76,    77,
      78,    79,    80,    81,    82,    83,    84,    85,   216,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    81,    82,    83,    84,    85,   223,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    81,    82,    83,    84,    85,    68,    69,    70,    71,
      72,    73,    74,    75,    76,    77,    78,    79,    80,    81,
      82,    83,    84,    85,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,     0,    80,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    68,    69,
      70,    71,    72,    73,    74,    75,    76
};

static const yytype_int16 yycheck[] =
{
      24,   178,    25,    27,     8,    28,     0,     1,    10,    33,
      34,     4,     6,     4,     0,     9,     7,    10,    35,    56,
       8,    56,     5,    36,    35,    38,    39,    40,    41,    35,
     207,   208,     5,    35,    47,     7,    51,     5,    42,    33,
       5,    65,    66,    58,    68,    69,    70,    71,    72,    73,
      74,    75,    76,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    56,   100,   241,   100,     5,    10,    35,    93,
       6,   248,    87,    38,    39,    40,    41,     5,     4,    14,
      15,    16,   259,     7,    10,    12,    13,    14,    15,    16,
      11,     4,    35,     4,   117,   119,     7,   121,    92,    38,
      39,    40,    41,     7,    30,    31,   100,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    42,     5,    44,    45,
      46,    32,   146,     4,    10,   225,   150,   151,    32,     7,
       4,     8,   156,   157,   158,     4,   160,     4,     7,     9,
      32,    32,     4,    10,   168,   169,   246,     9,    10,    35,
      38,    39,    40,    41,    32,     6,   256,    32,    11,   153,
       5,   185,    35,    32,    35,    32,   190,     4,    30,    31,
       7,    33,    34,    35,     4,    37,    44,   201,     9,    35,
      42,   204,    44,    45,    46,   209,     4,   211,    32,     6,
      44,     9,    10,     8,     8,    32,     4,   221,    38,    39,
      40,    41,    35,     4,    32,     4,   230,    32,     9,    10,
       7,     9,    30,    31,     9,    33,    34,    35,    10,    37,
      43,   245,    35,     7,    42,     4,    44,    45,    46,    30,
      31,    10,    33,    34,    35,     7,    37,    10,     8,     6,
       9,    42,     4,    44,    45,    46,    11,     9,    10,     9,
       8,    30,    31,     7,    33,    34,    35,     9,    37,     9,
     162,   100,   121,    42,     4,    44,    45,    46,    30,    31,
      10,    33,    34,    35,   234,    37,   256,    -1,   168,    -1,
      42,    -1,    44,    45,    46,    -1,     4,     5,    -1,    -1,
      30,    31,    10,    33,    34,    35,    -1,    -1,    38,    39,
      40,    41,     4,    -1,    -1,     7,    -1,    -1,    10,    -1,
      -1,    -1,    30,    31,     4,    33,    34,    35,    -1,    -1,
      10,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    30,    31,
      -1,    33,    34,    35,    -1,    -1,    -1,    -1,    -1,    -1,
      30,    31,    -1,    33,    34,    35,     5,     6,    -1,    -1,
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
      27,    28,    29,     6,    -1,    -1,    -1,    -1,    -1,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,     6,    -1,    -1,
      -1,    -1,    -1,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,     6,    -1,    -1,    -1,    -1,    -1,    12,    13,    14,
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
      21,    22,    23,    24,    25,    26,    27,    28,    29,    11,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    25,    26,    27,    28,    29,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    11,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    -1,    24,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    12,    13,
      14,    15,    16,    17,    18,    19,    20
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    36,    38,    39,    40,    41,    47,    53,    54,    56,
      57,    58,    59,    64,    88,    88,    88,     0,    54,    35,
      35,    35,     4,     7,    32,     4,     7,    32,     4,     7,
       5,    74,    88,     4,    10,    30,    31,    33,    34,    35,
      77,    78,    79,    80,    81,    84,    86,    87,    89,    90,
      91,     5,    74,    86,     5,    74,     8,    65,     5,    10,
      35,    86,    88,    66,    86,     4,    10,     7,    12,    13,
      14,    15,    16,    17,    18,    19,    20,    21,    22,    23,
      24,    25,    26,    27,    28,    29,    65,     5,     7,     7,
       5,    35,    36,    37,    42,    44,    45,    46,    61,    62,
      63,    64,    67,    68,    69,    70,    71,    72,    73,    75,
      82,    83,    86,    88,    65,    35,    55,     6,     5,     5,
      11,     6,     5,    76,    86,    86,    86,    86,    86,    86,
      86,    86,    86,    86,    86,    86,    86,    86,    86,    86,
      86,    86,    86,    86,    65,     7,    10,    88,     7,    86,
       4,     4,     8,     4,     9,    62,    32,    32,    32,     7,
      10,    35,     6,    11,    74,    86,    66,     5,     6,     6,
      11,    86,    35,     7,    86,    86,     9,    60,    61,    88,
      86,    86,    86,    86,     7,    32,    55,    35,    76,    86,
       6,    11,     5,     5,    44,     9,    60,    35,     7,     7,
       7,     6,    11,    86,     6,    11,    86,     8,     8,     4,
      44,    32,    86,    35,     7,    74,    11,    60,     9,    60,
      86,     4,    86,    11,     7,    32,     9,     9,     5,    86,
       6,    35,    35,    84,    43,     7,     5,    86,     7,    32,
       7,     8,    70,     7,     5,     6,    10,    60,     8,    86,
      84,    85,     9,     9,    60,     5,     6,    11,     9,     8,
      85,     7,     9,    60,     9
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    52,    53,    54,    54,    55,    55,    56,    56,    56,
      56,    57,    57,    58,    59,    59,    59,    59,    60,    60,
      61,    61,    61,    61,    61,    61,    61,    62,    62,    63,
      63,    63,    64,    64,    64,    64,    65,    66,    66,    67,
      67,    67,    67,    67,    67,    68,    68,    68,    69,    69,
      70,    70,    70,    71,    71,    72,    72,    73,    73,    73,
      73,    74,    74,    74,    74,    75,    76,    76,    77,    77,
      78,    78,    78,    78,    78,    78,    78,    78,    78,    78,
      78,    78,    78,    78,    78,    78,    78,    78,    78,    79,
      80,    81,    82,    83,    84,    84,    84,    85,    85,    86,
      86,    86,    86,    86,    86,    87,    87,    87,    88,    88,
      88,    88,    89,    90,    91,    91
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     3,     1,     1,     1,
       1,     7,     6,     4,     6,     5,     4,     3,     2,     1,
       1,     1,     1,     1,     1,     1,     2,     2,     0,     1,
       1,     1,     7,     6,     6,     5,     3,     1,     3,     3,
       5,     6,     8,     8,    12,     4,     4,     4,     3,     2,
       9,    11,     7,     7,     6,     9,     8,    11,    13,    12,
      14,     2,     4,     5,     7,     1,     1,     3,     4,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     4,
       4,     6,     4,     6,     3,     1,     1,     1,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1
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
#line 104 "./src/scanparse/parser.y"
        {
		parseresult = ASTprogram((yyvsp[0].node));
	}
#line 1713 "parser.tab.c"
    break;

  case 3: /* decls: decl decls  */
#line 110 "./src/scanparse/parser.y"
        {
		(yyval.node) = ASTdecls((yyvsp[-1].node), (yyvsp[0].node));
	}
#line 1721 "parser.tab.c"
    break;

  case 4: /* decls: decl  */
#line 114 "./src/scanparse/parser.y"
        {
		(yyval.node) = ASTdecls((yyvsp[0].node), NULL);
	}
#line 1729 "parser.tab.c"
    break;

  case 5: /* ids: ID  */
#line 120 "./src/scanparse/parser.y"
  {
    //single dimensions
    (yyval.node) = ASTids(NULL, (yyvsp[0].id));
  }
#line 1738 "parser.tab.c"
    break;

  case 6: /* ids: ID COMMA ids  */
#line 126 "./src/scanparse/parser.y"
  {
    //multi dimensional
    (yyval.node) = ASTids((yyvsp[0].node), (yyvsp[-2].id));  
  }
#line 1747 "parser.tab.c"
    break;

  case 7: /* decl: glob_decl  */
#line 136 "./src/scanparse/parser.y"
  {
    (yyval.node) = (yyvsp[0].node);
  }
#line 1755 "parser.tab.c"
    break;

  case 8: /* decl: fundef  */
#line 140 "./src/scanparse/parser.y"
  {
    (yyval.node) = (yyvsp[0].node);
  }
#line 1763 "parser.tab.c"
    break;

  case 9: /* decl: glob_def  */
#line 144 "./src/scanparse/parser.y"
  {
    (yyval.node) = (yyvsp[0].node);
  }
#line 1771 "parser.tab.c"
    break;

  case 10: /* decl: fun_dec  */
#line 148 "./src/scanparse/parser.y"
  {
    (yyval.node) = (yyvsp[0].node);
  }
#line 1779 "parser.tab.c"
    break;

  case 11: /* fun_dec: EXTERN type ID BRACKET_L param BRACKET_R SEMICOLON  */
#line 153 "./src/scanparse/parser.y"
  {
    (yyval.node) = ASTfundec((yyvsp[-2].node), (yyvsp[-4].id), (yyvsp[-5].ctype));
  }
#line 1787 "parser.tab.c"
    break;

  case 12: /* fun_dec: EXTERN type ID BRACKET_L BRACKET_R SEMICOLON  */
#line 157 "./src/scanparse/parser.y"
  {
    (yyval.node) = ASTfundec(NULL, (yyvsp[-3].id), (yyvsp[-4].ctype));
  }
#line 1795 "parser.tab.c"
    break;

  case 13: /* glob_decl: EXTERN type ID SEMICOLON  */
#line 163 "./src/scanparse/parser.y"
  {
    (yyval.node) = ASTglobdecl(NULL, (yyvsp[-1].id), (yyvsp[-2].ctype));
  }
#line 1803 "parser.tab.c"
    break;

  case 14: /* glob_def: EXPORT type ID LET expr SEMICOLON  */
#line 168 "./src/scanparse/parser.y"
  {
    (yyval.node) = ASTglobdef(NULL,(yyvsp[-1].node), (yyvsp[-3].id), (yyvsp[-4].ctype), true);
  }
#line 1811 "parser.tab.c"
    break;

  case 15: /* glob_def: type ID LET expr SEMICOLON  */
#line 172 "./src/scanparse/parser.y"
  {
    (yyval.node) = ASTglobdef(NULL,(yyvsp[-1].node), (yyvsp[-3].id), (yyvsp[-4].ctype), false);
  }
#line 1819 "parser.tab.c"
    break;

  case 16: /* glob_def: EXPORT type ID SEMICOLON  */
#line 176 "./src/scanparse/parser.y"
  {
    (yyval.node) = ASTglobdef(NULL,NULL, (yyvsp[-1].id), (yyvsp[-2].ctype), true);
  }
#line 1827 "parser.tab.c"
    break;

  case 17: /* glob_def: type ID SEMICOLON  */
#line 180 "./src/scanparse/parser.y"
  {
    (yyval.node) = ASTglobdef(NULL,NULL, (yyvsp[-1].id), (yyvsp[-2].ctype), true);
  }
#line 1835 "parser.tab.c"
    break;

  case 18: /* stmts: stmt stmts  */
#line 185 "./src/scanparse/parser.y"
  {
    (yyval.node) = ASTstmts((yyvsp[-1].node), (yyvsp[0].node));
  }
#line 1843 "parser.tab.c"
    break;

  case 19: /* stmts: stmt  */
#line 189 "./src/scanparse/parser.y"
  {
    (yyval.node) = ASTstmts((yyvsp[0].node), NULL);
  }
#line 1851 "parser.tab.c"
    break;

  case 20: /* stmt: assign  */
#line 198 "./src/scanparse/parser.y"
             { (yyval.node) = (yyvsp[0].node); }
#line 1857 "parser.tab.c"
    break;

  case 21: /* stmt: if_stmt  */
#line 199 "./src/scanparse/parser.y"
              { (yyval.node) = (yyvsp[0].node); }
#line 1863 "parser.tab.c"
    break;

  case 22: /* stmt: while_stmt  */
#line 200 "./src/scanparse/parser.y"
                 { (yyval.node) = (yyvsp[0].node); }
#line 1869 "parser.tab.c"
    break;

  case 23: /* stmt: do_while_stmt  */
#line 201 "./src/scanparse/parser.y"
                    { (yyval.node) = (yyvsp[0].node); }
#line 1875 "parser.tab.c"
    break;

  case 24: /* stmt: return_stmt  */
#line 202 "./src/scanparse/parser.y"
                  { (yyval.node) = (yyvsp[0].node); }
#line 1881 "parser.tab.c"
    break;

  case 25: /* stmt: for_stmt  */
#line 203 "./src/scanparse/parser.y"
               { (yyval.node) = (yyvsp[0].node); }
#line 1887 "parser.tab.c"
    break;

  case 26: /* stmt: expr SEMICOLON  */
#line 204 "./src/scanparse/parser.y"
                     { (yyval.node) = ASTexprstmt((yyvsp[-1].node)); 
}
#line 1894 "parser.tab.c"
    break;

  case 27: /* funContents: funContent funContents  */
#line 208 "./src/scanparse/parser.y"
  {
    (yyval.node) = ASTfuncontents((yyvsp[-1].node), (yyvsp[0].node));
  }
#line 1902 "parser.tab.c"
    break;

  case 28: /* funContents: %empty  */
#line 212 "./src/scanparse/parser.y"
  {
    (yyval.node) = NULL;
  }
#line 1910 "parser.tab.c"
    break;

  case 29: /* funContent: fundef  */
#line 216 "./src/scanparse/parser.y"
                   { (yyval.node) = (yyvsp[0].node); }
#line 1916 "parser.tab.c"
    break;

  case 30: /* funContent: stmt  */
#line 217 "./src/scanparse/parser.y"
                 { (yyval.node) = (yyvsp[0].node); }
#line 1922 "parser.tab.c"
    break;

  case 31: /* funContent: var_decl  */
#line 218 "./src/scanparse/parser.y"
                     { (yyval.node) = (yyvsp[0].node); }
#line 1928 "parser.tab.c"
    break;

  case 32: /* fundef: EXPORT type ID BRACKET_L param BRACKET_R funbody  */
#line 223 "./src/scanparse/parser.y"
  {
    (yyval.node) = ASTfundef((yyvsp[-2].node), (yyvsp[0].node), (yyvsp[-4].id), (yyvsp[-5].ctype), true); // Exported function
  }
#line 1936 "parser.tab.c"
    break;

  case 33: /* fundef: EXPORT type ID BRACKET_L BRACKET_R funbody  */
#line 228 "./src/scanparse/parser.y"
  {
    (yyval.node) = ASTfundef(NULL, (yyvsp[0].node), (yyvsp[-3].id), (yyvsp[-4].ctype), true);
  }
#line 1944 "parser.tab.c"
    break;

  case 34: /* fundef: type ID BRACKET_L param BRACKET_R funbody  */
#line 233 "./src/scanparse/parser.y"
  {
    (yyval.node) = ASTfundef((yyvsp[-2].node), (yyvsp[0].node), (yyvsp[-4].id), (yyvsp[-5].ctype), false); // Non-exported function
  }
#line 1952 "parser.tab.c"
    break;

  case 35: /* fundef: type ID BRACKET_L BRACKET_R funbody  */
#line 238 "./src/scanparse/parser.y"
  {
    (yyval.node) = ASTfundef(NULL, (yyvsp[0].node), (yyvsp[-3].id), (yyvsp[-4].ctype), false);
  }
#line 1960 "parser.tab.c"
    break;

  case 36: /* funbody: CURLY_L funContents CURLY_R  */
#line 243 "./src/scanparse/parser.y"
  {
    (yyval.node) = ASTfunbody((yyvsp[-1].node));
  }
#line 1968 "parser.tab.c"
    break;

  case 37: /* exprs: expr  */
#line 249 "./src/scanparse/parser.y"
  {
      (yyval.node) = ASTexprs((yyvsp[0].node), NULL);
  }
#line 1976 "parser.tab.c"
    break;

  case 38: /* exprs: expr COMMA exprs  */
#line 253 "./src/scanparse/parser.y"
  {
      (yyval.node) = ASTexprs((yyvsp[-2].node), (yyvsp[0].node));
  }
#line 1984 "parser.tab.c"
    break;

  case 39: /* var_decl: type ID SEMICOLON  */
#line 260 "./src/scanparse/parser.y"
  {
    (yyval.node) = ASTvardecl(NULL, NULL, (yyvsp[-1].id), (yyvsp[-2].ctype));
  }
#line 1992 "parser.tab.c"
    break;

  case 40: /* var_decl: type ID LET expr SEMICOLON  */
#line 265 "./src/scanparse/parser.y"
  {
    (yyval.node) = ASTvardecl(NULL, (yyvsp[-1].node), (yyvsp[-3].id), (yyvsp[-4].ctype));
  }
#line 2000 "parser.tab.c"
    break;

  case 41: /* var_decl: type SQUARE_L expr SQUARE_R ID SEMICOLON  */
#line 281 "./src/scanparse/parser.y"
  {
        (yyval.node) = ASTvardecl((yyvsp[-3].node),
            NULL,
            (yyvsp[-1].id),
            (yyvsp[-5].ctype)
        );
  }
#line 2012 "parser.tab.c"
    break;

  case 42: /* var_decl: type SQUARE_L expr COMMA expr SQUARE_R ID SEMICOLON  */
#line 304 "./src/scanparse/parser.y"
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
  }
#line 2031 "parser.tab.c"
    break;

  case 43: /* var_decl: type SQUARE_L expr SQUARE_R ID LET arrExpr SEMICOLON  */
#line 341 "./src/scanparse/parser.y"
  {

      (yyval.node) = ASTvardecl(
          ASTexprs((yyvsp[-5].node), NULL),  // Store the array size
          (yyvsp[-1].node),                         // Use arrExpr directly
          (yyvsp[-3].id),
          (yyvsp[-7].ctype)
      );
  }
#line 2045 "parser.tab.c"
    break;

  case 44: /* var_decl: type SQUARE_L expr COMMA expr SQUARE_R ID LET SQUARE_L arrExprs SQUARE_R SEMICOLON  */
#line 369 "./src/scanparse/parser.y"
{
    //construct dimensions
    node_st *dims = ASTexprs((yyvsp[-9].node), ASTexprs((yyvsp[-7].node), NULL));

    //construct ArrExpr node
    node_st *init = ASTarrexpr((yyvsp[-2].node), NULL);

    //create vardecl
    (yyval.node) = ASTvardecl(
        dims,   
        init,   
        (yyvsp[-5].id),  
        (yyvsp[-11].ctype)
    );
}
#line 2065 "parser.tab.c"
    break;

  case 45: /* assign: varlet LET expr SEMICOLON  */
#line 404 "./src/scanparse/parser.y"
{
  (yyval.node) = ASTassign((yyvsp[-3].node), (yyvsp[-1].node));
}
#line 2073 "parser.tab.c"
    break;

  case 46: /* assign: arrVarlet LET expr SEMICOLON  */
#line 409 "./src/scanparse/parser.y"
{
  (yyval.node) = ASTassign((yyvsp[-3].node), (yyvsp[-1].node));
}
#line 2081 "parser.tab.c"
    break;

  case 47: /* assign: matVarlet LET expr SEMICOLON  */
#line 414 "./src/scanparse/parser.y"
{
  (yyval.node) = ASTassign((yyvsp[-3].node), (yyvsp[-1].node));
}
#line 2089 "parser.tab.c"
    break;

  case 48: /* return_stmt: RETURN expr SEMICOLON  */
#line 419 "./src/scanparse/parser.y"
  {
    (yyval.node) = ASTreturn((yyvsp[-1].node));
  }
#line 2097 "parser.tab.c"
    break;

  case 49: /* return_stmt: RETURN SEMICOLON  */
#line 423 "./src/scanparse/parser.y"
  {
    (yyval.node) = ASTreturn(NULL);
  }
#line 2105 "parser.tab.c"
    break;

  case 50: /* if_stmt: IF BRACKET_L expr BRACKET_R CURLY_L stmts CURLY_R ELSE if_stmt  */
#line 428 "./src/scanparse/parser.y"
  {
    (yyval.node) = ASTifelse((yyvsp[-6].node), (yyvsp[-3].node), ASTstmts((yyvsp[0].node), NULL));
  }
#line 2113 "parser.tab.c"
    break;

  case 51: /* if_stmt: IF BRACKET_L expr BRACKET_R CURLY_L stmts CURLY_R ELSE CURLY_L stmts CURLY_R  */
#line 432 "./src/scanparse/parser.y"
  {
    (yyval.node) = ASTifelse((yyvsp[-8].node), (yyvsp[-5].node), (yyvsp[-1].node));
  }
#line 2121 "parser.tab.c"
    break;

  case 52: /* if_stmt: IF BRACKET_L expr BRACKET_R CURLY_L stmts CURLY_R  */
#line 436 "./src/scanparse/parser.y"
  {
    (yyval.node) = ASTifelse((yyvsp[-4].node), (yyvsp[-1].node), NULL);
  }
#line 2129 "parser.tab.c"
    break;

  case 53: /* while_stmt: WHILE BRACKET_L expr BRACKET_R CURLY_L stmts CURLY_R  */
#line 442 "./src/scanparse/parser.y"
  {
    (yyval.node) = ASTwhile((yyvsp[-4].node), (yyvsp[-1].node));
  }
#line 2137 "parser.tab.c"
    break;

  case 54: /* while_stmt: WHILE BRACKET_L expr BRACKET_R CURLY_L CURLY_R  */
#line 446 "./src/scanparse/parser.y"
  {
    (yyval.node) = ASTwhile((yyvsp[-3].node), NULL);
  }
#line 2145 "parser.tab.c"
    break;

  case 55: /* do_while_stmt: DO CURLY_L stmts CURLY_R WHILE BRACKET_L expr BRACKET_R SEMICOLON  */
#line 451 "./src/scanparse/parser.y"
  {
    (yyval.node) = ASTdowhile((yyvsp[-2].node), (yyvsp[-6].node));
  }
#line 2153 "parser.tab.c"
    break;

  case 56: /* do_while_stmt: DO CURLY_L CURLY_R WHILE BRACKET_L expr BRACKET_R SEMICOLON  */
#line 455 "./src/scanparse/parser.y"
  {
    (yyval.node) = ASTdowhile((yyvsp[-2].node), NULL);
  }
#line 2161 "parser.tab.c"
    break;

  case 57: /* for_stmt: FOR BRACKET_L type ID LET expr COMMA expr BRACKET_R CURLY_L CURLY_R  */
#line 463 "./src/scanparse/parser.y"
  {
    // printf("no step size, default to 1, no statements\n");
    (yyval.node) = ASTfor((yyvsp[-5].node), (yyvsp[-3].node), ASTnum(1), NULL, (yyvsp[-7].id));
  }
#line 2170 "parser.tab.c"
    break;

  case 58: /* for_stmt: FOR BRACKET_L type ID LET expr COMMA expr COMMA expr BRACKET_R CURLY_L CURLY_R  */
#line 470 "./src/scanparse/parser.y"
  {
    printf("with step size, no statements\n");
    (yyval.node) = ASTfor((yyvsp[-7].node), (yyvsp[-5].node), (yyvsp[-3].node), NULL, (yyvsp[-9].id));
  }
#line 2179 "parser.tab.c"
    break;

  case 59: /* for_stmt: FOR BRACKET_L type ID LET expr COMMA expr BRACKET_R CURLY_L stmts CURLY_R  */
#line 477 "./src/scanparse/parser.y"
  {
    printf("no step size, default to 1, with statements\n");
    (yyval.node) = ASTfor((yyvsp[-6].node), (yyvsp[-4].node), ASTnum(1), (yyvsp[-1].node), (yyvsp[-8].id));
  }
#line 2188 "parser.tab.c"
    break;

  case 60: /* for_stmt: FOR BRACKET_L type ID LET expr COMMA expr COMMA expr BRACKET_R CURLY_L stmts CURLY_R  */
#line 484 "./src/scanparse/parser.y"
  {
    // printf("with step size, with statements\n");
    (yyval.node) = ASTfor((yyvsp[-8].node), (yyvsp[-6].node), (yyvsp[-4].node), (yyvsp[-1].node), (yyvsp[-10].id));
  }
#line 2197 "parser.tab.c"
    break;

  case 61: /* param: type ID  */
#line 491 "./src/scanparse/parser.y"
  {
    (yyval.node) = ASTparam(NULL, NULL, (yyvsp[0].id), (yyvsp[-1].ctype));
  }
#line 2205 "parser.tab.c"
    break;

  case 62: /* param: type ID COMMA param  */
#line 496 "./src/scanparse/parser.y"
  {
    (yyval.node) = ASTparam(NULL, (yyvsp[0].node), (yyvsp[-2].id), (yyvsp[-3].ctype));
  }
#line 2213 "parser.tab.c"
    break;

  case 63: /* param: type SQUARE_L ids SQUARE_R ID  */
#line 501 "./src/scanparse/parser.y"
                                 {
      (yyval.node) = ASTparam((yyvsp[-2].node), NULL, (yyvsp[0].id), (yyvsp[-4].ctype));
  }
#line 2221 "parser.tab.c"
    break;

  case 64: /* param: type SQUARE_L ids SQUARE_R ID COMMA param  */
#line 507 "./src/scanparse/parser.y"
  {
    (yyval.node) = ASTparam((yyvsp[-4].node), (yyvsp[0].node), (yyvsp[-2].id), (yyvsp[-6].ctype));  
  }
#line 2229 "parser.tab.c"
    break;

  case 65: /* varlet: ID  */
#line 513 "./src/scanparse/parser.y"
  {
    (yyval.node) = ASTvarlet(NULL, (yyvsp[0].id));
    AddLocToNode((yyval.node), &(yylsp[0]), &(yylsp[0]));
  }
#line 2238 "parser.tab.c"
    break;

  case 66: /* args: expr  */
#line 520 "./src/scanparse/parser.y"
  {
    (yyval.node) = ASTexprs((yyvsp[0].node), NULL); 
  }
#line 2246 "parser.tab.c"
    break;

  case 67: /* args: expr COMMA args  */
#line 525 "./src/scanparse/parser.y"
  {
    (yyval.node) = ASTexprs((yyvsp[-2].node), (yyvsp[0].node));
  }
#line 2254 "parser.tab.c"
    break;

  case 68: /* call: ID BRACKET_L args BRACKET_R  */
#line 536 "./src/scanparse/parser.y"
  {
    (yyval.node) = ASTfuncall((yyvsp[-1].node), (yyvsp[-3].id));
  }
#line 2262 "parser.tab.c"
    break;

  case 69: /* call: ID BRACKET_L BRACKET_R  */
#line 541 "./src/scanparse/parser.y"
  {
    (yyval.node) = ASTfuncall(NULL, (yyvsp[-2].id));
  }
#line 2270 "parser.tab.c"
    break;

  case 70: /* arithmetic: expr PLUS expr  */
#line 547 "./src/scanparse/parser.y"
{
    (yyval.node) = ASTbinop((yyvsp[-2].node), (yyvsp[0].node), BO_add);
}
#line 2278 "parser.tab.c"
    break;

  case 71: /* arithmetic: expr MINUS expr  */
#line 551 "./src/scanparse/parser.y"
{
    (yyval.node) = ASTbinop((yyvsp[-2].node), (yyvsp[0].node), BO_sub);
}
#line 2286 "parser.tab.c"
    break;

  case 72: /* arithmetic: expr STAR expr  */
#line 555 "./src/scanparse/parser.y"
{
    (yyval.node) = ASTbinop((yyvsp[-2].node), (yyvsp[0].node), BO_mul);
}
#line 2294 "parser.tab.c"
    break;

  case 73: /* arithmetic: expr SLASH expr  */
#line 559 "./src/scanparse/parser.y"
{
    (yyval.node) = ASTbinop((yyvsp[-2].node), (yyvsp[0].node), BO_div);
}
#line 2302 "parser.tab.c"
    break;

  case 74: /* arithmetic: expr PERCENT expr  */
#line 563 "./src/scanparse/parser.y"
{
    (yyval.node) = ASTbinop((yyvsp[-2].node), (yyvsp[0].node), BO_mod);
}
#line 2310 "parser.tab.c"
    break;

  case 75: /* arithmetic: expr LT expr  */
#line 567 "./src/scanparse/parser.y"
{
    (yyval.node) = ASTbinop((yyvsp[-2].node), (yyvsp[0].node), BO_lt);
}
#line 2318 "parser.tab.c"
    break;

  case 76: /* arithmetic: expr LE expr  */
#line 571 "./src/scanparse/parser.y"
{
    (yyval.node) = ASTbinop((yyvsp[-2].node), (yyvsp[0].node), BO_le);
}
#line 2326 "parser.tab.c"
    break;

  case 77: /* arithmetic: expr GT expr  */
#line 575 "./src/scanparse/parser.y"
{
    (yyval.node) = ASTbinop((yyvsp[-2].node), (yyvsp[0].node), BO_gt);
}
#line 2334 "parser.tab.c"
    break;

  case 78: /* arithmetic: expr GE expr  */
#line 579 "./src/scanparse/parser.y"
{
    (yyval.node) = ASTbinop((yyvsp[-2].node), (yyvsp[0].node), BO_ge);
}
#line 2342 "parser.tab.c"
    break;

  case 79: /* arithmetic: expr EQ expr  */
#line 583 "./src/scanparse/parser.y"
{
    (yyval.node) = ASTbinop((yyvsp[-2].node), (yyvsp[0].node), BO_eq);
}
#line 2350 "parser.tab.c"
    break;

  case 80: /* arithmetic: expr NE expr  */
#line 587 "./src/scanparse/parser.y"
{
    (yyval.node) = ASTbinop((yyvsp[-2].node), (yyvsp[0].node), BO_ne);
}
#line 2358 "parser.tab.c"
    break;

  case 81: /* arithmetic: expr AND expr  */
#line 591 "./src/scanparse/parser.y"
{
    (yyval.node) = ASTbinop((yyvsp[-2].node), (yyvsp[0].node), BO_and);
}
#line 2366 "parser.tab.c"
    break;

  case 82: /* arithmetic: expr OR expr  */
#line 595 "./src/scanparse/parser.y"
{
    (yyval.node) = ASTbinop((yyvsp[-2].node), (yyvsp[0].node), BO_or);
}
#line 2374 "parser.tab.c"
    break;

  case 83: /* arithmetic: expr PLUSEQ expr  */
#line 599 "./src/scanparse/parser.y"
{
  (yyval.node) = ASTbinop((yyvsp[-2].node), (yyvsp[0].node), BO_add);
}
#line 2382 "parser.tab.c"
    break;

  case 84: /* arithmetic: expr MINUSEQ expr  */
#line 603 "./src/scanparse/parser.y"
{
  (yyval.node) = ASTbinop((yyvsp[-2].node), (yyvsp[0].node), BO_sub);
}
#line 2390 "parser.tab.c"
    break;

  case 85: /* arithmetic: expr STAREQ expr  */
#line 607 "./src/scanparse/parser.y"
{
  (yyval.node) = ASTbinop((yyvsp[-2].node), (yyvsp[0].node), BO_mul);
}
#line 2398 "parser.tab.c"
    break;

  case 86: /* arithmetic: expr SLASHEQ expr  */
#line 611 "./src/scanparse/parser.y"
{
  (yyval.node) = ASTbinop((yyvsp[-2].node), (yyvsp[0].node), BO_div);
}
#line 2406 "parser.tab.c"
    break;

  case 87: /* arithmetic: expr PERCENTEQ expr  */
#line 615 "./src/scanparse/parser.y"
{
  (yyval.node) = ASTbinop((yyvsp[-2].node), (yyvsp[0].node), BO_mod);
}
#line 2414 "parser.tab.c"
    break;

  case 88: /* arithmetic: BRACKET_L expr BRACKET_R  */
#line 619 "./src/scanparse/parser.y"
{
    (yyval.node) = (yyvsp[-1].node);
}
#line 2422 "parser.tab.c"
    break;

  case 89: /* cast: BRACKET_L type BRACKET_R expr  */
#line 625 "./src/scanparse/parser.y"
  {
    (yyval.node) = ASTcast((yyvsp[0].node), (yyvsp[-2].ctype));
  }
#line 2430 "parser.tab.c"
    break;

  case 90: /* arrVar: ID SQUARE_L expr SQUARE_R  */
#line 631 "./src/scanparse/parser.y"
{
    (yyval.node) = ASTvar(ASTexprs((yyvsp[-1].node), NULL), (yyvsp[-3].id));
}
#line 2438 "parser.tab.c"
    break;

  case 91: /* matVar: ID SQUARE_L expr COMMA expr SQUARE_R  */
#line 636 "./src/scanparse/parser.y"
                                            {
    (yyval.node) = ASTvar(ASTexprs((yyvsp[-3].node), ASTexprs((yyvsp[-1].node), NULL)), (yyvsp[-5].id));
}
#line 2446 "parser.tab.c"
    break;

  case 92: /* arrVarlet: ID SQUARE_L expr SQUARE_R  */
#line 641 "./src/scanparse/parser.y"
{
    (yyval.node) = ASTvarlet(ASTexprs((yyvsp[-1].node), NULL), (yyvsp[-3].id));  // ✅ Use VarLet instead of Var
}
#line 2454 "parser.tab.c"
    break;

  case 93: /* matVarlet: ID SQUARE_L expr COMMA expr SQUARE_R  */
#line 646 "./src/scanparse/parser.y"
{
    (yyval.node) = ASTvarlet(ASTexprs((yyvsp[-3].node), ASTexprs((yyvsp[-1].node), NULL)), (yyvsp[-5].id));  // ✅ Use VarLet instead of Var
}
#line 2462 "parser.tab.c"
    break;

  case 94: /* arrExpr: SQUARE_L exprs SQUARE_R  */
#line 651 "./src/scanparse/parser.y"
{
    (yyval.node) = ASTarrexpr((yyvsp[-1].node), generate_indices((yyvsp[-1].node)));
}
#line 2470 "parser.tab.c"
    break;

  case 97: /* arrExprs: arrExpr  */
#line 658 "./src/scanparse/parser.y"
{
    (yyval.node) = ASTexprs((yyvsp[0].node), NULL);
}
#line 2478 "parser.tab.c"
    break;

  case 98: /* arrExprs: arrExpr COMMA arrExprs  */
#line 662 "./src/scanparse/parser.y"
{
    (yyval.node) = ASTexprs((yyvsp[-2].node), (yyvsp[0].node));
}
#line 2486 "parser.tab.c"
    break;

  case 99: /* expr: constant  */
#line 666 "./src/scanparse/parser.y"
               { (yyval.node) = (yyvsp[0].node); }
#line 2492 "parser.tab.c"
    break;

  case 100: /* expr: ID  */
#line 667 "./src/scanparse/parser.y"
        {(yyval.node) = ASTvar(NULL, (yyvsp[0].id));}
#line 2498 "parser.tab.c"
    break;

  case 105: /* constant: floatval  */
#line 675 "./src/scanparse/parser.y"
  {
    (yyval.node) = (yyvsp[0].node);
  }
#line 2506 "parser.tab.c"
    break;

  case 106: /* constant: intval  */
#line 679 "./src/scanparse/parser.y"
  {
    (yyval.node) = (yyvsp[0].node);
  }
#line 2514 "parser.tab.c"
    break;

  case 107: /* constant: boolval  */
#line 683 "./src/scanparse/parser.y"
  {
    (yyval.node) = (yyvsp[0].node);
  }
#line 2522 "parser.tab.c"
    break;

  case 108: /* type: TYPE_INT  */
#line 687 "./src/scanparse/parser.y"
                 { (yyval.ctype) = CT_int; }
#line 2528 "parser.tab.c"
    break;

  case 109: /* type: TYPE_FLOAT  */
#line 688 "./src/scanparse/parser.y"
                 { (yyval.ctype) = CT_float; }
#line 2534 "parser.tab.c"
    break;

  case 110: /* type: TYPE_BOOL  */
#line 689 "./src/scanparse/parser.y"
                 { (yyval.ctype) = CT_bool; }
#line 2540 "parser.tab.c"
    break;

  case 111: /* type: TYPE_VOID  */
#line 690 "./src/scanparse/parser.y"
                 { (yyval.ctype) = CT_void; }
#line 2546 "parser.tab.c"
    break;

  case 112: /* floatval: FLOAT  */
#line 693 "./src/scanparse/parser.y"
  {
    (yyval.node) = ASTfloat((yyvsp[0].cflt));
  }
#line 2554 "parser.tab.c"
    break;

  case 113: /* intval: NUM  */
#line 698 "./src/scanparse/parser.y"
  {
    (yyval.node) = ASTnum((yyvsp[0].cint));
  }
#line 2562 "parser.tab.c"
    break;

  case 114: /* boolval: TRUEVAL  */
#line 703 "./src/scanparse/parser.y"
  {
    (yyval.node) = ASTbool(true);
  }
#line 2570 "parser.tab.c"
    break;

  case 115: /* boolval: FALSEVAL  */
#line 707 "./src/scanparse/parser.y"
  {
    (yyval.node) = ASTbool(false);
  }
#line 2578 "parser.tab.c"
    break;


#line 2582 "parser.tab.c"

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

#line 710 "./src/scanparse/parser.y"


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
