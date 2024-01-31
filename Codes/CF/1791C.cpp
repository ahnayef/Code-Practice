#include <bits/stdc++.h>
using namespace std;

int main()
{

    int t;
    cin >> t;

    while (t--)
    {
        int len, rem = 0;
        cin >> len;

        string s;
        cin >> s;

        int i = 0, j = len - 1;

        while (s[i] != '\0')
        {
            if ((s[i] == '0' && s[j] == '1') || (s[i] == '1' && s[j] == '0'))
            {
                i++;
                j--;
                rem += 2;
            }
            else
            {
                break;
            }
        }

        if (rem > len)
        {
            cout << 0 << endl;
        }
        else
        {
            cout << len - rem << endl;
        }
    }
    return 0;
}