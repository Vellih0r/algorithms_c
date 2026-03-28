#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node* next;
}Node;

int l_add(Node **head, int data)
{
    Node *new = malloc(sizeof(Node));
    if (!new)
    {
        fprintf(stderr, "Error allocating memory for new node");
        return 1;
    }
    new->data = data;
    new->next = NULL;

    while (*head)
        head = &(*head)->next;
    *head = new;
    return 0;
}

int l_insert(Node **head, int data, int key)
{
    if (!head)
    {
        fprintf(stderr, "l_insert requires an argument\n");
        return 1;
    }
    while (*head)
    {
        head = &(*head)->next;
        if ((*head)->data == key)
        {
            Node *new = malloc(sizeof(Node));
            if (!new)
            {
                fprintf(stderr, "Error allocating memory");
                return 1;
            }
            new->data = data;
            new->next = (*head)->next;
            *head = new;
            return 0;
        }
    }
    return 0;
}

int l_remove(Node **head, int key)
{
    if (!head)
    {
        fprintf(stderr, "l_add requires 2 arguments (not null)");
        return 1;
    }
    while (*head && (*head)->data != key)
        head = &(*head)->next;

    if (*head == NULL)
        return 0;

    Node *tmp = *head;
    *head = (*head)->next;
    free(tmp);
    return 0;
}

int l_get(Node **head, int key, Node** out)
{
    if (!head || !out)
    {
        fprintf(stderr, "l_get requires 3 arguments");
        return 1;
    }

    while (*head && (*head)->data != key)
        head = &(*head)->next;
    
    *out = *head;
    return 0;
}

void l_print(Node *head)
{
    if (!head)
    {
        printf("empty");
    }
    while (head)
    {
        if (head->next == NULL)
        {
            printf("%d\n", head->data);
            return;
        }
        printf("%d->", head->data);
        head = head->next;
    }
}

void l_destroy(Node **head)
{
    Node *current = *head;
    Node *next;
    while (current)
    {
        next = current->next;
        free(current);
        current = next;
    }
    *head = NULL;
}
