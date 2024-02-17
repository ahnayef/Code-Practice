#include <bits/stdc++.h>
using namespace std;

int partition(int arr[], int l, int h)
{
    int p = l;
    int q = h;
    int pivot = arr[l];
    while (p < q)
    {
        while (pivot >= arr[p])
        {
            p++;
        }
        while (pivot < arr[q])
        {
            q--;
        }
        if (p < q)
            swap(arr[p], arr[q]);
    }
    swap(arr[q], arr[l]);
    return q;
}

void quickSort(int arr[], int l, int h)
{
    if (l < h)
    {
        int q = partition(arr, l, h);
        quickSort(arr, l, q - 1);
        quickSort(arr, q + 1, h);
    }
}
int main()
{
    int n;

    cout << "Enter Number of Elements: ";
    
    cin >> n;

    int arr[n];

    cout << "Enter Array Elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    quickSort(arr, 0, n - 1);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}