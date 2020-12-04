class Solution {
    public int missingNumber(int[] nums) {
        Arrays.sort(nums);
        int cnt=0,ans=0;
        
        for(int i=0;i<nums.length;i++) {
            if(cnt==nums[i]) {
                cnt++;   
            }
            else {
                ans = cnt;
                break;
            }
        }
        if(ans==0) ans = cnt;
        return ans;
    }
}