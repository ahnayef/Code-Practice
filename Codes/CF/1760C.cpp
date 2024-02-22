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

        int *arr = new int[n];
        int *arr2 = new int[n];
        for (int i = 0; i < n; i++)
        {
            int num;
            cin >> num;
            arr[i] = arr2[i] = num;
        }

        sort(arr2, arr2 + n);

        for (int i = 0; i < n; i++)
        {
            if (arr[i] == arr2[n - 1])
            {
                cout << arr[i] - arr2[n - 2] << " ";
            }
            else
            {
                cout << arr[i] - arr2[n - 1] << " ";
            }
        }

        cout << endl;
    }
    return 0;
}