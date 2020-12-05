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
    public TreeNode searchBST(TreeNode root, int val) {
        return traverse(root,val);
    }
    private TreeNode traverse(TreeNode root,int target) {
        if(root==null) return null;
        if(root.val == target) return root;
        else if(root.val>target) return traverse(root.left,target);
        else return traverse(root.right,target);
    }  
}