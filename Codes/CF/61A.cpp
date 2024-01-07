#include <iostream>
using namespace std;

int main()
{
    string s1, s2;
    cin >> s1;
    cin >> s2;
    int i = 0;

    while (s1[i] != '\0')
    {

        if (s1[i] != s2[i])
        {
            cout << 1;
        }
        else
        {
            cout << 0;
        }

        i++;
    }

    return 0;
}