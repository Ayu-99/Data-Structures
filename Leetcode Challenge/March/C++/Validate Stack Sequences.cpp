// class Solution {
// public:
//     bool validateStackSequences(vector<int> &push, vector<int> &pop) {
//       stack<int> s;
//       for (int i = 0, j = 0; i < push.size(); ++i) {
//         s.push(push[i]);
//         while (!s.empty() && s.top() == pop[j]){
//             s.pop();
//             j++;  
//         } 
//       }
//       return s.empty(); //true
//     }
    
// };

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int i = 0, j = 0;
        for(int x :  pushed)
        {
            pushed[i] = x;
            i++;
            while(i> 0 && pushed[i-1] == popped[j])
            {
                
                --i;
                ++j;
            }
        }
        return i == 0; 
    }
};
