public class BinarySearch {

    public static int binarySearch(int[] arr, int target) {
        int low = 0;
        int high = arr.length - 1;

        while (low <= high) {
            int mid = low + (high - low) / 2; // prevents overflow

            if (arr[mid] == target) {
                return mid;          // found
            } else if (arr[mid] < target) {
                low = mid + 1;       // go right
            } else {
                high = mid - 1;      // go left
            }
        }
        return -1; // not found
    }

    public static void main(String[] args) {
        int[] arr = {1, 3, 5, 7, 9, 11};
        int target = 7;
        System.out.println(binarySearch(arr, target)); // Output: 3
    }
}
