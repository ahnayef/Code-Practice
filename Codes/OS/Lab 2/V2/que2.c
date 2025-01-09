#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
    pid_t c1, c2, c3, gc1, gc2;

    c1 = fork();

    if (c1 == 0)
    {
        gc1 = fork();

        if (gc1 == 0)
        {
            printf("\nGrand child 1 id: %d  parent: %d\n", getpid(), getppid());
            execl("./a", "./a", NULL);
        }
        else if (gc1 > 0)
        {
            gc2 = fork();

            if (gc2 == 0)
            {
                printf("\nGrand child 2 id: %d  parent: %d\n", getpid(), getppid());
                execl("./a", "./a", NULL);
            }
            else if (gc2 > 0)
            {
                printf("\nChild 1 id: %d  parent: %d\n", getpid(), getppid());
            }
        }
    }
    else if (c1 > 0)
    {
        // FIrst Parent

        c2 = fork();

        if (c2 == 0)
        {

            printf("\nChild 2 id: %d  parent: %d\n", getpid(), getppid());
        }
        else if (c2 > 0)
        {
            // Second parent

            c3 = fork();

            if (c3 == 0)
            {
                printf("\nChild 3 id: %d  parent: %d\n", getpid(), getppid());
            }
        }
    }
}