#include "symbol_table.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "ccngen/enum.h"

//var enties
struct var_entry {
  char *name;
  enum Type type;
  struct var_entry *next;
};

//func entries
struct func_entry {
  char *name;
  enum Type returnType;
  struct func_entry *next;
};

//symbol table holding the vars and funcs
struct stable {
  var_entry_st *var_entries;
  func_entry_st *func_entries;
  struct stable *parent;
};

//create new symbol table
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

//insert a variable into the symbol table
var_entry_st *STinsertVar(stable_st *table, const char *name, enum Type type) {
  if (!table || !name) return NULL;

  var_entry_st *entry = malloc(sizeof(var_entry_st));
  if (!entry) return NULL;

  entry->name = strdup(name);
  entry->type = type;
  entry->next = table->var_entries;
  table->var_entries = entry;

  return entry;
}

//insert a function into the symbol table
func_entry_st *STinsertFunc(stable_st *table, const char *name, enum Type returnType) {
  if (!table || !name) return NULL;

  func_entry_st *entry = malloc(sizeof(func_entry_st));
  if (!entry) return NULL;

  entry->name = strdup(name);
  entry->returnType = returnType;
  entry->next = table->func_entries;
  table->func_entries = entry;

  return entry;
}

//lookup var in symbol table or linked parents
var_entry_st *STlookupVar(stable_st *table, const char *name) {

  //setting the current scope/symbol table 
  stable_st *current = table;

  //loop over the current set symbol table
  while (current) {

      //gett the vars from the current set symbol table
      var_entry_st *entry = current->var_entries;

      //looping over the entries of the set vars
      while (entry) {

          //check if the names matches, meaning var found so we return it
          if (strcmp(entry->name, name) == 0) {
              return entry;
          }
          //setting the next entry to check
          entry = entry->next;
      }

      //not found in the current scope, needed to check for static accessible vars. Should not be possible that we access random vars in the scope above.
      current = current->parent;
  }

  //not founb
  return NULL;
}

//lookup func in symbol table or linked parents(practically the same as above)
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
        case CT_NULL:  return "NULL";
        case CT_int:   return "int";
        case CT_float: return "float";
        case CT_bool:  return "bool";
        case CT_void:  return "void";
        case CT_array: return "array";
        default:       return "UNKNOWN_TYPE";
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
          printf("  %s (%s)\n", var_entry->name, typeToString(var_entry->type));
          var_entry = var_entry->next;
      }
  } else {
      printf("No variables in this table.\n");
  }

  if (table->func_entries) {
      printf("Functions:\n");
      func_entry_st *func_entry = table->func_entries;
      while (func_entry) {
          printf("  %s (%s)\n", func_entry->name, typeToString(func_entry->returnType));
          func_entry = func_entry->next;
      }
  } else {
      printf("No functions in this table.\n");
  }

  if (!printParent)
  {
    return;
  }
  
  if (table->parent) {
      printf("\nParent Symbol Table:\n");
      printSymbolTableContent(table->parent, true);
  }
}

//free symbol table and all its entries
void STfree(stable_st *table) {
  if (!table) return;

  //vars
  var_entry_st *v_entry = table->var_entries;
  while (v_entry) {
      var_entry_st *temp = v_entry;
      v_entry = v_entry->next;
      free(temp->name);
      free(temp);
  }

  //funcs
  func_entry_st *f_entry = table->func_entries;
  while (f_entry) {
      func_entry_st *temp = f_entry;
      f_entry = f_entry->next;
      free(temp->name);
      free(temp);
  }

  //table
  free(table);
}
