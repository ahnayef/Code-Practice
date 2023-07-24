#include <stdio.h>
#include <ctype.h>

int main()
{

    char name[100];
    scanf("%s", &name);

    int i = 0;
    int len = 0;
    int sum = 0;

    while (name[len] != '\0')
    {
        name[len] = tolower(name[len]);
        len++;
    }

    while (name[i] != '\0')
    {

        int j = i + 1;
        while (name[j] != '\0')
        {
            if (name[i] == name[j])
            {
                sum += 1;
            }

            // Not  to remove
            j++;
        }

        // not to remove
        i++;
    }

    int noOfunique = len - sum;

    if (noOfunique % 2 != 0)
    {
        printf("IGNORE HIM!");
    }
    else if (noOfunique % 2 == 0)
    {
        printf("CHAT WITH HER!");
    }
}