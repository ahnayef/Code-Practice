// Create a stack using a linked list and perform push and pop operations.

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
    printf("\n");
}

void push(int data)
{
    struct node *newNode = NULL;
    newNode = malloc(sizeof(struct node));
    newNode->data = data;

    newNode->next = head;
    head = newNode;
}

void pop()
{
    struct node *temp;
    temp = head;
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

    printf("Liked list:\n");
    printList();

    printf("After pushing two elements:\n");  // Printing to make it easy and understandable for you.
    push(50);
    push(60);
    printList();
    printf("After popping one element:\n");
    pop();
    printList();

    return 0;
}