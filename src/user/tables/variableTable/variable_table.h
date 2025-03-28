#pragma once
#include <stdbool.h>
#include <stdio.h>

#include "ccngen/enum.h"

typedef struct glob_var_entry glob_var_entry_st;
typedef struct glob_var_table glob_var_table_st;

struct glob_var_entry {
  char *name;
  enum Type type;
  int index;
  bool is_initialized;
  glob_var_entry_st *next;
};

struct glob_var_table {
  glob_var_entry_st *entries;
  size_t size;
};

glob_var_table_st *VTnew();
void VTfree(glob_var_table_st *table);
int VTadd(glob_var_table_st *table,
          const char *name,
          enum Type type,
          bool is_initialized);
glob_var_entry_st *VTget(glob_var_table_st *table, int index);
void VTprint(glob_var_table_st *table);
