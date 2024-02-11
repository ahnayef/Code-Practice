#include <bits/stdc++.h>
using namespace std;

int main()
{

    int t, maxElement, minElement;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        int *arr = new int[n];
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        maxElement = max_element(arr, arr + n) - arr;
        minElement = min_element(arr, arr + n) - arr;

        /*

        if (maxElement > n / 2 && minElement > n / 2)
        {
            if (maxElement > minElement)
            {
                cout << n - minElement << endl;
            }
            else
            {
                cout << n - maxElement;
            }
        }
        else if (maxElement < n / 2 && minElement < n / 2)
        {
            if (maxElement > minElement)
            {
                cout << maxElement + 1 << endl;
            }
            else
            {
                cout << minElement + 1 << endl;
            }
        }
        else if (maxElement == n / 2)
        {
            if (maxElement > minElement)
            {
                cout << maxElement + 1 << endl;
            }
            else
            {
                if (n - minElement < minElement - maxElement)
                {
                    cout << maxElement + 1 + (n - minElement) << endl;
                }
                else
                {
                    cout << minElement + 1 << endl;
                }
            }
        }
        else if (minElement == n / 2)
        {
            if (minElement > maxElement)
            {
                cout << minElement + 1 << endl;
            }
            else
            {
                if (n - maxElement < maxElement - minElement)
                {
                    cout << minElement + 1 + (n - maxElement) << endl;
                }
                else
                {
                    cout << maxElement + 1 << endl;
                }
            }
        }
        else if (maxElement > n / 2 && minElement < n / 2)
        {
            if (n - maxElement < maxElement - minElement)
            {
                cout << minElement + 1 + (n - maxElement) << endl;
            }
            else
            {
                cout << maxElement + 1 << endl;
            }
        }
        else
        {
            if (n - minElement < minElement - maxElement)
            {
                cout << maxElement + 1 + (n - minElement) << endl;
            }
            else
            {
                cout << minElement + 1 << endl;
            }
        }
        */

        int removeFromRight = (n - minElement) + (n - maxElement);
        int removeFromLeft = (minElement + 1) + (maxElement + 1);
        int rightSmall = (n - minElement) + (maxElement + 1);
        int leftSmall = (minElement + 1) + (maxElement - n);

        int arr2[4] = {removeFromRight, rightSmall, removeFromLeft, leftSmall};

        cout << *min_element(arr2, arr2 + 4) << endl;
    }
    return 0;
}