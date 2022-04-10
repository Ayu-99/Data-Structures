class Solution {
public:
    int calPoints(vector<string>& ops) {
        vector<int> scores;
        int size = 0;
        
        for(auto i:ops) {
            if(i == "+") {
                scores.push_back(scores[size-1] + scores[size-2]);
                size++;
            } else if(i == "D") {
                scores.push_back(2*scores[size - 1]);
                size++;
            } else if(i == "C") {
                size--;
                scores.pop_back();
            } else{
                size++;
                scores.push_back(stoi(i));
            }
        }
        
        int sum = 0;
        for(int i =0; i<size; i++) {
            sum += scores[i];
        }
        
        return sum;
    }
};
