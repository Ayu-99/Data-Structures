class Solution {
public:
    string removeDuplicates(string s, int k) {
        int n = s.size();
        if(n<k) return s;
        
        stack<pair<char,int>> stack;
        for(int i=0; i<n; ++i){
            if(stack.empty() || stack.top().first != s[i]){
                stack.push({s[i],1});  
            } 
            else{
                auto prev = stack.top();
                stack.pop();
                stack.push({s[i], prev.second+1});
            }
            if(stack.top().second==k) stack.pop();
        }
        
        string ans = "";
        while(!stack.empty()){
            auto cur = stack.top();
            stack.pop();
            while(cur.second--){
                ans.push_back(cur.first);
            }
        }
        
        return ans;
    }
};
