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
  YYSYMBOL_expr = 85,                      /* expr  */
  YYSYMBOL_constant = 86,                  /* constant  */
  YYSYMBOL_type = 87,                      /* type  */
  YYSYMBOL_floatval = 88,                  /* floatval  */
  YYSYMBOL_intval = 89,                    /* intval  */
  YYSYMBOL_boolval = 90                    /* boolval  */
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
#define YYLAST   1089

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  52
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  39
/* YYNRULES -- Number of rules.  */
#define YYNRULES  117
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  275

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
       0,   103,   103,   110,   115,   122,   128,   138,   142,   146,
     150,   155,   160,   167,   174,   179,   184,   194,   204,   209,
     214,   219,   225,   230,   241,   242,   243,   244,   245,   246,
     247,   250,   254,   259,   260,   261,   264,   270,   276,   282,
     289,   296,   300,   306,   312,   329,   341,   392,   406,   421,
     427,   433,   439,   444,   450,   455,   460,   467,   472,   478,
     483,   492,   500,   507,   514,   521,   527,   534,   541,   548,
     554,   561,   573,   579,   586,   591,   596,   601,   606,   611,
     616,   621,   626,   631,   636,   641,   646,   651,   656,   661,
     666,   671,   676,   683,   690,   697,   702,   708,   714,   719,
     720,   733,   734,   738,   739,   740,   741,   744,   748,   752,
     757,   758,   759,   760,   762,   768,   774,   779
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
  "arrVar", "matVar", "arrVarlet", "matVarlet", "arrExpr", "expr",
  "constant", "type", "floatval", "intval", "boolval", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-195)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-98)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
    1022,   136,  -195,  -195,  -195,  -195,   136,     2,  -195,  1022,
    -195,  -195,  -195,  -195,    -3,   -24,   -23,  -195,  -195,   281,
      74,    78,    11,   259,   281,  -195,  -195,  -195,  -195,     6,
    -195,  -195,  -195,  -195,  -195,  -195,   503,  -195,  -195,  -195,
    -195,    32,  -195,   281,   104,  -195,   281,   114,  -195,   354,
      14,     9,   599,   291,   281,   281,   -22,   281,   281,   281,
     281,   281,   281,   281,   281,   281,   281,   281,   281,   281,
     281,   281,   281,   281,   281,    15,    21,    23,   670,    15,
      55,   693,    57,    60,  -195,   281,  -195,   281,  -195,    62,
     623,   527,   942,   107,   116,   116,  -195,  -195,  -195,   324,
     324,   324,   324,  1069,  1069,  1035,  1058,  1017,  1017,  1017,
    1017,  1017,    53,  -195,    15,   -13,    22,  -195,  -195,    15,
    -195,  -195,    69,  1017,  -195,  -195,   281,   281,  -195,    44,
    -195,   281,   101,   136,   298,    76,    96,   105,   112,  -195,
     109,    53,  -195,  -195,  -195,  -195,  -195,  -195,  -195,  -195,
      89,   103,   108,   716,   137,  -195,   118,   117,   136,  -195,
    -195,  -195,   961,   141,   739,   281,   126,  -195,   762,   281,
     281,    92,   136,  -195,  -195,   281,   281,   281,  -195,   281,
     159,   -13,   127,  -195,  -195,  -195,   281,  -195,   551,   166,
    -195,   379,   404,   134,   172,   242,   147,   785,   808,   831,
     575,  -195,   281,  -195,   165,   854,   281,   152,   187,   188,
     198,   160,  -195,   171,  -195,  -195,  -195,   281,   170,   877,
     136,  -195,   980,   242,   155,   281,   205,   281,   999,   161,
    -195,  -195,   178,   202,  -195,   206,   429,   281,   647,   179,
    -195,   281,   173,  -195,   210,   454,   281,   162,   900,    17,
    -195,   212,   329,  -195,   281,  -195,   242,  -195,  -195,   213,
     281,   923,   211,   203,   479,  -195,  -195,  -195,   214,   217,
    -195,   220,  -195,   219,  -195
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,   110,   111,   112,   113,     0,     0,     2,     4,
      10,     7,     9,     8,     0,     0,     0,     1,     3,     0,
       0,     0,     0,     0,     0,   116,   117,   115,   114,   102,
     103,   105,   104,    99,   100,   106,     0,   101,   107,   108,
     109,     0,    21,     0,     0,    20,     0,     0,    13,     0,
       0,     0,    41,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    92,     0,    98,     0,    73,     0,
      70,     0,     0,     0,    75,    74,    76,    77,    78,    80,
      79,    82,    81,    83,    84,    86,    85,    87,    88,    89,
      90,    91,    32,    39,     0,     0,    65,    19,    37,     0,
      18,    12,     0,    93,    42,    72,     0,     0,    94,     0,
      16,     0,   102,     0,     0,     0,     0,     0,     0,    34,
       0,    32,    33,    35,    24,    28,    25,    26,    27,    29,
       0,     0,     0,     0,     0,    38,     5,     0,     0,    36,
      11,    71,     0,     0,     0,     0,     0,    53,     0,     0,
       0,     0,     0,    40,    31,     0,     0,     0,    30,     0,
       0,     0,     0,    66,    95,    17,     0,    15,     0,     0,
      52,     0,     0,     0,     0,    23,     0,     0,     0,     0,
       0,    43,     0,     6,    67,     0,     0,    94,     0,     0,
       0,     0,    22,     0,    49,    50,    51,     0,     0,     0,
       0,    14,     0,     0,     0,     0,     0,     0,     0,     0,
      44,    68,    95,     0,    58,     0,     0,     0,     0,     0,
      45,     0,    56,    57,     0,     0,     0,     0,     0,     0,
      60,     0,     0,    46,     0,    48,     0,    54,    59,     0,
       0,     0,     0,     0,     0,    47,    55,    61,     0,     0,
      63,     0,    62,     0,    64
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -195,  -195,   222,    45,  -195,  -195,  -195,  -195,  -194,   -38,
      91,  -195,   -37,   -58,   156,  -195,  -195,  -195,   -10,  -195,
    -195,  -195,   -41,  -195,   130,  -195,  -195,  -195,  -195,  -195,
    -195,  -195,  -195,   -19,  -195,     8,  -195,  -195,  -195
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     7,     8,   157,     9,    10,    11,    12,   194,   195,
     140,   141,    13,   113,    51,   143,   144,   145,   146,   147,
     148,   149,    76,   150,    89,    30,    31,    32,    33,    34,
     151,   152,    35,   153,    37,    77,    38,    39,    40
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      36,   212,    17,    80,    49,    52,    83,    19,    14,    15,
      53,    21,    22,    93,    16,    47,    54,    14,    48,    85,
      86,   118,   156,   112,    78,   256,   114,    81,   158,   233,
     235,    50,    20,   115,    90,    91,    92,    75,    94,    95,
      96,    97,    98,    99,   100,   101,   102,   103,   104,   105,
     106,   107,   108,   109,   110,   111,   155,    23,   116,   135,
     119,   159,   262,    24,   121,   122,   123,   125,    52,   268,
       2,     3,     4,     5,   139,   142,   160,   273,    41,   163,
     169,    42,    44,    25,    26,    45,    27,    28,   132,   133,
     134,     2,     3,     4,     5,   135,    23,   136,   137,   138,
     170,   193,    24,   139,   142,    53,    43,    90,   162,    79,
      46,   165,   164,   171,   130,   168,   172,   183,   173,    82,
     154,   175,    25,    26,   181,    27,    28,   132,   182,   134,
      59,    60,    61,   -69,   135,   176,   136,   137,   138,   131,
     177,   166,     2,     3,     4,     5,   188,   179,   185,   154,
     191,   192,     2,     3,     4,     5,   197,   198,   199,    23,
     200,   189,   204,    41,   234,    24,   201,   205,   240,   253,
      44,   220,   180,   186,     2,     3,     4,     5,   210,   231,
     196,   211,   213,   219,   -96,    25,    26,   222,    27,    28,
     132,   202,   134,   241,   254,   223,   224,   135,   228,   136,
     137,   138,   225,   227,   226,   229,   236,    23,   238,   237,
     -97,   242,   267,    24,   247,   243,   249,   250,   245,   258,
     266,   263,   248,   270,    23,   271,   203,   252,   274,   272,
      24,    18,   174,    25,    26,   261,    27,    28,   132,   257,
     134,   264,     0,   124,     0,   135,    23,   136,   137,   138,
      25,    26,    24,    27,    28,   132,   161,   134,     0,     0,
       0,     0,   135,    23,   136,   137,   138,     0,     0,    24,
       0,     0,    25,    26,     0,    27,    28,   132,     0,   134,
       0,     0,     0,     0,   135,    23,   136,   137,   138,    25,
      26,    24,    27,    28,    29,    23,    88,     2,     3,     4,
       5,    24,    23,     0,     0,   167,     0,     0,    24,     0,
       0,    25,    26,     0,    27,    28,    29,     0,     0,     0,
       0,    25,    26,     0,    27,    28,    29,     0,    25,    26,
       0,    27,    28,    29,   259,   260,    57,    58,    59,    60,
      61,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    84,
       0,     0,     0,     0,     0,     0,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,   208,     0,     0,     0,     0,     0,
       0,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,   209,
       0,     0,     0,     0,     0,     0,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,   244,     0,     0,     0,     0,     0,
       0,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,   251,
       0,     0,     0,     0,     0,     0,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,   269,     0,     0,     0,     0,     0,
       0,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    55,
       0,     0,     0,     0,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,   127,     0,     0,     0,     0,   128,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,   206,     0,     0,
       0,     0,   207,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,   217,     0,     0,     0,     0,   218,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    87,     0,     0,     0,     0,
       0,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,   126,
       0,     0,     0,     0,     0,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,   246,     0,     0,     0,     0,     0,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,   117,     0,     0,
       0,     0,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
     120,     0,     0,     0,     0,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,   178,     0,     0,     0,     0,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,   187,     0,     0,     0,
       0,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,   190,
       0,     0,     0,     0,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,   214,     0,     0,     0,     0,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    69,
      70,    71,    72,    73,    74,   215,     0,     0,     0,     0,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    68,    69,    70,    71,    72,    73,    74,   216,     0,
       0,     0,     0,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,   221,     0,     0,     0,     0,    57,    58,    59,    60,
      61,    62,    63,    64,    65,    66,    67,    68,    69,    70,
      71,    72,    73,    74,   230,     0,     0,     0,     0,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,   255,     0,     0,
       0,     0,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
     265,     0,     0,     0,     0,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    69,    70,    71,
      72,    73,    74,   129,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    69,    70,    71,    72,
      73,    74,   184,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    69,    70,    71,    72,    73,
      74,   232,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
     239,    57,    58,    59,    60,    61,    62,    63,    64,    65,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,     1,    69,
       2,     3,     4,     5,     0,     0,     0,     0,     0,     6,
      57,    58,    59,    60,    61,    62,    63,    64,    65,    66,
      67,    57,    58,    59,    60,    61,    62,    63,    64,    65
};

