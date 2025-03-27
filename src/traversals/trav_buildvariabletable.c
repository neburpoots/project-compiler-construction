/**
 * @file
 *
 * Traversal: BuildVariableTable
 * UID      : BVT
 *
 *
 */

#include "ccn/ccn.h"
#include "ccngen/ast.h"
#include "ccngen/trav.h"
#include <stdio.h>
#include <string.h>
#include "user/tables/variableTable/variable_table.h"

void BVTinit()
{
  printf("\nINITIALIZING VARIABLE TABLE TRAVERSAL\n");
  struct data_bvt *data = DATA_BVT_GET();
  data->var_table_ptr = VTnew();
}

void BVTfini()
{
  struct data_bvt *data = DATA_BVT_GET();
  VTprint(data->var_table_ptr);
  return;
}

/**
 * @fn BVTprogram
 */
node_st *BVTprogram(node_st *node)
{
  struct data_bvt *data = DATA_BVT_GET();
  PROGRAM_VAR_TABLE(node) = data->var_table_ptr;
  TRAVchildren(node);
  return node;
}

/**
 * @fn BVTglobdef
 */
node_st *BVTglobdef(node_st *node) {
  struct data_bvt *data = DATA_BVT_GET();
  VTadd(data->var_table_ptr, GLOBDEF_NAME(node), GLOBDEF_TYPE(node), GLOBDEF_EXPORT(node));
  TRAVchildren(node);
  return node;
}

/**
* @fn BVTglobdecl
*/
node_st *BVTglobdecl(node_st *node) {
  struct data_bvt *data = DATA_BVT_GET();
  VTaddExtern(data->var_table_ptr, GLOBDECL_NAME(node), GLOBDECL_TYPE(node));
  TRAVchildren(node);
  return node;
}