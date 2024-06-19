import java.util.Scanner;

class findMod {

    int performAddMod(int a, int b, int m) {

        return (a + b) % m;
    }

    int performMulMod(int a, int b, int m) {
        return (a * b) % m;
    }

}

class Task2 {
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        int num1 = sc.nextInt();
        int num2 = sc.nextInt();
        int num3 = sc.nextInt();

        findMod val = new findMod();

        int add = val.performAddMod(num1, num2, num3);
        int mul = val.performMulMod(num1, num2, num3);

        String res = add > mul ? "Addition is Larger" : "Multiplication is Larger than Addition";

        System.out.println(res);

    }
}
