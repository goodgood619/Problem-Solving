class Solution {
    int ans = 0;
    public int findTargetSumWays(int[] nums, int S) {
        int depth = nums.length;
        makeNumber(0,depth,0,S,nums);
        return ans;
    }
    private void makeNumber(int idx,int depth,int tempNumber, int S,int[] nums) {
        if(idx == depth) {
            if(tempNumber == S) ans++;
            return;
        }
        makeNumber(idx+1,depth,tempNumber+nums[idx],S,nums);
        makeNumber(idx+1,depth,tempNumber-nums[idx],S,nums);
    }
}