class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int len_s = s.size();
        int len_p = p.size();
        
        if(len_s < len_p) return {};
        
        vector<int> p_freq(26,0);
        vector<int> window(26,0);
        
        //first window
        for(int i=0;i<len_p;i++){
            p_freq[p[i]-'a']++;
            window[s[i]-'a']++;
        }
        
        vector<int> ans;
        if(p_freq == window) ans.push_back(0);
        
        for(int i=len_p;i<len_s;i++){
            window[s[i-len_p] - 'a']--;
            window[s[i] - 'a']++;
            
            if(p_freq == window) ans.push_back(i-len_p+1);
        }
        return ans;
    }
};
