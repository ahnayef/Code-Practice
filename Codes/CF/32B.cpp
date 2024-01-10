#include <iostream>
using namespace std;

int main()
{
    string s, n = "";
    int i = 0;
    cin >> s;

    while (s[i] != '\0')
    {
        if (s[i] == '.')
        {
            n += '0';
        }
        else if (s[i] == '-' && s[i + 1] == '.')
        {
            n += '1';
            i++;
        }
        else if (s[i] == '-' && s[i + 1] == '-')
        {
            n += '2';
            i++;
        }

        i++;
    }

    cout << n;

    return 0;
}