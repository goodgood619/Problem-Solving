import java.io.*;
import java.util.StringTokenizer;

import static java.lang.Integer.max;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    static int[] gox = {0, 1, -1, 0};
    static int[] goy = {1, 0, 0, -1};
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken()), t = Integer.parseInt(st.nextToken());
        int[][] dp = new int[n + 1][t + 1];
        p[] arr = new p[n];
        for (int i = 0; i < n; i++) arr[i] = new p(0, 0);
        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            int k = Integer.parseInt(st.nextToken()), s = Integer.parseInt(st.nextToken());
            arr[i].score = s;
            arr[i].time = k;
        }
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= t; j++) {
                dp[i][j] = -1;
            }
        }
        System.out.println(go(n - 1, t, arr, dp));
    }

    private static int go(int n, int t, p[] arr, int[][] dp) {
        if (n < 0 || t <= 0) return 0;
        if (dp[n][t] != -1) return dp[n][t];
        dp[n][t] = 0;
        dp[n][t] = max(dp[n][t], go(n - 1, t, arr, dp));
        if (t - arr[n].time >= 0) dp[n][t] = max(dp[n][t], go(n - 1, t - arr[n].time, arr, dp) + arr[n].score);
        return dp[n][t];
    }

    private static class p {
        int time, score;

        private p(int time, int score) {
            this.time = time;
            this.score = score;
        }
    }
}