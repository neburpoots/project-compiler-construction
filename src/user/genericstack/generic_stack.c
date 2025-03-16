#include "generic_stack.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

struct generic_stack
{
    size_t capacity;
    size_t top;
    void **data;
};

generic_stack_st *GStackNew(size_t capacity)
{
    generic_stack_st *stack = malloc(sizeof(generic_stack_st));
    if (!stack)
        return NULL;

    stack->capacity = capacity;
    stack->top = 0;
    stack->data = malloc(capacity * sizeof(void *));
    if (!stack->data)
    {
        free(stack);
        return NULL;
    }
    return stack;
}

void GStackPush(generic_stack_st *stack, void *element)
{
    if (stack->top >= stack->capacity)
    {
        printf("Stack overflow: Unable to push element.\n");
        return;
    }
    stack->data[stack->top++] = element;
}

void *GStackPop(generic_stack_st *stack)
{
    if (stack->top == 0)
    {
        printf("Stack underflow: No element to pop.\n");
        return NULL;
    }
    return stack->data[--stack->top];
}

void *GStackPeek(generic_stack_st *stack)
{
    if (stack->top == 0)
    {
        return NULL;
    }
    return stack->data[stack->top - 1];
}

bool GStackIsEmpty(generic_stack_st *stack)
{
    return stack->top == 0;
}

void GStackFree(generic_stack_st *stack, void (*free_func)(void *))
{
    if (stack)
    {
        if (free_func)
        {
            for (size_t i = 0; i < stack->top; i++)
            {
                free_func(stack->data[i]); // Free each element if function provided
            }
        }
        free(stack->data);
        free(stack);
    }
}

void *GStackPopTail(generic_stack_st *stack)
{
    if (stack->top == 0)
    {
        printf("Stack underflow: No element to pop.\n");
        return NULL;
    }
    void *element = stack->data[stack->top - 1];
    stack->top--;  // Actually remove the element from the stack
    return element;
}