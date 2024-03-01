class Solution {
public:
    string maximumOddBinaryNumber(string s) {
        int countOnes=0, countZeros=0;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '1') countOnes++;
            if (s[i] == '0') countZeros++;
        }
        
        string ans;
        ans = string(countOnes-1, '1') + string(countZeros, '0') + '1';
        return ans;
        
        
        // sort(s.rbegin(),s.rend());
        // for(int i = s.size()-1;i>=0;i--){
        //     if(s[i]=='1')swap(s[i],s[s.size()-1]);
        // }
        // return s;
    }
};
