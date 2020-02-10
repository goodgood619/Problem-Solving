import java.io.*;
import static java.lang.Integer.max;
import static java.lang.StrictMath.sqrt;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[] gox = {0, 1, -1, 0};
    static int[] goy = {1, 0, 0, -1};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        boolean[] notprime = new boolean[1000001];
        for (int i = 2; i <= sqrt(1000000); i++) {
            if (notprime[i]) continue;
            for (int j = i * i; j <= 1000000; j += i) {
                notprime[j] = true;
            }
        }
        int n = Integer.parseInt(br.readLine());
        int[][] dp = new int[n + 1][n + 1];
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= n; j++) {
                dp[i][j] = -1;
            }
        }
        System.out.println(go(1, 1, dp, notprime, n) - 1);
    }

    private static int go(int a, int b, int[][] dp, boolean[] notprime, int n) {
        if (a > n || b > n) return 0;
        if (a == n && b == n) return 0;
        if (dp[a][b] != -1) return dp[a][b];
        StringBuilder sb = new StringBuilder();
        sb.append(a);
        sb.append(b);
        int here = Integer.parseInt(sb.toString());
        dp[a][b] = 0;
        if (!notprime[here])
            dp[a][b] = max(dp[a][b], max(go(a + 1, b, dp, notprime, n) + 1, go(a, b + 1, dp, notprime, n) + 1));
        else dp[a][b] = max(dp[a][b], max(go(a + 1, b, dp, notprime, n), go(a, b + 1, dp, notprime, n)));
        return dp[a][b];
    }
}