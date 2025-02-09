class Solution {

    public long countBadPairs(int[] nums) {
        long badPairs = 0;
        Map<Integer, Integer> diffCount = new HashMap<>();

        for (int pos = 0; pos < nums.length; pos++) {
            int diff = pos - nums[pos];

            int goodPairsCount = diffCount.getOrDefault(diff, 0);

            badPairs += pos - goodPairsCount;
            diffCount.put(diff, goodPairsCount + 1);
        }

        return badPairs;
    }
}
