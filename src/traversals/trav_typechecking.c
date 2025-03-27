/**
 * @file
 *
 * Traversal: TypeChecking
 * UID      : TC
 *
 *
 */

// ANSI color codes
#define RED "\033[1;31m"
#define GREEN "\033[1;32m"
#define YELLOW "\033[1;33m"
#define BLUE "\033[1;34m"
#define RESET "\033[0m" // Resets color formatting

#include "ccn/ccn.h"
#include "ccngen/ast.h"
#include "ccngen/trav.h"
#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include "user/symbolTable/symbol_table.h"
#include "user/stack/stack.h"
// used to create the stack
void TCinit()
{

    return;
}

// used for cleanup
void TCfini()
{
}


const char *node_to_type_string(node_st *node)
{
    switch (NODE_TYPE(node))
    {
    case NT_NULL:
        return "NT_NULL";
    case NT_BOOL:
        return "NT_BOOL";
    case NT_FLOAT:
        return "NT_FLOAT";
    case NT_NUM:
        return "NT_NUM";
    case NT_VAR:
        return "NT_VAR";
    case NT_VARLET:
        return "NT_VARLET";
    case NT_MONOP:
        return "NT_MONOP";
    case NT_BINOP:
        return "NT_BINOP";
    case NT_ASSIGN:
        return "NT_ASSIGN";
    case NT_FUNCONTENTS:
        return "NT_FUNCONTENTS";
    case NT_STMTS:
        return "NT_STMTS";
    case NT_VARDECL:
        return "NT_VARDECL";
    case NT_VARDECLS:
        return "NT_VARDECLS";
    case NT_PARAM:
        return "NT_PARAM";
    case NT_GLOBDEF:
        return "NT_GLOBDEF";
    case NT_FUNDEC:
        return "NT_FUNDEC";
    case NT_GLOBDECL:
        return "NT_GLOBDECL";
    case NT_FOR:
        return "NT_FOR";
    case NT_DOWHILE:
        return "NT_DOWHILE";
    case NT_WHILE:
        return "NT_WHILE";
    case NT_IFELSE:
        return "NT_IFELSE";
    case NT_FUNBODY:
        return "NT_FUNBODY";
    case NT_FUNDEF:
        return "NT_FUNDEF";
    case NT_FUNDEFS:
        return "NT_FUNDEFS";
    case NT_CAST:
        return "NT_CAST";
    case NT_FUNCALL:
        return "NT_FUNCALL";
    case NT_RETURN:
        return "NT_RETURN";
    case NT_EXPRSTMT:
        return "NT_EXPRSTMT";
    case NT_IDS:
        return "NT_IDS";
    case NT_ARREXPR:
        return "NT_ARREXPR";
    case NT_EXPRS:
        return "NT_EXPRS";
    case NT_DECLS:
        return "NT_DECLS";
    case NT_PROGRAM:
        return "NT_PROGRAM";
    case _NT_SIZE:
        return "_NT_SIZE";
    default:
        return "UNKNOWN_NODETYPE";
    }
}



/**
 * @fn TCprogram
 */
node_st *TCprogram(node_st *node)
{
    struct data_tc *data = DATA_TC_GET();
    data->type_error_count = 0;

    printf("Starting type checking traversal\n");
    TRAVchildren(node);

    printf("\n");
    if (data->type_error_count > 0)
    {
        printf(RED "Found %d type errors in program.\n" RESET, data->type_error_count);
    }
    else
    {
        printf(GREEN "No type errors found in program.\n" RESET);
    }

    return node;
}

/**
 * @fn TCglobdef
 */
node_st *TCglobdef(node_st *node)
{
    TRAVchildren(node);
    return node;
}

/**
 * @fn TCglobdecl
 */
node_st *TCglobdecl(node_st *node)
{
    TRAVchildren(node);
    return node;
}

// check return type of function
//  First parameter is the function node, second parameter is the statements of any node.

/**
 * @fn TCfundef
 */
