#include <bits/stdc++.h>
using namespace std;

int main()
{

    int t;
    cin >> t;

    while (t--)
    {
        long a, b, n, i = 0;
        cin >> a >> b >> n;

        while (b <= n || a <= n)
        {

            cout << a << " " << b << " = " << abs(a - b) << endl;
            if (a < b)
            {
                a += b;
                i++;
            }
            else if (b < a)
            {
                b += a;
                i++;
            }
            else
            {
                a += b;
                i++;
            }
        }
        cout << i - 1 << endl;
    }
    return 0;
}

/*
a b

5 4
9 4
13 4
17 4
21 4


a b
5 4

5 9
14 9
14 23


1 1 2 3 5 8 13 21 

*/