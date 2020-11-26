/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        ListNode head=null;
        ListNode ret = null;
        int sum=0;
        while(l1!=null || l2!=null) {
            if(l1!=null) sum += l1.val;
            if(l2!=null) sum += l2.val;
            if(head == null) {
                head = new ListNode(sum%10);
                sum/=10;
                ret = head;
            }
            else {
                ListNode cur = new ListNode(sum%10);
                sum/=10;
                ret.next = cur;
                ret = ret.next;
            }
            if(l1!=null) l1 = l1.next;
            if(l2!=null) l2 = l2.next;
        }
        if(sum!=0) {
            ListNode cur = new ListNode(sum%10);
            ret.next = cur;
        }
        return head;
    }
}