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
        string s;
        cin >> s;

        if (n == 1 && s == "W")
        {
            cout << 0 << endl;
        }
        else
        {
            int left = 0, right = n;

            for (int i = 0; s[i] != 'B'; i++)
            {
                left++;
            }
            for (int i = n - 1; s[i] != 'B'; i--)
            {
                right--;
            }

            cout << right - left << endl;
        }
    }
    return 0;
}