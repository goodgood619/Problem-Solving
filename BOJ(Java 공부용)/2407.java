import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[] gox = {0, 1, -1, 0, 1, 1, -1, -1};
    static int[] goy = {1, 0, 0, -1, 1, -1, 1, -1};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken()), k = Integer.parseInt(st.nextToken());
        BigInteger[][] dp = new BigInteger[n + 1][k + 1];
        System.out.println(go(n, k, dp));
    }

    private static BigInteger go(int n, int k, BigInteger[][] dp) {
        if (n <= 0 || k < 0) return BigInteger.ZERO;
        if (n == 1 || n == k || k == 0) return BigInteger.ONE;
        if (dp[n][k] != null) return dp[n][k];
        dp[n][k] = go(n - 1, k - 1, dp).add(go(n - 1, k, dp));
        return dp[n][k];
    }
}