static const yytype_int16 yycheck[] =
{
      19,   195,     0,    44,    23,    24,    47,    10,     0,     1,
       4,    35,    35,    35,     6,     4,    10,     9,     7,     5,
      11,    79,    35,     8,    43,     8,     5,    46,     6,   223,
     224,    23,    35,    10,    53,    54,    55,     5,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      69,    70,    71,    72,    73,    74,   114,     4,    35,    42,
       5,   119,   256,    10,     7,     5,    85,     5,    87,   263,
      38,    39,    40,    41,   112,   112,     7,   271,     4,    35,
       4,     7,     4,    30,    31,     7,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,     4,    44,    45,    46,
       4,     9,    10,   141,   141,     4,    32,   126,   127,     5,
      32,    10,   131,     8,     7,   134,     4,   158,     9,     5,
     112,    32,    30,    31,     6,    33,    34,    35,    11,    37,
      14,    15,    16,    32,    42,    32,    44,    45,    46,    32,
      32,   133,    38,    39,    40,    41,   165,    10,     7,   141,
     169,   170,    38,    39,    40,    41,   175,   176,   177,     4,
     179,    35,    35,     4,     9,    10,     7,   186,     7,     7,
       4,     6,    35,    32,    38,    39,    40,    41,    44,   220,
     172,     9,    35,   202,    32,    30,    31,   206,    33,    34,
      35,    32,    37,    32,    32,     8,     8,    42,   217,    44,
      45,    46,     4,    32,    44,    35,   225,     4,   227,     4,
      32,     9,     9,    10,    35,     9,    43,     7,   237,     7,
       9,     8,   241,     9,     4,     8,   181,   246,     9,     9,
      10,     9,   141,    30,    31,   254,    33,    34,    35,   249,
      37,   260,    -1,    87,    -1,    42,     4,    44,    45,    46,
      30,    31,    10,    33,    34,    35,   126,    37,    -1,    -1,
      -1,    -1,    42,     4,    44,    45,    46,    -1,    -1,    10,
      -1,    -1,    30,    31,    -1,    33,    34,    35,    -1,    37,
      -1,    -1,    -1,    -1,    42,     4,    44,    45,    46,    30,
      31,    10,    33,    34,    35,     4,     5,    38,    39,    40,
      41,    10,     4,    -1,    -1,     7,    -1,    -1,    10,    -1,
      -1,    30,    31,    -1,    33,    34,    35,    -1,    -1,    -1,
      -1,    30,    31,    -1,    33,    34,    35,    -1,    30,    31,
      -1,    33,    34,    35,     5,     6,    12,    13,    14,    15,
      16,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,     5,
      -1,    -1,    -1,    -1,    -1,    -1,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,     5,    -1,    -1,    -1,    -1,    -1,
      -1,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,     5,
      -1,    -1,    -1,    -1,    -1,    -1,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,     5,    -1,    -1,    -1,    -1,    -1,
      -1,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,     5,
      -1,    -1,    -1,    -1,    -1,    -1,    12,    13,    14,    15,
      16,    17,    18,    19,    20,    21,    22,    23,    24,    25,
      26,    27,    28,    29,     5,    -1,    -1,    -1,    -1,    -1,
      -1,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,     6,
      -1,    -1,    -1,    -1,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,     6,    -1,    -1,    -1,    -1,    11,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,     6,    -1,    -1,
      -1,    -1,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,     6,    -1,    -1,    -1,    -1,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,     6,    -1,    -1,    -1,    -1,
      -1,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,     6,
      -1,    -1,    -1,    -1,    -1,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,    28,    29,     6,    -1,    -1,    -1,    -1,    -1,    12,
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
      27,    28,    29,    11,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,    29,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    28,
      29,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    27,    28,    29,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    27,    28,    29,    12,
      13,    14,    15,    16,    17,    18,    19,    20,    21,    22,
      23,    24,    25,    26,    27,    28,    29,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    36,    24,
      38,    39,    40,    41,    -1,    -1,    -1,    -1,    -1,    47,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
      22,    12,    13,    14,    15,    16,    17,    18,    19,    20
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,    36,    38,    39,    40,    41,    47,    53,    54,    56,
      57,    58,    59,    64,    87,    87,    87,     0,    54,    10,
      35,    35,    35,     4,    10,    30,    31,    33,    34,    35,
      77,    78,    79,    80,    81,    84,    85,    86,    88,    89,
      90,     4,     7,    32,     4,     7,    32,     4,     7,    85,
      87,    66,    85,     4,    10,     6,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,     5,    74,    87,    85,     5,
      74,    85,     5,    74,     5,     5,    11,     6,     5,    76,
      85,    85,    85,    35,    85,    85,    85,    85,    85,    85,
      85,    85,    85,    85,    85,    85,    85,    85,    85,    85,
      85,    85,     8,    65,     5,    10,    35,     7,    65,     5,
       7,     7,     5,    85,    66,     5,     6,     6,    11,    11,
       7,    32,    35,    36,    37,    42,    44,    45,    46,    61,
      62,    63,    64,    67,    68,    69,    70,    71,    72,    73,
      75,    82,    83,    85,    87,    65,    35,    55,     6,    65,
       7,    76,    85,    35,    85,    10,    87,     7,    85,     4,
       4,     8,     4,     9,    62,    32,    32,    32,     7,    10,
      35,     6,    11,    74,    11,     7,    32,     7,    85,    35,
       7,    85,    85,     9,    60,    61,    87,    85,    85,    85,
      85,     7,    32,    55,    35,    85,     6,    11,     5,     5,
      44,     9,    60,    35,     7,     7,     7,     6,    11,    85,
       6,     7,    85,     8,     8,     4,    44,    32,    85,    35,
       7,    74,    11,    60,     9,    60,    85,     4,    85,    11,
       7,    32,     9,     9,     5,    85,     6,    35,    85,    43,
       7,     5,    85,     7,    32,     7,     8,    70,     7,     5,
       6,    85,    60,     8,    85,     7,     9,     9,    60,     5,
       9,     8,     9,    60,     9
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    52,    53,    54,    54,    55,    55,    56,    56,    56,
      56,    57,    57,    58,    59,    59,    59,    59,    59,    59,
      59,    59,    60,    60,    61,    61,    61,    61,    61,    61,
      61,    62,    62,    63,    63,    63,    64,    64,    64,    64,
      65,    66,    66,    67,    67,    67,    67,    67,    67,    68,
      68,    68,    69,    69,    70,    70,    70,    71,    71,    72,
      72,    73,    73,    73,    73,    74,    74,    74,    74,    75,
      76,    76,    77,    77,    78,    78,    78,    78,    78,    78,
      78,    78,    78,    78,    78,    78,    78,    78,    78,    78,
      78,    78,    78,    79,    80,    81,    82,    83,    84,    84,
      84,    85,    85,    85,    85,    85,    85,    86,    86,    86,
      87,    87,    87,    87,    88,    89,    90,    90
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     2,     1,     1,     3,     1,     1,     1,
       1,     7,     6,     4,    10,     8,     6,     8,     6,     5,
       4,     3,     2,     1,     1,     1,     1,     1,     1,     1,
       2,     2,     0,     1,     1,     1,     7,     6,     6,     5,
       3,     1,     3,     3,     5,     6,     8,    10,     8,     4,
       4,     4,     3,     2,     9,    11,     7,     7,     6,     9,
       8,    11,    13,    12,    14,     2,     4,     5,     7,     1,
       1,     3,     4,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     4,     4,     6,     4,     6,     3,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1
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
		AddLocToNode(parseresult, &(yylsp[0]), &(yylsp[0]));
	}
