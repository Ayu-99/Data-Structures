/*
Given a binary tree, return the inorder traversal of its nodes' values.

Example:

Input: [1,null,2,3]
   1
    \
     2
    /
   3

Output: [1,3,2]
Follow up: Recursive solution is trivial, could you do it iteratively?
*/
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#include<stack>
#include<vector>
class Solution {
public:
    
    /*
    void inorder(TreeNode* root, vector<int>&s){
        
        if(root->left!=NULL){
            inorder(root->left, s);
        }
        s.push_back(root->val);
        if(root->right!=NULL){
            inorder(root->right, s);
        }
        
    }
    
    vector<int> inorderTraversal(TreeNode* root) {
        
        vector<int> s;
        if(root!=NULL){
            inorder(root, s);
        }
        
        return s;
        
    }
    */
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> s;
        vector<int> v;
        // TreeNode* curr;
        TreeNode* current=root;
        while(current!=NULL || !s.empty()){
            
            while(current!=NULL){
                s.push(current);
                current=current->left;
            }
            
            current=s.top();
            s.pop();
            v.push_back(current->val);
            
            current=current->right;
            
            // cout<<curr->val;
        }
        
        return v;
    }
};
