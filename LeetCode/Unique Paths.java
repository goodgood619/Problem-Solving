class Solution {
    public int uniquePaths(int m, int n) {
        int[][] dp = new int[m][n];
        for(int i=0;i<m;i++) {
            for(int j=0;j<n;j++) dp[i][j]=-1;
        }
        
        return go(dp,m,n,0,0);
    }
    private static int go(int[][] dp, int m,int n,int x,int y) {
        if(x>=m || y>=n) return 0;
        if(x==m-1 && y==n-1) return 1;
        if(dp[x][y]!=-1) return dp[x][y];
        dp[x][y]=0;
        dp[x][y]+=go(dp,m,n,x+1,y);
        dp[x][y]+=go(dp,m,n,x,y+1);
        return dp[x][y];
    }
}