#line 1742 "parser.tab.c"
    break;

  case 3: /* decls: decl decls  */
#line 111 "./src/scanparse/parser.y"
        {
		(yyval.node) = ASTdecls((yyvsp[-1].node), (yyvsp[0].node));
		AddLocToNode((yyval.node), &(yylsp[-1]), &(yylsp[0]));
	}
#line 1751 "parser.tab.c"
    break;

  case 4: /* decls: decl  */
#line 116 "./src/scanparse/parser.y"
        {
		(yyval.node) = ASTdecls((yyvsp[0].node), NULL);
		AddLocToNode((yyval.node), &(yylsp[0]), &(yylsp[0]));
	}
#line 1760 "parser.tab.c"
    break;

  case 5: /* ids: ID  */
#line 123 "./src/scanparse/parser.y"
  {
    //single dimensions
    (yyval.node) = ASTids(NULL, (yyvsp[0].id));
  }
#line 1769 "parser.tab.c"
    break;

  case 6: /* ids: ID COMMA ids  */
#line 129 "./src/scanparse/parser.y"
  {
    //multi dimensional
    (yyval.node) = ASTids((yyvsp[0].node), (yyvsp[-2].id));  
  }
#line 1778 "parser.tab.c"
    break;

  case 7: /* decl: glob_decl  */
#line 139 "./src/scanparse/parser.y"
  {
    (yyval.node) = (yyvsp[0].node);
  }
#line 1786 "parser.tab.c"
    break;

  case 8: /* decl: fundef  */
#line 143 "./src/scanparse/parser.y"
  {
    (yyval.node) = (yyvsp[0].node);
  }
#line 1794 "parser.tab.c"
    break;

  case 9: /* decl: glob_def  */
#line 147 "./src/scanparse/parser.y"
  {
    (yyval.node) = (yyvsp[0].node);
  }
#line 1802 "parser.tab.c"
    break;

  case 10: /* decl: fun_dec  */
#line 151 "./src/scanparse/parser.y"
  {
    (yyval.node) = (yyvsp[0].node);
  }
#line 1810 "parser.tab.c"
    break;

  case 11: /* fun_dec: EXTERN type ID BRACKET_L param BRACKET_R SEMICOLON  */
#line 156 "./src/scanparse/parser.y"
  {
    (yyval.node) = ASTfundec((yyvsp[-2].node), (yyvsp[-4].id), (yyvsp[-5].ctype));
    AddLocToNode((yyval.node), &(yylsp[-6]), &(yylsp[-1]));
  }
#line 1819 "parser.tab.c"
    break;

  case 12: /* fun_dec: EXTERN type ID BRACKET_L BRACKET_R SEMICOLON  */
