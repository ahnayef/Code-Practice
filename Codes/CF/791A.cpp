#include <iostream>
using namespace std;

int main()
{
    int l, b, r = 0;
    cin>>l>>b;
    while (l <= b)
    {
        l *= 3;
        b *= 2;
        r++;
    }
    cout << r;
}