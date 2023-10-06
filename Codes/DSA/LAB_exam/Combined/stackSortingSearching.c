// Implement a stack using an array.
// Push some elements onto the stack.
// Sort the stack using bubble sort.
// Implement binary search to find a specific element.
// If the element is not found, display the message “Item not found”.

#include <stdio.h>

#define len 5
int arr[len];
int top = -1;

int push(int data)
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

int binarySearch(int e, int searchItem)
{
    int lb = 0, ub = e, mid = (lb + ub) / 2;
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

int main()
{

    push(10);
    push(2);
    push(15);
    push(6);
    push(4);

    bubbleSort(5); 

    int res = binarySearch(5, 10); // 5 = element available in the stack. 10 = searchItem

    printf("Sorted stack: ");

    for (int i = 0; i < 5; i++)
    {
        printf("%d ",arr[i]);
    }

    printf("\n")    ;

    if (res!=-1)
    {
        printf("Item found at index: %d",res);
    }else{
        printf("Item not found :/ ");
    }
    

    return 0;
}