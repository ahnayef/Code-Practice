#include <bits/stdc++.h>
using namespace std;

int main()
{
    int len;
    int evenCount = 0;
    int oddCount = 0;

    cin >> len;

    int arr[len];
    for (int i = 0; i < len; i++)
    {
        cin >> arr[i];
    }

    for (int i = 0; i < len; i++)
    {
        if (arr[i] % 2 == 0)
        {
            evenCount++;
        }
        else
        {
            oddCount++;
        }
    }

    bool isEven = evenCount > oddCount;

    for (int i = 0; i < len; i++)
    {
        if (isEven && arr[i] % 2 != 0)
        {
            cout << i + 1 << endl;
            break;
        }
        else if (!isEven && arr[i] % 2 == 0)
        {
            cout << i + 1 << endl;
            break;
        }
    }

    return 0;
}