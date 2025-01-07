// Create a C program consists of one parent process that creates two other child processes. We would like to compute the product of a sequence from 1 to n, where n > 0. We would like to implement our program in such a way we make use of both the child processes. Let one child process is P1 and another child process is P2. P1 executes the product from 1 to n/2, and process P2 executes the product from n/2+1 to n. The parent process will calculate and print the final result.

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

unsigned long long cal_product1(int n)
{
    unsigned long long product = 1;
    for (int i = 1; i <= n / 2; i++)
    {
        product *= i;
    }
    return product;
}

unsigned long long cal_product2(int n)
{
    unsigned long long product = 1;
    for (int i = n / 2 + 1; i <= n; i++)
    {
        product *= i;
    }
    return product;
}

int main()
{
    int n;
    scanf("%d", &n);

    if (n <= 0)
    {
        printf("n must be greater than 0.\n");
        return 1;
    }

    pid_t pid1, pid2;
    int status1, status2;
    unsigned long long product1 = 1, product2 = 1;

    unsigned long long total;

    pid1 = fork();
    if (pid1 == 0)
    {
        product1 = cal_product1(n);
        exit((product1));
    }
    else if (pid1 > 0)
    {
        pid2 = fork();
        if (pid2 == 0)
        {
            product2 = cal_product2(n);
            exit(product2);
        }
        else if (pid2 > 0)
        {
            wait(&status1);
            wait(&status2);

            unsigned long long total = WEXITSTATUS(status1) * WEXITSTATUS(status2);
            printf("%llu", total);
        }
    }

    return 0;
}