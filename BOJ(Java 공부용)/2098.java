import java.io.*;
import java.util.StringTokenizer;
import static java.lang.Integer.min;
public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine());
        int[][] dp = new int[n][1<<n];
        int[][] board = new int[n][n];
        for(int i=0;i<n;i++) {
            StringTokenizer st = new StringTokenizer(br.readLine());
            for(int j=0;j<n;j++) {
                board[i][j] = Integer.parseInt(st.nextToken());
            }
        }
        for(int i=0;i<n;i++) {
            for(int j=0;j<(1<<n);j++) {
                dp[i][j] = -1;
            }
        }

        System.out.println(go(0,1,n,board,dp));

    }
    private static int go(int here,int via,int n,int[][] board,int[][] dp) {
        if(via == (1<<n)-1) {
            if(board[here][0] == 0) return (int) 1e9;
            else return board[here][0];
        }
        if(dp[here][via] !=-1) return dp[here][via];
        dp[here][via] = (int) 1e9;
        for(int i=0;i<n;i++) {
            int next = i;
            if(board[here][next] == 0) continue;
            if(here != next && (via &(1<<i)) == 0) {
                dp[here][via] = min(dp[here][via],go(next,via | (1<<i),n,board,dp)+board[here][next]);
            }
        }
        return dp[here][via];
    }
}