/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root->val==p->val || root->val==q->val){
            return root;
        }
        
        TreeNode* a=NULL, *b=NULL;
        if(root->left!=NULL){
            a=lowestCommonAncestor(root->left, p, q);
        }
        
        if(root->right!=NULL){
            b=lowestCommonAncestor(root->right, p, q);
        }
        
        if(a==NULL && b==NULL){
            return NULL;
        }
        
        if(a!=NULL && b==NULL){
            return a;
        }
        
        if(a==NULL && b!=NULL){
            return b;
        }
        
        if(a!=NULL && b!=NULL){
            return root;
        }
        return root;
        
    }
};
