import java.io.*;
public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine().split(" ")[0]);
        long[][] dp = new long[n][2];
        for(int i=0;i<n;i++) {
            for(int j=0;j<2;j++){
                dp[i][j] = -1;
            }
        }
        bw.write(go(1,1,n,dp)+"\n");
        bw.flush();
        bw.close();
     }
     private static long go(int t,int num,int n,long[][] dp) {
        if(t == n) return 1;
        if(dp[t][num]!=-1) return dp[t][num];
        dp[t][num] = 0;
        if(num == 0) {
            dp[t][num] += go(t+1,(num+1)%2,n,dp);
            dp[t][num] += go(t+1,num%2,n,dp);
        }
        else dp[t][num] += go(t+1,0,n,dp);
        return dp[t][num];
     }
}