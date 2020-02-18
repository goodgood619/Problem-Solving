import java.io.*;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    static int[] gox = {0, 1, -1, 0, 1, 1, -1, -1};
    static int[] goy = {1, 0, 0, -1, 1, -1, 1, -1};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int[][][] dp = new int[n][n][n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < n; k++) {
                    dp[i][j][k] = -1;
                }
            }
        }

        System.out.println(go(0, 0, 0, dp, n));
    }

    private static int go(int x, int y1, int y2, int[][][] dp, int n) {
        if (x == n - 1) return 1;
        if (dp[x][y1][y2] != -1) return dp[x][y1][y2];
        dp[x][y1][y2] = 0;
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 2; j++) {
                if (y1 + i == y2 + j) continue;
                dp[x][y1][y2] += go(x + 1, y1 + i, y2 + j, dp, n);
                dp[x][y1][y2] %= 10007;
            }
        }
        return dp[x][y1][y2];
    }

}