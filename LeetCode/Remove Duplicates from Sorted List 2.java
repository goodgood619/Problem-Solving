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
        List<Integer> list =new ArrayList<>();
        ListNode temp = head;
        while(temp!=null) {
            if(map.get(temp.val)==null) {
                map.put(temp.val,1);
                list.add(temp.val);
            }
            else {
                int value = map.get(temp.val);
                value++;
                map.remove(temp.val);
                map.put(temp.val,value);
            }
            temp = temp.next;
        }
        boolean[] visited = new boolean[list.size()];
        for(int i=0;i<list.size();i++) {
            int value = map.get(list.get(i));
            if(value>=2) visited[i]=true;
        }
        ListNode goahead = null;
        ListNode ans = null;
        for(int i=0;i<list.size();i++) {
            if(!visited[i]) {
                int value = list.get(i);
                if(goahead==null) {
                    goahead = new ListNode(value);
                    ans = goahead;
                }
                else {
                    goahead.next = new ListNode(value);
                    goahead = goahead.next;
                }
            }
        }
        return ans;
    }
}