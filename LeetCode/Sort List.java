/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode sortList(ListNode head) {
        ListNode temp = head;
        List<Integer> list = new ArrayList<>();
        while(temp!=null) {
            list.add(temp.val);
            temp = temp.next;
        }
        list.sort((a,b)->{
            if(a<b) return -1;
            else if(a>b) return 1;
            else return 0;
        });
        
        ListNode ans = null;
        ListNode cur = null;
        for(Integer a : list) {
            if(cur==null) {
                cur = new ListNode(a);
                ans = cur;
            }
            else {
                cur.next = new ListNode(a);
                cur= cur.next;
            }
        }
        return ans;
    }
}