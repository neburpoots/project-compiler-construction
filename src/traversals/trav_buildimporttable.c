/**
 * @file
 *
 * Traversal: BuildImportTable
 * UID      : BIT
 *
 *
 */

#include "ccn/ccn.h"
#include "ccngen/ast.h"
#include "ccngen/trav.h"
#include <stdio.h>
#include "user/tables/importTable/import_table.h"
#include <string.h>

void BITinit()
{
  printf("\nINITIALIZING IMPORT TABLE TRAVERSAL\n");
  struct data_bit *data = DATA_BIT_GET();
  data->import_table_ptr = ITnew();
}

void BITfini()
{
  struct data_bit *data = DATA_BIT_GET();
  ITprint(data->import_table_ptr);
}

/**
 * @fn BITprogram
 */
node_st *BITprogram(node_st *node)
{
  struct data_bit *data = DATA_BIT_GET();
  PROGRAM_IMPORT_TABLE(node) = data->import_table_ptr;
  TRAVchildren(node);
  return node;
}

/**
 * @fn BITfundec
 */
node_st *BITfundec(node_st *node)
{
  import_table_st *table = DATA_BIT_GET()->import_table_ptr;
    param_entry_st *params = NULL;
    param_entry_st **current = &params;
    node_st *param = FUNDEC_PARAMS(node);
    while (param) {
        *current = malloc(sizeof(param_entry_st));
        (*current)->name = strdup(PARAM_NAME(param));
        (*current)->type = PARAM_TYPE(param);
        (*current)->next = NULL;
        current = &(*current)->next;
        param = PARAM_NEXT(param);
    }
    ITaddFunction(table, FUNDEC_NAME(node), FUNDEC_TYPE(node), params);
    TRAVchildren(node);
    return node;
}