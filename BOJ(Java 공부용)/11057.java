import java.io.*;
import java.util.*;
public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int[][] dp = new int[n][10];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 10; j++) {
                dp[i][j] = -1;
            }
        }
        int ans = 0;
        for (int i = 0; i < 10; i++) {
            ans += go(1, i, n, dp);
            ans %= 10007;
        }
        System.out.println(ans);
    }

    private static int go(int index, int num, int n, int[][] dp) {
        if (index >= n) return 1;
        if (dp[index][num] != -1) return dp[index][num];
        dp[index][num] = 0;
        for (int i = num; i < 10; i++) {
            dp[index][num] += go(index + 1, i, n, dp);
            dp[index][num] %= 10007;
        }
        return dp[index][num];
    }
}