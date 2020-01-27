import java.io.*;
import java.util.ArrayList;

import static java.lang.Integer.min;
public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] input = br.readLine().split(" ");
        int n = Integer.parseInt(input[0]);
        ArrayList<Integer> coin = new ArrayList<>();
        int[] dp = new int[100001];
        for(int i=0;i<=100000;i++) dp[i] = -1;
        for(int i=1;i<=n;i++) {
            int k = i*i;
            if(k<=n) coin.add(k);
            else break;
        }
        int ans = go(n,coin,dp);
        bw.write(ans == 100000000?"-1\n":String.valueOf(ans));
        bw.flush();
        bw.close();
    }
    private static int go(int k,ArrayList<Integer> coin,int[] dp) {
        if(k==0) return 0;
        if(k<0) return 100000000;
        if(dp[k]!=-1) return dp[k];
        dp[k] = 100000000;
        for(int i=0;i<coin.size();i++) {
            if(k-coin.get(i)>=0) {
                dp[k] = min(dp[k],go(k-coin.get(i),coin,dp)+1);
            }
        }
        return dp[k];
    }
}