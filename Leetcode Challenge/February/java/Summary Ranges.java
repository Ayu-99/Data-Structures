public List<String> summaryRanges(int[] nums) {
    int length = nums.length;
    List<String> result = new ArrayList<String>(length);
    for (int i = 0; i < length; i++) {
        int num = nums[i];
        while (i < length - 1 && nums[i] + 1 == nums[i + 1]) {
            i++;
        }
        if (num != nums[i]) {
            result.add(num + "->" + nums[i]);
        } else {
            result.add(num + "");
        }
    }
    return result;
}
