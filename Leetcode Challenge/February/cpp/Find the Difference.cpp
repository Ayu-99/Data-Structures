class Solution {
public:
    char findTheDifference(string s, string t) {
//         int a = 0;
//         int b = 0;
//         for (char c : s)
//             a += c;
//         for (char c : t)
//             b += c;
            
//         return b - a; //extra letter ascii
        
        char r=0;
        for(char c:s) r ^=c;
        for(char c:t) r ^=c;
        return r;
    }
};
