public List<List<Integer>> combinationSum(int[] candidates, int target) {
	List<List<Integer>> list = new ArrayList<>();
	combinationUtil(list, new ArrayList<>(), candidates, 0, target);
	return list;
}

public void combinationUtil(List<List<Integer>> list, List<Integer> temp, int[] candidates, int start, int target) {
	// base case
	if(target == 0) {
		list.add(new ArrayList<>(temp));
		return;
	}

	// recursion step
	for(int i = start; i < candidates.length; i++) {
		if(target < candidates[i]) continue;

		temp.add(candidates[i]);
		combinationUtil(list, temp, candidates, i, target - candidates[i]);
		temp.remove(temp.size() - 1);
	}
}
