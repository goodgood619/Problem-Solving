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
    public boolean isSameTree(TreeNode p, TreeNode q) {
        return checksame(p,q);
    }
    private boolean checksame(TreeNode a,TreeNode b) {
        if(a==null && b==null) return true;
        if(a!=null && b==null) return false;
        if(a== null && b!=null) return false;
        if(a.val != b.val) return false;
        return checksame(a.left,b.left) && checksame(a.right,b.right);
    }
}