// Question: Write a program that override the method to find the second minimum number and the same method of parent class find the 2nd maximum number.
// Sample input:
// 5
// 4 5 10 2 1
// Sample output:
// 2nd Minimum number is:2
// 2nd Maximum number is:5


import java.util.Scanner;

class A{
    void find(int a[],int len){
        System.out.println("2nd Maximum number is:"+ a[len-2]);
    }
}

class B extends A{
    void find(int a[],int len){
        System.out.println("2nd Minimum number is:"+a[1]);
        super.find(a, len);
    }
}

public class runProgram {
    
    public static void main(String[] args) {
        
        Scanner sc = new Scanner(System.in);
        
        System.out.println("Enter array length:");
        
        int len = sc.nextInt();
        
        int a[] = new int[len];
        
        System.out.println("Enter array element:");
        for(int i =0;i<len;i++){
            a[i]=sc.nextInt();
        }

        for (int i = 0; i < len - 1; i++) {
            for (int j = 0; j < len - i - 1; j++) {
                if (a[j] > a[j + 1]) {
                    int temp = a[j];
                    a[j] = a[j + 1];
                    a[j + 1] = temp;
                }
            }

        }
        B ob = new B();
        ob.find(a, len);
    }

}
