import java.io.*;
import java.util.StringTokenizer;

import static java.lang.Integer.max;
public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
//    static int[] gox = {0, 1, -1, 0};
//    static int[] goy = {1, 0, 0, -1};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken()), m = Integer.parseInt(st.nextToken());
        int[][] board = new int[n][m];
        int[][] dp = new int[n][m];
        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < m; j++) {
                board[i][j] = Integer.parseInt(st.nextToken());
                dp[i][j] = -1;
            }
        }
        System.out.println(go(0, 0, board, dp, n, m));
    }

    private static int go(int x, int y, int[][] board, int[][] dp, int n, int m) {
        if (x < 0 || x >= n || y < 0 || y >= m) return 0;
        if (dp[x][y] != -1) return dp[x][y];
        dp[x][y] = board[x][y];
        dp[x][y] += max(go(x + 1, y, board, dp, n, m), max(go(x, y + 1, board, dp, n, m), go(x + 1, y + 1, board, dp, n, m)));
        return dp[x][y];
    }
}