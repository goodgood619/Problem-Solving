class Solution {
    public void moveZeroes(int[] nums) {
        List<Integer> list =new ArrayList<>();
        int zerocnt=0;
        for(int i=0;i<nums.length;i++) {
            if(nums[i]==0) zerocnt++;
            else list.add(nums[i]);
        }
        int idx=0;
        for(Integer e : list) {
            nums[idx++] = e;
        }
        for(int i=idx;i<nums.length;i++) {
            nums[i]=0;
        }
    }
}