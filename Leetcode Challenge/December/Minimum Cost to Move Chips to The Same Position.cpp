class Solution {
public:
    int minCostToMoveChips(vector<int>& position) {
        
        int even = 0, odd = 0;
        for (auto chip : position) {
            if (chip % 2 == 0) {
                even++;
            } else {
                odd++;
            }
        }
        
        return min(even, odd);
    }
};
