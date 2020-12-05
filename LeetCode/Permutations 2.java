class Solution {
    public List<List<Integer>> permuteUnique(int[] nums) {
        Set<List<Integer>> makeSet =new HashSet<>();
        List<List<Integer>> ans = new ArrayList<>();
        boolean[] visited = new boolean[nums.length];
        List<Integer> temp = new ArrayList<>();
        makePermutation(0,nums.length,visited,temp,nums,makeSet);
        Iterator<List<Integer>> iter = makeSet.iterator();
        while(iter.hasNext()){
            ans.add(iter.next());
        }
        return ans;
    }
    private void makePermutation(int cnt,int depth,boolean[] visited, List<Integer> temp,int[] nums,Set<List<Integer>> makeSet) {
        if(cnt==depth) {
            List<Integer> ansList = new ArrayList<>(temp);
            makeSet.add(ansList);
            return;
        }
        for(int i=0;i<nums.length;i++) {
            if(!visited[i]) {
                visited[i] = true;
                temp.add(nums[i]);
                makePermutation(cnt+1,depth,visited,temp,nums,makeSet);
                visited[i] = false;
                temp.remove(temp.size()-1);
            }
        }
    }
}