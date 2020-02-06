import java.io.*;
import java.util.*;

import static java.lang.Integer.min;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        st = new StringTokenizer(br.readLine());
        int[] arr = new int[n + 1];
        int[] dp = new int[n + 1];
        for (int i = 1; i <= n; i++) arr[i] = Integer.parseInt(st.nextToken());
        Arrays.fill(dp, -1);
        System.out.println(go(1, arr, dp, n) == 1e9 ? -1 : go(1, arr, dp, n));
    }

    private static int go(int index, int[] arr, int[] dp, int n) {
        if (index >= n) return 0;
        if (dp[index] != -1) return dp[index];
        dp[index] = (int) 1e9;
        for (int i = index; i <= index + arr[index]; i++) dp[index] = min(dp[index], go(i, arr, dp, n) + 1);
        return dp[index];
    }
}