/**
 * @file
 *
 * Traversal: BuildVariableTable
 * UID      : BVT
 */
#define RED "\033[1;31m"
#define GREEN "\033[1;32m"
#define YELLOW "\033[1;33m"
#define BLUE "\033[1;34m"
#define RESET "\033[0m" // Resets color formatting

#include "ccn/ccn.h"
#include "ccngen/ast.h"
#include "ccngen/trav.h"
#include "user/tables/variableTable/variable_table.h"
#include "ccn/ccn.h"
#include "ccngen/ast.h"
#include "ccngen/trav.h"
#include <stdio.h>
#include <stdlib.h>

#include <palm/str.h>

#include <string.h>


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
    int index
      = VTadd(data->var_table_ptr, GLOBDEF_NAME(node), GLOBDEF_TYPE(node), true);
    INDEX_INDEX(node) = index;
  }
  TRAVchildren(node);
  return node;
}

node_st *BVTassign(node_st *node) {
  struct data_bvt *data = DATA_BVT_GET();


  const char *name = VARLET_NAME(ASSIGN_LET(node));

  var_entry_st *result = STlookupVar(ASSIGN_TABLE(node), name, true);

  if(result) {
    int index = VTadd(data->var_table_ptr, name, result->type, false);
    INDEX_INDEX(node) = index;

  } else {
    printf(RED "Error: variable %s is used in assignment, but not in symbol table.\n" RESET, name);
  }



  TRAVchildren(node);
  return node;
}
