// Implement insertion sort to sort an array(given in the question or taken as input) in descending order.

// NB: I'm assuming the array isn't provided in the question. I will take the array as input.

#include <stdio.h>

void insertionSort(int arr[], int len)
{
    for (int i = 0; i < len; i++)
    {
        int j = i - 1;
        int key = arr[i];
        while (j >= 0 && arr[j] < key)
        {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int main()
{

    int len;

    printf("No of element:");
    scanf("%d", &len);

    int arr[len]; // initialize array

    // Taking array as input:
    printf("Enter %d elements:", len);
    for (int i = 0; i < len; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Sorted array:");

    insertionSort(arr, len);

    for (int i = 0; i < len; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}