// Implement a stack using an array.
// Push some elements onto the stack.
// Sort the stack using bubble sort.
// Implement binary search to find a specific element.
// If the element is not found, display the message “Item not found”.

#include <stdio.h>

#define len 5
int arr[len];
int top = -1;

int isFull()
{
    if (top == len - 1)
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
    arr[top] = data;
}

void bubbleSort()
{
    int length = top + 1;
    for (int i = 0; i < length - 1; i++)
    {
        for (int j = 0; j < length - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int binarySearch(int searchItem)
{
    int lb = 0, ub = top+1, mid = (lb + ub) / 2;
    while (lb <= ub)
    {
        if (arr[mid] == searchItem)
        {
            return mid;
        }
        else if (arr[mid] > searchItem)
        {
            ub = mid - 1;
            mid = (lb + ub) / 2;
        }
        else
        {
            lb = mid + 1;
            mid = (lb + ub) / 2;
        }
    }
    return -1;
}

void print()
{
    for (int i = 0; i <= top; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main()
{

    push(10);
    push(2);
    push(15);
    push(6);
    push(4);

    bubbleSort(5);

    int res = binarySearch(10); // searchItem = 10

    printf("Sorted stack: ");

    print();

    if (res != -1)
    {
        printf("Item found at index: %d", res);
    }
    else
    {
        printf("Item not found :/ ");
    }

    return 0;
}