#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct Stack {
    int    *data;
    size_t top;
    size_t size;
}Stack;

int is_full(Stack *stack)
{
    return stack->top >= stack->size;
}

int is_empty(Stack *stack)
{
    return (stack->top == 0);
}

int s_push(Stack *stack, int val)
{
    if(!stack)
    {
        fprintf(stderr, "Stack is null\n");
        return 1;
    }
    if(is_full(stack))
    {
        fprintf(stderr, "Stack overflow\n");
        return 1;
    }

    stack->data[stack->top++] = val;
    return 0;
}

int s_pop(Stack *stack, int *out)
{
    if (!stack)
    {
        fprintf(stderr, "Stack is null\n");
        return 1;
    }
    if (!out)
    {
        fprintf(stderr, "Error poping and returning value\n");
    }
    if (is_empty(stack))
    {
        fprintf(stderr, "Stack underflow\n");
        return -1;
    }
    stack->top--;
    *out = stack->data[stack->top];
    return 0;
}

int s_top(Stack *stack, int *out)
{
    if (!stack)
    {
        fprintf(stderr, "Stack is null\n");
        return 1;
    }
    if (!out)
    {
        fprintf(stderr, "Error returning top value\n");
    }
    if (is_empty(stack))
    {
        fprintf(stderr, "Stack underflow\n");
        return -1;
    }
    *out = stack->data[stack->top-1];
    return 0;
}

int s_free(Stack* stack)
{
    if(!stack || !stack->data)
    {
        fprintf(stderr, "Stack is null, nothing to free\n");
        return 1;
    }
    free(stack->data);
    stack->data = NULL;
    stack->size = 0;
    stack->top = 0;
    return 0;
}

int s_create(Stack *stack, size_t size)
{
    if (!stack || size == 0)
    {
        fprintf(stderr, "No stack or no size\n");
        return 1;
    }
    stack->data = malloc(sizeof(int) * size);
    if (!stack->data) {
        printf("Error allocating memory for stack");
        return 1;
    }
    stack->size = size;
    stack->top = 0;
    return 0;
}

int s_print(Stack* stack)
{
    if (!stack || !stack->data)
    {
        fprintf(stderr, "Stack is null\n");
        return 1;
    }
    if (stack->size == 0 || stack->top == 0)
    {
        printf("[ ]\n");
        return 0;
    }
    printf("[ ");
    for (size_t i = 0; i < stack->top; i++)
        printf("%d ", stack->data[i]);
    printf("]\n");
    return 0;
}
