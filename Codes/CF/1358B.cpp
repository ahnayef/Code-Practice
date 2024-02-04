#include <bits/stdc++.h>
using namespace std;

int main()
{

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        int *arr = new int[2 * n];

        for (int i = 0; i < 2 * n; i++)
        {
            cin >> arr[i];
        }

        for (int i = 0; i < 2 * n; i++)
        {
            for (int j = i + 1; j < 2 * n; j++)
            {
                if (arr[i] == arr[j])
                {
                    arr[j] = -1;
                }
            }
        }

        for (int i = 0; i < 2 * n; i++)
        {
            if (arr[i] != -1)
            {
                cout << arr[i] << " ";
            }
        }
        cout << endl;
    }
    return 0;
}