#include <bits/stdc++.h>
using namespace std;

int main()
{

    int t;
    cin >> t;

    while (t--)
    {
        int n, res = 1;
        cin >> n;

        int *arr = new int[n];

        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        int min = arr[0], minIndex = 0;

        for (int i = 0; i < n; i++)
        {
            if (arr[i] < min)
            {
                min = arr[i];
                minIndex = i;
            }
        }

        arr[minIndex] = arr[minIndex] + 1;

        for (int i = 0; i < n; i++)
        {
            res *= arr[i];
        }

        cout << res << endl;
    }

    return 0;
}