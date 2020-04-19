import java.io.*;
import static java.lang.Integer.min;
public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] input = br.readLine().split(" ");
        int n = Integer.parseInt(input[0]);
        int k = Integer.parseInt(input[1]);
        int[] coin = new int[n];
        int[] dp = new int[10001];
        for(int i=0;i<=10000;i++) dp[i] = -1;
        for(int i=0;i<n;i++){
            String s = br.readLine();
            coin[i] = Integer.parseInt(s);
        }
        int ans = go(k,coin,dp);
        bw.write(ans == 100000000?"-1\n":String.valueOf(ans));
        bw.flush();
        bw.close();
    }
    private static int go(int k,int[] coin,int[] dp) {
        if(k==0) return 0;
        if(k<0) return 100000000;
        if(dp[k]!=-1) return dp[k];
        dp[k] = 100000000;
        for(int i=0;i<coin.length;i++) {
            if(k-coin[i]>=0) {
                dp[k] = min(dp[k],go(k-coin[i],coin,dp)+1);
            }
        }
        return dp[k];
    }
}
