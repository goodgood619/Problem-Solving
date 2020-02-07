import java.io.*;
import java.util.StringTokenizer;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        int[] dp = new int[n + 1];
        dp[0] = 0;
        dp[1] = 1;
        if (n >= 2) {
            for (int i = 2; i <= n; i++) dp[i] = dp[i - 1] + dp[i - 2];
            System.out.println(dp[n]);
        } else System.out.println(1);

    }
}