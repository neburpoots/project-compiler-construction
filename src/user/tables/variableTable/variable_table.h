#pragma once
#include "ccngen/enum.h"
#include <stdbool.h>
#include "user/symbolTable/symbol_table.h"

typedef struct global_var_entry global_var_entry_st;
typedef struct var_table var_table_st;

struct global_var_entry {
    char *name;
    enum Type type;
    int index;
    bool is_exported;
    global_var_entry_st *next;
};

struct var_table {
    global_var_entry_st *entries;
    size_t size;
    size_t capacity;
};

var_table_st *GTnew();
void GTfree(var_table_st *table);
int GTadd(var_table_st *table, const char *name, enum Type type, bool is_exported);
global_var_entry_st *GTget(var_table_st *table, int index);
void GTprint(var_table_st *table);