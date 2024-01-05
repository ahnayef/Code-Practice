#include <iostream>
using namespace std;

int main()
{
    int len, toRemove = 0;
    cin >> len;
    string s;
    cin >> s;

    for (int i = 0; i < len; i++)
    {
        for (int j = i+1; j < len; j++)
        {
            if (s[i] == s[j])
            {
                toRemove++;
                s[j]='0';
            }
        }
    }

    cout << toRemove;

    return 0;
}