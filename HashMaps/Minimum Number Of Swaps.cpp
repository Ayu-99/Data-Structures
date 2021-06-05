#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;

void swap(vector<int>& arr, int i, int j){
    int temp=arr[i];
    arr[i]=arr[j];
    arr[j]=temp;
}

int minimumNumberOfSwaps(vector<int> arr,int n){
    int ans=0;
    unordered_map<int,int> m;
    vector<int> temp=arr;
    sort(temp.begin(),temp.end());
    
    for(int i=0;i<n;i++){
        m[arr[i]]=i;
    }
    
    for(int i=0;i<n;i++){
        
        if(arr[i]!=temp[i]){

            ans++;
            int init=arr[i];
            swap(arr,i,m[temp[i]]);

            m[init]=m[temp[i]];
            m[temp[i]]=i;


        }
    }
    return ans;
}

int main(){
    vector<int> arr={1,5,4,3,2};
    int n=5;
    cout<<minimumNumberOfSwaps(arr,n)<<endl;
    return 0;

}
