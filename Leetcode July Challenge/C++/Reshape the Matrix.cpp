class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int rows = mat.size();
        int cols = mat[0].size();
        if(rows*cols < r*c || rows*cols > r*c){
            return mat;
        }
        
        vector<int> me;
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                me.push_back(mat[i][j]);
            }
        }
        
        int k = 0;
        vector<vector<int>> new_matrix(r, vector<int>(c, 0));
        for(int i = 0; i < r; i++){
            for(int j = 0; j < c; j++){
                new_matrix[i][j] = me[k];
                k++;
            }
        }
        
        return new_matrix;
        
    }
};
