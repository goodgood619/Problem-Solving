/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode middleNode(ListNode head) {
        ListNode temp = head;
        int length=0;
        while(temp!=null) {
            length++;
            temp = temp.next;
        }
        length/=2;
        while(length>0) {
            length--;
            head = head.next;
        }
        return head;
    }
}