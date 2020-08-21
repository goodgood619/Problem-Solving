import java.util.*;
class Solution {
    public int[] solution(int[] array, int[][] commands) {
        int[] answer = new int[commands.length];
        int idx=0;
        for(int i=0;i<commands.length;i++) {
            int left = commands[i][0];
            int right = commands[i][1];
            List<Integer> list = new ArrayList<>();
            for(int j=left-1;j<=right-1;j++) {
                list.add(array[j]);
            }
            Collections.sort(list);
            answer[idx++] = list.get(commands[i][2]-1);
        }
        return answer;
    }
}