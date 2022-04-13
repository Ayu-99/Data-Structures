class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n, vector<int> (n, 1));
        int left = 0, right = n-1, top = 0, down = n-1, index = 1;
        
        while (left <= right && top <= down) {
            //first row
            for (int j = left; j <= right; j++) {
                ans[top][j] = index;
                index++;
            }
                
            top++;
            
            //last col
            for (int i = top; i <= down; i++) {
                ans[i][right] = index;
                index++;
            }
            
            right--;
            
            //last row
            for (int j = right; j >= left; j--) {
                ans[down][j] = index;
                index++;
            }
            
            down--;
            
            //first col
            for (int i = down; i >= top; i--) {
                ans[i][left] = index;
                index++;
            }
            
            left++;
        }
        return ans;
    }
};
