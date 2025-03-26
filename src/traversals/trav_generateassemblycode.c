/**
 * @file
 *
 * Traversal: GenerateAssemblyCode
 * UID      : GAC
 *
 *
 */

#include "ccn/ccn.h"
#include "ccngen/ast.h"
#include "ccngen/trav.h"
#include <stdio.h>
#include <string.h>
#include "user/tables/exportTable/export_table.h"
#include "user/symbolTable/symbol_table.h"

void GACinit()
{
  printf("\nSTARTED CODE GENERATION\n");
}

void GACfini()
{
  printf("\nENDED CODE GENERATION\n");
}

void print_exports(node_st *node)
{
  export_table_st *export_table = PROGRAM_EXPORT_TABLE(node);

  if (export_table == NULL)
    return;

  export_entry_st *current_entry = export_table->entries;

  while (current_entry != NULL)
  {
    printf(".exportfun \"%s\" %s %s\n", current_entry->name, current_entry->label, typeToString(current_entry->return_type));
    current_entry = current_entry->next;
  }
}

void print_imports(node_st *node)
{
  import_table_st *import_table = PROGRAM_IMPORT_TABLE(node);

  if (import_table == NULL)
    return;

  import_entry_st *current_entry = import_table->entries;

  while (current_entry != NULL)
  {
    printf(".importfun \"%s\" %s ", current_entry->func_name, typeToString(current_entry->return_type));

    //parameters
    param_entry_st *current_param_entry = current_entry->parameters;

    while (current_param_entry != NULL)
    {
      printf("%s ", typeToString(current_param_entry->type));
      current_param_entry = current_param_entry->next;
    }

    printf("\n");

    current_entry = current_entry->next;
  }
}

/**
 * @fn GACprogram
 */
node_st *GACprogram(node_st *node)
{
  // import_table_st *import_table = PROGRAM_IMPORT_TABLE(node);
  print_exports(node);
  print_imports(node);
  TRAVchildren(node);
  return node;
}

/**
 * @fn GACfundef
 */
node_st *GACfundef(node_st *node)
{
  TRAVchildren(node);
  return node;
}

