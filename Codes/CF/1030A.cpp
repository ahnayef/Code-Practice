#include <iostream>
using namespace std;

int main()
{
    int n, isHard = 0;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int t;
        cin >> t;
        if (t == 1)
        {
            isHard = 1;
            break;
        }
        else
        {
            isHard = 0;
        }
    }

    if (isHard)
    {
        cout << "HARD";
    }
    else
    {
        cout << "EASY";
    }

    return 0;
}