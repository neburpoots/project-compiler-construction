#pragma once

#include <stdbool.h>
#include <stdlib.h>

typedef struct stable stable_st;
typedef struct var_entry var_entry_st;
typedef struct func_entry func_entry_st;

stable_st *STnew(stable_st *parent);