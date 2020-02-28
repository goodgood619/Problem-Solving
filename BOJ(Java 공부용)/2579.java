import java.io.*;

import static java.lang.Integer.max;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[] gox = {0, 1, 0, -1};
    static int[] goy = {1, 0, -1, 0};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int[] arr = new int[n];
        for (int i = 0; i < n; i++) arr[i] = Integer.parseInt(br.readLine());
        int[][] dp = new int[n][3];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 3; j++) {
                dp[i][j] = -1;
            }
        }
        bw.write(max(go(n - 1, 1, arr, dp), go(n - 1, 2, arr, dp)) + "\n");
        bw.flush();
        bw.close();
    }

    private static int go(int n, int cnt, int[] arr, int[][] dp) {
        if (n < 0) return 0;
        if (dp[n][cnt] != -1) return dp[n][cnt];
        dp[n][cnt] = 0;
        if (cnt == 1) dp[n][cnt] = max(dp[n][cnt], go(n - 1, 2, arr, dp) + arr[n]);
        else dp[n][cnt] = max(dp[n][cnt], max(go(n - 2, 1, arr, dp), go(n - 2, 2, arr, dp)) + arr[n]);
        return dp[n][cnt];
    }
}