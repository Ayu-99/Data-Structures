/*
Code : Minimum Count
Send Feedback
Given an integer N, find and return the count of minimum numbers, sum of whose squares is equal to N.
That is, if N is 4, then we can represent it as : {1^2 + 1^2 + 1^2 + 1^2} and {2^2}. Output will be 1, as 1 is the minimum count of numbers required.
Note : x^y represents x raise to the power y.
Input Format :
Integer N
Output Format :
Required minimum count
Constraints :
1 <= N <= 1000
Sample Input 1 :
12
Sample Output 1 :
3
Sample Output 1 Explanation :
12 can be represented as :
1^1 + 1^1 + 1^1 + 1^1 + 1^1 + 1^1 + 1^1 + 1^1 + 1^1 + 1^1 + 1^1 + 1^1
1^1 + 1^1 + 1^1 + 1^1 + 1^1 + 1^1 + 1^1 + 1^1 + 2^2
1^1 + 1^1 + 1^1 + 1^1 + 2^2 + 2^2
2^2 + 2^2 + 2^2
As we can see, the output should be 3.
Sample Input 2 :
9
Sample Output 2 :
1

*/

//Using Memoization
#include<cmath>

int minCountHelper(int n, int *arr){
    
    if(n<=3){
        return n;
    }
   
    if(arr[n]!=-1){
        return arr[n];
    }
    
    int count=n;
    for(int i=1;i<=n;i++){
        int temp=i*i;
        if(temp>n){
           break; 
        }
        
        count=min(count, minCountHelper(n-temp, arr)+1);
        arr[i]=count;
        
    }
    
    
    return count;
    
}
int minCount(int n){
    
    /*  Don't write main().
     *  Don't read input, it is passed as function argument.
     *  Return output and don't print it.
     *  Taking input and printing output is handled automatically.
     */
    
    int *arr=new int[n+1];
    for(int i=0;i<=n;i++){
        arr[i]=-1;
    }
    
    return minCountHelper(n, arr);
    
}
