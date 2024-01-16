#include <iostream>
using namespace std;

int checkT(string str)
{
    string tim = "Timur";
    int c = 0;

    for (int i = 0; i < 5; i++)
    {
        int j = 0;
        while (str[j] != '\0' && c < 5)
        {
            if (tim[i] == str[j])
            {
                c++;
            }

            j++;
        }
    }

    if (c == 5)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int main()
{

    int t;
    cin >> t;

    while (t--)
    {
        int n, total = 0, i = 0;
        cin >> n;
        string s;
        cin >> s;

        if (n != 5)
        {
            cout << "NO" << endl;
        }
        else
        {

            while (s[i] != '\0')
            {
                total += s[i];
                i++;
            }

            if (total == 529 && checkT(s))
            {
                cout << "YES" << endl;
            }
            else
            {
                cout << "NO" << endl;
            }
            total = 0;
        }
    }

    return 0;
}

// 529