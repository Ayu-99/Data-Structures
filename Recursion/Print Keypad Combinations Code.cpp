#include <iostream>
#include <string>
using namespace std;

void printKeypad(int num, string output, string options[]){
    if(num==0){
        cout<<output<<endl;
        return;
    }
    int n1=num%10;  //last digit
    string s1=options[n1];
    for(int i=0;i<s1.length();i++){
        printKeypad(num/10, s1[i]+output, options);
    }
}

void printKeypad(int num){
    string output="";
    string options[]={"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
                      0   1    2       3      4                                   9
    printKeypad(num, output, options);
    
}
