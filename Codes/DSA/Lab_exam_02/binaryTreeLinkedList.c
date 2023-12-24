#include<stdio.h>
#include<stdlib.h>

// Define the structure for a node in the binary tree; It's bassically a doubly linked list. You know what that is, right?
struct node{
    struct node* left;  // Pointer to the left child node
    int data;  // Data contained in the node
    struct node* right;  // Pointer to the right child node
};

// Function to create a binary tree. The founction contains recursion. You better know what that is.
struct node* createTree(){
    int input;
    int data;
    // Ask the user if they want to add a node
    printf("Do you want to add a node?\n 1: Yes\n 0: No\n");
    scanf("%d",&input);
    if(input==0)
        return NULL;  // If the user does not want to add a node, return NULL
    else{
        // Allocate memory for a new node
        struct node* newnode= malloc(sizeof(struct node));
        // Ask the user for the value of the node
        printf("Enter value: ");
        scanf("%d",&data);
        // Assign the user's value to the node
        newnode->data=data;
        // Ask the user for the left child of the node
        printf("Left child of %d ::",newnode->data);
        newnode->left=createTree();
        // Ask the user for the right child of the node
        printf("Right child of %d :: ",newnode->data);
        newnode->right=createTree();
        // Return the new node
        return newnode;
    }
}

int main()
{
    // Create the root of the tree
    struct node* root= createTree();

    // Input the tree like this one: (I've included the image below))
    // Print the data of the root and its children
    printf("%d ", root->data);
    printf("%d ", root->left->data);
    printf("%d ", root->right->data);
    printf("%d ", root->left->left->data);
    printf("%d ", root->left->right->data);
    printf("%d \n", root->right->right->data);
}