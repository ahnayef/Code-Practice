#include <stdio.h>
#include <math.h>

void isPerfect(int n)
{
    int res = 0;

    for (int i = n - 1; i > 0; i--)
    {
        if (n % i == 0)
        {
            res += i;
        }
    }

    if (res == n)
    {
        printf("The %d is a Perfect number.\n", n);
    }
    else
    {
        printf("The %d is not a Perfect number.\n", n);
    }
}

void isArmstrong(int n)
{

    int length = 0;
    int tempNum = n;
    int res = 0;

    while (tempNum != 0)
    {
        tempNum = tempNum / 10;
        ++length;
    }

    int out = n;
    int peek = 0;

    for (int i = 1; i <= length; i++)
    {
        peek = out % 10;
        res += pow(peek, length);
        out /= 10;
    }

    if (res == n)
    {
        printf("The %d is an Armstrong number.\n", n);
    }
    else
    {
        printf("The %d is not an Armstrong number.\n", n);
    }
}

int main()
{
    int number;
    printf("Input any number: ");
    scanf("%d", &number);
    isArmstrong(number);
    isPerfect(number);
}
