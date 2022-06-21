// class Solution {
// public:
//     int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        
//         int maxReach=0;
//         for(int i = 0; i < heights.size()-1; i++) {
            
//             int diff = heights[i+1] - heights[i]; //required number of bricks
//             if(diff < 0) {
//                 maxReach = i+1;
//                 continue;
//             }
//             else {
//                 if(diff <= bricks) {
//                     maxReach = i+1;
//                     bricks -= diff;
//                 } else if(ladders > 0) {
//                     maxReach = i+1;
//                     ladders -= 1;
//                 } else if(diff > bricks && ladders <= 0) {
//                     return maxReach;
//                 } else if(bricks <=0 && ladders <=0) {
//                     return maxReach;
//                 }
//             }
//         }
//         return maxReach;
        
//     }
// };

class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        
        // Priority Queue for storing the bricks used in each step in decreasing order (Max at top)
        priority_queue<int> maxB;
    
        int i=0, diff =0; 
        for(i=0; i<heights.size()-1; i++){ 
            
            diff = heights[i+1]-heights[i];
            
            if(diff <= 0){
                continue;
            }

            bricks -= diff; 
            maxB.push(diff); 
       
            if(bricks < 0){
                bricks += maxB.top(); 
                maxB.pop(); 
                ladders--;
            }

          
            if(ladders < 0) break;
        }
        
        
        return i;
    }
};
