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
    public boolean hasPathSum(TreeNode root, int sum) {
        if(root == null) return false;
        return checkPathSum(root,sum-root.val);
    }
    private boolean checkPathSum(TreeNode root, int sum) {
        if(root.left == null && root.right == null) {
            if(sum==0) return true;
            else return false;
        }
        boolean ret = false;
        if(root.left != null){
            ret = checkPathSum(root.left,sum-root.left.val);
        }
        if(ret==true) {
            return true;
        }
        if(root.right != null) {
            ret = checkPathSum(root.right,sum-root.right.val);
        }
        if(ret==true) {
            return true;
        }
        return ret;
    } 
}