#line 161 "./src/scanparse/parser.y"
  {
    (yyval.node) = ASTfundec(NULL, (yyvsp[-3].id), (yyvsp[-4].ctype));
    AddLocToNode((yyval.node), &(yylsp[-5]), &(yylsp[-1]));
  }
#line 1828 "parser.tab.c"
    break;

  case 13: /* glob_decl: EXTERN type ID SEMICOLON  */
#line 168 "./src/scanparse/parser.y"
  {
    (yyval.node) = ASTglobdecl(NULL, (yyvsp[-1].id), (yyvsp[-2].ctype));
    AddLocToNode((yyval.node), &(yylsp[-3]), &(yylsp[0]));
  }
#line 1837 "parser.tab.c"
    break;

  case 14: /* glob_def: type SQUARE_L expr COMMA expr SQUARE_R ID LET expr SEMICOLON  */
#line 175 "./src/scanparse/parser.y"
  {
    (yyval.node) = ASTglobdef((yyvsp[-7].node), (yyvsp[-1].node), (yyvsp[-3].id), (yyvsp[-9].ctype), false);
    AddLocToNode((yyval.node), &(yylsp[-9]), &(yylsp[0]));
  }
#line 1846 "parser.tab.c"
    break;

  case 15: /* glob_def: type SQUARE_L expr SQUARE_R ID LET expr SEMICOLON  */
#line 180 "./src/scanparse/parser.y"
  {
    (yyval.node) = ASTglobdef(ASTexprs((yyvsp[-5].node), NULL), (yyvsp[-1].node), (yyvsp[-3].id), (yyvsp[-7].ctype), false);
    AddLocToNode((yyval.node), &(yylsp[-7]), &(yylsp[0]));
  }
#line 1855 "parser.tab.c"
    break;

  case 16: /* glob_def: type SQUARE_L expr SQUARE_R ID SEMICOLON  */
#line 185 "./src/scanparse/parser.y"
  {
    (yyval.node) = ASTglobdef(ASTexprs((yyvsp[-3].node), NULL), NULL, (yyvsp[-1].id), (yyvsp[-5].ctype), false);
    AddLocToNode((yyval.node), &(yylsp[-5]), &(yylsp[0]));
  }
#line 1864 "parser.tab.c"
    break;

  case 17: /* glob_def: type SQUARE_L expr COMMA expr SQUARE_R ID SEMICOLON  */
#line 195 "./src/scanparse/parser.y"
  {
    (yyval.node) = ASTglobdef(ASTexprs((yyvsp[-5].node), ASTexprs((yyvsp[-3].node), NULL)), NULL, (yyvsp[-1].id), (yyvsp[-7].ctype), false);
    AddLocToNode((yyval.node), &(yylsp[-7]), &(yylsp[-1]));
  }
#line 1873 "parser.tab.c"
    break;

  case 18: /* glob_def: EXPORT type ID LET expr SEMICOLON  */
#line 205 "./src/scanparse/parser.y"
  {
    (yyval.node) = ASTglobdef(NULL,(yyvsp[-1].node), (yyvsp[-3].id), (yyvsp[-4].ctype), true);
    AddLocToNode((yyval.node), &(yylsp[-5]), &(yylsp[0]));
  }
#line 1882 "parser.tab.c"
    break;

  case 19: /* glob_def: type ID LET expr SEMICOLON  */
#line 210 "./src/scanparse/parser.y"
  {
    (yyval.node) = ASTglobdef(NULL,(yyvsp[-1].node), (yyvsp[-3].id), (yyvsp[-4].ctype), false);
    AddLocToNode((yyval.node), &(yylsp[-4]), &(yylsp[0]));
  }
#line 1891 "parser.tab.c"
    break;

  case 20: /* glob_def: EXPORT type ID SEMICOLON  */
#line 215 "./src/scanparse/parser.y"
  {
    (yyval.node) = ASTglobdef(NULL,NULL, (yyvsp[-1].id), (yyvsp[-2].ctype), true);
    AddLocToNode((yyval.node), &(yylsp[-3]), &(yylsp[0]));
  }
#line 1900 "parser.tab.c"
    break;

  case 21: /* glob_def: type ID SEMICOLON  */
#line 220 "./src/scanparse/parser.y"
  {
    (yyval.node) = ASTglobdef(NULL,NULL, (yyvsp[-1].id), (yyvsp[-2].ctype), true);
    AddLocToNode((yyval.node), &(yylsp[-2]), &(yylsp[0]));
  }
#line 1909 "parser.tab.c"
    break;

  case 22: /* stmts: stmt stmts  */
#line 226 "./src/scanparse/parser.y"
  {
    (yyval.node) = ASTstmts((yyvsp[-1].node), (yyvsp[0].node));
    AddLocToNode((yyval.node), &(yylsp[-1]), &(yylsp[0]));
  }
#line 1918 "parser.tab.c"
    break;

  case 23: /* stmts: stmt  */
#line 231 "./src/scanparse/parser.y"
  {
    (yyval.node) = ASTstmts((yyvsp[0].node), NULL);
    AddLocToNode((yyval.node), &(yylsp[0]), &(yylsp[0]));
  }
#line 1927 "parser.tab.c"
    break;

  case 24: /* stmt: assign  */
#line 241 "./src/scanparse/parser.y"
             { (yyval.node) = (yyvsp[0].node); }
#line 1933 "parser.tab.c"
    break;

  case 25: /* stmt: if_stmt  */
#line 242 "./src/scanparse/parser.y"
              { (yyval.node) = (yyvsp[0].node); }
#line 1939 "parser.tab.c"
    break;

  case 26: /* stmt: while_stmt  */
#line 243 "./src/scanparse/parser.y"
                 { (yyval.node) = (yyvsp[0].node); }
#line 1945 "parser.tab.c"
    break;

  case 27: /* stmt: do_while_stmt  */
#line 244 "./src/scanparse/parser.y"
                    { (yyval.node) = (yyvsp[0].node); }
#line 1951 "parser.tab.c"
    break;

  case 28: /* stmt: return_stmt  */
#line 245 "./src/scanparse/parser.y"
                  { (yyval.node) = (yyvsp[0].node); }
#line 1957 "parser.tab.c"
    break;

  case 29: /* stmt: for_stmt  */
#line 246 "./src/scanparse/parser.y"
               { (yyval.node) = (yyvsp[0].node); }
#line 1963 "parser.tab.c"
    break;

  case 30: /* stmt: expr SEMICOLON  */
#line 247 "./src/scanparse/parser.y"
                     { (yyval.node) = ASTexprstmt((yyvsp[-1].node)); 
}
#line 1970 "parser.tab.c"
    break;

  case 31: /* funContents: funContent funContents  */
#line 251 "./src/scanparse/parser.y"
  {
    (yyval.node) = ASTfuncontents((yyvsp[-1].node), (yyvsp[0].node));
  }
#line 1978 "parser.tab.c"
    break;

  case 32: /* funContents: %empty  */
#line 255 "./src/scanparse/parser.y"
  {
    (yyval.node) = NULL;
  }
#line 1986 "parser.tab.c"
    break;

  case 33: /* funContent: fundef  */
