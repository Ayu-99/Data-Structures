class Solution {
    public int longestSubarray(int[] nums, int limit) {
        LinkedList<Integer> inc = new LinkedList<>();
        LinkedList<Integer> dec = new LinkedList();
        int maxLength=0, left=0;

        for(int i=0; i<nums.length; i++) {
            int el = nums[i];
            while (inc.size() > 0 && el < inc.getLast()) {
                inc.removeLast();
            }
            inc.add(el);

            while (dec.size() > 0 && el > dec.getLast()) {
                dec.removeLast();
            }

            dec.add(el);

            while(dec.getFirst() - inc.getFirst() > limit) {
               if (nums[left] == dec.getFirst()) {
                    dec.removeFirst();
                }
                if (nums[left] == inc.getFirst()) {
                    inc.removeFirst();
                }
                left++;
            }

            int size = i - left + 1;
            maxLength = Math.max(maxLength, size);

        }

        return maxLength;
    }
}
