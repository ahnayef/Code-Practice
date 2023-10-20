#include <iostream>
#include <string>

using namespace std;

int main()
{

    string s;
    cin >> s;

    int len = s.length();
    int arr[len];

    int i = 0;
    int a = 0;

    while (s[i] != '\0')
    {

        if (s[i] != '+')
        {
            arr[a] = (s[i] + 0) - 48;
            a++;
        }

        i++;
    }
    // Sorting...
    for (int i = 1; i < a; i++)
    {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }

    a = 0;

    for (int i = 0; i < len; i += 2)
    {
        char tmp = arr[a] + 48;
        s[i] = tmp;
        a++;
    }

    i = 0;

    while (s[i] != '\0')
    {
        cout << s[i];
        i++;
    }
}