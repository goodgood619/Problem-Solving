import java.io.*;
import java.util.*;
import static java.lang.Integer.max;
public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[] gox = {0,1,-1,0};
    static int[] goy = {1,0,0,-1};
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n= Integer.parseInt(st.nextToken());
        int[][] board =new int[n][n];
        int[][] dp = new int[n][n];
        for(int i=0;i<n;i++) {
            st = new StringTokenizer(br.readLine());
            for(int j=0;j<n;j++) {
                board[i][j] = Integer.parseInt(st.nextToken());
                dp[i][j] = -1;
            }
        }

        int ans = 1;
        for(int i=0;i<n;i++) {
            for(int j=0;j<n;j++) {
                ans = max(ans,go(i,j,board,dp,1,n));
            }
        }
        System.out.println(ans);
    }
    private static int go(int x,int y,int[][] board, int[][] dp, int cnt,int n) {
        if(dp[x][y] !=-1) return dp[x][y];
        dp[x][y] = 1;
        for(int i=0;i<4;i++) {
            int nx = x+gox[i], ny = y+goy[i];
            if(nx< 0 || nx>=n || ny<0 || ny>=n || board[nx][ny]<=board[x][y])continue;
            dp[x][y] = max(dp[x][y], go(nx,ny,board,dp,cnt+1,n)+1);
        }
        return dp[x][y];
    }
}