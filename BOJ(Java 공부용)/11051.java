import java.io.*;
import java.util.StringTokenizer;
public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
//    static int[] gox = {0, 1, -1, 0};
//    static int[] goy = {1, 0, 0, -1};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken()), k = Integer.parseInt(st.nextToken());
        int[][] dp = new int[n + 1][k + 1];
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= k; j++) {
                dp[i][j] = -1;
            }
        }
        System.out.println(go(n, k, dp));
    }

    private static int go(int n, int k, int[][] dp) {
        if (n == 0 || n == k || k == 0) return 1;
        if (dp[n][k] != -1) return dp[n][k];
        dp[n][k] = 0;
        dp[n][k] = (go(n - 1, k - 1, dp) + go(n - 1, k, dp)) % 10007;
        return dp[n][k];
    }
}