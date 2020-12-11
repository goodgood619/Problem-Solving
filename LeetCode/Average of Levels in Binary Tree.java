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
    List<List<Integer>> tempAns;
    public List<Double> averageOfLevels(TreeNode root) {
        List<Double> ans = new ArrayList<>();
        tempAns = new ArrayList<>();
        if(root == null) return ans;
        int maxHeight = findmaxHeight(root);
        for(int i=0;i<maxHeight;i++) {
            tempAns.add(new ArrayList<>());
        }
        makeAns(root,0);
        for(List<Integer> list : tempAns) {
            double value = 0;
            for(int i=0;i<list.size();i++) {
                value += list.get(i);
            }
            value = value / (double)list.size();
            ans.add(value);
        }
        return ans;
    }
    private void makeAns(TreeNode root, int depth) {
        tempAns.get(depth).add(root.val);
        if(root.left ==null && root.right == null) {
            return;
        }
        if(root.left != null) makeAns(root.left,depth+1);
        if(root.right != null) makeAns(root.right,depth+1);
        
    }
    private int findmaxHeight(TreeNode root) {
        if(root.left == null && root.right ==null) return 1;
        int leftHeight = 0, rightHeight =0;
        if(root.left != null) {
            leftHeight = findmaxHeight(root.left);
        }
        if(root.right != null) {
            rightHeight = findmaxHeight(root.right);
        }
        return Math.max(leftHeight,rightHeight)+1;
    }
}