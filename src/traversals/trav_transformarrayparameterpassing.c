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

stable_st *table;

void TAPinit() {
  printf("\nENTERING TRANSFORM ARRAY PARAMETERS TRAVERSAL\n");
}

void TAPfini() {
  table = NULL;
  printf("\nFINISHING TRANSFORM ARRAY PARAMETERS TRAVERSAL\n");
}

/**
 * @fn TAPfundef
 */
node_st *TAPfundef(node_st *node) {
  printf("\n\nFUNDEFF\n\n");
  table = FUNDEF_TABLE(node);
  TRAVchildren(node);
  printf("\n\n");
  printSymbolTableContent(table, false);
  printSymbolTableContent(STgetParentTable(table), false);
  printf("\n\n");
  return node;
}

/**
 * @fn TAPparam
 * Processes each array parameter to extract dimensions and insert new parameters.
 */
node_st *TAPparam(node_st *node) {
  if (PARAM_TYPE(node) == CT_array) {
      // Extract dimensions
    int dim_count = 0;
    node_st *dim = PARAM_DIMS(node);
    while (dim) {
      dim_count++;
      dim = IDS_NEXT(dim);
    }

      // Store dimension names
    char **dim_names = malloc(dim_count * sizeof(char *));
    dim = PARAM_DIMS(node);
    for (int i = 0; i < dim_count; i++) {
      dim_names[i] = strdup(IDS_NAME(dim));
      dim = IDS_NEXT(dim);
    }

      // Update symbol table entry
    var_entry_st *entry = STlookupVar(table, PARAM_NAME(node), false);
    if (!entry) {
      for (int i = 0; i < dim_count; i++) {
        free(dim_names[i]);
      }
      free(dim_names);
      return node;
    }
    entry->dimension_names = dim_names;
    entry->num_dimensions = dim_count;

      // Create new dimension parameters
    node_st *new_params = NULL;
    node_st *last_param = NULL;
    for (int i = 0; i < dim_count; i++) {
      node_st *dim_param = ASTparam(NULL, NULL, strdup(dim_names[i]), CT_int);
      STinsertVar(table, dim_names[i], CT_int);
      if (!new_params) {
        new_params = dim_param;
        last_param = dim_param;
      } else {
        PARAM_NEXT(last_param) = dim_param;
        last_param = dim_param;
      }
    }

      // Link new parameters and continue traversal
    node_st *original_next = PARAM_NEXT(node);
    PARAM_NEXT(node) = original_next; // Restore original next
    if (new_params) {
      PARAM_NEXT(last_param) = node;
          // Process the next parameters recursively
      PARAM_NEXT(node) = TRAVopt(PARAM_NEXT(node));
      return new_params;
    }
  }
  // Process next parameters
  PARAM_NEXT(node) = TRAVopt(PARAM_NEXT(node));
  return node;
}

/**
 * @fn TAPfuncall
 * Alter the function call to use the extracted indices paramaters
 */
node_st *TAPfuncall(node_st *node) {
  node_st *new_args = NULL;
  node_st *last_arg = NULL;
  node_st *current_args = FUNCALL_FUN_ARGS(node);

  while (current_args) {
    node_st *arg_expr = EXPRS_EXPR(current_args);

    if (NODE_TYPE(arg_expr) == NT_VAR) {
      var_entry_st *var_entry = STlookupVar(table, VAR_NAME(arg_expr), true);

      if (var_entry && var_entry->type == CT_array) {
        // add dimension arguments
        for (int i = 0; i < var_entry->num_dimensions; i++) {
          node_st *dim_var = ASTvar(NULL, strdup(var_entry->dimension_names[i]));
          node_st *dim_expr = ASTexprs(dim_var, NULL);

          if (!new_args) {
            new_args = dim_expr;
            last_arg = dim_expr;
          } else {
            EXPRS_NEXT(last_arg) = dim_expr;
            last_arg = dim_expr;
          }
        }
      }
    }

    // add original comments
    node_st *arg_copy = ASTexprs(CCNcopy(arg_expr), NULL);
    if (!new_args) {
      new_args = arg_copy;
      last_arg = arg_copy;
    } else {
      EXPRS_NEXT(last_arg) = arg_copy;
      last_arg = arg_copy;
    }

    current_args = EXPRS_NEXT(current_args);
  }

  // replace thwe args
  if (FUNCALL_FUN_ARGS(node)) {
    CCNfree(FUNCALL_FUN_ARGS(node));
  }
  FUNCALL_FUN_ARGS(node) = new_args;

  return node;
}
