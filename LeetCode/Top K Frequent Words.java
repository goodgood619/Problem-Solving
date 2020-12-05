class Solution {
    public List<String> topKFrequent(String[] words, int k) {
        Map<String,Integer> map = new HashMap<>();
        for(int i=0;i<words.length;i++) {
            String s = words[i];
            if(map.get(s)==null) {
                map.put(s,1);
            }
            else {
                int value = map.get(s);
                value++;
                map.remove(s);
                map.put(s,value);
            }
        }
        List<P> v = new ArrayList<>();
        for(String ele : map.keySet()) {
            v.add(new P(ele,map.get(ele)));
        }
        
        v.sort((a,b)->{
           if(a.count>b.count) return -1;
            else if(a.count<b.count) return 1;
            else {
                return a.s.compareTo(b.s);
            }
        });
        List<String> ans = new ArrayList<>();
        for(P ele : v) {
            ans.add(ele.s);
            k--;
            if(k==0) break;
        }
        return ans;
    }
}
class P {
    String s;
    int count;
    P(String s,int count) {
        this.s = s;
        this.count= count;
    }
}