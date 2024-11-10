#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main()
{

    pid_t p = fork();

    if (p < 0)
    {
        printf("Failed to create process");
    }
    else if (p == 0)
    {
        printf("\n\nChild process:\n");
        printf("Child id: %d\n", getpid());
        printf("Parent id: %d\n\n", getppid());
    }
    else
    {
        printf("Parent process:\n");
        printf("Parent id: %d\n", getpid());
        printf("Child id: %d\n", p);
    }
}