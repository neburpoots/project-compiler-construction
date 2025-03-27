/**
 * @file
 *
 * Traversal: TransformArrayParameterPassing
 * UID      : TAP
 *
 *
 */

#include <stdio.h>
#include <string.h>

#include "ccn/ccn.h"
#include "ccngen/ast.h"
#include "ccngen/trav.h"
#include "user/symbolTable/symbol_table.h"

void TAPinit() {
  printf("\nENTERING TRANSFORM ARRAY PARAMETERS TRAVERSAL\n");
}

void TAPfini() {
  printf("\nFINISHING TRANSFORM ARRAY PARAMETERS TRAVERSAL\n");
}

stable_st *table;

/**
 * @fn TAPfundef
 */
node_st *TAPfundef(node_st *node) {
  table = FUNDEF_TABLE(node);
  TRAVchildren(node);
  printSymbolTableContent(table, false);
  return node;
}

/**
 * @fn TAPparam
 */
/**
 * @fn TAPparam
 */
node_st *TAPparam(node_st *node) {
  printf("PARAM TYPE: %s\n", typeToString(PARAM_TYPE(node)));

  if (PARAM_TYPE(node) == CT_array) {
    node_st *current_dim = PARAM_DIMS(node);
    node_st *new_params = NULL;
    node_st *last_dim_param = NULL;

    // Create new int parameters for each dimension
    while (current_dim != NULL) {
      printf("Processing dimension: %s\n", IDS_NAME(current_dim));

      // Create a copy of the dimension name
      char *dim_name = strdup(IDS_NAME(current_dim));
      if (!dim_name) {
        printf("Error: Memory allocation failed for dimension name\n");
        return node;
      }

      // create the dimension parameter node
      node_st *dim_param = ASTparam(NULL, NULL, dim_name, CT_int);

      // add to symbol table
      if (table != NULL) {
        var_entry_st *var_entry = STinsertVar(table, dim_name, CT_int);
        if (var_entry == NULL) {
          printf("Warning: Failed to add dimension parameter %s to symbol table\n",
                 dim_name);
        } else {
          printf("Added dimension parameter %s to symbol table\n", dim_name);
        }
      }

      // build new parameter
      if (new_params == NULL) {
        new_params = dim_param;
        last_dim_param = dim_param;
      } else {
        PARAM_NEXT(last_dim_param) = dim_param;
        last_dim_param = dim_param;
      }

      current_dim = IDS_NEXT(current_dim);
    }

    if (last_dim_param != NULL) {
      PARAM_NEXT(node) = NULL;
      PARAM_NEXT(last_dim_param) = node;
      return new_params;
    }
  }

  TRAVchildren(node);
  return node;
}

/**
 * @fn TAPfuncall
 */
node_st *TAPfuncall(node_st *node) {
  table = FUNDEF_TABLE(node);
  TRAVchildren(node);
  printSymbolTableContent(table, false);
  return node;
}