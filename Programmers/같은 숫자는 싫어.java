import java.util.*;

public class Solution {
    public int[] solution(int []arr) {
        int[] answer = {};
        List<Integer> list = new ArrayList<>();
        list.add(arr[0]);
        for(int i=1;i<arr.length;i++) {
            if(arr[i]!=arr[i-1]) {
                list.add(arr[i]);
            }
        }
        answer = new int[list.size()];
        int idx =0 ;
        for(int value : list) {
            answer[idx++] = value;
        }

        return answer;
    }
}