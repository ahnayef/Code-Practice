#include <iostream>
using namespace std;

int main()
{
    int t, res = 0;
    cin >> t;

    while (t--)
    {
        string s;
        cin >> s;

        if (s == "Tetrahedron")
        {
            res += 4;
        }
        else if (s == "Cube")
        {
            res += 6;
        }
        else if (s == "Octahedron")
        {
            res += 8;
        }
        else if (s == "Dodecahedron")
        {
            res += 12;
        }
        else
        {
            res += 20;
        }
    }

    cout << res;

    return 0;
}