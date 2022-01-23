class Solution {
public:
    vector<int> ans;
    
    void dfs(int low, int high, int i, int num){
        
        //lies in range
        if (num >= low and num <= high)
            ans.push_back(num);
        
        if (num > high or i>9)
            return;
        
        dfs(low, high, i+1, num*10 + i);
    }
    
    vector<int> sequentialDigits(int low, int high) {
        for(int i=1; i<=9; i++)
            dfs(low, high, i, 0);
        sort(ans.begin(), ans.end());
        return ans;
    }
};

/*
class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        int a[]={12,23,34,45,56,67,78,89,123,234,345,456,567,678,789,
                1234,2345,3456,4567,5678,6789,12345,23456,34567,
                45678,56789,123456,234567,345678,456789,
                1234567,2345678,3456789,12345678,23456789,123456789};
        
        vector<int> res;
        for(int i=0;i<=35;i++){
            if(a[i]<low ){
                continue;
            }
            if(a[i]>high){
                continue;
            }
            res.push_back(a[i]);
            
        }
        return res;
    }
};
*/
