/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode removeElements(ListNode head, int val) {
        List<Integer> list = new ArrayList<>();
        ListNode temp = head;
        while(temp!=null) {
            if(temp.val != val) list.add(temp.val);
            temp = temp.next;
        }
        ListNode ans = null;
        ListNode cur = null;
        for(Integer e : list) {
            if(cur==null) {
                cur = new ListNode(e);
                ans = cur;
            }
            else {
                cur.next = new ListNode(e);
                cur = cur.next;
            }
        }
        return ans;
    }
}