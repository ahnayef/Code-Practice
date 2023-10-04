// Find if a specific element exists in an array(given in the question or taken as input) using Linear search.

// NB: I'm assuming the array isn't provided in the question. I will take the array as input.

#include <stdio.h>

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

    // Taking search element as input:
    printf("Enter the element to search:");
    scanf("%d", &searchItem);

    int res = linearSearch(arr, len, searchItem);

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