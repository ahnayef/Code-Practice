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
        int maxNum = max({a, b, c});
        
        if (maxNum == a && maxNum == b && maxNum == c)
        {
            a = 1, b = 1, c = 1;
        }
        else if (a == maxNum && b == maxNum)
        {

            a = 1, b = 1, c = (maxNum - c + 1);
        }
        else if (b == maxNum && c == maxNum)
        {

            b = 1, c = 1, a = (maxNum - a + 1);
        }
        else if (a == maxNum && c == maxNum)
        {

            a = 1, c = 1, b = (maxNum - b + 1);
        }
        else if (maxNum == a)
        {

            a = 0, b = (maxNum - b + 1), c = (maxNum - c + 1);
        }
        else if (maxNum == b)
        {

            b = 0, a = (maxNum - a + 1), c = (maxNum - c + 1);
        }
        else if (maxNum == c)
        {

            c = 0, a = (maxNum - a + 1), b = (maxNum - b + 1);
        }
        cout << a << " " << b << " " << c << endl;
    }
    return 0;
}