#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        string s;
        cin >> s;
        int i = 0;
        while (s[i] != '\0')
        {
            i++;
        }

        if (i > 10)
        {
            cout << s[0] << i - 2 << s[i - 1] << "\n";
        }
        else
        {
            cout << s << "\n";
        }
    }

    return 0;
}