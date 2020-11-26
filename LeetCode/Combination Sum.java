class Solution {
    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        List<List<Integer>> ans = new ArrayList<>();
        List<Integer> temp = new ArrayList<>();
        Arrays.sort(candidates);
        go(candidates,0,target,ans,temp);
        return ans;
    }
    private void go(int[] arr,int here,int target,List<List<Integer>> ans, List<Integer> temp) {
        if(target==0) {
            ans.add(new ArrayList<>(temp));
            return;
        }
        for(int i=here;i<arr.length;i++) {
            if(target<arr[i]) continue;
            temp.add(arr[i]);
            go(arr,i,target-arr[i],ans,temp);
            temp.remove(temp.size()-1);
        }
    }
}