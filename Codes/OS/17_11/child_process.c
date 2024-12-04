//Que: Create 3 child process

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main()
{
    pid_t p1, p2, p3;

    p1 = fork();

    if (p1 == 0)
    {
        printf("Child 1 process id %d, parent id: %d\n", getpid(), getppid());
    }
    else
    {
        // printf("\n%d\n",p1);
        // printf("\n%d\n",getpid());
        p2 = fork();
        if (p2 == 0)
        {
            printf("Child 2 process id %d, parent id: %d\n", getpid(), getppid());
        }
        else
        {
            p3 = fork();
            if (p3 == 0)
            {
                printf("Child 3 process id %d, parent id: %d\n", getpid(), getppid());
            }
        }
    }
}