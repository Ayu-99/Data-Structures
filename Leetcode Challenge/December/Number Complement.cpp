class Solution {
public:
    
    int findComplement(long num) {
        for(long i=1;i<=num;i*=2) num^=i; 
        return num;
    }
};
