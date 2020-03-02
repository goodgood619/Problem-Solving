import java.io.*;
import java.util.StringTokenizer;

import static java.lang.Integer.min;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    static int[] gox = {0, 1, 0, -1};
    static int[] goy = {1, 0, -1, 0};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine());
        int[] arr = new int[n];
        int[][] dp = new int[n][n];
        for (int i = 0; i < n; i++) arr[i] = Integer.parseInt(st.nextToken());
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                dp[i][j] = -1;
            }
        }
        bw.write(go(0, n - 1, arr, dp) + " ");
        bw.flush();
        bw.close();
    }

    private static int go(int l, int r, int[] arr, int[][] dp) {
        if (l >= r) return 0;
        if (dp[l][r] != -1) return dp[l][r];
        dp[l][r] = (int) 1e9;
        if (arr[l] != arr[r]) dp[l][r] = min(dp[l][r], min(go(l + 1, r, arr, dp) + 1, go(l, r - 1, arr, dp) + 1));
        else dp[l][r] = min(dp[l][r], go(l + 1, r - 1, arr, dp));
        return dp[l][r];
    }
}