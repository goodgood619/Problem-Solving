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
    int ans = (int)1e9;
    public int minDepth(TreeNode root) {
        if(root==null) return 0;
        traverse(root,1);
        return ans;
    }
    private void traverse(TreeNode root, int depth) {
        if(root.left!=null) traverse(root.left,depth+1);
        if(root.right!=null) traverse(root.right,depth+1);
        if(root.left == null&& root.right== null) ans = Math.min(ans,depth);
    }
}