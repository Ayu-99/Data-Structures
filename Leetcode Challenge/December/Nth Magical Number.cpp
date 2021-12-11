class Solution {
public:
    int nthMagicalNumber(int n, int a, int b) {
//         int ans=0;
//         int i=1;
//         int number=2;
//         while(i<=n) {
//             if(number%a==0 || number%b==0) {
//                 if(i==n){
//                     ans=number;
//                     break;
//                 }
//                 i++;
//             }
            
//             number++;
            
//         }
        
//         ans = number;
//         return ans;
        
        
        long A = a, B = b;
        long mod = (long)(pow(10,9)+7);
        
        
        long left = min(a,b), right = (long)n*min(a,b);
        
		// Finding GCD
        while (B > 0) {
            long tmp = A;
            A = B;
            B = tmp % B;
        }
		
        long lcm = (a*b)/A;     //(n1*n2)/GCD
		
        while (left < right) {
            long m = left+(right-left)/2;
			
            if ((m / a) + (m / b) - (m / lcm) < n) left = m + 1;   
			
            else right = m;
        }
        return (int)(left % mod);
    }
};