node_st *TCfundef(node_st *node)
{
    struct data_tc *data = DATA_TC_GET();

    // Temp save parent function
    node_st *parent_function = data->current_function;

    // set as current function scope.
    data->current_function = node;

    TRAVchildren(node);

    // restore parent function
    data->current_function = parent_function;

    return node;
}

/**
 * @fn TCfundec
 */
node_st *TCfundec(node_st *node)
{
    TRAVchildren(node);
    return node;
}

/**
 * @fn TCfunbody
 */
node_st *TCfunbody(node_st *node)
{
    TRAVchildren(node);
    return node;
}

// Takes a vardecl node and the expected and resulting output types.
void printTypeMisMatch(node_st *node, enum Type expected, enum Type got)
{
    printf(RED "Error: Type mismatch in assignment.\n" RESET);
    printf(YELLOW "  Expected: " RESET BLUE "%s\n" RESET, typeToString(expected));
    printf(YELLOW "  Got:      " RESET RED "%s\n" RESET, typeToString(got));

    printf(YELLOW "At line: %d and column: %d\n" RESET, NODE_BLINE(node), NODE_BCOL(node));
    printf("\n");
}

// print function already declare.
void printVarDoesNotExist(node_st *node)
{
    printf(RED "\nError: variable does not exist\n" RESET);
    printf(YELLOW " Variable: " RESET "'%s'" YELLOW " is not defined.\n" RESET, VAR_NAME(node));
    printf(YELLOW "At line: %d and column: %d\n" RESET, NODE_BLINE(node), NODE_BCOL(node));
    printf("\n");
}

void printFunctionDoesNotExist(node_st *node)
{
    printf(RED "\nError: function does not exist\n" RESET);
    printf(YELLOW " Function: " RESET "'%s'" YELLOW " is not defined.\n" RESET, FUNCALL_NAME(node));
    printf(YELLOW "At line: %d and column: %d\n" RESET, NODE_BLINE(node), NODE_BCOL(node));
    printf("\n");
}

