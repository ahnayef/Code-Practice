#include <iostream>
#include <string>

using namespace std;

int main()
{

    int y, i = 0, isDisting = 0;
    cin >> y;
    y++;
    string stry = to_string(y);

    while (!isDisting)
    {
        while (stry[i] != '\0')
        {
            if (stry[i] != stry[i + 1])
            {
                isDisting = 1;
            }
            else
            {
                cout << stry[i] << " : " << stry[i + 1] << endl;
                y++;
                i = 0;
                stry = to_string(y);
                isDisting=0;
            }

            i++;
        }
    }

    cout << y;

    return 0;
}