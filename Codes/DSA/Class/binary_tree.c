#include <stdio.h>

#include <stdlib.h>

#define MAX 5

char tree[MAX];

void root(char parant)
{
    tree[0] = parant;
}

void left(char child, int parant)
{
    tree[(2 * parant) + 1] = child;
}

void right(char child, int parant)
{
    tree[(2 * parant) + 2] = child;
}

void print()
{
    for (int i = 0; i < MAX; i++)
    {
        if (tree[i] == '\0')
        {
            printf(".");
        }
        else
        {
            printf("%c", tree[i]);
        }
    }
}

int main()
{

    // char t[3];
    // printf("Global: %c\n",tree[0]);
    // printf("Local: %c",t[0]);

    root('A');
    left('B', 0);
    right('C', 0);
    left('D', 1);
    right('E', 1);

    print();
    return 0;
}