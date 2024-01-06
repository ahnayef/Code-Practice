#include <iostream>
using namespace std;

int main()
{
    int cost, money, item, totalPrice = 0, res = 0;

    cin >> cost >> money >> item;

    for (int i = 1; i <= item; i++)
    {
        totalPrice += cost * i;
    }

    res = totalPrice - money;

    if (res < 0)
    {
        cout << 0;
    }
    else
    {
        cout << res;
    }

    return 0;
}