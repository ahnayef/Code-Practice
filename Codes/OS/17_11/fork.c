#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <math.h>
#include <stdlib.h>
#include <wait.h>

int main()
{

    pid_t p = fork();

    if (p < 0)
    {
        printf("Failed to create process");
    }
    else if (p == 0)
    {
        printf("\nInside Child process:\n");
        exit(1);
    }
    else
    {
        printf("\nInside Parent process:\n");
    }

    printf("\nOutside child & parent process\n");
}