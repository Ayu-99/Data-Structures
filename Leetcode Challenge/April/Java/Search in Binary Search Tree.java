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
    public TreeNode searchBST(TreeNode root, int val) {
        if(root == null || root.val == val) return root;// Base Cases: root is null or val is present at root
		if(root.val > val) return searchBST(root.left, val); // Value is greater than root's val then search in right side of the root
		return searchBST(root.right, val);//Value is smaller than root's val then search in left side of the root
    }
}
