#include <iostream>
using namespace std;

int main()
{

    int t;

    cin >> t;

    while (t--)
    {
        int n, i = 0, total = 0;
        string s;

        cin >> n;
        cin >> s;

        while (s[i] != '\0')
        {
            int j = i + 1;

            while (s[j] != '\0')
            {
                if (s[i] == s[j])
                {
                    s[j] = '0';
                }
                j++;
            }
            i++;
        }

        i = 0;

        while (s[i] != '\0')
        {
            if (s[i] == '0')
            {
                total++;
            }
            else
            {
                total += 2;
            }

            i++;
        }

        cout << total << endl;
    }

    return 0;
}