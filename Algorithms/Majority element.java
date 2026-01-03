//brute
import java.util.HashMap;

class MajorityElementHashMap {
    public static int majorityElement(int[] nums) {
        int n = nums.length;
        HashMap<Integer, Integer> map = new HashMap<>();

        for (int num : nums) {
            map.put(num, map.getOrDefault(num, 0) + 1);

            if (map.get(num) > n / 2) {
                return num;
            }
        }
        return -1; // will not be reached if majority exists
    }

    public static void main(String[] args) {
        int[] arr = {3, 3, 4};
        System.out.println(majorityElement(arr));
    }
}


//optimized
class MajorityElementOptimized {
    public static int majorityElement(int[] nums) {
        int result = 0;
        int count = 0;

        for (int num : nums) {
            if (count == 0) {
                result = num;
            }

            if (num == result) {
                count++;
            } else {
                count--;
            }
        }
        return result;
    }

    public static void main(String[] args) {
        int[] arr = {2, 2, 1, 2, 3};
        System.out.println(majorityElement(arr));
    }
}
