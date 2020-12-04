class Solution {
    public List<Integer> topKFrequent(int[] nums, int k) {
        List<P> list = new ArrayList<>();
        Map<Integer,Integer> map = new HashMap<>();
        for(int i=0;i<nums.length;i++) {
            if(map.get(nums[i])==null) {
                map.put(nums[i],1);
            }
            else {
                int value = map.get(nums[i]);
                value++;
                map.remove(nums[i]);
                map.put(nums[i],value);
            }
        }
        for(Integer e : map.keySet()) {
            list.add(new P(e,map.get(e)));
        }
        list.sort((a,b)->{
           if(a.count>b.count) return -1;
            else if(a.count<b.count) return 1;
            else {
                if(a.num<b.num) return -1;
                else if(a.num>b.num) return 1;
                else return 0;
            }
        });
        List<Integer> ans =new ArrayList<>();
        for(P e : list) {
            ans.add(e.num);
            k--;
            if(k==0) break;
        }
        return ans;
    }
}
class P {
    int num,count;
    P(int num,int count) {
        this.num = num;
        this.count = count;
    }
}