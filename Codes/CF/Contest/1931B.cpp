#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        int *arr = new int[n];
        int sum = 0;

        for (int i = 0; i < n; ++i)
        {
            cin >> arr[i];
            sum += arr[i];
        }

        int make = sum / n;
        bool possible = true;
        for (int i = 0; i < n; ++i)
        {
            if (arr[i] > make)
            {
                if (i + 1 < n)
                {
                    int diff = arr[i] - make;
                    arr[i] -= diff;
                    arr[i + 1] += diff;
                }
                else
                {
                    possible = false;
                    break;
                }
            }
            else if (arr[i] < make)
            {
                possible = false;
                break;
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

    return 0;
}