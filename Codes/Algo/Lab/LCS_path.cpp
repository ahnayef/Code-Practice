#include <bits/stdc++.h>
using namespace std;
#define diag 1
#define left 2
#define up 3

int main()
{
    string s1, s2;
    cin >> s1 >> s2;
    int m = s1.size();
    int n = s2.size();

    int lcs[m + 1][n + 1], dir[m + 1][n + 1];

    for (int i = 0; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
        {
            if (i == 0 || j == 0)
                lcs[i][j] = 0;

            else if (s1[i - 1] == s2[j - 1])
            {
                lcs[i][j] = lcs[i - 1][j - 1] + 1;
                dir[i][j] = diag;
            }
            else
            {
                lcs[i][j] = max(lcs[i - 1][j], lcs[i][j - 1]);
                if (lcs[i][j] == lcs[i][j - 1])
                    dir[i][j] = left;
                else
                    dir[i][j] = up;
            }
        }
    }
    cout << "Length of LCS: " << lcs[m][n];

    int i = m;
    int j = n;
    string subseq = "";
    while (i > 0 && j > 0)
    {
        if (dir[i][j] == diag)
        {
            subseq += s1[i - 1];
            i--;
            j--;
        }
        else if (dir[i][j] == left)
            j--;
        else
            i--;
    }
    reverse(subseq.begin(), subseq.end());
    cout << "The longest common subsequence: " << subseq << endl;
}