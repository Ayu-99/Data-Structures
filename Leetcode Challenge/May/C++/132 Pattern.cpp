class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        // for(int i = 0; i < nums.size(); i++){
        //     for(int j = i + 1; j < nums.size(); j++){
        //         for(int k = j + 1; k < nums.size(); k++){
        //             if(nums[k] > nums[i] && nums[j] > nums[k]) return true;
        //         }
        //     }
        // }
        // return false;
//         int mine = nums[0];
        
//         for(int j = 0; j < nums.size() - 1; j++){
//             for(int k = j + 1; k < nums.size(); k++){
//                 if(nums[k] > mine && nums[j] > nums[k]) return true;
//                 mine = min(mine, nums[j]);
//             }
//         }
//         return false;
    
        stack<int> st;
        
        int thirdElement = INT_MIN; //nums[k]
        
        for(int i = nums.size() - 1; i >= 0; i--){
            if(nums[i] < thirdElement) return true;
            while(!st.empty() && st.top() < nums[i]) {
                thirdElement = st.top();
                st.pop();
            } 
            st.push(nums[i]);
        }
        return false;
    }

};
