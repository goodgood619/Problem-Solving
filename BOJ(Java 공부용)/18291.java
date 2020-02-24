import java.io.*;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[] gox = {0, 0, 1, -1};
    static int[] goy = {1, -1, 0, 0};
    static long mod = (long) (1e9 + 7);

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(br.readLine());
        while (t-- > 0) {
            // dp[1] =1 ;
            // dp[n]=dp[n-1]+dp[n-2]+...+dp[1];
            // dp[n-1] = dp[n-2]+...dp[1];
            // dp[3] = dp[2]+dp[1], dp[2] = dp[1], dp[3] = 2*dp[1];
            // dp[4] = dp[3]+dp[2]+dp[1] = dp[2]+dp[1]+dp[2]+dp[1] = 4*dp[1];
            // dp[5] = 4+3+2+1 = 3+2+1+2+1+1+1 = 1+1+1+1+1+1+1+1 = 8dp[1];
            //dp[n] = 2^(n-2)dp[1];
            int num = Integer.parseInt(br.readLine());
            if (num == 1) bw.write("1\n");
            else bw.write(go(num - 2) + "\n");
        }
        bw.flush();
        bw.close();
    }

    private static long go(int n) {
        if (n == 0) return 1;
        if (n % 2 == 0) {
            long ret = go(n / 2);
            return ret * ret % mod;
        } else {
            long ret = go(n / 2);
            return ret * ret * 2 % mod;
        }
    }
}