import java.io.*;
import java.util.StringTokenizer;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[] gox = {0, 0, 1, -1};
    static int[] goy = {1, -1, 0, 0};
    static int counter = 1;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken()), m = Integer.parseInt(st.nextToken()), k = Integer.parseInt(st.nextToken());
        int[][] dp = new int[n][m];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) dp[i][j] = -1;
        }
        if (k != 0) {
            k--;
            int mx = k / m, my = k % m;
            bw.write((go(0, 0, mx, my, mx + 1, my + 1, dp) * go(mx, my, n - 1, m - 1, n, m, dp)) + " ");
        } else {
            bw.write(go(0, 0, n - 1, m - 1, n, m, dp) + " ");
        }
        bw.flush();
        bw.close();
    }

    private static int go(int x, int y, int ex, int ey, int n, int m, int[][] dp) {
        if (x >= n || y >= m) return 0;
        if (x == ex && y == ey) return 1;
        if (dp[x][y] != -1) return dp[x][y];
        dp[x][y] = 0;
        dp[x][y] += go(x + 1, y, ex, ey, n, m, dp) + go(x, y + 1, ex, ey, n, m, dp);
        return dp[x][y];
    }
}