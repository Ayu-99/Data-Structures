#include<bits/stdc++.h>
using namespace std;

void printPermutations(string s,string output){
    if(s==""){ //base case
        cout<<output<<endl;
        return;
    }
    
    for(int i=0;i<s.length();i++){
        printPermutations(s.substr(0,i)+s.substr(i+1), output+s[i]);
        
    }
    
}

int main(){
    string s="cba";
    string output="";
    printPermutations(s, output);
    return 0;
}

//Time complexity n!
