import java.io.*;
public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String[] input = br.readLine().split(" ");
        int n = Integer.parseInt(input[0]);
        int m = Integer.parseInt(input[1]);
        int[][] dp = new int[n+1][m+1];
        for(int i = 1; i<=m;i++) {
            dp[1][i] = i-1;
        }
        for(int i=1;i<=n;i++) {
            dp[i][1] = i-1;
        }
        for(int i=2;i<=n;i++) {
            for(int j=2;j<=m;j++) {
                dp[i][j] = dp[i][j-1] + i;
            }
        }
        System.out.println(dp[n][m]);
    }
}