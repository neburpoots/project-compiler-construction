#pragma once

#include <stdbool.h>
#include <stdlib.h>
#include "user/symbolTable/symbol_table.h"

typedef struct stack stack_st;

stack_st *Stacknew(size_t capacity);
void Stackpush(stack_st *stack, stable_st *table);
stable_st *Stackpop(stack_st *stack);
bool StackisEmpty(stack_st *stack);
void Stackfree(stack_st *stack);
stable_st *StackPeek(stack_st *stack);