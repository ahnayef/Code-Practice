// Create a C program consists of one parent process that creates three other child processes. Print the ID of parent process and ID and parent's ID of each child process. Then, each child process will execute a program b.c. The program b.c will print "Hello, I am a child process".

#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

int main()
{
    pid_t p1, p2, p3;

    printf("Parent process id: %d\n", getpid());

    p1 = fork();
    if (p1 == 0)
    {
        printf("Child 1 process id: %d, parent id: %d\n", getpid(), getppid());
        execl("./b", "./b", NULL);
        exit(1);
    }
    else if (p1 > 0)
    {
        p2 = fork();
        if (p2 == 0)
        {
            printf("Child 2 process id: %d, parent id: %d\n", getpid(), getppid());
            execl("./b", "./b", NULL);
            exit(1);
        }
        else if (p2 > 0)
        {
            p3 = fork();
            if (p3 == 0)
            {
                printf("Child 3 process id: %d, parent id: %d\n", getpid(), getppid());
                execl("./b", "./b", NULL);
                exit(1);
            }
        }
    }
    return 0;
}
