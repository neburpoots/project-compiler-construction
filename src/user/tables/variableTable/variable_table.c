#include "user/tables/variableTable/variable_table.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "user/symbolTable/symbol_table.h"

glob_var_table_st *VTnew() {
  glob_var_table_st *table = malloc(sizeof(glob_var_table_st));
  table->entries = NULL;
  table->size = 0;
  return table;
}

int VTadd(glob_var_table_st *table,
          const char *name,
          enum Type type,
          bool is_initialized) {
  glob_var_entry_st *current = table->entries;
  while (current) {
    if (strcmp(current->name, name) == 0) {
      return -1;
    }
    current = current->next;
  }

  glob_var_entry_st *new_entry = malloc(sizeof(glob_var_entry_st));
  new_entry->name = strdup(name);
  new_entry->type = type;
  new_entry->index = table->size;
  new_entry->is_initialized = is_initialized;
  new_entry->next = table->entries;
  table->entries = new_entry;
  table->size++;
  return new_entry->index;
}

glob_var_entry_st *VTget(glob_var_table_st *table, int index) {
  glob_var_entry_st *current = table->entries;
  while (current) {
    if (current->index == index) {
      return current;
    }
    current = current->next;
  }
  return NULL;
}

// Cannot currently rely upon this function
glob_var_entry_st *VTgetByName(glob_var_table_st *table, const char *name) {
  glob_var_entry_st *current = table->entries;
  while (current) {
    if (strcmp(current->name, name) == 0) {
      return current;
    }
    current = current->next;
  }
  return NULL;
}

void VTprint(glob_var_table_st *table) {
  if (!table || !table->entries) {
    printf("Variable table is empty\n");
    return;
  }

  printf(
    "┌───────┬────────────────────────┬────────────────────────┬──────────────┐\n");
  printf(
    "│ Index │ Name                   │ Type                   │ Initialized  │\n");
  printf(
    "├───────┼────────────────────────┼────────────────────────┼──────────────┤\n");

  glob_var_entry_st *current = table->entries;
  while (current) {
    printf("│ %5d │ %-22s │ %-22s │ %-12s │\n",
           current->index,
           current->name,
           typeToString(current->type),
           current->is_initialized ? "Yes" : "No");
    current = current->next;
  }
  printf(
    "└───────┴────────────────────────┴────────────────────────┴──────────────┘\n");
}

void VTfree(glob_var_table_st *table) {
  glob_var_entry_st *current = table->entries;
  while (current) {
    glob_var_entry_st *next = current->next;
    free(current->name);
    free(current);
    current = next;
  }
  free(table);
}
