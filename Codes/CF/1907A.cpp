#include <bits/stdc++.h>
using namespace std;

int main()
{

    int t;
    cin >> t;

    while (t--)
    {
        string pos;
        cin >> pos;

        char start = 'a';

        for (int i = 0; i < 8; i++)
        {
            if (start == pos[0])
            {
                start++;
                continue;
            }
            else
            {
                printf("%c%c\n", start, pos[1]);
                start++;
            }
        }

        int rStart = 1;

        for (int i = 0; i < 8; i++)
        {
            if (to_string(rStart)[0] == pos[1])
            {
                rStart++;
                continue;
            }
            else
            {
                printf("%c%d\n", pos[0], rStart);
                rStart++;
            }
        }
    }
    return 0;
}