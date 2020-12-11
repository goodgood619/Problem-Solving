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
    public String smallestFromLeaf(TreeNode root) {
        if(root == null) return "";
        ans = new ArrayList<>();
        StringBuilder sb = new StringBuilder();
        sb.append((char)(root.val+97));
        makeAlphabet(root,sb);

        Collections.sort(ans,(a,b)->{
           return a.compareTo(b); 
        });
        return ans.get(0);
    }
    private void makeAlphabet(TreeNode root, StringBuilder sb) {
        if(root.left == null && root.right == null) {
            System.out.println(sb.toString());
            ans.add(sb.reverse().toString());
            sb.reverse();
            return;
        }
        if(root.left != null) {
            sb.append((char)(root.left.val+97));
            makeAlphabet(root.left,sb);
            sb.deleteCharAt(sb.length()-1);
        }
        if(root.right != null) {
            sb.append((char)(root.right.val+97));
            makeAlphabet(root.right,sb);
            sb.deleteCharAt(sb.length()-1);
        }
    }
}