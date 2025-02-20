/**
 * @file
 *
 * Traversal: SumInts
 * UID      : SI
 *
 *
 */

#include "ccn/ccn.h"
#include "ccngen/ast.h"
#include "ccngen/trav.h"

void SIinit() { return; }
void SIfini() { return; }

/**
 * @fn SIstmts
 */
node_st *SIstmts(node_st *node)
{
    TRAVchildren(node);
    return node;
}

/**
 * @fn SInum
 */
node_st *SInum(node_st *node)
{
    TRAVchildren(node);
    return node;
}

