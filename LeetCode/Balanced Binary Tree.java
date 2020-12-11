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
    boolean ans = true;
    public boolean isBalanced(TreeNode root) {
        if(root == null) return true;
        balanceCheck(root);
        return ans;
    }
    private int balanceCheck(TreeNode root) {
        if(root.left == null && root.right == null) return 1;
        int leftHeight = 0, rightHeight=0;
        if(root.left != null) {
            leftHeight = balanceCheck(root.left);
        }
        if(root.right != null) {
            rightHeight = balanceCheck(root.right);
        }
        if(Math.abs(leftHeight-rightHeight)>=2){
            if(ans) {
                ans = false;
            }
        }
        return Math.max(leftHeight,rightHeight)+1;
    }
}