#line 259 "./src/scanparse/parser.y"
                   { (yyval.node) = (yyvsp[0].node); }
#line 1992 "parser.tab.c"
    break;

  case 34: /* funContent: stmt  */
#line 260 "./src/scanparse/parser.y"
                 { (yyval.node) = (yyvsp[0].node); }
#line 1998 "parser.tab.c"
    break;

  case 35: /* funContent: var_decl  */
#line 261 "./src/scanparse/parser.y"
                     { (yyval.node) = (yyvsp[0].node); }
#line 2004 "parser.tab.c"
    break;

  case 36: /* fundef: EXPORT type ID BRACKET_L param BRACKET_R funbody  */
#line 266 "./src/scanparse/parser.y"
  {
    (yyval.node) = ASTfundef((yyvsp[-2].node), (yyvsp[0].node), (yyvsp[-4].id), (yyvsp[-5].ctype), true); // Exported function
    AddLocToNode((yyval.node), &(yylsp[-6]), &(yylsp[0]));
  }
#line 2013 "parser.tab.c"
    break;

  case 37: /* fundef: EXPORT type ID BRACKET_L BRACKET_R funbody  */
#line 272 "./src/scanparse/parser.y"
  {
    (yyval.node) = ASTfundef(NULL, (yyvsp[0].node), (yyvsp[-3].id), (yyvsp[-4].ctype), true);
    AddLocToNode((yyval.node), &(yylsp[-5]), &(yylsp[0]));
  }
#line 2022 "parser.tab.c"
    break;

  case 38: /* fundef: type ID BRACKET_L param BRACKET_R funbody  */
#line 278 "./src/scanparse/parser.y"
  {
    (yyval.node) = ASTfundef((yyvsp[-2].node), (yyvsp[0].node), (yyvsp[-4].id), (yyvsp[-5].ctype), false); // Non-exported function
    AddLocToNode((yyval.node), &(yylsp[-5]), &(yylsp[0]));
  }
#line 2031 "parser.tab.c"
    break;

  case 39: /* fundef: type ID BRACKET_L BRACKET_R funbody  */
#line 284 "./src/scanparse/parser.y"
  {
    (yyval.node) = ASTfundef(NULL, (yyvsp[0].node), (yyvsp[-3].id), (yyvsp[-4].ctype), false);
    AddLocToNode((yyval.node), &(yylsp[-4]), &(yylsp[0]));
  }
#line 2040 "parser.tab.c"
    break;

  case 40: /* funbody: CURLY_L funContents CURLY_R  */
#line 290 "./src/scanparse/parser.y"
  {
    (yyval.node) = ASTfunbody((yyvsp[-1].node));
    AddLocToNode((yyval.node), &(yylsp[-2]), &(yylsp[0]));
  }
#line 2049 "parser.tab.c"
    break;

  case 41: /* exprs: expr  */
#line 297 "./src/scanparse/parser.y"
  {
      (yyval.node) = ASTexprs((yyvsp[0].node), NULL);
  }
#line 2057 "parser.tab.c"
    break;

  case 42: /* exprs: expr COMMA exprs  */
#line 301 "./src/scanparse/parser.y"
  {
      (yyval.node) = ASTexprs((yyvsp[-2].node), (yyvsp[0].node));
  }
#line 2065 "parser.tab.c"
    break;

  case 43: /* var_decl: type ID SEMICOLON  */
#line 308 "./src/scanparse/parser.y"
  {
    (yyval.node) = ASTvardecl(NULL, NULL, (yyvsp[-1].id), (yyvsp[-2].ctype));
    AddLocToNode((yyval.node), &(yylsp[-2]), &(yylsp[0]));
  }
#line 2074 "parser.tab.c"
    break;

  case 44: /* var_decl: type ID LET expr SEMICOLON  */
#line 314 "./src/scanparse/parser.y"
  {
    (yyval.node) = ASTvardecl(NULL, (yyvsp[-1].node), (yyvsp[-3].id), (yyvsp[-4].ctype));
    AddLocToNode((yyval.node), &(yylsp[-4]), &(yylsp[0]));
  }
#line 2083 "parser.tab.c"
    break;

  case 45: /* var_decl: type SQUARE_L expr SQUARE_R ID SEMICOLON  */
#line 331 "./src/scanparse/parser.y"
  {
        (yyval.node) = ASTvardecl((yyvsp[-3].node),
            NULL,
            (yyvsp[-1].id),
            (yyvsp[-5].ctype)
        );
    AddLocToNode((yyval.node), &(yylsp[-5]), &(yylsp[0]));
  }
#line 2096 "parser.tab.c"
    break;

  case 46: /* var_decl: type SQUARE_L expr COMMA expr SQUARE_R ID SEMICOLON  */
#line 343 "./src/scanparse/parser.y"
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
#line 2116 "parser.tab.c"
    break;

  case 47: /* var_decl: type SQUARE_L expr COMMA expr SQUARE_R ID LET expr SEMICOLON  */
#line 393 "./src/scanparse/parser.y"
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
#line 2134 "parser.tab.c"
    break;

  case 48: /* var_decl: type SQUARE_L expr SQUARE_R ID LET expr SEMICOLON  */
#line 407 "./src/scanparse/parser.y"
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
#line 2152 "parser.tab.c"
    break;

  case 49: /* assign: varlet LET expr SEMICOLON  */
#line 422 "./src/scanparse/parser.y"
{
  (yyval.node) = ASTassign((yyvsp[-3].node), (yyvsp[-1].node));
  AddLocToNode((yyval.node), &(yylsp[-3]), &(yylsp[0]));
}
#line 2161 "parser.tab.c"
    break;

  case 50: /* assign: arrVarlet LET expr SEMICOLON  */
#line 428 "./src/scanparse/parser.y"
{
  (yyval.node) = ASTassign((yyvsp[-3].node), (yyvsp[-1].node));
  AddLocToNode((yyval.node), &(yylsp[-3]), &(yylsp[0]));
}
#line 2170 "parser.tab.c"
    break;

  case 51: /* assign: matVarlet LET expr SEMICOLON  */
#line 434 "./src/scanparse/parser.y"
{
  (yyval.node) = ASTassign((yyvsp[-3].node), (yyvsp[-1].node));
  AddLocToNode((yyval.node), &(yylsp[-3]), &(yylsp[0]));
}
#line 2179 "parser.tab.c"
    break;

  case 52: /* return_stmt: RETURN expr SEMICOLON  */
#line 440 "./src/scanparse/parser.y"
  {
    (yyval.node) = ASTreturn((yyvsp[-1].node));
    AddLocToNode((yyval.node), &(yylsp[-2]), &(yylsp[0]));
  }
#line 2188 "parser.tab.c"
    break;

  case 53: /* return_stmt: RETURN SEMICOLON  */
#line 445 "./src/scanparse/parser.y"
  {
    (yyval.node) = ASTreturn(NULL);
    AddLocToNode((yyval.node), &(yylsp[-1]), &(yylsp[0]));
  }
#line 2197 "parser.tab.c"
    break;

  case 54: /* if_stmt: IF BRACKET_L expr BRACKET_R CURLY_L stmts CURLY_R ELSE if_stmt  */
