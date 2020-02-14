import java.io.*;
import java.util.Arrays;

public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));

    static int[] gox = {0, 1, -1, 0};
    static int[] goy = {1, 0, 0, -1};
    
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        String s = br.readLine();
        int[] dp = new int[s.length()];
        Arrays.fill(dp, -1);
        System.out.println(go(s, 0, dp));
    }

    private static int go(String s, int index, int[] dp) {
        if (index == s.length()) return 1;
        if (dp[index] != -1) return dp[index];
        dp[index] = 0;
        if (s.charAt(index) >= '1' && s.charAt(index) <= '9') dp[index] += go(s, index + 1, dp);
        if (index < s.length() - 1) {
            int temp = (s.charAt(index) - '0') * 10 + s.charAt(index + 1) - '0';
            if (temp >= 10 && temp <= 26) dp[index] += go(s, index + 2, dp);
        }
        return dp[index] % 1000000;
    }

}