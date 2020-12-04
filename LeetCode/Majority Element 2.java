class Solution {
    public List<Integer> majorityElement(int[] nums) {
        int length = nums.length,cnt=0;
        cnt = length/3+1;
        Map<Integer,Integer> map = new HashMap<>();
        List<Integer> list = new ArrayList<>();
        for(int i=0;i<nums.length;i++) {
            int num = nums[i];
            if(map.get(num)==null) {
                map.put(num,1);
            }
            else {
                int value = map.get(num);
                value++;
                map.remove(num);
                map.put(num,value);
            }
        }
        for(Integer e : map.keySet()) {
            if(map.get(e)>=cnt) {
                list.add(e);
            }
        }
        return list;
    }
}