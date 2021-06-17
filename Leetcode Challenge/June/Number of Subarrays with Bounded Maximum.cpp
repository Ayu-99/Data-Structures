class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& A, int L, int R) {
        
        int i = 0, j = 0, count = 0, m = 0;
        
        while (j < A.size()){
            
            if(A[j] > R)
            {
                m = 0;
                i = j + 1;
            
            }
            
            else if(A[j] >= L && A[j] <= R)
            {
                m = j - i + 1; 
            }
            
            count += m;
            j++;
            
        }
        
       return count;
    }
};
