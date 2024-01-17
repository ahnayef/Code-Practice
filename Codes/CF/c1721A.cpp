#include <iostream>
using namespace std;

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int d = 0;
        string s, s1, s2;

        cin >> s1 >> s2;
        s = s1 + s2;

        for (int i = 0; i < 4; i++)
        {
            for (int j = i + 1; j < 4; j++)
            {
                if (s[j] == s[i])
                {
                    s[j] = '0';
                }
            }
        }

        for (int i = 0; i < 4; i++)
        {
            if (s[i] != '0')
            {
                d++;
            }
        }

        cout << d - 1 << endl;
        d = 0;
    }

    return 0;
}