import java.io.*;
import java.util.StringTokenizer;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[] gox = {0, 1, -1, 0, 1, 1, -1, -1};
    static int[] goy = {1, 0, 0, -1, 1, -1, 1, -1};

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
        if (x == n - 1 && y == m - 1) return 1;
        if (dp[x][y] != -1) return dp[x][y];
        dp[x][y] = 0;
        for (int i = 0; i < 4; i++) {
            int nx = x + gox[i], ny = y + goy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m || board[nx][ny] >= board[x][y]) continue;
            dp[x][y] += go(nx, ny, board, dp, n, m);
        }
        return dp[x][y];
    }
}