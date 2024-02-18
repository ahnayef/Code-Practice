#include <bits/stdc++.h>
using namespace std;

int main()
{

    int t;
    cin >> t;

    while (t--)
    {
        int n, c = 0;
        cin >> n;
        string s;
        cin >> s;

        for (int i = 0; s[i] != '\0'; i++)
        {
            if (s[i] == '*' && s[i + 1] == '*')
            {
                break;
            }
            if (s[i] == '@')
            {
                c++;
            }
        }

        cout << c << endl;
    }
    return 0;
}