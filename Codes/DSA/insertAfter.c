#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void insertAfter(struct node *ptr, struct node *add)
{
    add->next = ptr->next;
    ptr->next = add;
}

void travel(struct node *ptr)
{

    while (ptr != NULL)
    {
        printf("%d\n", ptr->data);
        ptr = ptr->next;
    }
}

int main()
{

    struct node *head = (struct node *)malloc(sizeof(struct node));
    struct node *second = (struct node *)malloc(sizeof(struct node));
    struct node *last = (struct node *)malloc(sizeof(struct node));
    struct node *new = (struct node *)malloc(sizeof(struct node));
    struct node *new2 = (struct node *)malloc(sizeof(struct node));

    head->data = 10;
    head->next = second;

    second->data = 20;
    second->next = last;

    last->data = 30;
    last->next = NULL;

    new->data = 70;
    new2->data = 100;

    travel(head);

    insertAfter(head, new);
    insertAfter(new, new2);

    printf("After insertion:\n");

    travel(head);


    return 0;
}