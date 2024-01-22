#include <bits/stdc++.h>
using namespace std;

void printArray(int arr[], int len)
{
    cout << endl;
    cout << "Array: ";
    for (int i = 0; i < len; i++)
    {
        cout << " " << arr[i];
    }
    cout << endl;
}

void insertionSortDry(int arr[], int len)
{
    for (int i = 1; i < len; i++)
    {
        printf("Step %d:\n\n", i);
        printf("i = %d, i < %d:\n\n", i, len);

        int key = arr[i];
        printf("key = arr[%d] = %d\n", i, key);

        int j = i - 1;
        printf("j = %d - 1 = %d\n\n", i, j);

        while (j >= 0 && arr[j] > key)
        {
            printf("\t(j (%d) >= 0 && arr[%d] = %d > key = %d)\n\n", j, j, arr[j], key);

            printf("\tarr[%d + 1] = arr[%d] = arr[%d] = %d\n\n", j, j + 1, j, arr[j]);
            arr[j + 1] = arr[j];
            printf("\tj = j -1 = %d-1 = %d\n\n\n", j, (j - 1));
            j--;
        }
        printf("arr[j + 1] = arr[%d + 1] = arr[%d] = key (%d)", j, (j + 1), key);
        arr[j + 1] = key;
        printArray(arr, i + 1);

        cout << "\n\n------------\n\n";
    }
}

int main()
{
    int len;
    cout << "Length: ";
    cin >> len;

    int arr[len];

    cout << "Enter " << len << " element:";

    for (int i = 0; i < len; i++)
    {
        cin >> arr[i];
    }

    cout << endl;

    insertionSortDry(arr, len);

    return 0;
}