class Solution {
public:
    int fib(int n) {
        
        int a=0, b=1, count=2, c;
        if(n == 0 || n==1) return n;
        
        while(count <= n) {
            c = a+b;
            a=b;
            b=c;
            count++;
        }
        return c;
    }
};
