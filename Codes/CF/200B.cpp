#include <iostream>
using namespace std;

int main()
{

    int n;
    float d = 0;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int t;
        cin >> t;
        d += t;
    }


    printf("%.12f",d/n);

    return 0;
}