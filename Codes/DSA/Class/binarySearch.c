#include <stdio.h>

int binSearch(int arr[], int searchItem, int len)
{
    
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