#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int cal1(int n)
{
    int sum = 0;

    for (int i = 0; i <= n / 2; i++)
    {
        sum += i;
    }
    return sum;
}

int cal2(int n)
{
    int sum = 0;

    for (int i = (n / 2) + 1; i <= n; i++)
    {
        sum += i;
    }
    return sum;
}

int main()
{
    int n;
    scanf("%d", &n);

    if (n < 0)
    {
        printf("n<0");
    }

    pid_t c1, c2, gc1, gc2;

    c1 = fork();

    if (c1 == 0)
    {
        // C1
        gc1 = fork();
        if (gc1 == 0)
        {
            // GC1
            int sum1 = cal1(n);
            exit(sum1);
        }
        else if (gc1 > 0)
        {
            // C1
            int status;
            wait(&status);
            int sum1 = WEXITSTATUS(status);
            exit(sum1);
        }
    }
    else if (c1 > 0)
    {
        // P
        c2 = fork();

        if (c2 == 0)
        {
            // C2

            gc2 = fork();
            if (gc2 == 0)
            {
                // GC2
                int sum2 = cal2(n);
                exit(sum2);
            }
            else if (gc2 > 0)
            {
                // C2
                int status;
                wait(&status);
                int sum2 = WEXITSTATUS(status);
                exit(sum2);
            }
        }
        if (c2 > 0)
        {
            int status1, status2;
            wait(&status1);
            wait(&status2);

            int total = WEXITSTATUS(status1) + WEXITSTATUS(status2);
            printf("%d", total); 
        }
    }
}