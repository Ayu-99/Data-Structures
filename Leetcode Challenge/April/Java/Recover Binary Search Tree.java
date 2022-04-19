class Solution {
    TreeNode prev = null, first = null, second = null;

    public void recoverTree(TreeNode root) {
        markTree(root);
        int temp = first.val;
        first.val = second.val;
        second.val = temp;
    }

    private void markTree(TreeNode curr) {
        if (curr == null)
            return;
        markTree(curr.left);
        if (prev != null && prev.val > curr.val) {
            if (first == null)
                first = prev;
            second = curr;
        }
        prev = curr;
        markTree(curr.right);
    }
}
