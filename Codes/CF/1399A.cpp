#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, len = 0;
        cin >> n;
        int total = n;
        int arr[n];

        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {

                if (arr[j + 1] > arr[j] || arr[j + 1] == arr[j])
                {
                    if ((arr[j + 1] - arr[j]) == 0 || (arr[j + 1] - arr[j]) == 1)
                    {
                        arr[j] = 0;
                    }
                }
                else
                {
                    if ((arr[j] - arr[j + 1]) == 0 || (arr[j] - arr[j + 1]) == 1)
                    {
                        arr[j + 1] = 0;
                    }
                }
            }
        }

        for (int i = 0; i < n; i++)
        {
            if (arr[i] != 0)
            {
                len++;
            }
        }

        if (len == 1)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }

    return 0;
}