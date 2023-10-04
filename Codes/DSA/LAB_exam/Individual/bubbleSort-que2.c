// Implement bubble sort to sort an array(given in the question or taken as input)  in descending order.

// NB: I'm assuming the array isn't provided in the question. I will take the array as input.

#include <stdio.h>

void bubbleSort(int arr[], int len)
{

    for (int i = 0; i < len - 1; i++)
    {
        for (int j = 0; j < len - i - 1; j++)
        {
            if (arr[j] < arr[j + 1])
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

    bubbleSort(arr, len);

    for (int i = 0; i < len; i++)
    {
        printf("%d ", arr[i]);
    }

    return 0;
}