/**
 * @file
 *
 * Traversal: ClearVariableTable
 * UID      : CVT
 *
 *
 */

#include <stdio.h>
#include <string.h>

#include "ccn/ccn.h"
#include "ccngen/ast.h"
#include "ccngen/trav.h"

/**
 * @fn CVTprogram
 */
node_st *CVTprogram(node_st *node) {
  printf("Clearing variable table\n");
  glob_var_table_st *global_var_table = PROGRAM_VAR_TABLE(node);
  if (global_var_table) {
    VTfree(global_var_table);
  }
  TRAVchildren(node);
  return node;
}
