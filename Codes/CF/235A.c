#include <stdio.h>
#include <string.h>

int main()
{

    char name[100];
    scanf("%s", &name);

    int i = 0;
    int sum = 0;
    while (name[i] != '\0')
    {

        int j = i + 1;
        while (name[j] != '\0')
        {
            if (name[i] == name[j])
            {
                sum += 2;
                printf("Matched case: %c. Total %d\n", name[j], sum);
            }

            // Not  to remove
            j++;
        }
        printf("\nEnd loop fro %c\n", name[i]);

        // not to remove
        i++;
    }

    if (sum % 2 != 0)
    {
        printf("IGNORE HIM!");
    }
    else
    {
        printf("CHAT WITH HER!");
    }

    // int arr[] = {3, 2, 9, 3, 4, 2, 5,9, -1};

    // int i = 0;
    // int sum = 0;
    // while (arr[i] != -1)
    // {

    //     int j = i + 1;
    //     while (arr[j] != -1)
    //     {
    //         if (arr[i] == arr[j])
    //         {
    //             sum += 1;
    //             printf("Matched case: %d. Total %d\n", arr[j], sum);
    //         }

    //         // Not  to remove
    //         j++;
    //     }
    //     printf("\nEnd loop fro %d\n", arr[i]);

    //     // not to remove
    //     i++;
    // }

    return 0;
}
