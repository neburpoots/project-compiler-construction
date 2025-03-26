/**
 * @file
 *
 * Traversal: ClearImportTable
 * UID      : CIT
 *
 *
 */

#include "ccn/ccn.h"
#include "ccngen/ast.h"
#include "ccngen/trav.h"
#include "user/tables/importTable/import_table.h"
#include <stdio.h>

/**
 * @fn CITprogram
 */
node_st *CITprogram(node_st *node)
{
  printf("Clearing import table\n");
  import_table_st *import_table = PROGRAM_IMPORT_TABLE(node);
  if (import_table) {
    ITfree(import_table);
  }
  TRAVchildren(node);
  return node;
}

