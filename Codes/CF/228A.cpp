#include <iostream>
using namespace std;

int main()
{
    long long int arr[4];
    int d = 0;

    for (int i = 0; i < 4; i++)
    {
        cin >> arr[i];
    }

    for (int i = 0; i < 4; i++)
    {
        for (int j = i + 1; j < 4; j++)
        {
            if (arr[i] == arr[j])
            {
                arr[i] = 0;
            }
        }
    }

    for (int i = 0; i < 4; i++)
    {
        if (arr[i] == 0)
        {
            d++;
        }
    }

    // for (int i = 0; i < 4; i++)
    // {
    //     cout << arr[i];
    // }

    cout << d;

    return 0;
}