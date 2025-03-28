/**
 * @file
 *
 * Traversal: BuildExportTable
 * UID      : BET
 *
 */

#include <stdio.h>
#include <string.h>

#include "ccn/ccn.h"
#include "ccngen/ast.h"
#include "ccngen/trav.h"
#include "user/tables/exportTable/export_table.h"

void BETinit() {
  printf("\nINITIALIZING EXPORT TABLE TRAVERSAL\n");
  struct data_bet *data = DATA_BET_GET();
  data->export_table_ptr = ETnew();
}

void BETfini() {
  struct data_bet *data = DATA_BET_GET();
  ETprint(data->export_table_ptr);
}

 /**
 * @fn BETprogram
 */
node_st *BETprogram(node_st *node) {
  struct data_bet *data = DATA_BET_GET();
  PROGRAM_EXPORT_TABLE(node) = data->export_table_ptr;
  TRAVchildren(node);
  return node;
}

 /**
 * @fn BETfundef - Process exported functions
 */
node_st *BETfundef(node_st *node) {
  if (FUNDEF_EXPORT(node)) {
    struct data_bet *data = DATA_BET_GET();

    param_entry_st *params = NULL;
    param_entry_st **current_param = &params;
    node_st *param_node = FUNDEF_PARAMS(node);

    while (param_node) {
      *current_param = malloc(sizeof(param_entry_st));
      (*current_param)->name = strdup(PARAM_NAME(param_node));
      (*current_param)->type = PARAM_TYPE(param_node);
      (*current_param)->next = NULL;
      current_param = &(*current_param)->next;
      param_node = PARAM_NEXT(param_node);
    }

    ETaddFunction(data->export_table_ptr,
                  FUNDEF_NAME(node),
                  FUNDEF_NAME(node),
                  FUNDEF_TYPE(node),
                  params);
  }
  TRAVchildren(node);
  return node;
}

 /**
 * @fn BETglobdef - Process exported global variables
 */
node_st *BETglobdef(node_st *node) {
  if (GLOBDEF_EXPORT(node)) {
    struct data_bet *data = DATA_BET_GET();
    ETaddVariable(data->export_table_ptr, GLOBDEF_NAME(node), GLOBDEF_TYPE(node));
  }
  TRAVchildren(node);
  return node;
}
