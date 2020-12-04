/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public void deleteNode(ListNode node) {
        // head는 이미 주어지는거같음..
        node.val = node.next.val;
        node.next = node.next.next;
    }
}