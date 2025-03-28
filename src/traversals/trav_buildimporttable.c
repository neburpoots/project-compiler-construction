/**
 * @file
 *
 * Traversal: BuildImportTable
 * UID      : BIT
 *
 *
 */

#include <stdio.h>
#include <string.h>

#include "ccn/ccn.h"
#include "ccngen/ast.h"
#include "ccngen/trav.h"
#include "user/tables/importTable/import_table.h"

void BITinit() {
  printf("\nINITIALIZING IMPORT TABLE TRAVERSAL\n");
  struct data_bit *data = DATA_BIT_GET();
  data->import_table_ptr = ITnew();
}

void BITfini() {
  struct data_bit *data = DATA_BIT_GET();
  ITprint(data->import_table_ptr);
}

/**
 * @fn BITprogram
 */
node_st *BITprogram(node_st *node) {
  struct data_bit *data = DATA_BIT_GET();
  PROGRAM_IMPORT_TABLE(node) = data->import_table_ptr;
  TRAVchildren(node);
  return node;
}

/**
 * @fn BITfundec
 */
node_st *BITfundec(node_st *node) {
  import_table_st *table = DATA_BIT_GET()->import_table_ptr;
  param_entry_st *params = NULL;
  param_entry_st **current_param = &params;

  // get parameters
  node_st *param_node = FUNDEC_PARAMS(node);
  while (param_node) {
    *current_param = malloc(sizeof(param_entry_st));
    (*current_param)->name = strdup(PARAM_NAME(param_node));
    (*current_param)->type = PARAM_TYPE(param_node);
    (*current_param)->next = NULL;
    current_param = &(*current_param)->next;
    param_node = PARAM_NEXT(param_node);
  }

  // add to import table
  ITaddFunction(table, FUNDEC_NAME(node), FUNDEC_TYPE(node), params);
  TRAVchildren(node);
  return node;
}

/**
 * @fn BITglobdec
 */
node_st *BITglobdecl(node_st *node) {
  import_table_st *table = DATA_BIT_GET()->import_table_ptr;
  ITaddVariable(table, GLOBDECL_NAME(node), GLOBDECL_TYPE(node));
  TRAVchildren(node);
  return node;
}
