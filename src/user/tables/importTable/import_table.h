// import_table.h
#pragma once
#include "ccngen/enum.h"
#include "user/symbolTable/symbol_table.h"

typedef enum {
  FUNCTION_ENTRY,
  VARIABLE_ENTRY
} ImportEntryType;

typedef struct import_entry import_entry_st;
typedef struct import_table import_table_st;

struct import_entry {
  ImportEntryType entry_type;
  char *name;

  union {
    // functions
    struct {
      enum Type return_type;
      param_entry_st *parameters;
    } func;

    // variables
    struct {
      enum Type var_type;
    } var;
  } data;

  import_entry_st *next;
};

struct import_table {
  import_entry_st *entries;
  size_t size;
};

import_table_st *ITnew();
void ITfree(import_table_st *table);
int ITaddFunction(import_table_st *table,
                  const char *name,
                  enum Type return_type,
                  param_entry_st *params);
int ITaddVariable(import_table_st *table, const char *name, enum Type var_type);
import_entry_st *ITget(import_table_st *table, int index);
void ITprint(import_table_st *table);
