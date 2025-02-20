/**
 * @file
 *
 * Traversal: OptSubstraction
 * UID      : OS
 *
 *
 */

#include "ccn/ccn.h"
#include "ccngen/ast.h"
#include "ccngen/trav.h"

/**
 * @fn OSbinop
 */
node_st *OSbinop(node_st *node)
{
    TRAVchildren(node);
    return node;
}

