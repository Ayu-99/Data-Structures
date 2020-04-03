/*
Two elements 'a' and 'b' are said to be a perfect pair if sum of digits of 'a' is equal to sum of digits of 'b'. Find the perfect pair with the maximum sum (a+b). 

Input:
First line of input contains number of testcases T. For each testcase, there will be 2 lines. First line contains N which denoted the number of elements in the array. Second line contains N space separated integers.

Output:
Print the maximum sum. If it is not possible print -1.

Your Task:
Complete the function PerfectMatch() which takes the array and N as inputs and returns the maximum perfect match. Return -1 if no such match is possible. 

Constraints:
1 <= T <= 100
1 <= N <= 10^5
1 <= arr[i] <= 10^9

Example:
Sample Input:
2
5
55 23 32 46 88
4
18 19 23 15

Sample Output:
101
-1 

Explanation:
Testcase 1:
Possible perfect match with equal digit sum are - 
(23, 32) with digit sum 5 
(55, 46) with digit sum 10 
The pair with maximum sum is (55, 46) i.e. 55 + 46 = 101

Testcase 2:
There are no elements that form a perfect match. 
*/



#include<bits/stdc++.h>
#include<unordered_map>
using namespace std;


int PerfectMatch(vector<int> arr,int n){
    map<int, vector<int>> mp;
    for(int i=0;i<n;i++){
        int temp=arr[i];
        int sum=0;
        while(temp>0){
            sum+=(temp)%10;
            temp=temp/10;
        }
        
        mp[sum].push_back(arr[i]);
    }
    
    
    int ans=0;
    bool flag=0;
    for(auto V:mp){
        if(V.second.size()>=2){
            flag=1;
            sort(V.second.begin(), V.second.end());
            reverse(V.second.begin(), V.second.end());
            int curr=V.second[0]+V.second[1];
            ans=max(ans, curr);
        }
    }
    
    
    if(flag==0){
        return -1;
    }
    return ans;
}


int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        
        cout<<PerfectMatch(arr, n);
    }
}
