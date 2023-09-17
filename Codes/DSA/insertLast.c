#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *head;

void travel()
{

    struct node *ptr;
    ptr = head;

    while (ptr != NULL)
    {
        printf("%d ", ptr->data);
        ptr = ptr->next;
    }
}

void insertLast(struct node *);

int main()
{

    struct node *one = NULL;
    struct node *two = NULL;
    struct node *three = NULL;
    struct node *newNode = NULL;

    one = malloc(sizeof(struct node));
    two = malloc(sizeof(struct node));
    three = malloc(sizeof(struct node));
    newNode = malloc(sizeof(struct node));

    one->data = 10;
    two->data = 20;
    three->data = 30;
    newNode->data = 50;

    one->next = two;
    two->next = three;
    three->next = NULL;

    head = one;

    insertLast(newNode);
    travel();
}

void insertLast(struct node *newNode)
{

    struct node *ptr;
    ptr = head;

    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }

    ptr->next = newNode;
    newNode->next = NULL;
}