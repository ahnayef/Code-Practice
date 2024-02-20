#include <bits/stdc++.h>
using namespace std;

int main()
{

    long long int n, ice, d = 0;

    cin >> n >> ice;

    for (int i = 0; i < n; i++)
    {
        char c;
        long long int  m;
        cin >> c >> m;

        if (c == '+')
        {
            ice += m;
        }
        else if (c == '-' && ice - m >= 0)
        {
            ice -= m;
        }
        else
        {
            d++;
        }
    }

    cout << ice << " " << d << endl;

    return 0;
}