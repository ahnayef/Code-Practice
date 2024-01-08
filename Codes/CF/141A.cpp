#include <iostream>
using namespace std;

string insertionSort(string str, int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = str[i];
        j = i - 1;
        while (j >= 0 && str[j] > key)
        {
            str[j + 1] = str[j];
            j = j - 1;
        }
        str[j + 1] = key;
    }

    return str;
}

int main()
{

    string a, b, c, f;
    cin >> a;
    cin >> b;
    cin >> c;
    int res = 0;

    f = a + b;

    int flen = 0, clen = 0;
    while (f[flen] != '\0')
    {
        flen++;
    }
    while (c[clen] != '\0')
    {
        clen++;
    }

    if (clen > flen)
    {
        cout << "NO";
    }
    else if (clen < flen)
    {
        cout << "NO";
    }
    else
    {
        c = insertionSort(c, flen);
        f = insertionSort(f, clen);

        int t = 0;

        while (f[t] != '\0')
        {
            if (f[t] != c[t])
            {
                res = 0;
                break;
            }
            else
            {
                res = 1;
            }
            t++;
        }
        if (res)
        {
            cout << "YES";
        }
        else
        {
            cout << "NO";
        }
    }

    return 0;
}

/*
PA PAINOEL
JOULU PUKKI
JOUL NA PAOILELU PUKKI

*/
