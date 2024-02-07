#include <bits/stdc++.h>
using namespace std;

int main()
{

    int t;
    cin >> t;

    while (t--)
    {
        int a, b,
            c, d,
            e, f,
            g, h,

            res;

        cin >> a >> b >> c >> d >> e >> f >> g >> h;

        if (a == c)
        {
            res = (d - b) * (d - b);
            cout << res << endl;
        }
        else if (a == e)
        {
            res = (f - b) * (f - b);
            cout << res << endl;
        }
        else if (a == g)
        {
            res = (h - b) * (h - b);
            cout << res << endl;
        }
        else if (c == e)
        {
            res = (f - d) * (f - d);
            cout << res << endl;
        }
        else if (c == g)
        {
            res = (h - d) * (h - d);
            cout << res << endl;
        }
        else
        {
            res = (h - f) * (h - f);
            cout << res << endl;
        }
    }
    return 0;
}