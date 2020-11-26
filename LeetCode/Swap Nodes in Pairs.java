/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode swapPairs(ListNode head) {
        List<Integer> list =new ArrayList<>();
        ListNode temp = head;
        while(temp!=null) {
            list.add(temp.val);
            temp = temp.next;
        }
        for(int i=0;i<list.size();i+=2) {
            if(i+1<list.size()) {
                int first = list.get(i);
                list.set(i,list.get(i+1));
                list.set(i+1,first);
            }
        }
        ListNode cur = null;
        ListNode ans= null;
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