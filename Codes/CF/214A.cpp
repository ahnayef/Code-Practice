#include <bits/stdc++.h>
using namespace std;

int main()
{

    int m, n, pair = 0;
    cin >> m >> n;

    for (int a = 0; a <= n; a++)
    {
        for (int b = 0; b <= m; b++)
        {
            if ((a * a + b == n) && (a + b * b == m))
            {
                pair++;
            }
        }
    }

    cout << pair;

    return 0;
}