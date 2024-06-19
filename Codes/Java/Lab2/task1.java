/* 

Question: 

Write a program with two methods 'retAddition' and 'retMultiplication' in a class 'Operations':

1. retAddition(a, b) that returns the sum of a and b 

2. retMultiplication(c) that calculates the formula : c * (2 * retAddition) * 10 

Then create another method onlyPrint(), that prints the result of retMultiplication.

*/

import java.util.Scanner; 
 
class Operations { 
    int resAdd, ans; 
 
    int retAddition(int var1, int var2) { 
        resAdd = var1 + var2; 
        return resAdd; 
    } 
 
    int retMultiplication(int var1) { 
        ans = var1 * (resAdd + resAdd) * 10; 
        return ans; 
    } 
 
    void onlyPrint() { 
        System.out.println(ans); 
    } 
} 
 
class runProgram { 
 
    public static void main(String[] args) { 
 
        Scanner sc = new Scanner(System.in); 
 
        Operations op = new Operations(); 
 
        int num1 = sc.nextInt(); 
        int num2 = sc.nextInt(); 
        int num3 = sc.nextInt(); 
 
        int a = op.retAddition(num1, num2); 
 
        int b = op.retMultiplication(num3); 
 
        op.onlyPrint(); 
 
    } 
 
}
