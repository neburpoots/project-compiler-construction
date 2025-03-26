// import_table.h
#pragma once
#include "ccngen/enum.h"
#include "user/symbolTable/symbol_table.h"

typedef struct import_entry import_entry_st;
typedef struct import_table import_table_st;

struct import_entry {
    char *func_name;
    enum Type return_type;
    param_entry_st *parameters;
    import_entry_st *next;
};

struct import_table {
    import_entry_st *entries;
    size_t size;
    size_t capacity;
};

import_table_st *ITnew();
void ITfree(import_table_st *table);
int ITaddFunction(import_table_st *table, const char *name, enum Type return_type, param_entry_st *params);
import_entry_st *ITget(import_table_st *table, int index);
void ITprint(import_table_st *table);