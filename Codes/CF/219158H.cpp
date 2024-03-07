#include <bits/stdc++.h>
using namespace std;

int main()
{

    long long int a, b;
    cin >> a >> b;

    double div = a / (float)b;

    long long int fl = floor(div);
    long long int cl = ceil(div);
    long long int rnd = round(div);

    printf("floor %lld / %lld = %lld\n", a, b, fl);
    printf("ceil %lld / %lld = %lld\n", a, b, cl);
    printf("round %lld / %lld = %lld", a, b, rnd);

    return 0;
}