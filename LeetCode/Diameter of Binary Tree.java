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
    int Max=0;
    public int diameterOfBinaryTree(TreeNode root) {
        if(root==null) return 0;
        traverse(root);
        return Max;
    }
    private int traverse(TreeNode root) {
        if(root.left==null && root.right==null) return 0;
        int left=0;
        int right=0;
        if(root.left != null) left = traverse(root.left)+1;
        if(root.right != null) right = traverse(root.right)+1;
        Max = Math.max(Max,left+right);
        return Math.max(left,right);
    }
}