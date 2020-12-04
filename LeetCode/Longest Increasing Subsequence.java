class Solution {
    public int lengthOfLIS(int[] arr) {
        if(arr.length==0) return 0;
        int[] dp = new int[arr.length];
        int ans=1;
        for(int i=0;i<arr.length;i++) {
            dp[i] = 1;
            for(int j=0;j<i;j++) {
                if(arr[j]<arr[i]) {
                    dp[i] = Math.max(dp[i],dp[j]+1);
                    ans = Math.max(ans,dp[i]);  
                }
            }
        }
        return ans;
    }
}