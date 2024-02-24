#include <bits/stdc++.h>
using namespace std;

void Merge(int arr[], int l, int mid, int r)
{
    int ls = mid - l + 1;
    int rs = r - mid;

    int L_subArray[ls], R_subArray[rs];

    for (int i = 0; i < ls; i++)
    {
        L_subArray[i] = arr[l + i];
    }
    for (int j = 0; j < rs; j++)
    {
        R_subArray[j] = arr[mid + 1 + j];
    }

    int i = 0, j = 0, k = l;

    while (i < ls && j < rs)
    {
        if (L_subArray[i] <= R_subArray[j])
        {
            arr[k] = L_subArray[i];
            i++;
        }
        else
        {
            arr[k] = R_subArray[j];
            j++;
        }

        k++;
    }

    while (i < ls)
    {
        arr[k] = L_subArray[i];
        i++;
        k++;
    }

    while (j < rs)
    {
        arr[k] = R_subArray[j];
        j++;
        k++;
    }
}

void merge_sort(int arr[], int l, int r)
{
    if (l < r)
    {
        int mid = (l + r) / 2;
        merge_sort(arr, l, mid);
        merge_sort(arr, mid + 1, r);
        Merge(arr, l, mid, r);
    }
}

int main()
{
    int n;
    cout << "Enter array length: ";
    cin >> n;
    // int *arr = new int[n];
    int arr[n];

    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    merge_sort(arr, 0, n - 1);

    cout << "Sorted Array: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}
