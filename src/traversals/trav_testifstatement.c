/**
 * @file
 *
 * Traversal: TestIfStatement
 * UID      : IFS
 *
 *
 */

#include "ccn/ccn.h"
#include "ccngen/ast.h"
#include "ccngen/trav.h"
#include <stdio.h>

/**
 * @fn IFSifelse
 */
node_st *IFSifelse(node_st *node)
{
    printf("test");
    // TRAVthen(node);
    // TRAVchildren(node);
    return node;
}

