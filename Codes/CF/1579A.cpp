#include <bits/stdc++.h>
using namespace std;

int main()
{

    int t;
    cin >> t;

    while (t--)
    {
        string s;
        cin >> s;

        int A = 0, B = 0, C = 0;

        for (int i = 0; s[i] != '\0'; i++)
        {
            if (s[i] == 'A')
            {
                A++;
            }
            else if (s[i] == 'B')
            {
                B++;
            }
            else
            {
                C++;
            }
        }

        if (s.length() == 1 || A > B || C > B || (A == B && B == C) || B < (A + C) || B > (A + C) || A > (B + C) || C > (A + B))
        {
            cout << "NO" << endl;
        }
        else
        {
            cout << "YES" << endl;
        }
    }
    return 0;
}