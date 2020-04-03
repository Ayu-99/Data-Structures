/*
Given a string of lower case letters alphabets representing alphabetical order in an alien language. Sort the given list of words lexicographically according to that order.
Words will contain only those letters which are the in the alphabets string.

Input:
First line of input consists of number of test cases t. Then t test cases follow. In each test case first line consists of the string alphabets. Second line of test case consists of an integer n, representing the number of words to be sorted. Third line holds the n space separated strings which are to be sorted.

Output:
Output contains the n sorted strings in a single line separated by spaces.

Constraints:
Your task is to complete the function sort_by_order(), which sorts the words as explained. Do not print anything.

Example:
Input:
1
qwerty
5
we qwer erer qw errr
Output:
qw qwer we erer errr
*/
#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;

unordered_map<int, int> mp;


bool compare(string &a, string &b){
    int l=min(a.length(), b.length());
    for(int i=0;i<l;i++){
        if(a[i]!=b[i]){
            return mp[a[i]]<mp[b[i]];
        }
    }
    return a.length()<b.length();
}


void sort_by_order(vector<string> &words, string alphabets){
    
    
    for(int i=0;i<alphabets.size();i++){
        mp[alphabets[i]]=i+1;
    }
    sort(words.begin(), words.end(), compare);
}

int main(){
    int t;
    cin>>t;
    while(t--){
       
       string alphabets;
       cin>>alphabets;
       
       int n;
       cin>>n;
       vector<string> words;
       for(int i=0;i<n;i++){
           cin>>words[i];
       }
       
       sort_by_order(words, alphabets);
       for(int i=0;i<n;i++){
           cout<<words[i]<<" ";
           
       }
       cout<<endl;
    }
}
