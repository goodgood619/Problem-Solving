import java.io.*;
import static java.lang.Integer.max;
public class Main {
    static BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
    static int st =0,Max=0;
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int n = Integer.parseInt(br.readLine().split(" ")[0]);
        int[][] dp = new int[n+1][n+1];
        int[][] arr = new int[n+1][n+1];
        for(int i=1;i<=n;i++) {
            for(int j=1;j<=n;j++) {
                dp[i][j] = -1;
                arr[i][j] = 0;
            }
        }
        for(int i=1;i<=n;i++) {
            String[] input = br.readLine().split(" ");
            for(int j=0;j<input.length;j++) {
                arr[i][j+1] = Integer.parseInt(input[j]);
            }
        }
        bw.write(String.valueOf(go(1,1,n,arr,dp)));
        bw.flush();
    }
    private static int go(int x,int y,int n,int[][] arr ,int[][] dp) {
        if(x >n || y>n ) return 0;
        if(dp[x][y]!=-1) return dp[x][y];
        dp[x][y] = 0;
        dp[x][y] = max(go(x+1,y,n,arr,dp)+arr[x][y],go(x+1,y+1,n,arr,dp)+arr[x][y]);
        return dp[x][y];
    }
}