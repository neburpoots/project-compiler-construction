/**
 * @file
 *
 * Traversal: BuildVariableTable
 * UID      : BVT
 */

#include "ccn/ccn.h"
#include "ccngen/ast.h"
#include "ccngen/trav.h"
#include "user/tables/variableTable/variable_table.h"

void BVTinit() {
  struct data_bvt *data = DATA_BVT_GET();
  data->var_table_ptr = VTnew();
}

void BVTfini() {
  struct data_bvt *data = DATA_BVT_GET();
  VTprint(data->var_table_ptr);
}

node_st *BVTprogram(node_st *node) {
  struct data_bvt *data = DATA_BVT_GET();
  PROGRAM_VAR_TABLE(node) = data->var_table_ptr;
  TRAVchildren(node);
  return node;
}

node_st *BVTfundef(node_st *node) {
  struct data_bvt *data = DATA_BVT_GET();
  node_st *param = FUNDEF_PARAMS(node);

  while (param) {
    VTadd(data->var_table_ptr, PARAM_NAME(param), PARAM_TYPE(param), true);
    param = PARAM_NEXT(param);
  }

  TRAVchildren(node);
  return node;
}

node_st *BVTglobdef(node_st *node) {
  if (!GLOBDEF_EXPORT(node)) {
    struct data_bvt *data = DATA_BVT_GET();
    int index = VTadd(data->var_table_ptr, GLOBDEF_NAME(node), GLOBDEF_TYPE(node), true);
    INDEX_INDEX(node) = index;
  }
  TRAVchildren(node);
  return node;
}

node_st *BVTassign(node_st *node) {
  struct data_bvt *data = DATA_BVT_GET();

  const char *name = VARLET_NAME(ASSIGN_LET(node));

  var_entry_st *result = STlookupVar(ASSIGN_TABLE(node), name, true);
  
  int index = VTadd(data->var_table_ptr, name, result->type, false);

  INDEX_INDEX(node) = index;
  TRAVchildren(node);
  return node;
}
