// Linked list insert at any position

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};
struct node *head = NULL, *current_node = NULL;

void Insert(int data)
{

    struct node *newNode = malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;

    // isEmpty
    if (head == NULL)
    {
        head = newNode;
        current_node = newNode;
    }
    else
    {

        current_node->next = newNode;
        current_node = newNode;
    }
}

void insertAnywhere(int position, int data)
{
    struct node *newNode1;
    newNode1 = malloc(sizeof(struct node));
    newNode1->data = data;

    if (position == 1)
    {
        newNode1->next = head;
        head = newNode1;
        return;
    }

    struct node *temp = head;

    for (int i = 2; i < position; i++)
    {

        if (temp->next != NULL)
        {
            temp = temp->next;
        }
    }
    newNode1->next = temp->next;
    temp->next = newNode1;
}

void print()
{
    struct node *current = head;

    if (head == NULL)
    {
        printf("List is empty\n");
        return;
    }

    while (current != NULL)
    {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main()
{
    int n, i, a, position, data;
    printf("Insert number of element:");
    scanf("%d", &n);
    printf("Insert the elements:");
    for (i = 0; i < n; i++)
    {

        scanf("%d", &a);
        Insert(a);
    }
    print();
    printf("Insert position where your want to insert new data: \n");
    scanf("%d", &position);
    if (position > n)
    {
        printf("position should be less than or equal to number of element.");
    }
    else
    {
        printf("Insert new data: \n");
        scanf("%d", &data);
        insertAnywhere(position, data);
        printf("Updated linked list \n");
        print();
    }
}