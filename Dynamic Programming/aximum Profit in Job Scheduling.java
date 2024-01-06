import java.util.*;
class Solution {
    
//     public int dfs1(int[][] jobs, int idx, int prevEndTime, int[] dp, int n) {
//         if (idx >= n) return 0;
//         if (dp[prevEndTime] != -1) return dp[prevEndTime];
        
//         int skipIt = dfs1(jobs, idx+1, prevEndTime, dp, n);
//         int takeIt = (jobs[idx][0] >= prevEndTime) ? (jobs[idx][2] + dfs1(jobs, idx+1, jobs[idx][1], dp, n)): 0;
        
//         dp[idx] = Math.max(skipIt, takeIt);
//         return dp[idx];
        
//     }
    
    public int dfs2(int[][] jobs, int idx, int[] dp, int n) {
        if (idx >= n) return 0;
        if (dp[idx] != -1) return dp[idx];
        int start = idx+1, end = n-1, nextJobIndex = n+1;
        while (start <= end) {
            int mid = start + (end-start)/2;
            if (jobs[mid][0] >= jobs[idx][1]) {
                nextJobIndex = mid;
                end = mid-1;
            }else {
                start = mid+1;
            }
        }
        dp[idx] = Math.max(dfs2(jobs, idx+1, dp, n), jobs[idx][2] + dfs2(jobs, nextJobIndex, dp, n));
        return dp[idx];
    }
    
    public int jobScheduling(int[] startTime, int[] endTime, int[] profit) {
        int n = startTime.length;
        int[][] jobs = new int[n][3];
        int dp[] = new int[n];
        Arrays.fill(dp, -1);
        
        for(int i=0; i<n; i++) {
            jobs[i][0] = startTime[i];
            jobs[i][1] = endTime[i];
            jobs[i][2] = profit[i];
        }
        
        Arrays.sort(jobs, Comparator.comparingInt(a->a[0]));
        return dfs2(jobs, 0, dp, n);  
    }
    
//     public int jobScheduling(int[] startTime, int[] endTime, int[] profit) {
//         int n = startTime.length;
//         int[][] jobs = new int[n][3];
//         int dp[] = new int[1000001];
//         Arrays.fill(dp, -1);
        
//         for(int i=0; i<n; i++) {
//             jobs[i][0] = startTime[i];
//             jobs[i][1] = endTime[i];
//             jobs[i][2] = profit[i];
//         }
        
//         Arrays.sort(jobs, Comparator.comparingInt(a->a[0]));
//         return dfs1(jobs, 0, 1, dp, n);
//     }
}
