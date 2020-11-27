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
    int inorderIndex,limit;
    public TreeNode buildTree(int[] preorder, int[] inorder) {
        Map<Integer,Integer> map = new HashMap<>();
        inorderIndex = 0;
        for(int i=0;i<inorder.length;i++) {
            map.put(inorder[i],i);
        }
        limit = inorder.length-1;
        return traverse(preorder,inorder,0,limit,map);
        
    }
    private TreeNode traverse(int[] preorder,int[] inorder,int start,int end,Map<Integer,Integer> map) {
        if(start>end || inorderIndex>limit) return null;
        TreeNode root = new TreeNode(preorder[inorderIndex++]);
        int curIndex = map.get(root.val);
        root.left = traverse(preorder,inorder,start,curIndex-1,map);
        root.right = traverse(preorder,inorder,curIndex+1,end,map);
        return root;
    }
}