//brute
import java.util.HashMap;
import java.util.Map;

class TwoUniqueHashMap {
    public static void findTwoUniques(int[] nums) {
        HashMap<Integer, Integer> map = new HashMap<>();

        // Count frequency
        for (int num : nums) {
            map.put(num, map.getOrDefault(num, 0) + 1);
        }

        // Print elements with frequency 1
        for (Map.Entry<Integer, Integer> entry : map.entrySet()) {
            if (entry.getValue() == 1) {
                System.out.print(entry.getKey() + " ");
            }
        }
    }

    public static void main(String[] args) {
        int[] arr = {1, 2, 1, 3, 2, 5};
        findTwoUniques(arr);
    }
}


//optimized
class TwoSingleNumbers {
    public static int[] singleNumber(int[] nums) {
        int xor = 0;

        for (int num : nums) {
            xor ^= num;
        }

        int diffBit = xor & (-xor); // rightmost set bit

        int x = 0, y = 0;
        for (int num : nums) {
            if ((num & diffBit) == 0) {
                x ^= num;
            } else {
                y ^= num;
            }
        }
        return new int[]{x, y};
    }

    public static void main(String[] args) {
        int[] arr = {1, 2, 1, 3, 2, 5};
        int[] res = singleNumber(arr);
        System.out.println(res[0] + " " + res[1]);
    }
}
