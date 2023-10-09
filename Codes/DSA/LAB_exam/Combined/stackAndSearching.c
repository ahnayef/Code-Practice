// Implement a stack using an array. (I myself don't know how to sort a linked list, so I won't be including any questions related to sorting linked lists).
// Push some elements onto the stack.
// Implement insertion / bubble sort using the stack.
// Display the sorted elements after the sorting operation.

#include <stdio.h>

#define size 5 // I's a Constant ||  Google it
int stack[size];
int top = -1;

int isFull()
{
    if (top == size - 1)
    {
        return 1;
    }
    return 0;
}

int isEmpty()
{
    if (top == -1)
    {
        return 1;
    }
    return 0;
}

void push(int data)
{

    if (isFull())
    {
        printf("Stack overflow");
        return;
    }
    top++;
    stack[top] = data;
}

void insertionSort()
{
    for (int i = 0; i < top; i++)
    {
        int j = i - 1;
        int key = stack[i];
        while (j >= 0 && stack[j] > key)
        {
            stack[j + 1] = stack[j];
            j--;
        }
        stack[j + 1] = key;
    }
};

void bubbleSort()
{

    for (int i = 0; i < top - 1; i++)
    {
        for (int j = 0; j < top - i - 1; j++)
        {
            if (stack[j] > stack[j + 1])
            {
                int temp = stack[j];
                stack[j] = stack[j + 1];
                stack[j + 1] = temp;
            }
        }
    }
}

void print()
{
    for (int i = 0; i < top; i++)
    {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

int main()
{
    push(12);
    push(10);
    push(30);
    push(15);
    push(5);

    printf("Before sorting: ");
    print();

    // Try any of these
    insertionSort(); 
    // bubbleSort();

    printf("After sorting: ");
    print();

    return 0;
}