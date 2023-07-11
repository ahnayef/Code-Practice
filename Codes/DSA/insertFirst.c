#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *insertFirst(struct node *toAdd, struct node *head)
{

    toAdd->next = head;

    head = toAdd;

    return head;
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

    struct node *head;
    struct node *middle;
    struct node *last;

    head = (struct node *)malloc(sizeof(struct node));
    middle = (struct node *)malloc(sizeof(struct node));
    last = (struct node *)malloc(sizeof(struct node));

    head->data = 10;
    middle->data = 20;
    last->data = 30;

    head->next = middle;
    middle->next = last;
    last->next = NULL;

    struct node *new = (struct node *)malloc(sizeof(struct node));

    new->data = 50;

    travel(head);

    printf("\nAfter insertion:\n");

    travel((insertFirst(new, head)));
}