#ifndef QUEUE_H
#define QUEUE_H

typedef struct Queue {
    int *data;
    int size;
    int how_much;
    int tail;
    int head;
}Queue;

int if_full(Queue*);
int is_empty(Queue*);
int q_create(Queue*, int);
int q_put(Queue*, int);
int q_peek(Queue*, int*);
int q_pop(Queue*, int*);
int q_free(Queue*);
int q_print(Queue*);
#endif
