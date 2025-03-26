#include "user/tables/exportTable/export_table.h"
#include <stdlib.h>
#include <string.h>
#include "user/symbolTable/symbol_table.h"
#include <stdio.h>

//create new export table
export_table_st *ETnew() {
    export_table_st *table = malloc(sizeof(export_table_st));
    table->entries = NULL;
    table->size = 0;
    return table;
}

//add entry to the export table
void ETadd(export_table_st *table, const char *name, enum Type return_type, param_entry_st *params) {
    export_entry_st *entry = malloc(sizeof(export_entry_st));
    entry->name = strdup(name);
    entry->return_type = return_type;
    entry->params = params;
    entry->next = table->entries;
    table->entries = entry;
    table->size++;
}

//print from chatGPT
void ETprint(export_table_st *table) {
  printf("Export Table (%zu entries):\n", table->size);
  printf("┌───────────────────────────┬────────────┬────────────────────────────────────────┐\n");
  printf("│ Function                  │ Return     │ Parameters                             │\n");
  printf("├───────────────────────────┼────────────┼────────────────────────────────────────┤\n");

  for (export_entry_st *e = table->entries; e; e = e->next) {
      char param_str[40 + 1] = "";
      int len = 0;

      param_entry_st *p = e->params;
      while (p) {
          int needed = snprintf(param_str + len, 40 - len, "%s%s %s",
                                len ? ", " : "", typeToString(p->type), p->name);
          if (len + needed >= 40) {
              strcpy(param_str + 40 - 4, "...");
              break;
          }
          len += needed;
          p = p->next;
      }

      printf("│ %-25s │ %-10s │ %-38s │\n", e->name, typeToString(e->return_type), param_str);
  }

  printf("└───────────────────────────┴────────────┴────────────────────────────────────────┘\n");
}

//free export table
void ETfree(export_table_st *table) {
    export_entry_st *e = table->entries;
    while (e) {
        export_entry_st *next = e->next;
        free(e->name);
        free(e);
        e = next;
    }
    free(table);
}