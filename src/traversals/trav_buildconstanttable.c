/**
 * @file
 *
 * Traversal: BuildConstantTable
 * UID      : BCT
 *
 *
 */

#include "ccn/ccn.h"
#include "ccngen/ast.h"
#include "ccngen/trav.h"
#include <stdio.h>
#include "user/tables/constTable/const_table.h"

void Add_node_value(node_st *node, ConstType type);

//used to create the stack
void BCTinit() {
  struct data_bct *data = DATA_BCT_GET();
  if (data->const_table_ptr == NULL) {
      data->const_table_ptr = CTnew();
  }
}


//used for cleanup
void BCTfini()
{
    struct data_bct *data = DATA_BCT_GET();
    if (data->const_table_ptr) {
        CTprint(data->const_table_ptr);
    }
    printf("\nFINISHING CONSTANT TABLE TRAVERSAL\n");
}

//helper function to add value to constant table
void Add_node_value(node_st *node, ConstType type){
  struct data_bct *data = DATA_BCT_GET();

  //Node index
  int index;

  switch (type)
  {
    case CONST_INT:
      index = CTadd(data->const_table_ptr, type, &NUM_VAL(node));
      break;

    case CONST_FLOAT:
      index = CTadd(data->const_table_ptr, type, &FLOAT_VAL(node));
      break;

    case CONST_BOOL:
      index = CTadd(data->const_table_ptr, type, &BOOL_VAL(node));
      break;

  default:
    printf("Supplied unknown type to constant table insertion function\n");
    break;
  }
  //set node index
  INDEX_INDEX(node) = index;
}

/**
 * @fn BCTprogram
 */
node_st *BCTprogram(node_st *node)
{
    struct data_bct *data = DATA_BCT_GET();
    PROGRAM_CONSTANT_TABLE(node) = data->const_table_ptr;
    TRAVchildren(node);
    return node;
}

/**
 * @fn BCTnum
 */
node_st *BCTnum(node_st *node)
{
  Add_node_value(node, CONST_INT);

  TRAVchildren(node);
  return node;
}

/**
 * @fn BCTfloat
 */
node_st *BCTfloat(node_st *node)
{
  Add_node_value(node, CONST_FLOAT);
  TRAVchildren(node);
  return node;
}

/**
 * @fn BCTbool
 */
node_st *BCTbool(node_st *node)
{
  Add_node_value(node, CONST_BOOL);

  TRAVchildren(node);
  return node;
}

/**
 * @fn BCTcondexpr
 */
node_st *BCTcondexpr(node_st *node) {
  TRAVdo(CONDEXPR_THEN_EXPR(node));
  TRAVdo(CONDEXPR_ELSE_EXPR(node));
  return node;
}

