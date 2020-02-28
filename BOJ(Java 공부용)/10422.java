import java.io.*;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[] gox = {0, 1, 0, -1};
    static int[] goy = {1, 0, -1, 0};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        long[][] dp = new long[5000][5000];
        for (int i = 0; i < 5000; i++) {
            for (int j = 0; j < 5000; j++) {
                dp[i][j] = -1;
            }
        }
        while (t-- > 0) {
            int n = Integer.parseInt(br.readLine());
            if (n % 2 == 1) bw.write("0\n");
            else bw.write(go(n / 2, n / 2, dp) + "\n");
        }
        bw.flush();
        bw.close();
    }

    private static long go(int x, int y, long[][] dp) {
        if (x < y || x < 0 || y < 0) return 0;
        if (x == 0 && y == 0) return 1;
        if (dp[x][y] != -1) return dp[x][y];
        dp[x][y] = 0;
        dp[x][y] += go(x - 1, y, dp) + go(x, y - 1, dp);
        dp[x][y] %= 1000000007;
        return dp[x][y];
    }
}