/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

    int maxDepth(TreeNode* root) {
        
        //base case
        if(root==NULL){
            return 0;
        }
        int d1=maxDepth(root->left); //left recursive call
        int d2=maxDepth(root->right); //right recursive call
        
        return max(d1,d2)+1;
    }

};
