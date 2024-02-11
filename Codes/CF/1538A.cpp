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
    }
    return 0;
}