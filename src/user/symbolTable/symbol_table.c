#include "symbol_table.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ccngen/enum.h"

static bool compareParamLists(param_entry_st *a, param_entry_st *b);
static struct param_entry *copyParamList(param_entry_st *src);

// symbol table holding the vars and funcs

// create new symbol table
stable_st *STnew(stable_st *parent) {
  stable_st *table = malloc(sizeof(stable_st));
  if (table == NULL) {
    return NULL;
  }

  table->var_entries = NULL;
  table->func_entries = NULL;
  table->parent = parent;
  return table;
}

// insert array variable into the symbol table
var_entry_st *STinsertArrayVar(stable_st *table,
                               const char *name,
                               enum Type type,
                               void *dimensions) {
  if (!table || !name) {
    return NULL;
  }

  // check if var already exists in local scope symbol table
  if (STlookupVar(table, name, false)) {
    return NULL;
  }

  var_entry_st *entry = malloc(sizeof(var_entry_st));
  if (!entry) {
    return NULL;
  }

  entry->name = strdup(name);
  entry->type = type;
  entry->dimensions = dimensions;
  entry->next = table->var_entries;
  table->var_entries = entry;

  return entry;
}

// insert a variable into the symbol table
var_entry_st *STinsertVar(stable_st *table, const char *name, enum Type type) {
  if (!table || !name) {
    return NULL;
  }

  // check if var already exists in local scope symbol table
  if (STlookupVar(table, name, false)) {
    return NULL;
  }

  var_entry_st *entry = malloc(sizeof(var_entry_st));
  if (!entry) {
    return NULL;
  }

  entry->name = strdup(name);
  entry->type = type;
  entry->dimensions = NULL;
  entry->next = table->var_entries;
  table->var_entries = entry;

  return entry;
}

// insert a function into the symbol table
func_entry_st *STinsertFunc(stable_st *table,
                            const char *name,
                            enum Type returnType,
                            param_entry_st *params) {
  if (!table || !name) {
      // free entire params list if present
    param_entry_st *current_param = params;
    while (current_param) {
      param_entry_st *temp = current_param;
      current_param = current_param->next;
      free(temp->name);
      free(temp);
    }
    return NULL;
  }

  // check for duplicate function signature in current scope. using the return type,
  // name and param types
  func_entry_st *current = table->func_entries;
  while (current) {
    if (strcmp(current->name, name) == 0 && current->returnType == returnType
        && compareParamLists(current->params, params)) {
          // free entire params list before returning
      param_entry_st *current_param = params;
      while (current_param) {
        param_entry_st *temp = current_param;
        current_param = current_param->next;
        free(temp->name);
        free(temp);
      }

          // duplicate found
      return NULL;
    }
    current = current->next;
  }

  func_entry_st *entry = malloc(sizeof(func_entry_st));
  if (!entry) {
      // free entire params list
    param_entry_st *current_param = params;
    while (current_param) {
      param_entry_st *temp = current_param;
      current_param = current_param->next;
      free(temp->name);
      free(temp);
    }
    return NULL;
  }

  entry->name = strdup(name);
  if (!entry->name) {
    free(entry);
    param_entry_st *current_param = params;
    while (current_param) {
      param_entry_st *temp = current_param;
      current_param = current_param->next;
      free(temp);
    }
    return NULL;
  }

  entry->returnType = returnType;
  entry->params = copyParamList(params);
  entry->next = table->func_entries;
  table->func_entries = entry;

  param_entry_st *current_param = params;
  while (current_param) {
    param_entry_st *temp = current_param;
    current_param = current_param->next;
    free(temp->name);
    free(temp);
  }

  return entry;
}

stable_st *STgetParentTable(stable_st *current_table) {
  if (current_table == NULL) {
    return NULL;
  }
  return current_table->parent;
}

// lookup var in symbol table or linked parents
var_entry_st *STlookupVar(stable_st *table, const char *name, bool traverse_parent) {
  // setting the current scope/symbol table
  stable_st *current = table;

  // loop over the current set symbol table
  while (current) {
      // gett the vars from the current set symbol table
    var_entry_st *entry = current->var_entries;

      // looping over the entries of the set vars
    while (entry) {
          // check if the names matches, meaning var found so we return it
      if (strcmp(entry->name, name) == 0) {
        return entry;
      }
          // setting the next entry to check
      entry = entry->next;
    }

    if (traverse_parent) {
      // not found in the current scope, needed to check for static accessible vars.
      // Should not be possible that we access random vars in the scope above.
      current = current->parent;
    } else {
      current = NULL;
    }
  }

  // not founb
  return NULL;
}

