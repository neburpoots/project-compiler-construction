/**
 * @file
 *
 * Traversal: BuildSymbolTables
 * UID      : BST
 *
 *
 */

#include "ccn/ccn.h"
#include "ccngen/ast.h"
#include "ccngen/trav.h"
#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include "user/symbolTable/symbol_table.h"

 void BSTinit() { return; }
 void BSTfini() { return; }

/**
 * @fn BSTprogram
 */
node_st *BSTprogram(node_st *node)
{
    printf("Started traversal\n");

    struct data_bst *data = DATA_BST_GET();

    printf("Creating symbol table\n");

    // SymbolTable *t = createSymbolTable(NULL);

    TRAVchildren(node);
    return node;
}

/**
 * @fn BSTfunbody
 */
node_st *BSTfunbody(node_st *node)
{
    TRAVchildren(node);
    return node;
}

/**
 * @fn BSTdowhile
 */
node_st *BSTdowhile(node_st *node)
{
    TRAVchildren(node);
    return node;
}

/**
 * @fn BSTfor
 */
node_st *BSTfor(node_st *node)
{
    TRAVchildren(node);
    return node;
}

/**
 * @fn BSTifelse
 */
node_st *BSTifelse(node_st *node)
{
    TRAVchildren(node);
    return node;
}

/**
 * @fn BSTwhile
 */
node_st *BSTwhile(node_st *node)
{
    TRAVchildren(node);
    return node;
}

/**
 * @fn BSTfundef
 */
node_st *BSTfundef(node_st *node)
{
    TRAVchildren(node);
    return node;
}