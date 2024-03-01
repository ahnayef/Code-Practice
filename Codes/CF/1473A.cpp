#include <bits/stdc++.h>
using namespace std;

int main()
{

    int t;
    cin >> t;

    while (t--)
    {
        int n, d, less = 1, can = 0;
        cin >> n >> d;
        int arr[n];

        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        for (int i = 0; i < n; i++)
        {
            if (arr[i] > d)
            {
                less = 0;
            }
        }

        if (!less)
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = i + 1; j < n; j++)
                {
                    if (arr[i] + arr[j] <= d)
                    {
                        can = 1;
                        break;
                    }
                }
            }
        }

        if (less)
        {
            cout << "YES" << endl;
        }
        else if (can)
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