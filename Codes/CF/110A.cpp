#include <iostream>
using namespace std;

int main()
{
    string str;
    cin >> str;

    int i = 0, l = 0;

    while (str[i] != '\0')
    {
        if (str[i] == '4' || str[i] == '7')
        {
            l++;
        }

        i++;
    }

    if (l == 7 || l == 4)
    {
        printf("YES");
    }
    else
    {
        printf("NO");
    }

    return 0;
}