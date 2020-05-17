import java.io.*;
import java.util.StringTokenizer;

public class Main {

    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[] gox = {0, 1, -1, 0};
    static int[] goy = {1, 0, 0, -1};
    static int ans = (int) -1e9;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine()), k = Integer.parseInt(br.readLine());
        P[] arr = new P[k];
        for (int i = 0; i < arr.length; i++) arr[i] = new P(0, 0);
        for (int i = 0; i < k; i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            arr[i].money = Integer.parseInt(st.nextToken());
            arr[i].cnt = Integer.parseInt(st.nextToken());
        }
        int[][] dp = new int[k][t + 1];
        for (int i = 0; i < k; i++) {
            for (int j = 0; j <= t; j++) {
                dp[i][j] = -1;
            }
        }
        bw.write(go(k - 1, t, dp, arr) + "");
        bw.flush();
        bw.close();
    }

    private static int go(int index, int t, int[][] dp, P[] arr) {
        if (t == 0) {
            return 1;
        }
        if (index < 0 || t < 0) return 0;
        if (dp[index][t] != -1) return dp[index][t];
        dp[index][t] = 0;
        for (int i = 0; i <= arr[index].cnt; i++) {
            if (t - i * arr[index].money >= 0) {
                dp[index][t] += go(index - 1, t - i * arr[index].money, dp, arr);
            }
        }
        return dp[index][t];
    }

}

class P {
    int money, cnt;

    P(int money, int cnt) {
        this.money = money;
        this.cnt = cnt;
    }
}