class Solution {
public:
    
    bool dfs(vector<int> matchsticks, int target, vector<int> &sides, int idx){
        
        // base case
        if(idx == matchsticks.size()){
            if(sides[0] == sides[1] && sides[1] == sides[2] && sides[2] == sides[3]){
                return true;
            }
            return false;
        }
        
        for(int i = 0; i < 4; i++){
            if (sides[i] + matchsticks[idx] > target){  //optimization - 1
                continue;
            }
            int j = i - 1;  //optimization - 3
            while (j>=0){
                if(sides[j] == sides[i]){
                    break;
                }
                
                j -= 1;
            }
            
            if(j != -1){
                continue;
            }
            
            
            sides[i] += matchsticks[idx];
            
            if( dfs(matchsticks, target, sides, idx+1) ){
                return true;
            }
            sides[i] -= matchsticks[idx];
        }
        
        return false;
    
        
    }
    
    
    bool makesquare(vector<int>& matchsticks) {
        
        if(matchsticks.size() == 0){
            return false;
        }
        
        int sum = 0;
        for(int i = 0; i < matchsticks.size() ; i++){
            sum += matchsticks[i];
        }
        
        int target = sum / 4;
        vector<int> sides(4,0);
        sort(matchsticks.begin(), matchsticks.end(), greater<int>()); // optimization 2
        return dfs(matchsticks, target, sides, 0);
        
        
    }
};
