//brute
import java.util.HashMap;

int singleNumber(int[] nums) {
    HashMap<Integer, Integer> freq = new HashMap<>();

    // Count frequency
    for (int num : nums) {
        freq.put(num, freq.getOrDefault(num, 0) + 1);
    }

    // Find element appearing once
    for (int num : nums) {
        if (freq.get(num) == 1) {
            return num;
        }
    }

    return -1; // should never happen
}



//optimized
int singleNumber(int[] nums) {
    int result = 0;

    for (int bit = 0; bit < 32; bit++) {
        int count = 0;

        for (int num : nums) {
            if ((num & (1 << bit)) != 0) {
                count++;
            }
        }

        if (count % 3 != 0) {
            result |= (1 << bit);
        }
    }

    return result;
}
