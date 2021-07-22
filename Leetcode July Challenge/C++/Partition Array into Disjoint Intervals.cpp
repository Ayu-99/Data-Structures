class Solution {
public:
    int partitionDisjoint(vector<int>& A) {
        
        int localMax = A[0], globalMax = A[0], pi=0;
        for(int i = 1; i < A.size(); i++){
            globalMax = max(globalMax, A[i]);
            if(localMax > A[i]){
                pi = i;
                localMax = globalMax;
            }
        }
        
        return pi+1;
//         int maxLeft = INT_MIN;
//         vector<int> minRight(A.size());
         
//         minRight[A.size()-1]=A.back();
        
//         for(int i=A.size()-2; i>=0; i--){
//             minRight[i]=min(A[i], minRight[i+1]);
//         }
            
        
//         for(int i = 0 ; i < A.size() - 1; i++){
//             maxLeft = max(maxLeft, A[i]);
//             if(maxLeft <= minRight[i+1]){
//                 return i+1;
//             }
//         }
//         return -1;
//         vector<int> maxLeft(A.size()), minRight(A.size());
//         maxLeft[0]=A[0]; 
//         minRight[A.size()-1]=A.back();
        
//         for(int i=1; i<A.size(); i++){
//             maxLeft[i]=max(A[i], maxLeft[i-1]);
//         }
//         for(int i=A.size()-2; i>=0; i--){
//             minRight[i]=min(A[i], minRight[i+1]);
//         }
            
        
//         for(int i = 0; i < A.size()-1; i++)
//             if(maxLeft[i] <= minRight[i+1])
//                 return i + 1;
        
//         return -1;
    }
};
