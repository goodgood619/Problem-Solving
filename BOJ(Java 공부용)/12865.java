import java.io.*;
import java.util.*;

import static java.lang.Integer.max;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken()), k = Integer.parseInt(st.nextToken());
        p[] bag = new p[n + 1];
        for (int i = 0; i <= n; i++) bag[i] = new p(0, 0);
        for (int i = 1; i <= n; i++) {
            st = new StringTokenizer(br.readLine());
            int first = Integer.parseInt(st.nextToken()), second = Integer.parseInt(st.nextToken());
            bag[i].first = first;
            bag[i].second = second;
        }
        int[][] dp = new int[n + 1][100001];
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= 100000; j++) dp[i][j] = -1;
        }
        System.out.println(go(n, k, bag, dp) + " ");
    }

    private static int go(int n, int k, p[] bag, int[][] dp) {
        if (k <= 0 || n <= 0) return 0;
        if (dp[n][k] != -1) return dp[n][k];
        dp[n][k] = 0;
        dp[n][k] = max(dp[n][k], go(n - 1, k, bag, dp));
        if (k - bag[n].first >= 0)
            dp[n][k] = max(dp[n][k], go(n - 1, k - bag[n].first, bag, dp) + bag[n].second);
        return dp[n][k];
    }

    private static class p {
        private int first;
        private int second;

        p(int first, int second) {
            this.first = first;
            this.second = second;
        }
    }
}