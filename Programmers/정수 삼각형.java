class Solution {
    public int solution(int[][] triangle) {
        int answer = 0;
        int n = triangle.length;
        int m = triangle[n-1].length;
        int[][] dp = new int[n][m];
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                dp[i][j] = -1;
            }
        }
        answer = go(triangle,dp,0,0,n,m);
        return answer;
    }
    private int go(int[][] arr, int[][] dp, int x,int y,int n,int m) {
        if(x>=n || y>=m) return 0;
        if(dp[x][y] != -1) return dp[x][y];
        dp[x][y] = 0;
        dp[x][y] = Math.max(go(arr,dp,x+1,y,n,m)+arr[x][y],go(arr,dp,x+1,y+1,n,m)+arr[x][y]);
        return dp[x][y];
    }
}