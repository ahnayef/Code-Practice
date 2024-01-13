#include <iostream>
#include <cmath>
using namespace std;

int main()
{

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        int a = round(n / 3.00), b = n - a * 2;

        cout << b << " " << a << endl;
    }

    return 0;
}