#include <iostream>
using namespace std;

int main()
{

    int n, pol = 0, c = 0;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int in;
        cin >> in;

        if (in == -1 && pol <= 0)
        {
            c++;
        }
        else if (in == -1 && pol > 0)
        {
            pol = pol + in;
        }

        else
        {
            pol += in;
        }
    }

    cout << c;

    return 0;
}