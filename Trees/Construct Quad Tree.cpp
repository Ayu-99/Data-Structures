/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

// class Solution {
// public:
//     bool sameValue(vector<vector<int>>& grid, int x1, int y1, int length) {
//         for (int i = x1; i < x1 + length; i++) {
//             for (int j = y1; j < y1 + length; j++)
//                 if (grid[i][j] != grid[x1][y1])
//                     return false;
//         }
//         return true;
//     }
    
//     Node* solve(vector<vector<int>>& grid, int x1, int y1, int length) {
//         if (sameValue(grid, x1, y1, length)) {
//             return new Node(grid[x1][y1], true);
//         } else {
//             Node* root = new Node(false, false);

//             root -> topLeft = solve(grid, x1, y1, length / 2);
//             root -> topRight = solve(grid, x1, y1 + length / 2, length / 2);
//             root -> bottomLeft = solve(grid, x1 + length / 2, y1, length / 2);
//             root -> bottomRight = solve(grid, x1 + length / 2, y1 + length / 2, length / 2);

//             return root;
//         }
//     }
    
//     Node* construct(vector<vector<int>>& grid) {
//         return solve(grid, 0, 0, grid.size());
//     }
// };

class Solution {
public:
    Node* solve(vector<vector<int>>& grid, int x1, int y1, int length) {
        if (length == 1) {
            return new Node(grid[x1][y1], true);
        }
        
        Node* topLeft = solve(grid, x1, y1, length / 2);
        Node* topRight = solve(grid, x1, y1 + length / 2, length / 2);
        Node* bottomLeft = solve(grid, x1 + length / 2, y1, length / 2);
        Node* bottomRight = solve(grid, x1 + length / 2, y1 + length / 2, length / 2);
            
        
        if (topLeft -> isLeaf && topRight -> isLeaf && bottomLeft -> isLeaf && bottomRight -> isLeaf
           && topLeft -> val == topRight -> val && topRight -> val == bottomLeft -> val 
           && bottomLeft -> val == bottomRight -> val) {
            return new Node(topLeft -> val, true);
        }
        
        return new Node(false, false, topLeft, topRight, bottomLeft, bottomRight);
    }
    
    Node* construct(vector<vector<int>>& grid) {
        return solve(grid, 0, 0, grid.size());
    }
};
