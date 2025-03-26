#include "user/tables/constTable/const_table.h"
#include <assert.h>
#include <stdio.h>

//struct for the constant table
struct const_table {
    const_entry_st *entries;
    size_t size;
    size_t capacity;
};

//create a new constant table
const_table_st *CTnew() {
    const_table_st *table = malloc(sizeof(const_table_st));
    table->entries = NULL;
    table->size = 0;
    table->capacity = 0;
    return table;
}

//add a constant (returns index if already exists)
int CTadd(const_table_st *table, ConstType type, void *value) {
    // Check for duplicates (optional: skip if not needed)
    const_entry_st *current = table->entries;
    for (int i = 0; current != NULL; current = current->next, i++) {
        if (current->type == type) {
            switch (type) {
                case CONST_INT:
                    if (current->value.int_val == *(int*)value) return i;
                    break;
                case CONST_FLOAT:
                    if (current->value.float_val == *(float*)value) return i;
                    break;
                case CONST_BOOL:
                    if (current->value.bool_val == *(bool*)value) return i;
                    break;
            }
        }
    }

    //craete new enty
    const_entry_st *new_entry = malloc(sizeof(const_entry_st));
    new_entry->type = type;
    switch (type) {
        case CONST_INT: new_entry->value.int_val = *(int*)value; break;
        case CONST_FLOAT: new_entry->value.float_val = *(float*)value; break;
        case CONST_BOOL: new_entry->value.bool_val = *(bool*)value; break;
    }
    new_entry->next = table->entries;
    table->entries = new_entry;
    return table->size++;
}

//get by index
const_entry_st *CTget(const_table_st *table, int index) {
    const_entry_st *current = table->entries;
    for (int i = 0; current != NULL && i < index; current = current->next, i++);
    return current;
}

//print table
void CTprint(const_table_st *table) {
  if (table == NULL || table->entries == NULL) {
      printf("Constant table is empty\n");
      return;
  }

  printf("\nConstant Table Contents:\n");
  printf("┌───────┬──────────┬───────────────┐\n");
  printf("│ Index │   Type   │     Value     │\n");
  printf("├───────┼──────────┼───────────────┤\n");

  const_entry_st *current = table->entries;
  int current_index = 0;

  while (current != NULL) {
      printf("│ %5d │ %-8s │ ", current_index,
             ConstTypeToString(current->type));

      switch (current->type) {
          case CONST_INT:
              printf("%-13d │\n", current->value.int_val);
              break;
          case CONST_FLOAT:
              printf("%-13.4f │\n", current->value.float_val);
              break;
          case CONST_BOOL:
              printf("%-13s │\n", current->value.bool_val ? "true" : "false");
              break;
          default:
              printf("%-13s │\n", "invalid");
              break;
      }

      current = current->next;
      current_index++;
  }

  printf("└───────┴──────────┴───────────────┘\n");
  printf("Total constants: %d\n\n", current_index);
}

//convert the entry type to string
const char *ConstTypeToString(ConstType type) {
  switch (type) {
      case CONST_INT:   return "INT";
      case CONST_FLOAT: return "FLOAT";
      case CONST_BOOL:  return "BOOL";
      default:         return "UNKNOWN";
  }
}

//free table and entries
void CTfree(const_table_st *table) {
    const_entry_st *current = table->entries;
    while (current != NULL) {
        const_entry_st *next = current->next;
        free(current);
        current = next;
    }
    free(table);
}