#line 451 "./src/scanparse/parser.y"
  {
    (yyval.node) = ASTifelse((yyvsp[-6].node), (yyvsp[-3].node), ASTstmts((yyvsp[0].node), NULL));
    AddLocToNode((yyval.node), &(yylsp[-8]), &(yylsp[0]));
  }
#line 2206 "parser.tab.c"
    break;

  case 55: /* if_stmt: IF BRACKET_L expr BRACKET_R CURLY_L stmts CURLY_R ELSE CURLY_L stmts CURLY_R  */
#line 456 "./src/scanparse/parser.y"
  {
    (yyval.node) = ASTifelse((yyvsp[-8].node), (yyvsp[-5].node), (yyvsp[-1].node));
    AddLocToNode((yyval.node), &(yylsp[-10]), &(yylsp[-1]));
  }
#line 2215 "parser.tab.c"
    break;

  case 56: /* if_stmt: IF BRACKET_L expr BRACKET_R CURLY_L stmts CURLY_R  */
#line 461 "./src/scanparse/parser.y"
  {
    (yyval.node) = ASTifelse((yyvsp[-4].node), (yyvsp[-1].node), NULL);
    AddLocToNode((yyval.node), &(yylsp[-6]), &(yylsp[-1]));
  }
#line 2224 "parser.tab.c"
    break;

  case 57: /* while_stmt: WHILE BRACKET_L expr BRACKET_R CURLY_L stmts CURLY_R  */
#line 468 "./src/scanparse/parser.y"
  {
    (yyval.node) = ASTwhile((yyvsp[-4].node), (yyvsp[-1].node));
    AddLocToNode((yyval.node), &(yylsp[-6]), &(yylsp[-1]));
  }
#line 2233 "parser.tab.c"
    break;

  case 58: /* while_stmt: WHILE BRACKET_L expr BRACKET_R CURLY_L CURLY_R  */
#line 473 "./src/scanparse/parser.y"
  {
    (yyval.node) = ASTwhile((yyvsp[-3].node), NULL);
    AddLocToNode((yyval.node), &(yylsp[-5]), &(yylsp[-1]));
  }
#line 2242 "parser.tab.c"
    break;

  case 59: /* do_while_stmt: DO CURLY_L stmts CURLY_R WHILE BRACKET_L expr BRACKET_R SEMICOLON  */
#line 479 "./src/scanparse/parser.y"
  {
    (yyval.node) = ASTdowhile((yyvsp[-2].node), (yyvsp[-6].node));
    AddLocToNode((yyval.node), &(yylsp[-8]), &(yylsp[0]));
  }
#line 2251 "parser.tab.c"
    break;

  case 60: /* do_while_stmt: DO CURLY_L CURLY_R WHILE BRACKET_L expr BRACKET_R SEMICOLON  */
#line 484 "./src/scanparse/parser.y"
  {
    (yyval.node) = ASTdowhile((yyvsp[-2].node), NULL);
    AddLocToNode((yyval.node), &(yylsp[-7]), &(yylsp[0]));
  }
#line 2260 "parser.tab.c"
    break;

  case 61: /* for_stmt: FOR BRACKET_L type ID LET expr COMMA expr BRACKET_R CURLY_L CURLY_R  */
#line 493 "./src/scanparse/parser.y"
  {
    (yyval.node) = ASTfor((yyvsp[-5].node), (yyvsp[-3].node), ASTnum(1), NULL, (yyvsp[-7].id));
    AddLocToNode((yyval.node), &(yylsp[-10]), &(yylsp[0]));

  }
#line 2270 "parser.tab.c"
    break;

  case 62: /* for_stmt: FOR BRACKET_L type ID LET expr COMMA expr COMMA expr BRACKET_R CURLY_L CURLY_R  */
#line 501 "./src/scanparse/parser.y"
  {
    (yyval.node) = ASTfor((yyvsp[-7].node), (yyvsp[-5].node), (yyvsp[-3].node), NULL, (yyvsp[-9].id));
    AddLocToNode((yyval.node), &(yylsp[-12]), &(yylsp[0]));
  }
#line 2279 "parser.tab.c"
    break;

  case 63: /* for_stmt: FOR BRACKET_L type ID LET expr COMMA expr BRACKET_R CURLY_L stmts CURLY_R  */
#line 508 "./src/scanparse/parser.y"
  {
    (yyval.node) = ASTfor((yyvsp[-6].node), (yyvsp[-4].node), ASTnum(1), (yyvsp[-1].node), (yyvsp[-8].id));
    AddLocToNode((yyval.node), &(yylsp[-11]), &(yylsp[0]));
  }
#line 2288 "parser.tab.c"
    break;

  case 64: /* for_stmt: FOR BRACKET_L type ID LET expr COMMA expr COMMA expr BRACKET_R CURLY_L stmts CURLY_R  */
#line 515 "./src/scanparse/parser.y"
  {
    (yyval.node) = ASTfor((yyvsp[-8].node), (yyvsp[-6].node), (yyvsp[-4].node), (yyvsp[-1].node), (yyvsp[-10].id));
    AddLocToNode((yyval.node), &(yylsp[-13]), &(yylsp[0]));
  }
#line 2297 "parser.tab.c"
    break;

  case 65: /* param: type ID  */
#line 522 "./src/scanparse/parser.y"
  {
    (yyval.node) = ASTparam(NULL, NULL, (yyvsp[0].id), (yyvsp[-1].ctype));
    AddLocToNode((yyval.node), &(yylsp[-1]), &(yylsp[0]));
  }
#line 2306 "parser.tab.c"
    break;

  case 66: /* param: type ID COMMA param  */
#line 528 "./src/scanparse/parser.y"
  {
    (yyval.node) = ASTparam(NULL, (yyvsp[0].node), (yyvsp[-2].id), (yyvsp[-3].ctype));
    AddLocToNode((yyval.node), &(yylsp[-3]), &(yylsp[0]));
  }
#line 2315 "parser.tab.c"
    break;

  case 67: /* param: type SQUARE_L ids SQUARE_R ID  */
#line 535 "./src/scanparse/parser.y"
  {
    (yyval.node) = ASTparam((yyvsp[-2].node), NULL, (yyvsp[0].id), (yyvsp[-4].ctype));
    AddLocToNode((yyval.node), &(yylsp[-4]), &(yylsp[0]));
  }
#line 2324 "parser.tab.c"
    break;

  case 68: /* param: type SQUARE_L ids SQUARE_R ID COMMA param  */
#line 542 "./src/scanparse/parser.y"
  {
    (yyval.node) = ASTparam((yyvsp[-4].node), (yyvsp[0].node), (yyvsp[-2].id), (yyvsp[-6].ctype));
    AddLocToNode((yyval.node), &(yylsp[-6]), &(yylsp[0]));
  }
#line 2333 "parser.tab.c"
    break;

  case 69: /* varlet: ID  */
#line 549 "./src/scanparse/parser.y"
  {
    (yyval.node) = ASTvarlet(NULL, (yyvsp[0].id));
    AddLocToNode((yyval.node), &(yylsp[0]), &(yylsp[0]));
  }
