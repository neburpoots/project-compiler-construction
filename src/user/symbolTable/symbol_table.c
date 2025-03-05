#include "symbol_table.h"
#include <stdlib.h>
#include <string.h>

//var enties
struct var_entry {
  char *name;
  struct var_entry *next;
};

//func entries
struct func_entry {
  char *name;
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