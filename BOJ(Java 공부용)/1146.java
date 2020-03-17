import java.io.*;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[] gox = {0, 1, -1, 0};
    static int[] goy = {1, 0, 0, -1};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int[][][] dp = new int[n + 1][n + 1][2];
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= n; j++) {
                for (int k = 0; k < 2; k++) {
                    dp[i][j][k] = -1;
                }
            }
        }
        int ans = 0;
        boolean[] visited = new boolean[n + 1];
        for (int i = 1; i <= n; i++) {
            visited[i] = true;
            ans += go(i, 1, 0, dp, visited, n);
            visited[i] = true;
            ans += go(i, 1, 1, dp, visited, n);
            visited[i] = false;
            ans %= 1000000;
        }
        if (n == 1) ans = 1;
        bw.write((ans % 1000000) + "\n");
        bw.flush();
        bw.close();
    }

    private static int go(int cur, int depth, int choose, int[][][] dp, boolean[] visited, int n) {
        if (depth == n) return 1;
        if (dp[cur][depth][choose] != -1) return dp[cur][depth][choose];
        dp[cur][depth][choose] = 0;
        if (choose == 0) {
            for (int i = cur + 1; i <= n; i++) {
                if (!visited[i]) {
                    visited[i] = true;
                    dp[cur][depth][choose] += go(i, depth + 1, 1, dp, visited, n);
                    visited[i] = false;
                }
            }
        } else {
            for (int i = cur - 1; i >= 1; i--) {
                if (!visited[i]) {
                    visited[i] = true;
                    dp[cur][depth][choose] += go(i, depth + 1, 0, dp, visited, n);
                    visited[i] = false;
                }
            }
        }
        dp[cur][depth][choose] %= 1000000;
        return dp[cur][depth][choose];
    }
}