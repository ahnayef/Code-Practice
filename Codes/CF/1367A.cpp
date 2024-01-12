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
        int i = 2;

        while (s[i] != '\0')
        {
            if (i % 2 == 0)
            {
                s[i] = '0';
            }

            i++;
        }

        i = 0;

        while (s[i] != '\0')
        {
            if (s[i] != '0')
            {
                cout << s[i];
            }
            i++;
        }
        cout << endl;
    }

    return 0;
}
