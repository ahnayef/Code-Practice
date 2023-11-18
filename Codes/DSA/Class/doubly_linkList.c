#include <stdio.h>
#include <stdlib.h>

// Define the structure
struct node
{
    struct node *prev;
    int data;
    struct node *next;
};

struct node *head = NULL; // Globally Initialize the head of the list

// Function to add a new node to the end of the list
void addNewNode(int data)
{
    struct node *newNode1;
    newNode1 = malloc(sizeof(struct node));

    newNode1->data = data;
    newNode1->next = NULL;

    struct node *temp = head; // Create a copy of the head node

    // traverse to find the last node
    while (temp->next != NULL)
    {
        temp = temp->next;
    }

    // Add the new node to the end of the list
    temp->next = newNode1;
    newNode1->prev = temp;
}

// Function to print the data of the list
void print()
{
    struct node *p = head; //Create copy of the head node
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

    newNode->data = 10; // Assign data in the new node
    first->data = 5; 
    second->data = 7;
    third->data = 2;
    newNode2->data = 8;

    newNode->prev = NULL; 
    newNode->next = first; // Add the new node to the beginning of the list

    first->prev = newNode; // Point the previous of the first node to the new node
    first->next = second;

    second->prev = first;
    second->next = third;

    third->prev = second;
    third->next = newNode2; // Add the new node to the end of the list

    newNode2->prev = third;
    newNode2->next = NULL; 

    head = newNode; // Assign the head to the new node

    addNewNode(27); // Add a new node to the end of the list

    print(); // Print the data of the list

    return 0;
}