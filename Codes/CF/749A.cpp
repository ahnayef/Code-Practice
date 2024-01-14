#include <iostream>
#include <cmath>
using namespace std;

int countTotal(int arr[], int p)
{
    int total = 0;
    for (int i = 0; i < p; i++)
    {
        total += arr[i];
    }

    return total;
}

int findMin(int arr[], int p)
{
    int min = arr[0], index = 0;

    for (int i = 0; i < p; i++)
    {
        if (arr[i] < min)
        {
            min = arr[i];
            index = i;
        }
    }

    return index;
}

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
    int n;
    cin >> n;

    int p = n / 2;

    int arr[p];

    for (int i = 0; i < p; i++)
    {
        arr[i] = n / (n / 2);
    }

    while (countTotal(arr, p) != n)
    {
        int myPrime = arr[findMin(arr, p)] + 1;

        while (!isPrime(myPrime))
        {
            myPrime++;
        }

        arr[findMin(arr, p)] = myPrime;
    }

    cout << p << endl;
    for (int i = 0; i < p; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}