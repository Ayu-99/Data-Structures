// class Solution {
// public:
    
//     int countSetBits(int n)
//     {
//         int count = 0;
//         while (n) {
//             int rsb = n & -n;
//             n -= rsb;
//             count++;
//         }
//         return count;
//     }
    
//     vector<int> countBits(int n) {
//         vector<int> ans;
		
//         for(int i = 0; i<=n; i++)
//         {
//             ans.push_back(countSetBits(i));
       
//         }
//         return ans;
//     }
// };

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> l;
        l.push_back(0);
        
        for(int i = 1; i< n+1; i++){
            if (i%2 != 0){ // i is odd
                
                l.push_back(l[i/2]+1);
            
            } else{ // i is even
                l.push_back(l[i/2]);
            }    
        }
        return l; 
    }
};
