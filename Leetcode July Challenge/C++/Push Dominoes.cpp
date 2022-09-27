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

// java code for this solution 
class Solution {
        public String pushDominoes(String dominoes) {
        int n = dominoes.length();
        char[] s = dominoes.toCharArray();
        char start = '.',end = '.';
        int startIdx = 0,i=0;
        
        while(i<n){
            startIdx =i;
            while(i<n && s[i] == '.')
                i++;
            if(i<n)
                end = s[i];
            if(i-startIdx>0){
                if(start == 'R' && end == 'L'){
                    int l = startIdx;
                    int r = i-1;
                    while(l<r){
                        s[l] = 'R';
                        s[r] = 'L';
                        l++;
                        r--;
                    }
                }
                else if(end == 'L'){
                    int l = i-1;
                    while(l>=startIdx){
                        s[l]= 'L';
                        l--;
                    }
                }
                else if(start == 'R'){
                    int r = startIdx;
                    while(r<i){
                        s[r] = 'R';
                        r++;
                    }
                }
            }
            start = end;
            i++;
            end = '.';
        }
        return new String(s);
    }








