import java.io.*;
import java.util.Arrays;
import java.util.StringTokenizer;

import static java.lang.Integer.max;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[] gox = {0, 0, 1, -1};
    static int[] goy = {1, -1, 0, 0};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int[] ti = new int[n + 1];
        int[] pi = new int[n + 1];
        int[] dp = new int[n + 1];
        Arrays.fill(dp, -1);
        for (int i = 1; i <= n; i++) {
            st = new StringTokenizer(br.readLine());
            ti[i] = Integer.parseInt(st.nextToken());
            pi[i] = Integer.parseInt(st.nextToken());
        }
        bw.write(go(1, ti, pi, n, dp) + " ");
        bw.flush();
        bw.close();
    }

    private static int go(int day, int[] ti, int[] pi, int n, int[] dp) {
        if (day == n + 1) return 0;
        if (day > n) return (int) -1e9;
        if (dp[day] != -1) return dp[day];
        dp[day] = max(go(day + 1, ti, pi, n, dp), go(day + ti[day], ti, pi, n, dp) + pi[day]);
        return dp[day];
    }
}