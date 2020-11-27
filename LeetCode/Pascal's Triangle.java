class Solution {
    public List<List<Integer>> generate(int numRows) {
        if(numRows==0) return new ArrayList<>();
        int[][] dp = new int[numRows][numRows];
        for(int i=0;i<numRows;i++) {
            for(int j=0;j<numRows;j++) {
                dp[i][j]=-1;
            }
        }
        dp[0][0]=1;
        for(int i=0;i<numRows;i++) go(dp,numRows-1,i);
        List<List<Integer>> ans = new ArrayList<>();
        for(int i=0;i<numRows;i++) {
            List<Integer> temp = new ArrayList<>();
            for(int j=0;j<=i;j++) {
                temp.add(dp[i][j]);
            }
            ans.add(temp);
        }
        return ans;
    }
    private int go(int[][] dp,int n,int m) {
        if(m==0 || n==m) {
            dp[n][m]=1;
            return dp[n][m];
        }
        if(dp[n][m]!=-1) return dp[n][m];
        dp[n][m]=0;
        dp[n][m]=go(dp,n-1,m-1)+go(dp,n-1,m);
        return dp[n][m];
    }
}