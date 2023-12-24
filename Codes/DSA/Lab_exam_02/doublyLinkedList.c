#include <stdio.h>
#include <stdlib.h>

// create node
struct node
{

    struct node *prev;
    int data;
    struct node *next;
};

// print data
void printLinkedlist(struct node *p)
{

    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
}

int main()
{

    struct node *head;

    struct node *first = NULL;
    first = malloc(sizeof(struct node));

    struct node *second = NULL;
    second = malloc(sizeof(struct node));

    struct node *third = NULL;
    third = malloc(sizeof(struct node));

    first->data = 5;
    second->data = 7;
    third->data = 2;

    first->prev = NULL;
    first->next = second;

    second->prev = first;
    second->next = third;

    third->prev = second;
    third->next = NULL;

    head = first;
     // Printing the initial linked list
    printLinkedlist(head);
    printf("\n");

    // insert data at the beginning
    struct node *newNode;
    newNode = malloc(sizeof(struct node));
    newNode->data = 4;
    newNode->prev = NULL;
    newNode->next = head;
    first->prev = newNode;
    head = newNode;

    // Printing the linked list after inserting a node at the beginning
    printLinkedlist(head);
    printf("\n");

    // insert data at the end
    struct node *newNode1;
    newNode1 = malloc(sizeof(struct node));

    newNode1->data = 9;
    newNode1->next = NULL;

    struct node *temp = head;

    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode1;
    newNode1->prev = temp;

    // Printing the linked list after inserting a node at the end
    printLinkedlist(head);
    printf("\n");
}
