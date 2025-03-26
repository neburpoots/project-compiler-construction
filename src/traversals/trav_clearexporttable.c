/**
 * @file
 *
 * Traversal: ClearExportTable
 * UID      : CET
 *
 *
 */

#include "ccn/ccn.h"
#include "ccngen/ast.h"
#include "ccngen/trav.h"
#include <stdio.h>
#include "user/tables/exportTable/export_table.h"

/**
 * @fn CETprogram
 */
node_st *CETprogram(node_st *node)
{
  printf("Clearing export table\n");
  export_table_st *export_table = PROGRAM_EXPORT_TABLE(node);
  if (export_table) {
    ETfree(export_table);
  }
  TRAVchildren(node);
  return node;
}

