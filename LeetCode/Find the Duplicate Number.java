class Solution {
    public int findDuplicate(int[] nums) {
        Set<Integer> set = new HashSet<>();
        int ans=0;
        for(int i=0;i<nums.length;i++) {
            if(!set.contains(nums[i])) {
                set.add(nums[i]);
            }
            else {
                ans = nums[i];
                break;
            }
        }
        return ans;
    }
}