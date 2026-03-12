#include <stdio.h>
#include "stack.h"

int main()
{
    int out = 0;
    Stack my_s;
    size_t size = 10;
    s_create(&my_s, size);

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

    for (size_t i = 0; i < size; i++)
    {
        s_push(&my_s, i);
    }
    s_print(&my_s);
    
    s_free(&my_s);
    printf("Stack after free:\n");
    s_print(&my_s);

    return 0;
}
