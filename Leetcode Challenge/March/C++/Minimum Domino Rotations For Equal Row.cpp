class Solution {
public:
    int minDominoRotations(vector<int>& A, vector<int>& B) {
        vector<int> countA(7), countB(7), countSame(7);
        int n = A.size();
        for (int i = 0; i < n; i++) {
            int a = A[i], b = B[i];
            countA[a] += 1;
            countB[b] += 1;
            if (a == b) countSame[a] += 1;
        }
        int ans = -1
        for (int v = 1; v <= 6; v++) {
            if (countA[v] + countB[v] - countSame[v] == n) {
                int ans = min(countA[v], countB[v]) - countSame[v];              
            }
        }   
        return ans ;
    }
};
