/**
 * Definition for binary tree
 * class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) {
 *      val = x;
 *      left=null;
 *      right=null;
 *     }
 * }
 */
public class Solution {
    
    public boolean helper(TreeNode root, List<Integer> path, int B) {
        
        if (root == null) return false;
        
        path.add(root.val);
        if (root.val == B) {
            return true;
        }
        
        
        if (helper(root.left, path, B) || helper(root.right, path, B)) {
            return true;
        }
        path.remove(path.size()-1);
        return false;
        
    }
    
    public int[] solve(TreeNode A, int B) {
        List<Integer> path = new ArrayList();
        helper(A, path, B);
        int[] arr = new int[path.size()];
        for(int i=0; i< path.size();i++) {
            arr[i] = path.get(i);
        }
        return arr;
    }
}
