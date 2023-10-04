// Insert a new node to the beginning of a linked list.

// NB: I'm assuming the linked list data isn't provided in the question. I will create the linked list with random data.

#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node *next;
    int data;
};

struct node *head;

void printList()
{
    struct node *ref;
    ref = head;

    while (ref != NULL)
    {
        printf("%d ", ref->data);
        ref = ref->next;
    }
}

void insertLast()
{
    head = head->next; // Easy ?
}

// Efficient way:

void deleteFirstNodeV2()
{
    struct node *temp = head;
    head = head->next;
    free(temp);
}

int main()
{
    struct node *one = NULL;
    struct node *two = NULL;
    struct node *three = NULL;
    struct node *four = NULL;

    one = malloc(sizeof(struct node));
    two = malloc(sizeof(struct node));
    three = malloc(sizeof(struct node));
    four = malloc(sizeof(struct node));

    one->data = 10;
    two->data = 20;
    three->data = 30;
    four->data = 40;

    one->next = two;
    two->next = three;
    three->next = four;
    four->next = NULL;

    head = one;

    printf("Original liked list:\n"); // Printing to make it easy and understandable for you.
    printList();

    printf("\nAfter deleting the first node:\n"); // Printing to make it easy and understandable for you.
    insertLast();
    printList();

    printf("\nAfter deleting the first node(efficient way):\n"); // Printing to make it easy and understandable for you.
    deleteFirstNodeV2();
    printList();

    return 0;
}