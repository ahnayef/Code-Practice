#include <bits/stdc++.h>
using namespace std;

int main()
{

    int t;
    cin >> t;

    while (t--)
    {
        int n, totalEven = 0, totalOdd = 0;

        cin >> n;

        int *arr = new int[n];

        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        for (int i = 0; i < n; i++)
        {
            if (arr[i] % 2 == 0)
            {
                totalEven += arr[i];
            }
        }
        for (int i = 0; i < n; i++)
        {
            if (arr[i] % 2 != 0)
            {
                totalOdd += arr[i];
            }
        }

        if (totalEven > totalOdd)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}