#pragma once
#include "ccngen/enum.h"
#include <stdbool.h>
#include "user/symbolTable/symbol_table.h"

typedef struct global_var_entry global_var_entry_st;
typedef struct global_extern_var_entry global_extern_var_entry_st;
typedef struct var_table global_var_table_st;

struct global_var_entry {
  char *name;
  enum Type type;
  int index;
  bool is_exported;
  global_var_entry_st *next;
};

struct global_extern_var_entry
{
  char *name;
  enum Type type;
  int index;
  global_extern_var_entry_st *next;
};

struct var_table {
  global_var_entry_st *globals;
  global_extern_var_entry_st *externs;
  size_t global_size;
  size_t extern_size;
};

global_var_table_st *VTnew();
void VTfree(global_var_table_st *table);
int VTadd(global_var_table_st *table, const char *name, enum Type type, bool is_exported);
int VTaddExtern(global_var_table_st *table, const char *name, enum Type type);
global_var_entry_st *VTget(global_var_table_st *table, int index);
global_extern_var_entry_st *VTgetExtern(global_var_table_st *table, int index);
void VTprint(global_var_table_st *table);
