import java.io.*;
import java.math.BigInteger;
import java.util.StringTokenizer;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        BigInteger[][] dp = new BigInteger[n][n];
        int[][] board = new int[n][n];
        for (int i = 0; i < n; i++) {
            st = new StringTokenizer(br.readLine());
            for (int j = 0; j < n; j++) {
                board[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        System.out.println(go(0, 0, board, dp, n));
    }

    private static BigInteger go(int x, int y, int[][] board, BigInteger[][] dp, int n) {
        if (x >= n || y >= n || x < 0 || y < 0) return BigInteger.ZERO;
        if (x == n - 1 && y == n - 1) return BigInteger.ONE;
        if (dp[x][y] != null) return dp[x][y];
        int jump = board[x][y];
        if (jump == 0) {
            return BigInteger.ZERO;
        }
        dp[x][y] = go(x + jump, y, board, dp, n).add(go(x, y + jump, board, dp, n));
        return dp[x][y];
    }
}