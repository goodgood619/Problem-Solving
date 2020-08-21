import java.util.*;
class Solution {
    public int solution(int[] priorities, int location) {
        int answer = 0,idx=0;
        Deque<P> q = new ArrayDeque<>();
        for(int value : priorities){
            q.add(new P(value,idx++));
        }
        while(!q.isEmpty()) {
            Deque<P> temp = new ArrayDeque<>(q);
            int curvalue = q.peek().value,curorigin = q.peek().origin;
            boolean check = false;
            while(!temp.isEmpty()) {
                int nextvalue = temp.peek().value;
                if(curvalue<nextvalue) {
                    check = true;
                    break;
                }
                temp.poll();
                
            }
            if(check) {
                q.add(new P(curvalue,curorigin));
                q.pollFirst();
            }
            else {
                answer++;
                if(curorigin == location) {
                    break;
                }
                q.pollFirst();
            }
        }
        return answer;
    }
}
class P {
    int value;
    int origin;
    P(int value,int origin) {
        this.value = value;
        this.origin = origin;
    }
}