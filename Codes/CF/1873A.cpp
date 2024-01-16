#include <iostream>
using namespace std;

string case1(string s1)
{
    char store = s1[0];
    s1[0] = s1[1];
    s1[1] = store;

    return s1;
}

string case2(string s2)
{
    char store = s2[1];
    s2[1] = s2[2];
    s2[2] = store;

    return s2;
}

string case3(string s3)
{
    char store = s3[0];
    s3[0] = s3[2];
    s3[2] = store;

    return s3;
}

int main()
{

    int t;

    cin >> t;

    while (t--)
    {

        string s, s1, s2, s3;
        cin >> s;

        if (s == "abc")
        {
            cout << "YES" << endl;
        }
        else
        {
            s1 = s2 = s3 = s;

            if (case1(s1) == "abc" || case2(s2) == "abc" || case3(s3) == "abc")
            {
                cout << "YES" << endl;
            }
            else
            {
                cout << "NO" << endl;
            }
        }
    }

    return 0;

    // s1 = s2 = s3 = s;
    // cout << case1(s1) << endl;
    // cout << case2(s2) << endl;
    // cout << case3(s3) << endl;
}
