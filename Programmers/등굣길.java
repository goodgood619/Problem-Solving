import java.util.*;
class Solution {
    public int solution(int m, int n, int[][] puddles) {
        int[][] board = new int[m][n];
        for(int i=0;i<puddles.length;i++) {
            int x = puddles[i][0];
            int y = puddles[i][1];
            board[--x][--y] = 1;
        }
        int[][] dp = new int[m][n];
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) {
                dp[i][j]=-1;
            }
        }
        return go(0,0,m,n,board,dp);
    }
    private int go(int x,int y,int n,int m,int[][] board,int[][] dp) {
        if(x>=n || y>=m || board[x][y]==1) return 0;
        if(x == n-1 && y==m-1) return 1;
        if(dp[x][y]!=-1) return dp[x][y];
        dp[x][y]=0;
        dp[x][y]+=go(x+1,y,n,m,board,dp)+go(x,y+1,n,m,board,dp);
        dp[x][y]%=1000000007;
        return dp[x][y];
    }
}