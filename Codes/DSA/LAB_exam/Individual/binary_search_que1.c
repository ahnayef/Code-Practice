// Find if a specific element exists in an array(given in the question or taken as input) using Linear search.

// NB: I'm assuming the array isn't provided in the question. I will take the array as input.

#include <stdio.h>

int binarySearch(int arr[], int len, int searchItem)
{
    int lb, ub, mid;

    lb = 0;
    ub = len;
    mid = (lb + ub) / 2;

    while (lb <= ub)
    {
        if (arr[mid] == searchItem)
        {
            return mid;
        }
        else if (searchItem > arr[mid])
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

    int len, searchItem;

    printf("No of element:");
    scanf("%d", &len);

    int arr[len]; // initialize array
    // Taking array as input:
    printf("Enter %d elements in sorted order.:", len);
    for (int i = 0; i < len; i++)
    {
        scanf("%d", &arr[i]);
    }

    // Taking search element as input:
    printf("Enter the element to search:");
    scanf("%d", &searchItem);

    int res = binarySearch(arr, len, searchItem);

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