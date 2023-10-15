#include <iostream>
using namespace std;

int main()
{
    string str;
    cin >> str;

    int target = str[0];

    if (target >= 97)
    {
        str[0] -= 32;
    }

    cout << str;
}