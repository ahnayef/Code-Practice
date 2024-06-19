import java.util.Scanner;

class AddN {

    AddN() {
        System.out.print("Sum: ");
    }

    AddN(int n) {
        this();
        System.out.println((n * (n + 1)) / 2);
    }

}

class Lab3Task1 {
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();

        AddN s = new AddN(n);
    }
}
