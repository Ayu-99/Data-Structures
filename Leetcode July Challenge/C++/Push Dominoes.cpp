class Solution {
public:
    string pushDominoes(string dominoes) {
        int n = dominoes.size();
        vector<int> left(n, 0), right(n, 0);
        char prev = '.';
        int count = 1;
        for(int i = 0; i < n; i++){
            if(dominoes[i] == 'R'){
                prev = 'R';
                count = 1;
                continue;
            }
            else if(dominoes[i] == 'L'){
                prev = 'L';
            }
            
            if(prev == 'R' && dominoes[i] == '.'){
                right[i] = count;
                count++;
            }
        }
        
        
        prev = '.';
        count = 1;
        for(int i = n - 1; i >= 0; i--){ //right to left
            if(dominoes[i] == 'L'){
                prev = 'L';
                count = 1;
                continue;
            }
            
            else if(dominoes[i] == 'R'){
                prev = 'R';
            }
            if(prev == 'L' && dominoes[i] == '.'){
                left[i] = count;
                count++;
            }
            
        }
        
        
        string finalResult = "";
        for(int i = 0; i < n; i++){
            if(left[i] == 0 && right[i] == 0){
                finalResult += dominoes[i];
            }
            
            else if(left[i] == 0){
                finalResult += 'R';
            }
            
            else if(right[i] == 0){
                finalResult += 'L';
            }
            
            else if(left[i] == right[i]){
                finalResult += '.';
            }
            else if(left[i] > right[i]){
                finalResult += 'R';
            }
            else{
                finalResult += 'L';
            }
            
        }
        
        return finalResult;
    }
};
