// Create a stack using a linked list and perform push and pop operations.

#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node *next;
    int data;
};

struct node *top;

void printList()
{
    struct node *ref;
    ref = top;

    while (ref != NULL)
    {
        printf("%d ", ref->data);
        ref = ref->next;
    }
    printf("\n");
}

int isFull(struct node *newNode)
{
    if (newNode == NULL)
    {
        return 1;
    }
    return 0;
}

int isEmpty()
{
    if (top == NULL)
    {
        return 1;
    }
    return 0;
}

void push(int data)
{
    struct node *newNode = NULL;
    newNode = malloc(sizeof(struct node));

    if (isFull(newNode))
    {
        return;
    }

    newNode->data = data;

    newNode->next = top;
    top = newNode;
}

void pop()
{
    if (isEmpty())
    {
        return;
    }

    struct node *temp;
    temp = top;
    top = top->next;
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

    top = one;

    printf("Liked list:\n");
    printList();

    printf("After pushing two elements:\n"); //Printing so you guys can understand
    push(50);
    push(60);
    printList();
    return 0;
}
