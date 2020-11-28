class Solution {
    public int findPeakElement(int[] nums) {
        if(nums.length==1) return 0;
        int maxHeight =0 , idx=-1;
        for(int i=0;i<nums.length;i++) {
            if(i==0 || i==nums.length-1) {
                if(i==0 && nums[i]>nums[i+1]) {
                    maxHeight = Math.max(maxHeight,nums[i]);
                    idx = i;
                }   
                else if(i == nums.length-1 && nums[i]>nums[i-1]){
                    maxHeight = Math.max(maxHeight,nums[i]);
                    idx = i;
                }
                continue;
            }
            if(nums[i-1]<nums[i] && nums[i]>nums[i+1]) {
                maxHeight= Math.max(maxHeight,nums[i]);
                idx= i;
            }
        }
        return idx;
    }
}