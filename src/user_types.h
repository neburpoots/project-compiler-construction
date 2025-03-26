#pragma once

#include "palm/hash_table.h"
#include "user/symbolTable/symbol_table.h"
#include "user/stack/stack.h"
#include "user/genericstack/generic_stack.h"
#include "user/tables/constTable/const_table.h"

typedef htable_st* htable_stptr;

// Add more types here if necessary
typedef stable_st* stable_stptr;
typedef stack_st* stack_stptr;

typedef generic_stack_st* generic_stack_stptr;
typedef const_table_st* ctable_stprt;