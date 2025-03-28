// export_table.c
#include "user/tables/exportTable/export_table.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

export_table_st *ETnew() {
  export_table_st *table = malloc(sizeof(export_table_st));
  table->entries = NULL;
  table->size = 0;
  return table;
}

int ETaddFunction(export_table_st *table,
                  const char *name,
                  const char *label,
                  enum Type return_type,
                  param_entry_st *params) {
  export_entry_st *current = table->entries;
  for (int i = 0; current != NULL; current = current->next, i++) {
    if (current->entry_type == EXPORT_FUNCTION && strcmp(current->name, name) == 0
        && current->data.func.return_type == return_type) {
      return i;
    }
  }

  export_entry_st *new_entry = malloc(sizeof(export_entry_st));
  new_entry->entry_type = EXPORT_FUNCTION;
  new_entry->name = strdup(name);
  new_entry->label = strdup(label);
  new_entry->data.func.return_type = return_type;
  new_entry->data.func.params = params;
  new_entry->next = table->entries;
  table->entries = new_entry;
  return table->size++;
}

int ETaddVariable(export_table_st *table, const char *name, enum Type var_type) {
  export_entry_st *current = table->entries;
  for (int i = 0; current != NULL; current = current->next, i++) {
    if (current->entry_type == EXPORT_VARIABLE && strcmp(current->name, name) == 0
        && current->data.var.var_type == var_type) {
      return i;
    }
  }

  export_entry_st *new_entry = malloc(sizeof(export_entry_st));
  new_entry->entry_type = EXPORT_VARIABLE;
  new_entry->name = strdup(name);
  new_entry->label = NULL;
  new_entry->data.var.var_type = var_type;
  new_entry->next = table->entries;
  table->entries = new_entry;
  return table->size++;
}

void ETprint(export_table_st *table) {
  printf("┌───────┬──────────┬────────────────────────┬──────────────┬─────────────────"
         "──────┐\n");
  printf("│ Index │   Type   │ Name                   │ Data         │ "
         "Parameters/Label      │\n");
  printf("├───────┼──────────┼────────────────────────┼──────────────┼─────────────────"
         "──────┤\n");

  export_entry_st *current = table->entries;
  for (int i = 0; current != NULL; current = current->next, i++) {
    if (current->entry_type == EXPORT_FUNCTION) {
      char params[128] = "";
      param_entry_st *p = current->data.func.params;
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

void ETfree(export_table_st *table) {
  export_entry_st *current = table->entries;
  while (current) {
    export_entry_st *next = current->next;
    free(current->name);
    free(current->label);
    if (current->entry_type == EXPORT_FUNCTION) {
      param_entry_st *p = current->data.func.params;
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
