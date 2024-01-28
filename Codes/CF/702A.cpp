#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, subCount = 0, subCount2 = 0;
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
            if (arr[i] < arr[i + 1])
            {
                subCount++;
            }
            else
            {
                if (subCount < subCount2)
                {
                    subCount = 0;
                }
                else
                {
                    subCount2 = subCount;
                    subCount = 0;
                }
            }
        }

        if (subCount2 > subCount)
        {
            cout << subCount2 + 1;
        }
        else
        {
            cout << subCount + 1;
        }
    }

    return 0;
}