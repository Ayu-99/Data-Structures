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
private:
    
    void markTree(TreeNode* root, TreeNode*& prev, TreeNode*& first, TreeNode*& end) {
        if (!root) return;
        markTree(root->left, prev, first, end);
        if (prev) {
            if (root->val < prev->val) {
                cout<<root->val << " "<<prev->val<<endl;
                if (!first) {
                    first = prev;
                    cout<<first->val<<endl;
                }
                end = root;
            }
        }
        prev = root;
        markTree(root->right, prev, first, end);
    }
    
    
public:
    void recoverTree(TreeNode* root) {
        TreeNode *prev = nullptr, *first = nullptr, *end = nullptr;
        markTree(root, prev, first, end);
        cout<<end->val<<endl;
        swap(first->val, end->val);
        return;
    }
};
