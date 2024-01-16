// https://codeforces.com/contest/707/problem/C

#include <iostream>
using namespace std;

int main()
{

    long a, b, c;
    cin >> a;
    if (a == 1)
    {
        cout << -1;
    }

    else if (a % 2 == 0)
    {
        b =  ((a / 2.0) * (a / 2.0)) - 1;
        c = ((a / 2.0) * (a / 2.0)) + 1;
        cout << b << " " << c;
    }
    else
    {
        b =  ((a * a) / 2.0) - 0.5;
        c = ((a * a) / 2.0) + 0.5;
        cout << b << " " << c;
    }

    return 0;
}