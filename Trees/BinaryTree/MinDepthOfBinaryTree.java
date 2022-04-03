package Trees.BinaryTree;

// https://leetcode.com/problems/minimum-depth-of-binary-tree/

public class MinDepthOfBinaryTree {
    // Approach 1
    public static int minDepth(TreeNode root) {
        if (root == null)
            return 0;
        if (root.left == null && root.right == null)
            return 1;
        if (root.left == null)
            return minDepth(root.right) + 1;
        if (root.right == null)
            return minDepth(root.left) + 1;
        return Math.min(minDepth(root.left), minDepth(root.right)) + 1;
    }

    // Approach 2
    int min = Integer.MAX_VALUE;

    public int minDepth2(TreeNode root) {
        if (root == null)
            return 0;
        minDepth2(root, 0);
        return min;
    }

    public void minDepth2(TreeNode root, int level) {
        if (root == null)
            return;
        level++;
        if (root.left == null && root.right == null)
            min = Math.min(min, level);
        minDepth2(root.left, level);
        minDepth2(root.right, level);
    }
}
