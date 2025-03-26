// import_table.c
#include "user/tables/importTable/import_table.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

import_table_st *ITnew() {
    import_table_st *table = malloc(sizeof(import_table_st));
    table->entries = NULL;
    table->size = 0;
    table->capacity = 0;
    return table;
}

int ITaddFunction(import_table_st *table, const char *name, enum Type return_type, param_entry_st *params) {
    import_entry_st *current = table->entries;
    for (int i = 0; current != NULL; current = current->next, i++) {
        if (strcmp(current->func_name, name) == 0 &&
            current->return_type == return_type) {
            return i;
        }
    }

    import_entry_st *new_entry = malloc(sizeof(import_entry_st));
    new_entry->func_name = strdup(name);
    new_entry->return_type = return_type;
    new_entry->parameters = params;
    new_entry->next = table->entries;
    table->entries = new_entry;
    return table->size++;
}


import_entry_st *ITget(import_table_st *table, int index) {
    import_entry_st *current = table->entries;
    for (int i = 0; current != NULL && i < index; current = current->next, i++);
    return current;
}

void ITprint(import_table_st *table) {
  if (!table || !table->entries) {
      printf("Import table is empty\n");
      return;
  }

  printf("\nImport Table Contents:\n");
  printf("┌───────┬────────────────────────┬──────────────┬──────────────────────────────────────────────────────────────┐\n");
  printf("│ Index │ Function               │ Return Type  │ Parameters                                                   │\n");
  printf("├───────┼────────────────────────┼──────────────┼──────────────────────────────────────────────────────────────┤\n");

  import_entry_st *current = table->entries;
  int current_index = 0;

  while (current) {
      char params_str[512] = "";  // Buffer for parameters
      param_entry_st *p = current->parameters;

      while (p) {
          strncat(params_str, typeToString(p->type), sizeof(params_str) - strlen(params_str) - 1);
          strncat(params_str, " ", sizeof(params_str) - strlen(params_str) - 1);
          strncat(params_str, p->name, sizeof(params_str) - strlen(params_str) - 1);
          if (p->next) strncat(params_str, ", ", sizeof(params_str) - strlen(params_str) - 1);
          p = p->next;
      }

      printf("│ %5d │ %-22s │ %-12s │ %-60s │\n",
        current_index,
             current->func_name,
             typeToString(current->return_type),
             params_str);

      current = current->next;
      current_index++;
  }

  printf("└───────┴────────────────────────┴──────────────┴──────────────────────────────────────────────────────────────┘\n");
  printf("Total imports: %d\n\n", current_index);
}



void ITfree(import_table_st *table) {
    import_entry_st *current = table->entries;
    while (current) {
        import_entry_st *next = current->next;
        free(current->func_name);

        // Free parameters
        param_entry_st *p = current->parameters;
        while (p) {
            param_entry_st *next_param = p->next;
            free(p->name);
            free(p);
            p = next_param;
        }

        free(current);
        current = next;
    }
    free(table);
}