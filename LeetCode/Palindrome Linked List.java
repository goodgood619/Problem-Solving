/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public boolean isPalindrome(ListNode head) {
        List<Integer> list = new ArrayList<>();
        ListNode temp = head;
        while(temp!=null) {
            list.add(temp.val);
            temp = temp.next;
        }
        boolean no = false;
        for(int i=0,j=list.size()-1;i<j;i++,j--) {
            int a =list.get(i);
            int b= list.get(j);
            if(a!=b) {
                no = true;
                break;
            }
        }
        return !no;
    }
}