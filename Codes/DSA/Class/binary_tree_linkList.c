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

void preOrder(struct node *root)
{
    if (root == NULL)
    {
        return;
    }
    else
    {
        printf("%d ", root->data);
        preOrder(root->left);
        preOrder(root->right);
    }
}

void inOrder(struct node *root)
{
    if (root == NULL)
    {
        return;
    }
    else
    {
        inOrder(root->left);
        printf("%d ", root->data);
        inOrder(root->right);
    }
}

void postOrder(struct node *root)
{
    if (root == NULL)
    {
        return;
    }
    else
    {
        postOrder(root->left);
        postOrder(root->right);
        printf("%d ", root->data);
    }
}

int main()
{

    struct node *root = createTree();

    printf("Preorder traversal: ");
    preOrder(root);
    printf("\n");
    printf("Inorder traversal: ");
    inOrder(root);
    printf("\n");
    printf("Postorder traversal: ");
    postOrder(root);
    printf("\n");

    return 0;
}