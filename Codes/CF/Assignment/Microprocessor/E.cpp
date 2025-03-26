// #include <bits/stdc++.h>
// using namespace std;

// int main()
// {
//     int a, b;
//     while (cin >> a >> b)
//     {
//         if (a == 0 && b == 0)
//         {
//             break;
//         }
//         int n1pos1 = a % 10;
//         int n1pos2 = (a / 10) % 10;
//         int n1pos3 = (a / 100) % 10;

//         int n2pos1 = b % 10;
//         int n2pos2 = (b / 10) % 10;
//         int n2pos3 = (b / 100) % 10;

//         int carry = 0;

//         if (n1pos1 + n2pos1 >= 10)
//         {
//             carry++;
//         }
//         if (n1pos2 + n2pos2 + carry >= 10)
//         {
//             carry++;
//         }
//         if (n1pos3 + n2pos3 + carry >= 10)
//         {
//             carry++;
//         }

//         if (carry == 0)
//         {
//             cout << "No carry operation." << endl;
//         }
//         else
//         {
//             cout << carry << " carry operations." << endl;
//         }
        
//     }
//     return 0;
// }



// #include <iostream>
// using namespace std;

// int main() {
//     unsigned long long a, b;
//     while (cin >> a >> b) {
//         if (a == 0 && b == 0){
//             break;
//         }
        
//         int carry = 0;
//         int count = 0; 
        
//         while (a > 0 || b > 0) {
//             int num1 = a % 10;
//             int num2 = b % 10;
            
//             int sum = num1 + num2 + carry;
            
//             if (sum >= 10) {
//                 carry = 1;
//                 count++;
//             } else {
//                 carry = 0;
//             }
            
//             a /= 10;
//             b /= 10;
//         }
        
//         if (count == 0)
//             cout << "No carry operation." << "\n";
//         else
//             cout << count << " carry operations." << "\n";
//     }
//     return 0;
// }