class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        Set<List<Integer>> set = new HashSet<>();
        List<List<Integer>> ans = new ArrayList<>();
        Arrays.sort(nums);
        Map<Integer,Integer> map = new HashMap<>();
        for(int i=0;i<nums.length;i++) {
            map.put(nums[i],i);
        }
        for(int i=0;i<nums.length;i++) {
            int first = nums[i];
            for(int j=i+1;j<nums.length;j++) {
                int second = nums[j];
                int rest = 0-first-second;
                if(map.get(rest)!=null && map.get(rest)>j) {
                    List<Integer> list = new ArrayList<>();
                    list.add(first);
                    list.add(second);
                    list.add(rest);
                    set.add(list);
                }
            }
        }
        for(List<Integer> ele : set) {
            ans.add(ele);
        }
        return ans;
    }
}