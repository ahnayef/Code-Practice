#include <bits/stdc++.h>
using namespace std;

int main()
{

    int t;
    cin >> t;

    while (t--)
    {
        string keyboard;
        string str;
        int cost = 0;

        cin >> keyboard;
        cin >> str;

        for (int i = 1; str[i] != '\0'; i++)
        {
            char curNow = str[i];
            char curPrev = str[i - 1];

            int diff = keyboard.find(curNow) - keyboard.find(curPrev);

            cost += abs(diff);
        }

        cout << cost << endl;
    }
    return 0;
}