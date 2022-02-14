/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    public int maxDepth(TreeNode root) {
        
        //base case
        if(root==null){
            return 0;
        }
        int d1=maxDepth(root.left); //left recursive call
        int d2=maxDepth(root.right); //right recursive call
        
        return Math.max(d1,d2)+1;
    }
}
