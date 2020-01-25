import java.io.*;

import static java.lang.Integer.min;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int st =0,Max=0;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine().split(" ")[0]);
        int[] dp = new int[n+1];
        for(int i=0;i<=n;i++) dp[i] = -1;
        bw.write(String.valueOf(go(n,dp)));
        bw.flush();
    }
    private static int go(int n,int[] dp) {
        if(n==1) return 0;
        if(dp[n] != -1) return dp[n];
        dp[n] = Integer.MAX_VALUE;
        if(n%3==0) {
            dp[n] = min(dp[n],go(n/3,dp)+1);
        }
        if(n%2==0){
            dp[n] = min(dp[n],go(n/2,dp)+1);
        }
        if(n>=2) {
            dp[n] = min(dp[n],go(n-1,dp)+1);
        }
        return dp[n];
    }
}