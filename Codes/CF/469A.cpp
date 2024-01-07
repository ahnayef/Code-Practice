#include <iostream>
using namespace std;

int main()
{
    int max, win = 0;
    cin >> max;

    int final[max + 1];
    for (int i = 0; i <= max; i++)
    {
        final[i] = 0;
    }

    int x, y;
    cin >> x;

    for (int i = 0; i < x; i++)
    {
        int t;
        cin >> t;
        final[t] = t;
    }

    cin >> y;
    for (int i = 0; i < y; i++)
    {
        int t;
        cin >> t;
        final[t] = t;
    }

    for (int i = 1; i <= max; i++)
    {
        if (final[i] == 0)
        {
            win = 0;
            break;
        }
        else
        {
            win = 1;
        }
    }

    if (win)
    {
        cout << "I become the guy.";
    }
    else
    {
        cout << "Oh, my keyboard!";
    }

    return 0;
}