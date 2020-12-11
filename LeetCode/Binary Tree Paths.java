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
    List<String> ans;
    public List<String> binaryTreePaths(TreeNode root) {
        ans = new ArrayList<>();
        if(root == null) return ans;
        List<Integer> numbers = new ArrayList<>();
        numbers.add(root.val);
        makeBinaryTreePath(root,numbers);
        return ans;
    }
    private void makeBinaryTreePath(TreeNode root, List<Integer> numbers) {
        if(root.left == null && root.right == null) {
            StringBuilder sb = new StringBuilder();
            sb.append(numbers.get(0));
            for(int i=1;i<numbers.size();i++) {
                sb.append('-');
                sb.append('>');
                sb.append(numbers.get(i));
            }
            ans.add(sb.toString());
            return;
        }
        if(root.left != null) {
            numbers.add(root.left.val);
            makeBinaryTreePath(root.left,numbers);
            numbers.remove(numbers.size()-1);
        }
        if(root.right != null) {
            numbers.add(root.right.val);
            makeBinaryTreePath(root.right,numbers);
            numbers.remove(numbers.size()-1);
        }
    }
}