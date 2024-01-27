#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, subCount = 0, subLength = 1, track = 0;
    cin >> n;

    int *arr = new int[n];

    if (n == 1)
    {
        cout << 1;
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        for (int i = 0; i < n - 1; i++)
        {
            if (arr[i] > arr[i + 1])
            {
                subLength++;
            }
        }

        int *subArr = new int[subLength];

        for (int i = 0; i < n - 1; i++)
        {
            if (arr[i] < arr[i + 1])
            {
                subCount++;
            }
            else
            {
                subArr[track] = subCount;
                track++;
                subCount = 0;
            }
            subArr[track] = subCount;
        }

        cout << *max_element(subArr, subArr + subLength) + 1;
    }

    return 0;
}