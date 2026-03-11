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
        return 1;
    if(is_full(stack))
        return 1;

    stack->data[stack->top++] = val;
    return 0;
}

int s_pop(Stack *stack, int *out)
{
    if(!stack || !out)
        return 1;
    if(is_empty(stack))
        return -1;
    stack->top--;
    *out = stack->data[stack->top];
    return 0;
}

int s_top(Stack *stack, int *out)
{
    if(!stack || !out)
        return 1;
    if(is_empty(stack))
        return -1;
    *out = stack->data[stack->top-1];
    return 0;
}

int s_free(Stack* stack)
{
    if(!stack)
        return 1;
    free(stack->data);
    stack->data = NULL;
    stack->size = 0;
    stack->top = 0;
    return 0;
}

int s_create(Stack *s, size_t size)
{
    if (!stack || size == 0)
        return 1;
    s->data = malloc(sizeof(int) * size);
    if (!s->data) {
        printf("Error allocating memory for stack");
        return 1;
    }
    s->size = size;
    s->top = 0;
    return 0;
}

int s_print(Stack* stack)
{
    if (!stack)
        return 1;
    printf("[ ");
    for (size_t i = 0; i < stack->top; i++)
        printf("%d ", stack->data[i]);
    printf("]\n");
}

int main()
{
    int out = 0;
    Stack my_s;
    s_create(&my_s, 10);

    s_pop(&my_s, &out);
    printf("Pop from empty: %d\n", out); 
    s_push(&my_s, 1);
    s_push(&my_s, 2);
    s_print(&my_s);
    s_pop(&my_s, &out);
    printf("Item pop: %d\n", out);
    s_print(&my_s);
    
    s_top(&my_s, &out);
    printf("Item top: %d\n", out);
    
    s_free(&my_s);
    printf("Stack after free: ");
    s_print(&my_s);

    return 0;
}
