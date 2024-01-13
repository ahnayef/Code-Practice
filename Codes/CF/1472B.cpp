#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, count1 = 0, count2 = 0;
        cin >> n;

        int arr[n];

        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        if (n <= 2)
        {
            if (arr[0] == arr[1])
            {
                cout << "YES" << endl;
            }
            else
            {
                cout << "NO" << endl;
            }
        }
        else
        {
            for (int i = 0; i < n; i++)
            {
                if (arr[i] == 1)
                {
                    count1++;
                }
                else if (arr[i] == 2)
                {
                    count2++;
                }
            }

            // cout << "Count1: " << count1 << " Count2: " << count2 << endl;

            if (!count1)
            {
                // cout << "Enter !count1" << endl;
                if (count2 % 2 == 0)
                {
                    cout << "YES" << endl;
                }
                else
                {
                    cout << "NO" << endl;
                }
            }
            else if (!count2)
            {
                // cout << "Enter !count1";

                if (count1 % 2 == 0)
                {
                    cout << "YES" << endl;
                }
                else
                {
                    cout << "NO" << endl;
                }
            }
            else if (count1 == count2)
            {
                cout << "YES" << endl;
            }
            else
            {
                cout << "NO" << endl;
            }

            count1 = count2 = 0;
        }
    }

    return 0;
}