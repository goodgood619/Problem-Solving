import java.util.*;

class Solution {
    public int[] solution(String s) {
        s = s.substring(2,s.length()-2).replace("},{","-");
        // System.out.println(s);
        String[] arr = s.split("-");
        Arrays.sort(arr,(o1,o2)-> o1.length()-o2.length());
        List<Integer> list = new ArrayList<>();
        for(String temp : arr) {
            String[] strArr = temp.split(",");
            for(String t:strArr) {
                int value = Integer.parseInt(t);
                if(!list.contains(value)) {
                    list.add(value);
                }
            }
        }
        int[] answer = {};
        answer = new int[list.size()];
        for(int i=0;i<list.size();i++) {
            answer[i] = list.get(i);
        }
        return answer;
    }
}