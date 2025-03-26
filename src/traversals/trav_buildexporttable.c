/**
 * @file
 *
 * Traversal: BuildExportTable
 * UID      : BET
 *
 *
 */

#include "ccn/ccn.h"
#include "ccngen/ast.h"
#include "ccngen/trav.h"
#include "user/tables/exportTable/export_table.h"
#include <stdio.h>
#include <string.h>

void BETinit()
{
  printf("\nINITIALIZING EXPORT TABLE TRAVERSAL\n");
  struct data_bet *data = DATA_BET_GET();
  data->export_table_ptr = ETnew();
}

void BETfini()
{
  struct data_bet *data = DATA_BET_GET();
  ETprint(data->export_table_ptr);
  return;
}

/**
 * @fn BETprogram
 */
node_st *BETprogram(node_st *node)
{
    struct data_bet *data = DATA_BET_GET();
    PROGRAM_EXPORT_TABLE(node) = data->export_table_ptr;
    TRAVchildren(node);
    return node;
}

node_st *BETfundef(node_st *node)
{
    if (FUNDEF_EXPORT(node)) {
        struct data_bet *data = DATA_BET_GET();

        param_entry_st *param_list = NULL;
        param_entry_st **current = &param_list;

        node_st *param = FUNDEF_PARAMS(node);
        while (param) {
            *current = malloc(sizeof(param_entry_st));
            (*current)->name = strdup(PARAM_NAME(param));
            (*current)->type = PARAM_TYPE(param);
            (*current)->next = NULL;

            current = &(*current)->next;
            param = PARAM_NEXT(param);
        }

        ETadd(data->export_table_ptr,
              FUNDEF_NAME(node),
              FUNDEF_NAME(node),
              FUNDEF_TYPE(node),
              param_list);
    }

    TRAVchildren(node);
    return node;
}
