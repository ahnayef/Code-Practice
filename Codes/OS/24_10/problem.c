#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

int main()
{
    pid_t pid0, pid1, pid2, pid3;

    pid1 = fork();

    if (pid1 < 0)
    {
        printf("Pid1 Fail");
    }

    if (pid1 != 0)
    {
        pid2 = fork();
    }

    if (pid2 < 0)
    {
        printf("Pid2 Fail");
    }

    if ((pid1 != 0) && (pid2 != 0))
    {
        pid3 = fork();
    }

    if (pid3 < 0)
    {
        printf("Pid3 Fail");
    }

    if (pid1 == 0 || pid2 == 0 || pid3 == 0)
    {
        execl("/home/ahn/Documents/Practice/C-Practice/count", "./count", NULL);
    }
    else
    {
        int status;
        for (int i = 0; i < 3; i++)
        {
            pid0 = wait(&status);
        }
    }
}