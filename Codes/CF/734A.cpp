#include <iostream>
using namespace std;

int main()
{
    string s;
    int n, a = 0, d = 0;

    cin >> n;
    cin >> s;

    int i = 0;
    while (s[i] != '\0')
    {
        if (s[i] == 'A')
        {
            a++;
        }
        else
        {
            d++;
        }
        i++;
    }

    if (a > d)
    {
        cout << "Anton";
    }
    else if (a < d)
    {
        cout << "Danik";
    }
    else
    {
        cout << "Friendship";
    }

    return 0;
}