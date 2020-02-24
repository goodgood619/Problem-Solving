import java.io.*;
import java.util.StringTokenizer;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[] gox = {0, 0, 1, -1};
    static int[] goy = {1, -1, 0, 0};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int[] arr = new int[n];
        StringTokenizer st = new StringTokenizer(br.readLine());
        for (int i = 0; i < n; i++) arr[i] = Integer.parseInt(st.nextToken());
        int[][] dp = new int[n][n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                dp[i][j] = -1;
            }
        }

        int k = Integer.parseInt(br.readLine());
        for (int i = 0; i < k; i++) {
            st = new StringTokenizer(br.readLine());
            int left = Integer.parseInt(st.nextToken()), right = Integer.parseInt(st.nextToken());
            left--;
            right--;
            bw.write(go(left, right, arr, dp) + "\n");
        }
        bw.flush();
        bw.close();
    }

    private static int go(int left, int right, int[] arr, int[][] dp) {
        if (left >= right) return 1;
        if (arr[left] != arr[right]) return 0;
        if (dp[left][right] != -1) return dp[left][right];
        dp[left][right] = 0;
        dp[left][right] = go(left + 1, right - 1, arr, dp);
        return dp[left][right];
    }
}