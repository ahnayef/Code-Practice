#include <iostream>
using namespace std;

void insertionSort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

int main()
{
    int t, possible = 1;
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

        if (n == 1)
        {
            cout << "YES" << endl;
        }
        else
        {
            insertionSort(arr, n);

            for (int i = 0; i < n - 1; i++)
            {

                if ((arr[i + 1] - arr[i]) > 1)
                {
                    possible = 0;
                    break;
                }
                else
                {
                    possible = 1;
                }
            }

            if (possible)
            {
                cout << "YES" << endl;
            }
            else
            {
                cout << "NO" << endl;
            }
        }
    }

    return 0;
}