
class Solution{
    public:
    string removeConsecutiveCharacter(string s)
    {
        // code here.
        int n = s.size();
        //base case
        if(n == 0 || n == 1){
            return s;
        }
        
        //small work
        if(s[0] == s[1]){
            int index = 0;
            while(s[index] == s[0] && index < n){
                index++;
            }
            return s[0] + removeConsecutiveCharacter(s.substr(index));
        }
        
        return s[0] + removeConsecutiveCharacter(s.substr(1));
        
        
    }
};
