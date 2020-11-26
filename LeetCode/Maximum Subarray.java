class Solution {
    public int maxSubArray(int[] nums) {
        int ans = 0;
        int[] dp = new int[nums.length];
        dp[0]=nums[0];
        ans = dp[0];
        for(int i=1;i<nums.length;i++) {
            dp[i]= Math.max(0,dp[i-1])+nums[i];
            ans = Math.max(ans,dp[i]);
        }
        return ans;
    }
}