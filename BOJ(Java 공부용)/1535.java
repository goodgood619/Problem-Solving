import java.io.*;
import static java.lang.Integer.max;
public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine().split(" ")[0]);
        String[] input = br.readLine().split(" ");
        String[] input2 = br.readLine().split(" ");
        p[] v = new p[n+1];
        for(int i=0;i<input.length;i++) {
            v[i+1] = new p(Integer.parseInt(input[i]),Integer.parseInt(input2[i]));
        }
        int[][] dp = new int[n+1][101];
        for(int i=0;i<=n;i++ ){
            for(int j=0;j<=100;j++) {
                dp[i][j] = -1;
            }
        }
        bw.write(go(n,100,dp,v)+"\n");
        bw.flush();
        bw.close();
    }
    private static int go(int n,int t,int[][] dp,p[] v) {
        if(t<=0 || n==0) return 0;
        if(dp[n][t]!=-1) return dp[n][t];
        dp[n][t] = 0;
        dp[n][t] = max(dp[n][t],go(n-1,t,dp,v));
        if(t>v[n].first) dp[n][t] = max(dp[n][t],go(n-1,t-v[n].first,dp,v)+v[n].second);
        return dp[n][t];
    }
    private static class p{
        int first,second;
        private p(int first,int second) {
            this.first = first;
            this.second = second;
        }
    }
}