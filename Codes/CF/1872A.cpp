#include <bits/stdc++.h>
using namespace std;

int main()
{

    int t;
    cin >> t;

    while (t--)
    {
        int a, b;
        float c;

        cin >> a >> b >> c;

        c = 2 * c;

        cout << ceil(abs(a - b) / c) << endl;
    }
    return 0;
}