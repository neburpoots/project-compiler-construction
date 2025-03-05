#include "symbol_table.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

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

//insert a variable into the symbol table
var_entry_st *STinsertVar(stable_st *table, const char *name) {
  if (!table || !name) return NULL;

  var_entry_st *entry = malloc(sizeof(var_entry_st));
  if (!entry) return NULL;

  entry->name = strdup(name);
  entry->next = table->var_entries;
  table->var_entries = entry;

  return entry;
}

//insert a function into the symbol table
func_entry_st *STinsertFunc(stable_st *table, const char *name) {
  if (!table || !name) return NULL;

  func_entry_st *entry = malloc(sizeof(func_entry_st));
  if (!entry) return NULL;

  entry->name = strdup(name);
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
