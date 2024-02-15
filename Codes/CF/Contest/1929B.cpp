#include <bits/stdc++.h>
using namespace std;

int main()
{

    int t;
    cin >> t;

    while (t--)
    {
        int n, k, d;
        cin >> n >> k;

        d = 4 * n - 2;

        if (k == d)
        {
            cout << ceil(k / 2.0) + n/2 << endl;
        }
        else
        {
            cout << ceil(k / 2.0) << endl;
        }
    }
    return 0;
}