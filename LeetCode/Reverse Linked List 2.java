/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode reverseBetween(ListNode head, int m, int n) {
        if(m==n) return head;
        ListNode start = head;
        ListNode end = head;
        ListNode cur = head;
        int p = m,q = n;
        while(p-->1) {
            start = start.next;
        }
        while(q-->0) {
            end = end.next;
        }
        ListNode temp = start;
        List<Integer> list = new ArrayList<>();
        while(true) {
            if(temp==end) break;
            list.add(temp.val);
            temp = temp.next;
        }
        ListNode goahead = new ListNode(0);
        ListNode ans = goahead;
        temp = head;
        // start까지 순차적 삽입
        while(temp!=start) {
            goahead.val = temp.val;
            ListNode next = new ListNode(0);
            goahead.next = next;
            goahead = goahead.next;
            temp = temp.next;
            cur = cur.next;
        }
        // list 삽입
        for(int i=list.size()-1;i>=0;i--) {
            goahead.val = list.get(i);
            if(i!=0) {
                ListNode next = new ListNode(0);
                goahead.next = next;
                goahead = goahead.next;
            }
            cur = cur.next;
        }
        if(cur!=null){
            // 만약끝이아니면 다음꺼를 미리 만들어준다
            ListNode bridge = new ListNode(0);
            goahead.next = bridge;
            goahead = goahead.next;
        }
        // 나머지 끝까지 삽입
        temp = end;
        while(temp!=null) {
            goahead.val = temp.val;
            ListNode next = new ListNode(0);
            if(temp.next!=null){
                    goahead.next = next;
                    goahead = goahead.next;
            }
            temp = temp.next;
        }
        return ans;
    }   
}