#include <bits/stdc++.h>
using namespace std;

int partition(int arr[], int l, int r)
{
    int pv = arr[l];
    int p = l + 1;
    int q = r;

    while (p <= q)
    {
        while (true)
        {
            if (arr[p] > pv)
                break;

            p++;
        }
        while (true)
        {
            if (arr[q] <= pv)
                break;

            q--;
        }

        if (p <= q)
            swap(arr[p], arr[q]);
    }

    swap(arr[q], arr[l]); // arr[l] = pv

    return q;
}

void quickSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int j = partition(arr, l, r);
        quickSort(arr, l, j - 1);
        quickSort(arr, j + 1, r);
    }
}

int main()
{

    int len;
    cout << "Enter array length: ";
    cin >> len;

    int arr[len];

    cout << "Enter " << len << " element: ";

    for (int i = 0; i < len; i++)
    {
        cin >> arr[i];
    }

    quickSort(arr, 0, len - 1);

    cout << "Sorted array: ";
    for (int i = 0; i < len; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}