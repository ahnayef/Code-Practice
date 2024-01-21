#include <bits/stdc++.h>
#include <array>
using namespace std;

void regularBubbleSort(int arr[], int len)
{
    int stepCount = 0, swapCount = 0;
    for (int i = 0; i < len - 1; i++)
    {
        for (int j = 0; j < len - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                swapCount++;
            }
        }
        stepCount++;
    }

    cout << "Steps: " << stepCount << endl
         << "Swaps: " << swapCount << endl;
}

void bubbleSortWithEarlyStop(int arr[], int len)
{
    int stepCount = 0, swapCount = 0;
    bool swaped;

    for (int i = 0; i < len - 1; i++)
    {
        swaped = false;

        for (int j = 0; j < len - i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                swaped = true;
                swapCount++;
            }
        }

        if (!swaped)
            break;

        stepCount++;
    }

    cout << "Steps: " << stepCount << endl
         << "Swaps: " << swapCount << endl;
}

int main()
{
    int arr[] = {10, 30, 100, 90, 50};

    regularBubbleSort(arr, 5);

    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << " ";
    }

    cout << endl
         << endl;

    int arr2[] = {10, 30, 100, 90, 50};

    bubbleSortWithEarlyStop(arr2, 5);

    for (int i = 0; i < 5; i++)
    {
        cout << arr2[i] << " ";
    }

    return 0;
}