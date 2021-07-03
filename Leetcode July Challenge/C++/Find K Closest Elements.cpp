// Two Pointer Approach
/*
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int left = 0, right = arr.size()-1;
        
        while (right - left + 1 > k) {
            
            if (arr[right] - x < x - arr[left]) left++;
            else right--;
        }
        
        return vector<int>(arr.begin() + left, arr.begin() + right + 1);
        
    }
};
*/

// Binary Search Approach
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int lo = 0, hi = arr.size()-k;
        while (lo < hi){
            
            int mid = lo + (hi - lo)/2;
            if(x - arr[mid] > arr[mid + k] - x){
                lo = mid + 1;
            }else{
                hi = mid;
            }
            
        }
        
        vector<int> ans;
        for(int i=0;i<k;i++){
            ans.push_back(arr[lo+i]);
        }
        
        return ans;
        
    }
};
