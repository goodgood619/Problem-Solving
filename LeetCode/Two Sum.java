class Solution {
    public int[] twoSum(int[] nums, int target) {
        int idx1=-1,idx2=-1;
        for(int i=0;i<nums.length;i++) {
            for(int j=i+1;j<nums.length;j++) {
                if(nums[i]+nums[j]==target) {
                    idx1 = i;
                    idx2 = j;
                    break;
                }
            }
            if(idx1!=-1) break;
        }
        int[] ret = new int[2];
        ret[0]=idx1;
        ret[1]=idx2;
        return ret;
    }
}