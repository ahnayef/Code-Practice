#include <iostream>
using namespace std;

int main()
{

    int n, m, p = 0, i = 1;
    cin >> n >> m;
    int time_reamaining = 240 - m;

    int time_spent = 0;

    while (p < n && time_reamaining > time_spent)
    {
        time_spent += i * 5;
        if (time_spent >= time_reamaining)
        {
            break;
        }
        else
        {
            p++;
        }
        i++;
    }

    cout << p;

    return 0;
}