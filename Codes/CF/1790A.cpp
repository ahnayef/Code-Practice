#include <bits/stdc++.h>
using namespace std;

int main()
{

    int t;
    cin >> t;

    while (t--)
    {
        string pi = "314159265358979323846264338327", s;
        int count = 0;
        cin >> s;

        while (s[count] == pi[count] && s[count] != '\0')
        {
            count++;
        }

        cout << count << endl;
    }
    return 0;
}