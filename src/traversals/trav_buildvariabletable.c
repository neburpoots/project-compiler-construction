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
    VTadd(data->var_table_ptr, GLOBDEF_NAME(node), GLOBDEF_TYPE(node), true);
  }
  TRAVchildren(node);
  return node;
}

node_st *BVTvardecl(node_st *node) {
  struct data_bvt *data = DATA_BVT_GET();
  VTadd(data->var_table_ptr, VARDECL_NAME(node), VARDECL_TYPE(node), false);
  TRAVchildren(node);
  return node;
}
