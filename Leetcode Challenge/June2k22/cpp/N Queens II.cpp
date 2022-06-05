class Solution {
public:
    int totalNQueens(int n) {
        vector<bool> col(n, true);
        vector<bool> antiD(2*n-1, true);
        vector<bool> mainD(2*n-1, true);
        vector<int> row(n, 0);
        int count = 0;
        dfs(0, row, col, mainD, antiD, count);
        return count;
    }
    void dfs(int i, vector<int> &row, vector<bool> &col, vector<bool>& mainD, vector<bool> &antiD, int &count) {
            if (i == row.size()) { //filled all the rows with queens
                count++;
                return;
            }
           for (int j = 0; j < col.size(); j++) {
             if (col[j] && mainD[i+j] && antiD[i+col.size()-1-j]) {
                 row[i] = j; 
                 col[j] = mainD[i+j] = antiD[i+col.size()-1-j] = false;
                 dfs(i+1, row, col, mainD, antiD, count);
                 //backtracking
                 col[j] = mainD[i+j] = antiD[i+col.size()-1-j] = true;
          }
        }
    }
};
