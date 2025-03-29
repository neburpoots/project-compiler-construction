/**
 * @file
 *
 * Traversal: TransformArrayDimensions
 * UID      : TAD
 *
 *
 */

#include <stdio.h>

#include "ccn/ccn.h"
#include "ccngen/ast.h"
#include "ccngen/trav.h"
#include "user/symbolTable/symbol_table.h"

stable_st *symbol_table;

void TADinit() {
  return;
}

void TADfini() {
  symbol_table = NULL;
  return;
}

/**
 * @fn TADfundef
 */
node_st *TADfundef(node_st *node) {
  symbol_table = FUNDEF_TABLE(node);
  TRAVchildren(node);
  return node;
}

/**
 * @fn TADparam
 */
node_st *TADparam(node_st *node) {
  if (PARAM_TYPE(node) == CT_array) {
    printf("ARRAY \n");

    node_st *dims = PARAM_DIMS(node);

    while (dims) {
      printf("%s\n", IDS_NAME(dims));
      dims = IDS_NEXT(dims);
    }


    printf("CLEARING DIMS\n");
  // CCNfree(PARAM_DIMS(node));
  }

  TRAVchildren(node);
  return node;
}
