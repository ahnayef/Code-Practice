/*


1) Sort an array of integers using bubble sort / insertion sort. - I'll show both bubble and insertion sort. No worries.
2) Implement  linear search/binary search to find a specific element in the sorted array. - Same, I'll show both.

NB: I'm assuming the array isn't provided in the question. I will take the array as input.


*/

#include <stdio.h>

// Que 1 : Sorting, you can use any of it

void insertionSort(int arr[], int len)
{
    for (int i = 0; i < len; i++)
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
}

void bubbleSort(int arr[], int len)
{
    for (int i = 0; i < len - 1; i++)
    {
        for (int j = 0; j < len - i - 1; j++)
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

// Que 2 : Use whichever one you prefer. There is no obligation.

int linearSearch(int arr[], int len, int searchItem)
{
    for (int i = 0; i < len; i++)
    {
        if (arr[i] == searchItem)
        {
            return i;
        }
    }

    return -1;
}

int binarySearch(int arr[], int len, int searchItem)
{
    int lb = 0, ub = len, mid = (lb + ub) / 2;

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

    int len, searchItem;

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

    bubbleSort(arr, len); // I preffer bubble sort. You can use another one(Insertion sort). There's no problem on it.

    // insertionSort(arr, len);

    for (int i = 0; i < len; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\nSearch item: ");
    scanf("%d", &searchItem);

    int res = binarySearch(arr, len, searchItem); // I preffer binary search. You can use another one(linear search). There's no problem on it.

    // int res = linearSearch(arr, len, searchItem);

    if (res != -1)
    {
        printf("Item found at %d", res);
    }
    else
    {
        printf("Item not found");
    }

    return 0;
}