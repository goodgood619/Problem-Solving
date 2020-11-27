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
    int maxdepth=0;
    public List<List<Integer>> zigzagLevelOrder(TreeNode root) {
        if(root==null) return new ArrayList<>();
        List<List<Integer>> list = new ArrayList<>();
        traverse(root,0);
        for(int i=0;i<=maxdepth;i++) {
            list.add(new ArrayList<>());
        }
        traverse2(root,0,list);
        List<List<Integer>> ans = new ArrayList<>();
        for(int i=0;i<list.size();i++) {
            List<Integer> temp = new ArrayList<>(list.get(i));
            if(i%2==0) ans.add(temp);
            else {
                List<Integer> temp2 = new ArrayList<>();
                for(int j=temp.size()-1;j>=0;j--) {
                    temp2.add(temp.get(j));
                }
                ans.add(temp2);
            }
        }
        return ans;
    }
    private void traverse2(TreeNode root,int cur,List<List<Integer>> list) {
        if(root==null) return;
        list.get(cur).add(root.val);
        if(root.left!=null) traverse2(root.left,cur+1,list);
        if(root.right!=null) traverse2(root.right,cur+1,list);
    }
    private void traverse(TreeNode root,int depth) {
        if(root==null) return;
        maxdepth= Math.max(maxdepth,depth);
        if(root.left!=null) traverse(root.left,depth+1);
        if(root.right!=null) traverse(root.right,depth+1);
    }
}