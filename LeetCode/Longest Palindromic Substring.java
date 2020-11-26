class Solution {
    public String longestPalindrome(String s) {
        int length = s.length();
        int[][] dp = new int[length][length];
        for(int i=0;i<length;i++) {
            for(int j=0;j<length;j++) {
                dp[i][j] = -1;
            }
        }
        
        for(int i=0;i<length;i++) {
            for(int j=i+1;j<length;j++) {
                makePalinDrome(i,j,s,dp);
            }
        }
        
        int ans=0,startIdx=0,endIdx=0;
        for(int i=0;i<length;i++) {
            for(int j=0;j<length;j++) {
                if(dp[i][j] == 1&&ans<j-i+1) {
                    ans = j-i+1;
                    startIdx = i;
                    endIdx = j;
                }
            }
        }
        
        String longestPalindrome = s.substring(startIdx,endIdx+1);
        return longestPalindrome;
    }
    private int makePalinDrome(int left,int right,String s,int[][] dp) {
        if(left>=right) return 1;
        if(s.charAt(left)!=s.charAt(right)) return 0;
        if(dp[left][right]!=-1) return dp[left][right];
        dp[left][right]=0;
        dp[left][right] = makePalinDrome(left+1,right-1,s,dp);
        return dp[left][right];
    }
}