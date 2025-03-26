/**
 * @file
 *
 * Traversal: ClearConstantTable
 * UID      : CCT
 *
 *
 */

#include "ccn/ccn.h"
#include "ccngen/ast.h"
#include "ccngen/trav.h"
#include <stdio.h>

/**
 * @fn CCTprogram
 */
// In some other traversal that needs the constant table:
node_st *CCTprogram(node_st *node) {
  printf("Clearing constant table\n");
  const_table_st *const_table = PROGRAM_CONSTANT_TABLE(node);
  if (const_table) {
    CTfree(const_table);
  }
  TRAVchildren(node);
  return node;
}