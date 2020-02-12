import java.io.*;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    static int[] gox = {0, 1, -1, 0, 1, -1};
    static int[] goy = {1, 0, 0, -1, 0, 0};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        while (t-- > 0) {
            int n = Integer.parseInt(br.readLine());
            int[] coin = new int[n + 1];
            int[][] dp = new int[n + 1][n + 1];
            for (int i = 0; i <= n; i++) coin[i] = i;
            for (int i = 0; i <= n; i++) {
                for (int j = 0; j <= n; j++) {
                    dp[i][j] = -1;
                }
            }
            bw.write(go(n, 1, coin, dp) + "\n");
        }
        bw.flush();
        bw.close();
    }

    private static int go(int k, int index, int[] coin, int[][] dp) {
        if (index >= coin.length) return 0;
        if (k < 0) return 0;
        if (k == 0) return 1;
        if (coin[index] == k) return 1;
        if (dp[k][index] != -1) return dp[k][index];
        dp[k][index] = 0;
        dp[k][index] = go(k - coin[index], index + 1, coin, dp) + go(k, index + 1, coin, dp);
        return dp[k][index] % 100999;
    }
}