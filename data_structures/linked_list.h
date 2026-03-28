#ifndef LINKED_LIST_H
#define LINKED_LIST_H

typedef struct Node
{
    int data;
    struct Node* next;
}Node;

int l_add(Node**, int);
int l_remove(Node**, int);
int l_insert(Node**, int, int);
void l_print(Node*);
int l_get(Node**, int, Node*);
void l_destory(Node**);
#endif
