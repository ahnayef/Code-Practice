#include <bits/stdc++.h>
using namespace std;

bool isPowerOf10(unsigned long long num)
{
    switch (num)
    {
    case 1:
    case 10:
    case 100:
    case 1000:
    case 10000:
    case 100000:
    case 1000000:
    case 10000000:
    case 100000000:
    case 1000000000:
        return true;
    default:
        return false;
    }
}

int main()
{

    int t;
    cin >> t;

    while (t--)
    {
        int n, r = 1;
        cin >> n;

        if (isPowerOf10(n))
        {
            cout << 0 << endl;
        }
        else
        {
            while (r < n)
            {
                r *= 10;
            }

            cout << n - (r / 10) << endl;
        }
    }

    return 0;
}