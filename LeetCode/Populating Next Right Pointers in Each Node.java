/*
// Definition for a Node.
class Node {
    public int val;
    public Node left;
    public Node right;
    public Node next;

    public Node() {}
    
    public Node(int _val) {
        val = _val;
    }

    public Node(int _val, Node _left, Node _right, Node _next) {
        val = _val;
        left = _left;
        right = _right;
        next = _next;
    }
};
*/
class Solution {
    public Node connect(Node root) {
        if(root==null) return null;
        if(root.left==null && root.right==null) return root;
        traverse(root);
        return root;
    }
    private void traverse(Node root) {
        if(root==null) return;
        
        // 현재 위치를 루트로 했을때 바로 밑단에 있는 왼쪽next를 오른쪽으로 연결
        if(root.left != null && root.right!=null)  {
            root.left.next = root.right;
        }
        // 분리되어 있는 이진트리를 이어야 하므로, next값을 이용해서 판별해야함!!
        if(root.right!=null && root.next!=null) {
            root.right.next = root.next.left;
        }
        traverse(root.left);
        traverse(root.right);
    }
}