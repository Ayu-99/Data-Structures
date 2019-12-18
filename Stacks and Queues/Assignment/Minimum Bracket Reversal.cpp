/*
Given a string expression which consists only ‘}’ and ‘{‘. The expression may not be balanced. You need to find the minimum number of bracket reversals which are required to make the expression balanced.
Return -1 if the given expression can't be balanced.
Input Format :
String S
Output Format :
Required count
Sample Input 1 :
{{{
Sample Output 1 :
-1
Sample Input 2 :
{{{{}}
Sample Output 2 :
1
*/

#include<string.h>
#include<stack>
int countBracketReversals(char input[]){
	// Write your code here
    int size=strlen(input);
    int count=0;
    stack<int> s;
    if(size%2!=0){
        return -1;
    }else{
             for(int i=0;i<size;i++){
                 if(input[i]=='{'){
                     s.push(input[i]);
                     
                 }else{
                     if(s.size()==0){
                         s.push(input[i]);
                     
                     }else if(s.size()!=0 && s.top()=='{'){
                         s.pop();
                     
                     }else{
                         s.push(input[i]);
                     }
                     
                 }
             }
        
            while(s.size()!=0){
                char c1=s.top();
                s.pop();
                char c2=s.top();
                s.pop();
                
                if(c1==c2){
                    count++;
                }else{
                    count=count+2;
                }
                
            }
        
    }
    
    return count;
}
