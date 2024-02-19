#include <bits/stdc++.h>
using namespace std;

int main()
{

    int t;
    cin >> t;

    while (t--)
    {
        int n, sq = 1;
        cin >> n;
        string s[n];

        for (int i = 0; i < n; i++)
        {
            cin >> s[i];
        }

        for (int i = 0; i < n - 1; i++)
        {
            if (s[i].find('1') != string::npos)
            {
                if (s[i].compare(s[i + 1]) != 0)
                {
                    sq = 0;
                }
            }
        }

        if (sq)
        {
            cout << "SQUARE" << endl;
        }
        else
        {
            cout << "TRIANGLE" << endl;
        }
    }
    return 0;
}