class Solution {
public:
    //  funcion to check validility of neighbor
    bool isValidNeighbor(int x, int y, vector<vector<int>>& board) {
        return (x >= 0 && x < board.size() && y >= 0 && y < board[0].size());
    }
    
    void gameOfLife(vector<vector<int>>& board) { 
        vector<int> dx = {0, 0, 1, 1, 1, -1, -1, -1}; //8 coordinated for neighbours
        vector<int> dy = {1, -1, 1, -1, 0, 0, 1, -1};
        
        for (int row = 0; row < board.size(); row++) {
            for (int col = 0; col < board[0].size(); col++) {
                
                int count_live_neighbors = 0;
                
                for (int i = 0; i < 8; i++) {
                    int curr_x = row + dx[i], curr_y = col +dy[i];
                    if (isValidNeighbor(curr_x, curr_y, board) && abs(board[curr_x][curr_y]) == 1)
                        count_live_neighbors++;
                }
                
                if (board[row][col] == 1 && (count_live_neighbors < 2 || count_live_neighbors > 3))
                    board[row][col] = -1;
                
                if (board[row][col] == 0 && count_live_neighbors == 3)
                    board[row][col] = 2;
            }
        }
        
        for (int row = 0; row < board.size(); row++) {
            for (int col = 0; col < board[0].size(); col++) {
                if (board[row][col] >= 1)
                    board[row][col] = 1;
                else
                    board[row][col] = 0;
            }
        }
    }
};
