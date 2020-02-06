import java.io.*;
import java.util.*;

import static java.lang.Integer.max;
public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine());
        int[] profit = new int[n + 1];
        int[] coin = new int[n + 1];
        int[] dp = new int[n + 1];
        for (int i = 1; i <= n; i++) {
            profit[i] = Integer.parseInt(st.nextToken());
            coin[i] = i;
        }
        Arrays.fill(dp, -1);
        dp[0] = 0;
        bw.write(go(n, coin, profit, dp) + " ");
        bw.flush();
        bw.close();
    }

    private static int go(int k, int[] coin, int[] profit, int[] dp) {
        if (dp[k] != -1) return dp[k];
        dp[k] = 0;
        for (int i = 1; i < coin.length; i++) {
            if (k - coin[i] >= 0) dp[k] = max(dp[k], go(k - coin[i], coin, profit, dp) + profit[i]);
        }
        return dp[k];
    }
}