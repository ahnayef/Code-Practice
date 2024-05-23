#include <bits/stdc++.h>
using namespace std;

struct Activity
{
    int start, finish;
};

void MaxActivities(Activity act[], int n)
{
    bool swapped;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (act[j].finish > act[j + 1].finish)
            {
                swap(act[j], act[j + 1]);
                swapped = true;
            }
        }
        if (swapped == false)
            break;
    }
    cout << "Following activities are selected :" << endl;
    int i = 0;
    cout << act[i].start << "," << act[i].finish << endl;
    for (int j = 1; j < n; j++)
    {
        if (act[j].start >= act[i].finish)
        {
            cout << act[j].start << "," << act[j].finish << endl;
            i = j;
        }
    }
}

int main()
{
    int n;
    cin >> n;
    Activity act[n];
    for (int i = 0; i < n; i++)
    {
        cin >> act[i].start >> act[i].finish;
    }

    MaxActivities(act, n);
}