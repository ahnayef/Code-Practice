#include <iostream>
using namespace std;

int main()
{

    int input;

    cin>>input;

    for (int i = 1; i <=5; i++)
    {
        if ((input % i) != 0)
        {
            cout << input % i;
            exit(1);
        }
    }

    return 0;
}