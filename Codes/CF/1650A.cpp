#include <bits/stdc++.h>
using namespace std;

int main()
{

    int t;
    cin >> t;

    while (t--)
    {
        string s;
        char c;
        int can = 0;

        cin >> s;
        cin >> c;

        for (int i = 0; s[i] != '\0'; i++)
        {
            if (s[i] == c && i % 2 == 0)
            {
                can = 1;
                break;
            }
        }

        if (can)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }
    return 0;
}