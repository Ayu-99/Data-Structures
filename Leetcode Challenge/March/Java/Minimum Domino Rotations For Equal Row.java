class Solution {
    public int minDominoRotations(int[] A, int[] B) {
        int[] countA = new int[7], countB = new int[7], countSame = new int[7];
        int n = A.length;
        for (int i = 0; i < n; i++) {
            int a = A[i], b = B[i];
            countA[a] += 1;
            countB[b] += 1;
            if (a == b) countSame[a] += 1;
        }
        int ans = n;
        for (int v = 1; v <= 6; v++) {
            if (countA[v] + countB[v] - countSame[v] == n) {
                int minSwap = Math.min(countA[v], countB[v]) - countSame[v];
                ans = Math.min(ans, minSwap);
            }
        }   
        return ans == n ? -1 : ans;
    }
}
