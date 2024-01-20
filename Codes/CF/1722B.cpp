#include <iostream>
#include <string>
using namespace std;

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        string s[2];

        for (int j = 0; j < 2; j++)
        {
            cin >> s[j];
        }

        int j = 0;

        while (s[0][j] != '\0')
        {
            if (s[0][j] == 'B')
            {
                s[0][j] == 'G';
            }

            j++;
        }
        j = 0;

        while (s[1][j] != '\0')
        {
            if (s[1][j] == 'B')
            {
                s[1][j] == 'G';
            }

            j++;
        }

        cout << s[0] << endl;
        cout << s[1] << endl;

        // if (s[0] == s[1])
        // {
        //     cout << "YES" << endl;
        // }
        // else
        // {
        //     cout << "NO" << endl;
        // }
    }

    return 0;
}