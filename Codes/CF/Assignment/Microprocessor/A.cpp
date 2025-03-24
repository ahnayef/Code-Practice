#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    for (int i = 1; i <= t; ++i)
    {
        int Ax, Ay, Bx, By, Cx, Cy;
        cin >> Ax >> Ay >> Bx >> By >> Cx >> Cy;

        int Dx = Ax + (Cx - Bx);
        int Dy = Ay + (Cy - By);

        int area = abs((Bx - Ax) * (Dy - Ay) -  (By - Ay)*(Dx - Ax));

        cout << "Case " << i << ": " << Dx << " " << Dy << " " << area << endl;
    }

    return 0;
}


// https://youtu.be/oET16XXfcCI