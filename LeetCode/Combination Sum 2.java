class Solution {
    public List<List<Integer>> combinationSum2(int[] candidates, int target) {
        Map<List<Integer>,Integer> map = new HashMap<>();
        List<List<Integer>> ans = new ArrayList<>();
        List<Integer> temp = new ArrayList<>();
        Arrays.sort(candidates);
        go(candidates,0,target,ans,temp,map);
        return ans;
    }
    private void go(int[] arr,int here,int target,List<List<Integer>> ans, List<Integer> temp,Map<List<Integer>,Integer> map) {
        if(target==0) {
            List<Integer> list= new ArrayList<>(temp);
            if(map.get(list)!=null) return;
            ans.add(list);
            map.put(list,1);
            return;
        }
        for(int i=here;i<arr.length;i++) {
            if(target<arr[i]) continue;
            temp.add(arr[i]);
            go(arr,i+1,target-arr[i],ans,temp,map);
            temp.remove(temp.size()-1);
        }
    }
}