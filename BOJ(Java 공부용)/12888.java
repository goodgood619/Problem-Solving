import java.io.*;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[] gox = {0, 0, 1, -1};
    static int[] goy = {1, -1, 0, 0};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        long[] dp = new long[61];
        dp[0] = 1;
        dp[1] = 1;
        int n = Integer.parseInt(br.readLine());
        for (int i = 2; i <= n; i++) {
            if (i % 2 == 0) {
                dp[i] = 2 * dp[i - 1] + 1;
            } else dp[i] = 2 * dp[i - 1] - 1;
        }
        bw.write(dp[n] + " ");
        bw.flush();
        bw.close();
    }
}