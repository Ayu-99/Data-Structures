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

//  class Solution {
// public:
//     string serializeSubtrees(TreeNode* node, unordered_map<string, int>& subtrees, vector<TreeNode*>& duplicates) {
//         if (!node) return "#"; 
        
//         string left = serializeSubtrees(node->left, subtrees, duplicates);
//         string right = serializeSubtrees(node->right, subtrees, duplicates);
        
//         string s = left + "," + right + "," + to_string(node->val); 
        
//         if (subtrees[s] == 1) duplicates.push_back(node); 
        
//         subtrees[s]++;
//         return s;
//     }
//  vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
//         unordered_map<string, int> subtrees; 
//         vector<TreeNode*> duplicates; 
        
//         serializeSubtrees(root, subtrees, duplicates);
        
//         return duplicates;
//     }
    
// };

class Solution {
public:
    
    int traverse(TreeNode* node, unordered_map<string, int> &tripletToID, unordered_map<int, int> &cnt, vector<TreeNode*> &res){
            if (node == nullptr) {
                return 0;
            }
            string triplet = to_string(traverse(node->left, tripletToID, cnt, res)) + "," + to_string(node->val) + "," +
                            to_string(traverse(node->right, tripletToID, cnt, res));
            if (!tripletToID.count(triplet)) {
                tripletToID[triplet] = tripletToID.size() + 1;
            }
            int id = tripletToID[triplet];
            cnt[id]++;
            if (cnt[id] == 2) {
                res.push_back(node);
            }
            return id;
        };
    
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        unordered_map<string, int> tripletToID;
        unordered_map<int, int> cnt;
        vector<TreeNode*> res;
        
        traverse(root, tripletToID, cnt, res);
        return res;
    }
};
