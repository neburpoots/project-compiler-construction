/**
 * @file
 *
 * Traversal: TransformArrayParameterPassing
 * UID      : TAP
 *
 *
 */

#include "ccn/ccn.h"
#include "ccngen/ast.h"
#include "ccngen/trav.h"
#include <stdio.h>
#include <string.h>

void TAPinit()
{
  printf("\nENTERING TRANSFORM ARRAY PARAMETERS TRAVERSAL\n");
}

void TAPfini()
{
  printf("\nFINISHING TRANSFORM ARRAY PARAMETERS TRAVERSAL\n");
}

/**
 * @fn TAPfundef
 */
node_st *TAPfundef(node_st *node)
{
  TRAVchildren(node);
  return node;
}


/**
 * @fn TAPparam
 */
node_st *TAPparam(node_st *node)
{
  TRAVchildren(node);
  return node;
}

