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
    
    TreeNode* buildTree_helper(vector<int> &preorder, vector<int> &inorder, int preorderStart, int preorderEnd, int inorderStart, int inorderEnd){
        
        if(inorderStart>inorderEnd){
            return NULL;
        }
        
        int rootVal = preorder[preorderStart];
        int rootIndex = -1;
        for(int i=inorderStart;i<=inorderEnd;i++){
            if(rootVal == inorder[i]){
                rootIndex = i;
                break;
            }
        }
        
        
        TreeNode *root = new TreeNode(rootVal);
        
        int lInS = inorderStart;
        int lInE = rootIndex-1;
        int rInS = rootIndex+1;
        int rInE = inorderEnd;
        
        int lPrS = preorderStart+1;
        int lPrE = lInE - lInS + lPrS;
        int rPrS = lPrE+1;
        int rPrE = preorderEnd;
        
        root->left = buildTree_helper(preorder, inorder, lPrS, lPrE, lInS, lInE);
        root->right = buildTree_helper(preorder, inorder, rPrS, rPrE, rInS, rInE);
        
        return root;
        
        
    }
    
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
        int preorderStart = 0;
        int preorderEnd = preorder.size()-1;
        int inorderStart = 0;
        int inorderEnd = inorder.size()-1;
        
        return buildTree_helper(preorder, inorder, preorderStart, preorderEnd, inorderStart, inorderEnd);
        
        
    }
};
