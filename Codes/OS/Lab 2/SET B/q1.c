// Create a C program consists of one parent process that creates two other child processes. We would like to compute the sum of a sequence from 0 to n, where n > 0. We would like to implement our program in such a way that we make use of both the child processes. Let one child process is P1 and another child process is P2. P1 executes the sum from 0 to n/2, and process P2 executes the sum from n/2+1 to n. The parent process will calculate and print the final result.

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <math.h>
#include <stdlib.h>
#include <wait.h>

int cal_sum1(int x)
{
    int i, total = 0;

    for (i = 0; i <= floor(x / 2); i++)
    {
        total += i;
    }
    return total;
}

int cal_sum2(int x)
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

    int n;
    scanf("%d", &n);

    int sum1 = 0, sum2 = 0;

    pid_t pid1, pid2;
    int status1, status2;

    int total = 0;

    pid1 = fork();

    if (pid1 < 0)
    {
        printf("Failed to create process");
    }
    else if (pid1 == 0)
    {
        sum1 = cal_sum1(n);
        exit(sum1);
    }
    else
    {
        pid2 = fork();
        if (pid2 == 0)
        {
            sum2 = cal_sum2(n);
            exit(sum2);
        }
    }

    wait(&status1);
    wait(&status2);

    total = WEXITSTATUS(status1) + WEXITSTATUS(status2);

    printf("%d", total);
}