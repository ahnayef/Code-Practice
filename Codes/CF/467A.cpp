#include <iostream>
using namespace std;

int main()
{
    int n, total = 0;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int p, q;
        cin >> p >> q;
        if ((q - p) >= 2)
        {
            total += 1;
        }
    }

    cout << total;

    return 0;
}