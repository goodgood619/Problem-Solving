import java.io.*;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[] gox = {0, 1, -1, 0};
    static int[] goy = {1, 0, 0, -1};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        while (t-- > 0) {
            int n = Integer.parseInt(br.readLine());
            long[][][] dp = new long[n + 1][n + 1][2];
            for (int i = 0; i <= n; i++) {
                for (int j = 0; j <= n; j++) {
                    for (int k = 0; k < 2; k++) {
                        dp[i][j][k] = -1;
                    }
                }
            }
            long ans = 0;
            for (int i = 0; i < n; i++) {
                ans += go(i, n - 1 - i, 0, dp);
                ans += go(i, n - 1 - i, 1, dp);
            }
            if (n == 1) ans = 1;
            bw.write(ans + "\n");
        }
        bw.flush();
        bw.close();
    }

    private static long go(int small, int big, int choose, long[][][] dp) {
        int curtotal = small + big;
        if (small == 0 && big == 0) return 1;
        if (dp[small][big][choose] != -1) return dp[small][big][choose];
        dp[small][big][choose] = 0;
        if (choose == 0) {
            for (int i = 0; i < big; i++) {
                dp[small][big][choose] += go(curtotal - (i + 1), i, 1, dp);
            }
        } else {
            for (int i = 0; i < small; i++) {
                dp[small][big][choose] += go(i, curtotal - (i + 1), 0, dp);
            }
        }
        return dp[small][big][choose];
    }
}