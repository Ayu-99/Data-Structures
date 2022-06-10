class Solution {
public:
	int lengthOfLongestSubstring(string s) 
	{
        int count[256]={0}; 
        int l=0; //i - starting index of window   
        int r=0;  //j - ending index of window
        int ans=0; //length of longest substring no repeating char
        
        while(r<s.length())     
        {
            count[s[r]]++;      
            
            while(count[s[r]]>1)   
            { 
                count[s[l]]--;   
                l++;         
            }
            
            ans = max(ans,r-l+1);   
            r++;   
        }    
        return ans;
        
	}
    
};
