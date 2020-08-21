import java.util.*;
class Solution {
    public String solution(String[] participant, String[] completion) {
        Map<String,Integer> map = new HashMap<>();
        for(int i=0;i<participant.length;i++) {
            String s = participant[i];
            if(map.get(s)==null) {
                map.put(s,1);
            }
            else {
                int value = map.get(s);
                value++;
                map.remove(s);
                map.put(s,value);
            }
        }
        
        for(int i=0;i<completion.length;i++)  {
            String complete = completion[i];
            int value = map.get(complete);
            value--;
            map.remove(complete);
            map.put(complete,value);
        }
        String answer ="";
        for(String e : map.keySet()) {
            if(map.get(e)==1) {
                answer = e;
                break;
            }
        }
        return answer;
    }
}