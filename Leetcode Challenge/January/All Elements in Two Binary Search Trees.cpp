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
    void inOrderTraverse(TreeNode *root, vector<int>& vec)
    {
        if(root)
	    {
		    inOrderTraverse(root->left, vec);
		    vec.push_back(root->val);
		    inOrderTraverse(root->right, vec);

	    }
    }
    
    
    void mergeVectors(vector<int> vec1, vector<int> vec2, vector<int>& mergedVectors)
    {
        int i = 0, j = 0, k = 0; 

        while (i < vec1.size() && j < vec2.size()) 
        { 
        
            if (vec1[i] < vec2[j]) {
                mergedVectors[k] = vec1[i]; 
                k++;
                i++;
            } else{
                mergedVectors[k] = vec2[j];
                k++;
                j++;
            }    
        } 
  
    
        while (i < vec1.size()) {
            mergedVectors[k] = vec1[i];
            k++;
            i++;
        }    
  
    
        while (j < vec2.size()) {
            mergedVectors[k] = vec2[j];
            k++;
            j++;
        }
        
    } 
    
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2)
    {
        vector<int> tree1, tree2;
        inOrderTraverse(root1, tree1);
        inOrderTraverse(root2, tree2);
        
        vector<int> mergedVectors(tree1.size() + tree2.size());
        mergeVectors(tree1, tree2, mergedVectors);
        return  mergedVectors;
        
    }
};
