#include <stdio.h>
#include "queue.h"

int main()
{
    int out = 0;
    Queue q;
    int size = 10;
    q_create(&q, size);

    q_pop(&q, &out);
    printf("Pop from empty: %d\n", out); 
    q_put(&q, 1);
    q_put(&q, 2);
    q_print(&q);
    q_pop(&q, &out);
    printf("Item pop: %d\n", out);
    q_print(&q);
    
    q_peek(&q, &out);
    printf("Item top: %d\n", out);

    for (int i = 0; i < size; i++)
    {
        q_put(&q, i);
    }
    q_print(&q);
    
    q_free(&q);
    printf("Queue after free:\n");
    q_print(&q);

    return 0;
}
