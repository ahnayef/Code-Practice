#include <iostream>
using namespace std;

int main()
{
    string s;
    cin >> s;
    long dc = 0;

    int i = 0;

    while (s[i] != '\0')
    {
        int j = i + 1;
        while (s[j] != '\0')
        {
            if (s[i] == s[j])
            {
                s[i] = '0';
            }
            j++;
        }

        i++;
    }

    int k = 0;

    while (s[k] != '\0')
    {
        if (s[k] != '0')
        {
            dc++;
        }
        k++;
    }

    if (dc % 2 == 0)
    {
        cout << "CHAT WITH HER!";
    }
    else
    {
        cout << "IGNORE HIM!";
    }

    return 0;
}
