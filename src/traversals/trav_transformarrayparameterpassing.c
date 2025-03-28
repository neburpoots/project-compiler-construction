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
 * Used to extract the indices from the array. Adds it to the symbol table aswell
 */
node_st *TAPparam(node_st *node) {
  if (PARAM_TYPE(node) == CT_array) {
    node_st *current_dim = PARAM_DIMS(node);
    node_st *new_params = NULL;
    node_st *last_dim_param = NULL;
    node_st *dim_ids = NULL;
    node_st *last_dim_id = NULL;  // New pointer to track end of dimension list

    while (current_dim != NULL) {
      char *dim_name = strdup(IDS_NAME(current_dim));
      if (!dim_name) {
        // Cleanup on error
        while (new_params) {
          node_st *tmp = new_params;
          new_params = PARAM_NEXT(new_params);
          CCNfree(tmp);
        }
        while (dim_ids) {
          node_st *tmp = dim_ids;
          dim_ids = IDS_NEXT(dim_ids);
          free(IDS_NAME(tmp));
          free(tmp);
        }
        return node;
      }

      // Create dimension parameter
      node_st *dim_param = ASTparam(NULL, NULL, dim_name, CT_int);
      STinsertVar(table, dim_name, CT_int);

      // Create ID node (don't strdup again)
      node_st *dim_id = ASTids(NULL, dim_name);

      // Append to dimension list (maintain original order)
      if (!dim_ids) {
        dim_ids = dim_id;
        last_dim_id = dim_id;
      } else {
        IDS_NEXT(last_dim_id) = dim_id;
        last_dim_id = dim_id;
      }

      // Link parameters
      if (!new_params) {
        new_params = dim_param;
        last_dim_param = dim_param;
      } else {
        PARAM_NEXT(last_dim_param) = dim_param;
        last_dim_param = dim_param;
      }

      current_dim = IDS_NEXT(current_dim);
    }

    // Update array entry
    var_entry_st *array_entry = STlookupVar(table, PARAM_NAME(node), false);
    if (array_entry) {
      // Free old dimensions if they exist
      if (array_entry->dimensions) {
        node_st *dim = (node_st *) array_entry->dimensions;
        while (dim) {
          node_st *tmp = dim;
          dim = IDS_NEXT(dim);
          free(IDS_NAME(tmp));
          free(tmp);
        }
      }
      array_entry->dimensions = dim_ids;
    } else {
      // Cleanup if no array entry found
      while (dim_ids) {
        node_st *tmp = dim_ids;
        dim_ids = IDS_NEXT(dim_ids);
        free(IDS_NAME(tmp));
        free(tmp);
      }
    }

    if (last_dim_param) {
      PARAM_NEXT(last_dim_param) = node;
      PARAM_NEXT(node) = NULL;
      return new_params;
    }
  }

  TRAVchildren(node);
  return node;
}

/**
 * @fn TAPfuncall
 * Alter the function call to use the extracted indices paramaters
 */
node_st *TAPfuncall(node_st *node) {
  char *func_name = FUNCALL_NAME(node);
  node_st *current_args = FUNCALL_FUN_ARGS(node);
  node_st *new_args = NULL;
  node_st *last_arg = NULL;

  // Process each argument
  while (current_args != NULL) {
    node_st *arg_expr = EXPRS_EXPR(current_args);

      // Handle array parameters
    if (NODE_TYPE(arg_expr) == NT_VAR) {
      var_entry_st *var_entry = STlookupVar(table, VAR_NAME(arg_expr), true);

      if (var_entry && var_entry->type == CT_array) {
              // Add dimension parameters first
        node_st *dims = (node_st *) var_entry->dimensions;
        while (dims != NULL) {
                  // Create dimension variable reference
          node_st *dim_var = ASTvar(NULL, strdup(IDS_NAME(dims)));
          node_st *dim_expr = ASTexprs(dim_var, NULL);

                  // Add to new arguments list
          if (!new_args) {
            new_args = dim_expr;
            last_arg = dim_expr;
          } else {
            EXPRS_NEXT(last_arg) = dim_expr;
            last_arg = dim_expr;
          }
          dims = IDS_NEXT(dims);
        }
      }
    }

      // Add original argument (array or scalar)
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

  // Replace old arguments with transformed ones
  if (FUNCALL_FUN_ARGS(node)) {
    CCNfree(FUNCALL_FUN_ARGS(node));
  }
  FUNCALL_FUN_ARGS(node) = new_args;

  printf("TRANSFORMED CALL: %s(", FUNCALL_NAME(node));
  node_st *arg = FUNCALL_FUN_ARGS(node);
  bool first = true;
  while (arg) {
    node_st *expr = EXPRS_EXPR(arg);
    if (NODE_TYPE(expr) == NT_VAR) {
      printf("%s%s", first ? "" : ", ", VAR_NAME(expr));
    }
    first = false;
    arg = EXPRS_NEXT(arg);
  }
  printf(")\n");


  TRAVchildren(node);
  return node;
}
