#include <iostream>
#include <sstream>
using namespace std;

int main()
{
    string s1;
    int i1 = 0, i2 = 0, len = 0, res = 0;

    getline(cin, s1);

    if (s1[0] == '{' && s1[1] == '}')
    {
        cout << 0;
    }
    else
    {

        while (s1[len] != '\0')
        {
            len++;
        }

        char s2[len];

        while (i1 <= len)
        {
            if (s1[i1] == '{' || s1[i1] == '}' || s1[i1] == ',' || s1[i1] == ' ')
            {
            }
            else
            {
                // cout << "No spcace" << endl;
                s2[i2] = s1[i1];
                i2++;
            }
            i1++;
        }

        // cout << s2 << endl;

        i2 = 0;

        while (s2[i2] != '\0')
        {
            int j = i2 + 1;
            while (s2[j] != '\0')
            {
                if (s2[i2] == s2[j])
                {
                    s2[i2] = '0';
                }
                j++;
            }
            i2++;
        }

        // cout << s2;

        i2 = 0;

        while (s2[i2] != '\0')
        {
            if (s2[i2] != '0')
            {
                res++;
            }
            i2++;
        }

        cout << res;
    }

    return 0;
}