import java.io.*;
import java.util.StringTokenizer;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[] gox = {0, 1, -1, 0, 1, 1, -1, -1};
    static int[] goy = {1, 0, 0, -1, 1, -1, 1, -1};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int[][] board = new int[n][n];
        long[][] dp = new long[n][n];
        for (int i = 0; i < n; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            for (int j = 0; j < n; j++) {
                board[i][j] = Integer.parseInt(st.nextToken());
                dp[i][j] = -1;
            }
        }
        System.out.println(go(0, 0, board, dp, n));
    }

    private static long go(int x, int y, int[][] board, long[][] dp, int n) {
        if (x == n - 1 && y == n - 1) return 1;
        if (x >= n || y >= n) return 0;
        if (dp[x][y] != -1) return dp[x][y];
        dp[x][y] = 0;
        int jump = board[x][y];
        if (jump == 0) return 0;
        dp[x][y] = go(x + jump, y, board, dp, n) + go(x, y + jump, board, dp, n);
        return dp[x][y];
    }
}