/**
 * @file
 *
 * Traversal: TestWhileStatements
 * UID      : WH
 *
 *
 */

#include "ccn/ccn.h"
#include "ccngen/ast.h"
#include "ccngen/trav.h"
#include <stdio.h>

/**
 * @fn WHwhile
 */
node_st *WHwhile(node_st *node)
{
    printf("Caught while\n");
    TRAVchildren(node);
    return node;
}

