#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        string cf = "codeforces";
        char c;
        int apear = 0, i = 0;
        cin >> c;

        while (cf[i] != '\0')
        {
            if (cf[i] == c)
            {
                apear = 1;
                break;
            }

            i++;
        }

        if (apear)
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