#include <iostream>
using namespace std;

int main()
{

    int n, t;
    cin >> t;

    while (t--)
    {

        cin >> n;
        int arr[n];
        int match[n];

        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        for (int i = 0; i < n; i++)
        {
            match[i] = 0;
        }

        // 11 13 11 11

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (arr[i] == arr[j])
                {
                    // cout << arr[i] << " : " << arr[j] << endl;
                    match[i] += 1;
                }
            }
        }

        for (int i = 0; i < n; i++)
        {
            if (match[i] == 1)
            {
                cout << (i + 1) << endl;
                break;
            }
        }
    }

    return 0;
}