// lookup func in symbol table or linked parents(practically the same as above)
func_entry_st *STlookupFunc(stable_st *table, const char *name) {
  stable_st *current = table;
  while (current) {
    func_entry_st *entry = current->func_entries;
    while (entry) {
      if (strcmp(entry->name, name) == 0) {
        return entry;
      }
      entry = entry->next;
    }
    current = current->parent;
  }
  return NULL;
}

const char *typeToString(enum Type t) {
  switch (t) {
  case CT_NULL:
    return "NULL";
  case CT_int:
    return "int";
  case CT_float:
    return "float";
  case CT_bool:
    return "bool";
  case CT_void:
    return "void";
  case CT_array:
    return "array";
  default:
    return "UNKNOWN_TYPE";
  }
}

void printSymbolTableContent(stable_st *table, bool printParent) {
  if (!table) {
    printf("Symbol table is NULL.\n");
    return;
  }

  printf("\nSymbol Table Contents:\n");

  if (table->var_entries) {
    printf("Variables:\n");
    var_entry_st *var_entry = table->var_entries;
    while (var_entry) {
      if (var_entry->dimensions) {
        printf("  %s (%s) - Array\n", var_entry->name, typeToString(var_entry->type));
      } else {
        printf("  %s (%s)\n", var_entry->name, typeToString(var_entry->type));
      }
      var_entry = var_entry->next;
    }
  } else {
    printf("No variables in this table.\n");
  }

  if (table->func_entries) {
    printf("Functions:\n");
    func_entry_st *func_entry = table->func_entries;
    while (func_entry) {
      printf("  %s %s (", typeToString(func_entry->returnType), func_entry->name);

      param_entry_st *current_param_entry = func_entry->params;
      bool first_param = true;
      while (current_param_entry) {
        if (!first_param) {
          printf(", ");
        }
        printf("%s of type %s",
               current_param_entry->name,
               typeToString(current_param_entry->type));
        first_param = false;
        current_param_entry = current_param_entry->next;
      }
      printf(")\n");
      func_entry = func_entry->next;
    }
  } else {
    printf("No functions in this table.\n");
  }

  if (!printParent) {
    return;
  }

  if (table->parent) {
    printf("\nParent Symbol Table:\n");
    printSymbolTableContent(table->parent, true);
  }
}

// free symbol table and all its entries
void STfree(stable_st *table) {
  if (!table) {
    return;
  }

  // vars
  var_entry_st *v_entry = table->var_entries;
  while (v_entry) {
    var_entry_st *temp = v_entry;
    v_entry = v_entry->next;
    free(temp->name);
    free(temp);
  }

  // funcs
  func_entry_st *f_entry = table->func_entries;
  while (f_entry) {
    // clear params
    param_entry_st *p_entry = f_entry->params;
    while (p_entry) {
      param_entry_st *temp = p_entry;
      p_entry = p_entry->next;
      free(temp->name);
      free(temp);
    }
    f_entry->params = NULL;

    func_entry_st *temp = f_entry;
    f_entry = f_entry->next;
    free(temp->name);
    free(temp);
  }

  // table
  free(table);
}

// helpers
static bool compareParamLists(param_entry_st *a, param_entry_st *b) {
  while (a && b) {
    if (a->type != b->type) {
      return false;
    }
    a = a->next;
    b = b->next;
  }
  return (a == NULL && b == NULL);
}

static struct param_entry *copyParamList(param_entry_st *src) {
  if (!src) {
    return NULL;
  }

  param_entry_st *dst = malloc(sizeof(param_entry_st));
  param_entry_st *current_dst = dst;
  param_entry_st *current_src = src;

  while (current_src) {
    current_dst->name = strdup(current_src->name);
    current_dst->type = current_src->type;

    if (current_src->next) {
      current_dst->next = malloc(sizeof(param_entry_st));
      current_dst = current_dst->next;
    } else {
      current_dst->next = NULL;
    }

    current_src = current_src->next;
  }

  return dst;
}
