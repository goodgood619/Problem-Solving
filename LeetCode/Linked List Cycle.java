/**
 * Definition for singly-linked list.
 * class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    public boolean hasCycle(ListNode head) {
        boolean cycle = false;
        ListNode temp = head;
        Set<ListNode> set =new HashSet<>();
        while(temp!=null) {
            if(!set.contains(temp)) {
                set.add(temp);
            }
            else {
                return true;
            }
            temp = temp.next;
        }
        return false;
    }
}