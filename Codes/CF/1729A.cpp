#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int a, b, c;

        cin >> a >> b >> c;

        int timeA = a - 1, timeB = (abs(b - c)) + (c - 1);

        if (timeA < timeB)
        {
            cout << 1 << endl;
        }
        else if (timeB < timeA)
        {
            cout << 2 << endl;
        }
        else
        {
            cout << 3 << endl;
        }
    }
    return 0;
}