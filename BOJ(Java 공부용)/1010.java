import java.io.*;
public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine().split(" ")[0]);
        for(int i=0;i<t;i++) {
            String[] input = br.readLine().split(" ");
            int k = Integer.parseInt(input[0]);
            int n = Integer.parseInt(input[1]);
            int[][] dp = new int[n+1][k+1];
            for(int j=0;j<=n;j++) {
                for(int p=0;p<=k;p++) {
                    dp[j][p] = -1;
                }
            }
            bw.write(go(n,k,dp)+"\n");
        }
        bw.flush();
        bw.close();
    }
    private static int go(int n,int k,int[][] dp) {
        if(k==0 || k==n || n==0) return 1;
        else if(n<0 || k<0) return 0;
        if(dp[n][k]!= -1) return dp[n][k];
        dp[n][k] = 0;
        dp[n][k] = go(n-1,k-1,dp) + go(n-1,k,dp);
        return dp[n][k];
    }
}