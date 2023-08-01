#include <stdio.h>

int linearSearch(int arr[], int searchItem, int len)
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
    int len;
    printf("Array length:");
    scanf("%d", &len);
    int arr[len];
    printf("Enter %d elements:", len);

    for (int i = 0; i < len; i++)
    {
        scanf("%d", &arr[i]);
    }

    int searchItem;

    printf("Item to search:");
    scanf("%d", &searchItem);

    int res = linearSearch(arr, searchItem, len);

    if (res != -1)
    {
        printf("Item index: %d\n", res);
    }
    else
    {
        printf("Item not found >_<\n");
    }

    return 0;
}
