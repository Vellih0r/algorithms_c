#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct Stack {
    int* stack;
    size_t top;
    size_t size;
}Stack;

int is_full(Stack *stack)
{
    return (stack->top < stack->size);
}

int is_empty(Stack *stack)
{
    return (stack->top == 0);
}

void push(Stack *stack, int val)
{
    if(is_full(stack))
    {
        int top = stack->top;
        stack->stack[top] = val;
        ++stack->top;// = val;
    }
}

int pop(Stack *stack)
{
    if(is_empty(stack))
        return -1;
    int tmp = stack->stack[stack->top];
    stack->top--;
    printf("top %d\n", tmp);
    return tmp;
}

int top(Stack *stack)
{
    return stack->stack[stack->top];
}

void s_free(Stack* stack)
{
    free(stack->stack);
}

void s_print(Stack* stack)
{
    printf("[ ");
    for (int i = 0; i < stack->top; i++)
        printf("%d ", stack->stack[i]);
    printf("]\n");
}

int main()
{
    Stack my_s;
    my_s.size = 10;
    my_s.stack = malloc(sizeof(int) * my_s.size);
    my_s.top = 0;

    printf("Pop from empty: %d\n", pop(&my_s));
    push(&my_s, 1);
    push(&my_s, 2);
    s_print(&my_s);
    printf("Item pop: %d\n", pop(&my_s));
    s_print(&my_s);
    
    s_free(&my_s);
    printf("Stack after free: ");
    s_print(&my_s);

    return 0;
}
