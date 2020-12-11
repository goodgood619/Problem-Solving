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
    int ans = 0;
    public int sumNumbers(TreeNode root) {
        if(root == null) return ans;
        StringBuilder sb = new StringBuilder();
        sb.append(root.val);
        makeLeafNumber(root,sb);
        return ans;
    }
    private void makeLeafNumber(TreeNode root, StringBuilder sb) {
        if(root.left == null && root.right == null) {
            ans += Integer.parseInt(sb.toString());
            return;
        }
        if(root.left != null) {
            sb.append(root.left.val);
            makeLeafNumber(root.left,sb);
            sb.deleteCharAt(sb.length()-1);
        }
        if(root.right != null) {
            sb.append(root.right.val);
            makeLeafNumber(root.right,sb);
            sb.deleteCharAt(sb.length()-1);
        }
    }
}