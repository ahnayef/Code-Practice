// Create a function to append a new node to the end of a linked list.

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

void insertLast(struct node *newNode)
{
    struct node *tmp = head;
    while (tmp->next != NULL)
    {
        tmp = tmp->next;
    }

    tmp->next = newNode;
}

// Efficient way:

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

    struct node *newnode = NULL;
    newnode = malloc(sizeof(struct node));
    newnode->data = 50; // hard coded, you can try taking input from user(2 lines of code 🙂)
    newnode->next = NULL;

    printf("Original liked list:\n"); // Printing to make it easy for you to understand
    printList();

    printf("\nAfter adding a element:\n"); // Printing to make it easy for you to understand
    insertLast(newnode);
    printList();

    return 0;
}