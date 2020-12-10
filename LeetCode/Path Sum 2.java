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
    public List<List<Integer>> pathSum(TreeNode root, int sum) {
        List<List<Integer>> ans = new ArrayList<>();
        if(root == null) return ans;
        List<Integer> makePathArray = new ArrayList<>();
        makePathArray.add(root.val);
        checkPathSum(root,sum-root.val,makePathArray,ans);
        return ans;
    }
    private void checkPathSum(TreeNode root, int sum, List<Integer> makePathArray,List<List<Integer>> ans) {
        if(root.left == null && root.right == null) {
            if(sum==0) {
                System.out.println(0);
                List<Integer> temp = new ArrayList<>(makePathArray);
                ans.add(temp);
                return;
            }
        }
        if(root.left !=null) {
            makePathArray.add(root.left.val);
            checkPathSum(root.left,sum-root.left.val,makePathArray,ans);
            makePathArray.remove(makePathArray.size()-1);
        }
        if(root.right != null) {
            makePathArray.add(root.right.val);
            checkPathSum(root.right,sum-root.right.val,makePathArray,ans);
            makePathArray.remove(makePathArray.size()-1);
        }
    }
}