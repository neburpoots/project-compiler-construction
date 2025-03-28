#pragma once

#include <stdbool.h>
#include <stdlib.h>
#include "ccngen/enum.h"

typedef enum {
    CONST_INT,
    CONST_FLOAT,
    CONST_BOOL
} ConstType;

struct const_entry {
    ConstType type;
    union {
        int int_val;
        float float_val;
        bool bool_val;
    } value;
    int index;
    struct const_entry *next;
};

typedef struct const_entry const_entry_st;
typedef struct const_table const_table_st;

const_table_st *CTnew();
int CTadd(const_table_st *table, ConstType type, void *value);
const_entry_st *CTget(const_table_st *table, int index);
void CTfree(const_table_st *table);
void CTprint(const_table_st *table);
const char *ConstTypeToString(ConstType type);