import java.io.*;
import java.util.StringTokenizer;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[] gox = {0, 1, -1, 0, 1, 1, -1, -1};
    static int[] goy = {1, 0, 0, -1, 1, -1, 1, -1};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        StringTokenizer st = new StringTokenizer(br.readLine());
        int[] arr = new int[n];
        long[][] dp = new long[n][21];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j <= 20; j++) {
                dp[i][j] = -1;
            }
        }
        for (int i = 0; i < n; i++) arr[i] = Integer.parseInt(st.nextToken());
        System.out.println(go(1, arr[0], n - 1, dp, arr));
    }

    private static long go(int index, int sum, int depth, long[][] dp, int[] arr) {
        if (sum < 0 || sum > 20) return 0;
        if (index == depth) {
            if (sum == arr[depth]) return 1;
            else return 0;
        }
        if (dp[index][sum] != -1) return dp[index][sum];
        dp[index][sum] = 0;
        dp[index][sum] += go(index + 1, sum + arr[index], depth, dp, arr);
        dp[index][sum] += go(index + 1, sum - arr[index], depth, dp, arr);
        return dp[index][sum];
    }
}