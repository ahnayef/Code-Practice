// Question: Write a program that calculates the nth Fibonacci number using recursion.


import java.util.Scanner;

class myFibo {
    static int[] dp = new int[100];

    int getFibo(int n) {

        if (n == 1) {
            return 0;
        }
        if (n == 2) {
            return 1;
        }

        return getFibo(n - 1) + getFibo(n - 2);
    }
}

class runProgram{
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        myFibo ob = new myFibo();

        System.out.print("Enter the position of the Fibonacci number to retrieve: ");

        int n = sc.nextInt();
        
        System.out.println(ob.getFibo(n));
    }

}
