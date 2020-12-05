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
    public TreeNode bstFromPreorder(int[] preorder) {
        TreeNode root = new TreeNode(preorder[0]);
        for(int i=1;i<preorder.length;i++) {
            root = traverse(root,preorder[i]);
        }
        return root;
    }
    private TreeNode traverse(TreeNode root,int value) {
        if(root==null) {
            return new TreeNode(value);
        }
        else if(root.val>value) {
            root.left = traverse(root.left,value);
        }
        else {
            root.right = traverse(root.right,value);
        }
        return root;
    }
}