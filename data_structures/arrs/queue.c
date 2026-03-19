#include <stdio.h>
#include <stdlib.h>

typedef struct Queue
{
    int*   data;
    int size;
    int how_much;
    int tail;
    int head;
}Queue;

int is_full(Queue* q)
{
    return q->how_much >= q->size;
}

int is_empty(Queue* q)
{
    return q->how_much == 0;
}

int q_create(Queue* q, int size)
{
    if (!q || !size)
    {
        fprintf(stderr, "No queue or no size\n");
        return 1;
    }
    q->data = malloc(sizeof(int) * size);
    if (!q->data)
    {
        fprintf(stderr, "Error allocating memory\n");
        return 1;
    }
    q->size = size;
    q->how_much = 0;
    q->tail = 0;
    q->head = 0;
    return 0;
}

int q_put(Queue* q, int value)
{
    if (!q || !q->data)
    {
        fprintf(stderr, "No queue or no data\n");
        return 1;
    }

    if (is_full(q))
    {
        fprintf(stderr, "Queue overflow\n");
        return 1;
    }

    // put value
    q->data[q->tail] = value;
    // move tail forward
    q->tail++;
    q->how_much++;
    /// circular queue - if head is out of bounuds - return it to the start
    if (q->tail >= q->size)
    {
        q->tail = 0;
    }
    return 0;
}

int q_pop(Queue* q, int* out)
{
    if (!q || !q->data || !out)
    {
        fprintf(stderr, "No queue or no data\n");
        return 1;
    }

    if (is_empty(q))
    {
        fprintf(stderr, "Queue underflow\n");
        return 1;
    }

    *out = q->data[q->head];
    q->head++;
    q->how_much--;
    if (q->head >= q->size)
    {
        q->head = 0;
    }
    return 0;
}

int q_free(Queue* q)
{
    if (!q || !q->data)
    {
        fprintf(stderr, "No queue or no data\n");
        return 1;
    }

    free(q->data);
    q->data = NULL;
    q->size = 0;
    q->tail = 0;
    q->head = 0;
    q->how_much = 0;
    return 0;
}

int q_print(Queue* q)
{
    if (!q || !q->data)
    {
        fprintf(stderr, "No queue or no data\n");
        return 1;
    }
    if (is_empty(q))
    {
        printf("Queue is empty\n");
        return 0;
    }

    printf("Queue: [ ");

    int i = q->head;
    // walkthrough circular queue
    for (int count = 0; count < q->how_much; count++)
    {
        printf("%d ", q->data[i]);
        i = (i+1) % q->size;
    }
    printf("]\n");
}

int q_peek(Queue* q, int* out)
{
    if (!q || !q->data || !out)
    {
        fprintf(stderr, "No queue or no data\n");
        return 1;
    }

    if (is_empty(q))
    {
        fprintf(stderr, "Queue is empty\n");
        return 1;
    }

    *out = q->data[q->head];
    return 0;
}


