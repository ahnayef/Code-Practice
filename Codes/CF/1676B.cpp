#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, min, eat = 0;
        cin >> n;

        int arr[n];

        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        min = arr[0];

        for (int i = 0; i < n; i++)
        {
            if (arr[i] < min)
            {
                min = arr[i];
            }
        }

        for (int i = 0; i < n; i++)
        {
            eat += arr[i] - min;
        }
        cout << eat << endl;
    }

    return 0;
}