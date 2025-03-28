#pragma once

#include <stdbool.h>
#include <stdlib.h>

#include "ccngen/enum.h"

struct param_entry {
  char *name;
  enum Type type;
  struct param_entry *next;
};

typedef struct param_entry param_entry_st;

// var enties
struct var_entry {
  char *name;
  enum Type type;
  void *dimensions;
  char **dimension_names;
  int num_dimensions;
  struct var_entry *next;
};
typedef struct var_entry var_entry_st;

struct func_entry {
  char *name;
  enum Type returnType;
  struct param_entry *params;
  struct func_entry *next;
};
typedef struct func_entry func_entry_st;

struct stable {
  var_entry_st *var_entries;
  func_entry_st *func_entries;
  struct stable *parent;
};
typedef struct stable stable_st;

// create new table
stable_st *STnew(stable_st *parent);

// insert a var into the symbol table linked list
var_entry_st *STinsertVar(stable_st *table, const char *name, const enum Type);

// insert an array var into the symbol table linked list
var_entry_st *STinsertArrayVar(stable_st *table,
                               const char *name,
                               const enum Type type,
                               void *dimensions);

// insert a func into the symbol table linked list
func_entry_st *STinsertFunc(stable_st *table,
                            const char *name,
                            enum Type returnType,
                            param_entry_st *params);

// lookup a var in the symbol table
var_entry_st *STlookupVar(stable_st *table, const char *name, bool traverse_parent);

// Get parent of current symbol table
stable_st *STgetParentTable(stable_st *current_table);

// lookup a func in the symbol table
func_entry_st *STlookupFunc(stable_st *table, const char *name);

// test log function
void printSymbolTableContent(stable_st *table, bool printParent);

// convert enum type to string
const char *typeToString(enum Type type);

// free the symbol table vars and fucns
void STfree(stable_st *table);
