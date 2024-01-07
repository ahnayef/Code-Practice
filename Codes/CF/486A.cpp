#include <iostream>
using namespace std;

int main()
{
    int n, f = 0;
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        if (i % 2 != 0)
        {
            f = f - i;
        }
        else
        {
            f = f + i;
        }
    }

    cout << f;

    return 0;
}