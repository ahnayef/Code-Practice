#include <stdio.h>

int binSearch(int arr[], int searchItem, int len)
{
    int l = 0, h = len - 1;
    int m = (l + h) / 2;

    while (l <= h)
    {
        if (arr[m] == searchItem)
        {
            return m;
        }
        else if (arr[m] > searchItem)
        {
            h = m - 1;
            m = (l + h) / 2;
        }
        else
        {
            l = m + 1;
            m = (l + h) / 2;
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

    // binSearch(arr, searchItem, len);

    int res = binSearch(arr, searchItem, len);

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