#include <bits/stdc++.h>
using namespace std;

int countDistinct(int arr[], int n)
{
    int res = 1;

    for (int i = 1; i < n; i++)
    {
        int j = 0;
        for (j = 0; j < i; j++)
            if (arr[i] == arr[j])
                break;

        if (i == j)
            res++;
    }
    return res;
}

int main()
{

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        int arr[n];

        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        int distinc = countDistinct(arr, n);

        if ((n - distinc) % 2 == 0)
        {
            cout << distinc << endl;
        }
        else
        {
            cout << distinc - 1 << endl;
        }
    }
    return 0;
}