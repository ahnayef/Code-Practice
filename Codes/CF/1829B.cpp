#include <bits/stdc++.h>
using namespace std;

int main()
{

    int t;
    cin >> t;

    while (t--)
    {
        int n, max = 0, current = 0;
        cin >> n;
        int *arr = new int[n];

        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        for (int i = 0; i < n; i++)
        {
            if (arr[i] == 0)
            {
                current++;
            }
            else
            {
                if (current >= max)
                {
                    max = current;
                    current = 0;
                }
                current = 0;
            }
        }

        if (current > max)
        {
            cout << current << endl;
        }
        else
        {
            cout << max << endl;
        }
    }
    return 0;
}