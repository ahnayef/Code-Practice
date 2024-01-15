#include <iostream>
using namespace std;

int main()
{

    int a, b, isColor = 0;
    cin >> a >> b;
    char str[a][b];

    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < b; j++)
        {
            cin >> str[i][j];
        }
    }

    for (int i = 0; i < a; i++)
    {
        for (int j = 0; j < b; j++)
        {
            if (str[i][j] == 'C' || str[i][j] == 'M' || str[i][j] == 'Y')
            {
                // cout << str[i][j] << endl;
                isColor = 1;
            }
        }
    }

    if (isColor)
    {
        cout << "#Color";
    }
    else
    {
        cout << "#Black&White";
    }

    return 0;
}