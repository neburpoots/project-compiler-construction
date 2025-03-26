/**
 * @file
 *
 * Traversal: GenerateAssemblyCode
 * UID      : GAC
 *
 *
 */

#include "ccn/ccn.h"
#include "ccngen/ast.h"
#include "ccngen/trav.h"

/**
 * @fn GACprogram
 */
node_st *GACprogram(node_st *node)
{
    TRAVchildren(node);
    return node;
}

/**
 * @fn GACfundef
 */
node_st *GACfundef(node_st *node)
{
    TRAVchildren(node);
    return node;
}