// Takes an expression and retrieves the type
void InferExprType(node_st *expr, stable_st *symbol_table)
{

    struct data_tc *data = DATA_TC_GET();

    switch (NODE_TYPE(expr))
    {
    case NT_FLOAT:
        // printf("FLOAT\n");
        EXPR_TYPE(expr) = CT_float;
        break;
    case NT_NUM:
        EXPR_TYPE(expr) = CT_int;
        break;
    case NT_BOOL:
        EXPR_TYPE(expr) = CT_bool;
        break;
    case NT_BINOP:
        // recursion to get correct child type.
        InferExprType(BINOP_LEFT(expr), symbol_table);
        InferExprType(BINOP_RIGHT(expr), symbol_table);

        enum BinOpType op = BINOP_OP(expr);

        enum Type left = EXPR_TYPE(BINOP_LEFT(expr));
        enum Type right = EXPR_TYPE(BINOP_RIGHT(expr));

        if (op == BO_add || op == BO_sub || op == BO_mul || op == BO_div || op == BO_mod)
        {
            // if either is boolean return error

            if (left == CT_bool || right == CT_bool)
            {
                data->type_error_count++;
                printTypeMisMatch(expr, CT_int, CT_bool);
            }

            // If either is float return float type.
            if (left == CT_float || right == CT_float)
            {
                EXPR_TYPE(expr) = CT_float;
            }
            else
            {
                EXPR_TYPE(expr) = CT_int;
            }
        }
        else if (op == BO_lt || op == BO_le || op == BO_gt || op == BO_ge || op == BO_eq || op == BO_ne)
        {
            // if either is boolean return error
            if (left == CT_bool || right == CT_bool)
            {
                data->type_error_count++;
                printTypeMisMatch(expr, CT_int, CT_bool);
            }

            EXPR_TYPE(expr) = CT_bool;
        }
        else if (op == BO_and || op == BO_or)
        {
            // if either is boolean return error
            if (left != CT_bool)
            {
                data->type_error_count++;
                printTypeMisMatch(expr, CT_bool, left);
            }

            if (right != CT_bool)
            {
                data->type_error_count++;
                printTypeMisMatch(expr, CT_bool, right);
            }

            EXPR_TYPE(expr) = CT_bool;
        }
        break;

    case NT_MONOP:
        // TODO: Implement monop type inference
        break;
    case NT_VAR:

        var_entry_st *result = STlookupVar(symbol_table, VAR_NAME(expr), true);

        if (result)
        {
            EXPR_TYPE(expr) = result->type;
        }
        else
        {
            data->type_error_count++;
            printVarDoesNotExist(expr);
        }

        break;
    case NT_FUNCALL:

        // if(FUNCALL_NAME(expr) == strcmp("__allocate")){
        //     EXPR_TYPE(expr) = CT_int;
        //     break;
        // }

        func_entry_st *result2 = STlookupFunc(symbol_table, FUNCALL_NAME(expr));

        if(!result2) {
            data->type_error_count++;
            printFunctionDoesNotExist(expr);
            break;
        }
        

        // Check the parameters of the function.
        node_st *arguments = FUNCALL_FUN_ARGS(expr);

        param_entry_st *param = result2->params;

        int arguments_count = 0;
        int param_count = 0;

        while (arguments || param)
        {

            if (arguments)
            {
                arguments_count++;
            }
            if (param)
            {
                param_count++;
            }

            // To many arguments
            if (arguments_count > param_count && !param)
            {
                data->type_error_count++;
                printf(RED "Error: Too many arguments in function call for the function: %s()\n" RESET, FUNCALL_NAME(expr));
                printf(YELLOW "At line: %d and column: %d\n" RESET, NODE_BLINE(expr), NODE_BCOL(expr));
                printf("\n");
                break;
            }

            // Too few arguments
            if (param_count > arguments_count && !arguments)
            {
                data->type_error_count++;
                printf(RED "Error: Too few arguments in function call: %s()\n" RESET, FUNCALL_NAME(expr));
                printf(YELLOW "At line: %d and column: %d\n" RESET, NODE_BLINE(expr), NODE_BCOL(expr));
                printf("\n");
                break;
            }

            // type checking
            if (param && arguments)
            {

                InferExprType(EXPRS_EXPR(arguments), symbol_table);

                if (EXPR_TYPE(EXPRS_EXPR(arguments)) != param->type)
                {
                    data->type_error_count++;
                    printTypeMisMatch(arguments, param->type, EXPR_TYPE(EXPRS_EXPR(arguments)));
                }
            }

            if (arguments)
            {
                arguments = EXPRS_NEXT(arguments);
            }
            if (param)
            {
                param = param->next;
            }
        }

        if (result2)
        {
            EXPR_TYPE(expr) = result2->returnType;
        }
        else
        {
            data->type_error_count++;
            printFunctionDoesNotExist(expr);
        }

        break;
    case NT_CAST:
        // NO checking is required according to civic docs
        // The only way to check if a conversion is allowed
        EXPR_TYPE(expr) = CAST_TYPE(expr);
        InferExprType(CAST_EXPR(expr), symbol_table);
        break;

    case NT_ARREXPR:
        EXPR_TYPE(expr) = CT_array;
        break;

    default:
        break;
    }
}

/**
 * @fn TCifelse
 */
node_st *TCifelse(node_st *node)
{
    if (!IFELSE_TABLE(node))
    {
        return node;
    }

    // printf("Entering if else\n");
    // printSymbolTableContent(IFELSE_TABLE(node), true);

    node_st *expr = IFELSE_COND(node);

    struct data_tc *data = DATA_TC_GET();

    InferExprType(expr, IFELSE_TABLE(node));

    if (EXPR_TYPE(expr) != CT_bool)
    {
        printf(RED "Error: If statement condition is not a boolean.\n" RESET);
        printf(YELLOW "At line: %d and column: %d\n" RESET, NODE_BLINE(node), NODE_BCOL(node));
        printf("\n");

        data->type_error_count++;
    }

    TRAVchildren(node);
    return node;
}

