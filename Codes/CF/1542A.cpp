#include <iostream>
using namespace std;

int main()
{

    int t;
    cin >> t;

    while (t--)
    {
        int n, evenCount = 0;
        cin >> n;

        int arr[2 * n];

        for (int i = 0; i < n * 2; i++)
        {
            cin >> arr[i];
        }

        for (int i = 0; i < n * 2; i++)
        {
            if (arr[i] % 2 == 0)
            {
                evenCount++;
            }
        }

        if (evenCount == n)
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