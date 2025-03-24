// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {
//     int t;
//     cin >> t;

//     for (int i = 1; i <= t; i++)
//     {
//         int P, S, R;
//         cin >> P >> S >> R;

//         if (R == 1 || S == 0)
//         {
//             cout << "Case " << i << ": Yes" << endl;
//         }
//         else
//         {
//             cout << "Case " << i << ": No" << endl;
//         }
//     }

//     return 0;
// }

#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    for (int i = 1; i <= t; ++i)
    {
        int P, S, R;
        cin >> P >> S >> R;

        if (S < P)
        {
            cout << "Case " << i << ": Yes" << "\n";
        }
        else if (S == P && R == 1)
        {
            cout << "Case " << i << ": Yes" << "\n";
        }
        else
        {
            cout << "Case " << i << ": No" << "\n";
        }
    }
    return 0;
}