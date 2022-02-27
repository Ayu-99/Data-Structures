import java.util.AbstractMap;
class Solution {
    public int widthOfBinaryTree(TreeNode root) {
        if (root == null) return 0;
        int max = 0;
        Queue<Map.Entry<TreeNode, Integer>> q = new LinkedList<Map.Entry<TreeNode, Integer>>();
        q.offer(new AbstractMap.SimpleEntry(root, 1));

        while (!q.isEmpty()) {
            int l = q.peek().getValue(), r = l; // right started same as left
            for (int i = 0, n = q.size(); i < n; i++) {
                TreeNode node = q.peek().getKey();
                r = q.poll().getValue();
                if (node.left != null) q.offer(new AbstractMap.SimpleEntry(node.left, r * 2));
                if (node.right != null) q.offer(new AbstractMap.SimpleEntry(node.right, r * 2 + 1));
            }
            max = Math.max(max, r + 1 - l);
        }

        return maxwidth;
    }
}
