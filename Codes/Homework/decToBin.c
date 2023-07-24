#include <stdio.h>

int decToBin(int num)
{

    int arrLen = 0;

    int dec = num;

    while (dec != 0)
    {
        dec /= 2;
        arrLen += 1;
    }

    int arr[arrLen];

    int dec2 = num;

    int i = 0;

    while (dec2 != 0)
    {
        arr[i] = dec2 % 2;
        dec2 /= 2;
        i++;
    }

    int revArr[arrLen];

    int arrLen2 = arrLen - 1;

    for (int k = 0; k < arrLen; k++)
    {
        revArr[arrLen2] = arr[k];
        arrLen2--;
    }

    for (int m = 0; m < arrLen; m++)
    {
        printf("%d",revArr[m]);
    }
    

    // return revArr;
}

int main()
{

    int dec;
    printf("Enter a decimal number:");
    scanf("%d", &dec);
    decToBin(dec);

    // printf("%d",104/2);
}