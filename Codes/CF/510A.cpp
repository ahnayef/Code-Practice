#include <iostream>
using namespace std;

int main()
{
    int a, b, order = 0;
    cin >> a >> b;

    for (int i = 1; i <= a; i++)
    {

        if (i % 2 == 0)
        {
            order++;
        }

        for (int j = 1; j <= b; j++)
        {
            if (i % 2 != 0)
            {
                cout << "#";
            }
            else
            {
                if (order % 2 != 0)
                {

                    if (j == b)
                    {
                        cout << "#";
                    }
                    else
                    {
                        cout << ".";
                    }
                }
                else
                {

                    if (j == 1)
                    {
                        cout << "#";
                    }
                    else
                    {
                        cout << ".";
                    }
                }
            }
        }
        cout << endl;
    }

    return 0;
}

// if (j == b)
// {
//     cout << "#";
// }
// else
// {
//     cout << "-";
// }