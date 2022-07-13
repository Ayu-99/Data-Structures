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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> v;
        queue<TreeNode*> q;
        q.push(root);
        
        if(root==NULL){
            return v;   
        }
        
        while(!q.empty()){
            int x=q.size();
            vector<int> v1;
            while(x--){
                TreeNode* front=q.front();
                q.pop();
                if(front->left!=NULL){
                    q.push(front->left);
                }
                
                if(front->right!=NULL){
                    q.push(front->right);
                }
                
                v1.push_back(front->val);
            }
            v.push_back(v1);
        }
        
        return v;
    }
};
