//  1st class task

#include <bits/stdc++.h>
using namespace std;

// void regularBubbleSort(int arr[], int len)
// {
//     for (int i = 0; i < len - 1; i++)
//     {
//         for (int j = 0; j < len - i - 1; j++)
//         {
//             if (arr[j] > arr[j + 1])
//             {
//                 swap(arr[j], arr[j + 1]);
//             }
//         }
//     }
// }

void printArray(int arr[], int len)
{
    cout << endl;
    cout << "Array: ";
    for (int i = 0; i < len; i++)
    {
        cout << " " << arr[i];
    }
    cout << endl;
}

void bubbleSortWithEarlyStop(int arr[], int len)
{
    bool swaped;

    for (int i = 0; i < len - 1; i++)
    {
        printf("Step %d:\n\n", i + 1);
        printf("i = %d, i < %d:\n\n", i, len);

        swaped = false;

        printf("Swaped = %s\n\n", swaped ? "True" : "False");

        for (int j = 0; j < len - i - 1; j++)
        {
            printf("\tj = %d, j < %d:\n\n", j, len - i - 1);

            printf("\t %d > %d : %s\n\n", arr[j], arr[j + 1], (arr[j] > arr[j + 1]) ? "True\n\t(Enter into the loop)" : "False\n\t(Don't enter the loop)");
            if (arr[j] > arr[j + 1])
            {
                printf("\t\tswap(%d,%d)\n\n", arr[j], arr[j + 1]);
                swap(arr[j], arr[j + 1]);
                swaped = true;
                printf("\t\tSwaped = %s\n\n", swaped ? "True" : "False");
            }
        }

        if (!swaped)
        {
            cout << "\tbreak;";
            break;
        }
        printArray(arr, len);
        cout << "\n-------------\n";
    }
}

int main()
{

    int len;
    cout << "Length: ";
    cin >> len;

    int *arr = new int[len];

    cout << "Enter " << len << " element:";

    for (int i = 0; i < len; i++)
    {
        cin >> arr[i];
    }

    bubbleSortWithEarlyStop(arr, 5);

    return 0;
}