class Solution {
public:
//     int kthSmallest(vector<vector<int>>& matrix, int k) {
//         priority_queue<int> pq; //max heap
//         for(int i = 0; i < matrix.size(); i++){
//             for(int j = 0; j < matrix[0].size(); j++){
//                 pq.push(matrix[i][j]);
//                 if (pq.size() > k){
//                     pq.pop();        
//                 }
                
//             }
//         }
        
//         return pq.top();
        
//     }
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        
        int n = matrix.size();
        int low = matrix[0][0];
        int high = matrix[n-1][n-1];
        while(low < high){
            
            int mid = low + (high - low)/2;
            int count = 0;
            for(int i = 0; i < n; i++){
                count += upper_bound(matrix[i].begin(), matrix[i].end(), mid) - matrix[i].begin();
                
            }
            
            if(count < k){
                low = mid + 1;
            }else{
                high = mid;
            }
            
        }
        
        return low;
    }
};
