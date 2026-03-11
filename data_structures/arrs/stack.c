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
    return (stack->top == stack->size);
}

int is_empty(Stack *stack)
{
    return (stack->top == 0);
}

void s_push(Stack *stack, int val)
{
    if(!is_full(stack))
    {
        int top = stack->top;
        stack->data[top] = val;
        ++stack->top;// = val;
    }
}

int s_pop(Stack *stack)
{
    if(is_empty(stack))
        return -1;
    stack->top--;
    return stack->data[stack->top];
}

int s_top(Stack *stack)
{
    return stack->data[stack->top-1];
}

void s_free(Stack* stack)
{
    free(stack->data);
    stack->data = NULL;
    stack->size = 0;
    stack->top = 0;
}

int s_create(Stack *s, size_t size)
{
    s->data = malloc(sizeof(int) * size);
    if (!s->data) {
        printf("Error allocating memory for stack");
        return 1;
    }
    s->size = size;
    s->top = 0;
}

void s_print(Stack* stack)
{
    printf("[ ");
    for (int i = 0; i < stack->top; i++)
        printf("%d ", stack->data[i]);
    printf("]\n");
}

int main()
{
    Stack my_s;
    s_create(&my_s, 10);

    printf("Pop from empty: %d\n", s_pop(&my_s));
    s_push(&my_s, 1);
    s_push(&my_s, 2);
    s_print(&my_s);
    printf("Item pop: %d\n", s_pop(&my_s));
    s_print(&my_s);
    
    printf("Item top: %d\n", s_top(&my_s));
    
    s_free(&my_s);
    printf("Stack after free: ");
    s_print(&my_s);

    return 0;
}
