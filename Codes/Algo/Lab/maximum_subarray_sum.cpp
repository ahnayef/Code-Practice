//This code has not been done in the lab

#include <bits/stdc++.h>
using namespace std;

int MSA(int arr[], int n)
{
    int ans = -9999;
    for (int start = 0; start < n; start++)
    {
        int sum = 0;
        for (int SAsize = 1; SAsize <= n; SAsize++)
        {
            if (start + SAsize > n)
            {
                break;
            }
            sum += arr[start + SAsize - 1];
            ans = max(ans, sum);
        }
    }
    return ans;
}

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

    cout << MSA(arr, len);

    return 0;
}
