/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode deleteDuplicates(ListNode head) {
        Map<Integer,Integer> map = new HashMap<>();
        ListNode temp = head;
        ListNode ans = null;
        ListNode goahead = null;
        List<Integer> list =new ArrayList<>();
        while(temp!=null) {
            int val = temp.val;
            if(map.get(val)==null) {
                map.put(val,1);
                list.add(val);
            }
            temp = temp.next;
        }
        for(Integer e :list) {
            ListNode current = new ListNode(e);
            if(goahead==null) { goahead= current;
                ans = goahead;                  
            }
            else {
                goahead.next = current;
                goahead = goahead.next;
            }
        }
        return ans;
    }
}