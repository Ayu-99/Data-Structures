class Solution {
	vector<int> original;
	int n;
    
public:

	Solution(vector<int>& nums) {
		original = nums;
		n = original.size();
	}
	
	vector<int> reset() {
		return original;
	}
	
	vector<int> shuffle() {
			vector<int> shuffled = original;
			
			int leftSize = n;
			for(int i = n-1; i>=0; i--) {
				int j = rand() % leftSize;
				swap(shuffled[i], shuffled[j]);
				leftSize--;
			}
			return shuffled;
	}
	
};
