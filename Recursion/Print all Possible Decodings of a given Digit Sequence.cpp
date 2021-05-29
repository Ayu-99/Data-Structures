#include<bits/stdc++.h>
#include <string.h>
using namespace std;


void printAllPossibleCodes(string input, string output){
    //Base Case
    if(input.empty()){
        cout<<output<<endl;
        return;
    }
    
    char c1=input[0]-'0'+'a'-1;
    int b=stoi(input.substr(0,2));
    char c2=b-1+'a';
    printAllPossibleCodes(input.substr(1), output+c1);
    if( b>=10 && b<=26){
        printAllPossibleCodes(input.substr(2), output+c2);    
    }
    
        
}

void printAllPossibleCodes(string input) {
    string output="";
    printAllPossibleCodes(input, output);
    
}

int main(){
    string s="1123";
    printAllPossibleCodes(s);
    return 0;
}
