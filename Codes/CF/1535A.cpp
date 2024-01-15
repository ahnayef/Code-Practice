#include <iostream>
using namespace std;

int main()
{

    int t;
    cin >> t;

    while (t--)
    {
        int arr[4], max1, max2, max1i, max2i;

        for (int i = 0; i < 4; i++)
        {
            cin >> arr[i];
        }

        max1 = arr[0] > arr[1] ? arr[0] : arr[1];
        max1i = arr[0] > arr[1] ? 1 : 0;

        max2 = arr[2] > arr[3] ? arr[2] : arr[3];
        max2i = arr[2] > arr[3] ? 3 : 2;

        if (max2 > max1)
        {
            if (max1 > arr[max2i])
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
            if (max2 > arr[max1i])
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

// 4 5 6 9

//   5   9