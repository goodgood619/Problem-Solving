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
    int postIndex;
    public TreeNode buildTree(int[] inorder, int[] postorder) {
        Map<Integer,Integer> map = new HashMap<>();
        postIndex = inorder.length-1;
        for(int i=0;i<=postIndex;i++) map.put(inorder[i],i);
        return traverse(inorder,postorder,0,postIndex,map);
    }
    private TreeNode traverse(int[] inorder,int[] postorder,int start,int end, Map<Integer,Integer> map) {
        if(start>end || postIndex<0) return null;
        TreeNode root = new TreeNode(postorder[postIndex--]);
        int curIndex = map.get(root.val);
        root.right = traverse(inorder,postorder,curIndex+1,end,map);
        root.left = traverse(inorder,postorder,start,curIndex-1,map);
        return root;
    }
}