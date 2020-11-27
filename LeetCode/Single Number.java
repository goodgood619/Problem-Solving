class Solution {
    public int singleNumber(int[] num) {
        Map<Integer,Integer> map = new HashMap<>();
        for(int i=0;i<num.length;i++) {
            if(map.get(num[i])==null) {
                map.put(num[i],1);
            }
            else {
                int value = map.get(num[i]);
                value++;
                map.remove(num[i]);
                map.put(num[i],value);
            }
        }
        
        int ans=0;
        for(Integer e : map.keySet()) {
            if(map.get(e)==1) {
                ans = e;
                break;
            }
        }
        return ans;
    }
}