import java.io.*;
import java.util.Arrays;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String s = br.readLine();
        int[] dp = new int[s.length()];
        Arrays.fill(dp, -1);
        System.out.println(go(s, 0, dp));
    }

    private static int go(String s, int here, int[] dp) {
        if (here >= s.length()) return 1;
        if (dp[here] != -1) return dp[here];
        dp[here] = 0;
        int sum = 0;
        if (s.charAt(here) - '0' != 0) dp[here] += go(s, here + 1, dp);
        if (here + 1 < s.length()) {
            sum += (s.charAt(here) - '0') * 10;
            sum += (s.charAt(here + 1) - '0');
            if (sum >= 10 && sum <= 34) dp[here] += go(s, here + 2, dp);
        }
        return dp[here];
    }
}