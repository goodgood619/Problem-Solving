import java.io.*;
import java.util.StringTokenizer;

public class Main {

    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[] gox = {0, 1, -1, 0};
    static int[] goy = {1, 0, 0, -1};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        while (t-- > 0) {
            int n = Integer.parseInt(br.readLine());
            StringTokenizer st = new StringTokenizer(br.readLine());
            int[] arr = new int[n];
            int[] dp = new int[n];
            for (int i = 0; i < n; i++) arr[i] = Integer.parseInt(st.nextToken());
            int ans = arr[0];
            for (int i = 0; i < n; i++) {
                if (i == 0) {
                    dp[0] = arr[0];
                } else {
                    dp[i] = Math.max(dp[i - 1], 0) + arr[i];
                    ans = Math.max(ans, dp[i]);
                }
            }
            bw.write(ans + "\n");
        }
        bw.flush();
        bw.close();
    }
}