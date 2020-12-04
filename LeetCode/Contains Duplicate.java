class Solution {
    public boolean containsDuplicate(int[] nums) {
        Map<Integer,Integer> map = new HashMap<>();
        boolean ok = false;
        for(Integer ele : nums) {
            if(map.get(ele)==null) {
                map.put(ele,1);
            }
            else {
                ok=true;
                break;
            }
        }
        return ok;
    }
}