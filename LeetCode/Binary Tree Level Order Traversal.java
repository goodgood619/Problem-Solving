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
    int maxDepth=0;
    public List<List<Integer>> levelOrder(TreeNode root) {
        if(root==null) return new ArrayList<>();
        findDepth(root,0);
        List<List<Integer>> v = new ArrayList<>();
        for(int i=0;i<=maxDepth;i++) {
            v.add(new ArrayList<>());
        }
        make(root,v,0);
        return v;
    }
    private void findDepth(TreeNode root,int curDepth) {
        if(root.left!=null) findDepth(root.left,curDepth+1);
        if(root.right!=null) findDepth(root.right,curDepth+1);
        maxDepth = Math.max(maxDepth,curDepth);
    }
    private void make(TreeNode root,List<List<Integer>> v, int cur) {
        v.get(cur).add(root.val);
        if(root.left!=null) make(root.left,v,cur+1);
        if(root.right!=null) make(root.right,v,cur+1);
    }
}