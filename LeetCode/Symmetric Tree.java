/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */
class Solution {
    public boolean isSymmetric(TreeNode root) {
        return go(root,root);
    }
    private boolean go(TreeNode a,TreeNode b) {
        if(a == null && b==null) return true;
        if(a == null || b== null) return false;
        return (a.val == b.val) && go(a.right,b.left) && go(a.left,b.right);
    }
}