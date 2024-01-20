#include <iostream>

using namespace std;

int main()
{

    int t;

    cin >> t;

    while (t--)
    {
        string s, cf = "codeforces";
        cin >> s;
        int diff = 0;

        int i = 0;

        while (cf[i] != '\0')
        {
            if (cf[i] != s[i])
            {
                diff++;
            }
            i++;
        }

        cout << diff << endl;
    }

    return 0;
}