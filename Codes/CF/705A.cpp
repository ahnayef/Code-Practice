#include <iostream>
using namespace std;

int main()
{
    string that = "that", it = "it";

    string odd = "I hate ";
    string even = "I love ";
    string final = "";

    int t;
    cin >> t;

    int i = 1;

    while (i != t)
    {
        if (i % 2 != 0)
        {
            final+=" I hate it";
        }
        else
        {
            final+=" I love it";
        }

        int j=0;

        i++;
    }

    return 0;
}

/*

n = 1 : I hate it // hate
n = 2 : I hate that I love it  // love
n = 3 : I hate that I love that I hate it //hate
n = 4 : I hate that I hove that I hate that I love it;





*/