#include "linked_list.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
    Node* head = malloc(sizeof(Node));
    if (!head)
        return 1;
    head->data = 1;
    head->next = NULL;

    l_add(&head, 2);
    l_add(&head, 9);
    l_insert(&head, 10, 2);
    l_print(head);
    l_remove(&head, 9);
    l_print(head);
    l_remove(&head, 0);
    l_print(head);
    return 0;
}
