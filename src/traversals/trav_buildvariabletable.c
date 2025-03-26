/**
 * @file
 *
 * Traversal: BuildVariableTable
 * UID      : BVT
 *
 *
 */

#include "ccn/ccn.h"
#include "ccngen/ast.h"
#include "ccngen/trav.h"

void BVTinit() { return; }
void BVTfini() { return; }

/**
 * @fn BVTprogram
 */
node_st *BVTprogram(node_st *node)
{
    TRAVchildren(node);
    return node;
}

/**
 * @fn BVTglobdef
 */
node_st *BVTglobdef(node_st *node)
{
    TRAVchildren(node);
    return node;
}

/**
 * @fn BVTglobdecl
 */
node_st *BVTglobdecl(node_st *node)
{
    TRAVchildren(node);
    return node;
}

