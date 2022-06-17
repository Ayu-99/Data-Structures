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
    int minCameraCover(TreeNode* root) {
        int sum=0;
        if(dfs(root,sum)==0)   sum++;// if root is not monitored, we place an additional camera here
        return sum;
    }
    
    int dfs(TreeNode * tr, int& sum){
        if(tr == NULL) return 1; //base case
        int l=dfs(tr->left,sum), r=dfs(tr->right,sum);
        if(l==0||r==0){// if at least 1 child is not monitored, we need to place a camera at current node 
            sum++;
            return 2;
        }else if(l==2||r==2){// if at least 1 child has camera, the current node is monitored. Thus, we don't need to place a camera here 
            return 1;
        }else{// if both children are monitored but have no camera, we don't need to place a camera here. We place the camera at its parent node at the higher level. 
            return 0;
        }
        return -1;// this return statement won't be triggered
    }
};
