class Solution {
    public int rob(int[] nums) {
        int[] dp = new int[nums.length+1];
        Arrays.fill(dp,-1);
        return go(0,nums.length,nums,dp);
    }
    private int go(int here,int depth,int[] nums,int[] dp) {
        if(here>=depth) return 0;
        if(dp[here]!=-1) return dp[here];
        if(here == depth-1) return nums[here];
        dp[here]=0;
        dp[here] = Math.max(go(here+2,depth,nums,dp)+nums[here],go(here+3,depth,nums,dp)+nums[here+1]);
        return dp[here];
    }
}