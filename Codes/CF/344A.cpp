#include <iostream>
using namespace std;

int main()
{
    int n, g = 0;
    cin >> n;

    int arr[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    for (int i = 0; i < n; i++)
    {
        if (i == 0)
        {
            g++;
        }
        else if (arr[i] != arr[i - 1])
        {
            g++;
        }
    }

    cout << g;

    return 0;
}