#include<stdio.h>
#include<stdlib.h>
#define MAX 10  // Define the maximum size of the binary tree; It's a constant

char tree[MAX];  // Declare the binary tree as an array; It's a global variable

// Function to set the root of the binary tree
void root(char parent){
    if(tree[0]!='\0'){  // Check if root already exists
        printf("Root already exist");
    }
    else{
        tree[0]=parent;  // Set the root of the tree
    }
}

// Function to set the left child of a node
void left(char child,int parent){
    if(tree[parent]=='\0'){  // Check if parent exists
        printf("parent does not exist");
    }
    else{
        tree[(2*parent)+1]=child;  // Set the left child of the parent
    }
}

// Function to set the right child of a node
void right(char child,int parent){
    if(tree[parent]=='\0'){  // Check if parent exists
        printf("parent does not exist");
    }
    else{
        tree[(2*parent)+2]=child;  // Set the right child of the parent
    }
}

// Function to print the binary tree
void printBinaryTree(){
    int i;
    for(i=0;i<MAX;i++){  // Loop through the tree
        if(tree[i]=='\0')  // If the node is empty, print a dot
            printf(".");
        else
            printf("%c",tree[i]);  // Print the node value
    }
}

int main()
{
    root('A');  // Set the root of the tree
    left('B',0);  // Set the left child of the root
    right('C',0);  // Set the right child of the root
    left('D',1);  // Set the left child of the second node
    right('E',1);  // Set the right child of the second node
    printBinaryTree();  // Print the binary tree
}