#line 2342 "parser.tab.c"
    break;

  case 70: /* args: expr  */
#line 556 "./src/scanparse/parser.y"
  {
    (yyval.node) = ASTexprs((yyvsp[0].node), NULL);
    AddLocToNode((yyval.node), &(yylsp[0]), &(yylsp[0]));
  }
#line 2351 "parser.tab.c"
    break;

  case 71: /* args: expr COMMA args  */
#line 562 "./src/scanparse/parser.y"
  {
    (yyval.node) = ASTexprs((yyvsp[-2].node), (yyvsp[0].node));
    AddLocToNode((yyval.node), &(yylsp[-2]), &(yylsp[0]));
  }
#line 2360 "parser.tab.c"
    break;

  case 72: /* call: ID BRACKET_L args BRACKET_R  */
#line 574 "./src/scanparse/parser.y"
  {
    (yyval.node) = ASTfuncall((yyvsp[-1].node), (yyvsp[-3].id));
    AddLocToNode((yyval.node), &(yylsp[-3]), &(yylsp[0]));
  }
#line 2369 "parser.tab.c"
    break;

  case 73: /* call: ID BRACKET_L BRACKET_R  */
#line 580 "./src/scanparse/parser.y"
  {
    (yyval.node) = ASTfuncall(NULL, (yyvsp[-2].id));
    AddLocToNode((yyval.node), &(yylsp[-2]), &(yylsp[0]));
  }
#line 2378 "parser.tab.c"
    break;

  case 74: /* arithmetic: expr PLUS expr  */
#line 587 "./src/scanparse/parser.y"
{
    (yyval.node) = ASTbinop((yyvsp[-2].node), (yyvsp[0].node), BO_add);
    AddLocToNode((yyval.node), &(yylsp[-2]), &(yylsp[0]));
}
#line 2387 "parser.tab.c"
    break;

  case 75: /* arithmetic: expr MINUS expr  */
#line 592 "./src/scanparse/parser.y"
{
    (yyval.node) = ASTbinop((yyvsp[-2].node), (yyvsp[0].node), BO_sub);
    AddLocToNode((yyval.node), &(yylsp[-2]), &(yylsp[0]));
}
#line 2396 "parser.tab.c"
    break;

  case 76: /* arithmetic: expr STAR expr  */
#line 597 "./src/scanparse/parser.y"
{
    (yyval.node) = ASTbinop((yyvsp[-2].node), (yyvsp[0].node), BO_mul);
    AddLocToNode((yyval.node), &(yylsp[-2]), &(yylsp[0]));
}
#line 2405 "parser.tab.c"
    break;

  case 77: /* arithmetic: expr SLASH expr  */
#line 602 "./src/scanparse/parser.y"
{
    (yyval.node) = ASTbinop((yyvsp[-2].node), (yyvsp[0].node), BO_div);
    AddLocToNode((yyval.node), &(yylsp[-2]), &(yylsp[0]));
}
#line 2414 "parser.tab.c"
    break;

  case 78: /* arithmetic: expr PERCENT expr  */
#line 607 "./src/scanparse/parser.y"
{
    (yyval.node) = ASTbinop((yyvsp[-2].node), (yyvsp[0].node), BO_mod);
    AddLocToNode((yyval.node), &(yylsp[-2]), &(yylsp[0]));
}
#line 2423 "parser.tab.c"
    break;

  case 79: /* arithmetic: expr LT expr  */
#line 612 "./src/scanparse/parser.y"
{
    (yyval.node) = ASTbinop((yyvsp[-2].node), (yyvsp[0].node), BO_lt);
    AddLocToNode((yyval.node), &(yylsp[-2]), &(yylsp[0]));
}
#line 2432 "parser.tab.c"
    break;

  case 80: /* arithmetic: expr LE expr  */
#line 617 "./src/scanparse/parser.y"
{
    (yyval.node) = ASTbinop((yyvsp[-2].node), (yyvsp[0].node), BO_le);
    AddLocToNode((yyval.node), &(yylsp[-2]), &(yylsp[0]));
}
#line 2441 "parser.tab.c"
    break;

  case 81: /* arithmetic: expr GT expr  */
#line 622 "./src/scanparse/parser.y"
{
    (yyval.node) = ASTbinop((yyvsp[-2].node), (yyvsp[0].node), BO_gt);
    AddLocToNode((yyval.node), &(yylsp[-2]), &(yylsp[0]));
}
#line 2450 "parser.tab.c"
    break;

  case 82: /* arithmetic: expr GE expr  */
#line 627 "./src/scanparse/parser.y"
{
    (yyval.node) = ASTbinop((yyvsp[-2].node), (yyvsp[0].node), BO_ge);
    AddLocToNode((yyval.node), &(yylsp[-2]), &(yylsp[0]));
}
#line 2459 "parser.tab.c"
    break;

  case 83: /* arithmetic: expr EQ expr  */
#line 632 "./src/scanparse/parser.y"
{
    (yyval.node) = ASTbinop((yyvsp[-2].node), (yyvsp[0].node), BO_eq);
    AddLocToNode((yyval.node), &(yylsp[-2]), &(yylsp[0]));
}
#line 2468 "parser.tab.c"
    break;

  case 84: /* arithmetic: expr NE expr  */
#line 637 "./src/scanparse/parser.y"
{
    (yyval.node) = ASTbinop((yyvsp[-2].node), (yyvsp[0].node), BO_ne);
    AddLocToNode((yyval.node), &(yylsp[-2]), &(yylsp[0]));
}
#line 2477 "parser.tab.c"
    break;

  case 85: /* arithmetic: expr AND expr  */
#line 642 "./src/scanparse/parser.y"
{
    (yyval.node) = ASTbinop((yyvsp[-2].node), (yyvsp[0].node), BO_and);
    AddLocToNode((yyval.node), &(yylsp[-2]), &(yylsp[0]));
}
#line 2486 "parser.tab.c"
    break;

  case 86: /* arithmetic: expr OR expr  */
#line 647 "./src/scanparse/parser.y"
{
    (yyval.node) = ASTbinop((yyvsp[-2].node), (yyvsp[0].node), BO_or);
    AddLocToNode((yyval.node), &(yylsp[-2]), &(yylsp[0]));
}
#line 2495 "parser.tab.c"
    break;

  case 87: /* arithmetic: expr PLUSEQ expr  */
#line 652 "./src/scanparse/parser.y"
{
  (yyval.node) = ASTbinop((yyvsp[-2].node), (yyvsp[0].node), BO_add);
  AddLocToNode((yyval.node), &(yylsp[-2]), &(yylsp[0]));
}
#line 2504 "parser.tab.c"
    break;

  case 88: /* arithmetic: expr MINUSEQ expr  */
#line 657 "./src/scanparse/parser.y"
{
  (yyval.node) = ASTbinop((yyvsp[-2].node), (yyvsp[0].node), BO_sub);
  AddLocToNode((yyval.node), &(yylsp[-2]), &(yylsp[0]));
}
#line 2513 "parser.tab.c"
    break;

  case 89: /* arithmetic: expr STAREQ expr  */
