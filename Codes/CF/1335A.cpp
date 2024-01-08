#include <iostream>
using namespace std;

int main()
{

    int t;
    cin >> t;

    while (t--)
    {
        int c;
        cin >> c;

        if (c % 2 == 0)
        {
            cout << (c / 2) - 1<<endl;
        }
        else
        {
            cout << c / 2<<endl;
        }
    }

    return 0;
}

// cout<<13/2;

// Runtime ???

/*
7
6 1 -
5 2
4 3
3 4 // break

*/

/*
7 = 3 : 7/2 = 3
8 = 3 : 8/2 = 4
9 = 4 : 9/2 - 4
10 = 4 : 10/2 = 5
11 = 5 : 11/2



*/