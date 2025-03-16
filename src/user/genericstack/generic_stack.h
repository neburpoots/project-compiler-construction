#pragma once

#include <stdlib.h>
#include <stdbool.h>

typedef struct generic_stack generic_stack_st;

// Create a new generic stack
generic_stack_st *GStackNew(size_t capacity);

// Push an element onto the stack
void GStackPush(generic_stack_st *stack, void *element);

// Pop an element from the stack
void *GStackPop(generic_stack_st *stack);

// Peek at the top element without popping it
void *GStackPeek(generic_stack_st *stack);

// Check if the stack is empty
bool GStackIsEmpty(generic_stack_st *stack);

// Free the stack and optionally free its elements
void GStackFree(generic_stack_st *stack, void (*free_func)(void *));

//Pop tail
void *GStackPopTail(generic_stack_st *stack);