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
    public boolean isValidBST(TreeNode root) {
        if(root==null) return true;
        return traverse(root,null,null);
    }
    private boolean traverse(TreeNode here,TreeNode Min,TreeNode Max) {
        if(here==null) return true;
        if(Min!=null && here.val<=Min.val) {
            return false;
        }
        if(Max!=null && here.val >=Max.val) {
            return false;
        }
        
        return traverse(here.left,Min,here) && traverse(here.right,here,Max);
    }
}