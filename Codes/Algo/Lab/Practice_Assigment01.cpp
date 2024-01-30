#include <bits/stdc++.h>
using namespace std;

void removeMax(int arr[], int arr2[], int len)
{
    int maxIndex = len - 1;

    for (int i = (len - 1); i >= 0; i--)
    {
        if (arr2[i] > arr2[maxIndex])
        {
            maxIndex = i;
        }
    }

    arr[maxIndex] = -1;
    arr2[maxIndex] = -1;
}

int main()
{
    int n, k, target;
    cout << "Enter array length: ";
    cin >> n;

    int *arr = new int[n];
    int *arr2 = new int[n];

    cout << "Enter " << n << " elements: ";

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "k:  ";
    cin >> k;

    cout << "target:  ";
    cin >> target;

    if (arr[0] > target)
    {
        for (int i = 0; i < k; i++)
        {
            cout << arr[i] << " ";
        }
    }
    else if (arr[n - 1] < target)
    {
        for (int i = n - k; i < n; i++)
        {
            cout << arr[i] << " ";
        }
    }
    else
    {

        for (int i = 0; i < n; i++)
        {
            arr2[i] = abs(target - arr[i]);
        }

        for (int i = 0; i < (n - k); i++)
        {
            removeMax(arr, arr2, n);
        }

        for (int i = 0; i < n; i++)
        {
            if (arr[i] != -1)
            {
                cout << arr[i] << " ";
            }
        }
    }

    return 0;
}