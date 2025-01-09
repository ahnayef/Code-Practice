// Create a C program consists of one parent process that creates three other child processes. Print the ID of current process ID and parent's ID of each child process. Then, each child process will execute a program a.c. The program a.c will print "Hello World".

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
    pid_t p1, p2, p3;

    p1 = fork();

    if (p1 == 0)
    {
        printf("Child 1 process id %d, parent id: %d\n", getpid(), getppid());
        execl("./a", "./a", NULL);
    }
    else if (p1 > 0)
    {
        p2 = fork();
        if (p2 == 0)
        {
            printf("Child 2 process id %d, parent id: %d\n", getpid(), getppid());
            execl("./a", "./a", NULL);
        }
        else if (p3 > 0)
        {
            p3 = fork();
            if (p3 == 0)
            {
                printf("Child 3 process id %d, parent id: %d\n", getpid(), getppid());
                execl("./a", "./a", NULL);
            }
        }
    }
}