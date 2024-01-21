#include <bits/stdc++.h>
using namespace std;

int main()
{

    string s;
    cin >> s;

    int dec = 0, len = s.length(), sup = len - 1;

    for (int i = 0; i < len; i++)
    {
        if (s[i] == '1')
        {
            dec += pow(2, sup);
        }
        sup--;
    }

    cout << dec;

    return 0;
}
