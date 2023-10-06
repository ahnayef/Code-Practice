// Implement a stack using an array. (I myself don't know how to sort a linked list, so I won't be including any questions related to sorting linked lists).
// Push some elements onto the stack.
// Implement insertion / bubble sort using the stack.
// Display the sorted elements after the sorting operation.

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
        printf("Stack overflow");
    }
}

void insertionSort(int length)
{
    for (int i = 0; i < length; i++)
    {
        int j = i - 1;
        int key = arr[i];
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
};

void bubbleSort(int lenght)
{
    for (int i = 0; i < lenght - 1; i++)
    {
        for (int j = 0; j < lenght - i - 1; j++)
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

int main()
{
    push(10);
    push(12);
    push(30);
    push(15);
    push(5);

    // Try any of these 

    insertionSort(5); // 5 is the number of elements available in the stack

    // bubbleSort(5);

    for (int i = 0; i < 5; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}