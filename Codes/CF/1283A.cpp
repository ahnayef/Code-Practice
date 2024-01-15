#include <iostream>
using namespace std;

int main()
{

    int t;
    cin >> t;

    while (t--)
    {
        int h, m;

        cin >> h >> m;

        m = m + (h * 60);

        cout << (24 * 60) - m << endl;
    }

    return 0;
}