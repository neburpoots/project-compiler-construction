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

int ETadd(export_table_st *table, const char *name, const char *label, enum Type return_type, param_entry_st *params) {
    export_entry_st *current = table->entries;
    for (int i = 0; current != NULL; current = current->next, i++) {
        if (strcmp(current->name, name) == 0 &&
            current->return_type == return_type) {
            return i;
        }
    }

    // Create new entry with label
    export_entry_st *new_entry = malloc(sizeof(export_entry_st));
    new_entry->name = strdup(name);
    new_entry->label = strdup(label);  // Store label
    new_entry->return_type = return_type;
    new_entry->params = params;
    new_entry->next = table->entries;
    table->entries = new_entry;
    return table->size++;
}

// ... (ETget remains the same)

void ETprint(export_table_st *table) {
  if (!table || !table->entries) {
      printf("Export table is empty\n");
      return;
  }

  printf("\nExport Table Contents:\n");
  printf("┌───────┬────────────────────────┬────────────────────────┬──────────────┬──────────────────────────────────────────────────────────────┐\n");
  printf("│ Index │ Function               │ Label                  │ Return Type  │ Parameters                                                   │\n");
  printf("├───────┼────────────────────────┼────────────────────────┼──────────────┼──────────────────────────────────────────────────────────────┤\n");

  export_entry_st *current = table->entries;
  int current_index = 0;

  while (current) {
      char params_str[512] = "";
      param_entry_st *p = current->params;

      while (p) {
          strncat(params_str, typeToString(p->type), sizeof(params_str) - strlen(params_str) - 1);
          strncat(params_str, " ", sizeof(params_str) - strlen(params_str) - 1);
          strncat(params_str, p->name, sizeof(params_str) - strlen(params_str) - 1);
          if (p->next) strncat(params_str, ", ", sizeof(params_str) - strlen(params_str) - 1);
          p = p->next;
      }

      printf("│ %5d │ %-22s │ %-22s │ %-12s │ %-60s │\n",
             current_index,
             current->name,
             current->label,  // Added label column
             typeToString(current->return_type),
             params_str);

      current = current->next;
      current_index++;
  }

  printf("└───────┴────────────────────────┴────────────────────────┴──────────────┴──────────────────────────────────────────────────────────────┘\n");
  printf("Total exports: %d\n\n", current_index);
}

void ETfree(export_table_st *table) {
    export_entry_st *current = table->entries;
    while (current) {
        export_entry_st *next = current->next;
        free(current->name);
        free(current->label);  // Free label memory
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