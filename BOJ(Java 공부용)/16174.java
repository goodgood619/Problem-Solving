import java.io.*;
import java.util.*;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[] gox = {0, 1, -1, 0};
    static int[] goy = {1, 0, 0, -1};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int[][] dp = new int[n][n];
        int[][] board = new int[n][n];
        for (int i = 0; i < n; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            for (int j = 0; j < n; j++) {
                board[i][j] = Integer.parseInt(st.nextToken());
                dp[i][j] = -1;
            }
        }
        go(0, 0, n, board, dp);
        System.out.println("Hing");
    }

    private static int go(int x, int y, int n, int[][] board, int[][] dp) {
        if (x >= n || y >= n) return 0;
        if (x == n - 1 && y == n - 1) {
            System.out.println("HaruHaru");
            System.exit(0);
        }
        if (dp[x][y] != -1) return dp[x][y];
        int jump = board[x][y];
        if (jump == 0) return 0;
        dp[x][y]=(go(x + jump, y, n, board, dp)+go(x, y + jump, n, board, dp))%1007;
        return dp[x][y];
    }
}