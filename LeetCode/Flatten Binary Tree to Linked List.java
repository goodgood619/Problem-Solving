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
    List<Integer> list = new ArrayList<>();
    public void flatten(TreeNode root) {
        if(root!=null){
        TreeNode start= root;
        traverse(root);
        TreeNode temp = start;
        for(int i=0;i<list.size();i++){
            start.val = list.get(i);
            if(i==list.size()-1) continue;
            start.left = null;
            if(start.right==null){
                TreeNode tnext = new TreeNode(0);
                start.right = tnext;
            }
            start = start.right;
        }
    }
    }
    private void traverse(TreeNode tree) {
        list.add(tree.val);
        if(tree.left != null) traverse(tree.left);
        if(tree.right!=null) traverse(tree.right);
    }
}