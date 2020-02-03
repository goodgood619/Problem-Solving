import java.io.*;
public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        if(n == 1) {
            System.out.println(4);
            return;
        }
        long[] dp = new long[n+1];
        dp[1] = 1;
        dp[2] = 1;
        for(int i=3;i<=n;i++) {
            dp[i] = dp[i-1]+dp[i-2];
        }
        bw.write((dp[n]+dp[n]+dp[n-1])*2+" ");
        bw.flush();
        bw.close();
    }
}