// export_table.h
#pragma once
#include "ccngen/enum.h"
#include "user/symbolTable/symbol_table.h"

typedef enum {
  EXPORT_FUNCTION,
  EXPORT_VARIABLE
} ExportEntryType;

typedef struct export_entry export_entry_st;
typedef struct export_table export_table_st;

struct export_entry {
  ExportEntryType entry_type;
  char *name;
  char *label;

  union {
    // functions
    struct {
      enum Type return_type;
      param_entry_st *params;
    } func;

    // vars
    struct {
      enum Type var_type;
    } var;
  } data;

  export_entry_st *next;
};

struct export_table {
  export_entry_st *entries;
  size_t size;
};

export_table_st *ETnew();
void ETfree(export_table_st *table);
int ETaddFunction(export_table_st *table,
                  const char *name,
                  const char *label,
                  enum Type return_type,
                  param_entry_st *params);
int ETaddVariable(export_table_st *table, const char *name, enum Type var_type);
export_entry_st *ETget(export_table_st *table, int index);
void ETprint(export_table_st *table);
