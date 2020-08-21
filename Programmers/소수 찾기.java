import java.util.*;
import java.io.*;
class Solution {
    HashMap<Integer,Integer> map = new HashMap<>();
    int answer = 0;
    public int solution(String numbers) {
        for(int i=1;i<=numbers.length();i++) {
            StringBuilder sb = new StringBuilder();
            boolean[] visited = new boolean[numbers.length()];
            dfs(0,i,sb,visited,numbers);
        }
        return answer;
    }
    private boolean check(int num){
        for(int i=2;i<=Math.sqrt(num);i++) {
            if(num%i == 0) return false;
        }
        return true;
    }
    private void dfs(int cnt,int depth,StringBuilder sb,boolean[] visited,String numbers) {
        if(cnt == depth) {
            int num = Integer.parseInt(sb.toString());
            if(num == 0 || num == 1) return;
            if(map.get(num) == null && check(num)) {
                map.put(num,1);
                System.out.println(num);
                answer++;
            }
            return;
        }
        
        for(int i = 0 ;i<numbers.length();i++) {
            if(!visited[i]) {
                visited[i] = true;
                sb.append(numbers.charAt(i));
                dfs(cnt+1,depth,sb,visited,numbers);
                sb.deleteCharAt(sb.length()-1);
                visited[i] = false;
            }
        }
    }
}