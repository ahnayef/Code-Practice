#include <bits/stdc++.h>
using namespace std;

int main()
{

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        int a = 1, b = 1, c = 1;

        while ((a + b + c) != n && c < 26)
        {
            c++;
        }
        while ((a + b + c) != n && b < 26)
        {
            b++;
        }
        while ((a + b + c) != n && a < 26)
        {
            a++;
        }

        printf("%c%c%c\n", a + 96, b + 96, c + 96);
    }
    return 0;
}