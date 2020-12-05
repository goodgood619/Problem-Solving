class Solution {
    public int lastStoneWeight(int[] stones) {
        List<Integer> list = new ArrayList<>();
        for(int i=0;i<stones.length;i++) list.add(stones[i]);
        while(list.size()!= 1) {
            if(list.size()==0) break;
            Collections.sort(list);
            int max1 = list.get(list.size()-1);
            int max2= list.get(list.size()-2);
            if(max1==max2) {
                list.remove(list.size()-1);
                list.remove(list.size()-1);
            }
            else {
                list.remove(list.size()-1);
                list.remove(list.size()-1);
                list.add(max1 - max2);
            }
        }
        if(list.size()==1) return list.get(0);
        return 0;
    }
}