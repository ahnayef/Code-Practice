#include <iostream>
using namespace std;

int main()
{
    int n, k, teamMember = 0;

    cin >> n >> k;

    int arr[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    for (int i = 0; i < n; i++)
    {
        if ((5 - arr[i]) >= k)
        {
            teamMember++;
        }
    }

    cout << teamMember / 3;

    return 0;
}