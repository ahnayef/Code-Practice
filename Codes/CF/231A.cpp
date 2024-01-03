#include <iostream>
using namespace std;

int main()
{
    int t, toSolve = 0;
    cin >> t;
    while (t--)
    {
        int arr[3], sum = 0;
        for (int i = 0; i < 3; i++)
        {
            cin >> arr[i];
        }

        for (int i = 0; i < 3; i++)
        {
            sum += arr[i];
        }
        if (sum >= 2)
        {
            toSolve++;
        }
    }

    cout << toSolve;

    return 0;
}