/**
 * @file
 *
 * Traversal: ClearVariableTable
 * UID      : CVT
 *
 *
 */

#include "ccn/ccn.h"
#include "ccngen/ast.h"
#include "ccngen/trav.h"

/**
 * @fn CVTprogram
 */
node_st *CVTprogram(node_st *node)
{
    TRAVchildren(node);
    return node;
}

