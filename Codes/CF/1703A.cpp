#include <iostream>
using namespace std;

int main()
{

    int t;
    cin >> t;

    while (t--)
    {
        int i = 0;
        string s;
        cin >> s;

        while (s[i] != '\0')
        {
            s[i] = tolower(s[i]);
            i++;
        }

        if (s == "yes")
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }

    return 0;
}