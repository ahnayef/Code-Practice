#include <iostream>
using namespace std;

int main()
{

    int n, t = 0, i = 1;
    cin >> n;
    // cout << (n * (n + 1)) / 2;

    while (t <= n)
    {
        t += (i * (i + 1)) / 2;
        i++;
    }

    cout << i - 2;

    return 0;
}
