/**
 * @file
 *
 * Traversal: RenameIdentifiers
 * UID      : RI
 *
 *
 */

#include "ccn/ccn.h"
#include "ccngen/ast.h"
#include "ccngen/trav.h"

/**
 * @fn RIvar
 */
node_st *RIvar(node_st *node)
{
    TRAVchildren(node);
    return node;
}

/**
 * @fn RIvarlet
 */
node_st *RIvarlet(node_st *node)
{
    TRAVchildren(node);
    return node;
}

