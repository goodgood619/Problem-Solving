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
    public List<Integer> preorderTraversal(TreeNode root) {
        if(root==null) return new ArrayList<>();
        List<Integer> v = new ArrayList<>();
        traverse(root,v);
        return v;
    }
    private void traverse(TreeNode root,List<Integer> v) {
        v.add(root.val);
        if(root.left!=null) traverse(root.left,v);
        if(root.right!=null) traverse(root.right,v);
    }
}