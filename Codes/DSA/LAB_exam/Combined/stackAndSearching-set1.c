// Implement a stack using an array.
// Push some elements onto the stack(in ascending order).
// Implement binary search to find a specific element.
// If the element is not found, display the message “Item not found”.

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

int binarySearch(int searchItem)
{
    int lb = 0, ub = top, mid = (lb + ub) / 2;

    while (lb <= ub)
    {
        if (stack[mid] == searchItem)
        {
            return mid;
        }
        else if (stack[mid] < searchItem)
        {
            lb = mid + 1;
            mid = (lb + ub) / 2;
        }
        else
        {
            ub = mid - 1;
            mid = (lb + ub) / 2;
        }
    }
    return -1;
}

void print()
{
    for (int i = 0; i <= top; i++)
    {
        printf("%d ", stack[i]);
    }

    printf("\n");
}

int main()
{
    // Pusing 6 element<
    push(10);
    push(12);
    push(15);
    push(18);

    int searchItem = 18; // Took one from the stack

    print(); // It's not printf

    int res = binarySearch(18);



    if (res != -1)
    {
        printf("Item found at index %d", res);
    }
    else
    {
        printf("Item not found >_<");
    }

    return 0;
}