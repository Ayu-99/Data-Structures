/*
Given a string expression, check if brackets present in the expression are balanced or not. Brackets are balanced if the bracket which opens last, closes first.
You need to return true if it is balanced, false otherwise.
Note: This problem was asked in initial rounds in Facebook
Sample Input 1 :
{ a + [ b+ (c + d)] + (e + f) }
Sample Output 1 :
true
Sample Input 2 :
{ a + [ b - c } ]
Sample Output 2 :
false
*/

#include<stack>
#include<string.h>
bool checkBalanced(char *exp) {
	// Write your code here
    
    
stack<char> s;
    for(int i=0;i<strlen(exp);i++){
        if(exp[i]=='(' || exp[i]=='[' || exp[i]=='{'){
            s.push(exp[i]);
            continue;
        }else if(exp[i]==')' || exp[i]==']' || exp[i]=='}'){
            if(s.size()!=0){
                if((exp[i]==')' && s.top()=='(') ||(exp[i]==']' && s.top()=='[') || (exp[i]=='}' && s.top()=='{') ){
                s.pop();
                continue;    
            }else{
                    return false;
                }
            
            }else{
                return false;
            }

        }else{
            continue;
        }
    }

        if(s.empty()==0){
            return false;
        }
        return true;
        
    

}
