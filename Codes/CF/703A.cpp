#include <iostream>
using namespace std;

int main()
{
    int t, mScore = 0, cScore = 0;

    cin >> t;
    while (t--)
    {
        int m, c;
        cin >> m >> c;

        if (m > c)
        {
            mScore++;
        }
        else if (c > m)
        {
            cScore++;
        }
    }           

    if (mScore > cScore)
    {
        cout << "Mishka";
    }
    else if (cScore > mScore)
    {
        cout << "Chris";
    }
    else
    {
        cout << "Friendship is magic!^^";
    }

    return 0;
}