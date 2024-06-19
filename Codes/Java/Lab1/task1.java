// Question: Create a program that sorts numbers using bubble sort, then finds a number using binary search. Both the array of numbers and the search number should be provided by the user. Print the sorted numbers and the found number's index or a not found message.



import java.util.Scanner;

class BubbleSort {
    void sort(int arr[], int n) {
        boolean swap;
        for (int i = 0; i < n - 1; i++) {
            swap = false;
            for (int j = 0; j < n - i - 1; j++) {
                if (arr[j] > arr[j + 1]) {
                    int temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                    swap = true;
                }
            }
            if (!swap) {
                break;
            }
        }
    }
}

class BinarySearch {
    int search(int arr[], int n, int search) {

        int lb = 0;
        int up = n - 1;
        int mid = (up + lb) / 2;

        while (lb <= up) {
            if (arr[mid] == search) {
                return mid;
            } else if (arr[mid] < search) {
                lb = mid + 1;
                mid = (up + lb) / 2;
            } else {
                up = mid - 1;
                mid = (up + lb) / 2;
            }
        }

        return -1;

    }
}

class Second {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();

        int arr[] = new int[n];

        for (int i = 0; i < n; i++) {
            arr[i] = sc.nextInt();
        }

        BubbleSort mySort = new BubbleSort();

        mySort.sort(arr, n);

        BinarySearch mySearch = new BinarySearch();

        for (int i = 0; i < n; i++) {
            System.out.format("%d ", arr[i]);
        }
        System.out.println("Search Item: ");

        int s = sc.nextInt();

        int searchItem = mySearch.search(arr, n, s);

        String stat = searchItem != -1 ? "Item not found" : "Item index" + searchItem;

        System.out.format("\n");
        System.out.println(stat);

    }

}
