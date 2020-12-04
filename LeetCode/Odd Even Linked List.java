/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode oddEvenList(ListNode head) {
        if(head==null) return null;
        ListNode first = head;
        ListNode second= head.next;
        ListNode ans = null;
        ListNode cur =null;
        while(first!=null) {
            int value = first.val;
            if(cur==null) {
                cur = new ListNode(value);
                ans= cur;
            }
            else {
                cur.next = new ListNode(value);
                cur = cur.next;
            }
            if(first.next!=null) first = first.next.next;
            else first = first.next;
        }
        while(second!=null) {
            int value = second.val;
            if(cur==null) {
                cur = new ListNode(value);
                cur = ans;
            }
            else {
                cur.next= new ListNode(value);
                cur=cur.next;
            }
            if(second.next!=null) second = second.next.next;
            else second = second.next;
        }
        return ans;
    }
}