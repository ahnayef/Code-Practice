#include <iostream>
using namespace std;

int main()
{

    int r, b;

    cin >> r >> b;

    int same = 0, different = 0;

    // 3 2

    if (r > b) // 3 > 2 // 2 > 1 // 1 > 0
    {
        while (r != 0) // r = 3 // r = 2 // r = 1
        {
            // cout << "r: " << r << " b: " << b << endl;
            if (r >= b && b != 0) // 3 >= 2 // 2 >= 1 // 1 => 0(false)
            {
                same++; // 1 // 1
            }
            else if (r > 1)
            {
                different++; // 1
                r--;
            }

            r--;       // 2 // 1
            if (b > 0) // 2 > 0 // 1 > 0
            {
                b--; // 1 // 0
            }
        }
        cout << same << " " << different;
    }

    else if (b > r)
    {
        while (b != 0)
        {
            // cout << "r: " << r << " b: " << r << endl;
            if (b >= r && r != 0)
            {
                same++;
            }
            else if (b > 1)
            {
                different++;
                b--;
            }

            b--;
            if (r > 0)
            {
                r--;
            }
        }

        cout << same << " " << different;
    }
    else
    {
        cout << r << " " << r - b;
    }

    return 0;
}