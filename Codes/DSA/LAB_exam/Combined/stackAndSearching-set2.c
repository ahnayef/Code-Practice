// Implement a stack using a linked list.
// Push some elements onto the stack.
// Implement linear search to find a specific element.
// If the element is not found, display the message “Item not found”.

#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node *next;
    int data;
};

struct node *head;

void printList() // I'm writing this function just so you can understand the linearSearch function below. Otherwise, there's no need for it
{
    struct node *ref;
    ref = head;

    while (ref != NULL)
    {
        printf("Data : %d || Address: %d\n", ref->data, ref);
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

void push(int data)
{
    struct node *newNode = NULL;
    newNode = malloc(sizeof(struct node));

    if (isFull(newNode))
    {
        return;
    }

    newNode->data = data;
    newNode->next = head;
    head = newNode;
}

int linearSearch(int data)
{
    struct node *ref = head;
    while (ref->data != data)
    {
        ref = ref->next;
        if (ref == NULL)
        {
            break;
        }
    }

    if (ref != NULL)
    {
        printf("Item found at the address: %d\n", ref);
    }
    else
    {
        return -1;
    }
}

int main()
{
    struct node *one = NULL;

    one = malloc(sizeof(struct node));

    one->data = 10;
    one->next = NULL;

    head = one;

    push(20);
    push(15);
    push(25);
    push(30);

    printList();

    int res = linearSearch(10);

    if (res == -1)
    {
        printf("Item not found >_<");
    }

    return 0;
}