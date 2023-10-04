#include <stdio.h>

#define len 5 // Constant

int arr[len]; // Array len = 5
int top = -1;

void push(int data)
{
    if (top < len - 1)
    {
        top++;
        arr[top] = data;
        printf("Push: %d\n", data);
    }
    else
    {
        printf("Stack overflow!\n");
    }
}

void pop()
{
    if (top > -1)
    {
        printf("Pop: %d\n", arr[top]);
        arr[top] = -1;
        top--;
    }
    else
    {
        printf("Stack underflow!\n");
    }
}

void TOP() // can't name it 'top' bacause of the global variable 🙃
{
    printf("Top: %d\n", arr[top]); // Printing element instead of index. You can return index but you'll have to print it while calling the function. I'll demonstrate it with top2() function.
}

// Top() - 2nd aproach:

int top2()
{
    return top;
}

int main()
{

    push(3);
    push(2);
    TOP();
    push(5);
    TOP();
    pop();
    TOP();
    pop();
    TOP();
    pop();
    printf("Top %d\n", arr[top2()]); // makes things messy

    return 0;
}
