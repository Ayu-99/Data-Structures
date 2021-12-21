class Solution {
public:
    bool isPowerOfTwo(int n) {
        return n>0 && !(n&(n-1));
        
//         if(n==0) return false;
//         return (ceil(log2(n)) == floor(log2(n)));
        
        // if (n == 0) return false;
        // while (n != 1)
        // {
        //     if (n%2 != 0)
        //         return false;
        //     n = n/2;
        // }
        // return true;

    }
};