/**
 * @fn TCdowhile
 */
node_st *TCdowhile(node_st *node)
{
    if (!DOWHILE_TABLE(node))
    {
        return node;
    }

    node_st *expr = DOWHILE_COND(node);

    struct data_tc *data = DATA_TC_GET();

    InferExprType(expr, DOWHILE_TABLE(node));

    if (EXPR_TYPE(expr) != CT_bool)
    {
        printf(RED "Error: Do while statement condition is not a boolean.\n" RESET);
        printf(YELLOW "At line: %d and column: %d\n" RESET, NODE_BLINE(node), NODE_BCOL(node));
        printf("\n");

        data->type_error_count++;
    }

    TRAVchildren(node);
    return node;
}

/**
 * @fn TCfor
 */
node_st *TCfor(node_st *node)
{
    if (!FOR_TABLE(node))
    {
        return node;
    }

    node_st *expr = FOR_STOP(node);

    struct data_tc *data = DATA_TC_GET();

    InferExprType(expr, FOR_TABLE(node));

    if (EXPR_TYPE(expr) != CT_bool)
    {
        printf(RED "Error: For loop condition is not a boolean.\n" RESET);
        printf(YELLOW "At line: %d and column: %d\n" RESET, NODE_BLINE(node), NODE_BCOL(node));
        printf("\n");
        data->type_error_count++;
    }

    TRAVchildren(node);
    return node;
}

/**
 * @fn TCparam
 */
node_st *TCparam(node_st *node)
{
    TRAVchildren(node);
    return node;
}

/**
 * @fn TCwhile
 */
node_st *TCwhile(node_st *node)
{
    if (!WHILE_TABLE(node))
    {
        return node;
    }

    node_st *expr = WHILE_COND(node);

    struct data_tc *data = DATA_TC_GET();

    InferExprType(expr, WHILE_TABLE(node));

    if (EXPR_TYPE(expr) != CT_bool)
    {
        printf(RED "Error: While loop condition is not a boolean.\n" RESET);
        printf(YELLOW "At line: %d and column: %d\n" RESET, NODE_BLINE(node), NODE_BCOL(node));
        printf("\n");
        data->type_error_count++;
    }

    TRAVchildren(node);
    return node;
}


/**
 * @fn TCassign
 * i = 10;
 */
node_st *TCassign(node_st *node)
{
    if (!ASSIGN_TABLE(node))
    {
        TRAVchildren(node);
        return node;
    }

    printf("Entering assign\n");
    printf("%s", VARLET_NAME(ASSIGN_LET(node)));

    node_st *expr = ASSIGN_EXPR(node);

    struct data_tc *data = DATA_TC_GET();

    // printf("\n node type: %s\n", node_to_type_string(expr));

    var_entry_st *result = STlookupVar(ASSIGN_TABLE(node), VARLET_NAME(ASSIGN_LET(node)), true);

    InferExprType(expr, ASSIGN_TABLE(node));

    // var_entry_st *result = STlookupVar(ASSIGN_TABLE(node), VARLET_NAME(ASSIGN_LET(node)), true);

    if (!result)
    {
        node_st *var = ASTvar(NULL, strdup(VARLET_NAME(ASSIGN_LET(node))));
        printVarDoesNotExist(var);
        CCNfree(var);

        TRAVchildren(node);
        return node;
    }

    // printf("test \n\n\n\n\n\n\n");

    if(result->dimensions) {

        node_st *dimensions = result->dimensions;
        node_st *dim_1 = EXPRS_EXPR(dimensions);

        int number;

        //int[1]
        if(NODE_TYPE(dim_1) == NT_NUM) {
            number = NUM_VAL(dim_1);
        }

        node_st *array_expr = expr;

        int counter_pounter = 0;

        while(array_expr) {
            counter_pounter++;

            //two dimensional array
            if(NODE_TYPE(EXPRS_EXPR(array_expr)) == NT_ARREXPR) {
                //print error and continue.
                data->type_error_count++;
                printf(RED "Error: Two dimensional array assignment not supported for 1D array.\n \n" RESET);
            }
            //Check type of expression
            InferExprType(EXPRS_EXPR(array_expr), ASSIGN_TABLE(node));

            if(EXPR_TYPE(EXPRS_EXPR(array_expr)) != result->type) {
                data->type_error_count++;
                printTypeMisMatch(array_expr, result->type, EXPR_TYPE(EXPRS_EXPR(array_expr)));
            }

            if(number && counter_pounter > number) {
                data->type_error_count++;
                printf(RED "Error: Too many elements in array assignment.\n" RESET);
                printf(YELLOW "At line: %d and column: %d\n" RESET, NODE_BLINE(node), NODE_BCOL(node));
                printf("\n");
            }
        }
    }

    if (EXPR_TYPE(expr) != result->type)
    {
        printf(RED "Error: Type mismatch in assignment for variable: " RESET "%s \n", VARLET_NAME(ASSIGN_LET(node)));

        printf(YELLOW "  Expected: " RESET BLUE "%s\n" RESET, typeToString(result->type));
        printf(YELLOW "  Got:      " RESET RED "%s\n" RESET, typeToString(EXPR_TYPE(expr)));

        printf(YELLOW "At line: %d and column: %d\n" RESET, NODE_BLINE(node), NODE_BCOL(node));
        printf("\n");

        data->type_error_count++;
    }

    TRAVchildren(node);
    return node;
}

