#include <bits/stdc++.h>
using namespace std;

int main()
{
	int p[] = {5,3,7,10};
    int n = sizeof(p) / sizeof(p[0]);
    int m=4;
	int rc[n+1][m+1];

	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= m; j++) {
			if (i == 0 || j == 0){
                rc[i][j] = 0;
			}
            else if (i > j){
                rc[i][j] = rc[i - 1][j];
            }
            else {
                rc[i][j] = max(p[i - 1]+rc[i][j - i],rc[i-1][j]);
            }

		}
	}
	cout << "Maximum profit of rod cutting: " << rc[n][m];
}