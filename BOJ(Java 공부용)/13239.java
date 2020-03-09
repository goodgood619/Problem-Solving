import java.io.*;
import java.util.StringTokenizer;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[] gox = {0, 0, 1, -1};
    static int[] goy = {1, -1, 0, 0};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        long[][] dp = new long[1001][1001];
        for (int i = 0; i <= 1000; i++) {
            for (int j = 0; j <= 1000; j++) {
                dp[i][j] = -1;
            }
        }
        int t = Integer.parseInt(br.readLine());
        while (t-- > 0) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            int n = Integer.parseInt(st.nextToken()), k = Integer.parseInt(st.nextToken());
            bw.write(go(n, k, dp) + "\n");
        }
        bw.flush();
        bw.close();
    }

    private static long go(int n, int k, long[][] dp) {
        if (n == 0 || k == 0 || n == k) return 1;
        if (dp[n][k] != -1) return dp[n][k];
        dp[n][k] = go(n - 1, k - 1, dp) + go(n - 1, k, dp);
        dp[n][k] %= 1000000007;
        return dp[n][k];
    }
}