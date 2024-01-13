#include <iostream>
using namespace std;

int track = 0;
string repeatList = "";

int includes(char c)
{
    for (int i = 0; i < track; i++)
    {
        if (repeatList[i] == c)
        {
            return 1;
        }
    }
    return 0;
}

int main()
{

    int n, sus = 0;
    cin >> n;

    string s;
    cin >> s;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (s[i] != s[j] && !includes(s[j]))
            {
                repeatList += s[i];
            }
            else if (includes(s[j]))
            {
                sus = 1;
                return sus;
            }
        }
    }

    cout << sus;

    return 0;
}