node_st *TCbinop(node_st *node)
{
    TRAVchildren(node);

    // Todo check if the types are correct.

    return node;
}

/**
 * @fn TCvardecl
 */
node_st *TCvardecl(node_st *node)
{
    struct data_tc *data = DATA_TC_GET();

    if (VARDECL_INIT(node))
    {
        node_st *init = VARDECL_INIT(node);
        InferExprType(init, VARDECL_TABLE(node)); // Get the inferred type

        enum Type declaredType = VARDECL_TYPE(node); // Get declared type

        if (EXPR_TYPE(init) != declaredType)
        {
            printf(RED "Error: Type mismatch in assignment for variable: " RESET "%s \n", VARDECL_NAME(node));

            printf(YELLOW "  Expected: " RESET BLUE "%s\n" RESET, typeToString(declaredType));
            printf(YELLOW "  Got:      " RESET RED "%s\n" RESET, typeToString(EXPR_TYPE(init)));

            printf(YELLOW "At line: %d and column: %d\n" RESET, NODE_BLINE(node), NODE_BCOL(node));
            printf("\n");

            data->type_error_count++;
        }
    }

    TRAVchildren(node);
    return node;
}

node_st *TCreturn(node_st *node)
{
    if (!RETURN_TABLE(node))
    {
        return node;
    }

    node_st *expr = RETURN_EXPR(node);

    struct data_tc *data = DATA_TC_GET();

    InferExprType(expr, RETURN_TABLE(node));

    // return type
    enum Type return_type = FUNDEF_TYPE(data->current_function);

    if (return_type == CT_void)
    {
        if (expr != NULL)
        {
            printf(RED "Error: Function with return type void cannot have a return with an expression.\n" RESET);
            printf(YELLOW "At line: %d and column: %d\n" RESET, NODE_BLINE(node), NODE_BCOL(node));
            printf("\n");
            data->type_error_count++;
        }
    }
    else if (EXPR_TYPE(expr) != return_type)
    {
        printf(RED "Error: Return type mismatch for function: " RESET "%s\n", FUNDEF_NAME(data->current_function));
        printf(YELLOW "  Expected: " RESET BLUE "%s\n" RESET, typeToString(return_type));
        printf(YELLOW "  Got:      " RESET RED "%s\n" RESET, typeToString(EXPR_TYPE(expr)));

        printf(YELLOW "At line: %d and column: %d\n" RESET, NODE_BLINE(node), NODE_BCOL(node));
        printf("\n");

        data->type_error_count++;
    }

    TRAVchildren(node);
    return node;
}