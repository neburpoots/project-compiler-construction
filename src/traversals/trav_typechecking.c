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
#define RESET "\033[0m"  // Resets color formatting

#include "ccn/ccn.h"
#include "ccngen/ast.h"
#include "ccngen/trav.h"
#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include "user/symbolTable/symbol_table.h"
#include "user/stack/stack.h"
//used to create the stack
void TCinit() 
{


    return;
}

//used for cleanup
void TCfini() 
{
    // printf("\nFINISHING SYMBOL TABLE TRAVERSAL\n");

    // printf("Getting symbol table stack\n");
    // struct data_bst *data = DATA_BST_GET();

    // printf("Freeing up symbol table stack\n");
    // Stackfree(data->symbol_table_stack_ptr);

    // return;
}


/**
 * @fn TCprogram
 */
node_st *TCprogram(node_st *node)
{
    TRAVchildren(node);


    //Frees the symbol tables from memory.
    Stackfree(PROGRAM_SYMBOLTABLESTACKPTR(node));

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


//check return type of function
// First parameter is the function node, second parameter is the statements of any node.

//TODO NICK HAS TO ADD ATTRIBUTE TO SYMBOL TABLE SO THAT I CAN FIND THE PARENT DEFINITION
bool checkReturnType(node_st *node, node_st *stmts)
{

    //Loop over the statements in the function body to find the return statement.
    // while (stmts != NULL)
    // {
    //     //If the statement is a return statement.
    //     if (NODE_TYPE(stmts) == NT_RETURN)
    //     {
    //         //Get the return type of the return statement.
    //         node_st *returnTypeStmt = RETURN_TYPE(stmts);

    //         //If the return type of the function and the return type of the return statement are not the same.
    //         if (NODE_TYPE(node) != NODE_TYPE(returnTypeStmt))
    //         {
    //             //Print an error message.
    //             printf("Error: Return type of function does not match return type of return statement.\n");
    //             return false;
    //         }
    //     }

    //     //Move to the next statement.
    //     stmts = STMTS_NEXT(stmts);
    // }

    return true;
}

/**
 * @fn TCfundef
 */
node_st *TCfundef(node_st *node)
{

    TRAVchildren(node);
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

/**
 * @fn TCdowhile
 */
node_st *TCdowhile(node_st *node)
{
    TRAVchildren(node);
    return node;
}

/**
 * @fn TCfor
 */
node_st *TCfor(node_st *node)
{
    TRAVchildren(node);
    return node;
}

/**
 * @fn TCifelse
 */
node_st *TCifelse(node_st *node)
{
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
    TRAVchildren(node);
    return node;
}

/**
 * @fn TCassign
 * i = 10;
 */
node_st *TCassign(node_st *node)
{


    TRAVchildren(node);
    return node;
}

// Takes a vardecl node and the expected and resulting output types.
void printTypeMisMatch(node_st *node, enum Type expected, enum Type got)
{
    printf(RED "Error: Type mismatch in assignment.\n" RESET);
    printf(YELLOW "  Variable: " RESET "%s\n", VARDECL_NAME(node));
    printf(YELLOW "  Expected: " RESET BLUE "%s\n" RESET, typeToString(expected));
    printf(YELLOW "  Got:      " RESET RED "%s\n" RESET, typeToString(got));

    

    printf(RED "  Example: " RESET "%s %s = " RED "%s" RESET ";\n\n", typeToString(expected), VARDECL_NAME(node), typeToString(got));
}

// Takes an expression and retrieves the type
enum Type InferExprType(node_st *expr) {
    switch(NODE_TYPE(expr)) {
        case NT_FLOAT:
            // printf("FLOAT\n");
            return CT_float;
            break;
        case NT_NUM:
            // printf("INT\n");
            return CT_int;
            break;
        case NT_BOOL:
            // printf("BOOL\n");
            return CT_bool;
            break;
        case NT_BINOP:
            //recursion to get correct child type.
            enum Type left = InferExprType(BINOP_LEFT(expr));
            enum Type right = InferExprType(BINOP_RIGHT(expr));
            enum BinOpType op = BINOP_OP(expr);

            if(op == BO_add || op == BO_sub || op == BO_mul || op == BO_div || op == BO_mod) {
                // If either is float return float type.
                if(left == CT_float || right == CT_float) {
                    return CT_float;
                } else {
                    return CT_int;
                }
            } else if(op == BO_lt || op == BO_le || op == BO_gt || op == BO_ge || op == BO_eq || op == BO_ne) {
                return CT_bool;
            } else if(op == BO_and || op == BO_or) {
                return CT_bool;
            }
            break;

        case NT_MONOP:
            //TODO: Implement monop type inference
            break;
        case NT_VAR:
            //TODO get the symbol table from the node attribute to find the var type.
        case NT_FUNCALL:
            //TODO get the symbol table from the node attribute to find the function type.
        case NT_CAST:
            // NO checking is required according to civic docs
            // The only way to check if a conversion is allowed
            return CAST_TYPE(expr);


        default:
            break;
    }
}


/**
 * @fn TCvardecl
 */
node_st *TCvardecl(node_st *node)
{
    if(VARDECL_INIT(node)) {
        enum Type exprType = InferExprType(VARDECL_INIT(node)); // Get the inferred type
        enum Type declaredType = VARDECL_TYPE(node); // Get declared type

        if (exprType != declaredType) {
            printTypeMisMatch(node, declaredType, exprType);
        }
    }

    TRAVchildren(node);
    return node;
}

