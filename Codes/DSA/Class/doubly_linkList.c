#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node *prev;
    int data;
    struct node *next;
};

struct node *head;

void addNewNode(int data)
{
    struct node *newNode1;
    newNode1 = malloc(sizeof(struct node));

    newNode1->data = data;
    newNode1->next = NULL;

    struct node *temp = head;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    temp->next = newNode1;
    newNode1->prev = temp;
}

void print(struct node *p)
{
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
}

int main()
{

    struct node *first = NULL;
    first = malloc(sizeof(struct node));

    struct node *second = NULL;
    second = malloc(sizeof(struct node));

    struct node *third = NULL;
    third = malloc(sizeof(struct node));

    struct node *newNode = NULL;
    newNode = malloc(sizeof(struct node));

    struct node *newNode2 = NULL;
    newNode2 = malloc(sizeof(struct node));

    newNode->data = 10;
    first->data = 5;
    second->data = 7;
    third->data = 2;
    newNode2->data = 8;

    newNode->prev = NULL;
    newNode->next = first;

    first->prev = newNode;
    first->next = second;

    second->prev = first;
    second->next = third;

    third->prev = second;
    third->next = newNode2;

    newNode2->prev = third;
    newNode2->next = NULL;

    head = newNode;

    addNewNode(27);

    print(head);

    return 0;
}