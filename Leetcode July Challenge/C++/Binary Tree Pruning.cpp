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
    
    int helper(TreeNode* root){
        if(root == NULL){
            return 0;
        }
        
        if(root-> left == NULL && root->right == NULL){
            if(root->val == 0){
                return 0;
            }else{
                return 1;
            }
        }
        
        int leftSubTreeOnes = helper(root->left);
        int rightSubTreeOnes = helper(root->right);
        
        if(leftSubTreeOnes == 0){
            root->left = NULL;
        }
        if(rightSubTreeOnes == 0){
            root->right = NULL;
        }
        
        return leftSubTreeOnes + rightSubTreeOnes + (root->val == 1 ? 1:0);
        
    }
    
    TreeNode* pruneTree(TreeNode* root) {
        
        if(helper(root) == 0){
            return NULL;
        }
        
        return root;
        
    }
};
