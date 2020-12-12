/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    public ListNode getIntersectionNode(ListNode headA, ListNode headB) {
        ListNode tempA = headA;
        ListNode tempB;
        ListNode ans = null;
        boolean intersectcheck = false;
        while(tempA != null) {
            for(tempB = headB;tempB != null; tempB = tempB.next) {
                if(tempA == tempB) {
                    intersectcheck = true;
                    ans = tempA;
                    break;
                }
            }
            if(intersectcheck) break;
            tempA = tempA.next;
        }
        if(intersectcheck) return ans;
        else return null;
    }
}