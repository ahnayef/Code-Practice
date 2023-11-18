#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *newnode = NULL, *front = NULL, *rear = NULL;

int isFull()
{
    if (newnode == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void enqueue(int data)
{

    newnode = malloc(sizeof(struct node));

    if (isFull())
    {
        printf("Overflow\n");
        exit(1);
    }

    newnode->data = data;
    newnode->next = NULL;

    if (rear == NULL)
    {
        front = rear = newnode;
    }
    else
    {
        rear->next = newnode;
        rear = newnode;
    }
}

int isEmpty()
{
    if (front == NULL)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int dequeue()
{
    if (isEmpty())
    {
        printf("Underflow\n");
        exit(1);
    }

    struct node *temp;
    temp = front;
    int data;

    data = temp->data;

    front = front->next;
    free(temp);
    temp = NULL;

    return data;
}

void print()
{
    struct node *temp;
    temp = front;

    while (temp)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

int main()
{

    enqueue(6);
    enqueue(16);
    enqueue(36);
    enqueue(46);
    enqueue(56);
    dequeue();
    dequeue();
    print();

    return 0;
}