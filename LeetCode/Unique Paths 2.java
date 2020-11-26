class Solution {
    public int uniquePathsWithObstacles(int[][] board) {
        int n= board.length;
        int m = board[0].length;
        int[][] dp = new int[n][m];
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                dp[i][j]=-1;
            }
        }
        
        return go(0,0,board,dp,n,m);
    }
    private int go(int x,int y,int[][] board, int[][] dp, int n,int m) {
        if(x>=n || y>=m || board[x][y]==1) return 0;
        if(x==n-1 && y==m-1) return 1;
        if(dp[x][y]!=-1) return dp[x][y];
        dp[x][y]=0;
        dp[x][y]+=go(x+1,y,board,dp,n,m)+go(x,y+1,board,dp,n,m);
        return dp[x][y];
    }
}