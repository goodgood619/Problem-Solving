class Solution {
    public List<Integer> findDisappearedNumbers(int[] nums) {
        List<Integer> ans = new ArrayList<>();
        if(nums.length ==0) return ans;
        int[] cnt = new int[nums.length+1];
        for(int i=0;i<nums.length;i++) {
            cnt[nums[i]]++;
        }
        for(int i=1;i<cnt.length;i++) {
            if(cnt[i]==0) ans.add(i);
        }
        return ans;
    }
}