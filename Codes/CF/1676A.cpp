#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, a = 0, b = 0;
        cin >> n;

        for (int i = 0; i < 6; i++)
        {
            if (i <= 2)
            {
                a += n % 10;
                n /= 10;
            }
            else
            {
                b += n % 10;
                n /= 10;
            }
        }

        if (a == b)
        {
            cout << "YES" << endl;
        }
        else
        {
            cout << "NO" << endl;
        }
    }

    return 0;
}