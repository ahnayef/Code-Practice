#include <iostream>
using namespace std;

void insertionSort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] < key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

int main()
{
    int n, s = 0, d = 0;
    cin >> n;
    int arr[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    insertionSort(arr, n);

    for (int i = 0; i < n; i++)
    {
        if (i % 2 != 0)
        {
            cout << arr[i] << " ";
        }
    }

    /*
        for (int i = 0; i < n; i++)
        {
            if (i % 2 == 0)
            {
                s += arr[i];
            }
            else
            {
                d += arr[i];
            }
        }

        cout << s << " " << d;


        */

    return 0;
}

// 0 1 2 3 4 5 6
// 7 6 5 4 3 2 1

// 00 01 02 03 04 05 06 07 08 09 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 33 34 35 36 37 38 39 40 41

// 48 47 45 44 43 42 41 40 39 38 37 36 35 33 32 31 29 28 27 26 25 24 22 21 20 19 18 17 16 15 14 13 12 11 09 08 07 06 05 04 03 01

// s: 48 45 43 41 39 37 35 32 29 27 25 22 20 18 16 14 12 9 7 5 3

// b: 47 44 42 40 38 36 33 31 28 26 24 21 19 17 15 13 11 8 6 4 1

//  47  44  42  40  38  36  33  31  28  26  24  21  19  17  15  13  11  08  06  04  01
