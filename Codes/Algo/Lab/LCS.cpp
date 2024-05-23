#include <bits/stdc++.h>
using namespace std;


int main()
{
	string s1, s2;
	cin>>s1>>s2;
	int m = s1.size();
	int n = s2.size();

	int lcs[m + 1][n + 1];

	for (int i = 0; i <= m; i++) {
		for (int j = 0; j <= n; j++) {
			if (i == 0 || j == 0)
				lcs[i][j] = 0;

			else if (s1[i - 1] == s2[j - 1])
				lcs[i][j] = lcs[i - 1][j - 1] + 1;

			else
				lcs[i][j] = max(lcs[i - 1][j], lcs[i][j - 1]);
		}
	}
	cout << "Length of LCS: " << lcs[m][n];


}