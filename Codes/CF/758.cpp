#include <iostream>
using namespace std;

int main()
{
    int n, total = 0;

    cin >> n;

    int arr[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int max = arr[0];

    for (int i = 0; i < n; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }

    for (int i = 0; i < n; i++)
    {
        total += max - arr[i];
    }

    // cout << max << endl;
    cout << total;

    return 0;
}