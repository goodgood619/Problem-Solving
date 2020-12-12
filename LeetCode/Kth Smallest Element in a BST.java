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
    public int kthSmallest(TreeNode root, int k) {
        List<Integer> ansArray = new ArrayList<>();
        inorder(root,ansArray);
        k--;
        return ansArray.get(k);
    }
    private void inorder(TreeNode root,List<Integer> ans) {
        if(root.left != null) inorder(root.left,ans);
        ans.add(root.val);
        if(root.right != null) inorder(root.right,ans);
    }
}