import java.util.*;
import java.io.*;
class Solution {
    public int solution(int[] money) {
        int answer = 0;
        // dp[i] : i번째 집을 털었을때 얻을수 있는 최대 이익
        // dp[i] : money[i]+dp[i+2], dp[i+1]; //현재있는 집을 털거냐 안털거냐
        // 첫번째 집부터 털경우, 두번째집부터 털경우
        
        int n = money.length;
        int[] first = new int[n];
        int[] second = new int[n];
        Arrays.fill(first,money[0]);
        Arrays.fill(second,money[1]);
        second[0] = 0;
        for(int i=2;i<first.length-1;i++) {
            first[i] = Math.max(first[i-2]+money[i],first[i-1]);
            answer= Math.max(answer,first[i]);
        }
        for(int i=2;i<second.length;i++) {
            second[i] = Math.max(second[i-2]+money[i],second[i-1]);
            answer = Math.max(answer,second[i]);
        }
        return answer;
    }
}