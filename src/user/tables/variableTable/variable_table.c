// global_table.c
#include "user/tables/variableTable/variable_table.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

global_var_table_st *VTnew() {
  global_var_table_st *table_st = malloc(sizeof(global_var_table_st));
  table_st->globals = NULL;
  table_st->externs = NULL;
  table_st->global_size = 0;
  table_st->extern_size = 0;
  return table_st;
}

int VTadd(global_var_table_st *table, const char *name, enum Type type, bool is_exported) {
  global_var_entry_st *current = table->globals;
  while (current) {
      if (strcmp(current->name, name) == 0) {
          return current->index;
      }
      current = current->next;
  }

  global_var_entry_st *new_entry = malloc(sizeof(global_var_entry_st));
  new_entry->name = strdup(name);
  new_entry->type = type;
  new_entry->index = table->global_size;
  new_entry->is_exported = is_exported;
  new_entry->next = table->globals;
  table->globals = new_entry;
  table->global_size++;
  return new_entry->index;
}

int VTaddExtern(global_var_table_st *table, const char *name, enum Type type) {
  global_extern_var_entry_st *current = table->externs;
  while (current) {
      if (strcmp(current->name, name) == 0) {
          return current->index;
      }
      current = current->next;
  }

  global_extern_var_entry_st *new_extern = malloc(sizeof(global_extern_var_entry_st));
  new_extern->name = strdup(name);
  new_extern->type = type;
  new_extern->index = table->extern_size;
  new_extern->next = table->externs;
  table->externs = new_extern;
  table->extern_size++;
  return new_extern->index;
}

global_var_entry_st *VTget(global_var_table_st *table, int index) {
  global_var_entry_st *current = table->globals;
  while (current) {
      if (current->index == index) return current;
      current = current->next;
  }
  return NULL;
}

global_extern_var_entry_st *VTgetExtern(global_var_table_st *table, int index) {
  global_extern_var_entry_st *current = table->externs;
  while (current) {
      if (current->index == index) return current;
      current = current->next;
  }
  return NULL;
}

void VTprint(global_var_table_st *table) {
  if (!table || (!table->globals && !table->externs)) {
      printf("Global variable table is empty\n");
      return;
  }

  printf("\nGlobal Variable Table Contents:\n");

  if (table->globals) {
      printf("\nGlobal Variables (Non-Extern):\n");
      printf("┌───────┬────────────────────────┬────────────────────────┬──────────────┐\n");
      printf("│ Index │ Name                   │ Type                   │ Exported     │\n");
      printf("├───────┼────────────────────────┼────────────────────────┼──────────────┤\n");

      global_var_entry_st *current = table->globals;
      while (current) {
          printf("│ %5d │ %-22s │ %-22s │ %-12s │\n",
                 current->index,
                 current->name,
                 typeToString(current->type),
                 current->is_exported ? "Yes" : "No");
          current = current->next;
      }
      printf("└───────┴────────────────────────┴────────────────────────┴──────────────┘\n");
      printf("Total globals: %zu\n", table->global_size);
  }

  if (table->externs) {
      printf("\nExtern Variables:\n");
      printf("┌───────┬────────────────────────┬────────────────────────┐\n");
      printf("│ Index │ Name                   │ Type                   │\n");
      printf("├───────┼────────────────────────┼────────────────────────┤\n");

      global_extern_var_entry_st *current = table->externs;
      while (current) {
          printf("│ %5d │ %-22s │ %-22s │\n",
                 current->index,
                 current->name,
                 typeToString(current->type));
          current = current->next;
      }
      printf("└───────┴────────────────────────┴────────────────────────┘\n");
      printf("Total externs: %zu\n", table->extern_size);
  }
}

void VTfree(global_var_table_st *table) {
  global_var_entry_st *current_global = table->globals;
  while (current_global) {
      global_var_entry_st *next = current_global->next;
      free(current_global->name);
      free(current_global);
      current_global = next;
  }

  global_extern_var_entry_st *current_extern = table->externs;
  while (current_extern) {
      global_extern_var_entry_st *next = current_extern->next;
      free(current_extern->name);
      free(current_extern);
      current_extern = next;
  }

  free(table);
}
