#include <iostream>
using namespace std;

int main()
{
    int t, ahed = 0;
    ;
    cin >> t;

    while (t--)
    {
        int arr[4];
        for (int i = 0; i < 4; i++)
        {
            cin >> arr[i];
        }
        for (int i = 1; i < 4; i++)
        {
            if (arr[i] > arr[0])
            {
                ahed++;
            }
        }
        cout << ahed << endl;
        ahed = 0;
    }

    return 0;
}