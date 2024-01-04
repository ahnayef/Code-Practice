#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int one, two, three;

    one = n / 2;

    if (one % 3 == 0)
    {
        one++;
    }

    two = (n - one) / 2;

    if (two % 3 == 0)
    {
        two++;
    }

    three = n - (one + two);

    while (two % 3 == 0 || three % 3 == 0)
    {
        two++;
        three--;
    }

    printf("%d %d %d", one, two, three);

    return 0;
}