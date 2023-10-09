#include <stdio.h>
#include <stdlib.h>

#define size 5 // Constant

int stack[size]; // Array size/length = 5
int top = -1;

int isFull()
{
    if (top == size - 1)
    {
        return 1;
    }
    return 0;
}

int isEmpty()
{
    if (top == -1)
    {
        return 1;
    }
    return 0;
}

void push(int data)
{

    if (isFull())
    {
        printf("Stack overflow!\n");
        return;
    }
    top++;
    stack[top] = data;
}

int pop()
{

    if (isEmpty())
    {
        printf("Stack underflow!\n");
        exit(1);
    }
    int del_data = stack[top];
    top--;
    return del_data;
}

void TOP() // can't name it 'top' bacause of the global variable 🙃
{
    printf("Top: %d\n", stack[top]); // Printing element instead of index. You can return index but you'll have to print it while calling the function. I'll demonstrate it with top2() function.
}

// Top() - 2nd aproach:

int top2()
{
    return top;
}

void print()
{
    for (int i = 0; i <= top; i++)
    {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

int main()
{

    // push(3);
    // push(2);
    // TOP();
    // push(5);
    // TOP();
    // pop();
    // TOP();
    // pop();
    // TOP();
    // pop();
    // print();

    push(10);
    push(20);
    push(30);
    pop();
    push(40);
    printf("pop %d\n", pop());
    print(); // It's not printf
    TOP();
    push(50);
    print(); 
    printf("Top %d\n", stack[top2()]); // makes things messy

    return 0;
}
