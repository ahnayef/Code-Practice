#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <math.h>
#include <stdlib.h>
#include <wait.h>

int parent_s(int x)
{
    int i, total = 0;

    for (i = 0; i <= floor(x / 2); i++)
    {
        total += i;
    }
    return total;
}

int child_s(int x)
{
    int i, total = 0;

    for (i = floor(x / 2) + 1; i <= x; i++)
    {
        total += i;
    }
    return total;
}

int main()
{

    int Total = 0;
    int n = 10;
    pid_t p = fork();
    int status;

    if (p < 0)
    {
        printf("Failed to create process");
    }
    else if (p == 0)
    {
        Total = Total + child_s(n);
        exit(Total);
    }
    else
    {
        wait(&status);
        Total = parent_s(n) + WEXITSTATUS(status);
        printf("%d\n", Total);
    }
}