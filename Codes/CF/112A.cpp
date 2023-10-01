#include <iostream>
#include <cctype>

using namespace std;

int main()
{

    string s1;
    string s2;
    // int num1 = 0;
    // int num2 = 0;

    cin >> s1;
    cin >> s2;


    for (char &c : s1)
    {
        c = tolower(c);

    }

    for (char &c : s2)
    {
        c = tolower(c);
    }


    int n=0;

    int out=0;

    while (s1[n] !='\0')
    {
        if((int)s1[n]<(int)s2[n]){
            out=-1;
            break;

        }else if((int)s2[n]<(int)s1[n]){
            out=1;
            break;
        }else{
            out+=0;
        }

        n++;
    }
    
    cout<<out;
    





    // for (char c : s1)
    // {
    //     num1 += (int)c;
    // }

    // for (char c : s2)
    // {
    //     num2 += (int)c;
    // }


    // if (num1<num2)
    // {
    //     cout<<-1;
    // }else if(num2<num1){
    //     cout<<1;
    // }else if(num1 == num2){
    //     cout<<0;
    // }
    
    


    return 0;
}