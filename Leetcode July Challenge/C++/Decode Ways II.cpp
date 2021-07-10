typedef long long ll;

class Solution {
public:
    
    
    ll mod = 1000000007;
    ll numDecodings(string &s, int idx, int len, vector<ll> &dp){
        if(idx == len){
            return 1;
        }
        
        if(s[idx] == '0'){
            return 0;
        }
        if(dp[idx] != -1){
            return dp[idx];
        }
        long long res = 0, mult = 1;
        if(s[idx] == '*'){
            mult = 9;
        }
        
        res += mult * numDecodings(s, idx + 1, len, dp);
        if( idx < len - 1){
            
            char next = s[idx + 1];
            int opts = 0;
            if(s[idx] == '*'){
                if(next == '*'){
                    opts = 15;
                }else{
                    if(next <= '6'){
                        opts = 2;
                    }else{
                        opts = 1;
                    }
                }
            }
            
            else if( s[idx] < '3'){
                if(next == '*'){
                    if(s[idx] == '1'){
                        opts = 9;
                    }
                    else{
                        opts = 6;
                    }
                }
                else{
                    if(stoi(s.substr(idx, 2)) <= 26){
                        opts = 1;
                    }    
                }
            }
            
            
            if(opts){
                res += opts* numDecodings(s, idx + 2, len, dp);
            }
            
            
        }
        return dp[idx]=res%(mod);
        
    }
    
    int numDecodings(string s) {
        
        int len = s.length();
        vector<ll> dp(len + 1, -1);
        return numDecodings(s, 0, len, dp);
    }
};
