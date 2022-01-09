class Solution {
public:
    bool isRobotBounded(string instructions) {
        char current_dir = 'N';
        int x = 0, y= 0;
        for(int i=0;i<instructions.length();i++){ 
            if(instructions[i] == 'G'){
                y += current_dir =='N' ? 1 : 0;
				y += current_dir =='S' ? -1 : 0;
				x += current_dir == 'E' ? 1 : 0;
				x += current_dir == 'W' ? -1 : 0;
            }
            else{
                char incoming = instructions[i];
                if(current_dir == 'N'){
                    current_dir = incoming == 'L' ? 'W' : 'E';
                }
                else if(current_dir == 'W'){
                    current_dir = incoming == 'L' ? 'S' : 'N';
                }
                else if(current_dir == 'S'){
                    current_dir = incoming == 'L' ? 'E' : 'W';
                }
                else{
                    current_dir = incoming == 'L' ? 'N' : 'S';
                }
            } 
            
        }
        
        if(x==0 && y==0 || current_dir!='N')
            return true;
        
        return false;
    }
};
