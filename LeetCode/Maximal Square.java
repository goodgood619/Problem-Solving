class Solution {
    public int maximalSquare(char[][] matrix) {
        int n = matrix.length;
        int m = matrix[0].length;
        int[][] dp = new int[n][m];
        int ans=0;
        for(int i=0;i<n;i++){ 
            if(matrix[i][0]=='1'){ 
                dp[i][0] = 1;
                ans= 1;                          
            }
        }
        for(int j=0;j<m;j++) {
            if(matrix[0][j]=='1'){ 
                dp[0][j] = 1;
                ans = 1;
            }
        }
        for(int i=1;i<n;i++) {
            for(int j=1;j<m;j++) {
                if(matrix[i][j]=='1') {
                    dp[i][j] = Math.min(Math.min(dp[i][j-1],dp[i-1][j]),dp[i-1][j-1])+1;
                    ans = Math.max(ans,dp[i][j]);  
                }
            }
        }
        return ans*ans;
    }
}