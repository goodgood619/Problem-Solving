class Solution {
    public void rotate(int[] nums, int k) {
        for(int i=1;i<=k;i++) {
            change(nums);
        }
    }
    private void change(int[] nums) {
        int first = nums[0];
        nums[0] = nums[nums.length-1];
        int temp = first;
        for(int i=1;i<nums.length;i++) {
            int temp2 = nums[i];
            nums[i] = temp;
            temp = temp2;
        }
    }
}