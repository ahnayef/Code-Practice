#include <bits/stdc++.h>
using namespace std;

int main()
{

    int t;
    cin >> t;

    while (t--)
    {
        int n, mod;
        cin >> n >> mod;

        vector<int> arr(n);
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }

        string s;
        cin >> s;

        for (int i = 0; i < n; i++)
        {
            int sum = accumulate(arr.begin(), arr.end(), 0);
            int myMod = sum % mod;
            cout << myMod << " ";
            if (s[i] == 'L')
            {
                arr.erase(arr.begin());
            }
            else
            {
                arr.erase(arr.end());
            }
        }
    }
    return 0;
}