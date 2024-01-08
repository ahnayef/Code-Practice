#include <iostream>
using namespace std;

int main()
{
    int a, b, c;
    cin >> a >> b >> c;

    int d1, d2, d3;

    d1 = abs(a - c) + abs(b - c);
    d2 = abs(a - b) + abs(c - b);
    d3 = abs(b - a) + abs(c - a);

    if (d1 < d2 && d1 < d3)
    {
        cout << d1;
    }
    else if (d2 < d1 && d2 < d3)
    {
        cout << d2;
    }
    else
    {
        cout << d3;
    }

    return 0;
}