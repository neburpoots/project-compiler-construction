#pragma once
#include "ccngen/enum.h"
#include "user/symbolTable/symbol_table.h"


typedef struct export_entry export_entry_st;
typedef struct export_table export_table_st;

struct export_entry {
    char *name;
    enum Type return_type;
    param_entry_st *params;
    export_entry_st *next;
};

struct export_table {
    export_entry_st *entries;
    size_t size;
};

export_table_st *ETnew();
void ETfree(export_table_st *table);
void ETadd(export_table_st *table, const char *name, enum Type return_type, param_entry_st *params);
void ETprint(export_table_st *table);