// global_table.c
#include "user/tables/variableTable/variable_table.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

var_table_st *GTnew() {
    var_table_st *table = malloc(sizeof(var_table_st));
    table->entries = NULL;
    table->size = 0;
    table->capacity = 0;
    return table;
}

int GTadd(var_table_st *table, const char *name, enum Type type, bool is_exported) {
    global_var_entry_st *current = table->entries;
    for (int i = 0; current != NULL; current = current->next, i++) {
        if (strcmp(current->name, name) == 0) {
            return i;
        }
    }

    global_var_entry_st *new_entry = malloc(sizeof(global_var_entry_st));
    new_entry->name = strdup(name);
    new_entry->type = type;
    new_entry->index = table->size;
    new_entry->is_exported = is_exported;
    new_entry->next = table->entries;

    table->entries = new_entry;
    return table->size++;
}

global_var_entry_st *GTget(var_table_st *table, int index) {
    global_var_entry_st *current = table->entries;
    for (int i = 0; current != NULL; current = current->next, i++) {
        if (i == index) return current;
    }
    return NULL;
}

void GTprint(var_table_st *table) {
    if (!table || !table->entries) {
        printf("Global variable table is empty\n");
        return;
    }

    printf("\nGlobal Variable Table Contents:\n");
    printf("┌───────┬────────────────────────┬────────────────────────┬──────────────┐\n");
    printf("│ Index │ Name                   │ Type                   │ Exported     │\n");
    printf("├───────┼────────────────────────┼────────────────────────┼──────────────┤\n");

    global_var_entry_st *current = table->entries;
    int current_index = 0;

    while (current) {
        printf("│ %5d │ %-22s │ %-22s │ %-12s │\n",
               current->index,
               current->name,
               typeToString(current->type),
               current->is_exported ? "Yes" : "No");

        current = current->next;
        current_index++;
    }

    printf("└───────┴────────────────────────┴────────────────────────┴──────────────┘\n");
    printf("Total globals: %d\n\n", current_index);
}

void GTfree(var_table_st *table) {
    global_var_entry_st *current = table->entries;
    while (current) {
        global_var_entry_st *next = current->next;
        free(current->name);
        free(current);
        current = next;
    }
    free(table);
}