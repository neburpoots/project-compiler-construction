// export_table.c
#include "user/tables/exportTable/export_table.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

export_table_st *ETnew() {
    export_table_st *table = malloc(sizeof(export_table_st));
    table->entries = NULL;
    table->size = 0;
    table->capacity = 0;
    return table;
}

int ETadd(export_table_st *table, const char *name, enum Type return_type, param_entry_st *params) {
    export_entry_st *current = table->entries;
    for (int i = 0; current != NULL; current = current->next, i++) {
        if (strcmp(current->name, name) == 0 &&
            current->return_type == return_type) {
            return i;
        }
    }

    // Create new entry
    export_entry_st *new_entry = malloc(sizeof(export_entry_st));
    new_entry->name = strdup(name);
    new_entry->return_type = return_type;
    new_entry->params = params;
    new_entry->next = table->entries;
    table->entries = new_entry;
    return table->size++;
}

export_entry_st *ETget(export_table_st *table, int index) {
    export_entry_st *current = table->entries;
    for (int i = 0; current != NULL && i < index; current = current->next, i++);
    return current;
}

void ETprint(export_table_st *table) {
  if (!table || !table->entries) {
      printf("Export table is empty\n");
      return;
  }

  printf("\nExport Table Contents:\n");
  printf("┌───────┬────────────────────────┬──────────────┬──────────────────────────────────────────────────────────────┐\n");
  printf("│ Index │ Function               │ Return Type  │ Parameters                                                   │\n");
  printf("├───────┼────────────────────────┼──────────────┼──────────────────────────────────────────────────────────────┤\n");

  export_entry_st *current = table->entries;
  int current_index = 0;

  while (current) {
      char params_str[512] = "";  // Buffer for parameters
      param_entry_st *p = current->params;

      while (p) {
          strncat(params_str, typeToString(p->type), sizeof(params_str) - strlen(params_str) - 1);
          strncat(params_str, " ", sizeof(params_str) - strlen(params_str) - 1);
          strncat(params_str, p->name, sizeof(params_str) - strlen(params_str) - 1);
          if (p->next) strncat(params_str, ", ", sizeof(params_str) - strlen(params_str) - 1);
          p = p->next;
      }

      printf("│ %5d │ %-22s │ %-12s │ %-60s │\n",
             current_index,
             current->name,
             typeToString(current->return_type),
             params_str);

      current = current->next;
      current_index++;
  }

  printf("└───────┴────────────────────────┴──────────────┴──────────────────────────────────────────────────────────────┘\n");
  printf("Total exports: %d\n\n", current_index);
}



void ETfree(export_table_st *table) {
    export_entry_st *current = table->entries;
    while (current) {
        export_entry_st *next = current->next;
        free(current->name);

        param_entry_st *p = current->params;
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