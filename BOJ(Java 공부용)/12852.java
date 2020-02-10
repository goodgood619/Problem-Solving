import java.io.*;
import java.util.*;
public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[] gox = {0, 1, -1, 0};
    static int[] goy = {1, 0, 0, -1};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int[] dp = new int[n + 1];
        int[] path = new int[n + 1];
        Arrays.fill(dp, -1);

        bw.write(go(n, dp, path) + "\n");
        bw.write(n + " ");
        while (n != 1) {
            bw.write(path[n] + " ");
            n = path[n];
        }
        bw.flush();
        bw.close();
    }

    private static int go(int n, int[] dp, int[] path) {
        if (n == 1) return 0;
        if (dp[n] != -1) return dp[n];
        dp[n] = (int) 1e9;
        int next = n;
        if (n % 3 == 0) {
            if (dp[n] > go(n / 3, dp, path) + 1) {
                dp[n] = go(n / 3, dp, path) + 1;
                next = n / 3;
            }
        }
        if (n % 2 == 0) {
            if (dp[n] > go(n / 2, dp, path) + 1) {
                dp[n] = go(n / 2, dp, path) + 1;
                next = n / 2;
            }
        }
        if (n >= 2) {
            if (dp[n] > go(n - 1, dp, path) + 1) {
                dp[n] = go(n - 1, dp, path) + 1;
                next = n - 1;
            }
        }
        path[n] = next;
        return dp[n];
    }
}