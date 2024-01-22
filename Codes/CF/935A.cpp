#include <bits/stdc++.h>
using namespace std;

int main()
{

    int n, i = 2, res = 0;
    cin >> n;

    if (n == 2)
    {
        cout << 1;
    }
    else
    {

        int tmp = n / 2;
        while (tmp > 0)
        {
            if ((n - i) % i == 0)
            {
                res++;
            }
            i++;
            tmp--;
        }

        cout << res + 1;
    }

    return 0;
}