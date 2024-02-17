#include <bits/stdc++.h>
using namespace std;

int main()
{
    int len, maxSum = -999999;
    cout << "Enter array length: ";
    cin >> len;

    int arr[len];
    cout << "Enter " << len << " element: ";
    for (int i = 0; i < len; i++)
    {
        cin >> arr[i];
    }

    for (int i = 0; i < len; i++)
    {
        int sum = 0;

        for (int j = i; j < len; j++)
        {
            sum += arr[j];
        }
        maxSum = max(maxSum, sum);
    }

    cout << maxSum;

    return 0;
}
