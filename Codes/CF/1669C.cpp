#include <bits/stdc++.h>
using namespace std;

int main()
{

    int t;
    cin >> t;

    while (t--)
    {
        int n, oddOddCount = 0, oddEvenCount = 0, evenOddCount = 0, evenEvenCount = 0;
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

        else if (n == 2)
        {
            if ((arr[0] % 2 == 0 && arr[1] % 2 != 0) || (arr[1] % 2 == 0 && arr[0] % 2 != 0))
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
                if (i % 2 == 0)
                {
                    if (i % 2 == 0)
                    {
                        oddOddCount++;
                    }
                    else
                    {
                        oddEvenCount++;
                    }
                }
                else
                {
                    if (i % 2 == 0)
                    {
                        evenOddCount++;
                    }
                    else
                    {
                        evenEvenCount++;
                    }
                }
            }

            if (((oddOddCount == 0 && oddEvenCount == n / 2) || (oddEvenCount == 0 && oddOddCount == n / 2)) && ((evenOddCount == 0 && evenEvenCount == n / 2) || (evenEvenCount == 0 && evenOddCount == n / 2)))
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