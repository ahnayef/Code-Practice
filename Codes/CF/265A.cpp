#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s, ins;
    cin >> s >> ins;

    int pos = 0;

    for (int i = 0; ins[i] != '\0'; i++)
    {
        if (ins[i] == s[pos])
        {
            pos++;
        }
    }

    cout << pos + 1;

    return 0;
}