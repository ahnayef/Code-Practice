#include <bits/stdc++.h>
using namespace std;

int binarySearch(int arr[], int l, int r, int x)
{
    while (l <= r)
    {
        int m = l + (r - l) / 2;

        if (arr[m] == x)
            return m;

        if (arr[m] < x)
            l = m + 1;

        else
            r = m - 1;
    }

    return -1;
}

int main()
{

    int t;
    cin >> t;

    while (t--)
    {
        int n, m, k;
        cin >> n >> m >> k;

        int *arr1 = new int[n];
        int *arr2 = new int[m];
        int *arr3 = new int[k];

        for (int i = 0; i < n; i++)
        {
            cin >> arr1[i];
        }
        for (int i = 0; i < m; i++)
        {
            cin >> arr2[i];
        }

        sort(arr1, arr1 + n);
        sort(arr2, arr2 + m);

        int target = 6;
        int arr1Penalty = 1;
        int arr2Penalty = 1;

        for (int i = 0; i < k && target > 0; i++)
        {
            int findArr1 = binarySearch(arr1, 0, n - 1, target);
            int findArr2 = binarySearch(arr2, 0, m - 1, target);

            if (findArr1 != -1 && arr1Penalty < 4)
            {
                arr1Penalty++;
                target--;
            }
            else if (findArr2 != -1 && arr2Penalty < 4)
            {
                arr2Penalty++;
                target--;
            }
            else
            {
                cout << "NO";
                break;
            }
        }

        cout << arr1Penalty << endl;
        cout << arr2Penalty << endl;
        cout << target;

        // for (int i = 0; i < k; i++)
        // {
        //     cout << arr3[i] << " ";
        // }
    }
    return 0;
}