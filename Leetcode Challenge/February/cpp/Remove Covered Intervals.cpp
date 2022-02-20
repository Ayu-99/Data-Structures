class Solution {
public:
        int removeCoveredIntervals(vector<vector<int>>& A) {
        int res = 0, left = -1, right = -1;
        sort(A.begin(), A.end());
        for (auto& v: A) {
            if (v[0] > left && v[1] > right) {
                left = v[0];
                ++res;
            }
            right = max(right, v[1]);
        }
        return res;
    }
}; 
