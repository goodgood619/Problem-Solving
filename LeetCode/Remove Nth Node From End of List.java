/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode removeNthFromEnd(ListNode head, int n) {
        ListNode temp = new ListNode(0);
        temp.next = head;
        ListNode first = temp;
        int totalsize=0;
        while(first!=null) {
            totalsize++;
            first = first.next;
        }
        int rest = totalsize - n;
        first = temp;
        while(rest>1) {
            first = first.next;
            rest--;
        }
        first.next = first.next.next;
        return temp.next;
    }
}