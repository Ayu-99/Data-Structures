class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        if(!matrix.size()){
            return false;
        }
        
        int n=matrix.size(); //rows
        int m=matrix[0].size(); //cols
        
        int lo=0;
        int h= (n*m)-1;
        
        while(lo<=h){
            
            
            int mid= (lo +(h-lo)/2);
            if(matrix[mid/m][mid%m]==target){
                return true;
            }
            
            else if(matrix[mid/m][mid%m] < target){
                lo=mid+1;
            }else{
                h=mid-1;
            }
        }
        return false;
    }
};
