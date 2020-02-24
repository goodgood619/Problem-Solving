import java.io.*;
import java.util.StringTokenizer;

import static java.lang.Integer.min;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[] gox = {0, 0, 1, -1};
    static int[] goy = {1, -1, 0, 0};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        while (t-- > 0) {
            int n = Integer.parseInt(br.readLine());
            StringTokenizer st = new StringTokenizer(br.readLine());
            int[] arr = new int[n + 1];
            int[] sum = new int[n + 1];
            for (int i = 1; i <= n; i++) {
                arr[i] = Integer.parseInt(st.nextToken());
                sum[i] = sum[i - 1] + arr[i];
            }
            int[][] dp = new int[n + 1][n + 1];
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= n; j++) {
                    dp[i][j] = -1;
                }
            }

            bw.write(go(1, n, dp, sum) + "\n");
        }
        bw.flush();
        bw.close();
    }

    private static int go(int left, int right, int[][] dp, int[] sum) {
        if (left == right) return 0;
        if (dp[left][right] != -1) return dp[left][right];
        dp[left][right] = (int) 1e9;
        for (int i = left; i < right; i++) {
            dp[left][right] = min(dp[left][right], go(left, i, dp, sum) + go(i + 1, right, dp, sum) + sum[right] - sum[left - 1]);
        }
        return dp[left][right];
    }
}