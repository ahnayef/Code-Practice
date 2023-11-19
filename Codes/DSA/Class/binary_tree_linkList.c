#include <stdio.h>
#include <stdlib.h>

struct node
{
    struct node *left;
    char data;
    struct node *right;
};

struct node *createTree()
{
    int input, data;
    printf("Do you want to add a node? press 1 for yes: ");
    scanf("%d", &input);

    if (!input)
    {
        return NULL;
    }
    else
    {
        struct node *newNode = malloc(sizeof(struct node));
        printf("Enter data:");
        scanf("%d", &data);
        newNode->data = data;
        printf("Left child of %d:\n", newNode->data);
        newNode->left = createTree();
        printf("Right child of %d:\n", newNode->data);
        newNode->right = createTree();
        return newNode;
    }
}

int main()
{

    struct node *root = createTree();

    printf("%d ", root->data);
    printf("%d ", root->left->data);
    printf("%d ", root->right->data);
    printf("%d ", root->left->left->data);
    printf("%d ", root->left->right->data);
    printf("%d ", root->right->right->data);

    return 0;
}