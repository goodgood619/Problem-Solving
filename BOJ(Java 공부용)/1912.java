import java.io.*;
import static java.lang.Integer.max;
public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine().split(" ")[0]);
        String[] input = br.readLine().split(" ");
        int[] dp = new int[n];
        int max =-1000000000 ;
        for(int i=0;i<input.length;i++) {
            if(i==0) {
                dp[0] = Integer.parseInt(input[i]);
                max = max(max,dp[0]);
            }
            else {
                dp[i] = dp[i-1] + Integer.parseInt(input[i]);
                if(dp[i]<Integer.parseInt(input[i])) dp[i] = Integer.parseInt(input[i]);
                max = max(max,dp[i]);
            }
        }
        System.out.println(max);
    }
}