#include <iostream>
#include<string>


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
            arr[a] = 
            a++;
        }

        i++;
    }

    // for (int i = 0; i < len; i++)
    // {
    //     cout<<arr[i]<<" ";
    // }
}