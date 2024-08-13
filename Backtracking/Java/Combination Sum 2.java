class Solution {

    public List<List<Integer>> combinationSum2(int[] candidates, int target) {
        List<List<Integer>> list = new LinkedList<List<Integer>>();
        Arrays.sort(candidates);
        backtrack(list, new ArrayList<Integer>(), candidates, target, 0);
        return list;
    }

    private void backtrack(
        List<List<Integer>> answer,
        List<Integer> tempList,
        int[] candidates,
        int totalLeft,
        int index
    ) {
        if (totalLeft < 0) return;
        else if (totalLeft == 0) { // Add to the answer array, if the sum is equal to target.
            answer.add(new ArrayList<>(tempList));
        } else {
            for (
                int i = index;
                i < candidates.length && totalLeft >= candidates[i];
                i++
            ) {
                if (i > index && candidates[i] == candidates[i - 1]) continue;
                // Add it to tempList.
                tempList.add(candidates[i]);
                // Check for all possible scenarios.
                backtrack(
                    answer,
                    tempList,
                    candidates,
                    totalLeft - candidates[i],
                    i + 1
                );
                // Backtrack the tempList.
                tempList.remove(tempList.size() - 1);
            }
        }
    }
}
