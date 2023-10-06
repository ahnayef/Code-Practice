// Implement a stack using an array.
// Push some elements onto the stack(in ascending order).
// Implement binary search to find a specific element.
// If the element is not found, display the message “Item not found”.

#include <stdio.h>

#define len 5 // I's a Constant ||  Google it
int arr[len];
int top = -1;

void push(int data)
{

    if (top < len - 1)
    {
        top++;
        arr[top] = data;
    }
    else
    {
        printf("Stack overflow!");
    }
}

int binarySearch(int arr[], int lenght, int searchItem)
{
    int lb = 0, ub = lenght, mid = (lb + ub) / 2;

    while (lb <= ub)
    {
        if (arr[mid] == searchItem)
        {
            return mid;
        }
        else if (arr[mid] < searchItem)
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

int main()
{
    // Pusing 6 element<
    push(10);
    push(12);
    push(15);
    push(18);

    int searchItem = 18; // Took one from the stack

    int res = binarySearch(arr, 4, searchItem);

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