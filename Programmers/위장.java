import java.util.*;
class Solution {
    public int solution(String[][] clothes) {
        Map<String,Integer> map = new HashMap<>();
        for(int i=0;i<clothes.length;i++) {
            String s = clothes[i][1];
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
        int cnt=1;
        for(String e : map.keySet()) {
            cnt *= (map.get(e)+1);
        }
        return cnt-1;
    }
}