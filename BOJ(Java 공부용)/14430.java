import java.io.*;
import java.util.*;
import static java.lang.Integer.max;
public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken()), m = Integer.parseInt(st.nextToken());
        int[][] dp = new int[n][m];
        int[][] board = new int[n][m];
        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < m; j++) {
                board[i][j] = Integer.parseInt(st.nextToken());
                dp[i][j] = -1;
            }
        }
        go(n - 1, m - 1, n, m, dp, board);
        int max = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                max = max(max, dp[i][j]);
            }
        }
        System.out.println(max);
    }

    private static int go(int x, int y, int n, int m, int[][] dp, int[][] board) {
        if (x < 0 || y < 0 || x >= n || y >= m) return 0;
        if (dp[x][y] != -1) return dp[x][y];
        return dp[x][y] = max(go(x - 1, y, n, m, dp, board) + board[x][y], go(x, y - 1, n, m, dp, board) + board[x][y]);
    }
}