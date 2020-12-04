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
        Deque<Integer> first = new ArrayDeque<>();
        Deque<Integer> second = new ArrayDeque<>();
        ListNode temp = l1;
        while(temp != null) {
            first.add(temp.val);
            temp = temp.next;
        }
        temp = l2;
        while(temp != null) {
            second.add(temp.val);
            temp = temp.next;
        }
        Deque<Integer> three = new ArrayDeque<>();
        int carry=0;
        while(first.size()>0 && second.size()>0) {
            int value = first.pollLast()+ second.pollLast()+carry;
            three.add(value%10);
            if(value>=10) carry = 1;
            else carry=0;
        }
        while(first.size()>0) {
            int value = first.pollLast() + carry;
            three.add(value%10);
            if(value>=10) carry = 1;
            else carry=0;
        }
        while(second.size()>0) {
            int value = second.pollLast() + carry;
            three.add(value%10);
            if(value>=10) carry = 1;
            else carry=0;
        }
        if(carry==1) {
            three.add(carry);
        }
        ListNode ans = null;
        ListNode cur = null;
        while(three.size()>0) {
            int val = three.pollLast();
            if(cur==null) {
                cur = new ListNode(val);
                ans = cur;
            }
            else {
                cur.next= new ListNode(val);
                cur = cur.next;
            }
        }
        return ans;
    }
}