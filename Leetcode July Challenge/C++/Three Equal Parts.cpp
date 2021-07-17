class Solution {
public:
    vector<int> threeEqualParts(vector<int>& arr) {
        vector<int> ans = {-1, -1};
        int numOf1s = 0, n = arr.size();
        for(int i = 0; i < n; i++){
            numOf1s += arr[i];
        }
        
        if(numOf1s % 3 != 0){
            return ans;
        }
        if(numOf1s == 0){
            vector<int> a = {0, 2};
            return a;
        }
        
        int numOf1sInEachPart = numOf1s / 3;
        numOf1s = 0;
        int firstPart1 = -1, secondPart1 = -1, thirdPart1 = -1;
        for(int i = 0; i < n; i++){
            if(arr[i] == 1){
                numOf1s++;  
                if(numOf1s == 1){
                    firstPart1 = i;
                }
                else if(numOf1s == (numOf1sInEachPart + 1)){
                    secondPart1 = i;
                }
                else if(numOf1s == (2 * numOf1sInEachPart + 1)){
                    thirdPart1 = i;
                }
            }
            
            
        }
        
        while(thirdPart1 < n){
            if(arr[firstPart1] == arr[thirdPart1] && arr[secondPart1] == arr[thirdPart1]){
                firstPart1++;
                secondPart1++;
                thirdPart1++;
            }
            else{
                return ans;
            }
        }
        
        return {firstPart1 - 1, secondPart1};
        
    }
};
