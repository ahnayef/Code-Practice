#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, countx = 0, rm = 0;
    cin >> n;
    string s;
    cin >> s;

    vector<int> arr(0);

    for (int i = 0; s[i] != '\0'; i++)
    {
        if (s[i] == 'x' && s[i + 1] == '\0')
        {
            countx++;
            if (countx > 2)
            {
                arr.push_back(countx);
            }
        }
        else if (s[i] == 'x')
        {
            countx++;
        }
        else
        {
            if (countx > 2)
            {
                arr.push_back(countx);
            }
            countx = 0;
        }
    }

    for (auto x : arr)
    {
        if (x > 2)
        {
            rm += x - 2;
        }
    }

    cout << rm;

    return 0;
}