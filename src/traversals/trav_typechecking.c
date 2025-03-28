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

// Update function signature in declaration
bool CheckArrayDimensions(node_st *dims, node_st *initializer, stable_st *st, struct data_tc *data);


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
        exit(EXIT_FAILURE);
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

    struct data_tc *data = DATA_TC_GET();

    if (GLOBDEF_INIT(node))
    {
        node_st *init = GLOBDEF_INIT(node);
        InferExprType(init, GLOBDEF_TABLE(node));

        enum Type declaredType = GLOBDEF_TYPE(node);

        if (GLOBDEF_DIMS(node))
        {
            // Array declaration
            if (EXPR_TYPE(init) != CT_array)
            {
                // Handle homogeneous initialization case (e.g., int[2,2] a = 5)
                if (EXPR_TYPE(init) == declaredType)
                {
                    // This will be handled in Milestone 6 transformations
                    TRAVchildren(node);
                    return node;
                }

                // Report type error
                printf(RED "Error: Array initialization type mismatch for '%s'\n" RESET, GLOBDEF_NAME(node));
                printf(YELLOW "  Expected: array of %s\n" RESET, typeToString(declaredType));
                printf(YELLOW "  Got:      %s\n" RESET, typeToString(EXPR_TYPE(init)));
                data->type_error_count++;
                TRAVchildren(node);
                return node;
            }

            // Check array dimensions match
            if (!CheckArrayDimensions(GLOBDEF_DIMS(node), init, GLOBDEF_TABLE(node), data))
            {
                TRAVchildren(node);
                return node;
            }

            // Check element types recursively
            CheckArrayElementTypes(ARREXPR_EXPRS(init), declaredType, GLOBDEF_TABLE(node), data);
        }
        else
        {
            // Non-array type checking
            if (EXPR_TYPE(init) != declaredType)
            {
                printf(RED "Error: Type mismatch for variable '%s'\n" RESET, GLOBDEF_NAME(node));
                printf(YELLOW "  Expected: %s\n" RESET, typeToString(declaredType));
                printf(YELLOW "  Got:      %s\n" RESET, typeToString(EXPR_TYPE(init)));
                data->type_error_count++;
            }
        }
    }

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
            node_st *indices = VAR_INDICES(expr);

            if(indices){
                node_st *dims = result->dimensions;

                node_st *second_dim = EXPRS_NEXT(dims);

                bool is_2d_array = false;

                if(second_dim){
                    is_2d_array = true;
                }
                

                node_st *first_index = EXPRS_EXPR(indices);

                InferExprType(first_index, symbol_table);

                //index is not int
                if(EXPR_TYPE(first_index) != CT_int){
                    data->type_error_count++;
                    printTypeMisMatch(expr, CT_int, EXPR_TYPE(first_index));
                }

                //if 1d array and no second index int x = array[1]
                if(!is_2d_array && !EXPRS_NEXT(indices)){
                    EXPR_TYPE(expr) = result->type;
                    break;
                }

                //accessing single d array with two indices.
                if(!is_2d_array && EXPRS_NEXT(indices)){
                    data->type_error_count++;
                    printf(RED "Error: Too many indices for 1d array.\n" RESET);
                    printf(YELLOW "At line: %d and column: %d\n" RESET, NODE_BLINE(expr), NODE_BCOL(expr));
                    printf("\n");
                    break;
                }

                //accessing 2d array with one index.
                if(is_2d_array && !EXPRS_NEXT(indices)) {
                    data->type_error_count++;
                    printf(RED "Error: Too few indices for 2d array.\n" RESET);
                    printf(YELLOW "At line: %d and column: %d\n" RESET, NODE_BLINE(expr), NODE_BCOL(expr));
                    printf("\n");
                    break;
                }

                node_st *second_index = EXPRS_EXPR(EXPRS_NEXT(indices));

                if(second_index && is_2d_array) {

                    InferExprType(second_index, symbol_table);

                    EXPR_TYPE(expr) = result->type;

                    if(EXPR_TYPE(second_index) != CT_int){
                        data->type_error_count++;
                        printTypeMisMatch(expr, CT_int, EXPR_TYPE(second_index));
                    }
                } else if(!is_2d_array && !second_index) {
                    //1d array
                    EXPR_TYPE(expr) = result->type; 
                } else {

                }
                
            } else {
                EXPR_TYPE(expr) = result->type;
            }
        } else {
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

        if (!result2)
        {
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
        // Array expression initial is handled by seperate function. See var_decl
        // int[2] = [1,2]
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
 * Handles assignments including array assignments with dimension checks
 */
node_st *TCassign(node_st *node) {
    struct data_tc *data = DATA_TC_GET();
    if (!ASSIGN_TABLE(node)) {
        TRAVchildren(node);
        return node;
    }

    node_st *varlet = ASSIGN_LET(node);
    node_st *expr = ASSIGN_EXPR(node);
    char *var_name = VARLET_NAME(varlet);

    // Type check the RHS expression first
    InferExprType(expr, ASSIGN_TABLE(node));

    // Look up variable in symbol table
    var_entry_st *var_entry = STlookupVar(ASSIGN_TABLE(node), var_name, true);
    if (!var_entry) {
        node_st *var = ASTvar(NULL, strdup(var_name));
        printVarDoesNotExist(var);
        CCNfree(var);
        TRAVchildren(node);
        return node;
    }

    // Handle array assignments
    if (var_entry->dimensions) {
        // Array variable assignment
        if (EXPR_TYPE(expr) != CT_array) {
            // Handle homogeneous initialization (e.g., arr = 5)
            if (EXPR_TYPE(expr) == var_entry->type) {
                TRAVchildren(node);
                return node;  // Handled in later transformations
            }
            
            // Type mismatch error
            printf(RED "Error: Array assignment type mismatch for '%s'\n" RESET, var_name);
            printf(YELLOW "  Expected: array of %s\n" RESET, typeToString(var_entry->type));
            printf(YELLOW "  Got:      %s\n" RESET, typeToString(EXPR_TYPE(expr)));
            data->type_error_count++;
            TRAVchildren(node);
            return node;
        }

        // Check array dimensions match declaration
        if (!CheckArrayDimensions(var_entry->dimensions, expr, ASSIGN_TABLE(node), data)) {
            TRAVchildren(node);
            return node;
        }

        // Check element types recursively
        CheckArrayElementTypes(ARREXPR_EXPRS(expr), var_entry->type, ASSIGN_TABLE(node), data);
    } else {
        // Scalar variable assignment
        if (EXPR_TYPE(expr) != var_entry->type) {
            printf(RED "Error: Type mismatch in assignment for '%s'\n" RESET, var_name);
            printf(YELLOW "  Expected: %s\n" RESET, typeToString(var_entry->type));
            printf(YELLOW "  Got:      %s\n" RESET, typeToString(EXPR_TYPE(expr)));
            data->type_error_count++;
        }
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
 * Helper function to check array dimensions match declarations
 * Returns true if dimensions match, false otherwise
 */
/**
 * Check if a dimension expression is a constant integer
 */
bool IsConstantInt(node_st *expr)
{
    return NODE_TYPE(expr) == NT_NUM;
}


/**
 * Revised dimension checking with function call support
 */
bool CheckArrayDimensions(node_st *dims, node_st *initializer, stable_st *st, struct data_tc *data)
{
    node_st *current_dim = dims;
    node_st *current_level = ARREXPR_EXPRS(initializer);
    int dim_index = 0;

    while (current_dim && current_level)
    {
        node_st *dim_expr = EXPRS_EXPR(current_dim);

        // 1. Check dimension expression type is int
        InferExprType(dim_expr, st);
        if (EXPR_TYPE(dim_expr) != CT_int)
        {
            printf(RED "Error: Dimension %d must be integer type\n" RESET, dim_index + 1);
            printf(YELLOW "  Got: %s\n" RESET, typeToString(EXPR_TYPE(dim_expr)));
            printf(YELLOW "  At line %d, column %d\n" RESET,
                   NODE_BLINE(dim_expr), NODE_BCOL(dim_expr));
            data->type_error_count++;
            return false;
        }

        // 2. Only check size if dimension is constant
        if (IsConstantInt(dim_expr))
        {
            int expected_size = NUM_VAL(dim_expr);
            int actual_size = CountArrayElements(current_level);

            if (actual_size > expected_size)
            {
                printf(RED "Error: Dimension %d size mismatch\n" RESET, dim_index + 1);
                printf(YELLOW "  Expected: %d elements\n" RESET, expected_size);
                printf(YELLOW "  Actual: %d elements\n" RESET, actual_size);
                data->type_error_count++;
                return false;
            }
        }

        // FIX: Advance to next level properly
        if (NODE_TYPE(EXPRS_EXPR(current_level)) == NT_ARREXPR) {
            current_level = ARREXPR_EXPRS(EXPRS_EXPR(current_level));
        } else {
            current_level = NULL;
        }

        // Move to next level (unchanged)
        current_dim = EXPRS_NEXT(current_dim);
        // current_level = EXPRS_NEXT(current_level);
        dim_index++;
    }
    return true;
}


int GetArrayNestingDepth(node_st *node)
{

    // Recursively count array nesting depth
    if (NODE_TYPE(node) != NT_ARREXPR)
        return 0;
    return 1 + GetArrayNestingDepth(EXPRS_EXPR(ARREXPR_EXPRS(node)));
}

int CountArrayElements(node_st *exprs)
{
    // Count elements at current nesting level
    int count = 0;
    while (exprs)
    {
        count++;
        exprs = EXPRS_NEXT(exprs);
    }
    return count;
}

int GetConstantIntValue(node_st *expr)
{
    // Helper to get integer value from constant expressions
    if (NODE_TYPE(expr) == NT_NUM)
        return NUM_VAL(expr);
    // Add handling for constant expressions if needed
    return -1; // Invalid value
}

/**
 * Helper function to check array element types
 */
void CheckArrayElementTypes(node_st *exprs, enum Type expectedType, stable_st *st, struct data_tc *data)
{
    while (exprs)
    {
        node_st *elem = EXPRS_EXPR(exprs);

        if (NODE_TYPE(elem) == NT_ARREXPR)
        {
            // Recursively check nested arrays
            CheckArrayElementTypes(ARREXPR_EXPRS(elem), expectedType, st, data);
        }
        else
        {
            InferExprType(elem, st);
            if (EXPR_TYPE(elem) != expectedType)
            {
                printTypeMisMatch(elem, expectedType, EXPR_TYPE(elem));
                data->type_error_count++;
            }
        }

        exprs = EXPRS_NEXT(exprs);
    }
}

/**
 * Main type checking for array declarations
 */
node_st *TCvardecl(node_st *node)
{
    struct data_tc *data = DATA_TC_GET();

    if (VARDECL_INIT(node))
    {
        node_st *init = VARDECL_INIT(node);
        InferExprType(init, VARDECL_TABLE(node));

        enum Type declaredType = VARDECL_TYPE(node);

        if (VARDECL_DIMS(node))
        {
            // Array declaration
            if (EXPR_TYPE(init) != CT_array)
            {
                // Handle homogeneous initialization case (e.g., int[2,2] a = 5)
                if (EXPR_TYPE(init) == declaredType)
                {
                    // This will be handled in Milestone 6 transformations
                    TRAVchildren(node);
                    return node;
                }

                // Report type error
                printf(RED "Error: Array initialization type mismatch for '%s'\n" RESET, VARDECL_NAME(node));
                printf(YELLOW "  Expected: array of %s\n" RESET, typeToString(declaredType));
                printf(YELLOW "  Got:      %s\n" RESET, typeToString(EXPR_TYPE(init)));
                data->type_error_count++;
                TRAVchildren(node);
                return node;
            }

            // Check array dimensions match
            if (!CheckArrayDimensions(VARDECL_DIMS(node), init, VARDECL_TABLE(node), data))
            {
                TRAVchildren(node);
                return node;
            }

            // Check element types recursively
            CheckArrayElementTypes(ARREXPR_EXPRS(init), declaredType, VARDECL_TABLE(node), data);
        }
        else
        {
            // Non-array type checking
            if (EXPR_TYPE(init) != declaredType)
            {
                printf(RED "Error: Type mismatch for variable '%s'\n" RESET, VARDECL_NAME(node));
                printf(YELLOW "  Expected: %s\n" RESET, typeToString(declaredType));
                printf(YELLOW "  Got:      %s\n" RESET, typeToString(EXPR_TYPE(init)));
                data->type_error_count++;
            }
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