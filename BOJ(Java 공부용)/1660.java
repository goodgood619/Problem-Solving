import java.io.*;
import java.util.ArrayList;
import java.util.Arrays;
import static java.lang.Integer.min;
public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    static int[] gox = {0, 1, -1, 0};
    static int[] goy = {1, 0, 0, -1};

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        ArrayList<Integer> sum = new ArrayList<>();
        int[] dp = new int[n + 1];
        Arrays.fill(dp, -1);
        for (int i = 1; ; i++) {
            if (i == 1) {
                sum.add(1);
                continue;
            }
            sum.add(i + sum.get(sum.size() - 1));
            if (sum.get(sum.size() - 1) > n) break;
        }
        ArrayList<Integer> coin = new ArrayList<>();

        for (int i = 0; ; i++) {
            if (i == 0) {
                coin.add(1);
                continue;
            }
            coin.add(sum.get(i) + coin.get(i - 1));
            if (coin.get(coin.size() - 1) > n) break;
        }

        System.out.println(go(n, coin, dp));
    }

    private static int go(int n, ArrayList<Integer> coin, int[] dp) {
        if (n == 0) return 0;
        if (n < 0) return (int) 1e9;
        if (dp[n] != -1) return dp[n];
        dp[n] = (int) 1e9;
        for (int i = coin.size() - 1; i >= 0; i--) {
            if (n - coin.get(i) >= 0) {
                dp[n] = min(dp[n], go(n - coin.get(i), coin, dp) + 1);
            }
        }
        return dp[n];
    }
}