#include <iostream>
using namespace std;

int main()
{
    int t, a = 0, b = 0, max = 0, temp = 0;
    cin >> t;

    for (int i = 0; i < t; i++)
    {
        cin >> a >> b;
        temp = temp - a + b;
        if (i == 0)
        {
            max = b - a;
            continue;
        }
        if (temp > max)
        {
            max = temp;
        }
    }

    cout << max;

    return 0;
}

// a b  max
// 0 3  3
// 2 5  3 - 2 + 5 = 6
// 4 2  6 - 4 + 2 = 4
// 4 0  4 - 4 + 0 = 0

// 10
// 0 5  5
// 1 7  5 - 1 + 7 = 11
// 10 8 11 - 10 + 8 = 9
// 5 3  9 - 5 + 3 = 7
// 0 5  7 - 0 + 5 = 12
// 3 3
// 8 8
// 0 6
// 10 1
// 9 0