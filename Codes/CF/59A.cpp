#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{

    string s;

    cin >> s;

    int i = 0, lc = 0, uc = 0;

    while (s[i] != '\0')
    {
        if (s[i] > 90)
        {
            lc++;
        }
        else
        {
            uc++;
        }

        i++;
    }

    if (uc > lc)
    {
        transform(s.begin(), s.end(), s.begin(), ::toupper);
        cout << s;
    }
    else
    {
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        cout << s;
    }

    return 0;
}