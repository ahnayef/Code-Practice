#include <iostream>

using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, res = -1;
        cin >> n;

        int total[n];

        for (int i = 0; i < n; i++)
        {
            int hold;
            cin >> hold;

            ++total[hold];
            if (total[hold] >= 3)
            {
                res = hold;
            }
        }

        cout << res << endl;
    }

    return 0;
}