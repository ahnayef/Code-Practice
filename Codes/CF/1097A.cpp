#include <bits/stdc++.h>
using namespace std;

int main()
{

    int has = 0;
    string s;
    getline(cin, s);

    string cards;

    getline(cin, cards);

    for (int i = 0; cards[i] != '\0'; i++)
    {
        if (cards[i] == s[0] || cards[i] == s[1])
        {
            has = 1;
            break;
        }
    }

    if (has)
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }

    return 0;
}