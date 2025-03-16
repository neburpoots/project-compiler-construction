#include "stack.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

struct stack {
  size_t capacity;  
  size_t top;     
  stable_st **data;
};

//create new stack
stack_st *Stacknew(size_t capacity) {
  stack_st *stack = malloc(sizeof(stack_st));
  if (stack == NULL) {
      return NULL;
  }
  stack->capacity = capacity;
  stack->top = 0;
  stack->data = malloc(capacity * sizeof(stable_st *));
  if (stack->data == NULL) {
      free(stack);
      return NULL;
  }
  return stack;
}

//push a symbol table onto the stack
void Stackpush(stack_st *stack, stable_st *table) {
  if (stack->top >= stack->capacity) {
      printf("Stack overflow: Unable to push symbol table.\n");
      return;
  }
  stack->data[stack->top++] = table;
}

//pop a symbol table from the stack
stable_st *Stackpop(stack_st *stack) {
  if (stack->top == 0) {
    printf("Stack underflow: No symbol table to pop.\n");
      return NULL;
  }
  return stack->data[--stack->top];
}

//check if the stack is empty
bool StackisEmpty(stack_st *stack) {
  return stack->top == 0;
}

stable_st *StackPeek(stack_st *stack) {
  if (stack->top == 0) {
      return NULL;
  }
  return stack->data[stack->top - 1];
}

//free the stack memory
void Stackfree(stack_st *stack, bool clean_entries) {
  if (stack) {
      if (clean_entries)
      {
        for (size_t i = 0; i < stack->top; i++) {
          stable_st *table = (stable_st *)stack->data[i];
          STfree(table);
        }
      }
      free(stack->data);
      free(stack);
  }
}
