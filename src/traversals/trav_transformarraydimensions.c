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

  printSymbolTableContent(symbol_table, false);

  TRAVchildren(node);
  return node;
}

void remove_dims_from_param(node_st *node) {
  if (PARAM_TYPE(node) == CT_array && PARAM_DIMS(node)) {
    CCNfree(PARAM_DIMS(node));
    PARAM_DIMS(node) = NULL;
  }
}

/**
 * @fn TADparam
 */
node_st *TADparam(node_st *node) {
  node_st *current_param = node;

  while (current_param != NULL) {
    remove_dims_from_param(current_param);
    current_param = PARAM_NEXT(current_param);
  }

  return node;
}
