import java.io.*;
import java.util.StringTokenizer;
import static java.lang.Integer.min;
public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int[] goy = {-1,0,1};
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken()), m = Integer.parseInt(st.nextToken());
        int[][] board = new int[n+1][m+1];
        int[][][] dp = new int[n+1][m+1][3];
        for(int i=1;i<=n;i++) {
            st = new StringTokenizer(br.readLine());
            for(int j=1;j<=m;j++) {
                board[i][j] = Integer.parseInt(st.nextToken());
            }
        }

        for(int i=1;i<=n;i++) {
            for(int j=1;j<=m;j++) {
                for(int k=0;k<3;k++) {
                    dp[i][j][k] = -1;
                }
            }
        }

        int ans = (int) 1e9;
        for(int i=1;i<=m;i++) {
            for(int j=0;j<3;j++) {
                ans = min(ans,go(dp,1,i,j,board,n,m));
            }
        }
        bw.write(ans+"\n");
        bw.flush();
        bw.close();
    }
    private static int go(int[][][] dp,int x,int y,int dir,int[][] board,int n,int m) {
        if(x == n+1) return 0;
        if(dp[x][y][dir] != -1) return dp[x][y][dir];
        dp[x][y][dir] = (int) 1e9;
        for(int i=0;i<3;i++) {
            if(dir != i && y+goy[i]>=1 && y+goy[i]<=m) {
                dp[x][y][dir] = min(dp[x][y][dir],go(dp,x+1,y+goy[i],i,board,n,m)+board[x][y]);
            }
        }
        return dp[x][y][dir];
    }
}