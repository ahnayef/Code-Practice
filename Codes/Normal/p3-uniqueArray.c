#include <stdio.h>

int main()
{

    int n;
    scanf("%d", &n);
    int arr[n];
    int isUnique = 0;

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i] != arr[j])
            {
                isUnique = 0;
                break;
            }
            else
            {
                isUnique = 1;
            }
        }
    }

    if (isUnique == 1)
    {
        printf("YES");
    }
    else
    {
        printf("NO");
    }
}