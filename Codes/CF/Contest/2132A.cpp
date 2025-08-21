#include <bits/stdc++.h>
using namespace std;

int main()
{

     int t;
     cin >> t;

     while (t--)
     {
          int lena, lenbc, currPos = 0;
          string a, b, c;

          cin >> lena;
          cin >> a;
          cin >> lenbc;
          cin >> b;
          cin >> c;

          for (char turn : c)
          {
               if (turn == 'D')
               {
                    a.push_back(b[currPos]);
                    currPos++;
               }
               else
               {
                    a.insert(a.begin(), b[currPos]);
                    currPos++;
               }
          }

          cout << a << endl;
     }
     return 0;
}

// D - end
// V - start

// 3
// efo
// 7
// r d c o e c s
// D V D V D V D

// codeforces