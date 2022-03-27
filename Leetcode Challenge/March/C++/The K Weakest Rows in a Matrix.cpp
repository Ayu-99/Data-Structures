class Solution {
    int calculateSoldierCount(vector<int>& v) {
        int l=0; int h=v.size()-1;
        while(l<=h) { 
            int mid=l+(h-l)/2;
            if(v[mid]==0) {
                h=mid-1;
            } else {
                l=mid+1;
            }
        }
        return l;
    }
    
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
     
        priority_queue<pair<int,int>> max_heap;
   
        for(int i=0;i<mat.size();++i){
            max_heap.push({calculateSoldierCount(mat[i]),i});
            if(max_heap.size()>k){
                max_heap.pop();
            }
        }
        
        vector<int>ans;
        while(max_heap.size()){ 
            ans.push_back(max_heap.top().second);
            max_heap.pop();
        }
		
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
