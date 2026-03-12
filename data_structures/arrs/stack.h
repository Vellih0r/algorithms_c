#ifndef STACK_H
#define STACK_H

#include <stddef.h>

typedef struct Stack {
    int    *data;
    size_t top;
    size_t size;
}Stack;

int if_full(Stack*);
int is_empty(Stack*);
int s_push(Stack*, int);
int s_top(Stack*, int*);
int s_pop(Stack*, int*);
int s_free(Stack*);
int s_create(Stack*, size_t);
int s_print(Stack*);
#endif
