vector<vector<int>> dp(50001, vector<int>(51, 0));
class Solution {
public:
    
    
    int numMatchingSubseq(string s, vector<string>& words){
        
        vector<vector<int>> charIndexes(26);
        for(int i = 0;i < s.size(); i++){
            charIndexes[s[i]-'a'].push_back(i);
        }
        
        int count = 0;
        
        for(int i = 0;i< words.size();i++){
            bool isSubseq = true;
            int lastCharIndex = -1;
            for(char w : words[i]){
                auto it = upper_bound(charIndexes[w - 'a'].begin(), charIndexes[w - 'a'].end(), lastCharIndex);
                if(it==charIndexes[w - 'a'].end()){
                    isSubseq = false;
                    break;
                }
                else{
                    lastCharIndex = *it;
                }
                
            }
            
            if(isSubseq){
                count++;
            }
            
            
        }
        
        
        return count;
        
    }
    
    
};
