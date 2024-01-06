#include <iostream>
using namespace std;

int main()
{
    string s, t;
    int len = 0, sim = 0;

    cin >> s;
    cin >> t;

    while (s[len] != '\0')
    {
        len++;
    }

    int rev = len - 1;

    for (int i = 0; i < len; i++)
    {
        // cout << s[i] << " = " << t[rev] << endl;
        if (s[i] == t[rev])
        {
            sim = 1;
        }
        else
        {
            sim = 0;
            break;
        }
        rev--;
    }

    if (sim == 1)
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }

    return 0;
}