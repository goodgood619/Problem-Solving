import java.io.*;
import java.util.StringTokenizer;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[] gox = {0, 1, -1, 0};
    static int[] goy = {1, 0, 0, -1};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken()), k = Integer.parseInt(st.nextToken());
        int[] coin = new int[n + 1];
        int[] dp = new int[k + 1];
        dp[0] = 1;

        for (int i = 1; i <= n; i++) {
            int num = Integer.parseInt(br.readLine());
            coin[i] = num;
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= k; j++) {
                if (j - coin[i] >= 0) {
                    dp[j] += dp[j - coin[i]];
                }
            }
        }
        System.out.println(dp[k]);

    }
}