#line 662 "./src/scanparse/parser.y"
{
  (yyval.node) = ASTbinop((yyvsp[-2].node), (yyvsp[0].node), BO_mul);
  AddLocToNode((yyval.node), &(yylsp[-2]), &(yylsp[0]));
}
#line 2522 "parser.tab.c"
    break;

  case 90: /* arithmetic: expr SLASHEQ expr  */
#line 667 "./src/scanparse/parser.y"
{
  (yyval.node) = ASTbinop((yyvsp[-2].node), (yyvsp[0].node), BO_div);
  AddLocToNode((yyval.node), &(yylsp[-2]), &(yylsp[0]));
}
#line 2531 "parser.tab.c"
    break;

  case 91: /* arithmetic: expr PERCENTEQ expr  */
#line 672 "./src/scanparse/parser.y"
{
  (yyval.node) = ASTbinop((yyvsp[-2].node), (yyvsp[0].node), BO_mod);
  AddLocToNode((yyval.node), &(yylsp[-2]), &(yylsp[0]));
}
#line 2540 "parser.tab.c"
    break;

  case 92: /* arithmetic: BRACKET_L expr BRACKET_R  */
#line 677 "./src/scanparse/parser.y"
{
  (yyval.node) = (yyvsp[-1].node);
  AddLocToNode((yyval.node), &(yylsp[-2]), &(yylsp[0]));
}
#line 2549 "parser.tab.c"
    break;

  case 93: /* cast: BRACKET_L type BRACKET_R expr  */
#line 684 "./src/scanparse/parser.y"
  {
    (yyval.node) = ASTcast((yyvsp[0].node), (yyvsp[-2].ctype));
    AddLocToNode((yyval.node), &(yylsp[-3]), &(yylsp[0]));
  }
#line 2558 "parser.tab.c"
    break;

  case 94: /* arrVar: ID SQUARE_L expr SQUARE_R  */
#line 691 "./src/scanparse/parser.y"
{
    (yyval.node) = ASTvar(ASTexprs((yyvsp[-1].node), NULL), (yyvsp[-3].id));
    AddLocToNode((yyval.node), &(yylsp[-3]), &(yylsp[0]));
}
#line 2567 "parser.tab.c"
    break;

  case 95: /* matVar: ID SQUARE_L expr COMMA expr SQUARE_R  */
#line 697 "./src/scanparse/parser.y"
                                            {
    (yyval.node) = ASTvar(ASTexprs((yyvsp[-3].node), ASTexprs((yyvsp[-1].node), NULL)), (yyvsp[-5].id));
    AddLocToNode((yyval.node), &(yylsp[-5]), &(yylsp[0]));
}
#line 2576 "parser.tab.c"
    break;

  case 96: /* arrVarlet: ID SQUARE_L expr SQUARE_R  */
#line 703 "./src/scanparse/parser.y"
{
    (yyval.node) = ASTvarlet(ASTexprs((yyvsp[-1].node), NULL), (yyvsp[-3].id));
    AddLocToNode((yyval.node), &(yylsp[-3]), &(yylsp[0]));
}
#line 2585 "parser.tab.c"
    break;

  case 97: /* matVarlet: ID SQUARE_L expr COMMA expr SQUARE_R  */
#line 709 "./src/scanparse/parser.y"
{
    (yyval.node) = ASTvarlet(ASTexprs((yyvsp[-3].node), ASTexprs((yyvsp[-1].node), NULL)), (yyvsp[-5].id));
    AddLocToNode((yyval.node), &(yylsp[-5]), &(yylsp[0]));
}
#line 2594 "parser.tab.c"
    break;

  case 98: /* arrExpr: SQUARE_L exprs SQUARE_R  */
#line 715 "./src/scanparse/parser.y"
{
    (yyval.node) = ASTarrexpr((yyvsp[-1].node), NULL);
    AddLocToNode((yyval.node), &(yylsp[-2]), &(yylsp[0]));
}
#line 2603 "parser.tab.c"
    break;

  case 101: /* expr: constant  */
#line 733 "./src/scanparse/parser.y"
               { (yyval.node) = (yyvsp[0].node); }
#line 2609 "parser.tab.c"
    break;

  case 102: /* expr: ID  */
#line 734 "./src/scanparse/parser.y"
        {
      (yyval.node) = ASTvar(NULL, (yyvsp[0].id));
      AddLocToNode((yyval.node), &(yylsp[0]), &(yylsp[0]));
    }
#line 2618 "parser.tab.c"
    break;

  case 107: /* constant: floatval  */
#line 745 "./src/scanparse/parser.y"
  {
    (yyval.node) = (yyvsp[0].node);
  }
#line 2626 "parser.tab.c"
    break;

  case 108: /* constant: intval  */
#line 749 "./src/scanparse/parser.y"
  {
    (yyval.node) = (yyvsp[0].node);
  }
#line 2634 "parser.tab.c"
    break;

  case 109: /* constant: boolval  */
#line 753 "./src/scanparse/parser.y"
  {
    (yyval.node) = (yyvsp[0].node);
  }
#line 2642 "parser.tab.c"
    break;

  case 110: /* type: TYPE_INT  */
#line 757 "./src/scanparse/parser.y"
                 { (yyval.ctype) = CT_int; }
#line 2648 "parser.tab.c"
    break;

  case 111: /* type: TYPE_FLOAT  */
#line 758 "./src/scanparse/parser.y"
                 { (yyval.ctype) = CT_float; }
#line 2654 "parser.tab.c"
    break;

  case 112: /* type: TYPE_BOOL  */
#line 759 "./src/scanparse/parser.y"
                 { (yyval.ctype) = CT_bool; }
#line 2660 "parser.tab.c"
    break;

  case 113: /* type: TYPE_VOID  */
#line 760 "./src/scanparse/parser.y"
                 { (yyval.ctype) = CT_void; }
#line 2666 "parser.tab.c"
    break;

  case 114: /* floatval: FLOAT  */
#line 763 "./src/scanparse/parser.y"
  {
    (yyval.node) = ASTfloat((yyvsp[0].cflt));
    AddLocToNode((yyval.node), &(yylsp[0]), &(yylsp[0]));
  }
#line 2675 "parser.tab.c"
    break;

  case 115: /* intval: NUM  */
#line 769 "./src/scanparse/parser.y"
  {
    (yyval.node) = ASTnum((yyvsp[0].cint));
    AddLocToNode((yyval.node), &(yylsp[0]), &(yylsp[0]));
  }
#line 2684 "parser.tab.c"
    break;

  case 116: /* boolval: TRUEVAL  */
#line 775 "./src/scanparse/parser.y"
  {
    (yyval.node) = ASTbool(true);
    AddLocToNode((yyval.node), &(yylsp[0]), &(yylsp[0]));
  }
#line 2693 "parser.tab.c"
    break;

  case 117: /* boolval: FALSEVAL  */
#line 780 "./src/scanparse/parser.y"
  {
    (yyval.node) = ASTbool(false);
    AddLocToNode((yyval.node), &(yylsp[0]), &(yylsp[0]));
  }
#line 2702 "parser.tab.c"
    break;


#line 2706 "parser.tab.c"

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

#line 784 "./src/scanparse/parser.y"


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
