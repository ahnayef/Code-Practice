#include <bits/stdc++.h>
using namespace std;

int main()
{

    int t;
    cin >> t;

    while (t--)
    {
        int n, sum = 0, make, possible = 0;
        cin >> n;
        int *arr = new int[n];

        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        for (int i = 0; i < n; i++)
        {
            sum += arr[i];
        }

        make = sum / n;

        for (int i = n - 1; i >= 0 && arr[i] <= make; i--)
        {
            for (int j = i - 1; j >= 0 && arr[i] < make; j--)
            {
                while (arr[j] > make && arr[i] < make)
                {
                    arr[j] = arr[j] - 1;
                    arr[i] = arr[i] + 1;
                }
            }
        }

        for (int i = 0; i < n; i++)
        {
            if (arr[i] == make)
            {
                possible = 1;
            }
            else
            {
                possible = 0;
                break;
            }
        }

        if (possible)
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


