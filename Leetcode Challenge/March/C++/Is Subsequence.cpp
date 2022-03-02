// class Solution {
// public:
//     bool isSubsequence(string s, string t) {
//         unordered_map<char, vector<int>> hg; 
//         for(int i=0; i<t.length();i++) hg[t[i]].push_back(i);
        
//         int prev = -1;
//         for(auto c : s){
//             auto it = hg.find(c);
//             if(it == hg.end()) return false;
//             auto vec = it->second;
//             int pos = upper_bound(vec.begin(), vec.end(), prev) - vec.begin(); 
//             if(pos == vec.size()) return false;
//             prev = vec[pos];
//         }
//         return true;
//     }
// };

class Solution {
public:
    bool isSubsequence(string s, string t) {
        if(s == ""){
            return true;
        }
        if(t == ""){
            return false;
        }    

        if(s.size() == 1 && t.size() == 1){
            return s[0] == t[0];
        }    

        int a = 0;
        for(int i=0; i<t.size();i++){
            
            if(s[a] == t[i]){
                a += 1;
            }
        }     
        
        
        if(a == s.size()){
            return true;
        }    
        else{
            return false;
        }    
    }
};
