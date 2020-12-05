/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode[] splitListToParts(ListNode root, int k) {
        int length = 0;
        ListNode temp = root;
        List<Integer> list =new ArrayList<>();
        while(temp!=null) {
            length++;
            list.add(temp.val);
            temp = temp.next;
        }
        int rest = length%k,same = length/k;
        ListNode[] ans = new ListNode[k];
        if(same>=1) {
        int idx=0;
        for(int i=0;i<list.size();) {
            ListNode cur = null;
            ListNode temp2 = null;
            int p = same;
            if(rest>0) {
                while(p-->0) {
                    int value = list.get(i);
                    if(cur==null) {
                        cur= new ListNode(value);
                        temp2 = cur;
                    }
                    else {
                        cur.next = new ListNode(value);
                        cur = cur.next;
                    }
                    i++;
                }
                int plusone = list.get(i);
                i++;
                cur.next = new ListNode(plusone);
                cur = cur.next;
                rest--;
                ans[idx++]=temp2;
            }
            else {
                while(p-->0) {
                    int value = list.get(i);
                    if(cur==null) {
                        cur= new ListNode(value);
                        temp2 = cur;
                    }
                    else {
                        cur.next = new ListNode(value);
                        cur = cur.next;
                    }
                    i++;
                }
                ans[idx++]=temp2;
            }
        }
        }
        else {
            for(int i=0;i<list.size();i++) {
                ans[i] = new ListNode(list.get(i));
            }
        }
        return ans;
    }
}