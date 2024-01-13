#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, count = 0, toAdd = 1;
        cin >> n;
        string res = "1";

        while (stoi(res) != n)
        {
            if (res.length() == 4)
            {
                toAdd++;
                res = to_string(toAdd);
                count += res.length();
            }
            else
            {
                res += to_string(toAdd);
                count += res.length();
            }
            // cout << res << " : " << res.length() << " : " << count << endl;
            // cout << res << endl;
        }
        cout << count + 1 << endl;
    }

    return 0;
}