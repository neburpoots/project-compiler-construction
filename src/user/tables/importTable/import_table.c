// import_table.c
#include "user/tables/importTable/import_table.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

import_table_st *ITnew() {
  import_table_st *table = malloc(sizeof(import_table_st));
  table->entries = NULL;
  table->size = 0;
  return table;
}

// add function
int ITaddFunction(import_table_st *table,
                  const char *name,
                  enum Type return_type,
                  param_entry_st *params) {
  // Check for duplicates
  import_entry_st *current = table->entries;
  for (int i = 0; current != NULL; current = current->next, i++) {
    if (current->entry_type == FUNCTION_ENTRY && strcmp(current->name, name) == 0
        && current->data.func.return_type == return_type) {
      return i;
    }
  }

  // Add new function entry
  import_entry_st *new_entry = malloc(sizeof(import_entry_st));
  new_entry->entry_type = FUNCTION_ENTRY;
  new_entry->name = strdup(name);
  new_entry->data.func.return_type = return_type;
  new_entry->data.func.parameters = params;
  new_entry->next = table->entries;
  table->entries = new_entry;
  return table->size++;
}

// add variable
int ITaddVariable(import_table_st *table, const char *name, enum Type var_type) {
  // Check for duplicates
  import_entry_st *current = table->entries;
  for (int i = 0; current != NULL; current = current->next, i++) {
    if (current->entry_type == VARIABLE_ENTRY && strcmp(current->name, name) == 0
        && current->data.var.var_type == var_type) {
      return i;
    }
  }

  // Add new variable entry
  import_entry_st *new_entry = malloc(sizeof(import_entry_st));
  new_entry->entry_type = VARIABLE_ENTRY;
  new_entry->name = strdup(name);
  new_entry->data.var.var_type = var_type;
  new_entry->next = table->entries;
  table->entries = new_entry;
  return table->size++;
}

// get var or function by index
import_entry_st *ITget(import_table_st *table, int index) {
  import_entry_st *current = table->entries;
  for (int i = 0; current != NULL && i < index; current = current->next, i++)
    ;
  return current;
}

// print from chatgpt
void ITprint(import_table_st *table) {
  printf("┌───────┬──────────┬────────────────────────┬──────────────┬─────────────────"
         "──────┐\n");
  printf("│ Index │   Type   │ Name                   │ Return/Type  │ Parameters      "
         "      │\n");
  printf("├───────┼──────────┼────────────────────────┼──────────────┼─────────────────"
         "──────┤\n");

  import_entry_st *current = table->entries;
  for (int i = 0; current != NULL; current = current->next, i++) {
    if (current->entry_type == FUNCTION_ENTRY) {
          // Print function entry
      char params[128] = "";
      param_entry_st *p = current->data.func.parameters;
      while (p) {
        strcat(params, typeToString(p->type));
        if (p->next) {
          strcat(params, ", ");
        }
        p = p->next;
      }
      printf("│ %5d │ FUNCTION │ %-22s │ %-12s │ %-21s │\n",
             i,
             current->name,
             typeToString(current->data.func.return_type),
             params);
    } else {
          // Print variable entry
      printf("│ %5d │ VARIABLE │ %-22s │ %-12s │ %-21s │\n",
             i,
             current->name,
             typeToString(current->data.var.var_type),
             "N/A");
    }
  }
  printf("└───────┴──────────┴────────────────────────┴──────────────┴─────────────────"
         "──────┘\n");
}

// free all
void ITfree(import_table_st *table) {
  import_entry_st *current = table->entries;
  while (current) {
    import_entry_st *next = current->next;
    free(current->name);
    if (current->entry_type == FUNCTION_ENTRY) {
      // Free function parameters
      param_entry_st *p = current->data.func.parameters;
      while (p) {
        param_entry_st *next_param = p->next;
        free(p->name);
        free(p);
        p = next_param;
      }
    }
    free(current);
    current = next;
  }
  free(table);
}
