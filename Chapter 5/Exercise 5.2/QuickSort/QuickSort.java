public class QuickSort {
    static int partition(char[] arr, int low, int high) {
        int pivot = arr[high];
        int lower = low - 1;

        for (int j = low; j < high; j++) {
            if (arr[j] <= pivot) {
                lower++;

                // Swap
                char temp = arr[lower];
                arr[lower] = arr[j];
                arr[j] = temp;
            }
        }
        char temp = arr[lower + 1];
        arr[lower + 1] = arr[high];
        arr[high] = temp;
        return lower + 1;
    }

    static void quickSort(char[] arr, int low, int high) {
        if (low < high) {
            int part = partition(arr, low, high);

            quickSort(arr, low, part - 1);
            quickSort(arr, part + 1, high);
        }
    }

    public static void main(String[] args) {
        char[] example = "EXAMPLE".toCharArray();

        quickSort(example, 0, example.length - 1);
        System.out.print("The Sorted Array: ");
        for (int i = 0; i < example.length; i++) {
            System.out.print(example[i] + " ");
        }
        System.out.println();
    }

    
}