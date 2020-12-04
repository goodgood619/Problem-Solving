class Solution {
    public int numSquares(int n) {
        List<Integer> coin = new ArrayList<>();
        for(int i=1;;i++) {
            int p = i*i;
            if(p<=n) coin.add(p);
            else break;
        }
        int[] dp = new int[n+1];
        Arrays.fill(dp,-1);
        return go(n,dp,coin);
    }
    private int go(int k,int[] dp,List<Integer> list) {
        if(k<0) return (int)1e9;
        if(k==0) return 0;
        if(dp[k]!=-1) return dp[k];
        dp[k] = (int)1e9;
        for(int i=list.size()-1;i>=0;i--) {
            int cur =list.get(i);
            if(k-cur>=0) {
                dp[k] = Math.min(dp[k],go(k-cur,dp,list)+1);
            }
        }
        return dp[k];
    }
}