/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode reverseList(ListNode head) {
        if(head==null) return null;
        ListNode goforward = head;
        List<Integer> list =new ArrayList<>();
        while(goforward!=null) {
            list.add(goforward.val);
            goforward = goforward.next;
        }
        ListNode ans = new ListNode(0);
        ListNode real = ans;
        for(int i=list.size()-1;i>=0;i--) {
            ans.val = list.get(i);
            if(i!=0){
                ListNode next = new ListNode(0);
                ans.next = next;
                ans = ans.next;
            }
            else break;
        }
        ans.next = null;
        return real;
    }
}