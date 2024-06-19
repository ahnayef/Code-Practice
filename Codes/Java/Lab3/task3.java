// Question: Write a program that finds the second largest number in two different arrays using the same method in a class.



import java.util.Scanner;

class Demo {
    
    int SecondLargest(int arr[]) {
        for (int i = 0; i < arr.length - 1; i++) {
            for (int j = 0; j < arr.length - i - 1; j++) {
                if (arr[j] > arr[j + 1]) {
                    int temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }
        return arr[arr.length - 2];
    }
}

class runProgram {
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        Demo ob = new Demo();

        System.out.print("Enter arr1 length:");
        int n1 = sc.nextInt();
        int arr1[] = new int[n1];

        System.out.print("Enter " + n1 + " element:");
        for (int i = 0; i < arr1.length; i++) {
            arr1[i] = sc.nextInt();
        }

        System.out.print("Enter arr2 length:");
        int n2 = sc.nextInt();
        int arr2[] = new int[n2];

        System.out.print("Enter " + n2 + " element:");
        for (int i = 0; i < arr2.length; i++) {
            arr2[i] = sc.nextInt();
        }

        System.out.println("Second Largest in arr1: " + ob.SecondLargest(arr1));
        System.out.println("Second Largest in arr2: " + ob.SecondLargest(arr2));

        System.out.println();

    }
}
