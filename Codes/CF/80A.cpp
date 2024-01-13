#include <iostream>
using namespace std;

int isPrime(int n)
{
    if (n <= 1)
        return 0;

    for (int i = 2; i <= n / 2; i++)
        if (n % i == 0)
            return 0;

    return 1;
}

int main()
{
    int a, b;
    cin >> a >> b;

    int i = a + 1;

    while (!isPrime(i))
    {
        i++;
    }

    if (i == b)
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }

    return 0;
}